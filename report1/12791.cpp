#include <iostream>
#include <cstdlib>
#define N 25
using namespace std;
typedef struct david
{
	int year;
	char *name;
}David;
int main()
{
	David asd[N] = 
	{
		{1967, "DavidBowie"},
		{1969, "SpaceOddity"},
		{1970 ,"TheManWhoSoldTheWorld"},
		{1971 ,"HunkyDory"},
		{1972 ,"TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars"},
		{1973 ,"AladdinSane"},
		{1973 ,"PinUps"},
		{1974 ,"DiamondDogs"},
		{1975 ,"YoungAmericans"},
		{1976 ,"StationToStation"},
		{1977 ,"Low"},
		{1977 ,"Heroes"},
		{1979 ,"Lodger"},
		{1980 ,"ScaryMonstersAndSuperCreeps"},
		{1983 ,"LetsDance"},
		{1984 ,"Tonight"},
		{1987 ,"NeverLetMeDown"},
		{1993 ,"BlackTieWhiteNoise"},
		{1995 ,"1.Outside"},
		{1997 ,"Earthling"},
		{1999 ,"Hours"},
		{2002 ,"Heathen"},
		{2003 ,"Reality"},
		{2013 ,"TheNextDay"},
		{2016 ,"BlackStar"}
	};
	int testcase , *S, *E;
	cin >> testcase;
	if (100 < testcase || testcase < 1) exit(1);
	S = new int[testcase];
	E = new int[testcase];
	for (int i = 0; i < testcase; i++) {
		cin >> S[i] >> E[i];
		if (S[i] < 1 || E[i] > 2016 || S[i] > E[i])	exit(1);
	}
	for (int j = 0; j < testcase; j++) {
		int cnt = 0, arr[N];
		for (int i = 0; i <= N; i++)
			if (asd[i].year >= S[j] && asd[i].year <= E[j])
				arr[cnt++] = i;
		cout << cnt << endl;
		for (int i = 0; i < cnt; i++)
			cout << asd[arr[i]].year << ' ' << asd[arr[i]].name << endl;
	}
    return 0;
}
