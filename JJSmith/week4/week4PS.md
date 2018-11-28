# 4주차 풀이



## 1. Treasure

유형 : 정렬  
난이도 : 1/10  
풀이 :  
정렬 문제의 기초라고 할 수 있다. A배열 요소와 B배열 요소의 순서별 곱의 최솟값을 구하는 문제인데
조건은 B배열의 요소의 순서를 건들지 않고 A배열을 요소의 순을 바꿔서 최솟값을 구하라고 한다.

결국 구하는 건 B요소의 최대값에 A요소의 최솟값을 곱하는 식으로 역 순의 배열의 곱을 구하면 구하고자 하는 최솟값이 나오므로
B배열 요소를 바꾸지 말라했으면 새로운 자료구조를 만들어 정렬 후 곱하면 된다. 따라서 우선순위 큐(Min Heap과 Max Heap)를 만들어
곱해 최솟값을 구했다.
  
배열의 크기 N만큼 도는 포문 3번이 전부 3n 시간복잡도는 O(n)
  
```C++
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int main() {
	int N, min=0;
	priority_queue<int> sortA;
	priority_queue<int,vector<int>, greater<int> > sortB;
	
	cin>>N;
	
	int A[N],B[N];
	
	for(int i=0; i<N; i++) {
		cin>>A[i];
		sortA.push(A[i]);
	}
	
	for(int i=0; i<N; i++) {
		cin>>B[i];
		sortB.push(B[i]);
	}
	
	for(int i=0; i<N; i++) {
		min+=sortA.top()*sortB.top();
		sortA.pop();
		sortB.pop();
	}
	
	cout<<min<<endl;
	
	return 0;
}
```



## 2. WordSort

유형 : 문자열, 정렬   
난이도 : 2/10  
풀이 :   
랜덤 순 중복 가능한 단어를 제거 후 길이 우선 사전 순(오름차순) 정렬하는 문제다.
정렬 문제의 확장판으로 중복제거를 위해 나는 Set이라는 자료구조를 사용했다.
정렬은 Set으로도 좀 되고, 길이가 우선이기에 cmp(사용자 정의 정렬함수)를 만들어
길이 우선, 사전 순 정렬을 헀다.
  
시간복잡도는 퀵 정렬(Sort함수)를 썼기 때문에 O(nLogn)이다.

```C++
#include <vector>
#include <string>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int cmp(const string& a, const string& b) {
	if(a.length()==b.length()) return a<b;
	return a.length()<b.length();
}

int main() {
	int N;
	string str;
	
	cin>>N;
	
	set<string> uni;
	vector<string> res;
	
	for(int i=0; i<N; i++) {
		cin>>str;
		uni.insert(str);
	}
	
	set<string>::iterator it;
	
	for(it=uni.begin(); it!=uni.end(); it++) {
		res.push_back(*it);
	}
	
	sort(res.begin(), res.end(), cmp);
	
	for(int i=0; i<res.size(); i++) {
		cout<<res[i]<<endl;
	}
	
	return 0;
}
```



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
