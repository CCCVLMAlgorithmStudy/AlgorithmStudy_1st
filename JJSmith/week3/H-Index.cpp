#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int cSize = citations.size();
    int h;
    
    sort(citations.rbegin(), citations.rend());
    
    for(int i=0; i<cSize; i++) {
        h = citations[i];
        if(h >= i+1) answer++;
        else break;
    }
    
    return answer;
}
