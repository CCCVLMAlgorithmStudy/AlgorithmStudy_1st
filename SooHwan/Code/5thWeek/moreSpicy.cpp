#include <string>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    std::priority_queue<int,std::vector<int>, std::greater<int> > Q;

    for(int x:scoville){
        Q.push(x);
    }

    while(Q.top()<K){
        if(Q.size()<2){
            answer = -1;
            break;
        }
        int first = Q.top();
        Q.pop();
        int second = Q.top();
        Q.pop();

        Q.push(first+2*second);
        answer++;
    }
    return answer;
}