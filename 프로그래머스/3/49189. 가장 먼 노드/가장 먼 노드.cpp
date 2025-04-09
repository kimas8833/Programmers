#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    vector<vector<int>> graph(n + 1);
    vector<int> distance(n + 1, -1);
    queue<int> q;

    // 그래프 생성
    for (const auto& e : edge) {
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
    }

    // BFS 초기 설정
    q.push(1);
    distance[1] = 0;

    // BFS 실행
    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int next : graph[current]) {
            if (distance[next] == -1) {
                distance[next] = distance[current] + 1;
                q.push(next);
            }
        }
    }

    // 최대 거리 계산
    int max_distance = *max_element(distance.begin(), distance.end());
    return count(distance.begin(), distance.end(), max_distance);
}
