#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int solution(int n, vector<vector<int> > edge) {
    int answer = 1;
    const int INF = 123456789;
    std::vector<std::vector<int> > adj(n,std::vector<int>(n,INF));

    for (auto i:edge){
        adj[i[0]-1][i[1]-1] = adj[i[1]-1][i[0]-1] = 1;
    }

    for(int i=0;i<n;i++){
        adj[i][i] = 0;
    }

    std::vector<int> dist(n,INF);
    std::priority_queue <std::pair <int,int> > PQ;

    dist[0] = 0;

    for(int i=0;i<dist.size();i++){
        PQ.push( {dist[i] ,i } );
    }

    while(!PQ.empty()){
        auto temp = PQ.top(); PQ.pop();
        int distance = temp.first;
        int index = temp.second;
        if(dist[index]>distance){
            for(int i=0;i<n;i++){
                if(adj[index][i]==1){
                    dist[i] = dist[i] > dist[index]+adj[index][i]? dist[i] : dist[index]+adj[index][i];
                    PQ.push({dist[i], i});
                }
            }
        }
    }
    std::sort(dist.begin(),dist.end());
    int longest = dist.back();
    for(auto i = adj[0].rbegin()+1;i != adj[0].rend();i++){
            if(*i!=longest)
                break;
            answer++;
    }
        
    return answer;
}