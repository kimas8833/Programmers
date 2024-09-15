#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    vector<vector<bool>> graph(n+1, vector<bool>(n+1, false));
    for(const auto& result : results)
    {
        int winner = result[0];
        int loser = result[1];
        graph[winner][loser] = true; // winner가 loser를 이김
    }
    
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(graph[i][k] && graph[k][j])
                {
                    graph[i][j] = true;
                }
                
            }
        }
    }
    
    int answer =0;
    for(int i=1;i<=n;i++)
    {
        int count =0;
        for(int j=1;j<=n;j++)
        {
            if(graph[i][j] || graph[j][i])
            {
                count++;
            }
        }
        if(count == n-1)
        {
            answer++;
        }
    }
    
    return answer;
}