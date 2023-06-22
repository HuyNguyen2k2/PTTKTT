#include<stdio.h>
#include<malloc.h>
#include<string.h>
//Khai bao
typedef struct {
	char TenDV[30];
	float TL, GT, DG;
	int PA, SL;
}DoVat;

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
		for(j = n-1; j>= i+1; j--){
			if(dsdv[j].DG > dsdv[j-1].DG){
				swap(&dsdv[j], &dsdv[j-1]);
			}
		}
	}	
}

//Ham nhap
DoVat *ReadFromFile(float *W, int *n){
	FILE *f;
	f = fopen("CaiBalo1.txt", "r");
	fscanf(f, "%f", W);
	int i = 0;
	DoVat *dsdv = (DoVat*)malloc(sizeof(DoVat));
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

//Ham xuat
void InDSDV(DoVat *dsdv, int n, float W){
	int i;
	float TongTL = 0.0, TongGT = 0.0;
	printf("--Phuong an Caibalo 1 su dung thuat toan nhanh can--\n");
	printf("|STT|     Ten Do Vat    | T Luong | G Tri | S Luong | D Gia | P An |\n");
	for(i = 0; i < n; i++){
		printf("|%2d |%-19s|%9.2f|%7.2f|%5d    |%7.2f|%3d   |\n", i+1, dsdv[i].TenDV, dsdv[i].TL,
			dsdv[i].GT, dsdv[i].DG, dsdv[i].PA);
		TongTL += dsdv[i].PA * dsdv[i].TL;
		TongGT += dsdv[i].PA * dsdv[i].GT;
	}
	printf("Trong luong Caibalo = %.2f\n", W);
	printf("Tong trong luong = %.2f\n", TongTL);
	printf("Tong gia tri = %.2f\n", TongGT);
}

//Ham tinh cac dai luong tai nut goc
void tao_nut_goc(float W, float *V, float *CT, float *GLNTT, float *TGT, float DG_Max){
	*TGT = 0.0;
	*V = W;
	*CT = *V * DG_Max;
	*GLNTT = 0.0;
}

//Ham ghi nhan phuong an tot nhat
void cap_nhat_GLNTT(float TGT, float *GLNTT, int x[], DoVat *dsdv, int n){
	int i;
	if(*GLNTT < TGT){
		*GLNTT = TGT;
		for(i = 0; i < n; i++){
			dsdv[i].PA = x[i];
		}
	}
}

int min(int a, int b){
	return a<b? a:b;
}

//Ham nhanh can
void nhanh_can(int i, float *TGT, float *CT, float *V, float *GLNTT, int x[], DoVat *dsdv, int n){
	int j;	//so do vat duoc chon
	int yk;	//so do vat lon nhat co the chon
	yk = min(dsdv[i].SL, *V/dsdv[i].TL);
	for(j = yk; j >= 0; j--){
		
		*TGT = *TGT + j * dsdv[i].GT;
		*V = *V - j * dsdv[i].TL;
		*CT = *TGT + *V * dsdv[i+1].DG;
		
		if(*CT > *GLNTT){
			x[i] = j;
			if( (i == n-1) || (*V == 0) ){
				cap_nhat_GLNTT(*TGT, GLNTT, x, dsdv, n);
			}else{
				nhanh_can(i+1, TGT, CT, V, GLNTT, x, dsdv, n);
			}
		}
		x[i] = 0;
		*TGT = *TGT - j * dsdv[i].GT;
		*V = *V + j * dsdv[i].TL;
	}	
}

int main(){
	DoVat *dsdv;
	int n;
	float W;
	
	float TGT, CT, V, GLNTT;
	
	dsdv = ReadFromFile(&W, &n);
	
	int x[n];
	
	bubbleSort(dsdv, n);
	tao_nut_goc(W, &V, &CT, &GLNTT, &TGT, dsdv[0].DG);
	nhanh_can(0, &TGT, &CT, &V, &GLNTT, x, dsdv, n);
	InDSDV(dsdv, n, W);
	
	free(dsdv);
	
	return 0;
}
