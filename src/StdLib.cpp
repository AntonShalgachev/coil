#include "coil/detail/StdLib.h"

// This implementation is an adaptation of "musl" C standard library

#include <assert.h>
#include <errno.h>
#include <ctype.h>
#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdint.h>
#include <string.h>
#include <stddef.h>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4244) // '=': conversion from '__int64' to 'int', possible loss of data
#pragma warning(disable : 4308) // negative integral constant converted to unsigned type
#pragma warning(disable : 4245) // 'argument': conversion from '__int64' to 'unsigned __int64', signed/unsigned mismatch
#pragma warning(disable : 4702) // unreachable code
#endif

#if LDBL_MANT_DIG == 53 && LDBL_MAX_EXP == 1024

#define LD_B1B_DIG 2
#define LD_B1B_MAX 9007199, 254740991
#define KMAX 128

#elif LDBL_MANT_DIG == 64 && LDBL_MAX_EXP == 16384

#define LD_B1B_DIG 3
#define LD_B1B_MAX 18, 446744073, 709551615
#define KMAX 2048

#elif LDBL_MANT_DIG == 113 && LDBL_MAX_EXP == 16384

#define LD_B1B_DIG 4
#define LD_B1B_MAX 10384593, 717069655, 257060992, 658440191
#define KMAX 2048

#else
#error Unsupported long double representation
#endif

#define MASK (KMAX-1)

#define shcnt(f) ((f)->shcnt + ((f)->rpos - (f)->buf))
#define shlim(f, lim) __shlim((f), (lim))
#define shgetc(f) (((f)->rpos != (f)->shend) ? checked_shgetc(f) : __shgetc(f))
#define shunget(f) ((f)->shlim>=0 ? (void)(f)->rpos-- : (void)0)

#define sh_fromstring(f, s, e) \
	((f)->buf = (f)->rpos = (unsigned char *)(s), (f)->rend = (unsigned char*)-1, (f)->bufend=(unsigned char *)(e))

namespace
{
    // Struct is reduced to only necessary fields
    struct FAKE_FILE {
        unsigned char* rpos, * rend;
        unsigned char* buf, * bufend;
        unsigned char* shend;
        ptrdiff_t shlim, shcnt;
    };

    void __shlim(FAKE_FILE* f, ptrdiff_t lim)
    {
        f->shlim = lim;
        f->shcnt = f->buf - f->rpos;
        /* If lim is nonzero, rend must be a valid pointer. */
        if (lim && f->rend - f->rpos > lim)
            f->shend = f->rpos + lim;
        else
            f->shend = f->rend;
    }

    int __shgetc(FAKE_FILE*)
    {
        // Code removed since it should never reach this point
        assert(false);
        return 0;
    }

    int checked_shgetc(FAKE_FILE* f)
    {
        if (f->rpos == f->bufend)
        {
            f->rpos++;
            return 0;
        }
        return *f->rpos++;
    }

    long long scanexp(FAKE_FILE* f, int pok)
    {
        int c;
        int x;
        long long y;
        int neg = 0;

        c = shgetc(f);
        if (c == '+' || c == '-')
        {
            neg = (c == '-');
            c = shgetc(f);
            if (static_cast<unsigned>(c - '0') >= 10U && pok) shunget(f);
        }
        if (static_cast<unsigned>(c - '0') >= 10U)
        {
            shunget(f);
            return LLONG_MIN;
        }
        for (x = 0; static_cast<unsigned>(c - '0') < 10U && x < INT_MAX / 10; c = shgetc(f))
            x = 10 * x + c - '0';
        for (y = x; static_cast<unsigned>(c - '0') < 10U && y < LLONG_MAX / 100; c = shgetc(f))
            y = 10 * y + c - '0';
        for (; static_cast<unsigned>(c - '0') < 10U; c = shgetc(f));
        shunget(f);
        return neg ? -y : y;
    }

