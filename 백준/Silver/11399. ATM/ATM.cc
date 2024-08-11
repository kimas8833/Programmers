#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    int sum=0;
    cin >> N;

    vector<int> arr(N);

    for(int i=0;i<N;i++)
        cin >> arr[i];
    
    sort(arr.begin(),arr.end());
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<=i;j++)
            sum+=arr[j];
    }
    cout << sum << endl;

}
