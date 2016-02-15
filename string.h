#ifndef STRING_H
#define STRING_H

#include <cstring>

class String {
    std::size_t capacity; // capacity equals the allocated_size - 1
    std::size_t size;

    public:
        char* p;
        String();
        ~String();
        String(const char* s);
        String(const String& s);
        String& operator= (const String& s);
        String(String&& s);
        String& operator= (String&& s);
        size_t length() const;
};

#endif
