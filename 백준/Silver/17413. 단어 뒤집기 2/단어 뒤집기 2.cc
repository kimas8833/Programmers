#include <iostream>
#include <stack>
#include <string>


using namespace std;

void reverseWords(string &s)
{
    stack<char> st;
    bool insideTag = false;

    for(char c: s)
    {
        if(c == '<')
        {
            while (!st.empty())
            {
                cout << st.top();
                st.pop();
            }
            insideTag =true;
            cout << c;
        }
        else if(c== '>')
        {
            insideTag = false;
            cout << c;
        }
        else if(insideTag)
        {
            cout << c;
        }
        else
        {
            if(c==' ')
            {
                while (!st.empty())
                {
                    cout << st.top();
                    st.pop();
                }
            cout << c;
            }
            else
            {
                st.push(c);
            }
        }

    }
    while(!st.empty())
    {
        cout << st.top();
        st.pop();
    }
}






int main() {
    string s;
    getline(cin,s);
    
    reverseWords(s);

    return 0;
}
