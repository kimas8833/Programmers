#include <iostream>
#include <queue>

using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    int a;
    queue<int> q;
    string st;
    cin >> N;
    while(N--)
    {
        cin >> st;
        if(st == "push")
        {
            cin >> a;
            q.push(a);
        }
        else if(st == "pop")
        {
            int c;
            if(q.empty())
                cout << "-1\n";
            else
            {
                
                cout << q.front() << '\n';
                q.pop();
            }
            
        }
        else if(st == "size")
        {
            cout << q.size() << '\n';
        }
        else if(st == "empty")
        {
            cout << q.empty() << '\n';
        }
        else if(st == "front")
        {
            if(q.empty())
                cout << "-1\n"; 
            else
                cout << q.front() << '\n';
        }
        else if(st == "back")
        {
            if(q.empty())
                cout << "-1\n";
            else
                cout << q.back() << '\n';
        }
    }

}