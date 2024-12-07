#include <iostream>
#include <vector>
#include <cstring> // memset 사용

using namespace std;

const int MAX = 50;
int map[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int T, M, N, K;

// DFS 함수
void dfs(int x, int y) {
    visited[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < M && ny >= 0 && ny < N && !visited[nx][ny] && map[nx][ny] == 1) {
            dfs(nx, ny);
        }
    }
}

int main() {
    cin >> T;

    while (T--) {
        cin >> M >> N >> K;

        // 맵과 방문 여부 초기화
        memset(map, 0, sizeof(map));
        memset(visited, 0, sizeof(visited));

        for (int i = 0; i < K; i++) {
            int x, y;
            cin >> x >> y;
            map[x][y] = 1;
        }

        int block_count = 0;

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (map[i][j] == 1 && !visited[i][j]) {
                    dfs(i, j);
                    block_count++;
                }
            }
        }

        cout << block_count << '\n';
    }

    return 0;
}
