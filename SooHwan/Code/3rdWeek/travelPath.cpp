#include <string>
#include <vector>
#include <map>
#include <list>
#include <algorithm>
using namespace std;

void getEulerCircuit(map<string, list<string> >& path,string here,vector<string>& circuit){
    while(!path[here].empty()){
            string temp = path[here].front();
            path[here].pop_front();
            getEulerCircuit(path,temp,circuit);
    }
    circuit.push_back(here);
}

vector<string> solution(vector<vector<string> > tickets) {
    vector<string> answer;
    std::map<string,list<string> > Path;
    for(auto i = tickets.begin();i!=tickets.end();i++){
        Path[(*i)[0]].push_back((*i)[1]);
    }
    
    for(auto i = Path.begin();i!=Path.end();i++){
        (*i).second.sort();
    }
    
    getEulerCircuit(Path,"ICN",answer);
    reverse(answer.begin(),answer.end());
    return answer;
}

//한붓 그리기 가능 조건
//1. 1개의 그래프여야 하고
//2. I/O의 차이가 0개인 점 뿐이거나 1개인 점이 정확히 2개여야만 한다. 이때 출력이 더 많은 점이 출발점, 입력이 더 많은 점이 도착점이 된다. I/O 의 차이가 모두 0개라면 출발점이 곧 도착점이 된다.
//그래프의 입력은 I/O차이가 0개이거나 1개인 점이 2개인 점 뿐이다.
//1번 이동할 때 마다 이동할 때 사용한 간선을 제외한 새로운 그래프가 나오는데, 이 그래프 역시 한붓 그리기가 가능해야 한다.
//출발 지점에서 #O -1, 도착지점에서 #I -1 => 차이가 2이상 벌어지면 해당 경로를 이용하는 것은 안됨, 그래프가 끊어져도 안 됨.=>그래프 끊어지는 걸 어떻게 점검하지?