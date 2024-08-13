#include <iostream>
#include <queue>

using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,K;
    cin >> N;
    cin >> K;
    queue<int> q;
    for(int i=0;i<N;i++)
        q.push(i+1);

    cout << '<';
    while(!q.empty())
    {
        for(int i=0;i<K-1;i++)
        {                        
            q.push(q.front());
            q.pop();   
        }
        cout << q.front();
        q.pop();
        if(!q.empty())
            cout << ", ";
    }
    cout << '>';
    return 0;
}
/*
12 3 4567
45 6 712
71 2 45
45 7 1
14 5
14

1(2)3

3(1)

*/