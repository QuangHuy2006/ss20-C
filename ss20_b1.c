#include <string.h>
#include <stdio.h>
#include <stdlib.h>
struct thuvien{
	int idbook;
	char name[100];
	char author[100];
	long long price;
};
typedef struct thuvien lib;

void swap(lib *a, lib *b){
	lib temp=*a;
	*a=*b;
	*b=temp;
}

void input(lib *a,int n){
	for(int i=1;i<=n;i++){
		a[i].idbook=i;
		fflush(stdin);
		printf("nhap ten cuon sach thu %d : ", a[i].idbook);
		gets(a[i].name);
		fflush(stdin);
		printf("nhap ten tac gia cua cuon sach thu %d : ", a[i].idbook);
		gets(a[i].author);
		printf("nhap gia tien cuon sach thu %d : ", a[i].idbook);
		scanf("%lld", &a[i].price);
	}
}

void print(lib *a,int n){
	for(int i=1;i<=n;i++){
		a[i].idbook=i;
		printf("CUON SACH THU %d", a[i].idbook);
		printf("\n=================\n");
		printf("\nten cuon sach : %s", a[i].name);
		printf("\nten tac gia : %s", a[i].author);
		printf("\ngia tien : %lld", a[i].price);
		printf("\n=================\n");
	}
}

void insert(lib *a,int n){
	int x;
	printf("nhap vi tri ban muon chen vao : ");
	scanf("%d", &x);
	if(x<0 || x>5){
		printf("khong hop le!");
	}else{
	for(int i=n+1;i>=x;i--){
		strcpy(a[i].name,a[i-1].name);
		strcpy(a[i].author,a[i-1].author);
		a[i].price=a[i-1].price;
	}
		fflush(stdin);
		printf("nhap ten cuon sach thu %d : ", a[x].idbook);
		gets(a[x].name);
		fflush(stdin);
		printf("nhap ten tac gia cua cuon sach thu %d : ", a[x].idbook);
		gets(a[x].author);
		printf("nhap gia tien cuon sach thu %d : ", a[x].idbook);
		scanf("%lld", &a[x].price);
		for(int i=1;i<=n+1;i++){
			a[i].idbook=i;
			printf("CUON SACH THU %d", a[i].idbook);
			printf("\n=================\n");
			printf("\nten cuon sach : %s", a[i].name);
			printf("\nten tac gia : %s", a[i].author);
			printf("\ngia tien : %lld", a[i].price);
			printf("\n=================\n");
		}
	}
}

void deleted(lib *a,int n){
	int x;
	printf("nhap ma sach ban muon xoa : ");
	scanf("%d", &x);
	if(x<0 || x>5){
		printf("khong hop le!");
	}else{
	for(int i=x;i<=6;i++){
		strcpy(a[i].name,a[i+1].name);
		strcpy(a[i].author,a[i+1].author);
		a[i].price=a[i+1].price;
	}
		for(int i=1;i<=n-1;i++){
			a[i].idbook=i;
			printf("CUON SACH THU %d", a[i].idbook);
			printf("\n=================\n");
			printf("\nten cuon sach : %s", a[i].name);
			printf("\nten tac gia : %s", a[i].author);
			printf("\ngia tien : %lld", a[i].price);
			printf("\n=================\n");
		
		}
	}
}

void changevalue(lib*a,int n){
	int x;
	printf("nhap ma sach ban muon sua : ");
	scanf("%d", &x);
	if(x<0 || x>5){
		printf("khong hop le!");
	}else{
		fflush(stdin);
		printf("nhap ten cuon sach thu %d : ", a[x].idbook);
		gets(a[x].name);
		fflush(stdin);
		printf("nhap ten tac gia cua cuon sach thu %d : ", a[x].idbook);
		gets(a[x].author);
		printf("nhap gia tien cuon sach thu %d : ", a[x].idbook);
		scanf("%lld", &a[x].price);
		for(int i=1;i<=n;i++){
			a[i].idbook=i;
			printf("CUON SACH THU %d", a[i].idbook);
			printf("\n=================\n");
			printf("\nten cuon sach : %s", a[i].name);
			printf("\nten tac gia : %s", a[i].author);
			printf("\ngia tien : %lld", a[i].price);
			printf("\n=================\n");
		}
	}
}
 void increase(lib *a, int n){
	for(int i=1;i<=n;i++){
		int minpos=i;
		for(int j=i+1;j<=n;j++){
			if(a[minpos].price>a[j].price){
				minpos=j;
			}
			swap(&a[i].price,&a[minpos].price);
		}
	}
	for(int i=1;i<=n;i++){
			a[i].idbook=i;
			printf("CUON SACH THU %d", a[i].idbook);
			printf("\n=================\n");
			printf("\nten cuon sach : %s", a[i].name);
			printf("\nten tac gia : %s", a[i].author);
			printf("\ngia tien : %lld", a[i].price);
			printf("\n=================\n");
	}
}
void find(lib *a, int n){
	int cnt=0;
	char x[50];
	fflush(stdin);
	printf("nhap ten cuon sach ban muon tim kiem : ");
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
int main(){
	lib a[50];
	int choice;
	int n;
	do{
	printf("\n1:nhap so luong va thong tin sach");
	printf("\n2:hien thi thong tin sach");
	printf("\n3:them sach vao vi tri");
	printf("\n4:xoa sach theo ma sach");
	printf("\n5:cap nhat thong tin sach theo ma sach");
	printf("\n6:sap xep sach theo gia");
	printf("\n7:tim kiem sach theo ten");
	printf("\n8:thoat");
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
		deleted(a,n);
	}
	if(choice==5){
		changevalue(a,n);
	}
	if(choice==6){
		increase(a,n);
	}
	if(choice==7){
		find(a,n);
	}
	}while(choice!=8);
	exit(0);
}