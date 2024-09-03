#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    bool capitalize = true;
    for(int i = 0;i< s.length();i++)
    {
        if(s[i] == ' ')
            capitalize = true;
        else if(capitalize && isalpha(s[i]))
        {
            s[i]=toupper(s[i]);
            capitalize = false;
        }
        else
        {
            s[i]=tolower(s[i]);
            capitalize = false;
            
        }
    }
    return s;
}