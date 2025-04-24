#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    sort(routes.begin(), routes.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    });
    
    int lastcamera = -30001;
    for(const auto& route : routes)
    {
        if(lastcamera < route[0])
        {
            answer++;
            lastcamera = route[1];
        }
    }
         
         
    
    return answer;
}