    long double decfloat(FAKE_FILE* f, int c, int bits, int emin, int sign, int pok)
    {
        uint32_t x[KMAX];
        static const uint32_t th[] = { LD_B1B_MAX };
        int i, j, k, a, z;
        long long lrp = 0, dc = 0;
        long long e10 = 0;
        int lnz = 0;
        int gotdig = 0, gotrad = 0;
        int rp;
        int e2;
        int emax = -emin - bits + 3;
        int denormal = 0;
        long double y;
        long double frac = 0;
        long double bias = 0;
        static const int p10s[] = { 10, 100, 1000, 10000,
            100000, 1000000, 10000000, 100000000 };

        j = 0;
        k = 0;

        /* Don't let leading zeros consume buffer space */
        for (; c == '0'; c = shgetc(f)) gotdig = 1;
        if (c == '.')
        {
            gotrad = 1;
            for (c = shgetc(f); c == '0'; c = shgetc(f)) gotdig = 1, lrp--;
        }

        x[0] = 0;
        for (; static_cast<unsigned>(c - '0') < 10U || c == '.'; c = shgetc(f))
        {
            if (c == '.')
            {
                if (gotrad) break;
                gotrad = 1;
                lrp = dc;
            }
            else if (k < KMAX - 3)
            {
                dc++;
                if (c != '0') lnz = dc;
                if (j) x[k] = x[k] * 10 + c - '0';
                else x[k] = c - '0';
                if (++j == 9)
                {
                    k++;
                    j = 0;
                }
                gotdig = 1;
            }
            else
            {
                dc++;
                if (c != '0')
                {
                    lnz = (KMAX - 4) * 9;
                    x[KMAX - 4] |= 1;
                }
            }
        }
        if (!gotrad) lrp = dc;

        if (gotdig && (c | 32) == 'e')
        {
            e10 = scanexp(f, pok);
            if (e10 == LLONG_MIN)
            {
                if (pok)
                {
                    shunget(f);
                }
                else
                {
                    shlim(f, 0);
                    return 0;
                }
                e10 = 0;
            }
            lrp += e10;
        }
        else if (c >= 0)
        {
            shunget(f);
        }
        if (!gotdig)
        {
            errno = EINVAL;
            shlim(f, 0);
            return 0;
        }

        /* Handle zero specially to avoid nasty special cases later */
        if (!x[0]) return sign * 0.0;

        /* Optimize small integers (w/no exponent) and over/under-flow */
        if (lrp == dc && dc < 10 && (bits > 30 || x[0] >> bits == 0))
            return sign * (long double)x[0];
        if (lrp > -emin / 2)
        {
            errno = ERANGE;
            return sign * LDBL_MAX * LDBL_MAX;
        }
        if (lrp < emin - 2 * LDBL_MANT_DIG)
        {
            errno = ERANGE;
            return sign * LDBL_MIN * LDBL_MIN;
        }

        /* Align incomplete final B1B digit */
        if (j)
        {
            for (; j < 9; j++) x[k] *= 10;
            k++;
            j = 0;
        }

        a = 0;
        z = k;
        e2 = 0;
        rp = lrp;

        /* Optimize small to mid-size integers (even in exp. notation) */
        if (lnz < 9 && lnz <= rp && rp < 18)
        {
            if (rp == 9) return sign * (long double)x[0];
            if (rp < 9) return sign * (long double)x[0] / p10s[8 - rp];
            int bitlim = bits - 3 * (int)(rp - 9);
            if (bitlim > 30 || x[0] >> bitlim == 0)
                return sign * (long double)x[0] * p10s[rp - 10];
        }

        /* Drop trailing zeros */
        for (; !x[z - 1]; z--);

        /* Align radix point to B1B digit boundary */
        if (rp % 9)
        {
            int rpm9 = rp >= 0 ? rp % 9 : rp % 9 + 9;
            int p10 = p10s[8 - rpm9];
            uint32_t carry = 0;
            for (k = a; k != z; k++)
            {
                uint32_t tmp = x[k] % p10;
                x[k] = x[k] / p10 + carry;
                carry = 1000000000 / p10 * tmp;
                if (k == a && !x[k])
                {
                    a = (a + 1 & MASK);
                    rp -= 9;
                }
            }
            if (carry) x[z++] = carry;
            rp += 9 - rpm9;
        }

        /* Upscale until desired number of bits are left of radix point */
        while (rp < 9 * LD_B1B_DIG || (rp == 9 * LD_B1B_DIG && x[a] < th[0]))
        {
            uint32_t carry = 0;
            e2 -= 29;
            for (k = (z - 1 & MASK); ; k = (k - 1 & MASK))
            {
                uint64_t tmp = ((uint64_t)x[k] << 29) + carry;
                if (tmp > 1000000000)
                {
                    carry = tmp / 1000000000;
                    x[k] = tmp % 1000000000;
                }
                else
                {
                    carry = 0;
                    x[k] = tmp;
                }
                if (k == (z - 1 & MASK) && k != a && !x[k]) z = k;
                if (k == a) break;
            }
            if (carry)
            {
                rp += 9;
                a = (a - 1 & MASK);
                if (a == z)
                {
                    z = (z - 1 & MASK);
                    x[z - 1 & MASK] |= x[z];
                }
                x[a] = carry;
            }
        }

        /* Downscale until exactly number of bits are left of radix point */
        for (;;)
        {
            uint32_t carry = 0;
            int sh = 1;
            for (i = 0; i < LD_B1B_DIG; i++)
            {
                k = (a + i & MASK);
                if (k == z || x[k] < th[i])
                {
                    i = LD_B1B_DIG;
                    break;
                }
                if (x[a + i & MASK] > th[i]) break;
            }
            if (i == LD_B1B_DIG && rp == 9 * LD_B1B_DIG) break;
            /* FIXME: find a way to compute optimal sh */
            if (rp > 9 + 9 * LD_B1B_DIG) sh = 9;
            e2 += sh;
            for (k = a; k != z; k = (k + 1 & MASK))
            {
                uint32_t tmp = x[k] & (1 << sh) - 1;
                x[k] = (x[k] >> sh) + carry;
                carry = (1000000000 >> sh) * tmp;
                if (k == a && !x[k])
                {
                    a = (a + 1 & MASK);
                    i--;
                    rp -= 9;
                }
            }
            if (carry)
            {
                if ((z + 1 & MASK) != a)
                {
                    x[z] = carry;
                    z = (z + 1 & MASK);
                }
                else x[z - 1 & MASK] |= 1;
            }
        }

        /* Assemble desired bits into floating point variable */
        for (y = i = 0; i < LD_B1B_DIG; i++)
        {
            if ((a + i & MASK) == z) x[(z = (z + 1 & MASK)) - 1] = 0;
            y = 1000000000.0L * y + x[a + i & MASK];
        }

        y *= sign;

        /* Limit precision for denormal results */
        if (bits > LDBL_MANT_DIG + e2 - emin)
        {
            bits = LDBL_MANT_DIG + e2 - emin;
            if (bits < 0) bits = 0;
            denormal = 1;
        }

        /* Calculate bias term to force rounding, move out lower bits */
        if (bits < LDBL_MANT_DIG)
        {
            bias = copysignl(scalbn(1, 2 * LDBL_MANT_DIG - bits - 1), y);
            frac = fmodl(y, scalbn(1, LDBL_MANT_DIG - bits));
            y -= frac;
            y += bias;
        }

        /* Process tail of decimal input so it can affect rounding */
        if ((a + i & MASK) != z)
        {
            uint32_t t = x[a + i & MASK];
            if (t < 500000000 && (t || (a + i + 1 & MASK) != z))
                frac += 0.25 * sign;
            else if (t > 500000000)
                frac += 0.75 * sign;
            else if (t == 500000000)
            {
                if ((a + i + 1 & MASK) == z)
                    frac += 0.5 * sign;
                else
                    frac += 0.75 * sign;
            }
            if (LDBL_MANT_DIG - bits >= 2 && !fmodl(frac, 1))
                frac++;
        }

        y += frac;
        y -= bias;

        if ((e2 + LDBL_MANT_DIG & INT_MAX) > emax - 5)
        {
            if (fabsl(y) >= 2 / LDBL_EPSILON)
            {
                if (denormal && bits == LDBL_MANT_DIG + e2 - emin)
                    denormal = 0;
                y *= 0.5;
                e2++;
            }
            if (e2 + LDBL_MANT_DIG > emax || (denormal && frac))
                errno = ERANGE;
        }

        return scalbnl(y, e2);
    }

