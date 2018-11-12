#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class CompareProcessTime{
    public:
        template <class T = std::vector<int> >
        bool operator () (T& a, T& b) const{
            return a[1]>b[1];
        }
};

class CompareInputTime{
    public:
        template <class T = std::vector<int> >
        bool operator () (T& a, T& b) const{
            return a[0]>b[0];
        }
};

int solution(vector<vector<int> > jobs) {
    int answer = 0;

    std::priority_queue<vector<int>,vector<vector<int> >, CompareProcessTime> PQ;
    std::sort(jobs.begin(),jobs.end(),CompareInputTime());
    int time = jobs[0][0];

    auto iter = jobs.begin();
    while(iter != jobs.end()||!PQ.empty()){
        while(iter!=jobs.end()&&(*iter)[0]<=time){//작업이 이미 도착해있다면
            PQ.push(*iter++); //도착해 있는 작업들을 모두 Priority Queue에 넣음
        }

        if(!PQ.empty()){
                time += PQ.top()[1]; //작업을 수행한다.
                answer += (time - PQ.top()[0]); //처음 들어온 시간부터 수행 된 시간까지의 차이를 뺀다.
                PQ.pop();     
        }
        else{
            time = (*iter)[0];
        }
    }

    answer /= jobs.size();
    return answer;
}

