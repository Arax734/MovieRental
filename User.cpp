#include "User.h"
#include "Film.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include "Film.h"
#include <ctime>
#include <vector>
#include <stdio.h>
#include <conio.h>
#pragma warning(disable : 4996)
using namespace std;
short unsigned int status;
char actual;
string input;
void User::rejestracja()
{
    system("cls");
    cout<<"Podaj imie: ";
    cin.ignore();
    getline(cin,imie);
    cout<<"Podaj nazwisko: ";
    getline(cin,nazwisko);
    cout<<"Podaj nick: ";
    getline(cin,nick);
    cout<<"Podaj email: ";
    getline(cin,email);
    cout<<("Podaj haslo: ");
    getline(cin,haslo);
    cout<<"Podaj wiek: ";
    cin>>wiek;
    aktywowane = '1';
    administrator = '0';
    fstream plik_pomocniczy;
    int liczba=0;
    plik_pomocniczy.open("pomocnicze/id_user.txt",ios::in);
  	while(plik_pomocniczy>>liczba)
    {
    	id=liczba;
	}
	plik_pomocniczy.close();
    fstream plik;
    plik.open("baza/wszyscy_uzytkownicy.txt", ios::out | ios::app);
    plik<<id<<";"<<imie<<";"<<nazwisko<<";"<<nick<<";"<<email<<";"<<haslo<<";"<<wiek<<";"<<aktywowane<<";"<< administrator << endl;
    
    id++;
    plik_pomocniczy.open("pomocnicze/id_user.txt",ios::out);
    plik_pomocniczy<<id;
    plik_pomocniczy.close();

    
    plik.close();
}
void User::logowanie() {
    haslo = "";
    input = "";
    string nick_pom, haslo_pom;   
    cout << "Podaj nick: ";
    cin >> nick_pom;
    cout << "Podaj haslo: ";
    do {
        actual = NULL;
        actual = getch();
        status = static_cast <int>(actual);
        if (status == 13)
            break;
        input += actual;
        cout << "*";
    } while (1);
    ifstream myFileStream("baza/wszyscy_uzytkownicy.txt");
    if (!myFileStream.is_open()) {
        cout << "blad" << endl;
    }
    string myString;
    string line;
    while (getline(myFileStream, line))
    {
        string pomocnicza;
        stringstream ss(line);
        getline(ss, pomocnicza, ';');
        istringstream(pomocnicza) >> id;
        getline(ss, imie, ';');
        getline(ss, nazwisko, ';');
        getline(ss, nick, ';');
        getline(ss, email, ';');
        getline(ss, haslo, ';');      
                           
        getline(ss, pomocnicza, ';');
        istringstream(pomocnicza) >> wiek;
        getline(ss, pomocnicza, ';');
        istringstream(pomocnicza) >> aktywowane;
        getline(ss, pomocnicza, ';');
        istringstream(pomocnicza) >> administrator;
        if (nick == nick_pom) {
            if (haslo == input) {
                if (aktywowane == '0') {
                    cout << endl << endl << "Konto nie jest aktywne" << endl;;
                    exit(0);
                }
                system("cls");
                cout << "Zalogowano pomyslnie!" << endl << endl << endl << endl;
                zalogowany = true;
                break;
            }
            else {

                cout << endl << "Haslo jest niepoprawne!" << endl << endl;
                cout << "Sprobuj ponownie" << endl << endl;
                break;

            }
            break;
        }
    }
    myFileStream.close();
   
}
void User::wyswietl_uzytkownikow()
{
	ifstream myFileStream("baza/wszyscy_uzytkownicy.txt");
	if (!myFileStream.is_open()) {
		cout << "blad" << endl;
	}
	string myString;
	string line;
	while (getline(myFileStream, line))
	{
		string pomocnicza;
		stringstream ss(line);
		getline(ss, pomocnicza, ';');
		istringstream(pomocnicza) >> id;
		getline(ss, imie, ';');
		getline(ss, nazwisko, ';');
		getline(ss, nick, ';');
		getline(ss, email, ';');
		getline(ss, haslo, ';');
		getline(ss, pomocnicza, ';');
		istringstream(pomocnicza) >> wiek;
		getline(ss, pomocnicza, ';');
        istringstream(pomocnicza) >> aktywowane;
        getline(ss, pomocnicza, ';');
        istringstream(pomocnicza) >> administrator;
        getline(ss, pomocnicza, ';');
        cout << "ID: " << id << "." << endl;
		cout << "Imie: " << imie << "." << endl;
		cout << "Nazwisko: " << nazwisko << endl;
		cout << "Nick: " << nick << endl;
		cout << "Email: " << email << endl;
		cout << "Haslo: " << " " << haslo << endl;
		cout << "wiek: " << " " << wiek << endl;
        cout << "Aktywowane(1-to aktywne, 0-to dezaktywowane): " << " " << aktywowane << endl;
        cout << "Administrator(1-to aktywny, 0-to brak): " << " " << administrator << endl;
        cout << "*************************************************" << endl << endl << endl << endl;
	}
	myFileStream.close();
    
}
void User::moje_dane()
{
    cout << "ID: " << id << "." << endl;
    cout << "Imie: " << imie << "." << endl;
    cout << "Nazwisko: " << nazwisko << endl;
    cout << "Nick: " << nick << endl;
    cout << "Email: " << email << endl;
    cout << "Haslo: " << " " << haslo << endl;
    cout << "wiek: " << " " << wiek << endl;
    cout << "Aktywowane(1-to aktywne, 0-to dezaktywowane): " << " " << aktywowane << endl;
    cout << "Administrator(1-to aktywny, 0-to brak): " << " " << administrator << endl;
}
void User::nadaj_prawa()
{
    cout << "Nadaj prawa administratora" << endl;
    fstream plik;
    plik.open("baza/wszyscy_uzytkownicy.txt", ios::in | ios::out | ios::app);
    string tekst;
    vector <string> temp;
    int id_dodatkowe;
    cout << "Podaj ID uzytkownika, ktoremu chcesz nadac prawa administratora: ";
    cin >> id_dodatkowe;
    int numer_linii = 1;
    if (plik.good())
    {
        ifstream myFileStream("baza/wszyscy_uzytkownicy.txt");
        if (!myFileStream.is_open()) {
            cout << "blad" << endl;
        }
        string myString;
        string line;
        while (getline(myFileStream, line))
        {
            string pomocnicza;
            stringstream ss(line);
            getline(ss, pomocnicza, ';');
            istringstream(pomocnicza) >> id;
            getline(ss, imie, ';');
            getline(ss, nazwisko, ';');
            getline(ss, nick, ';');
            getline(ss, email, ';');
            getline(ss, haslo, ';');
            getline(ss, wypozyczone_filmy, ';');
            getline(ss, pomocnicza, ';');
            istringstream(pomocnicza) >> wiek;
            getline(ss, pomocnicza, ';');
            istringstream(pomocnicza) >> aktywowane;
            getline(ss, pomocnicza, ';');
            istringstream(pomocnicza) >> administrator;
            
            if (numer_linii != id_dodatkowe)
            {
                temp.push_back(line);
            }
            else {
                char accept;
                system("cls");
                cout << "Czy chcesz nadac prawa administratora uzytkownikowi " << nick << "? y/n: ";
                cin >> accept;
                if (accept != 'y') {
                    exit(0);
                }
                else {
                    int i = line.length();
                    line[i - 1] = '1';
                    temp.push_back(line);
                    administrator = '1';
                    cin.ignore();
                }
            }
            numer_linii++;
        }
        myFileStream.close();
    }
    plik.close();
    plik.open("baza/wszyscy_uzytkownicy.txt", ios::in | ios::out | ios::trunc);
    for (int i = 0; i < temp.size(); i++)
    {
        plik << temp.at(i) << endl;
    }
    plik.close();
}
void User::odbierz_prawa()
{
    cout << "Odbierz prawa administratora" << endl;
    fstream plik;
    plik.open("baza/wszyscy_uzytkownicy.txt", ios::in | ios::out | ios::app);
    string tekst;
    vector <string> temp;
    int id_dodatkowe;
    cout << "Podaj ID uzytkownika, ktoremu chcesz odebrac prawa administratora: ";
    cin >> id_dodatkowe;
    int numer_linii = 1;
    if (plik.good())
    {
        ifstream myFileStream("baza/wszyscy_uzytkownicy.txt");
        if (!myFileStream.is_open()) {
            cout << "blad" << endl;
        }
        string myString;
        string line;
        while (getline(myFileStream, line))
        {
            string pomocnicza;
            stringstream ss(line);
            getline(ss, pomocnicza, ';');
            istringstream(pomocnicza) >> id;
            getline(ss, imie, ';');
            getline(ss, nazwisko, ';');
            getline(ss, nick, ';');
            getline(ss, email, ';');
            getline(ss, haslo, ';');
            getline(ss, wypozyczone_filmy, ';');
            getline(ss, pomocnicza, ';');
            istringstream(pomocnicza) >> wiek;
            getline(ss, pomocnicza, ';');
            istringstream(pomocnicza) >> aktywowane;
            getline(ss, pomocnicza, ';');
            istringstream(pomocnicza) >> administrator;

            if (numer_linii != id_dodatkowe)
            {
                temp.push_back(line);
            }
            else {
                char accept;
                system("cls");
                cout << "Czy chcesz odebrac prawa administratora uzytkownikowi " << nick << "? y/n: ";
                cin >> accept;
                if (accept != 'y') {
                    exit(0);
                }
                else {
                    int i = line.length();
                    line[i - 1] = '0';
                    temp.push_back(line);
                    administrator = '0';
                    cin.ignore();
                }
            }
            numer_linii++;
        }
        myFileStream.close();
    }
    plik.close();
    plik.open("baza/wszyscy_uzytkownicy.txt", ios::in | ios::out | ios::trunc);
    for (int i = 0; i < temp.size(); i++)
    {
        plik << temp.at(i) << endl;
    }
    plik.close();
}
void User::wyloguj()
{
    system("cls");
    cout << "Wylogowano sie pomyslnie" << endl << endl;
    zalogowany = false;
}
void User::wylacz_program()
{
    system("cls");
    cout << "Wylaczono pomyslnie" << endl << endl;
    exit(0);
}
void User::wybierz_film()
{
    film_wyp = 0;
    int x;
    fstream plik_pomocniczy;
    int liczba = 0;
    plik_pomocniczy.open("pomocnicze/id.txt", ios::in);
    while (plik_pomocniczy >> liczba)
    {
        x = liczba;
    }
    plik_pomocniczy.close();
    while (film_wyp<1 || film_wyp>x)
    {
        cout << "Wybierz film do wypozyczenia: ";
        cin >> film_wyp;
    }
}
void User::wypozycz_film(int id_u, int id_film)
{
    int dzien, miesiac, rok;
    time_t tim = time(0);
    tm* gottime = gmtime(&tim);

    dzien = gottime->tm_mday;
    miesiac = gottime->tm_mon + 1;
    rok = gottime->tm_year + 1900;

    fstream plik;
    plik.open("baza/wypozyczenia.txt", ios::out | ios::app);
    plik << id_u << ";" << id_film << ";" << dzien << ";" << miesiac << ";" << rok << endl;
    plik.close();
}
void User::oddaj_film(int id_u) 
{
    cout << "Oddaj film" << endl;
    fstream plik;
    plik.open("baza/wypozyczenia.txt", ios::in | ios::out | ios::app);
    string tekst;
    vector <string> temp;
    int id_dodatkowe;
    cout << "Podaj ID filmu, ktory chcesz oddac: ";
    cin >> id_dodatkowe;
    int numer_pomocniczy = 1;
    if (plik.good())
    {
        ifstream myFileStream("baza/wypozyczenia.txt");
        if (!myFileStream.is_open()) {
            cout << "blad" << endl;
        }
        string myString;
        string line;
        while (getline(myFileStream, line))
        {
            int id_uzytkownika, id_filmu;
            int day, month, year;
            string pomocnicza;
            stringstream ss(line);
            getline(ss, pomocnicza, ';');
            istringstream(pomocnicza) >> id_uzytkownika;
            getline(ss, pomocnicza, ';');
            istringstream(pomocnicza) >> id_filmu;
            getline(ss, pomocnicza, ';');
            istringstream(pomocnicza) >> day;
            getline(ss, pomocnicza, ';');
            istringstream(pomocnicza) >> month;
            getline(ss, pomocnicza, ';');
            istringstream(pomocnicza) >> year;
            if (id_filmu != id_dodatkowe || id != id_uzytkownika)
            {
                temp.push_back(line);
            }
            else {
                int numer_dodatkowy = id_filmu;
                char accept;
                system("cls");
                ifstream myFileStream2("baza/wszystkie_filmy.txt");
                if (!myFileStream2.is_open()) {
                    cout << "blad" << endl;
                }
                string myString;
                string line2;
                while (getline(myFileStream2, line2))
                {
                    int id_filmu, rok_premiery, ile_sztuk, cena, ilosc_wypozyczen;
                    string nazwa, rezyser, firma, gatunek;
                    string pomocnicza;
                    stringstream ss(line2);
                    getline(ss, pomocnicza, ';');
                    istringstream(pomocnicza) >> id_filmu;
                    getline(ss, nazwa, ';');
                    getline(ss, rezyser, ';');
                    getline(ss, firma, ';');
                    getline(ss, gatunek, ';');
                    getline(ss, pomocnicza, ';');
                    istringstream(pomocnicza) >> rok_premiery;
                    getline(ss, pomocnicza, ';');
                    istringstream(pomocnicza) >> ile_sztuk;
                    getline(ss, pomocnicza, ';');
                    istringstream(pomocnicza) >> cena;
                    getline(ss, pomocnicza, ';');
                    istringstream(pomocnicza) >> ilosc_wypozyczen;
                    if (numer_pomocniczy == numer_dodatkowy) {
                        cout << "Czy chcesz oddac film " << nazwa << "? y/n: ";
                        cin >> accept;
                        if (accept != 'y') {
                            exit(0);
                        }
                        else {
                            line.clear();
                            numer_pomocniczy++;
                        }
                    }
                    else {
                        numer_pomocniczy++;
                    }
                    
                }
                myFileStream2.close();
            }
        }
        myFileStream.close();
    }
    plik.close();
    plik.open("baza/wypozyczenia.txt", ios::in | ios::out | ios::trunc);
    for (int i = 0; i < temp.size(); i++)
    {
        plik << temp.at(i) << endl;
    }
    plik.close();
}

