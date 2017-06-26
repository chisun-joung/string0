//
//  main.cpp
//  stl
//
//  Created by CHISUN JOUNG on 26/06/2017.
//  Copyright © 2017 CHISUN JOUNG. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

void print_vector(const vector<int>& v)
{
    for(auto it : v)
        cout << it << ", ";
    
    cout << endl;
}

int main() {

    vector<int> v;
    
    // 1. 난수를 10개 구해서 v에 넣으세요.
   
    for(int i=0; i < 10; ++i) {
        v.push_back(rand()%100 + 1 );
    }
    
    
    int cmd = 0;
    
    while(1)
    {
        cin >> cmd;
        
        // 2. cmd가 1이면 v의 모든 내용을 화면에 출력해 주세요
        if( cmd == 1 )
        {
            print_vector(v);
        }
        //3.cmd가2이면v를오름차순으로정렬한후v의내용을화면출력해주세요
        // 비교 정책으로 함수 객체를 사용해서 만들어 주세요
        if( cmd == 2 )
        {
            vector<int> temp(v);
            sort(temp.begin(),temp.end(), greater<int>());
            print_vector(temp);
        }
        
        //4.cmd가3이면v를내림차순으로정렬한후v의내용을화면출력해주세요
        // 비교 정책으로 람다 표현식을 사용해 주세요
        if ( cmd == 3)
        {
            vector<int> temp(v);
            sort(temp.begin(),temp.end(), [](int a, int b){ return a < b;});
            print_vector(temp);
        }
        
        //5.cmd가4이면또다른숫자를하나입력받으세요.
        // 해당 숫자가 vector에 있으면 제거한후 vector를 다시 출력해 주세요
        if ( cmd == 4 )
        {
            int num;
            cout << "input number (1~100) :";
            cin >> num;
            auto p1 = find(v.begin(), v.end(), num);
            if(p1 != v.end()){
                v.erase(p1);
            }
            print_vector(v);
        }
        
        //6.cmd가5이면또다른숫자를하나입력받으세요.
        // 해당 숫자를 찾아서 0으로 변경한후 vector를 다시 출력해 주세요
        if ( cmd == 5 )
        {
            int num;
            cout << "input number (1~100) :";
            cin >> num;
            auto p1 = find(v.begin(), v.end(), num);
            if(p1 != v.end()){
                *p1 = 0;
            }
            print_vector(v);
        }

        //7.cmd가6이면v의size를20개로늘린후v의내용을출력해주세요
        if ( cmd == 6 )
        {
            v.resize(20);
            print_vector(v);
        }
        
        if( cmd == 0)
            break;
    }
    
    return 0;
}
