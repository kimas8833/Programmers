#include <iostream>
#include <string>

using namespace std;

bool han(int n)
{
    int a,b,c;

    a=n/100;
    b=n%100 /10;
    c=n%10;

    return (a == 0) || ((a-b)== (b-c));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, count =0;
    cin >> N;

    for(int i=1;i<=N;i++)
    {
        if(han(i))
        {
            count++;
        }
    }
    cout << count << endl;
    return 0;

}

