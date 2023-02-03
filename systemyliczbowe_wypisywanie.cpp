#include <iostream>

//0 0 0 0 0 0 1 1
void wypiszBinarnie(int liczba){
	char tabPomocnicza[32];
	int ileZnakow = 0;

	while(liczba > 0){
		int reszta = liczba % 2;
		liczba = liczba / 2;

		tabPomocnicza[ileZnakow] = reszta;
		ileZnakow++;
	}

	for(; ileZnakow > 0; --ileZnakow){
		std::cout << (int)tabPomocnicza[ileZnakow - 1];
	}
}

void wypiszHeks(int liczba){
	char tabPomocnicza[(sizeof(liczba) * 8) / 4 + 1];
	int ileZnakow = 0;
	unsigned int modul = liczba;

	if(liczba < 0){
		modul = -liczba;
	}

	while(modul > 0){
		int reszta = modul % 16;
		modul /= 16;

		if(reszta < 10){
			tabPomocnicza[ileZnakow] = (char)('0' + reszta);
		} else {
			tabPomocnicza[ileZnakow] = (char)('A' + reszta - 10);
		}

		++ileZnakow;
	}

	if(liczba < 0){
		tabPomocnicza[ileZnakow] = '-';
		ileZnakow++;
	}

	for(; ileZnakow > 0; ileZnakow--){
		std::cout << tabPomocnicza[ileZnakow - 1];
	}
}

//00000111
void wypiszWSystemie(int liczba, unsigned int podstawa, const char *cyfry){
	char tabPomocnicza[33];
	int ileZnakow = 0;
	unsigned int modul = liczba;

	if(liczba < 0){
		modul = -liczba;
	}

	while(modul > 0){
		int reszta = modul % podstawa;
		modul /= podstawa;

		tabPomocnicza[ileZnakow] = cyfry[reszta];
		ileZnakow++;
	}

	if(liczba < 0){
		tabPomocnicza[ileZnakow] = '-';
		++ileZnakow;
	}

	for(; ileZnakow > 0; --ileZnakow){
		std::cout << tabPomocnicza[ileZnakow - 1];
	}
}

int main(){
	int liczba = -0x01db56;

	//wypiszBinarnie(liczba);
	wypiszWSystemie(liczba, 40, "0123456789ABCDEFGHIJKLMNOPRSTUWZ!@#$%^&*()abcdefhijklmnoprstuw,./;'\\[]{}");
	return 0;
}
