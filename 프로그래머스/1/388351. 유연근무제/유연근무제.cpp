#include <string>
#include <vector>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    
    for(int employee = 0; employee < schedules.size(); employee++){ //직원 수만큼 반복
        
        int temp_hour = schedules[employee]/100;
        int temp_minute = (schedules[employee]%100)+10;
    
        if((temp_minute) >= 60){
            temp_hour++;
            temp_minute -= 60;
        }
        
        int dead_line = (temp_hour*100)+temp_minute; //출근 희망시간+10 계산
        
        int current_day = startday;
        bool pass = true;
        for(int day = 0; day < 7; day++){  // timelogs의 7일 데이터를 순회
            // current_day의 요일 확인 (1-7 범위)
            int weekday = ((current_day - 1) % 7) + 1;  // 1~7로 순환
            
            // 토요일(6) 또는 일요일(7)이면 스킵
            if(weekday == 6 || weekday == 7){
                current_day++;
                continue;
            }
            
            // 평일인 경우 출근 시간 체크
            if(timelogs[employee][day] > dead_line){
                pass = false;
                break;
            }
            
            current_day++;
        }
        if(pass) answer++;
    }
    
    return answer;
}