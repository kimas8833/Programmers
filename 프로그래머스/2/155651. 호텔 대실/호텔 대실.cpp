#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int to_Min(const string &s)
{
    int h = stoi(s.substr(0,2));
    int m = stoi(s.substr(3,5));
    
    return m + h*60;
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    
    sort(book_time.begin(), book_time.end(), [](auto &a, auto &b){return to_Min(a[0])<to_Min(b[0]);});
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(auto &bt : book_time)
    {
        int start = to_Min(bt[0]);
        int end = to_Min(bt[1])+10;
        
        if(!pq.empty()&&start>=pq.top())
        {
            pq.pop();
        }
        pq.push(end);
    }
    return pq.size();
}