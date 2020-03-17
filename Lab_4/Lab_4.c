#include <stdio.h>

int makeTrees(int n, int A[n][n]);
void removeRepeated(int n, int A[n][n]);
int areInDifferentTrees(int n, int A[n][n], int first, int second);
void addToTree(int n, int A[n][n], int first, int second);

int main(void){
    int A[11][11] = {
         { 0, 7, 3, 2, 0, 0, 0, 0, 0, 0, 0 },
         { 7, 0, 0, 0, 7, 0, 1, 0, 0, 0, 0 },
         { 3, 0, 0, 0, 7, 4, 0, 0, 0, 0, 0 },
         { 2, 0, 0, 0, 0, 5, 5, 0, 0, 0, 0 },
         { 0, 7, 7, 0, 0, 0, 0, 2, 4, 0, 0 },
         { 0, 0, 4, 5, 0, 0, 0, 4, 0, 2, 0 },
         { 0, 1, 0, 5, 0, 0, 0, 0, 3, 4, 0 },
         { 0, 0, 0, 0, 2, 4, 0, 0, 0, 0, 3 },
         { 0, 0, 0, 0, 4, 0, 3, 0, 0, 0, 1 },
         { 0, 0, 0, 0, 0, 2, 4, 0, 0, 0, 6 },
         { 0, 0, 0, 0, 0, 0, 0, 3, 1, 6, 0 }
    };
    removeRepeated(11, A);
    printf("\nVerticles sorted by weight:");
    for(int i=1; i<=7; i++){
        printf("\n%d: ", i);
        for(int j=1; j<=11; j++){
            for(int k=1; k<=11; k++){
                if(A[j-1][k-1]==i){
                    printf("%d<->%d; ", j, k); 
                }
            }
        }
    }
    int B[11][11];
    makeTrees(11, B);
    printf("\n\nEdges : ");
    for(int i=1; i<=7; i++){
        for(int j=1; j<=11; j++){
            for(int k=1; k<=11; k++){
                if(A[j-1][k-1]==i && areInDifferentTrees(11, B, j, k)){
                    addToTree(11, B, j, k);
                    printf("%d-%d; ", j, k);
                }
            }
        }
    }
    printf("\n\n");
    return 0;
}   

int makeTrees(int n, int A[n][n]){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            A[i][j]=0;
        }
    }
    for(int i=0; i<n; i++){
        A[i][i]=i+1;
    }
    return A[n][n];
}

void removeRepeated(int n, int A[n][n]){    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(j<i){
                A[i][j]=0;
            }
        }
    }
}

int areInDifferentTrees(int n, int A[n][n], int first, int second){
    int temp1;
    int temp2;
    for(int i=0; i<n; i++){
        temp1 = 0;
        temp2 = 0;
        for(int j=0; j<n; j++){
            if(A[i][j]==first){
                temp1=1;
            }
        }
        for(int k=0; k<n; k++){
            if(A[i][k]==second){
                temp2=1;
            }
        }
        if(temp1 && temp2){
            return 0;
        }
    }
    return 1;
}

void addToTree(int n, int A[n][n], int first, int second){
    int temp;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(A[i][j]==second){
                temp=i;
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(A[i][j]==first){
                for(int k=0; k<n; k++){
                    if(A[temp][k]){
                        A[i][k]=A[temp][k];
                        A[temp][k]=0;
                    }
                }
            }
        }
    }
}