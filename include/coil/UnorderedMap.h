#pragma once

#include "Assert.h"
#include "Hash.h"
#include "Vector.h"
#include "detail/Utility.h"

namespace coil
{
    template<typename K, typename V>
    class KeyValuePair
    {
        template<typename, typename>
        friend class UnorderedMap;

    public:
        K const& key() const { return m_key; }
        V const& value() const { return m_value; }
        V& value() { return m_value; }

    private:
        KeyValuePair(K key, V value) : m_key(coil::move(key)), m_value(coil::move(value)) {}

        K m_key;
        V m_value;
    };

    template<typename K, typename V>
    class UnorderedMap
    {
    public:
        struct Node
        {
            KeyValuePair<K, V> pair;

            size_t bucket = invalidIndex;
            size_t prev = invalidIndex;
            size_t next = invalidIndex;
        };

        class Iterator
        {
        public:
            Iterator(Node* node) : m_node(node) {}

            KeyValuePair<K, V>& operator*() { return m_node->pair; }
            KeyValuePair<K, V>* operator->() { return &m_node->pair; }

            bool operator==(Iterator const& rhs) const
            {
                return m_node == rhs.m_node;
            }

            bool operator!=(Iterator const& rhs) const
            {
                return !(*this == rhs);
            }

            Iterator& operator++()
            {
                m_node++;
                return *this;
            }

        private:
            Node* m_node = nullptr;
        };

        class ConstIterator
        {
        public:
            ConstIterator(Node const* node) : m_node(node) {}

            KeyValuePair<K, V> const& operator*() const { return m_node->pair; }
            KeyValuePair<K, V> const* operator->() const { return &m_node->pair; }

            bool operator==(ConstIterator const& rhs) const
            {
                return m_node == rhs.m_node;
            }

            bool operator!=(ConstIterator const& rhs) const
            {
                return !(*this == rhs);
            }

            Iterator& operator++()
            {
                m_node++;
                return *this;
            }

        private:
            Node const* m_node = nullptr;
        };

        UnorderedMap(size_t bucketsCount = 1, float maxLoadFactor = 1.0f) : m_maxLoadFactor(maxLoadFactor)
        {
            rehash(bucketsCount);
        }

        ConstIterator begin() const { return { m_nodes.begin() }; }
        ConstIterator end() const { return { m_nodes.end() }; }
        Iterator begin() { return { m_nodes.begin() }; }
        Iterator end() { return { m_nodes.end() }; }

        Iterator insertOrAssign(K key, V value)
        {
            if (Iterator it = find(key); it != end())
            {
                it->m_value = coil::move(value);
                return it;
            }

            size_t nextSize = size() + 1;
            float nextLoadFactor = 1.0f * nextSize / m_buckets.size();
            if (nextLoadFactor > m_maxLoadFactor)
                rehash(size() * 2);

            size_t newNodeIndex = m_nodes.size();
            m_nodes.pushBack({ KeyValuePair<K, V>{ coil::move(key), coil::move(value) }, invalidIndex, invalidIndex, invalidIndex });

            insertNode(newNodeIndex);

            return Iterator{ &m_nodes[newNodeIndex] };
        }

