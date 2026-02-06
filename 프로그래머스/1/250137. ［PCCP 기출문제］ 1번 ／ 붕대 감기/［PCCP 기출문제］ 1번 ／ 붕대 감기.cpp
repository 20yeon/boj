#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int casting_time = bandage[0];
    int recovery_amount_per_second = bandage[1];
    int addtional_recovery_amount = bandage[2];
    
    int current_health = health;
    int current_time = 0;
    int success_streak = 0;
    for(int iter = 0; iter < attacks.size();){
        current_time++; //1초가 지남.
        
        //현재 공격 시간 및 데미지
        int current_attack_time = attacks[iter][0];
        int current_attack_damage = attacks[iter][1];
        
        //몬스터의 공격시간
        if(current_time == current_attack_time){
            //연속 성공 초기화
            success_streak = 0;
            //데미지 처리
            current_health -= current_attack_damage;
            if(current_health <= 0) return -1;
            else iter++;
        }else{
            //초당 HP 증가 처리
            if((current_health + recovery_amount_per_second) <= health) current_health += recovery_amount_per_second;
            else current_health = health;
            //연속 성공 처리
            success_streak++;
            //추가 회복량 처리 및 연속 성공 초기화
            if(success_streak == casting_time){
                if((current_health + addtional_recovery_amount) <= health) current_health += addtional_recovery_amount;
                else current_health = health;
                success_streak = 0;
            }
        }
        
    }
    
    int answer = current_health;
    return answer;
}