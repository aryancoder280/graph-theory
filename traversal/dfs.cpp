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

void dfs(vector<int>graph[],int node,bool visited[],bool done[]) {

    for(int i=0;i<graph[node].size();i++) {
        int val = graph[node][i];
        if(!visited[val]) {
            cout<<val<<"->";
            visited[val] = true;
            dfs(graph,val,visited,done);
           // visited[val] = false;
            if(node == 0) cout<<endl;
        }
    }
    done[node] = true;
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
    cout<<"dfs\n";
    bool visited[vertices] = {false},done[vertices] = {false};
    visited[1] = true;
    dfs(graph,1,visited,done);
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
