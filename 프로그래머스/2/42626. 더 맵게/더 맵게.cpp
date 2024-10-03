#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> min_heap(scoville.begin(), scoville.end());
    
    while(min_heap.top() < K)
    {
        if(min_heap.size() < 2)
            return -1;
        
        int first = min_heap.top();
        min_heap.pop();
        int second = min_heap.top();
        min_heap.pop();
        
        int make = first + (second * 2);
        min_heap.push(make);
        answer++;
    }
        
    return answer;
}