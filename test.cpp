#include <iostream>
#include "String.h"
using namespace std;

ostream& operator<< (ostream& os, const String& s) {
    for (size_t i = 0; i < s.length(); i++) os << s[i];
    return os;
}

int main() {
    String s_long = "abcsdkfjsaldkfjasdkfsjdfksdfjaskdfjaskdfjasdkf";
    String s = "abc";
    cout << s << endl;
    cout << s.length() << endl;

    String copied(s_long);
    cout << copied << endl;

    String assigned = s_long;
    cout << assigned << endl;

    s = assigned;
    cout << s << endl;

    String empty = "";
    cout << empty << endl;

    cout << empty.empty() << endl;
}
