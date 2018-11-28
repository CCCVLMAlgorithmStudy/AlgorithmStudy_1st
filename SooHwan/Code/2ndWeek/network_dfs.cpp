#include <string>
#include <vector>
#include <stack>

using namespace std;

bool *visited;

void dfs(vector<vector<int>>& computers,int n,int vertex){
    if(visited[vertex] == false){
        visited[vertex] = true;
        for(int i = 0;i<n;i++){
            if(i!=vertex&&computers[vertex][i] == 1&&visited[i]==false){
                dfs(computers,n,i);
            }
        }
    }
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    visited = new bool[n];

    for(int i=0;i<n;i++){
        visited[i] = false;
    }

    for(int i=0;i<n;i++){
        if(visited[i] == false){
            dfs(computers,n,i);
            answer++;
        }
    }
    delete[] visited;
    return answer;
}
