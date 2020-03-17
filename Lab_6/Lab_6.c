#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void lexic(int *Array, int k, int n);
void change(int *r, int *s);
void comeBack(int *Array, int l);
int factorial(int n);
int main(){
	int n;
	printf("Enter your N: ");
	scanf("%d", &n);
	int Array[n];
	for(int i=0; i<n; i++){
		Array[i]=i+1;
	}
	lexic(Array, n-1, n);
	int degree, counter;
	printf("\n\nEnter degree for timetable: (x-y)^");
	scanf("%d", &degree);
	printf("(x-y)^%d==", degree);
	for(int i=0; i<=degree; i++){
		counter=factorial(degree)/(factorial(i)*factorial(degree-i));
		printf("%d*x^%d*y^%d",counter, degree-i, i); 
      if((i)%2==1 && i!=degree) {
				printf(" + ");
			}else if(i!=degree){
        printf(" - ");
      }
	}
	getchar();
	getchar();
	return 0;
}

void lexic(int *Array, int k, int n){
	if(k==0){
		for(int i=0; i<n; i++){
			printf("%d ", Array[i]);
		}
		printf("\n");
	}else{
		for(int i=0; i<=k; i++){
			lexic(Array, k-1, n);
			if(i<k){
				change(&Array[i], &Array[k]);
				comeBack(Array, k-1);
			}
		}
	}
}

void change(int *r, int *s){
	int temp;
	temp=*r;
	*r=*s;
	*s=temp;
}

void comeBack(int *Array, int l){
	int i=0, j=l;
	while(i<j){
		change(&Array[i], &Array[j]);
		++i;
		--j;
	}
}

int factorial(int n){
	int f=1;
	for(int i=1; i<=n; i++){
		f*=i;
	}
	return f;
}