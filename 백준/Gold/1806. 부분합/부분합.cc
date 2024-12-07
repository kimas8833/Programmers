#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, S;
    cin >> N >> S;
    vector<int> vc(N);
    for(int i=0;i<N;i++)
    {
        cin >> vc[i];
    }   
    int start =0, end = 0;
    int sum = 0;
    int min_length = 1e9+1;
    while(end < N)
    {
        sum += vc[end];
        
        while(sum >= S)
        {
            min_length = min(min_length, end - start + 1);
            sum -= vc[start++];
        }
        
        end++;
    }
    if(min_length == 1e9+1)
    {
        cout << 0 << '\n';
    }
    else
    {
        cout << min_length << '\n';
    }
    
    return 0;
}