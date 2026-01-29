#include<stdio.h>
void fib(int n){
int t1=0,t2=1;
int new;
printf("fibonacci series(iterATIVE):-\n");
for(int i=1;i<=n;i++)
{
    printf("%d\n",t1);
    new=t1+t2;
    t1=t2;
    t2=new;
}
}
int main()
{
    int terms=19;
    fib(terms);
    return 0;
}
