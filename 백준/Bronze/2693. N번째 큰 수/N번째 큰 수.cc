#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> arr(10);

    while(N--)
    {
        for(int i=0;i<10;i++)
            cin >> arr[i];

        sort(arr.begin(), arr.end(), greater<int>());

        cout << arr[2] << endl;
        
    }

    return 0;

}
