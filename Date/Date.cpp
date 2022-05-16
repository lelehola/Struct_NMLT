#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

struct Ngay //138
{
	int ngay;
	int thang;
	int nam;
};
typedef struct Ngay NGAY;

void Nhap(NGAY&); //139

void Xuat(NGAY); //140

int ktNhuan(NGAY); // 141

int SoNgayToiDaTrongThang(NGAY); //142

int SoNgayToiDaTrongNam(NGAY); // 143

int ktHopLe(NGAY); //144

int SoSanh(NGAY, NGAY); //145

int SoThuTuTrongNam(NGAY); //146

int SoThuTu(NGAY); //147

void XuatThu(NGAY); // 148

int KhoangCach(NGAY, NGAY); //149

NGAY TimNgay(int, int); //150

NGAY TimNgay(int); // 151

NGAY KeTiep(NGAY); //152

NGAY TruocDo(NGAY); // 153

NGAY KeTiep(NGAY, int); // 154

NGAY TruocDo(NGAY, int); //155
int main()
{  
	NGAY a;
	Nhap(a);
	cout << "\nNgay vua nhap: ";
	Xuat(a);

	int kq1 = ktNhuan(a);
	if (kq1 == 1)
		cout << a.nam << " la nam nhuan" << endl;
	else
		cout << a.nam << " khong la nam nhuan" << endl;

	int kq2 = SoNgayToiDaTrongThang(a);
	cout << "\nSo ngay toi da trong thang " << a.thang << " la " << kq2 << endl;

	int kq3 = SoNgayToiDaTrongNam(a);
	cout << "\nSo ngay toi da trong nam " << a.nam << " la " << kq3 << endl;

	int kq4 = ktHopLe(a);
	if (kq4 == 1)
		cout << a.ngay << "/" << a.thang << "/" << a.nam << " la hop le " << endl;
	else
		cout << a.ngay << "/" << a.thang << "/" << a.nam << " la khong hop le " << endl;

	NGAY b, d;
	Nhap(b);
	Nhap(d);
	int kq5 = SoSanh(b, d);
	if (kq5 == 1)
		cout << "Ngay thang nam b lon hon ngay thang nam d" << endl;
	else if (kq5 == -1)
		cout << "Ngay thang nam d lon hon ngay thang nam b" << endl;

	int kq6 = SoThuTuTrongNam(a);
	cout << "So thu tu cua ngay trong nam la: " << kq6 << endl;

	int kq7 = SoThuTu(a);
	cout << "So thu tu ngay ke tu 01/01/01 la: " << kq7 << endl;

	cout << "Thu cua ngay tuong ung la: ";
	XuatThu(a);

	int kq8 = KhoangCach(b, d);
	cout << "Khoang cach giua 2 ngay la: " << kq8 << endl;

	NGAY temp1 = TimNgay(a.nam, kq6);
	cout << "Ngay tuong ung: " << temp1.ngay << "/" << temp1.thang << "/" << temp1.nam << endl;
	
	NGAY temp2 = TimNgay(kq7);
	cout << "Ngay tuong ung: " << temp2.ngay << "/" << temp2.thang << "/" << temp2.nam << endl;
	
	NGAY temp3 = KeTiep(a);
	cout << "Ngay ke tiep la: " << temp3.ngay << "/" << temp3.thang << "/" << temp3.nam << endl;

	NGAY temp4 = TruocDo(a);
	cout << "Ngay truoc do la: " << temp4.ngay << "/" << temp4.thang << "/" << temp4.nam;

	int k;
	cout << "\nNhap k: ";
	cin >> k;
	NGAY temp5 = KeTiep(a, k);
	cout << "Ngay ke tiep k lan la: " << temp5.ngay << "/" << temp5.thang << "/" << temp5.nam << endl;

	int n;
	cout << "\nNhap n: ";
	cin >> n;
	NGAY temp6 = TruocDo(a, k);
	cout << "Ngay ke tiep k lan la: " << temp6.ngay << "/" << temp6.thang << "/" << temp6.nam;
	return 1;
}
void Nhap(NGAY& a)
{
	cout << "Nhap ngay: ";
	cin >> a.ngay;
	cout << "Nhap thang: ";
	cin >> a.thang;
	cout << "Nhap nam: ";
	cin >> a.nam;
}
void Xuat(NGAY a)
{
	cout << "\nNgay: " << a.ngay;
	cout << "\nThang: " << a.thang;
	cout << "\nNam: " << a.nam;
}
int ktNhuan(NGAY a)
{
	if ((a.nam % 4 == 0 && a.nam % 100 != 0) || (a.nam%400 == 0))
		return 1;
	return 0;
}
int SoNgayToiDaTrongThang(NGAY a)
{
	int ngaythang[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (ktNhuan(a))
		ngaythang[1] = 29;
	return ngaythang[a.thang - 1];
}
int SoNgayToiDaTrongNam(NGAY a)
{
	if (ktNhuan(a))
		return 366;
	return 365;
}
int ktHopLe(NGAY a)
{
	if (a.thang < 1 || a.thang >12 || a.nam < 1 || a.ngay < 1)
		return 0;
	if (a.ngay > SoNgayToiDaTrongThang(a))
		return 0;
	return 1;
}

int SoSanh(NGAY a, NGAY b)
{
	if (a.nam > b.nam)
		return 1;
	if (a.nam < b.nam)
		return -1;
	if (a.thang > b.thang)
		return 1;
	if (a.thang < b.thang)
		return -1;
	if (a.nam > b.nam)
		return 1;
	if (a.nam < b.nam)
		return -1;
	return 0;
}
int SoThuTuTrongNam(NGAY a)
{
	int stt = 0;
	for (int i = 1; i <= a.thang - 1; i++)  //tinh tong ngay trong cac thang truoc
	{
		NGAY temp = { 1,i,a.nam };
		stt += SoNgayToiDaTrongThang(temp);
	}
	return (stt + a.ngay);
}
int SoThuTu(NGAY a)
{
	int stt = 0;
	for (int i = 1; i <= a.nam - 1; i++)
	{
		NGAY temp = { 1,1,i };
		stt += SoNgayToiDaTrongNam(temp);
	}
	return(stt + SoThuTuTrongNam(a));
}
void XuatThu(NGAY a)
{
	int stt = SoThuTu(a);
	switch (stt % 7)
	{
	    case 0: cout << "Chu Nhat";
		    break;
		case 1: cout << "Thu Hai";
			break;
		case 2: cout << "Thu Ba";
			break;
		case 3: cout << "Thu Tu";
			break;
		case 4: cout << "Thu Nam";
			break;
		case 5: cout << "Thu Sau";
			break;
		case 6: cout << "Thu Bay";
			break;
	}
}
int KhoangCach(NGAY a, NGAY b)
{
	int x = SoThuTu(a);
	int y = SoThuTu(b);
	return abs(x - y);
}
NGAY TimNgay(int nam, int stt)
{
	NGAY temp = { 1,1,nam };
	temp.thang = 1;
	while (stt > SoNgayToiDaTrongThang(temp))
	{
		stt = stt - SoNgayToiDaTrongThang(temp);
		temp.thang++;
	}
	temp.ngay = stt;
	return temp;
}
NGAY TimNgay(int stt)
{
	int nam = 1;
	int sn = 365;
	while (stt > sn)
	{
		stt = stt - sn;
		nam++;
		NGAY temp = { 1,1,nam };
		sn = SoNgayToiDaTrongNam(temp);
	}
	return TimNgay(nam, stt);
}
NGAY KeTiep(NGAY a)
{
	int stt = SoThuTu(a);
	stt += 1;
	return TimNgay(stt);
}
NGAY TruocDo(NGAY a)
{
	if (a.ngay == 1 && a.thang == 1 && a.nam == 1)
		return a;
	int stt = SoThuTu(a);
	stt--;
	return TimNgay(stt);
}
NGAY KeTiep(NGAY a, int k)
{
	int stt = SoThuTu(a);
	stt += k;
	return TimNgay(stt);
}
NGAY TruocDo(NGAY a, int k)
{
	NGAY temp = a;
	for (int i = 1; i <= k; i++)
		temp = TruocDo(temp);
	return temp;
}
