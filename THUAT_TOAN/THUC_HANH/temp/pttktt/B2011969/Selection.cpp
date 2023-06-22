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
//Thuat toan noi bot(BubbleSort)
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

void SelectionSort (recordtype a[ ], int n){
int i,j, lowindex;
keytype lowkey;
 for(i=0; i<=n-2; i++){
 lowkey = a[i].key;
 lowindex = i;
 for(j=i+1; j<=n-1; j++)
 if(a[j].key < lowkey) {
 lowkey = a[j].key;
 lowindex = j;
}
Swap(&a[i],&a[lowindex]);
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
	
	printf("Thuat toan noi bot SelectionSort \n\n");
	printf("------------------------\n\n");
	Read_Data(a, &n);
	
	printf("Du lieu truoc khi sap xep: \n");
	printf("------------------------\n\n");
	Print_Data(a,n);
	
	SelectionSort(a,n);
	
	
	printf("Du lieu sau khi sap xep: \n");
	printf("------------------------\n\n");
	Print_Data(a,n);
	
	
	return 0; 
}
