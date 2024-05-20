// boj_2217.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, res;
vector<int> rope;

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int weight; cin >> weight;
        rope.push_back(weight);
    }
}

void solve() {
    sort(rope.begin(), rope.end());
    res = rope.back();
    for (int i = rope.size() - 1; i >= 0; i--) {
        if (rope[i] * (rope.size() - i) > res) res = rope[i] * (rope.size() - i);
    }
    cout << res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    input();
    solve();
    
    return 0;
}