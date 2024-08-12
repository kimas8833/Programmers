#include <iostream>
#include <vector>
#include <execution>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<pair<int, int>> arr(N);

    for(int i=0;i<N;i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }

    sort(arr.begin(), arr.end());

    for(int i=0;i<N;i++)
        cout << arr[i].first<< ' ' << arr[i].second << '\n';
    
    return 0;
}