#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int findNearestPoint(std::vector<int>& arr,int currentCursor){
    int n = 1;
    
    while(arr[currentCursor+n]==0){
        n = n>0? -n: (-n)+1;
    }
    return currentCursor+n;
}

int solution(string name) {
    int answer = 0;
    std::string temp = name + name;
    std::vector<int> count;
    for(auto i:temp){
        count.push_back(i-'A');
    }
    
    int needToChange = std::count_if(count.begin(),count.end(),[](int a){return a>0;}) / 2;
    int cursor = name.size();
    while(needToChange > 0){
        answer += (25-count[cursor]>=count[cursor]? count[cursor]:26 - count[cursor]); // 위로 가는게 적으면 위로, 아래로 가는게 이득이면 아래로 움직임
        count[cursor%name.size()] = count[name.size()+cursor%name.size()] = 0; // 해당 위치의 값을 0으로 재설정(두 문자열을 이어붙였으니 두 군데 모두 재설정 해줘야 함)
        needToChange--;//움직여야 하는 글자 수 줄임

        if(needToChange!=0){//다음 글자로 커서 움직임. 마지막 글자 바꾸고 나서는 커서를 움직일 필요가 없으므로 걸러줌
            int Nextcursor = findNearestPoint(count,cursor);
            answer += abs(Nextcursor-cursor);
            cursor = Nextcursor;
        }
    }
    return answer;
}
