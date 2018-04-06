/*
   BIG NUMBER COUNTING~~~~~
    
    overload : +, -, *, /, >, <, ==



    Big Divid : 10000 / 50
=>  0 0 0 0 1 0 0 0 0     
            0 5 
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string change_to_string(vector<int> c);

vector <int> big_plus(vector<int> a, vector<int> b);

vector <int> big_minus(vector<int> a, vector<int> b);

vector <int> big_multi(vector<int> a, vector<int> b);

vector <int> big_divid(vector<int> a, vector <int> b);

//Overload the < > << operator.
bool operator < (vector <int> a, vector <int> b);

bool operator > (vector <int> a, vector <int> b);

bool operator == (vector <int> a, vector <int> b);

ostream& operator<<(ostream& os, vector<int> a);

int main(){
    
    string a_t,b_t;
    char oper;
    cin>>a_t>>oper>>b_t;
    
    vector<int> a(1000,0),b(1000,0),c(2000,0);
    int l_a=0,l_b=0;
    
    for(int i=a_t.length()-1 ; i>=0 ; i--){
        a[l_a]=a_t[i]-'0';
        l_a++;
    }
    for(int i=b_t.length()-1 ; i>=0 ; i--){
        b[l_b]=b_t[i]-'0';
        l_b++;
    }
    if(oper =='<'){
        if(a<b)
            cout<<"true"<<endl;
        else
            cout<<"false"<<endl;
    }
    else if(oper =='>'){
        if(a>b)
            cout<<"true"<<endl;
        else
            cout<<"false"<<endl;
    }
    else if(oper =='='){
        if(a==b)
            cout<<"true"<<endl;
        else
            cout<<"false"<<endl;
    }
    else if(oper=='+'){
        c=big_plus(a,b);
        string ans=change_to_string(c);
        cout<<ans<<endl;
    }
    else if(oper=='-'){
        c=big_minus(a,b);
        string ans=change_to_string(c);
        cout<<ans<<endl;
    }
    else if(oper=='*'){
        c=big_multi(a,b);
        string ans=change_to_string(c);
        cout<<ans<<endl;
    }
    else if(oper=='/'){
        if(b>a){
            string ans=change_to_string(a);
            cout<<ans<<endl;
        }
        else{
            c=big_divid(a,b);
            string ans=change_to_string(c);
            cout<<ans<<endl;
            
        }
        
    }
    
    
    return 0;
}

ostream& operator<<(ostream& os, vector<int> a)  
{
    vector <int> a1;
    int flag=0;
    
    for(int i=a.size()-1;i>=0;i--){
        if(flag==0 && a[i]!=0)
            flag=1;
        if(flag==1)
            a1.insert(a1.begin(),a[i]);
    }
    vector<int> check(1000,0);
    if(check==a)
        cout<<"0";
    else{
        for(int i=0;i<a1.size();i++)
            cout<<a1[i]<<" ";
    }
    return os;  
}  

bool operator == (vector<int> a, vector<int> b)
{
    vector <int> a1,b1;
    int flag=0;
    for(int i=a.size()-1; i>=0; i--){
        if(flag==0 && a[i]!=0)
            flag=1;
        if(flag==1){
            a1.push_back(a[i]);
        }
        
    }
    flag=0;
    for(int i=b.size()-1; i>=0; i--){
        if(flag==0 && b[i]!=0)
            flag=1;
        if(flag==1){
            b1.push_back(b[i]);
        }
        
    }
    //cout<<a1.size()<<" "<<b1.size()<<endl;
	if(a1.size()==b1.size()){
	    int flag=0;
	    for(int i=0;i<a1.size();i++)
	        if(a1[i]!=b1[i])
	            flag++;
	    if(flag==0)
	        return true;
	    else
	        return false;
	}
	else
	    return false;
	
	    
}

bool operator< (vector<int> a, vector<int> b)
{
    vector <int> a1,b1;
    int flag=0;
    for(int i=a.size()-1; i>=0; i--){
        if(flag==0 && a[i]!=0)
            flag=1;
        if(flag==1){
            a1.push_back(a[i]);
        }
        
    }
    flag=0;
    for(int i=b.size()-1; i>=0; i--){
        if(flag==0 && b[i]!=0)
            flag=1;
        if(flag==1){
            b1.push_back(b[i]);
        }
        
    }
    //cout<<a1.size()<<" "<<b1.size()<<endl;
	if(a1.size()<b1.size())
	    return true;
	else if(a1.size()>b1.size())
	    return false;
	else{
	    int l=0;
	    
	    while(l<a1.size()){
	        if(a1[l]<b1[l])
	            return true;
	        else if(a1[l]>b1[l])
	            return false;
	        l++;
	    }
	    return true; 
	}
	    
}

bool operator> (vector<int> a, vector<int> b)
{
    vector <int> a1,b1;
    int flag=0;
    for(int i=a.size()-1; i>=0; i--){
        if(flag==0 && a[i]!=0)
            flag=1;
        if(flag==1){
            a1.push_back(a[i]);
        }
        
    }
    flag=0;
    for(int i=b.size()-1; i>=0; i--){
        if(flag==0 && b[i]!=0)
            flag=1;
        if(flag==1){
            b1.push_back(b[i]);
        }
        
    }
    //cout<<a1.size()<<" "<<b1.size()<<endl;
    
	if(a1.size()>b1.size())
	    return true;
	else if(a1.size()<b1.size())
	    return false;
	else{
	    int l=0;
	    
	    while(l<a1.size()){
	        if(a1[l]>b1[l])
	            return true;
	        else if(a1[l]<b1[l])
	            return false;
	        l++;
	    }
	    return true; 
	}
	    
}

vector <int> big_divid(vector<int> a, vector<int> b){
    //count a.size()
    vector<int> c(2000, 0);
    int l=0;
    for(int i=a.size()-1; i>=0; i--){
        if(a[i]!=0)
            break;
        l++;
    }
    int a_size = a.size() - l;
    vector <int> temp(1000,0);
    
    vector <int> ans(1000,0);
    int rounds=0;
    for(int i = a_size - 1; i>=0 ;i--){
        temp.insert(temp.begin(),a[i]);
        //cout<<"round:"<<rounds<<endl;
        int X=0;
        while(temp>b){
            temp = big_minus(temp, b);
            //cout<<"temp:"<<temp<<" b:"<<b<<endl;
            X++;
        }
        ans.insert(ans.begin(),X);
        rounds++;
    }
    return ans;
}

vector <int> big_minus(vector<int> a, vector<int> b){
    vector <int> c(2000, 0);
    int borrow=0;
        if(a>b){
            for(int i=0;i<800;i++){
                c[i]=a[i]-b[i]+borrow;
                if(c[i]<0){
                    c[i]=c[i]+10;
                    borrow=-1;
                }
                else
                    borrow=0;
            }
            
            
        }
        else{
            for(int i=0;i<800;i++){
                c[i]=b[i]-a[i]+borrow;
                if(c[i]<0){
                    c[i]+=10;
                    borrow=-1;
                }
                else
                    borrow=0;
            }
            
        }
        if(a==b){
            vector <int> news(1000,0);
            cout<<"yes zero"<<endl;
            return news;
        }
        return c;
}

vector <int> big_plus(vector<int> a, vector<int> b){
    vector<int> c(1000,0);
    int carry=0;
        for(int i=0;i<800;i++){
            c[i]=a[i]+b[i]+carry;
            carry=c[i]/10;
            c[i]=c[i]%10;
        }
    
    
    return c;
}

vector <int> big_multi(vector<int> a, vector<int> b){
    vector <int> c(2000,0);
    for(int i=0;i<500;i++){
        for(int j=0;j<500;j++){
            c[i+j]+=a[i]*b[j];
                
        }
    }
    int carry=0;
    for(int i=0;i<1000;i++){
        c[i]+=carry;
        carry=c[i]/10;
        c[i]%=10;
    }
    return c;
}

string change_to_string(vector<int> c){
    vector<char> ans;
    int flag=0;
    for(int i=c.size()-10;i>=0;i--){
        if(flag==0 && c[i]!=0)
            flag=1;
        if(flag==1)
            ans.push_back(c[i]+'0');
        
    }
    
    string tmp(ans.begin(),ans.end());
    
    return tmp;
}

