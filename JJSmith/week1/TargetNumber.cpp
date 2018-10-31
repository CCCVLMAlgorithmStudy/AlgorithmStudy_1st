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
