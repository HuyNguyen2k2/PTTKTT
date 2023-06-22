#include<stdio.h>

typedef int keytype;
typedef float othertype;
typedef struct{
	keytype key;
	othertype otherfields;
}recordtype;

void swap(recordtype *x, recordtype *y){
	recordtype temp;
	temp = *x;
	*x = *y; 
	*y = temp;
}

void InsertionSort(recordtype a[], int n){
	int i, j;
	for(i = 0; i <= n-1; i++){
		j = i;
		while( (j>0) && (a[j].key < a[j-1].key)){
			swap(&a[j], &a[j-1]);
			j--;
		}
	}
}

void readFile(recordtype a[], int *n){
	FILE *f;
	f = fopen("data.txt", "r");
	int i = 0;
	if(f!=NULL){
		while(!feof(f)){
			fscanf(f, "%d%f", &a[i].key, &a[i].otherfields);
			i++;
		}
	}else{
		printf("Loi!Khong the mo file.");
	}
	fclose(f);
	*n = i;
}

void print(recordtype a[], int n){
	int i;
	for(i = 0; i < n; i++){
		printf("%d\t%d\t%.2f\n", i+1, a[i].key, a[i].otherfields);
	}
	printf("\n");
}

int main(){
	int n;
	recordtype a[100];
	
	printf("--CHUONG TRINH SAP XEP SU DUNG SX XEN--\n");
	readFile(a, &n);
	
	printf("---Du lieu truoc khi sap xep--\n");
	print(a, n-1);
	
	printf("---Du lieu sau khi sap xep--\n");
	InsertionSort(a, n-1);
	print(a, n-1);
	
	return 0;
}
