#include<stdio.h>

//Thuat toán sap xep chon

//Khai báo
typedef int keytype;
typedef float othertype;
typedef struct {
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

//Ham SelectionSort
void selectionSort(recordtype a[], int n){
	int i, j, lowIndex;
	keytype lowkey;
	for(i = 0; i <= n-2; i++){
		lowkey = a[i].key;
		lowIndex = i;
		for(j = i+1; j <= n-1; j++){
			if(a[j].key < lowkey){
				lowkey = a[j].key;
				lowIndex = j;
			}
		}
		swap(&a[j], &a[lowIndex]);
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
	}
	fclose(f);
	*n = i;
}

//Ham xuat
void printFile(recordtype a[], int n){
	int i;
	for(i = 0; i < n-1; i++){
		printf("%d\t%d\t%.2f\n", i+1, a[i].key, a[i].otherfields);
	}
	printf("\n");
}

int main(){
	int n;
	recordtype a[100];
	
	printf("--CHUONG TRINH SAP XEP SU DUNG THUAT TOAN SELECTION SORT--\n");
	readFile(a, &n);
	
	printf("Du lieu truoc khi sap xep:\n");
	printFile(a, n);
	
	printf("Du lieu sau khi sap xep:\n");
	selectionSort(a, n-2);
	printFile(a, n);
	
	return 0;
}
