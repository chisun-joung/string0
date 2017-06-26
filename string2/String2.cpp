//
//  main.cpp
//  string2
//
//  Created by CHISUN JOUNG on 23/06/2017.
//  Copyright © 2017 CHISUN JOUNG. All rights reserved.
//

#include <iostream>
using namespace std;

class StringManager
{
    char* buff;
    int size;
    int* ref;

    
public:
    
    StringManager(): StringManager(""){}
    StringManager(const char* s)
    {
        size = strlen(s);
        buff = new char[size + 1];
        strcpy(buff,s);
        ref = new int;
        *ref = 1;
    }
    ~StringManager()
    {
        if(--(*ref) == 0)
        {
            delete [] buff;
            delete ref;
        }
    }
    
    StringManager(const StringManager& s): buff(s.buff),size(s.size),ref(s.ref)
    {
        ++(*ref);
    }
    StringManager& operator=(const StringManager& s)
    {
        if (&s == this) return *this;
        
        size = s.size;
        if(--(*ref) == 0) {
            delete[] buff;
            delete ref;
        }
        buff = s.buff;
        ref = s.ref;
        ++(*ref);
        return *this;
    }
    friend ostream& operator<<(ostream& os, const StringManager& s);
};
ostream& operator<<(ostream& os, const StringManager& s)
{
    os << s.buff;
    return os;
}

/*
class String {
    StringManager* mgr;
public:
    String():String(""){}
    String(const char* s)
    {
        mgr = new StringManager(s);
    }
    ~String() { delete mgr; }
    String(const String& s)
    {
        mgr = new StringManager(*s.mgr);
    }
    String& operator=(const String& s)
    {
        *mgr = *s.mgr;
        return *this;
    }
    
    friend ostream& operator<<(ostream& os, const String& s);
};
 

ostream& operator<<(ostream& os, const String& s)
{
    os << *(s.mgr);
    return os;
}
*/

class String {
    StringManager mgr;
public:
    String():String(""){}
    String(const char* s) : mgr(s)
    {
    }
    String(const String& s) : mgr(s.mgr)
    {
    }
    String& operator=(const String& s)
    {
        mgr = s.mgr;
        return *this;
    }
    
    friend ostream& operator<<(ostream& os, const String& s);
};


ostream& operator<<(ostream& os, const String& s)
{
    os << s.mgr;
    return os;
}


int main() {
    String s1 = "hello";
    cout << s1 << endl;
    
    String s2 = s1;
    cout << s2 << endl;
    
    String s3 = "student ";
    s3 = s1;
    cout << s3 << endl;
    
    s1 = s1;
    cout << s1 << endl;
    
    String s4;
    cout << s4 << endl;
    return 0;
}
