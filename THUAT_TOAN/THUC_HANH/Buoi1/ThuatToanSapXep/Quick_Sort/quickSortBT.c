//Quick sort bien the

#include<stdio.h>

typedef int keytype;
typedef float othertype;
typedef struct {
	keytype key;
	othertype otherfields;
}recordtype;

void swap(recordtype *x, recordtype *y){
	recordtype temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

//FindPivot
int findPivot(recordtype a[], int i, int j){
	int k;
	keytype firstKey;
	k = i+1;
	firstKey = a[i].key;
	while( (k<=j) && (a[k].key == firstKey) ) k++;
	if(k > j){
		return -1;
	}else{
		if( a[k].key > firstKey ){ //
			return i;
		}else{
			return k;
		}
	}
}

//Partition
int partition(recordtype a[], int i, int j, keytype pivot){
	int L, R;
	L = i;
	R = j;
	while( L<=R ){
		while( a[L].key <= pivot ) L++; //
		while( a[R].key > pivot ) R--; //
		if( L < R ) swap(&a[L], &a[R]);
	}
	return L;
}

void quickSort(recordtype a[], int i, int j){
	keytype pivot;
	int pivotIndex, k;
	pivotIndex = findPivot(a, i, j);
	if( pivotIndex != -1 ){
		pivot = a[pivotIndex].key;
		k = partition(a, i, j, pivot);
		quickSort(a, i, k-1);
		quickSort(a, k, j);
	}
}

void read(recordtype a[], int *n){
	FILE *f;
	f = fopen("data.txt", "r");
	int i = 0;
	if(f!=NULL){
		while(!feof(f)){
			fscanf(f, "%d%f", &a[i].key, &a[i].otherfields);
			i++;
		}
	}else{
		printf("Loi! Khong the doc file");
	}
	fclose(f);
	*n = i;
}

void print(recordtype a[], int n){
	int i;
	for(i = 0; i < n; i++){
		printf("%3d %5d %8.3f\n", i+1, a[i].key, a[i].otherfields);
	}
	printf("\n");
}

int main(){
	recordtype a[100];
	int n;
	
	printf("--THUAT TOAN SAP XEP NHANH--\n");
	read(a, &n);
	
	printf("Du lieu truoc khi sap xep: \n");
	print(a, n);
	
	printf("Du lieu sau khi sap xep: \n");
	quickSort(a, 0, n-1);
	print(a, n);
	
	
	return 0;
}
