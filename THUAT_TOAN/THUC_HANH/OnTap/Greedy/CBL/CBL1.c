#include<stdio.h>
#include<malloc.h>
#include<string.h>

//Khai bao 
typedef struct {
	char TenDV[20];
	float TL, GT, DG;
	int PA;
}DoVat;

//Doc file
DoVat *ReadFromFile(float *W, int *n){
	FILE *f;
	f = fopen("CaiBalo1.txt", "r");
	fscanf(f, "%f", W);
	DoVat *dsdv;
	dsdv = (DoVat*)malloc(sizeof(DoVat));
	int i = 0;
	while(!feof(f)){
		fscanf(f, "%f%f%[^\n]", &dsdv[i].TL, &dsdv[i].GT, &dsdv[i].TenDV);
		dsdv[i].DG = dsdv[i].GT / dsdv[i].TL;
		dsdv[i].PA = 0;
		i++;
		dsdv = (DoVat*)realloc(dsdv, sizeof(DoVat)*(i+1));
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

//Ham sap xep
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
		W -= dsdv[i].PA * dsdv[i].TL;
	}
}

//ham in
void InDSDV(DoVat *dsdv, int n, float W){
	int i;
	float TongTL = 0.0, TongGT = 0.0;
	printf("Phuong an Caibalo su dung thuat toan tham an nhu sau:\n");
	printf("Trong luong caibalo: %.2f\n", W);
	printf("|STT|     Ten Do Vat    | T Luong | Gia Tri | Don Gia | Phuong An |\n");
	for(i = 0; i < n; i++){
		printf("|%2d |%-18s |%9.2f|%9.2f|%9.2f|%6d     |\n", i+1, 
			dsdv[i].TenDV, dsdv[i].TL, dsdv[i].GT, dsdv[i].DG, dsdv[i].PA);
		TongGT += dsdv[i].PA * dsdv[i].GT;
		TongTL += dsdv[i].PA * dsdv[i].TL;
	}h
	printf("Phuong an Caibalo (theo DG giam dan): PA = (");
	for(i = 0; i < n-1; i++){
		printf("%d, ", dsdv[i].PA);
	}
	printf("%d)\n", dsdv[n-1].PA);
	printf("Tong trong luong = %.2f\n", TongTL);
	printf("Tong gia tri = %.2f\n", TongGT);
}
int main(){
	int n;
	float W;
	DoVat *dsdv;
	
	dsdv = ReadFromFile(&W, &n);
	bubbleSort(dsdv, n-1);
	Greedy(dsdv, n, W);
	InDSDV(dsdv, n-1, W);
	
	free(dsdv);
	
	return 0;
}
