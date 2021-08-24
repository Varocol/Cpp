/*N - Football
Petya loves football very much. One day, as he was watching a football match, he was writing the players' current positions on a piece of paper. To simplify the situation he depicted it as a string consisting of zeroes and ones. A zero corresponds to players of one team; a one corresponds to players of another team. If there are at least 7 players of some team standing one after another, then the situation is considered dangerous. For example, the situation 00100110111111101 is dangerous and 11110111011101 is not. You are given the current situation. Determine whether it is dangerous or not.
Input
The first input line contains a non-empty string consisting of characters "0" and "1", which represents players. The length of the string does not exceed 100 characters. There's at least one player from each team present on the field.
Output
Print "YES" if the situation is dangerous. Otherwise, print "NO".
Examples
Input
001001
Output
NO
Input
1000000001
Output
YES
*/
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    string a;bool flag=true;int b;cin>>a;
    for(int i=0;i<a.length()-1&&flag;i++)
    {
        b=1;
        while(a[i]==a[i+1]&&i<a.length()-1){b++;i++;if(b==7){flag=false;break;}}
    }
    if(flag)cout<<"NO";
    else cout<<"YES";
    cin.get();
    cin.get();
}