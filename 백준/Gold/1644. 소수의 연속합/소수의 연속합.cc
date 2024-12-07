#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> sieve(int n)
{
    vector<bool> is_prime(n+1, true);
    vector<int> primes;
    
    is_prime[0] = is_prime[1] = false;
    for(int i=2;i<=n;i++)
    {
        if(is_prime[i])
        {
            primes.push_back(i);
            for(int j=i*2; j<=n; j+=i)
            {
                is_prime[j] = false;
            }
        }
    }
    return primes;
}

int main()
{
    int N;
    cin >> N;
    if(N == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    
    vector<int> primes = sieve(N);
    int start =0, end =0, count = 0, sum = 0;
    while(end <= primes.size())
    {
        if(sum >= N)
        {
            if(sum == N)
            {
                count++;
            }
            sum -= primes[start++];
        }
        else
        {
            if(end < primes.size())
            {
                sum += primes[end];
            }
            end++;
        }
    }
    cout << count << endl;
    return 0;
}