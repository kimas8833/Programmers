#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    // 최대 힙과 최소 힙 선언
    priority_queue<int> maxHeap; // 중간값 이하의 숫자를 저장하는 최대 힙
    priority_queue<int, vector<int>, greater<int>> minHeap; // 중간값 이상의 숫자를 저장하는 최소 힙

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        // 최대 힙에 먼저 넣어줌
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }

        // 두 힙의 크기 조절
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }

        // 현재 중간값 출력
        cout << maxHeap.top() << "\n";
    }

    return 0;
}
