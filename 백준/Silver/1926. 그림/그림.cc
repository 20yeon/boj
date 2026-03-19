#include <iostream>
#include <vector>

using namespace std;

int painting[500][500];
bool visited[500][500];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int n,m, painting_nums = 0, biggest_painting = 0, temp_count;

void solve(int x, int y){
    if(visited[y][x] == true || painting[y][x] == 0) return;

    visited[y][x] = true;
    temp_count++;
    
    for(int i = 0; i < 4; i++){
        int next_x = x + dx[i], next_y = y + dy[i];
        if(next_x < 0 || next_x >= 500 || next_y < 0 || next_y >= 500) continue;
        solve(next_x, next_y);
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cin>>painting[i][j];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(painting[i][j] == 1 && visited[i][j] == false){
                temp_count = 0;
                solve(j, i);
                painting_nums++;
                biggest_painting = (temp_count > biggest_painting) ? temp_count : biggest_painting;
            }
        }
    }
    cout<<painting_nums<<"\n"<<biggest_painting;
    return 0;
}