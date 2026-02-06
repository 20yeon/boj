#include <string>
#include <vector>

using namespace std;

int boxes[100][10];

int solution(int n, int w, int num) {
    int target_row = 0;
    int target_col = 0;
    
    int row = (n % w != 0) ? n / w + 1 : n / w;
    int col = w;
    
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(i % 2 == 0){  // 짝수 행: 왼쪽에서 오른쪽
                if((i * w + j + 1) > n) 
                    boxes[i][j] = 0;
                else {
                    boxes[i][j] = i * w + j + 1;
                    if((i * w + j + 1) == num){
                        target_row = i;
                        target_col = j;
                    }
                }
            } else {
                if((i * w + j + 1) > n) 
                    boxes[i][w - (j + 1)] = 0;
                else {
                    boxes[i][w - (j + 1)] = i * w + j + 1;
                    if((i * w + j + 1) == num){
                        target_row = i;
                        target_col = w - (j + 1);
                    }
                }
            }
        }
    }
    
    // target_col 열에서 target_row부터 위쪽의 상자 개수 세기
    int answer = 0;
    for(int i = target_row; i < row; i++){  // 범위 체크 포함
        if(boxes[i][target_col] != 0){
            answer++;
        }
    }
    
    return answer;
}