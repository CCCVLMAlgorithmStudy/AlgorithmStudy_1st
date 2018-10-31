#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    string num124[] = {"4","1","2"};
    int num;
        
    while(n>0)
    {
        num = n%3;
        n/=3;
        if(num == 0) n-=1;
        answer= num124[num]+ answer;
    }
    
    return answer;
}
