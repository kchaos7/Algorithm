#include <stdio.h>

int coin[6] = {500, 100 , 50,10, 5, 1};
int count;

int main()
{
    int m, i = 0;
    
    scanf("%d", &m);
    m = 1000 - m;
    while (i < 6)
    {
        if (coin[i] > m)
            i++;
        else if (coin[i] <= m)
        {
            
            count += (m / coin[i]);
            m %= coin[i];
//            printf("%d %d \n",m, count);
        }
    }
    
    printf("%d\n", count);
    
    return 0;
}

