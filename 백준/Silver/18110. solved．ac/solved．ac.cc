#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> v;
int n, start, res;

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int nn; cin >> nn;
        v.push_back(nn);
    }
    sort(v.begin(), v.end());
}

void solve() {
    start = (int)round((double)n * 0.15);
    int temp_n = n - start;
    for (int i = start; i < temp_n; i++) {
        res += v[i];
    }
    res = (int)(round((double)res / (temp_n - start)));
    
    if (n != 0)cout << res;
    else cout << 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    input();
    solve();
    
    return 0;
}
