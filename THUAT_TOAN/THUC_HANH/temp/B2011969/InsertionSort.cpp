#include<stdio.h>

typedef int keytype;
typedef float othertype;

typedef struct {
	keytype key;
	othertype otherfields;
}recordtype;

void Swap(recordtype *x, recordtype *y){
	recordtype temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
//Thuat toan xen(Ínsertion)
int Partition(recordtype a[], int i, int j,
keytype pivot)
{ int L,R;
 L = i;
 R = j;
while (L <= R)
{ while (a[L].key < pivot) L++;
 while (a[R].key >= pivot) R--;
if (L<R) Swap(&a[L],&a[R]);
}
 return L;
}

int FindPivot(recordtype a[], int i,int j)
{ keytype firstkey;
int k ;
k = i+1;
firstkey = a[i].key; while ( (k <= j) && (a[k].key ==
firstkey) ) k++;
 if (k > j) return -1;
else
if (a[k].key>firstkey) return k;
else return i;
}
void Insertion(recordtype a[], int n){
	int i,j;
	for(i=1; i<=n-1; i++){
		j=i;
		while ((j>0)&&(a[j].key<a[j-1].key)){
			Swap(&a[j], &a[j-1]);
			j--;
		}
	} 

}
	
void Read_Data(recordtype a[], int *n){
	FILE *f;
	f = fopen("data.txt", "r");
	int i=0;
	if(f!=NULL)
	while (!feof(f)){
		fscanf(f,"%d%f", &a[i].key, &a[i].otherfields);
		i++;
	} else printf("Loi khong mo duoc file\n");
	fclose(f);
	*n=i;
}
void Print_Data(recordtype a[], int n){
	int i;
	for(i=0; i<n; i++)
	printf("%3d %5d %8.2f\n", i+1, a[i].key, a[i].otherfields);
}

int main(){
	recordtype a[100];
	int n;
	
	printf("Thuat toan xen Insertion \n\n");
	printf("------------------------\n\n");
	Read_Data(a, &n);
	
	printf("Du lieu truoc khi sap xep: \n");
	printf("------------------------\n\n");
	Print_Data(a,n);
	
	Insertion(a,n);
	
	
	printf("Du lieu sau khi sap xep: \n");
	printf("------------------------\n\n");
	Print_Data(a,n);
	
	
	return 0; 
}
