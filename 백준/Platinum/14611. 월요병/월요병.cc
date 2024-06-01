#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<cstring>
using namespace std;


int N,M;
const long long maxi = 1e18;
vector<long long> v[300];
long long dist[300][300];
int dx[8]={0,0,1,-1,1,-1,1,-1};
int dy[8]={1,-1,0,0,1,-1,-1,1};
void dijkstra(){
    for(int i=0;i<300;i++){
        fill(dist[i],dist[i]+300,maxi);
    }
    priority_queue<pair<long long,pair<int,int>>> pq;
    // 위쪽 ㅡ
    for(int i=0;i<M;i++){
        int n = v[0][i];
        if(n==-1) continue;
        if(n==-2){
            dist[0][i]=0;pq.push({0,{i,0}});
        }else{
            dist[0][i]=v[0][i];pq.push({dist[0][i],{i,0}});
        }
    }
    // 오른쪽 ㅣ
    for(int i=0;i<N;i++){
        int n = v[i][M-1];
        if(n==-1) continue;
        if(n==-2){
            dist[i][M-1]=0;pq.push({0,{M-1,i}});
        }else{
            dist[i][M-1]=v[i][M-1];pq.push({dist[i][M-1],{M-1,i}});
        }
    }
    while(!pq.empty()){
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        int c = -pq.top().first;
        pq.pop();
        for(int i=0;i<8;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx<0||nx>=M||ny<0||ny>=N) continue;
            long long nv = v[ny][nx];
            if(nv==-1) continue;
            if(nv==-2){
                if(dist[ny][nx]>dist[y][x]){
                    dist[ny][nx]=dist[y][x];
                    pq.push({-dist[ny][nx],{nx,ny}});
                }
            }else{
                if(dist[ny][nx]>dist[y][x]+nv){
                    dist[ny][nx]=dist[y][x]+nv;
                    pq.push({-dist[ny][nx],{nx,ny}});
                }
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int t=0;t<M;t++){
            long long a;cin>>a;
            v[i].push_back(a);
        }
    }
    dijkstra();
    long long ans = maxi;
    // 왼쪽 ㅣ
    for(int i=0;i<N;i++){
        ans = min(ans,dist[i][0]);
    }
    // 아래 ㅡ
    for(int i=0;i<M;i++){
        ans = min(ans,dist[N-1][i]);
    }
    if(ans==maxi){
        cout<<"-1";
    }else{
        cout<<ans;
    }
}