    long double hexfloat(FAKE_FILE* f, int bits, int emin, int sign, int pok)
    {
        uint32_t x = 0;
        long double y = 0;
        long double scale = 1;
        long double bias = 0;
        int gottail = 0, gotrad = 0, gotdig = 0;
        long long rp = 0;
        long long dc = 0;
        long long e2 = 0;
        int d;
        int c;

        c = shgetc(f);

        /* Skip leading zeros */
        for (; c == '0'; c = shgetc(f)) gotdig = 1;

        if (c == '.')
        {
            gotrad = 1;
            c = shgetc(f);
            /* Count zeros after the radix point before significand */
            for (rp = 0; c == '0'; c = shgetc(f), rp--) gotdig = 1;
        }

        for (; static_cast<unsigned>(c - '0') < 10U || static_cast<unsigned>((c | 32) - 'a') < 6U || c == '.'; c = shgetc(f))
        {
            if (c == '.')
            {
                if (gotrad) break;
                rp = dc;
                gotrad = 1;
            }
            else
            {
                gotdig = 1;
                if (c > '9') d = (c | 32) + 10 - 'a';
                else d = c - '0';
                if (dc < 8)
                {
                    x = x * 16 + d;
                }
                else if (dc < LDBL_MANT_DIG / 4 + 1)
                {
                    y += d * (scale /= 16);
                }
                else if (d && !gottail)
                {
                    y += 0.5 * scale;
                    gottail = 1;
                }
                dc++;
            }
        }
        if (!gotdig)
        {
            shunget(f);
            if (pok)
            {
                shunget(f);
                if (gotrad) shunget(f);
            }
            else
            {
                shlim(f, 0);
            }
            return sign * 0.0;
        }
        if (!gotrad) rp = dc;
        while (dc < 8) x *= 16, dc++;
        if ((c | 32) == 'p')
        {
            e2 = scanexp(f, pok);
            if (e2 == LLONG_MIN)
            {
                if (pok)
                {
                    shunget(f);
                }
                else
                {
                    shlim(f, 0);
                    return 0;
                }
                e2 = 0;
            }
        }
        else
        {
            shunget(f);
        }
        e2 += 4 * rp - 32;

        if (!x) return sign * 0.0;
        if (e2 > -emin)
        {
            errno = ERANGE;
            return sign * LDBL_MAX * LDBL_MAX;
        }
        if (e2 < emin - 2 * LDBL_MANT_DIG)
        {
            errno = ERANGE;
            return sign * LDBL_MIN * LDBL_MIN;
        }

        while (x < 0x80000000)
        {
            if (y >= 0.5)
            {
                x += x + 1;
                y += y - 1;
            }
            else
            {
                x += x;
                y += y;
            }
            e2--;
        }

        if (bits > 32 + e2 - emin)
        {
            bits = 32 + e2 - emin;
            if (bits < 0) bits = 0;
        }

        if (bits < LDBL_MANT_DIG)
            bias = copysignl(scalbn(1, 32 + LDBL_MANT_DIG - bits - 1), sign);

        if (bits < 32 && y && !(x & 1)) x++, y = 0;

        y = bias + sign * (long double)x + sign * y;
        y -= bias;

        if (!y) errno = ERANGE;

        return scalbnl(y, e2);
    }

