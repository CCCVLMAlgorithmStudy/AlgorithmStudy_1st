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









int solution_Conventional(int n, vector<int> stations, int w)
{
    int answer = 0;
    int coverage= 2*w + 1;
    
    int PrevStation = 1;
    stations.push_back(n);//계산의 일관성을 위해 마지막 원소를 임의로 집어넣음
    for(auto i = stations.begin();i!=stations.end();i++){
        if(i == stations.begin()){
            if( 0 >= (*i)-w){
                PrevStation = (*i);
                continue;
            }

            answer += ((*i-w) - PrevStation) / coverage + (((*i-w) - PrevStation) % coverage == 0?0:1);
        }
        else if(i+1 == stations.end()){
            if(PrevStation+w+1>=n){
                PrevStation = (*i);
                continue;
            }
            else{
                answer += ((*i) - (PrevStation+w))/ coverage + (((*i-w) - PrevStation) % coverage == 0?0:1);
            }
        }
        else{
            if(PrevStation+w+1>=(*i)-w){
                 PrevStation = (*i);
                 continue;
            }  

            answer += ((*i-w) - (PrevStation+w)-1)/coverage + (((*i-w) - PrevStation) % coverage == 0?0:1);
        }
        PrevStation = (*i);
    }
    return answer;
}
