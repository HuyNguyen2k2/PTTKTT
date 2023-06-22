\#include<stdio.h>

//Thuat toan quickSort

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

//Ham tim chot findpivot
int FindPivot(recordtype a[], int i, int j){
	keytype firstKey;
	int k = i+1;
	firstKey = a[i].key;
	while( (k<=j) && (a[k].key == firstKey) ){
		k++;
	}
	if(k > j){
		return -1;
	}else{
		if(a[k].key > firstKey){
			return k;
		}else{
			return i;
		}
	}
}

//Ham phan hoach Paratition
int Paratition(recordtype a[], int i, int j, keytype pivot){
	int L, R;
	L = i;
	R = j;
	while(L<=R){
		while(a[L].key<pivot) L++;
		while(a[R].key>=pivot) R--;
		if(L < R) swap(&a[L], &a[R]);
	}
	return L;	//tra ve diem phan hoach
}

//Ham quick sort
void QuickSort(recordtype a[], int i, int j){
	keytype pivot;	//Pivot: bien giu gia tri chot
	int pivotIndex, k;	//k: bien giu gia tri diem phan hoach
	pivotIndex = FindPivot(a, i, j);
	if(pivotIndex != -1){
		pivot = a[pivotIndex].key;
		k = Paratition(a, i, j, pivot);
		QuickSort(a, i, k-1);
		QuickSort(a, k, j);	
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
		printf("Loi! Khong the mo file.");
	}
	fclose(f);
	*n = i;
}

void printData(recordtype a[], int n){
	int i;
	for(i = 0; i < n-1; i++){
		printf("%d\t%d\t%.2f\n", i+1, a[i].key, a[i].otherfields);
	}
	printf("\n");
}
 
int main(){
	int n;
	recordtype a[100];
	
	printf("--CHUONG TRINH SAP XEP SU DUNG THUAT TOAN QUICK SORT--\n");
	readFile(a, &n);
	
	printf("Du lieu truoc khi sap xep:\n");
	printData(a, n);
	
	printf("Du lieu sau khi sap xep:\n");
	QuickSort(a, 0, n-2);
	printData(a, n);
	
	return 0;
}
