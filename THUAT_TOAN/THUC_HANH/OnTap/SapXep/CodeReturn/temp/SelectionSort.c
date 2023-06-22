#include<stdio.h>

//Thuat toan sx chon selectionSort

//Khai bao
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

//Ham selectionsort
void SelectionSort(recordtype a[], int n){
	int i, j, lowindex;
	keytype lowkey;
	for(i = 0; i <= n-2; i++){
		lowkey = a[i].key;
		lowindex = i;
		for(j = i+1; j <= n-1; j++){
			if(a[j].key < lowkey){
				lowkey = a[j].key;
				lowindex = j;
			}
		}
		swap(&a[i], &a[lowindex]);
	}
}

//ham doc
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
		printf("Loi! Khong the mo file.\n");
	}
	*n = i;
	fclose(f);
}

//Ham in
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
	
	printf("--CHUONG TRINH SAP XEP SU DUNG GIAI THUAT SELECTION SORT--\n");
	readFile(a, &n);
	
	printf("---Du lieu truoc khi sap xep--\n");
	print(a, n-1);
	
	printf("---Du lieu sau khi sap xep--\n");
	SelectionSort(a, n-1);
	print(a, n-1);
	
	return 0;
}
