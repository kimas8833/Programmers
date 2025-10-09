#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for(const string& skill_tree : skill_trees)
    {
        string filtered_skill = "";
        for(char c : skill_tree)
        {
            if(skill.find(c) != string::npos)
            {
                filtered_skill += c;
            }
        }
        
        if(skill.find(filtered_skill) == 0)
        {
            answer++;
        }
    }
    return answer;
}