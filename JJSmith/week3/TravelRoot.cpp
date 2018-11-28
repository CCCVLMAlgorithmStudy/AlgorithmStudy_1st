#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<pair<string,string>> pss;

pss t;
vector<bool> isVisited;
vector<string> answer;
bool hasAnswer= false;

void DFS(vector<string>& r, string from, string to, int tn, int depth) {    
    if(depth==t.size()) { 
        r.push_back(to);
        hasAnswer=true; 
        answer=r; return; 
    }
    
    for(int i=0; i<t.size(); i++) {
        if(!isVisited[i]) {
            if(to==t[i].first) {
                r.push_back(to);
                isVisited[i]=true;
                DFS(r, to, t[i].second, i, depth+1);
            }
        }
    }
    if(hasAnswer) return;
    isVisited[tn]=false;
    r.pop_back();
}

vector<string> solution(vector<vector<string>> tickets) {
    int tSize = tickets.size();
    vector<string> res;
    string s1, s2;
    
    isVisited.resize(tSize, false);
    
    for(int i=0; i<tSize; i++) {
        s1=tickets[i][0];
        s2=tickets[i][1];
        t.push_back(make_pair(s1, s2));
    }
    
    sort(t.begin(),t.end());
    
    for(int i=0; i<t.size(); i++) {
        if(hasAnswer) break;
        if(t[i].first!="ICN") continue;
        res.push_back(t[i].first);
        isVisited[i]=true;
        DFS(res,t[i].first,t[i].second,i,1);
    }
        
    return answer;
}
