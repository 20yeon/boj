#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n, m;
int height,start_index;
vector<int> seg_tree_min;

void input() {
    cin >> n >> m;
    height = (int)ceil(log2(n));
    seg_tree_min.resize((1 << (height + 1)), 0);

    start_index = 1 << height;
    for (int i = 0; i < n; i++) cin >>seg_tree_min[i + start_index];
}

void set_min_tree() {
    for (int i = 0; i < n; i++) {
        int temp_index = start_index + i;
        while (temp_index > 1) {
            if (seg_tree_min[temp_index / 2] != 0) seg_tree_min[temp_index / 2] = (seg_tree_min[temp_index] < seg_tree_min[temp_index / 2]) ? seg_tree_min[temp_index] : seg_tree_min[temp_index / 2];
            else seg_tree_min[temp_index / 2] = seg_tree_min[temp_index];
            temp_index /= 2;
        }
    }
}

int get_min(int start, int end) {
    int min = 1000000001;
    while (start <= end) {
        if (min > seg_tree_min[start]) min = seg_tree_min[start];
        if (min > seg_tree_min[end]) min = seg_tree_min[end];
        start = (start % 2 != 0) ? start / 2 + 1 : start / 2;
        end = (end % 2 == 0) ? end / 2 - 1 : end / 2;
    }
    return min;
}


void solve() {
    set_min_tree();
    
    for (int i = 0; i < m; i++) {
        int n1, n2;
        cin >> n1 >> n2;

        n1 += start_index - 1;
        n2 += start_index - 1;

        cout << get_min(n1, n2)<< "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    input();
    solve();

    return 0;
}
