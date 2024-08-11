#include <iostream>
#include <stack>
#include <vector>
#include <string>


using namespace std;




int main() {

    int N; //1~500,000
    cin >> N;
    vector<int> arr(N);
    vector<int> answer(N);
    stack<pair<int, int>> st;

    for(int i=0;i<N;i++)
    {
        cin >> arr[i];
    }

    for(int i=0;i<N;i++)
    {
        while(!st.empty() && st.top().first <= arr[i])
            st.pop();

        if(st.empty())
            answer[i] = 0;
        else
            answer[i] = st.top().second+1;
        
        st.push({arr[i],i});
    }

    for(int i=0;i<N;i++)
    {
        cout << answer[i] << ' ';
    }


}
