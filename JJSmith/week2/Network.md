# 2주차 풀이



## 3. Network

유형 : BFS, DFS, 그래프, 재귀  
난이도 : 3/10  
풀이 :   
DFS와 BFS두가지 방법으로 풀었다. 사실 두 방법의 큰 차이는 없는 문제였다.  
BFS는 큐를 사용해서 자기를 터트려 자기에 연결된 요소들을 큐에 집어넣는 식으로  
좌우 우선으로 넓게 넓게 퍼저가는 방법이다.  
DFS는 스택이나 재귀를 사용해서 연결된 것으로 먼저 들어가 연결의 끝까지 찾아가보는  
방식으로 깊이(상하) 우선 방법이다.  
  
연결된 객체들의 갯수를 구하는 것이므로  
그래프 문제의 가장 쉬운 문제로도 생각할 수도 있다.  

양방향 그래프이기 때문에 방향성을 생각할 필요가 없고, 사실 상 2차 배열으로 엣지를 만들 필요 없이  
버텍스 정보만 담을 isVisited 불린 배열만 만들어서 풀었다.  
연결된 컴퓨터 정보를 활용해 연결된 컴퓨터를 다 true시키고 연결된 애들을 다 찾으면 네트워크 수를 +1해주는 식으로   
풀면 된다.   
​    
참조여부를 확인해서 결국 컴퓨터의 개수만큼 프로세스가 돌아가므로(정비례) 시간복잡도는 O(n)    
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
