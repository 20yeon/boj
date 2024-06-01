#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int p[2250001], r, c;
bool visited[1500][1500];
string map[1500];
queue<int> q;

int find(int n) {
	if (p[n] == n) return n;
	p[n] = find(p[n]);
	return p[n];
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	p[b] = a;
}

void nearbyWater(int t) {
	int y = t / c;
	int x = t % c;
	for (int i = 0; i < 4; i++) {
		int nx = x + dir[i][0];
		int ny = y + dir[i][1];
		int nt = ny * c + nx;
		if (nx >= 0 && nx < c && ny >= 0 && ny < r) {
			if (find(nt) != find(t) && map[ny][nx] == '.') {
				merge(t, nt);
				nearbyWater(nt);
			}
			else if (map[ny][nx] == 'X' && !visited[ny][nx]) {
				visited[ny][nx] = true;
				q.push(nt);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int level = 0, qsize, Lpos1 = -1, Lpos2, nx, ny, nt;
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		cin >> map[i];
		for (int j = 0; j < c; j++) {
			p[i * c + j] = i * c + j;
			if (map[i][j] == 'L') {
				if (Lpos1 == -1)
					Lpos1 = i * c + j;
				else
					Lpos2 = i * c + j;
			}
		}
	}
	nearbyWater(Lpos1);
	nearbyWater(Lpos2);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] == '.')
				nearbyWater(i * c + j);
		}
	}
	while (!q.empty()) {
		if (find(Lpos1) == find(Lpos2)) break;
		level++;
		qsize = q.size();
		while (qsize--) {
			auto& t = q.front();
			int cx = t % c, cy = t / c;
			map[cy][cx] = '.';
			for (int i = 0; i < 4; i++) {
				nx = cx + dir[i][0];
				ny = cy + dir[i][1];
				nt = ny * c + nx;
				if (nx >= 0 && nx < c && ny >= 0 && ny < r) {
					if (map[ny][nx] == '.' || map[ny][nx] == 'L')
						merge(t, nt);
					else if (!visited[ny][nx]) {
						visited[ny][nx] = true;
						q.push(nt);
					}
				}
			}
			q.pop();
		}
	}
	cout << level;
}