#include <iostream>
#include <cmath>
#include <queue>
#include <vector>

using namespace std;

struct Compare{
    bool operator()(const int& a, const int& b)
    {
        if(abs(a) == abs(b))
        {
            return a > b;
        }
        return abs(a) > abs(b);
    }

    
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    priority_queue<int, vector<int>, Compare> pq;
    
    while(N--)
    {
        int x;
        cin >> x;
        if(x == 0)
        {
            if(pq.empty())
            {
                cout << 0 << '\n';
            }
            else
            {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else
        {
            pq.push(x);
        }
    }
    return 0;
}