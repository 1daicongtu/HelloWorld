#include<iostream>
#include<fstream>

using namespace std;
typedef struct SinhVien
{
	char MSSV[20];
	char Name[50];
	int Age;
	char Sex[5];
} SV;
void inputArr(SV arr[], int l)
{
	for (int i = 0; i < l; i++)
	{
		cout<<"Nhap vao ma so sinh vien: ";
		gets(arr[i].MSSV);
		cout<<"Nhap vao Ho va Ten: ";
		gets(arr[i].Name);
		cout<<"Nhap vao Tuoi: ";
		cin>>arr[i].Age;
		cin.ignore();
		cout<<"Nhap vao gioi tinh: ";
		gets(arr[i].Sex);
		cout<<endl;
	}
}
void outputArr(SV arr[], int l)
{
	for (int i = 0; i < l; i++)
	{
		cout<<"MSSV: "<<arr[i].MSSV<<endl;
		cout<<"Name: "<<arr[i].Name<<endl;
		cout<<"Age: "<<arr[i].Age<<endl;
		cout<<"Sex: "<<arr[i].Sex<<endl<<endl; 
	}
}
void outputArrFile(SV arr[], int l, ofstream &ghiFile)
{
	for (int i = 0; i < l; i++)
	{
		ghiFile<<"MSSV: "<<arr[i].MSSV<<endl;
		ghiFile<<"Name: "<<arr[i].Name<<endl;
		ghiFile<<"Age: "<<arr[i].Age<<endl;
		ghiFile<<"Sex: "<<arr[i].Sex<<endl<<endl; 
	}
	ghiFile.close();
}
void outputBinaryFile(SV arr[], int l, ofstream &binaryFile)
{
	for (int i = 0; i < l; i++)
	{
		binaryFile.write((char*)&arr[i].MSSV, sizeof(SinhVien));
		binaryFile.write((char*)&arr[i].Name, sizeof(SinhVien));
		binaryFile.write((char*)&arr[i].Age, sizeof(SinhVien));
		binaryFile.write((char*)&arr[i].Sex, sizeof(SinhVien));
	}
	binaryFile.close();
}
int main()
{
	ofstream ghiFile ("GhiFileStruct.txt");
	ofstream binaryFile ("FileBinaryStruct123.txt", ios::binary);
	SV arr[100];
	int l;
	cout<<"Nhap vao so luong sinh vien: ";
	cin>>l;
	cin.ignore();
	inputArr(arr, l);
	outputBinaryFile(arr, l, binaryFile);
	ifstream readBinaryFile("FileBinaryStruct123.txt", ios::binary);
	int n = 0;
	SV a[100];
	while (!readBinaryFile.eof())
	{
		readBinaryFile.read((char*)&a[n].MSSV, sizeof(SinhVien));
		readBinaryFile.read((char*)&a[n].Name, sizeof(SinhVien));
		readBinaryFile.read((char*)&a[n].Age, sizeof(SinhVien));
		readBinaryFile.read((char*)&a[n].Sex, sizeof(SinhVien));
		if (!readBinaryFile.eof())
		{
			n++;
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout<<"MSSV: "<<a[i].MSSV<<endl;
		cout<<"Name: "<<a[i].Name<<endl;
		cout<<"Age: "<<a[i].Age<<endl;
		cout<<"Sex: "<<a[i].Sex<<endl<<endl;
	}
	readBinaryFile.close();
	return 0;
}