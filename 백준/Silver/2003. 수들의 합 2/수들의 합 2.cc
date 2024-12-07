#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M;
    cin >> N >> M;
    vector<int> vc(N);
    for(int i=0;i<N;i++)
    {
        cin >> vc[i];
    }
    int start = 0, end = 0, current_sum = 0, count = 0;
    while(end <=N)
    {
        if(current_sum >=M)
        {
            if(current_sum == M)
            {
                count++;
            }
            current_sum -= vc[start++];
        }
        else
        {
            if(end == N) break;
            current_sum += vc[end++];
        }
    }
    cout << count << '\n';
    return 0;
}