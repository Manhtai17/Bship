#include <iostream>
#include <cstring>
#include <windows.h>
#include <ctime>
#include <cstdlib>

#define size  10



char board0[10][10];
char Hits[10][10];
char KHtau;
int x;
char y_c;
const int h = 70; // so lan ban toi da
int CDtau[5];
const int numships = 5;

using namespace std;


void game();
void BanSung(char Hits[size][size], char board0[size][size], int x, char y_c, int h);
void Ktra(char &KHtau);
void dattau(char board0[size][size]);
void VeKhung(char board0[size][size]);
void setship(int numships);

int main()
{
	for (int i=0;i<size;i++){
		for (int j=0;j<size;j++){
			Hits[i][j]=' ';
			board0[i][j]=' ';
		}
	}
	/*char v;
	setship(5);
	v=KHtau;
	cout << v;*/
    VeKhung(Hits);
	dattau(board0);
	VeKhung(board0);
	//game();
	system("cls");
	cout << " hay bat dau " << endl;
	system("pause");
	BanSung(Hits, board0, x, y_c,h);
	return 0;

}

void game()
{
	//system("cls");
	cout << " hay bat dau " << endl;
	system("pause");
	BanSung(Hits, board0, x, y_c,h);
}

void BanSung(char Hits[size][size], char board0[size][size], int x, char y_c, int h) {
	//Hits[][] luu tru nhung toa do ma nguoi choi tung Hits
	//int x;//toa do x ma nguoi choi ban
	//char y_c;//tod do y ma nguoi choi ban
	int y;

	int k = 0; // tong so khoang

	for (int i = 0; i<numships; i++) {
		k += CDtau[i];
	}
	while (h != 0 || k != 0) {
		system("cls");
		VeKhung(Hits);

		cout << "Nhap toa do x ma Hits muon Hits" << endl;
		do {
			cout << "Moi Hits nhap toa do x ma Hits muon Hits" << endl;
			cout << "X: ";
			cin >> x;
			cout << endl;
		} while (x <= 10 && x >= 1);

		do {
			cout << "Moi Hits nhap toa do y ma Hits muon Hits" << endl;
			cout << "Y: ";
			cin >> y_c;
			y_c = toupper(y_c);
			y = y_c - 'A'; // chuyen tu chu ve so;
			cout << endl;
		} while (y >= 1 && y <= 10);
		k--;

		if (Hits[x - 1][y - 1] != 'X' && Hits[x - 1][y - 1] != 'M') {      // vi tri nay chua tung duoc Hits trc do
			if (board0[x - 1][y - 1] != ' ') {                   // tuc la nguoi choi da Hits trung
				KHtau = board0[x - 1][y - 1];                 // de ti nua dung Khtau check tinh trnag cua tau
				Hits[x - 1][y - 1] = 'X';
				system("cls");
				VeKhung(Hits);
				system("pause");
				Ktra(KHtau);
				cout << "Trung Dan" << endl;
				system("pause");
				k--;
			}
			else {
				system("cls");
				Hits[x - 1][y - 1] = 'M';
				VeKhung(Hits);
				cout << "Truot roi ! " << endl;
				system("pause");
			}
		}
	}
}

// Ham de kiem tra tinh trang cua tau
void Ktra(char &KHtau)
{
	int SoKhoang[5] = { 2, 3, 3, 4, 5 };
	switch (KHtau) {

	case 'S':
		SoKhoang[0]--;
		if (SoKhoang[0] == 0) {
			cout << endl << "Sub bi pha huy ." << endl;
			system("pause");

		}
		break;
	case 'D':
		SoKhoang[1]--;
		if (SoKhoang[1] == 0) {
			cout << endl << "Des bi pha huy ." << endl;
			system("pause");

		}
		break;
	case 'C':
		SoKhoang[2]--;
		if (SoKhoang[2] == 0) {
			cout << endl << "Cru bi pha huy ." << endl;
			system("pause");

		}
		break;

	case 'B':
		SoKhoang[3]--;
		if (SoKhoang[3] == 0) {
			cout << endl << "Bat bi pha huy ." << endl;
			system("pause");

		}
		break;
	case 'A':
		SoKhoang[4]--;
		if (SoKhoang[4] == 0) {
			cout << endl << "Air bi pha huy ." << endl;
			system("pause");

		}
		break;
	}
}

