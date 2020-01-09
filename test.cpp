#include <iostream>
using namespace std;

//int 转 string
int intToString(int n,string *str)
{
	int tem;
	while(n){
		tem=n%10;
		n=n/10;
		string s(1,'0'+tem);
		*str=s+*str;
	}
	return str->length();
}

int main(int argc, char const *argv[])
{
	int x=12345;
	
	string str,ss;
	//ss=to_string(x);
	int n=intToString(x,&str);
	for (int i = 0; i < n; i++)
	{
		cout <<str[i]<<endl;
	}
	
	

	//std::cout <<"toString:"<<str<<endl;
	//std::cout <<"to_string:"<<ss<<endl;
	return 0;
}