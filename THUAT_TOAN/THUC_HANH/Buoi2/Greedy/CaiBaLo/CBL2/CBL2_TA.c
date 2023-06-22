#include<stdio.h>
#include<malloc.h>
#include<string.h>

typedef struct {
	char TenDV[20];
	float TL, GT, DG;
	int SL, PA;
} DoVat;

DoVat *ReadFromFile(float *W, int *n){
	FILE *f;
	f = fopen("CaiBalo2.txt", "r");
	fscanf(f, "%f", W);
	DoVat *dsdv;
	dsdv = (DoVat*)malloc(sizeof(DoVat));
	int i = 0;
	while(!feof(f)){
		fscanf(f, "%f%f%d%[^\n]", &dsdv[i].TL, &dsdv[i].GT, &dsdv[i].SL, &dsdv[i].TenDV);
		dsdv[i].DG = dsdv[i].GT / dsdv[i].TL;
		dsdv[i].PA = 0;
		i++;
		dsdv = (DoVat*)realloc(dsdv, sizeof(DoVat)*(i+1));
	}
	*n = i;
	fclose(f);
	return dsdv;
}

void swap(DoVat *x, DoVat *y){
	DoVat temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void bubbleSort(DoVat *dsdv, int n){
	int i, j;
	for(i = 0; i < n-2; i++){
		for(j = n-1; j >= i+1; j--){
			if(dsdv[j].DG > dsdv[j-1].DG){
				swap(&dsdv[j], &dsdv[j-1]);
			}
		}
	}
}

void InDSDV(DoVat *dsdv, int n, float W){
	int i;
	float TongTL = 0.0, TongGT = 0.0;
	printf("\nPhuong an cai balo su dung giai thuat THAM AN nhu sau: \n");
	printf("Trong luong cai balo = %.2f\n", W);
	printf("|STT|     Ten do vat     | T luong | Gia tri | Don Gia | Phuong an |\n");
	for(i = 1; i < n; i++){
		printf("|%2d |%-20s|%9.2f|%9.2f|%9.2f|%6d     |\n", i,
			dsdv[i].TenDV, dsdv[i].TL, dsdv[i].GT, dsdv[i].DG, dsdv[i].PA);
		TongGT += dsdv[i].PA * dsdv[i].GT;
		TongTL += dsdv[i].PA * dsdv[i].TL;
	}
	printf("Phuong an (theo thu tu giam dan): X(");
	for(i = 1; i < n-1; i++){
		printf("%d, ", dsdv[i].PA);
	}
	printf("%d)", dsdv[n-1].PA);
	printf("\nTong trong luong = %.2f\n", TongTL);
	printf("Tong gia tri = %.2f", TongGT);
}

void Greedy(DoVat *dsdv, int n, float W){
	int i;
	for(i = 0; i < n; i++){
		dsdv[i].PA = (W / dsdv[i].TL);
		W -= dsdv[i].PA * dsdv[i].TL;
	}
}

int main(){
	int n;
	float W;
	DoVat *dsdv;
	
	dsdv = ReadFromFile(&W, &n);
	bubbleSort(dsdv, n);
	Greedy(dsdv, n, W);
	InDSDV(dsdv, n, W);
	
	free(dsdv);
	
	return 0;
}
