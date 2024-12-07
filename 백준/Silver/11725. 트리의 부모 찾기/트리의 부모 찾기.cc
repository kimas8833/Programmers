#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<vector<int>> graph(N+1);
    vector<int> parent(N+1,0);
    for(int i=0;i<N-1;i++)
    {
        int x,y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
        
    }
    
    queue<int> q;
    q.push(1);
    parent[1] = -1;
    
    while(!q.empty())
    {
        int current = q.front();
        q.pop();
        
        for(int next : graph[current])
        {
            if(parent[next] == 0)
            {
                parent[next] = current;
                q.push(next);
            }
        }
    }
    
    for(int i=2;i<=N;++i)
    {
        cout << parent[i] << '\n';
    }
    return 0;
    
    
}