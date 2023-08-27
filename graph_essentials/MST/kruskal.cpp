#include<bits/stdc++.h>
using namespace std;

int find_set(int val,int parent[]) {
    if(parent[val] == -1) return val;

    return parent[val] = find_set(parent[val],parent);
}
bool union_set(int a,int b,int parent[],int ranking[]) {

    int s1 = find_set(a,parent);
    int s2 = find_set(b,parent);
    //cout<<s1<<" "<<s2<<endl;
    if(s1!=s2) {
        if(ranking[s1]<ranking[s2]) {
            swap(s1,s2);
        }
        parent[s2] = s1;
        ranking[s1] +=ranking[s2];
        return true;
    }
    return false;
}
bool comp(pair<pair<int,int>,int>a,pair<pair<int,int>,int>b) {
    if(a.second<b.second) return true;
    return false;
}
int main() {
    int vertices,edges;
    cin>>vertices>>edges;
    vector<pair<pair<int,int>,int> >edgeList;
    for(int i=0;i<edges;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        edgeList.push_back({{u,v},w});
    }
    sort(edgeList.begin(),edgeList.end(),comp);
    int parent[vertices+1];
    int ranking[vertices+1];
    for(int i=0;i<=vertices;i++) {
        parent[i] = -1;
        ranking[i] = 1;
    }
    int ans = 0;

    for(int i=0;i<edgeList.size();i++) {
        auto edge = edgeList[i];
        int u = edge.first.first;
        int v = edge.first.second;
        int w = edge.second;
      //  cout<<u<<" "<<v<<" "<<w<<endl;
        if(!union_set(u,v,parent,ranking)) continue;
        //cout<<u<<" "<<v<<" "<<w<<endl;
        ans+=w;
    }
    cout<<ans<<endl;
}

/*
4 6
0 1 1
0 2 2
0 3 2
1 2 2
1 3 3
2 3 3
*/

