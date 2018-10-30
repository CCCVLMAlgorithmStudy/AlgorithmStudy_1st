#include <iostream>
#include<string>
#include<stack>

using namespace std;

int solution(string s)
{
    int answer = 0;
    std::stack<char> st;

    if(s.empty()){//문자열이 비어있으면 언제나 참
        return 1;
    }

    if(s.size()%2!=0){
        return 0;
    }
    
    for(auto i = s.begin();i!=s.end();i++){
        if(st.empty())//스택이 비어있으면
            st.push(*i);
        else if(st.top() == *i)//짝이면
            st.pop();
        else
            st.push(*i);
    }

    if(st.empty()){
        answer = 1;
    }
    else{
        answer = 0;
    }

    return answer;
}