#include <iostream>
using namespace std;
#define MAXNUM 10
int main()
{

    int A[MAXNUM + 1];
    int N, K, i, ans = 0;
    // N, K 입력
    cin >> N >> K;
    
    for(i = 1 ; i <= N ; i++){
        cin >> A[i];
    }

    for(i = N; i >= 1; i--)
    {
        if(K < A[i])
            continue;
        ans = ans + (K / A[i]);
        K %= A[i];
    }    
    cout << ans << endl;

}