#include <iostream>
#include <stack>
#include <string>


using namespace std;

bool isBalanced(string s)
{
    stack<char> st;

    for(char c : s)
    {
        if(c == '(' || c == '[')
        {
            st.push(c);
        }
        else if(c == ')')
        {
            if(st.empty() || st.top() != '(') return false;
            st.pop();
        }
        else  if(c == ']')
        {
            if(st.empty() || st.top() != '[') return false;
            st.pop();
        }
    }
    return st.empty();
}

int main() {
    string s;
    while (true)
    {
        getline(cin, s);
        if(s == ".") break;
        if(isBalanced(s))
        {
            cout << "yes" << '\n';
        }
        else
        {
            cout << "no" << '\n';
        }

    }

    return 0;
}
