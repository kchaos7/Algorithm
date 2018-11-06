#include <iostream>
using namespace std;

int main()
{
	int n; cin >> n;
	int x,y;
	int count;
	if(n <100)
	{
		for( int i=1 ; i <= n ; i ++)
		{
			x =  (i /10) - (i %10);
			if(x< 10)
				count++;			
		}
	}
	if(n >=100 && n<=1000)
	{
		count = 99;
		for( int i = 100 ; i <= n ; i ++)
		{
			x = (i /100)-(i %100)/10;
			y = (i %100)/10 - (i %100)%10;
			if(x == y)
				count++;
		}
	}
	cout << count;
	
}
