# 1주차 풀이

## 1. TargetNumber
  
유형 : 재귀, DFS  
난이도 : 4/10  
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
  
## 2. 124Number  
  
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
# 3. RemovingPairs   
  
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
    
문자열의 길이만큼 반복하므로(정비례) 시간복잡도는 O(n)    
    
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
# 4. IronBar  
  
유형 : 구현, 스택  
난이도 : 4/10  
풀이 :   
스택 구현문제 중에 살짝 어려운 편에 속한다고 생각한다.  
우선 () 괄호를 사용한 문제가 나왔다면 스택을 써야겠다고 마음먹으면 된다.  
(로 열렸으면 언젠가 )로 닫혀야 되기 때문이다.  
즉, 열린 것만 스택에 넣어 닫힌 거가 나오면 열린 걸 제거하고 뭔가 하면된다.  
핵심 포인트는 이전 문자를 비교해서 이전 문자가 (열린 문자인데 현재 문자가 )닫힌 문자이면  
()자르기가 나오기 때문에 스택에 담긴 열린크기 만큼 더해주고,  
그게 아니라는 말은 ))이므로 전에 ()로 잘렸던 적이 있기에   
)닫힌애 조각(1)만 더해주면 된다.  
  
시간복잡도는 문자열의 갯수만큼 판단 O(n)  
  
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
  
# 5. SelfNumber   
유형 : 구현, 재귀  
난이도 : 2/10  
풀이 :   
사실 문제에서 해결방법이 거의 나와서 난이도를 낮게 줬다.  
(p.s d(d(n)) 이거 재귀라고 다 말해주잖아.)  
단, 이 문제는 규칙을 찾으려고 하면 골치아픈 문제다.  
나도 찾으려다가 찾은 줄 알고 실수하고 결국 단순히 풀었다.  
  
bool형태로 selfNum이 아닌 경우를 제거하는 식으로 풀었다.  
내가 자리수 더할 때 쓰는 유용한 방법으로   
10(자리수)을 먼저 곱해주면   
나눠주는 것과 나머지(자리수) 더하기를 한줄로 표현할 수 있다.  
```
n*=10;
res+=(n/=10)%10;
```  
  
내 코드의 시간복잡도는 n만큼 d(n)을 구해야하므로 O(nlogn)와 유사하다.  
  
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
