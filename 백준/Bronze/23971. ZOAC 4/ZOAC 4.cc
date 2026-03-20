#include<iostream>
using namespace std;
int main(){
    int H, W, N, M;
    cin >> H >> W >> N >> M;
    
    int rows = (H + N) / (N + 1);  // 세로로 앉을 수 있는 행 수
    int cols = (W + M) / (M + 1);  // 가로로 앉을 수 있는 열 수
    
    cout << rows * cols;
    
    return 0;
}