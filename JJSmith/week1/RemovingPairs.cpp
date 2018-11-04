#include <string>
#include <vector>

using namespace std;

int solution(string s)
{
    int answer = 0;
    int sLen = s.length();
    char c;
    vector<char> st; 
    
    for(int i=0; i<sLen; i++) {
        c=s[i];
        
        if(st.empty()||st.back()!=c) st.push_back(c);
        else st.pop_back();
    }
    
    if(st.empty()) answer = 1;
    
    return answer;
}
