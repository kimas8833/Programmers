#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

string solution(string s) {
    istringstream iss(s);
    vector<int> numbers;
    int number;
    
    while(iss >> number){
        numbers.push_back(number);
    }
    
    int max = *max_element(numbers.begin(),numbers.end());
    int min = *min_element(numbers.begin(),numbers.end());
    
    return to_string(min) + " " +to_string(max);
    
}