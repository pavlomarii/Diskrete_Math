#include <stdio.h>
#include <math.h>

int main(void){
	int size;
	printf("\nInput size of arrays: ");
	scanf("%d", &size);
	printf("\n");
	int array1[size]; 
	int array2[size];
	for(int i=0; i<size; i++){
		printf("Array1[%d]=", i);
		scanf("%d", &array1[i]);
	}
	printf("\n");
	for(int i=0; i<size; i++){
		printf("Array2[%d]=", i);
		scanf("%d", &array2[i]);
	}
	printf("\nArray1 is:{");
	for(int i=0; i<size; i++){
		printf("%d ", array1[i]);
	}
	printf("\b}\n\nArray2 is:{");
	for(int i=0; i<size; i++){
		printf("%d ", array2[i]);
	}
	printf("\b}\n");
	int array3[size][size];
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			if(array1[i]<array2[j]){
				array3[i][j]=1;
			}else{
				array3[i][j]=0;
			}
		}
	}
	printf("\nMatrix is:\n");
	for(int i=0; i<size; i++){
		printf("(");
		for(int j=0; j<size; j++){
			printf("%d ", array3[i][j]);
		}
		printf("\b)\n");
	}
	int refl=0;
	for(int i=0; i<size; i++){
		if(array3[i][i]==1){
			refl++;
		}
	}
	if(refl==size){
		printf("\nRelation is reflexivity");
	}else if (refl<size && refl>0){
		printf("\nRelation is not reflexivity");
	}else if (refl==0){
		printf("\nRelation is antireflexivity");
	}
	int symm=0;
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			if(array3[i][j]==array3[j][i]){
				symm++;
			}
		}
	}
	if(symm==pow(size,2)){
		printf("\nRelation is symmetric");
	}else if (symm<pow(size,2) && symm>size){
		printf("\nRelation is not symmetric");
	}else if (symm==size){
		printf("\nRelation is antisymmetric");
	}
	int m=1,n=1;
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			for(int k=0; k<size; k++){
				if(i!=j && j!=k && i!=k){
				  if(array3[i][j]==1 && array3[j][k]==1 && array3[i][k]==0){
				 	m=0;
				  }else if (array3[i][j]==1 && array3[j][k]==1 && array3[i][k]==1){
				 	n=0;
				  }
				}
			}
		}
	}
	if(m==1){
		printf ("\nRelation is transitivity");
	}else if (n==1){
		printf ("\nRelation is antitranzitivity");
	}else{
		printf ("\nRelation is not tranzitivity");
	}
	scanf("%d", size);
	return 0;
}