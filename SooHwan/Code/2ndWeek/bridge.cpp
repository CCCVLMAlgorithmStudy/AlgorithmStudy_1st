#include <string>
#include <vector>
#include <deque>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;

    int current_weight = 0;
    std::deque<int> Q;
    std::vector<int>::iterator window_start ,window_end;
    window_start = window_end = truck_weights.begin();
    
    while(window_start!=truck_weights.end()){
        answer++;

        for(auto i = Q.begin();i!=Q.end();i++){
            (*i)++;
        }
        if(Q.front()==bridge_length){
            current_weight -= *(window_start++);
            Q.pop_front();
        }

        if(window_end!=truck_weights.end()&&current_weight+(*window_end) <= weight){
            Q.push_back(0);
            current_weight += *(window_end++);
        }
    }

    return answer;
}