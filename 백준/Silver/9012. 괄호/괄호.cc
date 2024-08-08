#include <iostream>
#include <stack>
#include <string>


using namespace std;

bool isValidParentheses(const string& s){
    stack<char> st;
    for(char ch : s)
    {
        if(ch == '(')
            st.push(ch);
        else
        {
            if(st.empty())
                return false;
            st.pop();
        }
        
    }
    return st.empty();
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        string s;
        cin >> s;
        if(isValidParentheses(s))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}