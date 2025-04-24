#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int solution(int n, vector<vector<int>> wires) {
    int answer = n;
    
    vector<vector<int>> adj(n+1);
    for(auto &w : wires)
    {
        int u = w[0], v = w[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for(auto &w : wires)
    {
        int cut_u = w[0], cut_v = w[1];
        
        vector<bool> visited(n+1, false);
        queue<int> q;
        int cnt = 0;
        
        q.push(cut_u);
        visited[cut_u] = true;
        
        while(!q.empty())
        {
            int cur = q.front();q.pop();
            cnt++;
            for(int nxt : adj[cur])
            {
                if((cur == cut_u && nxt == cut_v) || (cur == cut_v && nxt == cut_u))
                    continue;
                if(!visited[nxt])
                {
                    visited[nxt] = true;
                    q.push(nxt);
                }
            }
        }
        answer = min(answer, abs(cnt - (n - cnt)));
    }
    return answer;
}