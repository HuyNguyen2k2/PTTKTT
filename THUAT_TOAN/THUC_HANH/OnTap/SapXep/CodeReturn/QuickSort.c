#include<stdio.h>

//Thuat toan quicksort

//Khai bao
typedef int keytype;
typedef float othertype;
typedef struct{
	keytype key;
	othertype otherfields;
}recordtype;

//Ham swap
void swap(recordtype *x, recordtype *y){
	recordtype temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

//Ham tim chot FindPivot
int FindPivot(recordtype a[], int i, int j){
	keytype firstKey;
	int k;
	k = i+1;
	firstKey = a[i].key;
	while( (k <= j)&&(a[k].key == firstKey) ) k++;
	if(k > j) return -1;
	else
		if(a[k].key > firstKey) return k;
		else return i;
}

//Ham phan hoach
int Paratition(recordtype a[], int i, int j, keytype pivot){
	int L, R;
	L = i;
	R = j;
	while( L <= R ){
		while (a[L].key < pivot) L++;
		while (a[R].key >= pivot) R--;
		if(L<R) swap(&a[L], &a[R]);
	}
	return L;
}

//Ham quickSort
void QuickSort(recordtype a[], int i, int j){
	keytype pivot;
	int pivotIndex, k;
	pivotIndex = FindPivot(a, i, j);
	if(pivotIndex != -1){
		pivot = a[pivotIndex].key;
		k = Paratition(a, i, j, pivot);
		QuickSort(a, i, k-1);
		QuickSort(a, k, j);
	}
}

//Ham nhap
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
		printf("Loi! Khong the mo file.");
	}
	fclose(f);
	*n = i;
}

//Ham xuat
void print(recordtype a[], int n){
	int i;
	for(i = 0; i < n-1; i++){
		printf("%d\t%d\t%.2f\n", i+1, a[i].key, a[i].otherfields);
	}
}

int main(){
	int n;
	recordtype a[100];
	
	printf("--CHUONG TRINH SAP XEP SU DUNG GIAI THUAT QUICKSORT--\n");
	readFile(a, &n);
	
	printf("Du lieu truoc khi sap xep:\n");
	print(a, n);
	
	printf("Du lieu sau khi sap xep:\n");
	QuickSort(a, 0, n-2);
	print(a, n);
	
	return 0;
}
