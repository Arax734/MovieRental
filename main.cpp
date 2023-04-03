#include <iostream>
#include "Film.h"
#include "User.h"
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
using namespace std;
int main() {

	User uzytkownik;
	Film film1;
	int p = 0;
	bool wylaczanie{};
	uzytkownik.zalogowany = false;
	uzytkownik.wylacz = false;
	uzytkownik.wylacz = wylaczanie;
	while (wylaczanie == false) {
		if (uzytkownik.zalogowany == false)
		{
			while (p != 1 && p != 2)
			{
				cout << "*******************MENU********************" << endl;
				cout << "Wybierz opcje z menu: " << endl;
				cout << "1.Logowanie " << endl;
				cout << "2.Rejestracja " << endl;
				cout << "Wybieram: ";
				cin >> p;
				system("cls");
			}
			switch (p)
			{
			case 1:
				cout << "*********Logowanie*********" << endl << endl;
				uzytkownik.logowanie();
				break;
			case 2:
				cout << "********Rejestracja********" << endl << endl;
				uzytkownik.rejestracja();
				break;
			}
			if (p == 2)
			{
				cout << endl;
				system("cls");
				cout << "Pomyslnie utworzono konto" << endl << endl;
				cout << "ZALOGUJ SIE!!" << endl;
				p = 1;
				uzytkownik.logowanie();
			}
		}
		if (uzytkownik.zalogowany == true)
		{
			int a = uzytkownik.id;
			if (uzytkownik.administrator == '0')
			{
				while (true) {
					string z = " ";
					while (z != "1" && z != "2" && z != "3" && z != "4" && z != "5" && z != "6")
					{
						system("cls");
						cout << "******************* MENU ********************" << endl << endl;
						cout << "Wybierz opcje z menu: " << endl;
						cout << "1.Wypozycz film " << endl;
						cout << "2.Oddaj film " << endl;
						cout << "3.Moje konto " << endl;
						cout << "4.Wyswietl wszystkie filmy " << endl << endl;
						cout << "*********************************************" << endl << endl;
						cout << "5.Wyloguj sie " << endl;
						cout << "6.Wylacz " << endl << endl;
						cout << "Wybieram: ";
						cin >> z;
						system("cls");
					}

					if (z == "1")
					{
						film1.wyswietl_wszystkie_filmy();
						uzytkownik.wybierz_film();
						film1.sprawdz_czy_dostepny(uzytkownik.film_wyp);
						int b = film1.id;
						if (film1.dostepny == 1)
						{
							uzytkownik.wypozycz_film(a, b);
							film1.odejmij(b);
						}
						else
						{
							cout << "Brak egzemplarzy wybranego filmu. Wybierz inny :)" << endl;
						}
					}
					if (z == "2")
					{
						film1.wyswietl_wszystkie_filmy();
						uzytkownik.oddaj_film(a);
						film1.dodaj(uzytkownik.film_wyp);
					}
					if (z == "3")
					{
						uzytkownik.moje_dane();
					}
					if (z == "4")
					{
						film1.wyswietl_wszystkie_filmy();
						cin.ignore();
					}
					if (z == "5")
					{
						uzytkownik.wyloguj();
						break;
					}
					if (z == "6")
					{
						uzytkownik.wylacz_program();
					}
					system("pause");
				}
			}
			if (uzytkownik.administrator == '1')
			{
				while (true) {
					string z = " ";
					while (z != "1" && z != "2" && z != "3" && z != "4" && z != "5" && z != "6" && z != "7" && z != "8" && z != "9" && z != "10" && z != "11" && z != "12" && z != "13" && z != "14" && z !="15")
					{
						system("cls");
						cout << endl << endl << "******************* MENU ********************" << endl << endl;
						cout << "Wybierz opcje z menu: " << endl;
						cout << "1.Wypozycz film " << endl;
						cout << "2.Oddaj film " << endl;
						cout << "3.Moje konto " << endl << endl;
						cout << "********** FUNKCJE ADMINISTRATORA ***********" << endl << endl;
						cout << "4.Wyswietl wszystkie filmy " << endl;
						cout << "5.Wyswietl uzytkownikow " << endl;
						cout << "6.Dodaj film " << endl;
						cout << "7.Zmien ilosc filmow " << endl;
						cout << "8.Dezaktywuj konto " << endl;
						cout << "9.Aktywuj konto " << endl;
						cout << "10.Nadaj prawa administratora " << endl;
						cout << "11.Odbierz prawa administratora " << endl;
						cout << "Utworz raporty: " << endl;
						cout << "12. Raport ogolny " << endl;
						cout << "13.Ile razy dany film zostal wypozyczony i ile zarobil " << endl << endl;
						cout << "*********************************************" << endl << endl;
						cout << "14.Wyloguj sie " << endl;
						cout << "15.Wylacz " << endl << endl;
						cout << "Wybieram: ";
						cin >> z;
						system("cls");
					}

					if (z == "1")
					{
						film1.wyswietl_wszystkie_filmy();
						uzytkownik.wybierz_film();
						film1.sprawdz_czy_dostepny(uzytkownik.film_wyp);
						int b = film1.id;
						if (film1.dostepny == 1)
						{
							uzytkownik.wypozycz_film(a,b);
							film1.odejmij(b);
						}
						else
						{
							cout << "Brak egzemplarzy wybranego filmu. Wybierz inny :)"<<endl;
						}
					
					}
					if (z == "2")
					{
						film1.wyswietl_wszystkie_filmy();
						uzytkownik.oddaj_film(a);
						film1.dodaj(uzytkownik.film_wyp);
					}
					if (z == "3")
					{
						uzytkownik.moje_dane();
					}
					if (z == "4")
					{
						film1.wyswietl_wszystkie_filmy();
						cin.ignore();
					}
					if (z == "5")
					{
						uzytkownik.wyswietl_uzytkownikow();
						cin.ignore();
					}
					if (z == "6")
					{
						film1.dodaj_film();
					}
					if (z == "7")
					{
						film1.wyswietl_wszystkie_filmy();
						film1.zmiana_ilosci();
					}
					if (z == "8")
					{
						uzytkownik.wyswietl_uzytkownikow();
						uzytkownik.dezaktywuj();
					}
					if (z == "9")
					{
						uzytkownik.wyswietl_uzytkownikow();
						uzytkownik.aktywuj();
					}
					if (z == "10")
					{
						uzytkownik.wyswietl_uzytkownikow();
						uzytkownik.nadaj_prawa();
					}
					if (z == "11")
					{
						uzytkownik.wyswietl_uzytkownikow();
						uzytkownik.odbierz_prawa();
					}
					if (z == "12")
					{
						film1.raportogolny();
					}
					if (z == "13")
					{
						film1.raport_zaro();
					}
					if (z == "14")
					{
						uzytkownik.wyloguj();
						break;
					}
					if (z == "15")
					{
						uzytkownik.wylacz_program();
					}
					system("pause");
				}
			}
		}
	}
}