#include <iostream>
#include "String.h"
using namespace std;

ostream& operator<< (ostream& os, const String& s) {
    for (size_t i = 0; i < s.length(); i++) os << s[i];
    return os;
}

int main() {
    //String s_long = "abcsdkfjsaldkfjasdkfsjdfksdfjaskdfjaskdfjasdkf";
    //String s = "abc";
    //cout << s << endl;
    //cout << s.length() << endl;

    //String copied(s_long);
    //cout << copied << endl;

    //String assigned = s_long;
    //cout << assigned << endl;

    //s = assigned;
    //cout << s << endl;

    //String empty = "";
    //cout << empty << endl;

    //cout << empty.empty() << endl;

    //String modified = "abc";
    //modified[1] = 'd';
    //cout << modified << endl;

    //String to_be_moved = "to_be_moved";
    //String dest(std::move(to_be_moved));
    //cout << to_be_moved << endl;
    //cout << dest << endl;
    //
    //String a;
    //a += 'a';
    //a += 'b';
    //a += 'c';
    //cout << a << endl;

    String h = "hello";
    String w = " world"; 
    h += w;
    h += "dddddddddddddddddddddddddddddddd";
    cout << h << endl;
    
}
