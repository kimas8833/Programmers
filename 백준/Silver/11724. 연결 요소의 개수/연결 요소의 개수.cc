#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void dfs(int node, const vector<vector<int>>& graph, vector<bool>& visited)
{
    visited[node] = true;
    for(int neighbor : graph[node])
    {
        if(!visited[neighbor])
        {
            dfs(neighbor, graph, visited);
        }
    }
}


int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> graph(N+1);
    vector<bool> visited(N+1, false);
    
    while(M--)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
       
    }
    
    int connected = 0;
    
    for(int i=1;i<=N;i++)
    {
        if(!visited[i])
        {
            dfs(i, graph, visited);
            connected++;
        }
    }
    
    cout << connected << endl;
    
    return 0;
    
}
