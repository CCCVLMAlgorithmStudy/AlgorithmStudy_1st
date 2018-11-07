#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int coverage = 2 * w + 1;
    
    if(stations.empty()){
        return (n+coverage-1)/coverage;
    }
    
    int prevStation = -w;
    int lastStation = n+w+1;
    stations.push_back(lastStation);
    
    for(auto i = stations.begin();i!=stations.end();i++){
        int range = (*i - w) - (prevStation + w) - 1;
        
        if(range > 0){
            answer += (range+coverage-1) / coverage;     
        }
        prevStation = (*i);
    }
    return answer;
}