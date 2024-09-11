#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> indegree;
vector<int> graph[32001];
int n,m;

void input(){
    cin>>n>>m;
    indegree.assign(n+1,0);

    for(int i = 0; i < m; i++){
        int n1, n2;
        cin>>n1>>n2;

        graph[n1].push_back(n2);
        indegree[n2]++;
    }
}

void solve(){
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 1; i <= n; i++) if(indegree[i] == 0) pq.push(i);
    

    for(int i = 0; i < n; i++){
        if(pq.empty()) return;

        int cur = pq.top(); pq.pop();
        cout<<cur<<" ";

        for(int j = 0; j < graph[cur].size(); j++){
            int next = graph[cur][j];
            if(--indegree[next] == 0) pq.push(next);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    input();
    solve();
    return 0;
}