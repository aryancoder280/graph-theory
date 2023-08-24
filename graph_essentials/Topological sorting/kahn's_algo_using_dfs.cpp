#include<bits/stdc++.h>
using namespace std;

void kahnAlgoUsingDfs(int node,vector<int>graph[],int indegree[]) {

    for(int i=0;i<graph[node].size();i++) {
        int val = graph[node][i];
        indegree[val]--;
        if(indegree[val] == 0 && indegree[val]!=-1) {
            cout<<val<<",";
            kahnAlgoUsingDfs(val,graph,indegree);
        }
    }
    indegree[node] = -1;
}
int main() {
    int n,m;
    cin>>n>>m;
    vector<int>graph[n];
    int indegree[n] = {0};
    for(int i=0;i<m;i++) {
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        indegree[y]++;
    }
    bool visited[n] = {false};
    for(int i=0;i<n;i++) {
        if(indegree[i] == 0 && indegree[i]!=-1) {
            cout<<i<<" ";
            kahnAlgoUsingDfs(i,graph,indegree);
        }
    }

}

