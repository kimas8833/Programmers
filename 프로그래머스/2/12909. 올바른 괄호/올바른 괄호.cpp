#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    char a;
    int num = 0;
    for(auto a : s)
    {
        if(a == '(')
        {
            num++;
        }    
        else if(a == ')')
        {
            num--;
        }
        if(num <0)
            return false;
    }
    if(num == 0)    return true;
    else return false;
}