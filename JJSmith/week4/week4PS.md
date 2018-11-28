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



## 3. K-Number

유형 : 정렬  
난이도 : 1/10  
풀이 :  
정렬 문제의 기본이라고 할 수 있다. 자료구조의 일부를 잘라서 새로운 임시 자료구조를 만든다음
오름차순으로 정렬 후 인덱스 참조로 k번째 넘버를 구한다음 답 그릇에 담으면 된다.
인덱스는 0번부터 시작한다는 것을 생각해서 구현하면 끝.

command에 따라 실제 정렬하는 요소의 길이가 달라지므로 사실상 시간 복잡도가 애매하긴 하다
command로 자른 배열의 실제 길이를 n, command의 수를 m이라 했을 때 시간복잡도는 O(nLogn*m)    
​    

```c++
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> tmp;
    
    for(auto c : commands) {
        tmp.assign(array.begin()+c[0]-1,array.begin()+c[1]);
        sort(tmp.begin(), tmp.end());
        answer.push_back(tmp[c[2]-1]);
    }
    
    return answer;
}
```
