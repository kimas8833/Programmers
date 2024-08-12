#include <iostream>
#include <vector>
#include <execution>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string num;
    cin >> num;

    sort(num.begin(), num.end(),greater<char>());

    cout << num << '\n';

    return 0;
}