    long double __floatscan(FAKE_FILE* f, int prec, int pok)
    {
        int sign = 1;
        size_t i;
        int bits;
        int emin;
        int c;

        switch (prec)
        {
        case 0:
            bits = FLT_MANT_DIG;
            emin = FLT_MIN_EXP - bits;
            break;
        case 1:
            bits = DBL_MANT_DIG;
            emin = DBL_MIN_EXP - bits;
            break;
        case 2:
            bits = LDBL_MANT_DIG;
            emin = LDBL_MIN_EXP - bits;
            break;
        default:
            return 0;
        }

        while (isspace((c = shgetc(f))));

        if (c == '+' || c == '-')
        {
            sign -= 2 * (c == '-');
            c = shgetc(f);
        }

        for (i = 0; i < 8 && (c | 32) == "infinity"[i]; i++)
            if (i < 7) c = shgetc(f);
        if (i == 3 || i == 8 || (i > 3 && pok))
        {
            if (i != 8)
            {
                shunget(f);
                if (pok) for (; i > 3; i--) shunget(f);
            }
            return sign * INFINITY;
        }
        if (!i) for (i = 0; i < 3 && (c | 32) == "nan"[i]; i++)
            if (i < 2) c = shgetc(f);
        if (i == 3)
        {
            if (shgetc(f) != '(')
            {
                shunget(f);
                return NAN;
            }
            for (i = 1; ; i++)
            {
                c = shgetc(f);
                if (static_cast<unsigned>(c - '0') < 10U || static_cast<unsigned>(c - 'A') < 26U || static_cast<unsigned>(c - 'a') < 26U || c == '_')
                    continue;
                if (c == ')') return NAN;
                shunget(f);
                if (!pok)
                {
                    errno = EINVAL;
                    shlim(f, 0);
                    return 0;
                }
                while (i--) shunget(f);
                return NAN;
            }
            return NAN;
        }

        if (i)
        {
            shunget(f);
            errno = EINVAL;
            shlim(f, 0);
            return 0;
        }

        if (c == '0')
        {
            c = shgetc(f);
            if ((c | 32) == 'x')
                return hexfloat(f, bits, emin, sign, pok);
            shunget(f);
            c = '0';
        }

        return decfloat(f, c, bits, emin, sign, pok);
    }

