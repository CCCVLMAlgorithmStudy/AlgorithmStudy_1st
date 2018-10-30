#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string arrangement) {
    int answer = 0;
    std::stack<char> st;
    bool willBeLaser = false;
    
    for(auto i = arrangement.begin();i!=arrangement.end();i++){
        if(*i == '('){
            st.push(*i);
            willBeLaser = true;
        }
        else{
               st.pop();
            if(willBeLaser){
                answer += st.size();
                willBeLaser = false;
            }
            else{
                answer += 1;
            }
        }
        
    }
        return answer;
}
