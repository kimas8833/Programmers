#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);
    stack<int> st;  // 스택에는 건물의 인덱스만 저장합니다.
    long long count = 0;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < N; i++) {
        // 현재 건물보다 낮거나 같은 건물들을 스택에서 제거
        while (!st.empty() && st.top() <= arr[i]) {
            st.pop();
        }

        // 스택에 남아 있는 건물들은 현재 건물에서 볼 수 있는 건물들
        count += st.size();

        // 현재 건물을 스택에 추가
        st.push(arr[i]);
    }

    cout << count << endl;

    return 0;
}