    long double strtox(const char* s, const char* e, char** p, int prec)
    {
        FAKE_FILE f;
        sh_fromstring(&f, s, e);
        shlim(&f, 0);
        long double y = __floatscan(&f, prec, 1);
        ptrdiff_t cnt = shcnt(&f);
        if (p) *p = cnt ? (char*)s + cnt : (char*)s;
        return y;
    }
}

namespace
{
    /* Lookup table for digit values. -1==255>=36 -> invalid */
    const unsigned char table[] = { 255,
    255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
    255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
    255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
      0,  1,  2,  3,  4,  5,  6,  7,  8,  9,255,255,255,255,255,255,
    255, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24,
     25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35,255,255,255,255,255,
    255, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24,
     25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35,255,255,255,255,255,
    255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
    255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
    255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
    255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
    255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
    255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
    255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
    255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
    };

    unsigned long long __intscan(FAKE_FILE* f, unsigned base, int pok, unsigned long long lim)
    {
        const unsigned char* val = table + 1;
        int c, neg = 0;
        unsigned x;
        unsigned long long y;
        if (base > 36 || base == 1)
        {
            errno = EINVAL;
            return 0;
        }
        while (isspace((c = shgetc(f))));
        if (c == '+' || c == '-')
        {
            neg = -(c == '-');
            c = shgetc(f);
        }
        if ((base == 0 || base == 16) && c == '0')
        {
            c = shgetc(f);
            if ((c | 32) == 'x')
            {
                c = shgetc(f);
                if (val[c] >= 16)
                {
                    shunget(f);
                    if (pok) shunget(f);
                    else shlim(f, 0);
                    return 0;
                }
                base = 16;
            }
            else if (base == 0)
            {
                base = 8;
            }
        }
        else
        {
            if (base == 0) base = 10;
            if (val[c] >= base)
            {
                shunget(f);
                shlim(f, 0);
                errno = EINVAL;
                return 0;
            }
        }
        if (base == 10)
        {
            for (x = 0; static_cast<unsigned>(c - '0') < 10U && x <= UINT_MAX / 10 - 1; c = shgetc(f))
                x = x * 10 + (c - '0');
            for (y = x; static_cast<unsigned>(c - '0') < 10U && y <= ULLONG_MAX / 10 && 10 * y <= ULLONG_MAX - (c - '0'); c = shgetc(f))
                y = y * 10 + (c - '0');
            if (static_cast<unsigned>(c - '0') >= 10U) goto done;
        }
        else if (!(base & base - 1))
        {
            int bs = "\0\1\2\4\7\3\6\5"[(0x17 * base) >> 5 & 7];
            for (x = 0; val[c] < base && x <= UINT_MAX / 32; c = shgetc(f))
                x = x << bs | val[c];
            for (y = x; val[c]<base && y <= ULLONG_MAX >> bs; c = shgetc(f))
                y = y << bs | val[c];
        }
        else
        {
            for (x = 0; val[c] < base && x <= UINT_MAX / 36 - 1; c = shgetc(f))
                x = x * base + val[c];
            for (y = x; val[c] < base && y <= ULLONG_MAX / base && base * y <= ULLONG_MAX - val[c]; c = shgetc(f))
                y = y * base + val[c];
        }
        if (val[c] < base)
        {
            for (; val[c] < base; c = shgetc(f));
            errno = ERANGE;
            y = lim;
            if (lim & 1) neg = 0;
        }
    done:
        shunget(f);
        if (y >= lim)
        {
            if (!(lim & 1) && !neg)
            {
                errno = ERANGE;
                return lim - 1;
            }
            else if (y > lim)
            {
                errno = ERANGE;
                return lim;
            }
        }
        return (y ^ neg) - neg;
    }

