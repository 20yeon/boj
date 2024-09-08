#include <iostream>
#include <queue>

using namespace std;

struct num {
	int x;
	num(int n) { this->x = n; }
	bool operator <(const num& n) const {
		return this->x < n.x;
	}
};

priority_queue<num> pq;
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int m; cin >> m;
		
		if (m > 0) pq.push(num(m));
		else {
		    if(pq.empty()) cout<<0<<"\n";
		    else{
		        cout << pq.top().x << "\n";
			    pq.pop();   
		    }
		}
	}

	return 0;
}