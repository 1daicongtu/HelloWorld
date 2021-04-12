#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
int main()
{
	ofstream ofs ("CanLeFile.txt");
	ofs<<left<<setw(20)<<10<<right<<setw(10)<<12<<endl;
	ofs.close();
}