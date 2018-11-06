#include <iostream>
#include <algorithm>
using namespace std;
int Sum(int *ary)
{
	int sum = 0;
	for(int i = 0; i < 9 ; i++)
	{
		sum += ary[i];
	}
	return sum;
}
int func(int *ary){
	int GetSum = Sum(ary);
	for(int i = 0 ; i < 8; i++)
	{
		for(int j = 1 ; j < 9; j++)
		{
			if((GetSum - ary[i] - ary[j]) == 100)
			{
				ary[i] = -1;
				ary[j] = -1;
				return 0;
			}
		}
	}
	return -1;
}
int main ()
{
	int ary[9] = {0} ;
	for( int i = 0 ; i < 9; i ++){
		scanf("%d",&ary[i]);
	}
	func(ary);
	sort(ary, ary+9);
	for(int i = 2; i < 9; i++)
		printf("%d\n", ary[i]);

}

