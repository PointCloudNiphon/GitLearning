#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int arr[N],sum[N];
int main(){
    int n , M;cin>>n>>M;
    sum[0]=0;
    for(int i=1;i<=n;i++){
        scanf("%d",arr+i);
        sum[i]=sum[i-1]+arr[i];
    }
    int minupper_M = 2*M;
    for(int i=1;i<=n;i++){
        int t = upper_bound(sum+i,sum+n+1,M+sum[i-1])-sum;
        if(sum[t-1]-sum[i-1]==M){
            minupper_M =M;// sum[t-1];
            break;
        }
        else{
            if(t<=n)
            minupper_M = min(minupper_M, sum[t]-sum[i-1]);
        }
    }
    //  cout<<minupper_M<<endl;
    for(int i=1;i<=n;i++){
        int t = upper_bound(sum+i,sum+n+1,minupper_M + sum[i-1])-sum;
        // cout<<"i:"<<i<<" t："<<t<<endl;
        if(sum[t-1]-sum[i-1]==minupper_M){
            printf("%d-%d\n",i,t-1);
        }
    }
    return 0;
}
/*
3 3 
1 2 3
*/
/*
3 5 
2 2 2

*/