void User::dezaktywuj()
{
    cout << "Dezaktywuj konto" << endl;
    fstream plik;
    plik.open("baza/wszyscy_uzytkownicy.txt", ios::in | ios::out | ios::app);
    string tekst;
    vector <string> temp;
    int id_dodatkowe;
    cout << "Podaj ID uzytkownika, ktorego konto chcesz dezaktywowac: ";
    cin >> id_dodatkowe;
    int numer_linii = 1;
    if (plik.good())
    {
        ifstream myFileStream("baza/wszyscy_uzytkownicy.txt");
        if (!myFileStream.is_open()) {
            cout << "blad" << endl;
        }
        string myString;
        string line;
        while (getline(myFileStream, line))
        {
            string pomocnicza;
            stringstream ss(line);
            getline(ss, pomocnicza, ';');
            istringstream(pomocnicza) >> id;
            getline(ss, imie, ';');
            getline(ss, nazwisko, ';');
            getline(ss, nick, ';');
            getline(ss, email, ';');
            getline(ss, haslo, ';');
            getline(ss, wypozyczone_filmy, ';');
            getline(ss, pomocnicza, ';');
            istringstream(pomocnicza) >> wiek;
            getline(ss, pomocnicza, ';');
            istringstream(pomocnicza) >> aktywowane;
            getline(ss, pomocnicza, ';');
            istringstream(pomocnicza) >> administrator;
            if (numer_linii != id_dodatkowe)
            {
                temp.push_back(line);
            }
            else {
                char accept;
                system("cls");
                cout << "Czy chcesz dezaktywowac konto uzytkownika " << nick << "? y/n: ";
                cin >> accept;
                if (accept != 'y') {
                    exit(0);
                }
                else {
                    int i = line.length();
                    line[i - 3] = '0';
                    temp.push_back(line);

                    aktywowane = '0';

                }
            }
            numer_linii++;
        }
        myFileStream.close();
    }
    plik.close();
    plik.open("baza/wszyscy_uzytkownicy.txt", ios::in | ios::out | ios::trunc);
    for (int i = 0; i < temp.size(); i++)
    {
        plik << temp.at(i) << endl;
    }
    plik.close();
    administrator = '1';
}
void User::aktywuj()
{
    cout << "Aktywuj konto" << endl;
    fstream plik;
    plik.open("baza/wszyscy_uzytkownicy.txt", ios::in | ios::out | ios::app);
    string tekst;
    vector <string> temp;
    int id_dodatkowe;
    cout << "Podaj ID uzytkownika, ktorego konto chcesz aktywowac: ";
    cin >> id_dodatkowe;
    int numer_linii = 1;
    if (plik.good())
    {
        ifstream myFileStream("baza/wszyscy_uzytkownicy.txt");
        if (!myFileStream.is_open()) {
            cout << "blad" << endl;
        }
        string myString;
        string line;
        while (getline(myFileStream, line))
        {
            string pomocnicza;
            stringstream ss(line);
            getline(ss, pomocnicza, ';');
            istringstream(pomocnicza) >> id;
            getline(ss, imie, ';');
            getline(ss, nazwisko, ';');
            getline(ss, nick, ';');
            getline(ss, email, ';');
            getline(ss, haslo, ';');
            getline(ss, wypozyczone_filmy, ';');
            getline(ss, pomocnicza, ';');
            istringstream(pomocnicza) >> wiek;
            getline(ss, pomocnicza, ';');
            istringstream(pomocnicza) >> aktywowane;
            getline(ss, pomocnicza, ';');
            istringstream(pomocnicza) >> administrator;
            if (numer_linii != id_dodatkowe)
            {
                temp.push_back(line);
            }
            else {
                char accept;
                system("cls");
                cout << "Czy chcesz aktywowac konto uzytkownika " << nick << "? y/n: ";
                cin >> accept;
                if (accept != 'y') {
                    exit(0);
                }
                else {
                    int i = line.length();
                    line[i - 3] = '1';
                    temp.push_back(line);

                    aktywowane = '1';
                    
                }
            }
            numer_linii++;
        }
        myFileStream.close();
    }
    plik.close();
    plik.open("baza/wszyscy_uzytkownicy.txt", ios::in | ios::out | ios::trunc);
    for (int i = 0; i < temp.size(); i++)
    {
        plik << temp.at(i) << endl;
    }
    plik.close();
    administrator = '1';
}