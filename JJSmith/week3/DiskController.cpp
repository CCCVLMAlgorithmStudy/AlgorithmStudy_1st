#include <vector>
#include <queue>
#include <algorithm>

#define PII pair<int,int>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int useTime;
    int jSize = jobs.size();
    vector<int> workingJob;
    bool isStart=true;
    priority_queue<PII,vector<PII>,greater<PII>> minJob; //first - takeTime, second - requestTime
    
    sort(jobs.begin(),jobs.end());
    
    while(!jobs.empty()||!minJob.empty()) {
        if(isStart) {
            workingJob=jobs[0];
            jobs.erase(jobs.begin());
            useTime=workingJob[0]+workingJob[1];
            answer+=workingJob[1];
            isStart=false; 
        } else {
            workingJob[0]=minJob.top().second;
            workingJob[1]=minJob.top().first;
            useTime+=workingJob[1];
            answer+=(useTime-workingJob[0]);
            minJob.pop();
        }
        
        for(int i=0; i<jobs.size(); i++) {
            if(useTime>=jobs[i][0]&&jobs[i][0]>=useTime-workingJob[1]) { minJob.pu  \
                  sh(PII(jobs[i][1],jobs[i][0])); jobs.erase(jobs.begin()+i--);}
        }
        
        if(minJob.empty()) { isStart=true; }
    }
    
    return answer/jSize;
}
