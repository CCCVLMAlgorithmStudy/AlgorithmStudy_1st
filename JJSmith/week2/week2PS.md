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



## 2. SetSations

유형 : 진법, 구현  
난이도 : 3/10  
풀이 :   
이 문제는 처음 접하면 어려운게 당연한 문제.   
얼핏보면 3진법 변환이라 생각하기 쉬운데 0의 함정이 있다.  

3진법숫자  
1 1  
2 2  
3 10  
4 11  
5 12  
6 100  
7 101  

124숫자  
1 1  
2 2  
3 4  
4 11  
5 12  
6 14  
7 21  

3진법(120진법)에는 3이라는 숫자는 없고 1자리수 올려주는 용도인 0이 있다.  
하지만 124진법에는 4가 숫자지 올려주는 용도가 아니다.   
따라서 3진법 형태의 변환에서 나누어떨어져 0이나오면 자리수를 맞추기 위해 1씩 빼준다.  

시간복잡도는 3이라는 정수로 나누는 수만큼 반복이므로 O(logn)과 유사하다 볼 수 있다.  

```C++
#include <vector>

using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0, sSize=stations.size(), pos, pre=1, able=w*2+1, area;

    for(int i=0; i<sSize; i++) {
        pos = stations[i];
        if(pre+w<pos) {
            area = ((pos-w) - pre); 
            if(area%able!=0) answer++;
            answer += area/able;
        }
        pre = pos+w+1;
    }
    
    if(pre-1<n) { 
        area = n-(pre-1);
        if(area%able!=0) answer++;
        answer += area/able;
    }

    return answer;
}
```



## 3. Network

유형 : 문자열, 스택  
난이도 : 3/10  
풀이 :   
짝을 찾는 여러 방법이 있겠지만, 항상 시간복잡도와 실제적시간을 고민해야한다.  
문자를 찾아 실제로 제거할 생각은 위험하다.  
문자를 찾아 제거한다는 자체는 찾는 시간과 제거하는 비용 둘다 들어가기에   
실제적시간의 측면에서 매우 불리한 방법이다.  
그래서 스택을 써 한 문자씩 비교해 한 문자만 제거처리하는게 효율적이다.  

처음부터 한 문자씩 불러와 스택이 비어있거나 이전에 넣은 문자(a,b)와 다르면 스택에 넣는다.  
이 경우가 아니면 전 문자와 같다는 말이므로(aa) 이전에 넣은 그 문자를 제거하고 스택에 넣지 않는다.  
(a제거+a를 스택에 안넣음 = aa제거)    
​    
문자열의 길이만큼 반복하므로(정비례) 시간복잡도는 O(n)    
​    

```c++
//DFS
#include <vector>

using namespace std;

vector<bool> isVisited;

void DFS(int s, int num, vector<vector<int>>& cp) {
    isVisited[s]=true;
    for(int i=0; i<num; i++) {
        if(!isVisited[i]&&cp[s][i]) { isVisited[i]=true; DFS(i, num, cp); }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    isVisited.resize(n,false);

    for(int i=0; i<n; i++) {
        if(!isVisited[i]) { answer++; DFS(i, n, computers); }
    }

    return answer;
}

//BFS
#include <queue>

using namespace std;

vector<bool> isVisited;
queue<int> BFS;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0, parent;
    isVisited.resize(n,false);

    for(int i=0; i<n; i++) {
        if(isVisited[i]) continue;
        BFS.push(i);
        isVisited[i]=true;
        while(!BFS.empty()) {
            parent = BFS.front();
            BFS.pop();
            for(int j=0; j<n; j++) {
                if(!isVisited[j]&&computers[parent][j]) { BFS.push(j); isVisited[j]=true; }
            }
        }
        answer++;
    }

    return answer;
}
```