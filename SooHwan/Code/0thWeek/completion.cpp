#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    std::sort(participant.begin(), participant.end());
    std::sort(completion.begin(),completion.end());

    for(auto i = participant.begin(),j = completion.begin();j!=completion.end();i++,j++){
        if(*i != *j)
            return *i;
    }
    return *participant.rbegin();//last participant
}
