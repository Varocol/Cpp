#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int dp[110][110];
int N,M;
struct T
{
    int bugs,awards,cnt;
    int connects[110];
}room[110];  
void solve(int,int);
int  main()
{  
     cin>>N>>M;
     while (N!=-1&&M!=-1)
     {
        memset(dp,0,sizeof(dp)); 
        //memset(room,0,sizeof(room));
        for(int i=1;i<=N;i++)
        {
            cin>>room[i].bugs>>room[i].awards;
            room[i].bugs=(room[i].bugs+19)/20;//�����һ��Ҫע��,��һbugs��0�Ͳ�����(x-1)/20+1������
            room[i].cnt=0;
        } 
        for(int i=1;i<N;i++)
        {
            int a,b;
            cin>>a>>b;
            room[a].connects[room[a].cnt++]=b;//ͼһ��Ҫ��ͨ,һ��Ҫ˫�򣡣�
            room[b].connects[room[b].cnt++]=a;
        }
        solve(1,1);
        if(M==0)dp[1][M]=0; //����ط�һ��Ҫ��������
        cout<<dp[1][M]<<endl;
        cin>>N>>M;
     }
     return 0;
}
void solve(int start,int pre)
{ 
     for(int i=room[start].bugs;i<=M;i++)
         dp[start][i]=room[start].awards;
     for(int i=0;i<room[start].cnt;i++) 
     {
         if(room[start].connects[i]==pre)continue;
         solve(room[start].connects[i],start);
         for(int j=M;j>=room[start].bugs;j--)
         { 
             for(int k=1;k<=j-room[start].bugs;k++)
             {
                 dp[start][j]=max(dp[start][j],dp[start][j-k]+dp[room[start].connects[i]][k]);
             }
         }
     } 
}
