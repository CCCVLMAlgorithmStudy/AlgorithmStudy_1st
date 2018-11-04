#include <string>
#include <vector>

using namespace std;

int solution(string arrangement) {
    int answer = 0;
    int aSize = arrangement.size();
    vector<char> stack;
    char ch,pre;
    
    for(int i=0; i<aSize; i++) {
        ch = arrangement[i];
        if(ch=='(') stack.push_back(ch);
        else {
            stack.pop_back();
            pre = arrangement[i-1];
            if(pre=='(') answer += stack.size();
            else answer++;
        }
    }
    
    return answer;
}
