#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int tSize= truck_weights.size();
    vector<pair<int,int>> inBrg;
    int leftw;
    int ableBrg;
    
    answer++;
    inBrg.push_back(make_pair(truck_weights[0],answer+bridge_length));
    leftw = weight- truck_weights[0];
    ableBrg = bridge_length-1;
    truck_weights.erase(truck_weights.begin());
        
    while(!(truck_weights.empty()&&inBrg.empty())) {
        if(inBrg[0].second==answer) {
            leftw+=inBrg[0].first;
            ableBrg+=1;
            inBrg.erase(inBrg.begin());
        }
        
        if(truck_weights.empty()&&inBrg.empty()) break;
        
        if(!truck_weights.empty()&&answer!=1) {
            if(ableBrg>0&&leftw-truck_weights[0]>=0) {
            leftw-=truck_weights[0]; 
            ableBrg-=1;
            inBrg.push_back(make_pair(truck_weights[0],answer+bridge_length));
            truck_weights.erase(truck_weights.begin());
            }
        }
        answer++;
    }
    
    return answer;
}
