#pragma once

namespace coil
{
    float strtof(const char* s, const char* e, char** p);
    double strtod(const char* s, const char* e, char** p);
    long double strtold(const char* s, const char* e, char** p);

    long strtol(const char* s, const char* e, char** p, int base);
    unsigned long strtoul(const char* s, const char* e, char** p, int base);
    long long strtoll(const char* s, const char* e, char** p, int base);
    unsigned long long strtoull(const char* s, const char* e, char** p, int base);
}
