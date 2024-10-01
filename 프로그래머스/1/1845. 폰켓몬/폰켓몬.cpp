#include <vector>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
    unordered_set<int> unique(nums.begin(), nums.end());
    int max_pick = nums.size()/2;
    return min((int)unique.size(), max_pick);

}