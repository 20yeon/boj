#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[1000001];
bool visited[1000001];
int n, res = 0;

void input(){
    cin>>n;

    for(int i = 0; i < n; i++){
        int start, end; cin>>start>>end;
        graph[start].push_back(end);
        graph[end].push_back(start);
    }
}

int dfs(int start_node){
    visited[start_node]  = true;
    bool adopter = false;
    if(graph[start_node].size() == 0) return 0;
    else{
        for(int i = 0; i < graph[start_node].size(); i++){
            if(!visited[graph[start_node][i]]){
                if(dfs(graph[start_node][i]) == 0){
                    if(!adopter) {
                        adopter = true;
                        res++;
                    }
                }
            }
        }
    }
    if(adopter) return 1;
    else return 0;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    input();
    dfs(1);
    cout<<res;
    return 0;
}