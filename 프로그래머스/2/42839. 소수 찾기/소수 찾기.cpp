#include <string>
#include <vector>
#include <set>

using namespace std;

// 소수 판별 함수 (sqrt 안 쓰고 i * i <= n 형태로 깔끔하게)
bool isPrime(int n) {
    if (n < 2) return false;     // 0, 1 제외
    if (n == 2) return true;     // 2는 소수
    if (n % 2 == 0) return false; // 2를 제외한 짝수는 모두 소수 아님

    for (int i = 3; 1LL * i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

// DFS로 numbers의 숫자들로 만들 수 있는 모든 숫자 생성
void dfs(const string& numbers,
         string current,
         vector<bool>& used,
         set<int>& candidates)
{
    // current가 비어있지 않으면 숫자로 만들어서 후보에 추가
    if (!current.empty()) {
        int num = stoi(current);
        candidates.insert(num);  // set으로 중복 제거
    }

    // 아직 사용하지 않은 자리의 숫자를 하나씩 붙여나가며 재귀
    for (int i = 0; i < (int)numbers.size(); ++i) {
        if (used[i]) continue;

        used[i] = true;
        dfs(numbers, current + numbers[i], used, candidates);
        used[i] = false; // 백트래킹
    }
}

int solution(string numbers) {
    set<int> candidates;                     // 만들 수 있는 모든 숫자 집합
    vector<bool> used(numbers.size(), false); // 각 자리 사용 여부

    dfs(numbers, "", used, candidates);      // 빈 문자열에서 시작

    int count = 0;
    for (int num : candidates) {
        if (isPrime(num)) ++count;
    }
    return count;
}