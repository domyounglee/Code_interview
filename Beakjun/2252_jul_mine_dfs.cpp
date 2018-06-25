#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>

#define MAX 99999
using namespace std;
int n, m, a, b;

vector<vector<int> > graph;
stack<int> st;
int check[MAX]={0,};




int dfs(int node){
	if(check[node]==1) return 0;
	check[node]=1;

	for(int i=0;i<graph[node].size();i++){
		if(check[graph[node][i]]!=1){
			dfs(graph[node][i]);
		}
	
	}

	st.push(node);

	return 0;
}



int main(){
	scanf("%d %d", &n, &m);
    graph.resize(n + 1);
    	

	for(int i = 0;i<m; i++){
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
	}

	for(int i=1 ; i<=n; i++){
		dfs(i);
	}

	while(st.size()){
		printf("%d ",st.top());
		st.pop();
	}
	
	return 0;
}
