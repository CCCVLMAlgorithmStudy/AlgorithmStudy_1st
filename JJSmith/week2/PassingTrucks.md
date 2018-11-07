# 2주차 풀이



## 1. PassingTrucks

유형 : 재귀, DFS  
난이도 : 3/10  
풀이 :  
수의 합을 구하는 문제.   
수들은 2가지 케이스만 가지고 있다.   
어떤 수 a라고 했을 때 a나 -a만 가능  

이렇게 특정한 케이스가 정해진 것이 반복 된다는 규칙을 발견했을 땐  
재귀, dp가 떠올라야한다.  
전의 값이 일정하게 누적되지 않으므로 dp를 쓸 문제가 아니다.  
그럼 재귀! 현재 수를 2가지 케이스로 나누어 더한 후 다음 수를 같은 형태로 반복  
마지막에 타겟 값이 맞는지 확인.(p.s 이 부분 때문에 DFS라고 한거)  

수들의 갯수가 n이라고 했을 때  
경우의 수는 2^n 가지   
따라서 시간복잡도는 O(2^n) p.s 그래서 가정한 수의 범위가 작은 것.  

```C++
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int tSize= truck_weights.size();
    vector<pair<int,int>> inBrg;
    int leftw;
    int ableBrg;
    
    answer++;
    inBrg.push_back(make_pair(truck_weights[0],answer+bridge_length));
    leftw = weight- truck_weights[0];
    ableBrg = bridge_length-1;
    truck_weights.erase(truck_weights.begin());
        
    while(!(truck_weights.empty()&&inBrg.empty())) {
        if(inBrg[0].second==answer) {
            leftw+=inBrg[0].first;
            ableBrg+=1;
            inBrg.erase(inBrg.begin());
        }
        
        if(truck_weights.empty()&&inBrg.empty()) break;
        
        if(!truck_weights.empty()&&answer!=1) {
            if(ableBrg>0&&leftw-truck_weights[0]>=0) {
            leftw-=truck_weights[0]; 
            ableBrg-=1;
            inBrg.push_back(make_pair(truck_weights[0],answer+bridge_length));
            truck_weights.erase(truck_weights.begin());
            }
        }
        answer++;
    }
    
    return answer;
}
```



