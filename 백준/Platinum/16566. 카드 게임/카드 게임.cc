#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int parent[4000001];
int n,m,k;
vector<int> arr;
int Find(int x){
    if(parent[x] ==x) return parent[x];

    return parent[x] = Find(parent[x]);
}

void Union(int x, int y){
    x = Find(x);
    y = Find(y);
    if(x!=y){
        if(x>y) parent[y] = x;
        else parent[x] = y;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for(int i = 0;i<m;i++){
        int num;
        cin >> num;
        arr.push_back(num);
        parent[i] = i;
    }
    sort(arr.begin(), arr.end());
    int temp;
    for(int i = 0;i<k;i++){
        cin >> temp;
        int index = upper_bound(arr.begin(), arr.end(),temp) - arr.begin();
        int p = Find(index);
        cout << arr[p] << endl;
        Union(p, p + 1);
    }
    return 0;
}