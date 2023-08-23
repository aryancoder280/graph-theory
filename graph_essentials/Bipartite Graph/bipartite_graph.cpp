#include<bits/stdc++.h>
using namespace std;

bool color_using_dfs(vector<int>graph[],int node,int visited[],int color,int parent) {

    for(int i=0;i<graph[node].size();i++) {
        int nbr = graph[node][i];
        if(nbr == parent) continue;
        if(visited[nbr] == 0) {
            visited[nbr] = 3-color;
            bool valid = color_using_dfs(graph,nbr,visited,3-color,node);
            if(valid == false) return false;
        }
        else if(visited[nbr]!=3-color) {
            return false;
        }
    }
    return true;
}
bool dfs(vector<int>graph[],int n) {

    int visited[n] = {0}; // 0 means unvisited, 1 means visited and color is 1, 2 means visited means 2;

    int color = 1;
    visited[0] = color;
    bool valid = color_using_dfs(graph,0,visited,color,-1);

    for(int i=0;i<n;i++) cout<<visited[i]<<" ";
    if(valid) return true;
    return false;
}
int main() {
    int n,m;
    cin>>n>>m;

    vector<int>graph[n];
    for(int i=0;i<m;i++) {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    if(!dfs(graph,n)) cout<<"InValid\n";
    else {
        cout<<"Valid\n";
    }
    //BFS or DFS, by coloring the node at each step, current node should have color 1 and nbr should have 2
}
