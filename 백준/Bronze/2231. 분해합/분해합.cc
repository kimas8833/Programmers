#include <stdio.h>

int getSum(int number)
{
    int sum = number;
    while(number >0)
    {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}


int main(void)
{
    int N;
    scanf("%d",&N);
    int num;
    for(num=0;num<N;num++)
    {
        if(getSum(num)==N)
        {
            printf("%d\n",num);
            return 0;
        }        
        
    }
    
    printf("0\n");
    return 0;
}