#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n, m, k;
long long height,start_index;
vector<long long> seg_tree;

void input() {
    cin >> n >> m >> k;
    height = (long long)ceil(log2(n));
    seg_tree.resize((1 << (height + 1)), 0);

    start_index = 1 << height;
    for (int i = 0; i < n; i++) {
        cin >> seg_tree[i + start_index];
    }
}

long long set_tree(long long node_num) {
    if (node_num*2 >= seg_tree.size()) return seg_tree[node_num];
    else return seg_tree[node_num] = set_tree(node_num * 2) + set_tree(node_num * 2 + 1);
}

void change_value(long long node_num, long long val) {
    long long diff = (long long)(val - seg_tree[node_num]);
    while (node_num > 0) {
        seg_tree[node_num] += diff;
        node_num /= 2;
    }
}

long long get_sum(long long start, long long end) {
    long long partsum = 0;
    while (start <= end) {
        if (start % 2 == 1) partsum += seg_tree[start];
        if (end % 2 == 0) partsum += seg_tree[end];
        start = (start + 1) / 2;
        end = (end - 1) / 2;
    }
    return partsum;
}

void solve() {
    set_tree(1);
    for (int i = 0; i < m + k; i++) {
        int oper;
        long long n1, n2;
        cin >> oper >> n1 >> n2;

        if (oper == 1) change_value(start_index + n1 - 1, n2);
        if (oper == 2) {
            n1 += (start_index - 1);
            n2 += (start_index - 1);

            cout << get_sum(n1, n2)<<'\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    input();
    solve();

    return 0;
}
