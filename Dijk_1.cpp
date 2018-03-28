/*
    DIJSKTRA~ single path problem
	
	WARNING : g++ -o test2 test2.cpp -std=c++11
	using auto , you need to use c++11
	
	***memset has problem~~~~ : 
	The second parameter to memset() is a single byte. 
	memset() does not fill the specified area of memory with ints
	, but with single bytes.

	If you want to initialize your board array of ints,
	you'll have to do it with the same kind of a loop that 
	your test program uses to print its contents.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>
#include "memory.h"

using namespace std;

class Solution {
public:
	
    vector <vector<int> > maps;
    int edge[300][300];
    int max_int=1e9;
    int dist[500];
    int visit[500]={0};
    
    int networkDelayTime(vector<vector<int> >& times, int N, int K) {
        // initialize
		for(int i=0;i<500;i++){
			vector<int> QQ;
			maps.push_back(QQ);
		}
        memset(edge,-(INT_MAX-1),sizeof(edge));
        memset(dist,-(INT_MAX-1),sizeof(dist));
        dist[K-1]=0;
        make_edge( times);
        make_map(times);
		for(int i=0;i<N;i++){
			cout<<dist[i]<<" ";
			
		}
		cout<<INT_MAX;
		cout<<endl;
        // DIJ
        DIJ(N);
        
		int ans=0;
		for(int i=0;i<N;i++){
			cout<<dist[i]<<" ";
			ans=max(ans,dist[i]);
		}
		cout<<endl;
		return ans;
    }
	
    void DIJ(int N){
        //!!!! find min
		for(int p=0;p<100;p++){
			
			//check
			int flag=1;
			for(int i=0;i<N;i++)
				if(visit[i]==0)
					flag=0;
			if(flag==1)
				break;
			
			
			
			//extract min
        	int tmp=1000000;
			int K;
        	for(int i=0;i<N;i++)
            	if(dist[i]<tmp&&visit[i]==0){
					K=i;
					tmp=dist[i];
				}
        	cout<<K<<endl;
        	visit[K]=1;
			
			//find the counter of : K -> n
        	for(const auto& n : maps[K]){
            	if(visit[ n ]==0){
                	dist[n]=min(dist[n], dist[ K ] + edge[K][n]);
                
            	}
        	}
		}//DIJ(N);
    }
    
    void make_edge(vector<vector<int> >& times){
        for(const auto& n1 : times)
            edge[n1[0]-1][n1[1]-1]=n1[2];
		return;
    }
    
	void make_map(vector<vector<int> >& times){
        for(const auto& n : times)
            maps[ n[0] -1].push_back(n[1]-1);
		return;
    }
	
	
	
};


int main(){
	//cout<<"2"<<endl;
	vector<vector <int> > Q2;
	vector<int> Q1;
	Q1.push_back(2);
	Q1.push_back(1);
	Q1.push_back(1);
	Q2.push_back(Q1);
	Q1.clear();
	Q1.push_back(2);
	Q1.push_back(3);
	Q1.push_back(1);
	Q2.push_back(Q1);
	Q1.clear();
	Q1.push_back(3);
	Q1.push_back(4);
	Q1.push_back(1);
	Q2.push_back(Q1);
	Q1.clear();
	
	//cout<<"2"<<endl;
	int N=4,K=2;
	Solution anss;
	int ans;
	ans=anss.networkDelayTime(Q2, N, K);
	cout<<ans<<endl;
	//cout<<"what?"<<endl;
	return 0;
}
