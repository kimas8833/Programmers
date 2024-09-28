#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int dx[] = {0, 0, -1, 1};  // 상, 하, 좌, 우 이동
int dy[] = {-1, 1, 0, 0};

int bfs(const vector<vector<int>>& maps) {
    int n = maps.size();      // 행의 개수
    int m = maps[0].size();   // 열의 개수
    
    vector<vector<bool>> visited(n, vector<bool>(m, false));  // 방문 체크
    queue<pair<pair<int, int>, int>> q;  // (좌표, 이동 횟수)를 저장하는 큐
    
    q.push({{0, 0}, 1});  // 시작점 (0, 0)에서 시작, 이동 횟수는 1
    visited[0][0] = true;
    
    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int count = q.front().second;
        q.pop();
        
        // 도착점에 도달한 경우
        if (x == n - 1 && y == m - 1) {
            return count;
        }
        
        // 상하좌우로 이동
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            // 맵의 범위를 벗어나지 않고, 방문하지 않았으며, 갈 수 있는 곳이면
            if (nx >= 0 && ny >= 0 && nx < n && ny < m && maps[nx][ny] == 1 && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({{nx, ny}, count + 1});
            }
        }
    }
    
    // 도착점에 도달할 수 없는 경우
    return -1;
}

int solution(vector<vector<int>> maps) {
    return bfs(maps);
}
