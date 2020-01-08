/*
问题描述
　　给定n个数，请找出其中相差（差的绝对值）最小的两个数，输出它们的差值的绝对值。
输入格式
　　输入第一行包含一个整数n。
　　第二行包含n个正整数，相邻整数之间使用一个空格分隔。
输出格式
　　输出一个整数，表示答案。
样例输入
5
1 5 4 8 20
样例输出
1
样例说明
　　相差最小的两个数是5和4，它们之间的差值是1。
样例输入
5
9 3 6 1 3
样例输出
0
样例说明
　　有两个相同的数3，它们之间的差值是0.
数据规模和约定
　　对于所有评测用例，2 ≤ n ≤ 1000，每个给定的整数都是不超过10000的正整数。
*/

#include <iostream>

using namespace std;

int getMinDiff(int x,int *  arr,int n,int excepIndex)
{
    int t=excepIndex+1>n-1?excepIndex-1:excepIndex+1;
    int min=x-arr[t];
    min=min>0?min:-min;
    int tem;
    for (int i = 1; i < n; i++)
    {
        if(i==excepIndex)
            continue;
        tem=x-arr[i];
        tem=tem>0?tem:-tem;
        min=min<=tem?min:tem;
    }
    return min;
}

int getMin(int *  arr,int n)
{
    int min=arr[0];
    for (int i = 1; i < n; i++)
    {
        min=min<=arr[i]?min:arr[i];
    }
    
    return min;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >>n;
    int *arr=(int *)malloc(sizeof(int)*n);
    int *res=(int *)malloc(sizeof(int)*n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];    
    }

    for (int i = 0; i < n; i++)
    {
        res[i]= getMinDiff(arr[i],arr,n,i);
    }

    cout <<getMin(res,n)<<endl;
    
    return 0;
}
