#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#include <utility> 

#define MAX 99999

using namespace std;
int n, m, l, a, b, p1, p2,x, mode ;
pair<int, int> pr;

vector<int> input;
vector< pair<int, int>  >  changes;

vector< vector<int> > graph;
vector <int> check_node;
vector <int> check_cycle;
stack <int> st;


int dfs(int node){
	if(check_node[node] == 1){return 0;}
	check_node[node] = 1;
	


	for(int i=0; i<graph[node].size(); i++){
		
		if(check_node[graph[node][i]]!=1){
			dfs(graph[node][i]);
		}
		
		else if(check_cycle[graph[node][i]] != 1){
			
			mode=1;
		
		}
	}


	check_cycle[node]=1;
	st.push(node);

	return 0;
}	


int main(){
	scanf("%d", &n); // number of test case
	//printf("\n%d\n", n);
	//input_check.resize(n+1);

	for(int i=0 ; i<n; i++){
		
		scanf("%d", &m); //number of node
		
		check_node.resize(m+1,0);
		check_cycle.resize(m+1,0);
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






		for(int j = 0; j<m-1 ; j++){
			for(int k = j+1; k<m; k++){
				graph[input[j]].push_back(input[k]);
			
			
			}	
		}

		/*
		printf("\n1_____________\n");
		for(int j = 1; j <= m ; j++){
			for(int k = 0; k < graph[j].size(); k++){
				printf("%d ",graph[j][k]);
			
			}	
			printf("\n");
		}
		printf("\n1_____________\n");
		*/

		for(int j = 0; j < l; j ++){
			int check = 0;
			for( int k = 0 ; k < graph[changes[j].first].size() ; k++){
				if(graph[  changes[j].first  ][k] == changes[j].second){
					// swap it 
					graph[  changes[j].first  ].erase( graph[  changes[j].first  ].begin() + k);  

					graph[  changes[j].second ].push_back( changes[j].first );
					
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
						
						check=1;
						break;
					}
				}

			}
		}

		/*
		printf("\n2______________\n");
		for(int j = 1; j <= m ; j++){
			for(int k = 0; k < graph[j].size(); k++){
				printf("%d ",graph[j][k]);
			
			}	
			printf("\n");
		}
		printf("\n2______________\n");
		*/


		/*
		for(int j = 0; j<m-1 ; j++){
			for(int k = j+1; k<m; k++){
				//check if it is changed
				int check = 0;
				for(int x = 0; x<l; x++){
			
					if((input[j] == changes[x].first && input[k] == changes[x].second) || (input[j] == changes[x].second && input[k] == changes[x].first)){
						
						graph[input[k]].push_back(input[j]);
						
						check=1;
					}
				}
				
				if(check == 0){
					
					graph[input[j]].push_back(input[k]);
					
				}
				
			
			}	
		}
		
		*/




		mode=0;
		
		for(int a = 1; a<=m; a++){
			dfs(a);
		}


		// print the result 
		if(mode ==0){
			while(!st.empty()){
				printf("%d ",st.top());
				st.pop();
			}	
				
		}
		else if(mode == 1){           // if it has cycle
			printf("IMPOSSIBLE");
		}

		

		input.clear();
		changes.clear();
		graph.clear();
		check_node.clear();
		check_cycle.clear();
		printf("\n");


	}



}

