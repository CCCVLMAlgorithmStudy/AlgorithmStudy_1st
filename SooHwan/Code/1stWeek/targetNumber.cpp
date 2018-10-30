#include <string>
#include <vector>

using namespace std;

void CanGetTargetNumber(vector<int>& numbers,int currentIndex,int lastIndex,int target,int& answer){
    if(currentIndex == lastIndex){
        int lastValueAdded = target + numbers[currentIndex];
        if(lastValueAdded == 0)
            answer += 1;

        int lastValueSub = target - numbers[currentIndex];
        if(lastValueSub == 0)
            answer += 1;
    }
    else{
        CanGetTargetNumber(numbers,currentIndex+1, lastIndex, target+numbers[currentIndex], answer);
        CanGetTargetNumber(numbers,currentIndex+1, lastIndex, target-numbers[currentIndex], answer);
    }
}

int solution(vector<int> numbers, int target) {
    int answer = 0;

    CanGetTargetNumber(numbers, 0, numbers.size()-1, target, answer);
    return answer; 
}