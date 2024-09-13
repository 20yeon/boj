#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, able = 1;
int indegree[1001];
vector<int> res;
vector<int> graph[1001];

void input() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;
        vector<int> link(num, 0);
        for (int j = 0; j < num; j++) {
            cin >> link[j];
        }
        for (int j = 0; j < num - 1; j++) {
            graph[link[j]].push_back(link[j + 1]);
            indegree[link[j + 1]]++;  // link[j+1]의 진입 차수를 증가시킴
        }
    }
}

void solve() {
    queue<int> q;

    // 진입 차수가 0인 노드를 큐에 넣음
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    // 큐를 이용한 위상 정렬 수행
    while (!q.empty()) {
        int cur = q.front();
        res.push_back(cur);  // 노드를 결과에 추가
        q.pop();

        // 현재 노드와 연결된 노드들의 진입 차수를 감소
        for (int j = 0; j < graph[cur].size(); j++) {
            int next = graph[cur][j];
            if (--indegree[next] == 0) {
                q.push(next);
            }
        }
    }

    // 사이클이 있는 경우 처리: 모든 노드를 정렬하지 못했을 경우
    if (res.size() != n) {
        cout << 0 << "\n";
    }
    else {
        for (const auto& elem : res) {
            cout << elem << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    input();
    solve();

    return 0;
}
