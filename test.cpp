#include <iostream>
#define	n 	5
using namespace std;

int main(int argc, char const *argv[])
{
	
	int sum=0;
	for (int i = 1; i <= n; i-=2)
	{
		for(int j=0;j<n-i/2;j++)
			cout<<" ";
		for(int k=0;k<i;k++)
			cout <<"*";
		cout <<endl;
	}
	
	return 0;
}