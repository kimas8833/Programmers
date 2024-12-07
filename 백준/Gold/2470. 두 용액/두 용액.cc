#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    vector<int> vc(N);
    for(int i=0; i<N;i++)
    {
        cin >> vc[i];
    }
    sort(vc.begin(), vc.end());
    int left = 0;
    int right = N-1;
    int closest_sum = 2e9+1;
    int ans1 = 0, ans2 = 0;
    while(left < right)
    {
        int sum = vc[left] + vc[right];
        if(sum == 0)
        {
            cout << vc[left] << " " << vc[right] << '\n';
            return 0;
        }
        
        if(abs(sum) < abs(closest_sum))
        {
            closest_sum = sum;
            ans1 = vc[left];
            ans2 = vc[right];
        }
        if(sum < 0)
        {
            left++;
        }
        else{
            right--;
        }
        
        
            
    }
    cout << ans1 << " "<< ans2 << '\n';
    return 0;
}