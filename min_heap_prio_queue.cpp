/*
	Make Priority Queue By vector:
	
	std::make_heap
	std::pop_heap   // don't delete any element, need implement
					//with  vec.pop_back
	(pop_heap()  ->   vec.pop_back)
	
	std::push_heap
	(vec.push_back()   ->   push_heap )
	
	***need overload  :  
	
*/
#include<iostream>
#include<queue>
#include<vector>

using namespace std;

class Student {
public:
	char* chName;
	int nAge;
	Student(): chName(""),nAge(0){}
	Student( char* chNewName, int nNewAge ):chName(chNewName), nAge(nNewAge){}
};


//Overload the < operator.
bool operator< (const Student& structstudent1, const Student &structstudent2)
{
	return structstudent1.nAge > structstudent2.nAge;
}
//Overload the > operator.
bool operator> (const Student& structstudent1, const Student &structstudent2)
{
	return structstudent1.nAge < structstudent2.nAge;
}
//Overload the == operator
bool operator==(const& ans,const& rhs)
{ return ans->nAge == rhs.nAge;}
	

int main(){
	
	//make heap
	vector <Student> Q;
	Q.push_back( Student( "Mark", 38 ) );
	Q.push_back( Student( "Marc", 25 ) );
	Q.push_back( Student( "Bill", 47 ) );
	Q.push_back( Student( "Andy", 13 ) );
	Q.push_back( Student( "Newt", 44 ) );
	make_heap(Q.begin(),Q.end());
	
	// find() in heap
	//vector <int>::iterator it;
	//find (Q.begin(), Q.end(), Student("Mark",38));
	
	
	while(!Q.empty()){	
		cout<<Q[0].chName<<endl;
		pop_heap(Q.begin(),Q.end());
		Q.pop_back();
	}
	
	
	
	
	return 0;
}
