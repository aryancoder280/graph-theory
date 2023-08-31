#include<bits/stdc++.h>
using namespace std;

void print(vector<int>graph[],int vertices) {

    for(int i=0;i<=vertices;i++) {
        cout<<i<<"-->";
        for(int j=0;j<graph[i].size();j++) {
            cout<<graph[i][j]<<",";
        }
        cout<<endl;
    }
}
void dijkstra(vector<pair<int,int> >graph[],int n,int src) {

    vector<int>dis(n,INT_MAX);
    set<pair<int,int> >s;
    vector<pair<int,int>>ans;
    dis[src] = 0;
    s.insert({0,src});

    while(!s.empty()) {
        auto it = s.begin();
        int node = it->second;
        int nodeDis = it->first;
        ans.push_back({node,nodeDis});
        s.erase(it);

        for(int i=0;i<graph[node].size();i++) {
            auto it2 = graph[node][i];
            int nbr = it2.first;
            int w = it2.second;
            if(w + nodeDis < dis[nbr]) {
                s.erase({dis[nbr],nbr});
                dis[nbr] = w + nodeDis;
                s.insert({dis[nbr],nbr});
            }
        }
    }
    for(int i=0;i<ans.size();i++) cout<<ans[i].first<<" "<<ans[i].second<<endl;

}
int main() {
    int vertices,edges;
    cin>>vertices>>edges;
    vector<pair<int,int> >graph[vertices+1];
    for(int i=0;i<edges;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }
    int src;
    cin>>src;
    dijkstra(graph,vertices,src);

}

/*
7 7
0 1
1 2
2 3
3 5
5 6
4 5
0 4
*/

