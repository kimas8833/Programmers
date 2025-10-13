#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    map<string, int> memory_scores;
    for(int i=0;i<name.size();i++)
    {
        memory_scores[name[i]] = yearning[i];
    }
    for(const auto& p : photo)
    {
        int current_photo_score = 0;
        for(const auto& person : p)
        {
            if(memory_scores.count(person))
            {
                current_photo_score += memory_scores[person];
            }
        }
        answer.push_back(current_photo_score);
    }
    
    return answer;
}