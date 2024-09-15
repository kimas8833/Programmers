#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    vector<vector<int>> dist(n+1, vector<int>(n + 1, INF));
    
    for(int i=1; i<=n;i++)
    {
        dist[i][i] = 0;
    }
    for(const auto& fare : fares)
    {
        int u=fare[0], v=fare[1], w=fare[2];
        dist[u][v] = w;
        dist[v][u] = w;
    }
    
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            if(dist[i][k] == INF) continue;
            for(int j=1;j<=n;j++)
            {
                if(dist[k][j] == INF)continue;
                if(dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    int answer = INF;
    for(int k=1;k<=n;k++)
    {
        if(dist[s][k] == INF || dist[k][a] == INF || dist[k][b] == INF)
            continue;
        int total = dist[s][k] + dist[k][a] + dist[k][b];
        answer = min(answer, total);
    }
    
    return answer;
}