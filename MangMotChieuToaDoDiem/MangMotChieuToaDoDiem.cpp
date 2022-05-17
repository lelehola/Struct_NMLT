#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

struct Diem
{
	int x;
	int y;
};
typedef struct Diem DIEM;
struct TamGiac
{
	DIEM A;
	DIEM B;
	DIEM C;
};
typedef struct TamGiac TAMGIAC;

void Nhap(DIEM&);
void Nhap(DIEM[], int&); //173

void Xuat(DIEM);
void Xuat(DIEM[], int n); //174

int DemDiem(DIEM[], int); //175
DIEM TungLonNhat(DIEM[], int); //176

float KhoangCachGoc(DIEM); //177
DIEM GanGocNhat(DIEM[], int);

float KhoangCach(DIEM, DIEM); //178
void GanNhauNhat(DIEM[], int, DIEM&, DIEM&);

int ktTrung(DIEM, DIEM); //179
int TanSuat(DIEM[], int, DIEM);
int DemDiem(DIEM[], int);

void TamGiacDocLap(DIEM[], int); //180
bool ktThuocTamGiac(DIEM, DIEM, DIEM, DIEM);
void TamGiac(DIEM, DIEM, DIEM);

int main()
{
	DIEM a[1000];
	int n;
	Nhap(a, n);
	cout << "\nCac diem vua nhap: ";
	Xuat(a, n);

	int kq1 = DemDiem(a, n);
	cout << "So luong diem trong mang co hoanh do duong " << kq1 << endl;

	DIEM temp1 = TungLonNhat(a, n);
	cout << "Diem co tung do lon nhat mang: ";
	Xuat(temp1);

	DIEM temp2 = GanGocNhat(a, n);
	cout << "Diem gan goc nhat la: ";
	Xuat(temp2);

	DIEM P, Q;
	Nhap(P);
	Nhap(Q);
	GanNhauNhat(a,n, P, Q);
	cout << "\nToa do hai diem gan nhau nhat: ";
	Xuat(P);
	Xuat(Q);

	int kq2 = DemDiem(a, n);
	cout << "\nCac diem rieng biet: " << kq2 << endl;

	cout << "Tam giac doc lap la: ";
	TamGiacDocLap(a, n);

	return 0;
}   
void Nhap(DIEM &a)
{
	cout << "\nNhap x: ";
	cin >> a.x;
	cout << "\nNhap y: ";
	cin >> a.y;
}
void Nhap(DIEM a[], int& n)
{
	cout << "Nhap n: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap a[" << i << "]: ";
		Nhap(a[i]);
	}
}
void Xuat(DIEM a)
{
	cout << "\nx: " << a.x;
	cout << "\ny: " << a.y;
}
void Xuat(DIEM a[], int n)
{
	for (int i = 0; i < n; i++)
		Xuat(a[i]);
}
int DemDiem(DIEM a[], int n)
{
	int dem = 0;
	for (int i = 0; i < n; i++)
		if (a[i].x > 0)
			dem++;
	return dem;
}
DIEM TungLonNhat(DIEM a[], int n)
{
	DIEM lc = a[0];
	for (int i = 0; i < n; i++)
		if (a[i].y > lc.y)
			lc = a[i];
	return lc;
}
float KhoangCachGoc(DIEM a)
{
	return sqrt(a.x * a.x + a.y * a.y);
}
DIEM GanGocNhat(DIEM a[], int n)
{
	DIEM lc = a[0];
	for (int i = 0; i < n; i++)
		if (KhoangCachGoc(lc) > KhoangCachGoc(a[i]))
			lc = a[i];
	return lc;
}
float KhoangCach(DIEM a, DIEM b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
void GanNhauNhat(DIEM a[], int n, DIEM& P, DIEM& Q)
{
	P = a[0];
	Q = a[1];
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (KhoangCach(P, Q) > KhoangCach(a[i], a[j]))
			{
				P = a[i];
				Q = a[j];
			}
}
int ktTrung(DIEM a, DIEM b)
{
	if (a.x == b.y && a.y == b.y)
		return 1;
	return 0;
}
int TanSuat(DIEM a[], int n, DIEM P)
{
	int dem = 0;
	for (int i = 0; i < n; i++)
		if (ktTrung(a[i], P) == 1)
			dem++;
	return dem;
}
bool ktThuocTamGiac(DIEM a, DIEM b, DIEM c, DIEM d)
{
	float Sabc = (float)(1 / 2) * abs(a.x * b.y + b.x * c.y + c.x * a.y - b.x * a.y - c.x * b.y - a.x * c.y);
	float Smab = (float)(1 / 2) * abs(d.x * a.y + a.x * b.y + b.x * d.y - a.x * d.y - b.x * a.y - d.x * b.y);
	float Smbc = (float)(1 / 2) * abs(d.x * a.y + a.x * c.y + c.x * d.y - a.x * d.y - c.x * a.y - d.x * c.y);
	float Smca = (float)(1 / 2) * abs(d.x * c.y + c.x * a.y + a.x * d.y - c.x * d.y - a.x * c.y - d.x * a.y);
	int tong = Smab + Smbc + Smca;
	if (Sabc == tong)
	{
		return true;
	}
	return false;
}
void TamGiac(DIEM a, DIEM b, DIEM c)
{
	cout << "\nDiem a: " << "(" << a.x << ", " << a.y << ")";
	cout << "\nDiem b: " << "(" << b.x << ", " << b.y << ")";
	cout << "\nDiem c: " << "(" << c.x << ", " << c.y << ")";
}
void TamGiacDocLap(DIEM a[], int n)
{
	for (int i = 0; i < n - 3; i++)  // diem dau tien
		for (int j = i + 1; j < n - 2; j++) // diem thu hai
			for (int q = j + 1; q < n - 1; q++) // diem thu ba
				for (int p = q + 1; p < n; p++) // kt cac diem co thuoc tam giac khong
					if (ktThuocTamGiac(a[i], a[j], a[q], a[p]))
						TamGiac(a[i], a[j], a[q]);
}
