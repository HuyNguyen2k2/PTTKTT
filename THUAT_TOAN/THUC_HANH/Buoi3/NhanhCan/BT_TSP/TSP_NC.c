#include<stdio.h>
#define size 30

typedef struct {
	float do_dai;
	int dau, cuoi;
	int da_dung;
}canh;

void read_file(char file_name[], canh a[][size], int *n){
	int i, j;
	FILE *f;
	f = fopen("TSP1.txt", "r");
	if(f == NULL){
		printf("Loi mo file!\n");
		return ;
	}
	fscanf(f, "%d", n);	//Doc so dinh cua do thi n
	
	for(i = 0; i < *n; i++){
		for(j = 0; j < *n; j++){
			fscanf(f, "%f", &a[i][j].do_dai);
			a[i][j].dau = i;
			a[i][j].cuoi = j;
			a[i][j].da_dung = 0;
		}
	}
	fclose(f);
}

void in_ma_tran(canh a[][size], int n){
	int i, j;
	printf("\nMa tran TRONG SO cua do thi\n");
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			printf(" %c%c =%5.2f ", a[i][j].dau+97, a[i][j].cuoi+97, a[i][j].do_dai);
		}
		printf("\n");
	}
}

void in_PA(canh PA[], int n){
	int i;
	float sum = 0.0;
	printf("\nPhuong an tim duoc:\n");
	for(i = 0; i < n; i++){
		printf("%c", PA[i].dau+97);
		printf("-> ");
	}
	printf("%c", PA[0].dau+97);
	printf("\nTong do dai cac canh cua chu trinh  = %5.2f\n", sum);
}

float canh_NN(canh[][size], int n){
	float Cmin = 3.40282e+38;
	int i, j;
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			if(i!=j && !a[i][j].da_dung && a[i][j].do_dai<Cmin){
				Cmin = a[i][j].do_dai;
			}
		}
	}
	return Cmin;
}

float can_duoi(canh a[][size], float TGT, int n, int i){
	return TGT + (n-i) * canh_NN(a, n);
}

void cap_nhat_PA_TNTT(canh a[][size], int n, float TGT, float *GNNTT, canh x[], canh PA[]){
	int i;
	
}

int main(){
	
	return 0;
}
