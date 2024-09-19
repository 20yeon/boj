#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> v;
int n, res = 2100000000;  // 초기화된 res는 매우 큰 값으로 설정

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int nn;
        cin >> nn;
        v.push_back(nn);
    }
}

void solve() {
    auto left = v.begin();
    auto right = v.end() - 1;

    auto res_left = left;
    auto res_right = right;

    while (left < right) {  // left와 right 포인터로 루프를 돈다
        int temp = (*left) + (*right);

        // 현재 값이 더 최솟값에 가까운지 체크
        if (abs(temp) < abs(res)) {
            res = temp;
            res_left = left;
            res_right = right;
        }

        // 합이 0일 경우 즉시 종료
        if (temp == 0) {
            break;
        }
        else if (temp > 0) {
            right--;  // 합이 0보다 크면 큰 값을 줄이기 위해 right를 왼쪽으로 이동
        }
        else {
            left++;  // 합이 0보다 작으면 작은 값을 키우기 위해 left를 오른쪽으로 이동
        }
    }

    cout << *res_left << " " << *res_right;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    input();
    solve();

    return 0;
}
