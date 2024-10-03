#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> day;
    for(int i=0; i<speeds.size();i++)
    {
        int count=0;
            
        while(progresses[i]<100)
        {
            count++;
            progresses[i] += speeds[i];
        
        }
        day.push(count);
        
    }
    while(!day.empty())
    {
        int current_day = day.front();
        day.pop();
        int count = 1;
        
        while(!day.empty() && day.front() <= current_day)
        {
            count ++;
            day.pop();
        }
        answer.push_back(count);
    }

    return answer;
}