#include<stdio.h>

//Khai bao
typedef int keytype;
typedef float othertype;
typedef struct {
	keytype key;
	othertype otherfields;
}recordtype;

//Hàm swap
void swap(recordtype *x, recordtype *y){
	recordtype temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

//Ham BubbleSort
void bubbleSort(recordtype a[], int n){
	int i, j;
	for(i = 0; i <= n-2; i++){
		for(j = n-1; j >= i+1; j--){
			if(a[j].key < a[j-1].key){
				swap(&a[j], &a[j-1]);
			}
		}
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
void print(recordtype a[], int n){
	int i;
	for(i = 0; i < n-1; i++){
		printf("%d\t%d\t%.2f\n", i+1, a[i].key, a[i].otherfields);
	}
	printf("\n");
}

int main(){
	int n;
	recordtype a[100]; bb                       
	
	printf("--CHUONG TRINH SX SU DUNG GIAI THUAT NOI BOT--\n");
	readFile(a, &n);
	
	printf("Du lieu truoc khi sap xep:\n");
	print(a, n);
	
	printf("Du lieu sau khi sap xep:\n");
	bubbleSort(a, n-1);
	print(a, n);
	
	return 0;
}
