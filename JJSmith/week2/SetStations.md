# 2주차 풀이



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



