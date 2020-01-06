/*
[题目描述]
老师给了你n个整数组成的测量数据，保证有序(可能为升序或降序)，可能存在
重复的数据。请统计出这组测量数据中的最大值、中位数以及最小值，并按照从大到小
的顺序输出这三个数。
[输入格式]
从标准输入读入数据。，
第- -行输入-一个整数n,在第二行中存在n个有序的整数，表示测量数据，可能为
升序或降序排列，可能存在连续多个整数相等，整数与整数之间使用空格隔开。
[输出格式]
输出到标准输出。
包含一行，包括最大值、中位数以及最小值共三个数，并按照从大到小的顺序输
出。数据与数据之间使用空格隔开。对于整数请直接输出整数，对于可能出现的分数，
请输出四舍五入保留1位小数的结果。
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int main(int argc, char const *argv[])
{
	int *arr;
	int n,min,max;
	float mid;

	scanf("%d",&n);
	arr=(int*)malloc(sizeof(int)*n);
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}

	bool isAsc=arr[0]<arr[n-1]?true:false;
	min=isAsc?arr[0]:arr[n-1];
	max=isAsc?arr[n-1]:arr[0];
	if(n%2==0){
		mid=(arr[n/2]+arr[n/2-1])*1.0/2.0;
	}else{
		mid=(arr[n/2]);
	}

	if(mid>(int)mid)
		printf("%d %.1f %d\n",max,mid,min);
	else
		printf("%d %d %d\n",max,(int)mid,min);
	return 0;
}