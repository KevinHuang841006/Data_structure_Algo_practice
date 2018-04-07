/*
   判斷質數~~~~
將數字取 sqrt() 降低搜尋成本
TIP：基本上都是直接暴力法

*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    
    int a,b;
    while(cin>>a>>b){
        int ans=0;
        /*if(a<=2)
            ans++;*/
        if(a==2)
            ans++;
        
        if(a%2==0&&a>=2)
            a+=1;
        // always start from odd number
        for(int i=a;i<=b;i+=2){
            int mid=sqrt(i);
            int check=0;
            for(int j=3;j<=mid;j++)
                if(i%j==0){
                    check++;
                    break;
                }
            if(check==0)
                ans++;
        }
        if(a==1&&b==1)
            ans=0;
        if(a==2&&b==2)
            ans=1;
        cout<<ans<<endl;
    }
    
    
    return 0;
}
