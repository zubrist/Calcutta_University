#include<stdio.h>

int n, i, j, counter=0;

int sort(int array[], int a[]){
    for(i=0;i<counter-1;i++){
        for(j=i+1;j<counter;j++){
            if(a[array[i]]>a[array[j]]){
                int temp = a[array[i]];
                a[array[i]] = a[array[j]];
                a[array[j]] = temp;
            }
        }
    }
}

int shell(int a[], int gap){
    int i,j,array[n];
    for(i=0;i<gap;i++){
        counter=0;
        for(j=i;j<n;j+=gap){
            array[counter++] = j;
        }
        sort(array, a);
    }
}

int main(){
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int i,a[n];
    for(i=0;i<n;i++){
        printf("Enter the number: ");
        scanf("%d", &a[i]);
    }
    int gap, g;
    printf("Enter any odd value: ");
    scanf("%d", &gap);
    for(g = gap; g>=1; g=g-2) {
    	shell(a, g);
    	printf("\nSublist incremented by %d\n", g);
    	for(i=0;i<n;i++){
        	printf("%d ", a[i]);
    	}
    }
}
