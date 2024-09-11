#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int t,n,k,w;
int Time[1001], res[1001], indegree[1001];
vector<int> graph[1001];

void initalize(){
    fill(Time, Time+1001, 0);
    fill(indegree, indegree+1001, 0);
    fill(res, res+1001, 0);
    for(int i = 0; i < 1001; i++) graph[i].clear();
}

void input(){
    cin>>n>>k;
    for(int i = 1; i <= n; i++) cin>>Time[i];
    for(int i = 0; i < k; i++){
        int n1, n2; cin>>n1>>n2;
        graph[n1].push_back(n2);
        indegree[n2]++;
    }
    cin>>w;
}
void solve(){
    cin>>t;
    for(int i = 0; i < t; i++){
        initalize();
        input();

        queue<int> q;
        for(int i = 1; i <= n; i++){
            if(indegree[i] == 0){
                q.push(i); res[i] = Time[i];
            }
        }
        while(!q.empty()){
            int cur = q.front(); q.pop();
            for(int i = 0; i < graph[cur].size(); i++){
                int next = graph[cur][i];
                res[next] = (res[next] < res[cur]+Time[next]) ? res[cur]+Time[next] : res[next];
                if(--indegree[next] == 0) q.push(next);
            }
        }
        cout<<res[w]<<endl;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

}