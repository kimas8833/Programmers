#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m;
int board[501][501];
bool visited[501][501];

// 상, 하, 좌, 우 네 방향
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    int area = 0;

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        area++;

        // 네 방향으로 이동
        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            // 범위를 벗어나지 않고, 아직 방문하지 않은 1인 경우
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && board[nx][ny] == 1 && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }

    return area;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    int num_pictures = 0;
    int max_area = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 1 && !visited[i][j]) {
                num_pictures++;
                int area = bfs(i, j);
                if (area > max_area) {
                    max_area = area;
                }
            }
        }
    }

    cout << num_pictures << '\n' << max_area << '\n';
    return 0;
}
