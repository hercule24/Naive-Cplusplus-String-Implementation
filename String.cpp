#include <iostream>
#include "String.h"

String::String() : capacity(15), size(0), p(new char[16]) {}

String::~String() { delete[] p; }

String::String(const char* s) {
    //std::cout << "from c string" << std::endl;
    size_t s_size = strlen(s);
    if (s_size > capacity) {
        delete[] p;
        p = new char[2 * s_size + 1];
        capacity = 2 * s_size;
    }
    size = s_size;
    strcpy(p, s);
}

String::String(const String& s) {
    size_t s_size = s.length();
    if (s_size > capacity) {
        delete[] p;
        p = new char[2 * s_size + 1];
        capacity = 2 * s_size;
    }
    size = s_size;
    for (int i = 0; i < size; i++) {
        p[i] = s.p[i];
    }
    p[size] = '\0';
}

String& String::operator= (const String& s) {
    size_t s_size = s.length();
    if (s_size > capacity) {
        delete[] p;
        p = new char[2 * s_size + 1];
        capacity = 2 * s_size;
    }
    size = s_size;
    for (int i = 0; i < size; i++) {
        p[i] = s.p[i];
    }
    p[size] = '\0';
    return *this;
}

String::String(String&& s) {
    capacity = s.capacity;
    size = s.size;
    delete[] p;
    p = s.p;
    s.p = nullptr;
}

String& String::operator= (String&& s) {
    capacity = s.capacity;
    size = s.size;
    delete[] p;
    p = s.p;
    s.p = nullptr;
    return *this;
}

size_t String::length() const {
    return size;
}
