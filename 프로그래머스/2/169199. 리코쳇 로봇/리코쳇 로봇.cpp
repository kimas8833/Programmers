#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <iostream>

using namespace std;

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

int bfs(const vector<string>& board, int startX, int startY, int goalX, int goalY)
{
    int n=board.size();
    int m=board[0].size();
    
    vector<vector<int>> visited(n, vector<int>(m,0));
    queue<tuple<int, int, int>> q;
    
    q.push({startX, startY, 0});
    visited[startY][startX] = 1;
    
    while(!q.empty())
    {
        int x, y, count;
        tie(x,y,count) = q.front();
        q.pop();
        
        if(x==goalX && y==goalY)
        {
            return count;
        }
        
        for(int dir = 0; dir<4;++dir)
        {
            int nx = x;
            int ny = y;
            
            while(true)
            {
                int nextX = nx + dx[dir];
                int nextY = ny + dy[dir];
                
                if(nextX <0 || nextX >= m || nextY < 0 || nextY >=n || board[nextY][nextX] == 'D')
                {
                    break;
                }
                
                nx = nextX;
                ny = nextY;
            }
            
            if(!visited[ny][nx])
            {
                visited[ny][nx] = 1;
                q.push({nx, ny, count +1});
            }
        }
    }
    return -1;
}

int solution(vector<string> board) {
    int answer = 0;
    int n=board.size();
    int m=board[0].size();
    
    int startX, startY, goalX, goalY;
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j< m; j++)
        {
            if(board[i][j] == 'R')
            {
                startX = j;
                startY = i;
            }
            else if(board[i][j] == 'G')
            {
                goalX = j;
                goalY = i;
            }
        }
    }
    return bfs(board, startX, startY, goalX, goalY);
}