    unsigned long long strtox(const char* s, const char* e, char** p, int base, unsigned long long lim)
    {
        FAKE_FILE f;
        sh_fromstring(&f, s, e);
        shlim(&f, 0);
        unsigned long long y = __intscan(&f, base, 1, lim);
        if (p)
        {
            size_t cnt = shcnt(&f);
            *p = (char*)s + cnt;
        }
        return y;
    }
}

namespace coil
{
    float strtof(const char* s, const char* e, char** p)
    {
        return static_cast<float>(strtox(s, e, p, 0));
    }

    double strtod(const char* s, const char* e, char** p)
    {
        return static_cast<double>(strtox(s, e, p, 1));
    }

    long double strtold(const char* s, const char* e, char** p)
    {
        return strtox(s, e, p, 2);
    }

    long strtol(const char* s, const char* e, char** p, int base)
    {
        return static_cast<long>(strtox(s, e, p, base, 0UL + LONG_MIN));
    }

    unsigned long strtoul(const char* s, const char* e, char** p, int base)
    {
        return static_cast<unsigned long>(strtox(s, e, p, base, ULONG_MAX));
    }

    long long strtoll(const char* s, const char* e, char** p, int base)
    {
        return strtox(s, e, p, base, LLONG_MIN);
    }

    unsigned long long strtoull(const char* s, const char* e, char** p, int base)
    {
        return strtox(s, e, p, base, ULLONG_MAX);
    }
}

#if defined(_MSC_VER)
#pragma warning(pop)
#endif
