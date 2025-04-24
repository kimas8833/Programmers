#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const vector<int>& a, const vector<int>& b)
{
    return a[1] < b[1];
}

int solution(vector<vector<int>> targets) {
    if(targets.empty()) return 0;
    
    sort(targets.begin(), targets.end(), compare);
    
    int answer = 1;
    int currentEnd = targets[0][1];
    for(int i=1;i<targets.size();i++)
    {
        int start = targets[i][0];
        int end = targets[i][1];
        
        if(start >= currentEnd)
        {
            answer++;
            currentEnd = end;
        }
    }
    return answer;
}