# 2주차 풀이



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