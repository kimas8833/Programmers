#include <iostream>
#include <stack>
#include <string>


using namespace std;




int main() {
    string st;
    int n;
    getline(cin, st);
    cin >> n;

    stack<char> left, right;

    for(char c:st)
    {
        left.push(c);
    }

    while(n--)
    {
        char command;
        cin >> command;

        if(command == 'L')
        {
            if(!left.empty())
            {
                right.push(left.top());
                left.pop();
            }
                
        }
        else if(command == 'D')
        {
            if(!right.empty())
            {
                left.push(right.top());
                right.pop();
            }
        }
        else if(command == 'B')
        {
            if(!left.empty())
            {
                left.pop();
            }

        }
        else if(command == 'P')
        {
            char b;
            cin >> b;
            left.push(b);
        }
    }
    while(!left.empty())
    {
        right.push(left.top());
        left.pop();
    }

    while(!right.empty())
    {
        cout << right.top();
        right.pop();
    }

    return 0;
}
