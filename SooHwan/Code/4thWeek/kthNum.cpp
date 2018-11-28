#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int> > commands) {
    vector<int> answer;
    
    for(auto i = commands.begin();i!=commands.end();i++){
        std::vector<int> temp;
        int ai = (*i)[0];
        int aj = (*i)[1];
        int ak = (*i)[2];
        temp.resize(aj-ai+1);
        std::copy(array.begin()+ai-1,array.begin()+aj,temp.begin());
        std::sort(temp.begin(),temp.end());
        answer.push_back(*(temp.begin()+ak-1));
    }
    return answer;
}