#include <iostream>
#include <string>
using namespace std;




int main()
{
    int N;
    cin >> N;
    int a=666;
    int count =0;
    while(true)
    {
        if(to_string(a).find("666") != string::npos)
        {
            count++;
        }
        if(count == N)
        {
            cout << a <<endl;
            break;
        }
        a++;

                
    }
    return 0;

}