#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    for(int i=0;i<prices.size();i++)    
    {
        int current_price = prices[i];
        int count =0;
        for(int j=i;j<prices.size();j++)
        {
            count++;
            if(current_price > prices[j])
            {
                break;
            }
        }
        answer.push_back(count-1);
    }
        
    
    return answer;
}