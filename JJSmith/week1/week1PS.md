1주차 풀이

```
#include <vector>

using namespace std;

int answer = 0;
int tg;

void DFS(vector<int> &n, int preNum, int s) {
    if(s>0) {
        DFS(n, preNum+n[s-1], s-1); //add
        DFS(n, preNum-n[s-1], s-1); //subtract
    } else if(preNum==tg) answer++;
    
    return;
}

int solution(vector<int> numbers, int target) {
    int nSize= numbers.size();
    tg = target;
    
    DFS(numbers, 0, nSize);
    return answer;
}
```

```
#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    string num124[] = {"4","1","2"};
    int num;
        
    while(n>0)
    {
        num = n%3;
        n/=3;
        if(num == 0) n-=1;
        answer= num124[num]+ answer;
    }
    
    return answer;
}
```

```
#include <string>
#include <vector>

using namespace std;

int solution(string s)
{
    int answer = 0;
    int sLen = s.length();
    char c;
    vector<char> st; 
    
    for(int i=0; i<sLen; i++) {
        c=s[i];
        
        if(st.empty()||st.back()!=c) st.push_back(c);
        else st.pop_back();
    }
    
    if(st.empty()) answer = 1;
    
    return answer;
}
```

```
#include <string>
#include <vector>

using namespace std;

int solution(string arrangement) {
    int answer = 0;
    int aSize = arrangement.size();
    vector<char> stack;
    char ch,pre;
    
    for(int i=0; i<aSize; i++) {
        ch = arrangement[i];
        if(ch=='(') stack.push_back(ch);
        else {
            stack.pop_back();
            pre = arrangement[i-1];
            if(pre=='(') answer += stack.size();
            else answer++;
        }
    }
    
    return answer;
}
```

```
#include <iostream>
#include <vector>

using namespace std;

vector<bool> selfNum(10100, true);

int dN(int n) {
	int res = n;
	n*=10;
	do { res+=(n/=10)%10; } while(n>0); 
	
	return res;
}

int main() {
	for(int i=1; i<=10000; i++) {
		selfNum[dN(i)]=false;
	}
	
	for(int i=1; i<=10000; i++) {
		if(selfNum[i]) cout<<i<<endl;
	}
	
	return 0;
}
```
