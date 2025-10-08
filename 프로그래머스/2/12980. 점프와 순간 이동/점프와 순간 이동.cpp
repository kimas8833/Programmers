#include <iostream>
using namespace std;

int solution(int n)
{
    int ans = 0; // 사용한 배터리 양

    // n이 0이 될 때까지 과정을 반복합니다.
    while (n > 0)
    {
        // n이 짝수인 경우
        if (n % 2 == 0) {
            // 비용이 없는 순간이동(의 역연산)을 수행합니다.
            n /= 2;
        }
        // n이 홀수인 경우
        else {
            // 점프(의 역연산)를 통해 짝수로 만들어 줍니다.
            n -= 1;
            // 배터리를 1 소모합니다.
            ans++;
        }
    }

    return ans;
}