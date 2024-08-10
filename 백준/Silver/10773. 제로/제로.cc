#include <iostream>
#include <stack>
#include <string>


using namespace std;


void sum(char &s)
{

}



int main() {
    int T;
    cin >> T;
    stack<int> st;
    int a=0;
    int sum=0;
    while(T--)
    {
        cin >> a;
        if(a!=0)
        {
            st.push(a);
        }
        else
        {
            st.pop();
        }

    }
    while(!st.empty())
    {
        sum=sum+st.top();
        st.pop();
    }
    cout << sum << endl;
    return 0;
}
