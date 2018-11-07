# 2주차 풀이



## 2. SetSations

유형 : 구현  
난이도 : 3/10  
풀이 :   
항상 문제를 풀때 반복문의 들어갈 내용이나 증감요소를 생각하면 쉽게 풀 수 있다.   
이 구현 문제의 핵심은 이미 설치된 스테이션의 정보를 활용해  
반복문 안에 들어갈 조건을 생각하는 것이다.  
  
스테이션의 중심에서 퍼지는 값을 빼면 터지지 않는 곳의 경계점이고 퍼지는 값을  
더해주면 오른쪽의 터지지 않는 곳의 경계점을 찾을 수 있다.  
여기서 스테이션을 왼쪽부터 찾아가면서 경계점을 통해서 터지지않는 영역을 구해  
스테이션 광역범위로 나눠주면 설치갯수를 구할 수 있다. 단, 터지는 곳에 설치된 스테이션의 경우를  
잡아줘야 하는데 그 경우에는 설치프로세스를 건너뛰고, 오른쪽의 경계점만 리뉴얼 시킨다.  
  
여기서 반복해서 사용하는 값들은 변수에 넣어 재참조가 안되게 했다.  
  
시간복잡도는 스테이션의 갯수의 두배 만큼 반복하므로 정비례 O(n)이다.

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



