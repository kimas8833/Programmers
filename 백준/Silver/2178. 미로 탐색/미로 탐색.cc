#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int N,M;
const int MAX = 100;

int map[MAX][MAX];
int visited[MAX][MAX];

int start_x =0, start_y=0;
int end_x = N-1, end_y = M-1;

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

int main()
{
    cin >> N >> M;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            scanf("%1d",&map[i][j]);
        }
    }
    
    queue<pair<int, int>> q;
    q.push({0,0});
    visited[0][0] = 1;
    
    while(!q.empty())
    {
        int x= q.front().first;
        int y= q.front().second;
        q.pop();
        
        for(int i=0;i<4;i++)
        {
            int nx = x +dx[i];
            int ny = y +dy[i];
            
            if(nx >= 0 && nx < N && ny >= 0 && ny < M && map[nx][ny] == 1 && visited[nx][ny] == 0)
            {
                visited[nx][ny] = visited[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    
    cout << visited[N - 1][M - 1] << endl;
    
    return 0;
    
    
}