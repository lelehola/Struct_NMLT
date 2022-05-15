#include<iostream>
#include<iomanip>
using namespace std;

struct DuongThang
{
	float a;
	float b;
	float c;
};
typedef struct DuongThang DUONGTHANG;

void Nhap(DUONGTHANG&);
void Xuat(DUONGTHANG);

int main()
{
	DUONGTHANG ln;
	Nhap(ln);

	cout << "\nDuong thang vua nhap: ";
	Xuat(ln);
	return 1;
}
void Nhap(DUONGTHANG& l)
{
	cout << "Nhap a: ";
	cin >> l.a;
	cout << "Nhap b: ";
	cin >> l.b;
	cout << "Nhap c: ";
	cin >> l.c;
}
void Xuat(DUONGTHANG l)
{
	cout << setw(6);
	cout << setprecision(3);
	cout << "\na: " << l.a;
	cout << "\nb: " << l.b;
	cout << "\nc: " << l.c;
}