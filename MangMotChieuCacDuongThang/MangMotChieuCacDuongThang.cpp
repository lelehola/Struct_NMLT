#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

struct DuongThang
{
	float a;
	float b;
	float c;
};
typedef struct DuongThang DUONGTHANG;

struct Diem
{
	int x;
	int y;
};
typedef struct Diem DIEM;

void Nhap(DIEM);
void Nhap(DIEM[], int&);

void Nhap(DUONGTHANG);        //206
void Nhap(DUONGTHANG[], int&);

void Xuat(DUONGTHANG);        //207
void Xuat(DUONGTHANG[], int n);

bool ktSongSong(DUONGTHANG, DUONGTHANG); //208
int ktSongSong(DUONGTHANG[], int);

int ktCapSongSong(DUONGTHANG[], int); //209

int ktTrungTrung(DUONGTHANG, DUONGTHANG);  //210
int ktCapTrungNhau(DUONGTHANG[], int);

bool ktThuoc(DUONGTHANG, DIEM);       //211
int ktQuaDiem(DUONGTHANG[], int, DIEM);

DUONGTHANG GanDiemNhat(DUONGTHANG[], int, DIEM); //212
float KhoangCach(DUONGTHANG, DIEM);

bool ktCat(DUONGTHANG, DUONGTHANG);  //213
DIEM GiaoDiem(DUONGTHANG, DUONGTHANG);
int ktDongQui(DUONGTHANG[], int n);
int main()
{
	DUONGTHANG a[1000];
	int n;
	Nhap(a, n);
	cout << "/nCac duong thang vua nhap la: ";
	Xuat(a, n);

	int kq1 = ktSongSong(a, n);
	if (kq1 == 1)
		cout << "\nCac duong thang song song";
	else
		cout << "\nCac duong thang khong song song";
	return 1;

	int kq2 = ktCapSongSong(a, n);
	if (kq2 == 1)
		cout << "\nTon tai cap duong thang song song";
	else
		cout << "\nKhong ton tai cap duong thang song song";

	DIEM P;
	int kq3 = ktQuaDiem(a,n, P);
	if (kq3 == 1)
		cout << "\nTon tai duong thang di qua diem";
	else
		cout << "\nKhong ton tai duong thang di qua diem";

	DUONGTHANG temp = GanDiemNhat(a, n, P);
	cout << "\nDuong thang gan diem P nhat: ";
	Xuat(temp);

	DUONGTHANG b[100];
	int m;
	Nhap(b, m);
	int kq4 = ktDongQui(b, m);
	if (kq4 == 1)
		cout << "Ba duong thang dong qui " << endl;
	else
		cout << "Ba duong thang khong dong qui " << endl;
}
void Nhap(DUONGTHANG P)
{
	cout << "\nNhap a: ";
	cin >> P.a;
	cout << "\nNhap b: ";
	cin >> P.b;
	cout << "\nNhap c: ";
	cin >> P.c;
}
void Nhap(DUONGTHANG a[], int& n)
{
	cout << "\nNhap n: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap duong thang A[" << i << "]:\n ";
		Nhap(a[i]);
	}
}
void Nhap(DIEM& a)
{
	cout << "\nNhap x: ";
	cin >> a.x;
	cout << "\nNhap y: ";
	cin >> a.y;
}
void Xuat(DUONGTHANG P)
{
	cout << "\na: " << P.a;
	cout << "\nb: " << P.b;
	cout << "\nc: " << P.c;
}
void Xuat(DUONGTHANG a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Duong thang a[" << i << "]: ";
		Xuat(a[i]);
	}
}
bool ktSongSong(DUONGTHANG P, DUONGTHANG Q)
{
	if ((P.a / Q.a) == (P.b / Q.b) && (P.b / Q.b) != (P.c / Q.c))
		return true;
	return false;
}
int ktSongSong(DUONGTHANG a[], int n)
{
	int flag = 1;
	for (int i = 0; i < n; i++)
		if (!ktSongSong(a[i], a[i + 1]))
			flag = 0;
	return flag;
}
int ktCapSongSong(DUONGTHANG a[], int n)
{
	int flag = 0;
	for (int i = 0; i < n - 1; i++)
		for (int j = i; j < n; j++)
			if (ktSongSong(a[i], a[j]))
				flag = 1;
	return flag;
}
int ktTrungTrung(DUONGTHANG P, DUONGTHANG Q)
{
	if ((P.a / Q.a) == (P.b / Q.b) && (P.b / Q.b) == (P.c / Q.c))
		return true;
	return false;
}
int ktCapTrungNhau(DUONGTHANG a[], int n)
{
	int flag = 0;
	for (int i = 0; i < n - 1; i++)
		for (int j = i; j < n; j++)
			if (ktTrungTrung(a[i], a[j]))
				flag = 1;
	return flag;
}
bool ktThuoc(DUONGTHANG l, DIEM P)
{
	if (l.a * P.x + l.b * P.y + l.c == 0)
		return true;
	return false;
}
int ktQuaDiem(DUONGTHANG a[], int n, DIEM P)
{
	int flag = 0;
	for (int i = 0; i < n; i++)
		if (ktThuoc(a[i], P))
			flag = 1;
	return flag;
}
float KhoangCach(DUONGTHANG l, DIEM P)
{
	return (abs(l.a * P.x + l.b * P.y + l.c) / sqrt(l.a * l.a + l.b * l.b));
}
DUONGTHANG GanDiemNhat(DUONGTHANG a[], int n, DIEM P)
{
	DUONGTHANG lc = a[0];
	for (int i = 0; i < n; i++)
		if (KhoangCach(a[i], P) < KhoangCach(lc, P))
			lc = a[i];
	return lc;
}
bool ktCat(DUONGTHANG P, DUONGTHANG Q)
{
	if ((P.a / Q.a) != (P.b / Q.b))
		return true;
	return false;
}
DIEM GiaoDiem(DUONGTHANG d1, DUONGTHANG d2)
{
	float D = d1.a * d2.b - d2.a * d1.b;
	float Dx = -d1.c * d2.b + d2.c * d1.b;
	float Dy = -d1.a * d2.c + d2.a * d1.c;

	DIEM temp;
	temp.x = Dx / D;
	temp.y = Dy / D;
	return temp;
}
int ktDongQui(DUONGTHANG a[], int n)
{
	for(int i = 0; i < n-1; i++)
		for(int j = i+1; j < n; j++)
			if (ktCat(a[i], a[j]))
			{
				DIEM PP = GiaoDiem(a[i], a[j]);
				for(int k = 0; k < n; k++)
					if(k!=i && k!= j && ktThuoc(a[k],PP))
						return 1;
			}
	return 0;
}
