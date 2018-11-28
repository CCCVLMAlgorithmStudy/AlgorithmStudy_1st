#include <string>
#include <vector>

using namespace std;

int solution(string arrangement) {
    int rtn = 0;
    int p=0;
    for(int i=0; i<arrangement.size(); i++){
        if(arrangement[i] == '('){
            p++;
        }else{
            p--;
            if(arrangement[i-1] == '('){
                if(p>0)
                    rtn += p;
            }else{
                rtn++;
            }
        }
    }

    return rtn;
}
