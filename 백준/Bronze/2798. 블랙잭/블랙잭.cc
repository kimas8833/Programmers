#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,M;
    cin >> N >> M;
    vector<int> arr(N);
    int max_sum=0;
    for(int i=0;i<N;i++) 
        cin >> arr[i];

    for(int i=0;i<N-2;i++)
    {
        for(int j=i+1;j<N-1;j++)
        {
            for(int k=j+1;k<N;k++)
            {
                
                int sum = arr[i]+arr[j]+arr[k];
                if(sum<=M && sum > max_sum)
                {
                    max_sum=sum;
                    if(max_sum==M)
                    {
                        cout << max_sum;
                        return 0;
                    }

                }

                
                     
            }
        }
    }
    cout << max_sum << '\n';
    return 0;
}