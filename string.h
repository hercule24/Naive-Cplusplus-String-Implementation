#ifndef STRING_H
#define STRING_H

#include <cstring>

class String {
    size_t capacity; // capacity equals the allocated_size - 1
    size_t size;
    char* p;

    public:
        String();
        ~String();
        String(const char* s);
        String(const String& s);
        String& operator= (const String& s);
        String(String&& s);
        String& operator= (String&& s);
        size_t length() const;
        char operator[] (size_t i) const;
        bool empty() const;
};

#endif
