#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n) {
    int answer = 0;
    std::vector<bool> num;

    for(int i=0;i<=n;i++){
        if(i==0||i==1){
            num.push_back(false);
        }else{
            num.push_back(true);
        }
    }

    for(int i=0;i<=n;i++){
        if(num[i]){
            int temp = i;
            while(temp<=n){
                num[temp] = false;
                temp+=temp;
            }
        }
    }

    std::vector<bool> result;

    std::copy_if(num.begin(),num.end(),std::back_inserter(result),[](bool i){return i;});
    answer = result.size();
    return answer;
}