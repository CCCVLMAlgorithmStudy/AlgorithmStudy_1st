#include <string>
#include <vector>
#include <algorithm>

using namespace std;


string solution(vector<int> numbers) {
    string answer = "";

    std::sort(numbers.begin(),numbers.end(),[](const int& a,const int& b){
            std::string tempA = std::to_string(a);
            std::string tempB = std::to_string(b);

            int length = tempA.size()* tempB.size();
            while(length>tempA.size()){
                tempA += tempA;
            }
            while(length>tempB.size()){
                tempB += tempB;
            }

            return tempA>tempB;
    });

    for(auto i = numbers.begin();i!=numbers.end();i++){
        if(answer == "0" && *i == 0){
            continue;
        }
      answer += std::to_string(*i);
    }
    return answer;
}
