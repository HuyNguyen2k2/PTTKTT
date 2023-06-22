#include<stdio.h>
#include<string.h>
#include<malloc.h>

//khai bao
typedef struct {
	char TenDV[20];
	float TL, GT, DG;
	int PA;
}DoVat;

//Ham nhap
DoVat *ReadFromFile(float *W, int *n){
	FILE *f;
	f = fopen("CaiBalo3.txt", "r");
	fscanf(f, "%f", W);
	DoVat *dsdv = (DoVat*)malloc(sizeof(DoVat));
	int i = 0;
	if(f!=NULL){
		while(!feof(f)){
			fscanf(f, "%f%f%[^\n]", &dsdv[i].TL, &dsdv[i].GT, &dsdv[i].TenDV);
			dsdv[i].DG = dsdv[i].GT / dsdv[i].TL;
			dsdv[i].PA = 0;
			i++;
			dsdv = (DoVat*)realloc(dsdv, sizeof(DoVat)*(i+1));
		}
	}else{
		printf("Loi! Khong the mo file.\n");
	}
	fclose(f);
	*n = i;
	return dsdv;
}

//Ham swap
void swap(DoVat *x, DoVat *y){
	DoVat temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

//Ham sx
void bubbleSort(DoVat *dsdv, int n){
	int i, j;
	for(i = 0; i <= n-2; i++){
		for(j = n-1; j >= i+1; j--){
			if(dsdv[j].DG > dsdv[j-1].DG){
				swap(&dsdv[j], &dsdv[j-1]);
			}
		}
	}
}

//Ham greedy
void Greedy(DoVat *dsdv, int n, float W){
	int i;
	for(i = 0; i < n; i++){
		dsdv[i].PA = (W / dsdv[i].TL);
		if(dsdv[i].PA > 1){
			dsdv[i].PA = 1;
		}
		W -= dsdv[i].PA * dsdv[i].TL;
	}
}

//Ham xuat
void InDSDV(DoVat *dsdv, int n, float W){
	int i;
	float TongTL = 0.0, TongGT = 0.0;
	printf("Phuong an Caibalo 3 su dung thuat toan tham an nhu sau:\n");
	printf("Trong luong Caibalo = %.2f\n", W);
	printf("|STT|     Ten Do Vat    | Tr Luong | Gia Tri | Don Gia | Phuong an |\n");
	for(i = 0; i < n; i++){
		printf("|%2d |%-19s|%10.2f|%9.2f|%9.2f|%6d     |\n", i+1,
			dsdv[i].TenDV, dsdv[i].TL, dsdv[i].GT, dsdv[i].DG, dsdv[i].PA);
		TongTL += dsdv[i].PA * dsdv[i].TL;
		TongGT += dsdv[i].PA * dsdv[i].GT;
	}
	printf("Phuong an caibalo: PA = (");
	for(i = 0; i < n-1; i++){
		printf("%d, ", dsdv[i].PA);
	}
	printf("%d)\n", dsdv[n-1].PA);
	printf("Tong trong luong = %.2f\n", TongTL);
	printf("Tong gia tri = %.2f", TongGT);
}
int main(){
	int n;
	float W;
	DoVat *dsdv;
	
	dsdv = ReadFromFile(&W, &n);
	bubbleSort(dsdv, n-1);
	Greedy(dsdv, n, W);
	InDSDV(dsdv, n-1, W);
	
	return 0;
}
