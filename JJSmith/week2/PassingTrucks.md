# 2주차 풀이



## 1. PassingTrucks

유형 : 스택, 구현  
난이도 : 4/10  
풀이 :  
쇠 막대기처럼 스택 문제 중에 어려운 편에 속하는 문제.  
  
시간을 구하는 문제이므로 시간 단위로 상황 변화를 생각해보면 조금씩 실마리가 보이는 문제다.  
주요 자료구조로는 다리 위에 지나가는 트럭을 pair로 (트럭의 무게, 도착시간)이 담긴 트럭의 정보를 저장했다.  
  
이 때 생각없이 풀어서 다리에 트럭이 들어갈때마다 트럭을 지우는 비효율적인 방법을 선택했다.  
반복문에서 시간을 1씩 늘리고, FIFO구조이므로 pair의 첫번째 항목의 도착시간이 됬을때. 
다리여유무게 회복하게 하였다.  
  
걸리는 시간만큼 반복문 돌기 때문에 트럭의 갯수가 n이고 다리의 길이가 m이라고 했을 때  
최악의 시간은 n* m   
따라서 시간복잡도는 O(n+ m) 에서 O(n* m) 사이 정도된다.  
  
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

