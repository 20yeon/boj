#include <iostream>
#include <queue>

using namespace std;

int n, res = 0;

struct cards{
    int num;
    cards(int x){
        this->num = x;
    }
    bool operator < (const cards& card) const{
        return num > card.num;
    }
};
priority_queue<cards> pq;

void solve(){
    while(pq.size() != 1){
        int temp = pq.top().num;
        pq.pop();
        temp += pq.top().num;
        pq.pop();
        res+=temp;
        pq.push(cards(temp));
    }
    cout<<res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    for(int i = 0; i < n; i++){
        int nums; cin>>nums;
        pq.push(cards(nums));
    }

    solve();

    return 0;
}
