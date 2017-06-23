//
//  main.cpp
//  string0
//
//  Created by CHISUN JOUNG on 23/06/2017.
//  Copyright © 2017 CHISUN JOUNG. All rights reserved.
//
#include <iostream>
using namespace std;
class String
{
    char* buff;
    int size;
    
public:
    String(): String(""){}
    String(const char* s)
    {
        size = strlen(s);
        buff = new char[size + 1];
        strcpy(buff,s);
    }
    ~String() { delete [] buff; }
    String(const String& s): size(s.size)
    {
        buff = new char[size + 1];
        strcpy(buff, s.buff);
    }
    String& operator=(const String& s)
    {
        if (&s == this) return *this;
        
        size = s.size;
        delete[] buff;
        
        buff = new char[size + 1];
        strcpy(buff, s.buff);
        return *this;
    }
    friend ostream& operator<<(ostream& os, const String& s);
};
ostream& operator<<(ostream& os, const String& s)
{
    os << s.buff;
    return os;
}

int main() {
    String s1 = "hello";
    cout << s1 << endl;
    
    String s2 = s1;
    cout << s2 << endl;
    
    String s3 = "student";
    s3 = s1;
    cout << s3 << endl;
    
    s1 = s1;
    cout << s1 << endl;
    
    String s4;
    cout << s4 << endl;
    return 0;
}
