#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    int row = land.size();
    int col = land[0].size();
    
    for(int i=1;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            int max_prev_row = 0;
            for(int k=0;k<col;k++)
            {
                if(j==k) continue;
                max_prev_row = max(max_prev_row, land[i-1][k]);
            }
            land[i][j] += max_prev_row;
        }
    }


    answer = *max_element(land.back().begin(), land.back().end());
    return answer;
}