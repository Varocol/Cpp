#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
     int nums[4];
     //vector<typename>arrayname,����һ������
     vector<double>a;
     //vector<typename>arrayname(element_num),����һ����ʼ״̬������element_num��Ԫ�ص�����
     vector<double>b(2);
     //vector<typename>arrayname(element_num,num),����һ����ʼ״̬������element_num��Ԫ��,ÿ��Ԫ��Ϊnum������
     vector<double>c(14,0);
     //vector<typename>arrayname(vector),����һ����vectorһ��������
     vector<double>d(a); 
     //vector<typename>arrayname(nums,nums+4),����nums���鲿�����ݵ�������
     vector<double>e(nums,nums+4);
     //arrayname.push_back(const T& x):����β������һ��Ԫ��X
     a.push_back(1);
     //iterator insert(iterator it,const T& x):�����е�����ָ��Ԫ��ǰ����һ��Ԫ��x
     a.insert(a.begin(),1);
     //iterator insert(iterator it,int n,const T& x):�����е�����ָ��Ԫ��ǰ����n����ͬ��Ԫ��x
     a.insert(a.begin(),10,1);
     //iterator insert(iterator it,const_iterator first,const_iterator last):�����е�����ָ��Ԫ��ǰ������һ����ͬ����������[first,last)�������
     a.insert(a.begin(),b.begin(),b.end());
     //iterator erase(iterator it):ɾ�������е�����ָ��Ԫ��
     a.erase(a.begin());
     //iterator erase(iterator first,iterator last):ɾ��������[first,last)��Ԫ��
     a.erase(a.begin(),a.end());
     //void pop_back():ɾ�����������һ��Ԫ��
     a.pop_back();
     //void clear():�������������Ԫ��
     a.clear();
     //reference at(int pos):����posλ��Ԫ�ص�����
     a.at(1);
     //reference front():������Ԫ�ص�����
     a.front();
     //reference back():����βԪ�ص�����
     a.back();
     //iterator begin():��������ͷָ�룬ָ���һ��Ԫ��
     a.begin();
     //iterator end():��������βָ�룬ָ���������һ��Ԫ�ص���һ��λ��
     a.end();
     //reverse_iterator rbegin():�����������ָ�����һ��Ԫ��
     a.rbegin();
     //reverse_iterator rend():�����������ָ���һ��Ԫ��֮ǰ��λ��
     a.rend();
     //bool empty() const:�ж������Ƿ�Ϊ�գ���Ϊ�գ�����������Ԫ��
     a.empty();
     //int size() const:����������Ԫ�صĸ���
     a.size();
     //int capacity() const:���ص�ǰ�����������ɵ����Ԫ��ֵ
     a.capacity();
     //int max_size() const:�������������vectorԪ������ֵ
     a.max_size();
     //void swap(vector&):��������ͬ��������������
     a.swap(b);
     //void assign(int n,const T& x):����������ǰn��Ԫ�ص�ֵΪx
     a.assign(12,1);
     //void assign(const_iterator first,const_iterator last):������[first,last)��Ԫ�����óɵ�ǰ����Ԫ��
     a.assign(b.begin(),b.end());
     //reserve ������ת
     a.reserve(a.size());
     //algorithm reverse()����������ת
     reverse(a.begin(),a.end());
}