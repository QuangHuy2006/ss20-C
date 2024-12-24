#include <string.h>
#include <stdio.h>
#include <stdlib.h>
struct sale{
	int id;
	char name[100];
	long long inprice;
	long long outprice;
	long long money;
};
typedef struct sale revenue;

void swap(revenue *a,revenue *b){
	revenue temp=*a;
	*a=*b;
	*b=temp;
}

void input(revenue *a,int n){
	for(int i=1;i<=n;i++){
		a[i].id=i;
		fflush(stdin);
		printf("nhap ten san pham thu %d : ", a[i].id);
		gets(a[i].name);
		printf("nhap gia nhap san pham : ");
		scanf("%lld", &a[i].inprice);
		printf("nhap gia ban san pham : ");
		scanf("%lld", &a[i].outprice);
		printf("\n");
	}
}

void print(revenue *a,int n){
	for(int i=1;i<=n;i++){
			a[i].id=i;
			printf("SAN PHAM THU %d", a[i].id);
			printf("\n=================\n");
			printf("\nten san pham : %s", a[i].name);
			printf("\ngia nhap : %lld", a[i].inprice);
			printf("\ngia ban : %lld", a[i].outprice);
			printf("\n=================\n");
		}
}

void insert(revenue *a,int n){
	for(int i=n+1;i>=n+1;i--){
		strcpy(a[i].name,a[i-1].name);
		a[i].inprice=a[i-1].inprice;
		a[i].outprice=a[i-1].outprice;
	}
		fflush(stdin);
		printf("nhap ten san pham moi : ");
		gets(a[n+1].name);
		fflush(stdin);
		printf("nhap gia nhap san pham : ");
		scanf("%lld", &a[n+1].inprice);
		printf("nhap gia san pham : ");
		scanf("%lld", &a[n+1].outprice);
		for(int i=1;i<=n+1;i++){
			a[i].id=i;
			printf("SAN PHAM THU %d", a[i].id);
			printf("\n=================\n");
			printf("\nten san pham : %s", a[i].name);
			printf("\ngia nhap : %lld", a[i].inprice);
			printf("\ngia ban : %lld", a[i].outprice);
			printf("\n=================\n");
		}
	}

void sell(revenue *a,int n){
	int x;
	printf("nhap so luong san pham muon xoa : ");
	scanf("%d", &x);
	if(x<0 || x>5){
		printf("khong hop le!");
	}else{
for(int j=x;j>=1;j--){
	for(int i=x;i<=6;i++){
		strcpy(a[i].name,a[i+1].name);
		a[i].inprice=a[i+1].inprice;
		a[i].outprice=a[i+1].outprice;
	}
}
		for(int i=1;i<=n-x;i++){
			a[i].id=i;
			printf("SAN PHAM THU %d", a[i].id);
			printf("\n=================\n");
			printf("\nten san pham : %s", a[i].name);
			printf("\ngia nhap : %lld", a[i].inprice);
			printf("\ngia ban : %lld", a[i].outprice);
			printf("\n=================\n");
		}
	}
}

void changevalue(revenue *a,int n){
	fflush(stdin);
	int x;
	printf("nhap thu tu san pham ban muon sua : ");
	scanf("%d", &x);
	if(x<0 || x>n){
		printf("khong hop le!");
	}else{
		fflush(stdin);
		printf("nhap ten san pham : ");
		gets(a[x].name);
		printf("nhap gia nhap san pham : ");
		scanf("%lld", &a[x].inprice);
		printf("nhap gia ban san pham : ");
		scanf("%lld", &a[x].outprice);
		for(int i=1;i<=n;i++){
			a[i].id=i;
			printf("SAN PHAM THU %d", a[i].id);
			printf("\n=================\n");
			printf("\nten san pham : %s", a[i].name);
			printf("\ngia nhap : %lld", a[i].inprice);
			printf("\ngia ban : %lld", a[i].outprice);
			printf("\n=================\n");
		}
	}
}
void increase(revenue *a, int n){
	for(int i=1;i<=n;i++){
		int minpos=i;
		for(int j=i+1;j<=n;j++){
			if(a[minpos].outprice>a[j].outprice){
				minpos=j;
			}
			swap(&a[i].outprice,&a[minpos].outprice);
		}
	}
}

void decrease(revenue *a, int n){
	for(int i=1;i<=n;i++){
		int minpos=i;
		for(int j=i+1;j<=n;j++){
			if(a[minpos].outprice<a[j].outprice){
				minpos=j;
			}
			swap(&a[i].outprice,&a[minpos].outprice);
		}
	}
	for(int i=1;i<=n;i++){
			a[i].id=i;
			printf("SAN PHAM THU %d", a[i].id);
			printf("\n=================\n");
			printf("\nten san pham : %s", a[i].name);
			printf("\ngia nhap : %lld", a[i].inprice);
			printf("\ngia ban : %lld", a[i].outprice);
			printf("\n=================\n");
		}
}
void find(revenue *a, int n){
	int cnt=0;
	char x[50];
	fflush(stdin);
	printf("nhap ten san pham : ");
	gets(x);
	for(int i=1;i<=n;i++){
		if(strcmp(a[i].name,x)==0){
			++cnt;
		}
	}
	if(cnt){
		printf("FOUND!");
	}else{
		printf("NOT FOUND!");
	}
}

void total(revenue *a, int n){
	long long sum=0;
	for(int i=1;i<=n;i++){
		sum+=a[i].outprice;
	}
	printf("tong doanh thu = %lld ", sum);
}
int main(){
	revenue a[50]={};
	int choice;
	int n;
	do{
	printf("\n1:nhap so luong va thong tin sach");
	printf("\n2:hien thi thong tin sach");
	printf("\n3:them san pham");
	printf("\n4:cap nhat thong tin san pham");
	printf("\n5:sap xep san pham");
	printf("\n6:tim kiem san pham");
	printf("\n7:ban san pham");
	printf("\n8:doanh thu");
	printf("\n9:thoat");
	printf("\nnhap lua chon cua ban:");
	scanf("%d", &choice);
	if(choice==1){
		printf("nhap so luong phan tu ban muon:");
		scanf("%d", &n);
		input(a,n);
	}
	if(choice==2){
		print(a,n);
	}
	if(choice==3){
		insert(a,n);
	}
	if(choice==4){
		changevalue(a,n);
	}
	if(choice==5){
		int choice2;
		printf("\n1:tang dan");
		printf("\n2:giam dan");
		printf("\nnhap lua chon cua ban : ");
		scanf("%d", &choice2);
		if(choice2==1){
			increase(a,n);
		}
		if(choice2==2){
			decrease(a,n);
		}
	}
	if(choice==6){
		find(a,n);
	}
	if(choice==7){
		sell(a,n);
	}
	if(choice==8){
		total(a,n);
	}
	if(choice==9){
		printf("thoat chuong trinh !");
	}
	}while(choice!=9);
	exit(0);
}
