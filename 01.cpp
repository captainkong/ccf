/**
01
求非对称素数之和
Description
第一行输入两个数m,n, (2<=m<n<=9999)。求出在范围[m,n)既满足非对称，又是
素数的数值以及之和。
非对称:即如13,15, 17....327.....
Input
从键盘输入两个整数。
Output
输出非对称素数和非对称素数之和。每一个输出 数据后有换行。
Sample Input
300 330
Sample Output 
307
311 
317 
935
*/

#include <iostream>
#include <string>
using namespace std;

//是否是素数
bool isPrime(int n)
{
    bool flag=true;
    for(int i=2;i<n&&flag;i++)
    {
        if(n%i==0)
            flag=false;
    }
    return flag;
}

//是否对称
bool isSymmetry(int n)
{
    bool flag=true;
    string str=to_string(n);
    for (int i = 0; flag&&(i < str.length()/2); i++)
    {
        if(str[i]!=str[str.length()-1-i])
            flag=false;
    }
    return flag;
}


int main(int argc, char const *argv[])
{
    int min,max,sum=0;
    //cout <<"请输入最小值和最大值:";
    cin >>min>>max;
    

    for(int i=min;i<=max;i++)
    {
        if(!isSymmetry(i)&&isPrime(i))
        {
            cout <<i<<endl;
            sum+=i;
        }           

    }
    cout <<sum<<endl;

    return 0;
}