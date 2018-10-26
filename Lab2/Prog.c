#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    printf("\nChoose size (1-10) of array 1:");            
    int n;                                                
    n = GetInt();
    while (n<1 || n>10)
    {
        printf("It must be 1-10:");
        n = GetInt();
    }    
    int Array1 [n];
    
    
    printf("\nEnter %i values: \n", n);
    for (int i=0; i<n; i++)
    {
        printf("Array1[%i]=", i);
        Array1[i] = GetInt();
    }
    
    
    printf("\nArray1 is:{");
    for (int i=0; i<n; i++)
        printf("%i ", Array1[i]);
    printf("\b}");    
    
    
    printf("\n\nChoose size (1-10) of array 2:");
    int m;
    m = GetInt();
    while (m<1 || m>10)
    {
        printf("It must be 1-10:");
        m = GetInt();
    }
    int Array2 [m];
    
    
    printf("\nEnter %i values: \n", m);
    for (int i=0; i<m; i++)
    {
        printf("Array2[%i]=", i);
        Array2[i] = GetInt();
    }
    
    
    printf("\nArray2 is:{");
    for (int i=0; i<m; i++)
        printf("%i ", Array2[i]);
    printf("\b}");        
    
    
    printf("\n\n");
    int counter1 = 0;
    printf("Intersection of arrays is:{");
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if (Array1[i]==Array2[j])
            {
                printf("%i ", Array1[i]);
                counter1++;
            }
        }
    }
    printf("\b}\n\n");
    printf("Power of intersection:%i", counter1);
    
    
    counter1 = 0;   
    int counter2=0;
    printf("\n\nDifference of arrays is:{");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if (Array1[i]!=Array2[j])
            {
                counter1++;
            }
        }
        if (counter1%m==0)
        {
            printf("%d ", Array1[i]);
            counter2++;
        } 
        counter1=0;
        continue; 
    }
    printf("\b}\n\nPower of difference:%i", counter2);
    printf("\n\n");
    
    return 0;    
}