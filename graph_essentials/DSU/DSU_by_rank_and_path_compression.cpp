#include<bits/stdc++.h>
using namespace std;

int findSet(int val,vector<int>parent) {
    if(parent[val] == -1) return val;
    else {
        return parent[val] = findSet(parent[val],parent);
    }
}
void unionSet(int a,int b,vector<int>&parent,vector<int>&ranking) {
    int set1 = findSet(a,parent);
    int set2 = findSet(b,parent);
    if(set1!=set2) {
            if(ranking[set1]<ranking[set2]) {
                swap(set1,set2);
            }
            parent[set2] = set1;
            ranking[set1] += set2;
    }
    return;
}
int main() {
    int n,m;
    cin>>n>>m;
    vector<int>parent(n,-1);
    vector<int>ranking(n,0);
    while(m--) {
        int op;
        cin>>op;
        for(int i=0;i<n;i++) cout<<parent[i]<<" ";
        cout<<endl;
        if(op == 1) {
            int x;
            cin>>x;
            cout<<x<<" belongs to"<<findSet(x,parent);
        }
        else {
            int x,y;
        cin>>x>>y;
            unionSet(x,y,parent,ranking);
        }
    }
}


