#include <string>
#include <vector>
#include <algorithm>
#include<functional>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    std::sort(citations.begin(),citations.end(),std::greater<int>());

    for(int i=0; i<citations.size(); i++){
        if(citations[i] < i+1){
           break;
        }
         answer = i+1;
    }

    return answer;
}