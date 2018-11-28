#include <string>
#include <vector>
#include <algorithm>

using namespace std;


string solution(vector<int> numbers) {
    string answer = "";

    std::sort(numbers.begin(),numbers.end(),[](const int& a,const int& b){
            std::string tempA = std::to_string(a);
            std::string tempB = std::to_string(b);

            return tempA+tempB >tempB+tempA;
    });

    for(auto i = numbers.begin();i!=numbers.end();i++){
        if(answer == "0" && *i == 0){//모든 원소가 0인 경우 0은 1번만 추가 되어야 하기에 걸러줌
            break;
        }
      answer += std::to_string(*i);
    }
    return answer;
}