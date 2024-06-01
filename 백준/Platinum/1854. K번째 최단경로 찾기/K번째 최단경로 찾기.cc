#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N,M,K;
vector< pair<int,int> > map[1002];
priority_queue<int> kth_queue[1002];

void dijkstra() {
   priority_queue< pair<int,int> > pq; 
   pq.push(make_pair(0,1));
   kth_queue[1].push(0);
   
   while(!pq.empty()) {
       int cur_u = pq.top().second;
       int cur_d = -pq.top().first;
       
       pq.pop();
       
       for (int i = 0; i < map[cur_u].size(); i++) {
           int next_u = map[cur_u][i].first;
           int next_d = map[cur_u][i].second + cur_d;
           
           if (kth_queue[next_u].size() < K) {
               kth_queue[next_u].push(next_d);
               pq.push(make_pair(-next_d,next_u));
           } else if (kth_queue[next_u].top() > next_d) {
               kth_queue[next_u].pop();
               kth_queue[next_u].push(next_d);
               pq.push(make_pair(-next_d,next_u));
           }
       }
   }
}


int main()
{   
    
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
    
    cin >> N >> M >> K;
    
    for (int i = 0; i < M; i++) {
        int u,v,d;
        
        cin >> u >> v >> d;
        
        map[u].push_back(make_pair(v,d));
    }
        
    dijkstra();
    
    for (int i = 1; i <= N; i++) {
        if (kth_queue[i].size() != K) cout << -1 << "\n";
        else cout << kth_queue[i].top() << "\n";
    }
    
    return 0;
}