#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    answer.push_back(*(arr.begin()));

    for(auto i = arr.begin()+1;i!=arr.end();i++){

        if(*i != *answer.rbegin()){
            answer.push_back(*i);
        }
    }

    return answer;
}