#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <functional>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    map<int, int> tangerine_counts;
    for(int size : tangerine)
    {
        tangerine_counts[size]++;
    }
    vector<int> counts;
    for(auto const&[size, count] : tangerine_counts)
    {
        counts.push_back(count);
    }
    
    sort(counts.begin(), counts.end(), greater<int>());
    
    for(int count : counts)
    {
        k -= count;
        answer++;
        
        if(k<=0) break;
    }
    
    
    return answer;
}