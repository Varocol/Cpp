#include<array>
#include<vector>
#include<iostream>
using namespace std;
int main()
{
    //vector
    vector<int>a(0);//vector<typename>XX(num_element);
    int c;
    cin>>c;
    vector<double>b(c);//����һ��c��Ԫ�ص�b����

    //array
    array<double,4>d;//array<typename,num_element>XX;
    array<double,4>e{1.0,2.0,3.0,4.0};
    array<int,4>g;
    d.at(1)=0;
    b.at(1)=0;
    d=e;             //���Ը������鳤�ȱ������
    //һ������
    int f[10];

}