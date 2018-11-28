#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> numSort;
    string num, s;
    int nSize=numbers.size();
    int numPos;
    
    if(*max_element(numbers.begin(),numbers.end())==0) return answer="0";
    
    for(int i=0; i<nSize; i++) {
        num = to_string(numbers[i]); s="";
        for(int j=0; j<4; j++) {
            if(num.length()>j) s+=num.substr(j,1)+"a";
            else s+=num.substr(j%num.length(),1)+"a";  //64 < 646, 67 > 676 이여야함
        }
        s+=(char)('f'-num.length());  //3 -> 3a3a3a3ae, 34 -> 3a4a3a4ad 343 -> 3a4a3a3ac, 1000 -> 1a0a0a0ab
        numSort.push_back(s);
    }
    
    sort(numSort.rbegin(),numSort.rend());
    
    for(int i=0; i<nSize; i++) {
        num = numSort[i];
        num.erase(remove(num.begin(),num.end(),'a'), num.end());
        numPos='f'-num[num.length()-1]; //뒤의 알파벳을 사용해 정렬용 생성 문자들 제거
        num.erase(numPos,5-numPos);
        
        answer+=num;
    }
    
    return answer;
}
