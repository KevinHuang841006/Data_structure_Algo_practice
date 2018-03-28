#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>
#include "memory.h"

using namespace std;

class Solution{
public:
	vector <vector <int> >edge ;
	vector <vector <int> >maps ;
	vector <int> dist;
	vector <int> visit;
	int short_path(vector<vector<int> > roads,int N , int K   ){
		//initialize edge, maps, dist
		initialize(roads,N);
		dist[K]=0;
		
		//dijk
		DIJK(N);
		
		//answer
		make_heap(dist.begin(),dist.end());
		//cout<<*max_element(dist,dist+N)<<endl;
		return dist.front();
	}
	
	void DIJK(int N){
		
		for(int l=0;l<N;l++){           // max choose N node
			//extract min
			int k,tmp=INT_MAX; 		    //min,no_visit node
			for(int i=0;i<N;i++)
				if(visit[i]==0 && dist[i]<tmp){
					k=i;
					tmp=dist[i];
				}
			visit[k]=1;
			cout<<"node:"<<k<<endl;
			// refresh side node
			for(const auto& n:maps[k]){
				if(visit[n]==0)
					dist[ n ] = min(dist[n], dist[k] + edge[k][n] );
			}
			
		}
		
	}
	
	void initialize(vector<vector <int> > roads ,int N){
		//for edge
		for(int i=0;i<N;i++){
			//vector<int >Q (N,INT_MAX);
			edge.push_back(vector<int>(N,INT_MAX));
		}
		
		for(const auto& n : roads)
			edge[ n[0] ][ n[1] ] = n[2];
		//for maps
		for(int i=0;i<N;i++)
			maps.push_back(vector<int>() );
		for(const auto& n: roads)
			maps[ n[0] ].push_back( n[1] );
		//dist(N,0);
		for(int i=0;i<N;i++){
			dist.push_back(INT_MAX);
			visit.push_back(0);
		}
		out_put2(edge,N);
	}
	
	void out_put2(vector<vector<int> > aa, int N){
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++)
				cout<<aa[i][j]<<" ";
			cout<<endl;
		}
	}
	
};

int main(){
	
	vector<vector <int> > Q2;
	vector<int> Q1;
	Q1.push_back(1);
	Q1.push_back(0);
	Q1.push_back(1);
	Q2.push_back(Q1);
	Q1.clear();
	Q1.push_back(1);
	Q1.push_back(2);
	Q1.push_back(1);
	Q2.push_back(Q1);
	Q1.clear();
	Q1.push_back(2);
	Q1.push_back(3);
	Q1.push_back(1);
	Q2.push_back(Q1);
	Q1.clear();
	Solution A;
	int ans=A.short_path(Q2,4,1);
	cout<<ans<<endl;
	
	return 0;
}
