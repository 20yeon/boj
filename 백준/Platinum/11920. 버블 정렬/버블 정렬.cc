#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(int argc, const char * argv[]) {

    int N, K;
    priority_queue<int, vector<int>, greater<int>> q;
    
    cin >> N >> K;
    vector<int> v(N + 1);
    
    for(int i = 0;i < N;i++)
        cin >> v[i];

    for(int i = 0;i < K;i++)
        q.push(v[i]);
    
    for(int i = 0;i < N - K;i++){
        q.push(v[i + K]);
        v[i] = q.top();
        q.pop();
    }
    
    for(int i = 0;i < N - K;i++)
        cout << v[i] << " ";
    
    while(!q.empty()){
        cout << q.top() << " ";
        q.pop();
    }
    cout << "\n";
    
    return 0;
}