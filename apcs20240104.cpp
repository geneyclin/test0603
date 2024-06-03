#include<iostream>
#include<math.h>
using namespace std;
int b[100][100],a[100],c[100][100]; //a記錄個個元素b紀錄區間成本c紀錄區間和
int n;
int mc(int op,int ed){
    if(b[op][ed]==-1){
        if(ed-op==1){
            b[op][ed]=abs(a[op]-a[ed]);
        }
        else if(ed==op){
            b[op][ed]=0;
        }
        else{
            int minn=2147483647;
            for(int i=op;i<ed;i++){
                minn=min(minn,mc(op,i)+mc(i+1,ed)+abs(c[op][i]-c[i+1][ed]));    
            }
            b[op][ed]=minn;
        }        
    }
    return b[op][ed];
    
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        for (int j=i;j<n;j++){
            b[i][j]=-1;
        }
    }
    for(int i=0;i<n;i++){
        for (int j=i;j<n;j++){
            c[i][j]=0;
            for(int k=i;k<=j;k++){
                c[i][j]+=a[k];
            }
        }
    }
    mc(0,n-1);
    cout<<b[0][n-1];


    

}
