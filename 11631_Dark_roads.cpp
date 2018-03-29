/*
	min span tree~~~
	
	***tips~~
	1.	sort two dim array: by ascending order, check vector[2]
	sort(data.begin(), 
		 data.end(), 
		 [](const vector<int> &a, const vector<int> &b)
		 { return a[2] < b[2]; } 
		 );
	
	2.  DFS on detect cycle:
       
	   visit[0]: not explore
	   visit[1]: explore once 
	   visit[2]: fully explore
	
	***warning~
	1. don't use: vector<vector <int> > data[50]
		may cost segment fault, initialize step by step
	
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>
#include "memory.h"

using namespace std;
vector <vector <int> > load_data();

class Struct{
public:
	int x;
	int y;
};

class Solution{
public:
	int flag=0;
	int min_span_tree(vector<vector<int> >data, int V,int E){
		
		//count max cost
		int cost=0;
		for(auto n:data)
			cost+=n[2];
		
		//make min heap
		make_heap(data.begin(),data.end(), [](const vector<int> &a, const vector<int> &b) { return a[2] > b[2]; });
		
		vector <vector<int> >ans;
		//pop data sequentially
		while(!data.empty()){
			//cout<<data.front()[0]<<" "<<data.front()[1]<<" "<<data.front()[2]<<endl;
			ans.push_back(data.front());
			if(check_loop(ans,V)==true)
				ans.pop_back();
			pop_heap(data.begin(),data.end(), [](const vector<int> &a, const vector<int> &b) { return a[2] > b[2]; });
			data.pop_back();
		}
		
		out_put(ans);
		
		//count max save cost
		
		for(auto n:ans)
			cost-=n[2];
		
		return cost;
	}
	
	bool check_loop(vector<vector<int> >ans, int V){
			int visit[V]={0};
			//make edge
			vector<vector<int>> edge;
			for(int i=0;i<V;i++)
				edge.push_back(vector<int>());
			for(const auto& n:ans){
				edge[ n[0] ].push_back(n[1]);
				edge[ n[1] ].push_back(n[0]);
			}
			
			
			//detect cycle
			flag=0;
			DFS(edge,visit,ans[0][0]);
			if(flag==1)
				return true;
			else
				return false;
	}
	
	void DFS(vector<vector<int> >edge, int* visit, int K){
		visit[K]=1;
		for(const auto& n: edge[K]){
			if(visit[n]==0)
				DFS(edge,visit,n);
			else if(visit[n]==2)
				flag=1;
		}
		visit[K]=2;
	}
	
	void out_put(vector<vector<int> >data){
		for(const auto& n:data)
			cout<<n[0]<<" "<<n[1]<<" "<<n[2]<<endl;
	}
	
};

int main(){
	vector <vector <int> > data;
	int V=7, E=11;
	data=load_data();
	Solution A;
	cout<<A.min_span_tree(data,V,E)<<endl;
	
	return 0;
}

vector <vector <int> > load_data(){
	vector<vector <int> > Q2;
	vector<int> Q1;
	Q1.push_back(0);
	Q1.push_back(1);
	Q1.push_back(7);
	Q2.push_back(Q1);
	Q1.clear();
	Q1.push_back(0);
	Q1.push_back(3);
	Q1.push_back(5);
	Q2.push_back(Q1);
	Q1.clear();
	Q1.push_back(1);
	Q1.push_back(2);
	Q1.push_back(8);
	Q2.push_back(Q1);
	Q1.clear();
	Q1.push_back(1);
	Q1.push_back(3);
	Q1.push_back(9);
	Q2.push_back(Q1);
	Q1.clear();
	Q1.push_back(1);
	Q1.push_back(4);
	Q1.push_back(7);
	Q2.push_back(Q1);
	Q1.clear();
	Q1.push_back(2);
	Q1.push_back(4);
	Q1.push_back(5);
	Q2.push_back(Q1);
	Q1.clear();
	Q1.push_back(3);
	Q1.push_back(4);
	Q1.push_back(15);
	Q2.push_back(Q1);
	Q1.clear();
	Q1.push_back(3);
	Q1.push_back(5);
	Q1.push_back(6);
	Q2.push_back(Q1);
	Q1.clear();
	Q1.push_back(4);
	Q1.push_back(5);
	Q1.push_back(8);
	Q2.push_back(Q1);
	Q1.clear();
	Q1.push_back(4);
	Q1.push_back(6);
	Q1.push_back(9);
	Q2.push_back(Q1);
	Q1.clear();
	Q1.push_back(5);
	Q1.push_back(6);
	Q1.push_back(11);
	Q2.push_back(Q1);
	Q1.clear();
	return Q2;
	
}
