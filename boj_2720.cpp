// boj_2720.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
#include <iostream>

using namespace std;

int t, q = 25, d = 10, n = 5, p = 1;
void solve() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        int change; cin >> change;
        cout << change / q << " ";
        change %= q;
        cout << change / d << " ";
        change %= d;
        cout << change / n << " ";
        change %= n;
        cout << change / p;
        change %= p;
        cout << endl;
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}