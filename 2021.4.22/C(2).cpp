#include<bits/stdc++.h>
#include<iostream>
#include<set>
#define ll long long
using namespace std;
int main(){
   ll t;
   cin >>t;
   ll num=0;
   map<string , int> a;
   while(t--){
    string s;
    cin >>s;
    sort(s.begin(),s.end());//ʹ�����ֵ���˳�����ţ����ж��Ƿ�һ����
    num +=a[s]++;//����Ϊʲô��ans+=����Ϊ����Ҫ�ҵ���ÿ�������ж��ٸ�����һ�������գ�����ans+=����ǵ�ǰ����֮ǰ������Ե�����������Ҳ����˵��n��һ����������n-1��ͬ���յ������������档a[s]++�ĺ���������Ϊ����һ��������֮ƥ�䡣
   }
   cout<<num<<endl;
     return 0;
}

