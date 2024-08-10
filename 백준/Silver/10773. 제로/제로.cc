#include <iostream>
#include <stack>
#include <string>


using namespace std;



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
        else if(!st.empty())  //pop 전에 스택이 비어 있는지 확인
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
