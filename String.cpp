#include <iostream>
#include "String.h"

String::String() : capacity(15), size(0), p(new char[16]) { 
    p[0] = '\0';
}

String::~String() { delete[] p; }

String::String(const char* s) {
    size = strlen(s);
    capacity = 2 * size;
    p = new char[2 * size + 1];
    strcpy(p, s);
}

String::String(const String& s) {
    size = s.length();
    capacity = 2 * size;
    p = new char[2 * size + 1];
    for (int i = 0; i < size; i++) {
        p[i] = s.p[i];
    }
    p[size] = '\0';
}

String& String::operator= (const String& s) {
    size = s.length();
    if (size > capacity) {
        delete[] p;
        p = new char[2 * size + 1];
        capacity = 2 * size;
    }
    for (int i = 0; i < size; i++) {
        p[i] = s.p[i];
    }
    p[size] = '\0';
    return *this;
}

String::String(String&& s) {
    capacity = s.capacity;
    size = s.size;
    p = s.p;
    s.p = nullptr;
    s.capacity = 0;
    s.size = 0;
}

String& String::operator= (String&& s) {
    capacity = s.capacity;
    size = s.size;
    delete[] p;
    p = s.p;
    s.p = nullptr;
    s.capacity = 0;
    s.size = 0;
    return *this;
}

size_t String::length() const {
    return size;
}

char& String::operator[] (size_t i) {
    return p[i];
}

const char& String::operator[] (size_t i) const {
    return p[i];
}

bool String::empty() const {
    return size == 0;
}

String& String::operator+= (char c) {
    if (size == capacity) {
        delete[] p;
        capacity = 2 * capacity;
        p = new char[capacity+1];
    }
    p[size] = c;
    size++;
    p[size] = '\0';
    return *this;
}

String& String::operator+= (const String& s) {
    size_t new_size = size + s.length();
    if (new_size > capacity) {
        capacity = 2 * new_size;
    }
    strncpy(p+size, s.p, s.length());
    size = new_size;
    return *this;
}

String& String::operator+= (const char* s) {
    size_t s_size = strlen(s);
    size_t new_size = size + s_size;
    if (new_size > capacity) {
        capacity = 2 * new_size;
    }
    strncpy(p+size, s, s_size);
    size = new_size;
    return *this;
}
