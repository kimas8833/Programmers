#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
const int MAX = 25;
int map[MAX][MAX];
int visited[MAX][MAX];

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

int dfs(int x, int y)
{
    visited[x][y] = true;
    int count = 1;
    for(int i=0;i<4;i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && nx < N && ny >= 0 && ny <N && !visited[nx][ny] && map[nx][ny] == 1)
        {
            count += dfs(nx,ny);
        }
    }
    return count;
}

int main()
{
    cin >> N;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            scanf("%1d", &map[i][j]);
        }
    }
    vector<int> block_sizes;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(map[i][j] == 1 && !visited[i][j])
            {
                int block_size = dfs(i, j);
                block_sizes.push_back(block_size);
            }
        }
    }
    sort(block_sizes.begin(), block_sizes.end());
    cout << block_sizes.size() << endl;
    for(const auto& block_size : block_sizes)
    {
        cout << block_size << endl;
    }
    return 0;
    
    
}