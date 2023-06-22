#include<stdio.h>
#include<malloc.h>
#include<string.h>

typedef struct {
	char TenDV[20];
	float TL, GT, DG;
	int PA;
}DoVat;

DoVat *ReaFromFile(float *W, int *n){
	FILE *f;
	f = fopen("CaiBalo3.txt", "r");
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
	for(i = 0; i <= n-2; i++){
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
	printf("\nPhuong an Cai balo 3 dung thuat toan tham anw nhu sau: \n");
	printf("\nTrong luong cua cai balo = %-9.2f\n", W);
	printf("|---|------------------|---------|---------|---------|-----------|\n");
	printf("|STT|     Ten Do Vat   | T Luong | Gia Tri | Don Gia | Phuong an |\n");
	printf("|---|------------------|---------|---------|---------|-----------|\n");
	for(i = 0; i < n-1; i++){
		printf("|%2d |%-18s|%9.2f|%9.2f|%9.2f|%6d     |\n", i+1,
			dsdv[i].TenDV, dsdv[i].TL, dsdv[i].GT, dsdv[i].DG, dsdv[i].PA);
		TongTL += dsdv[i].PA * dsdv[i].TL;
		TongGT += dsdv[i].PA * dsdv[i].GT;
	}
	printf("|---|------------------|---------|---------|---------|-----------|\n");	
	printf("Phuong an (theo tu tu DG giam dan): X(");
	for(i = 0; i < n-2; i++){
		printf("%d, ", dsdv[i].PA);
	}
	printf("%d)", dsdv[n-1].PA);
	printf("\nTong trong luong = %-9.2f\n", TongTL);
	printf("Tong gia tri = %-9.2f", TongGT);
}

void Greedy(DoVat *dsdv, int n, float W){
	int i;
	for(i = 0; i < n; i++){
		dsdv[i].PA = (W/dsdv[i].TL);
		if(dsdv[i].PA > 1){
			dsdv[i].PA = 1;
		}
		W -= dsdv[i].PA * dsdv[i].TL;
	}
}

int main(){
	int n;
	float W;
	DoVat *dsdv;
	
	dsdv = ReaFromFile(&W, &n);
	bubbleSort(dsdv, n);
	Greedy(dsdv, n, W);
	InDSDV(dsdv, n, W);
	
	free(dsdv);
	
	return 0;
}
