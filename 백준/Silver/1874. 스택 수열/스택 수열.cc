#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int n;
    int cur = 0;
    int num = 1;
    cin >> n;
    vector<int> sequence(n);
    stack<int> s;
    vector<char> operations;

    for (int i = 0; i < n; i++) {
        cin >> sequence[i];
    }

    while (cur < n) {
        if (s.empty() || s.top() < sequence[cur]) {
            operations.push_back('+');
            s.push(num++);
        } else if (s.top() == sequence[cur]) {
            operations.push_back('-');
            s.pop();
            cur++;
        } else {
            cout << "NO" << '\n';
            return 0;
        }
    }

    for (char op : operations) {
        cout << op << '\n';
    }

    return 0;
}
