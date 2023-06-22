#include<stdio.h>

//Khai bao cau truc
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
};
//selection sort
void selectionSort(recordtype a[], int n){
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
		printf("Loi! Khong the mo file.\n");
	}
	fclose(f);
	*n=i;
}

void print(recordtype a[], int n){
	int i;
	for(i = 0; i < n-1; i++){
		printf("%3d %5d %8.2f\n", i+1, a[i].key, a[i].otherfields);
	}
	printf("\n");
}

int main(){
	recordtype a[100];
	int n;
	
	printf("--THUAT TOAN SAP XEP CHON--\n\n");
	read(a, &n);
	
	printf("Du lieu truoc khi sap xep: \n");
	print(a, n);
	
	selectionSort(a, n);
	printf("Du lieu sau khi sap xep: \n");
	print(a, n);
	
	return 0;
}
