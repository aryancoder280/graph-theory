#include<bits/stdc++.h>
using namespace std;

int find_set(int x,vector<int>&parent) {
    if(parent[x] == -1) return x;
    else {
        return parent[x] = find_set(parent[x],parent);
    }
}
int union_set(vector<int>&parent,int a,int b) {
    int s1 = find_set(a,parent);
    int s2 = find_set(b,parent);
    if(s1!=s2) {
        //cout<<s1<<" "<<s2<<endl;
        if(s1>s2) swap(s1,s2);
        parent[s2] = s1;
    }
    return s1;
}
int solve(vector<vector<int>> matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int>row(n,-1);
    vector<int>col(m,-1);
    vector<int>parent(n*m,-1);
    unordered_set<int>set;
    int ele = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            bool valid = true;
            if(matrix[i][j] == 1) {
                if(row[i] == -1) {
                    row[i] = ele;

                }
                else {
                    union_set(parent,row[i],ele);
                    find_set(ele,parent);
                    valid = false;
                }
                if(col[j] == -1) {
                    col[j] = ele;
                }
                else {
                    union_set(parent,col[j],ele);
                    find_set(ele,parent);
                    valid = false;
                }
                if(valid) {parent[ele] = find_set(ele,parent);cout<<1<<endl;}
            }
            ele++;
        }
    }
    for(int i=0;i<n*m;i++) {
        if(parent[i]!= -1) set.insert(parent[i]);
    }
    return set.size();
}

int main() {
    vector<vector<int>>matrix = {{0,1,0},{0,0,0},{1,0,1}};

    cout<<solve(matrix)<<endl;
}
