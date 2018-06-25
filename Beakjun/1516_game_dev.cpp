#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

#define MAX 99999
using namespace std;
int n, m, a, b, i, j;
vector< vector<int> > graph;
vector< int> val;
vector< int> upd_val;

int indegree[MAX]={0,};



int bfs(){
	queue<int> q;

	for(int i=1;i<=n;i++){
		if (indegree[i]==0){
			q.push(i);

			// if it has no indegree upd_val = val
			upd_val[i] = val[i];
			//printf("%d ",i);
		}
	}


	//iterate until the queue gets empty 
	while(!q.empty()){
		int node = q.front();
		q.pop();
		
		
		for(int j=0; j< graph[node].size();j++){

			int child_node=graph[node][j];
		
			//update the upd_val
			if(upd_val[child_node] == -1){
				upd_val[child_node] = upd_val[node] + val[child_node];
				
			}
			else if(upd_val[node] + val[child_node] > upd_val[child_node]){
					upd_val[child_node] = upd_val[node] + val[child_node];
			}

			//reduce the indegree of the child node 
			indegree[child_node]--;
			//push if it has no indegree
			if (indegree[child_node]==0){
				q.push(child_node);

				//printf("%d ",child_node);
			}
		}
	}
	return 0;
}	



int main(){
	
	scanf("%d",&n);

	graph.resize(n+1);
	val.resize(n+1);
	upd_val.resize(n+1, -1);


	
	for(int a=1; a <= n; a++){
		j=1;
		while(1){
			
			scanf("%d",&b);

			if(b == -1){break;}

			if(j == 1){					// insert to val
				val[a]=b;				// 인덱스 조심 !! j 아니다 a 다. 
			}
			else{
				graph[b].push_back(a);
				indegree[a]++;
			} // insert to  graph
			j++;
		}
	}

	bfs();
	
	for(int a = 1; a <= n; a++){
		printf("%d \n", upd_val[a]);
	}
	
}