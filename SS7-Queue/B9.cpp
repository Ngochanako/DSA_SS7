#include<bits/stdc++.h>
using namespace std;
//ham them phan tu vao danh sach ke trong do thi vo huong
void addEdge(map<char,vector<char>>& adjList,char u, char v){
	adjList[u].push_back(v);
	adjList[v].push_back(u);
}
int main(){
	map<char,int> dp;
	map<char,bool> check;
	map<char, vector<char>> adjList;

    // Thêm các canh vao do thi
    addEdge(adjList, 'A', 'B');
    addEdge(adjList, 'A', 'C');
    addEdge(adjList, 'B', 'D');
    addEdge(adjList, 'C', 'D');
    addEdge(adjList, 'C', 'E');
    //khoi tao gia tri mac dinh
    for(auto pair:adjList){
    	dp[pair.first]=INT_MAX;
    	check[pair.first]=false;
	}
    //tinh duong di ngan nhat tu dinh A den cac canh
    queue<char> q;
    q.push('A');
    check['A']=true;
    dp['A']=0;
    while(!q.empty()){
    	char t=q.front();   	
    	q.pop();
    	for(char x:adjList[t]){
    		if(!check[x]){
    			check[x]=true;
    			dp[x]=dp[t]+1;
    			q.push(x);
			}
		}
	}
	//in ra duong di ngan nhat den cac dinh
	for(auto pair: dp){
		if(pair.second==INT_MAX){
			cout<<"Khong co duong di den :"<<pair.first<<endl;
		}else{
			cout<<"Duong di ngan nhat tu A den "<<pair.first<<" la:"<<pair.second<<endl;
		}
	}
}