void dattau(char board0[size][size]) {
	// board0[][] dung luu tru du lieu ma may da random dat tau
	int k ;     // rand() % 4 +1; // 1 la len ; 2 la xuong ; 3 la sang phai ; 4 la sang trai
	int c_x ;
	int c_y ;
	char y;
	int lengthship = 1;
	int numships = 5;
	int m = 1;   // bien chay dung de so sanh voi chieu dai cua tau xem vi tri dat tau co hop le khong

	while (numships > 0) {

		system("cls");
		VeKhung(board0);
		//c_x = rand() % 10 + 1;
		//c_y = rand() % 10 + 1;
		do{
		cout << "Nhap toa do muon thiet lap X: "<< endl;
		cin >> c_x;}
		while(c_x<1&& c_x>10);

		do{
		cout << "Nhap toa do muon thiet lap Y: "<< endl;
		cin >> y;
        c_y=y-64;
		}
		while(c_y<1&& c_y>10);

		do{
		cout << "Xac dinh huong tau: "<< endl;
		cout << "1) Tau Len"<< endl;
		cout << "2) Tau Xuong"<< endl;
		cout <<" 3) Sang Phai"<< endl;
		cout << "4) Sang trai"<< endl;
		cin >> k;}
		while(k<1 && k>4);
		//k = rand() % 4 + 1;

		if (board0[c_x - 1][c_y - 1] == ' ') {
			setship(numships);

			switch (k) {

			case 1:
				for (int j = 0; j < lengthship; j++) {
					if (c_y - 1 >= 0 && c_y - 1 <= size && c_x - 1 >= 0 && c_x - 1 <= size && board0[c_x - 1][c_y - 1] == ' ') {
						m++;
					}
					c_y--;
				}
				if (m == lengthship) {
					c_y += lengthship;
                    // tra ve gia tri dau de thiet lap tau
					for (int i = 0; i<lengthship; i++) {
                        setship(numships);
						board0[c_x - 1][c_y - 1] = KHtau;
						c_y--;
					}
					numships--;
					VeKhung(board0);
				}
				else {
					// Vi tri khong hop le
					c_y += lengthship;
					board0[c_x - 1][c_y - 1] = ' ';
				}
				break;
			case 2:
				for (int j = 0; j < lengthship; j++) {
					if (c_y - 1 >= 0 && c_y - 1 <= size && c_x - 1 >= 0 && c_x - 1 <= size && board0[c_x - 1][c_y - 1] == ' ') {
						m++;
					}
					c_y++;
				}
				if (m == lengthship) {
					c_y -= lengthship;
					for (int i = 0; i<lengthship; i++) {
                        setship(numships);
						board0[c_x - 1][c_y - 1] = KHtau;
						c_y++;
					}
					numships--;
					VeKhung(board0);
				}
				else {
					//Vi tri khong hop le
					c_y -= lengthship;
					board0[c_x - 1][c_y - 1] = ' ';
				}
				break;
			case 3:
				for (int j = 0; j < lengthship; j++) {
					if (c_y - 1 >= 0 && c_y - 1 <= size && c_x - 1 >= 0 && c_x - 1 <= size && board0[c_x - 1][c_y - 1] == ' ') {
						m++;
					}
					c_x++;
				}
				if (m == lengthship) {
					c_x -= lengthship;
					for (int i = 0; i<lengthship; i++) {
                            setship(numships);
						board0[c_x - 1][c_y - 1] = KHtau;
						c_x++;
					}
					VeKhung(board0);
					numships--;
				}
				else {
					//Vi tri khong hop le
					c_x -= lengthship;
					board0[c_x - 1][c_y - 1] = ' ';
				}
				break;
			case 4:
				for (int j = 0; j < lengthship; j++) {
					if (c_y - 1 >= 0 && c_y - 1 <= size && c_x - 1 >= 0 && c_x - 1 <= size && board0[c_x - 1][c_y - 1] == ' ') {
						m++;
					}
					c_x--;
				}
				if (m == lengthship) {
					c_x += lengthship;
					for (int i = 0; i<lengthship; i++) {
                            setship(numships);
						board0[c_x - 1][c_y - 1] = KHtau;
						c_x--;
					}
					numships--;
					VeKhung(board0);

				}
				else {
					//Vi tri khong hop le
					c_x += lengthship;
					board0[c_x - 1][c_y - 1] = ' ';
				}
				break;
			}
		}
	}
}

void VeKhung(char board0[size][size]) {
	for (int i=0;i<size;i++){
		for (int j=0;j<size;j++){
			board0[i][j]=' ';
		}
	}
	cout << "  ";
	for (int iX = 0; iX < size; iX++)
	{
		cout << " " << iX + 1 << "  ";
	}
	cout << endl;
	cout << " ";
	for (int iX = 0; iX < size; iX++)
	{
		cout << "+---";
	}
	cout << "+" << endl; // dau cong dau tien
	for (int iY = 0; iY < size; iY++)
	{
		cout << char(iY + 'A'); // In chu cai truc tung A B C ....
		for (int iX = 0; iX < size; iX++)
		{
			cout << "| " << board0[iY][iX] << " ";
		}
		cout << "|" << endl;
		cout << " ";
		for (int iX = 0; iX < size; iX++)
		{
			cout << "+---"; // Ve dong cuoi
		}
		cout << "+" << endl; // dau cong cuoi cung
	}
	cout << endl;

}
void setship(int numships) {
	int lengthship = 0;
	string nameship = " ";
	char KHtau = 32;
	int CDtau[5] = { 2,3,3,4,5 };
	switch (numships) {
	case 1:
		lengthship = CDtau[0];
		nameship = "Sub";
		KHtau = 'S';
		break;
	case 2:
		lengthship = CDtau[1];
		nameship = "Des";
		KHtau = 'D';
		break;
	case 3:
		lengthship = CDtau[2];
		nameship = "Cru";
		KHtau = 'C';
		break;

	case 4:
		lengthship = CDtau[3];
		nameship = "Bat";
		KHtau = 'B';
		break;
	case 5:
		lengthship = CDtau[4];
		nameship = "Air";
		KHtau = 'A';
		break;

	default:
		break;

	}
}
