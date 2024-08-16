#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> st(9);
    vector<int> ans(7);
    int sum=0;

    for(int i=0;i<9;i++)
    {
        cin >> st[i];
        sum += st[i];
    }

    for(int i=0;i<8;i++)
    {
        for(int j=1;j<9;j++)
        {
            if(i!=j)
            {
                if(sum-st[i]-st[j] == 100)
                {
                    st[i]=100;
                    st[j]=100;
                    sort(st.begin(),st.end());
                    for(int z=0;z<7;z++)
                        cout << st[z] << '\n';

                    return 0;
                }

            }
        }
    }

    return 0;

}


