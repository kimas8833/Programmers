#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    vector<int> vc(N);
    for(int i=0;i<N;i++)
    {
        cin >> vc[i];
    }
    int x;
    cin >> x;
    int left = 0;
    int right = N-1;
    sort(vc.begin(),vc.end());
    int count=0;
    while(left < right)
    {
        int sum = vc[left] + vc[right];
        if(sum == x)
        {
            count++;
            left++;
            right--;
        }
        else if (sum < x)
        {
            left++;
        }
        else
        {
            right--;
        }
        
    }
    cout << count << '\n';
    return 0;
        
    
}
