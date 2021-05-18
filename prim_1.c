#include<stdio.h>
#include<stdbool.h>
#include<math.h>
bool prime(unsigned long long n);
inline bool prime(unsigned long long n)
{
    register unsigned int i;
    unsigned int b;
    b=sqrt(n);
    bool k=1;
    if(n<=1)k=0;
    else if(n==2||n==3)k=1;
	else if(n%6==1||n%6==5)
	{
	    for(i=5;i<=b;i=i+2)
	    {
	        if(n%i==0)
	        {
	            k=0;
	            break;
	        }
	    }
	}
	else k=0;
	return k;
}
void main(void)
{
    unsigned long long num;
    printf("Enter the number:");
    scanf("%llu",&num);
    //printf("ans-->%d",prime(num));
    printf("The statement --> %llu is prime: is %s.",num,prime(num)?"true":"false");
}