        template<typename T>
        void erase(T const& key)
        {
            size_t nodeIndex = findNodeIndex(key);
            if (nodeIndex == invalidIndex)
                return;

            COIL_ASSERT(nodeIndex < m_nodes.size());
            Node& node = m_nodes[nodeIndex];

            COIL_ASSERT(node.bucket < m_buckets.size());

            if (node.prev != invalidIndex)
            {
                COIL_ASSERT(m_buckets[node.bucket] != nodeIndex);
                COIL_ASSERT(node.prev < m_nodes.size());
                m_nodes[node.prev].next = node.next;
            }
            else
            {
                COIL_ASSERT(m_buckets[node.bucket] == nodeIndex);
                m_buckets[node.bucket] = node.next;
            }

            if (node.next != invalidIndex)
            {
                COIL_ASSERT(node.next < m_nodes.size());
                m_nodes[node.next].prev = node.prev;
            }

            node.prev = invalidIndex;
            node.next = invalidIndex;

            COIL_ASSERT(nodeIndex < m_nodes.size());
            Node& erasedNode = m_nodes[nodeIndex];

            COIL_ASSERT(!m_nodes.empty());

            if (nodeIndex != m_nodes.size() - 1)
            {
                Node& lastNode = m_nodes.back();

                if (lastNode.prev != invalidIndex)
                {
                    COIL_ASSERT(lastNode.prev < m_nodes.size());
                    m_nodes[lastNode.prev].next = nodeIndex;
                }
                else
                {
                    COIL_ASSERT(lastNode.bucket < m_buckets.size());
                    m_buckets[lastNode.bucket] = nodeIndex;
                }

                coil::exchange(erasedNode, lastNode);
            }

            COIL_ASSERT(m_nodes.back().prev == invalidIndex);
            COIL_ASSERT(m_nodes.back().next == invalidIndex);

            m_nodes.popBack();
        }

        void clear()
        {
            m_nodes.clear();
            resetBuckets();
        }

        template<typename T>
        Iterator find(T const& key)
        {
            size_t index = findNodeIndex(key);
            if (index != invalidIndex)
                return Iterator{ &m_nodes[index] };
            return end();
        }

        template<typename T>
        ConstIterator find(T const& key) const
        {
            size_t index = findNodeIndex(key);
            if (index != invalidIndex)
                return ConstIterator{ &m_nodes[index] };
            return end();
        }

        size_t size() const { return m_nodes.size(); }

    private:
        template<typename T>
        size_t computeBucketIndex(T const& key) const
        {
            size_t hash = Hash<T>{}(key);
            return hash % m_buckets.size();
        }

        void insertNode(size_t newNodeIndex)
        {
            COIL_ASSERT(newNodeIndex < m_nodes.size());
            Node& newNode = m_nodes[newNodeIndex];

            size_t bucketIndex = computeBucketIndex(newNode.pair.m_key);
            COIL_ASSERT(bucketIndex < m_buckets.size());

            newNode.bucket = bucketIndex;
            newNode.next = invalidIndex;
            newNode.prev = invalidIndex;

            size_t firstNodeIndex = m_buckets[bucketIndex];
            if (firstNodeIndex == invalidIndex)
            {
                m_buckets[bucketIndex] = newNodeIndex;
                return;
            }

            size_t nodeIndex = firstNodeIndex;
            while (nodeIndex != invalidIndex)
            {
                COIL_ASSERT(nodeIndex < m_nodes.size());
                Node& node = m_nodes[nodeIndex];

                if (node.next == invalidIndex)
                {
                    node.next = newNodeIndex;
                    newNode.prev = nodeIndex;
                    return;
                }

                nodeIndex = node.next;
            }
        }

        void resetBuckets()
        {
            for (size_t i = 0; i < m_buckets.size(); i++)
                m_buckets[i] = invalidIndex;
        }

        void rehash(size_t buckets)
        {
            m_buckets.resize(buckets);
            resetBuckets();

            for (size_t nodeIndex = 0; nodeIndex < m_nodes.size(); nodeIndex++)
                insertNode(nodeIndex);
        }

        template<typename T>
        size_t findNodeIndex(T const& key) const
        {
            size_t bucketIndex = computeBucketIndex(key);
            COIL_ASSERT(bucketIndex < m_buckets.size());

            size_t nodeIndex = m_buckets[bucketIndex];
            while (nodeIndex != invalidIndex)
            {
                COIL_ASSERT(nodeIndex < m_nodes.size());
                Node const& node = m_nodes[nodeIndex];

                if (node.pair.m_key == key)
                    return nodeIndex;

                nodeIndex = node.next;
            }

            return invalidIndex;
        }

    private:
        inline static constexpr size_t invalidIndex = static_cast<size_t>(-1);

    private:
        Vector<size_t> m_buckets;
        Vector<Node> m_nodes;
        float m_maxLoadFactor = 1.0f;
    };
}
