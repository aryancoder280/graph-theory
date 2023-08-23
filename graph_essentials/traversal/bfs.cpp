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

void bfs(vector<int>graph[],int src,int n) {

    queue<int>q;
    q.push(src);
    bool visited[n+1] = {false};
    visited[src] = true;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        cout<<node<<"->";
        //all neighbours
        for(int i=0;i<graph[node].size();i++) {
            int nbr = graph[node][i];
            if(!visited[nbr]) {
                visited[nbr] = true;
                q.push(nbr);
            }
        }
    }
    return;
}
int main() {
    int vertices,edges;
    cin>>vertices>>edges;
    vector<int>graph[vertices+1];
    for(int i=0;i<edges;i++) {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    print(graph,vertices);
    cout<<"bfs\n";
    bfs(graph,0,vertices);
}

