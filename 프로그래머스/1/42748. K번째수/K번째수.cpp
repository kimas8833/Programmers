#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(auto& command : commands)
    {
        vector<int> ab(array.begin()+command[0]-1,array.begin()+command[1]);
        sort(ab.begin(), ab.end());
        answer.push_back(ab[command[2]-1]);
    }
    return answer;
}