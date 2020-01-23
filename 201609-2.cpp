/*
问题描述
　　请实现一个铁路购票系统的简单座位分配算法，来处理一节车厢的座位分配。
　　假设一节车厢有20排、每一排5个座位。为方便起见，我们用1到100来给所有的座位编号，第一排是1到5号，第二排是6到10号，依次类推，第20排是96到100号。
　　购票时，一个人可能购一张或多张票，最多不超过5张。如果这几张票可以安排在同一排编号相邻的座位，则应该安排在编号最小的相邻座位。
    否则应该安排在编号最小的几个空座位中（不考虑是否相邻）。
　　假设初始时车票全部未被购买，现在给了一些购票指令，请你处理这些指令。
输入格式
　　输入的第一行包含一个整数n，表示购票指令的数量。
　　第二行包含n个整数，每个整数p在1到5之间，表示要购入的票数，相邻的两个数之间使用一个空格分隔。
输出格式
　　输出n行，每行对应一条指令的处理结果。
　　对于购票指令p，输出p张车票的编号，按从小到大排序。
样例输入
4
2 5 4 2
样例输出
1 2
6 7 8 9 10
11 12 13 14
3 4
样例说明
　　1) 购2张票，得到座位1、2。
　　2) 购5张票，得到座位6至10。
　　3) 购4张票，得到座位11至14。
　　4) 购2张票，得到座位3、4。
评测用例规模与约定
　　对于所有评测用例，1 ≤ n ≤ 100，所有购票数量之和不超过100。
*/

#include <iostream>

using namespace std;

//获取某行的剩余空位
int getRestCountOfOneLine(int arr[20][5][2], int line)
{
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        if (0 == arr[line][i][1])
            sum++;
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    int n, seat[20][5][2];
    cin >> n;
    int *arr = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0, id = 1; i < 20; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            seat[i][j][0] = id++;
            seat[i][j][1] = 0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        bool flag=false;
        for (int j = 0; j < 20; j++)
        {
            if (getRestCountOfOneLine(seat, j) >= arr[i])
            { //某行满足入座条件
                int k = 0;
                while (seat[j][k][1] != 0)
                {
                    k++;
                }
                for (int m = 1; m <= arr[i]; m++, k++)
                {
                    seat[j][k][1] = i+1;
                }
                flag=true;
                break;
            }
        }
        if(!flag)   //没有剩余大块连续空间
        {
            int count=0;
            for (int j = 0; j < 20,count<arr[i]; j++)
            {
                for (int k = 0; k < 5,count<arr[i]; k++)
                {
                    if(seat[j][k][1]==0)
                    {
                        seat[j][k][1]=i+1;
                        count++;
                    }
                }   
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                if(i==seat[j][k][1])
                    cout <<seat[j][k][0]<<" ";
            }
        }
        cout <<endl;
    }

    return 0;
}
