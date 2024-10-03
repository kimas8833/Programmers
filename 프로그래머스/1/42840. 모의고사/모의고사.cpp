#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> a;
    a= {1, 2, 3, 4, 5};
    vector<int> b;
    b={2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> c;
    c={3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    int count_a=0;
    int count_b=0;
    int count_c=0;
    
    for(int i=0;i<answers.size();i++)
    {
        if(answers[i] == a[i%5])
        {
            count_a++;
        }
        if(answers[i] == b[i%8])
        {
            count_b++;
        }
        if(answers[i] == c[i%10])
        {
            count_c++;
        }
        
    }
    int max_value = max({count_a, count_b, count_c});
    if(max_value == count_a) answer.push_back(1);
    if(max_value == count_b) answer.push_back(2);
    if(max_value == count_c) answer.push_back(3);
    sort(answer.begin(),answer.end());
    return answer;
}