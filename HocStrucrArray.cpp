#include<iostream>
#include<fstream>
using namespace std;
typedef struct SinhVien
{
	char MSSV[50];
	char Diem; // A, B, C, D, F
	int Sex; // 1 is Male, O is Female
	float DRL; // Diem ren luyen
} SV;
void inputStructArr(SV TH16[], int n);
void outputStructArr(SV TH16[], int n);
void outputFile(SV TH16[], int n, ofstream &ofs);
int main()
{
	ofstream ofs ("DaTaStructStudent.txt");
	if (ofs.fail())
	{
		cout<<"Khong mo duoc file!";
		return 0;
	}
	int n = 2;
	SV TH16[n];
	inputStructArr(TH16, n);
	outputStructArr(TH16, n);
	outputFile(TH16, n, ofs);
}
void inputStructArr(SV TH16[], int n)
{ 
	for (int i = 0; i < n; i++)
	{
		cout<<"Nhap vao MSSV: ";
		gets(TH16[i].MSSV);
		cout<<"Nhap vao diem: ";
		cin>>TH16[i].Diem;
		cin.ignore();
		cout<<"Nhap vao Gioi Tinh (1/0): ";
		cin>>TH16[i].Sex;
		cin.ignore();
		cout<<"Nhap vao diem ren luyen: ";
		cin>>TH16[i].DRL;
		cin.ignore();
		cout<<endl;
	}
}
void outputStructArr(SV TH16[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout<<"MSSV: "<<TH16[i].MSSV<<endl;
		cout<<"Diem: "<<TH16[i].Diem<<endl;
		if (TH16[i].Sex == 1)
		{
			cout<<"Gioi Tinh: Nam"<<endl;
		} else
		{
			cout<<"Gioi Tinh: Nu"<<endl;
		}
		cout<<"Diem ren luyen: "<<TH16[i].DRL<<endl<<endl;
	}
}
void outputFile(SV TH16[], int n, ofstream &ofs)
{
	for (int i = 0; i < n; i++)
	{
		ofs<<"MSSV: "<<TH16[i].MSSV<<endl;
		ofs<<"Diem: "<<TH16[i].Diem<<endl;
		if (TH16[i].Sex == 1)
		{
			ofs<<"Gioi Tinh: Nam"<<endl;
		} else
		{
			ofs<<"Gioi Tinh: Nu"<<endl;
		}
		ofs<<"Diem ren luyen: "<<TH16[i].DRL<<endl<<endl;
	}
	ofs.close();
}