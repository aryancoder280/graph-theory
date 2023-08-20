#include<bits/stdc++.h>
using namespace std;

void print(vector<int>graph[],int vertices) {

    for(int i=1;i<=vertices;i++) {
        cout<<i<<"-->";
        for(int j=0;j<graph[i].size();j++) {
            cout<<graph[i][j]<<",";
        }
        cout<<endl;
    }
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
}
