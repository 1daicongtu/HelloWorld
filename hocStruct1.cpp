#include<iostream>
using namespace std;
typedef struct SinhVien
{
	char name[50];
	char MSSV[50];
	float toan;
	char GioiTinh[5];
	float van;
} SV;
void inputStruct(SV a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout<<"Nhap vao ten sinh vien: ";
		gets(a[i].name);
		cout<<"Nhap vao ma so sinh vien: ";
		gets(a[i].MSSV);
		cout<<"Nhap vao diem toan: ";
		cin>>a[i].toan;
		cin.ignore(1);
		cout<<"Nhap vao gioi tinh: ";
		gets(a[i].GioiTinh);
		cout<<"Nhap vao diem van: ";
		cin>>a[i].van;
		cin.ignore(1);
	}
}
void outputStruct(SV a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout<<"Name: "<<a[i].name<<endl;
		cout<<"MSSV: "<<a[i].MSSV<<endl;
		cout<<"Diem Toan: "<<a[i].toan<<endl;
		cout<<"Gioi Tinh: "<<a[i].GioiTinh<<endl;
		cout<<"Diem van: "<<a[i].van<<endl<<endl;
	}
}
int main()
{
	SV a[100];
	int n;
	cout<<"Nhap vao so luong phan tu: ";
	cin>>n;
	cin.ignore();
	inputStruct(a, n);
	outputStruct(a, n);
}