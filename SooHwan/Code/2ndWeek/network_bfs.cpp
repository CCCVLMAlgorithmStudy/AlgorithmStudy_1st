#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    bool *visited = new bool[n];
    std::queue<int> Q;

    for(int i=0;i<n;i++){
        visited[i] = false;
    }

    for(int i=0;i<n;i++){
        if(visited[i] == false){
            Q.push(i);
            while(!Q.empty()){
                for(int j = 0;j<n;j++){
                    if(Q.front()!=j&&computers[Q.front()][j] == 1&&visited[j] == false){
                        visited[j] = true;
                        Q.push(j);
                    }
                }
                Q.pop();
            }
            answer++;
        }
    }
    delete[] visited;
    return answer;
}