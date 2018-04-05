
/*

INPUT  ： 2 * ( 3 + 4 ) * 5

OUTPUT ： 234+*5*

case (is_number) :
  push back to post_vector

case (is_operator)：
  若curr.piority比stack.top()大，一直pop並放入post_vector
  push curr to stack
  
case ('(')：
  push back to stack
  
case (')')：
  pop並push入post_vector，直到出現 '('

*/
#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

bool is_operator(char x){
    if(x=='+' || x=='-' || x=='*' || x=='/')
        return true;
    else
        return false;
}

int piority(char x){
    
    if(x=='*'||x=='/')
        return 5;
    else if(x=='+'||x=='-')
        return 2;
    else
        return 10;
}

int main(){
    
    string temp;
    cin>>temp;
    //cout<<temp.length()<<endl;
    //1+2+3   2*(3+4)*5
    vector <char> word;
    vector <char> post;
    stack <char> content;
    for(int i=0;i<temp.length();i++)
        word.push_back(temp[i]);
    
    for(int i=0;i<word.size();i++){
        //get prefix head
        char x=word[i];
        /****** Debuger
        
        cout<<"now : "<<x<<endl;
        cout<<"post:";
        for(int j=0;j<post.size();j++)
            cout<<post[j]<<" ";
        cout<<endl;
        
        cout<<"content:";
        for (stack<char> dump = content; !dump.empty(); dump.pop())
            cout << dump.top() <<" ";
        cout<<endl;
        */
        
        if(x>='0' && x<='9'){
            //cout<<"num"<<endl;
            post.push_back(x);
        }
        else if( is_operator(x) ){
            //cout<<"oper"<<endl;
            while(!content.empty()&&piority(x) >= piority(content.top())   ){
                
                char y=content.top();
                //cout<<"y:"<<y<<endl;
                content.pop();
                post.push_back(y);
            }
            content.push(x);
        }
        else if(x=='(')
            content.push(x);
        else if(x==')'){
            while(!content.empty() && content.top()!='('){
                post.push_back(content.top());
                content.pop();
            }
            if(content.top()=='(')
                content.pop();
        }
        
    }
    
    while(!content.empty()){
        post.push_back(content.top());
        content.pop();
    }
    
    
    for(int i=0;i<post.size();i++)
        cout<<post[i];
    cout<<endl;
    return 0;
}
