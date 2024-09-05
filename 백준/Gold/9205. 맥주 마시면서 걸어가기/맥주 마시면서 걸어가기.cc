#include<iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool visited[100],able;
vector<pair<int, int>> store(100);
pair<int, int> festival, home;
int t;


void input(){
    cin>>t;
}

void init(){
    able = false;
    store.clear();
    fill(visited, visited+sizeof(visited)/sizeof(bool),false);
}

bool bfs(int n){
    queue<pair<int, int>> q; q.push({home.first,home.second});
    while(!q.empty()){
        const auto [start_x, start_y] = q.front(); q.pop();
        if(abs(festival.first - start_x)+abs(festival.second-start_y) <= 1000) return true;
        else{
            for(int i = 0; i < n; i++){
                if(visited[i] != 1){
                    const auto[next_x, next_y] = store[i];
                    if(abs(next_x - start_x)+abs(next_y-start_y) <= 1000){
                        visited[i] = true; q.push({next_x, next_y});
                    }
                }else continue;
            }
        }
    }return false;
}

void solve(){
    input();
    for(int i = 0; i < t; i++){
        init();

        int n; cin>>n;
        cin>>home.first>>home.second;
        for(int i = 0; i < n; i++) cin>>store[i].first>>store[i].second;
        cin>>festival.first>>festival.second;

        able = bfs(n);
        if(able) cout<<"happy"<<endl;
        else cout<<"sad"<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}