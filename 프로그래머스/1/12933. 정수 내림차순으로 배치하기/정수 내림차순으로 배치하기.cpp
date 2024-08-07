#include <string>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    string s = to_string(n);
    sort(s.rbegin(),s.rend());
    return stoll(s);
}