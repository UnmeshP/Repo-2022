#include<stdio.h>    
#include<stdlib.h>  
int main()
{  
    int a[3],dno,bno=0,remainder,f=1,g=0;
    printf("Enter the number to convert: ");    
    scanf("%d",&dno);    

    while(g<3)
    {
        remainder = dno % 2;
        dno = dno / 2;
        bno = remainder;
        a[g]=bno;
        g=g+1;
    }

    printf("\nBinary of Given Number is=%d%d%d",a[2],a[1],a[0]);    
    return 0;  
}  
