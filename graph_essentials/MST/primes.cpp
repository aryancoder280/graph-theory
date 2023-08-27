#include<bits/stdc++.h>
using namespace std;
int main() {
    int vertices,edges;
    cin>>vertices>>edges;
    vector<pair<int,int> >graph[vertices];
    for(int i=0;i<edges;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int> > >pq;
    bool visited[vertices] = {false};


    int ans = 0;

    pq.push({0,0});//source node push in the queue {weight,node}

    while(!pq.empty()) {
        auto best = pq.top();
        pq.pop();

        int to = best.second;
        int weight = best.first;

        if(visited[to]) {
            //discard the edge
            continue;
        }
        ans += weight;
        visited[to] = 1;
        for(int i=0;i<graph[to].size();i++) {
            auto val = graph[to][i];
            if(visited[val.first] == 0) {
                pq.push({val.second,val.first});
            }
        }

    }
    cout<<ans<<endl;
}


