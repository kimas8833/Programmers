#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    if(arr.size()>1)
    {
        int minElement = *min_element(arr.begin(),arr.end());
        arr.erase(remove(arr.begin(),arr.end(),minElement),arr.end());
    }
    else
    {
        arr.clear();
        arr.push_back(-1);
    }

    return arr;
    
    
}