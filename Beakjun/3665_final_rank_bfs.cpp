#include <cstdio>
#include <algorithm>
#include <vector>

#include <utility> 
#include <queue>
#define MAX 99999

using namespace std;
int n, m, l, a, b, p1, p2,x, mode ;
pair<int, int> pr;

vector<int> input;
vector< pair<int, int>  >  changes;

vector< vector<int> > graph;
vector <int> check_node;
vector <int> check_cycle;

vector <int> indegree;


vector <int> result;

int bfs(){
	queue<int> q;

	for(int i=1;i<=m;i++){
		if (indegree[i]==0){
			q.push(i);
		}
	}


	//iterate until the queue gets empty 
	while(!q.empty()){
		int val = q.front();
		q.pop();
		result.push_back(val);

		for(int j=0; j< graph[val].size();j++){
			
			//reduce the indegree of the child node 
			indegree[graph[val][j]]--;

			if (indegree[graph[val][j]]==0){
				q.push(graph[val][j]);
			}
		}
	}
	return 0;
}	



int main(){
	scanf("%d", &n); // number of test case
	//printf("\n%d\n", n);
	//input_check.resize(n+1);

	for(int i=0 ; i<n; i++){
		
		scanf("%d", &m); //number of node
		

		for(int j=0 ; j<m ; j++){
			scanf("%d", &a); 
			
			input.push_back(a);
			
		}
		
		scanf("%d", &l); //number of changes
		//printf("%d\n",l);

		for(int j=0; j<l ;j++){
			
			scanf("%d %d",&p1, &p2);
			
			pr = make_pair(p1, p2);
			
			changes.push_back(pr);
			
		}
		
		//inserted it to the graph
		graph.resize(m+1);
		indegree.resize(m+1);			//important!!!!!!




		for(int j = 0; j<m-1 ; j++){
			for(int k = j+1; k<m; k++){
				graph[input[j]].push_back(input[k]);
				indegree[input[k]]++;
			
			}	
		}


		for(int j = 0; j < l; j ++){
			int check = 0;
			for( int k = 0 ; k < graph[changes[j].first].size() ; k++){
				if(graph[  changes[j].first  ][k] == changes[j].second){
					// swap it 
					graph[  changes[j].first  ].erase( graph[  changes[j].first  ].begin() + k);  

					graph[  changes[j].second ].push_back( changes[j].first );
					
					indegree[changes[j].second]--;
					indegree[changes[j].first]++;
					check=1;
					break;
				}
			}

			if (check == 0){
				for( int k = 0 ; k < graph[changes[j].second].size() ; k++){
					if(graph[  changes[j].second  ][k] == changes[j].first){
						// swap it 
						graph[  changes[j].second  ].erase( graph[  changes[j].second  ].begin() + k);  

						graph[  changes[j].first ].push_back( changes[j].second );
						
						indegree[changes[j].second]++;
						indegree[changes[j].first]--;
						check=1;
						break;
					}
				}

			}
		}




		mode=0;

		bfs();
		

		for(int j= 1 ; j <= m ; j++){
			if(indegree[j] != 0){
				mode =1;
			}
		}
		// print the result 
		if(mode ==0){
			for(int a = 0; a < m; a++){
				printf("%d ", result[a]);
			}
		
		}
		else if(mode == 1){           // if it has cycle
			printf("IMPOSSIBLE");
		}

	

		indegree.clear();

		result.clear();
		input.clear();
		changes.clear();
		graph.clear();
		printf("\n");

	}

	

}

