#include "Film.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <string>
#include <stdlib.h>
#include <vector>
#pragma warning(disable : 4996)
using namespace std;
void Film::dodaj_film()
{
    system("cls");
    cout<<"Podaj nazwe filmu: ";
    cin.ignore();
    getline(cin,nazwa);
    cout<<"Podaj imie i nazwisko rezysera filmu: ";
    getline(cin,rezyser);
    cout<<"Podaj nazwe firmy, ktora wyprodukowala film: ";
    getline(cin,firma);
    cout<<"Podaj gatunek filmu: ";
    getline(cin,gatunek);
    cout<<"Podaj rok premiery filmu: ";
    cin>>rok_premiery;
    cout<<"Podaj ilosc sztuk, ktora dodajesz: ";
    cin>>ile_sztuk;
    cout<<"Podaj cene wypozyczenia filmu: ";
    cin>>cena;
    
    fstream plik_pomocniczy;
    int liczba=0;
    plik_pomocniczy.open("pomocnicze/id.txt",ios::in);
  	while(plik_pomocniczy>>liczba)
    {
    	id=liczba;
	}
	plik_pomocniczy.close();
    fstream plik;
    plik.open("baza/wszystkie_filmy.txt", ios::out | ios::app);
    plik<<id<<";"<<nazwa<<";"<<rezyser<<";"<<firma<<";"<<gatunek<<";"<<rok_premiery<<";"<<ile_sztuk<<";"<<cena<<";"<<0<<endl;
    id++;
    plik_pomocniczy.open("pomocnicze/id.txt",ios::out);
    plik_pomocniczy<<id;
    plik_pomocniczy.close();
    
    plik.close();
}
void Film::wyswietl_wszystkie_filmy()
{
    
	ifstream myFileStream("baza/wszystkie_filmy.txt");
	if(!myFileStream.is_open()){
		cout<<"blad"<<endl;
	}
    
	string myString;
	string line;
	while(getline(myFileStream, line))
	{
		string pomocnicza;
		stringstream ss(line);
		getline(ss, pomocnicza, ';');
		istringstream(pomocnicza)>>id;
		getline(ss, nazwa,';');
		getline(ss, rezyser,';');
		getline(ss, firma,';');
		getline(ss, gatunek,';');
		getline(ss, pomocnicza,';');
		istringstream(pomocnicza)>>rok_premiery;
		getline(ss, pomocnicza,';');
		istringstream(pomocnicza)>>ile_sztuk;
		getline(ss, pomocnicza,';');
		istringstream(pomocnicza)>>cena;
        getline(ss, pomocnicza, ';');
        istringstream(pomocnicza) >> ilosc_wypozyczen;
		cout<<"ID: "<<id<<"."<<endl;
		cout<<"Nazwa filmu: "<<nazwa<<endl;
		cout<<"Rezyser: "<<rezyser<<endl;
		cout<<"Gatunek: "<<gatunek<<endl;
		cout<<firma<<" "<<rok_premiery<<endl;
		cout<<"Dostepnych sztuk filmu: "<<ile_sztuk<<". Cena: "<<cena<<" zl."<<endl<<endl<<endl<<endl;
        cout << "*************************************************" << endl;
	}
		myFileStream.close();
}
void Film::zmiana_ilosci() {

    fstream plik;
    plik.open("baza/wszystkie_filmy.txt", ios::in | ios::out | ios::app);
    string tekst;
    vector <string> temp;
    int id_dodatkowe;
    cout << "Podaj ID filmu, ktorego ilosc chcesz zmienic: ";
    cin >> id_dodatkowe;
    int numer_linii = 1;
    if (plik.good())
    {
        ifstream myFileStream("baza/wszystkie_filmy.txt");
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
            if (numer_linii != id_dodatkowe)
            {
                temp.push_back(line);
            }
            else {
                string pozostala_ilosc;
                system("cls");
                cout << "Podaj ilosc dostepnych filmow pt. " << nazwa << ": ";
                cin >> pozostala_ilosc;
                string rok = to_string(rok_premiery);
                string cen = to_string(cena);
                string id_st = to_string(id);
                string il_wyp = to_string(ilosc_wypozyczen);
                temp.push_back(id_st + ";" + nazwa + ";" + rezyser + ";" + firma + ";" + gatunek + ";" + rok + ";" + pozostala_ilosc + ";" + cen + ";" + il_wyp);
            }
            numer_linii++;
        }
        myFileStream.close();
    }
    plik.close();
    plik.open("baza/wszystkie_filmy.txt", ios::in | ios::out | ios::trunc);
    for (int i = 0; i < temp.size(); i++)
    {
        plik << temp.at(i) << endl;
    }
    plik.close();
}
void Film::sprawdz_czy_dostepny(int nr_filmu) 
{
    dostepny = 0;

    ifstream myFileStream("baza/wszystkie_filmy.txt");
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
       
        if (id == nr_filmu)
        {
            if (ile_sztuk == 0)
            {
                dostepny = 0;
            }
            else
            {
                dostepny = 1;
            }
            break;
        }
    }
    myFileStream.close();
}
void Film::odejmij(int id_f)
{
    fstream plik3;
    plik3.open("baza/wszystkie_filmy.txt", ios::in | ios::out | ios::app);
    string tekst;
    vector <string> temp;
    int id_dodatkowe;
    id_dodatkowe = id_f;
    int numer_linii = 1;
    if (plik3.good())
    {
        ifstream myFileStream("baza/wszystkie_filmy.txt");
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
            if (numer_linii != id_dodatkowe)
            {
                temp.push_back(line);
            }
            else {
                    string pozostala_ilosc;
                    ile_sztuk--;
                    ilosc_wypozyczen++;
                    pozostala_ilosc = to_string(ile_sztuk);
                    string rok = to_string(rok_premiery);
                    string cen = to_string(cena);
                    string id_st = to_string(id);
                    string il_wyp = to_string(ilosc_wypozyczen);
                    temp.push_back(id_st + ";" + nazwa + ";" + rezyser + ";" + firma + ";" + gatunek + ";" + rok + ";" + pozostala_ilosc + ";" + cen + ";" + il_wyp);
                
            }
            numer_linii++;
        }
        myFileStream.close();
    }
    plik3.close();
    plik3.open("baza/wszystkie_filmy.txt", ios::in | ios::out | ios::trunc);
    for (int i = 0; i < temp.size(); i++)
    {
        plik3 << temp.at(i) << endl;
    }
    plik3.close();

    fstream plik_pomocniczy;
    plik_pomocniczy.open("pomocnicze/ilosc_wypozyczen.txt",ios::in);
    int liczba;
    plik_pomocniczy >> liczba;
    plik_pomocniczy.close();

    liczba++;

    plik_pomocniczy.open("pomocnicze/ilosc_wypozyczen.txt", ios::out);
    plik_pomocniczy << liczba;
    plik_pomocniczy.close();
}
void Film::dodaj(int id_f)
{
    fstream plik3;
    plik3.open("baza/wszystkie_filmy.txt", ios::in | ios::out | ios::app);
    string tekst;
    vector <string> temp;
    int id_dodatkowe;
    id_dodatkowe = id_f;
    int numer_linii = 1;
    if (plik3.good())
    {
        ifstream myFileStream("baza/wszystkie_filmy.txt");
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
            if (numer_linii != id_dodatkowe)
            {
                temp.push_back(line);
            }
            else {
                string pozostala_ilosc;
                ile_sztuk++;
                pozostala_ilosc = to_string(ile_sztuk);
                string rok = to_string(rok_premiery);
                string cen = to_string(cena);
                string id_st = to_string(id);
                temp.push_back(id_st + ";" + nazwa + ";" + rezyser + ";" + firma + ";" + gatunek + ";" + rok + ";" + pozostala_ilosc + ";" + cen);
            }
            numer_linii++;
        }
        myFileStream.close();
    }
    plik3.close();
    plik3.open("baza/wszystkie_filmy.txt", ios::in | ios::out | ios::trunc);
    for (int i = 0; i < temp.size(); i++)
    {
        plik3 << temp.at(i) << endl;
    }
    plik3.close();


}
void Film::raportogolny()
{
    fstream plik_pomocniczy;
    int a = 0, b = 0, c = 0;
    plik_pomocniczy.open("pomocnicze/id.txt", ios::in);
    while (plik_pomocniczy >> a)
    {
        a = a;
    }
    plik_pomocniczy.close();
    a--;

    plik_pomocniczy.open("pomocnicze/id_user.txt", ios::in);
    while (plik_pomocniczy >> b)
    {
        b = b;
    }
    plik_pomocniczy.close();
    b--;

    plik_pomocniczy.open("pomocnicze/ilosc_wypozyczen.txt", ios::in);
    while (plik_pomocniczy >> c)
    {
        c = c;
    }
    plik_pomocniczy.close();

    int dzien, miesiac, rok;
    time_t tim = time(0);
    tm* gottime = gmtime(&tim);

    dzien = gottime->tm_mday;
    miesiac = gottime->tm_mon + 1;
    rok = gottime->tm_year + 1900;
    
    string sdzien, smiesiac, srok;
    sdzien = to_string(dzien);
    smiesiac = to_string(miesiac);
    srok = to_string(rok);
    string nazwa = "raport_ogolny_" + sdzien + "_" + smiesiac + "_" + srok;
    
    plik_pomocniczy.open("raporty/"+nazwa+".txt", ios::out);
    plik_pomocniczy << "Laczna ilosc filmow w bazie danych: " << a << "." << endl << "Laczna ilosc wypozyczen filmow: " << c << "." << endl << "Laczna liczba zarejestrowanych uzytkownikow: " << b << ".";
    plik_pomocniczy.close();
    cout << "Raport zostal pomyslnie utworzony." << endl;
}
void Film::raport_zaro()
{
    ifstream myFileStream("baza/wszystkie_filmy.txt");
    if (!myFileStream.is_open()) {
        cout << "blad" << endl;
    }
    fstream plik_pomocniczy;
    string nazwa2;

    int dzien, miesiac, rok;
    time_t tim = time(0);
    tm* gottime = gmtime(&tim);

    dzien = gottime->tm_mday;
    miesiac = gottime->tm_mon + 1;
    rok = gottime->tm_year + 1900;

    string sdzien, smiesiac, srok;
    sdzien = to_string(dzien);
    smiesiac = to_string(miesiac);
    srok = to_string(rok);
    nazwa2 = "raport_film_" + sdzien + "_" + smiesiac + "_" + srok;
    
    plik_pomocniczy.open("raporty/" + nazwa2 + ".txt", ios::out);
    string myString;
    string line;
    while (getline(myFileStream, line))
    {
        string pomocnicza;
        stringstream ss(line);
        getline(ss, pomocnicza, ';');
        istringstream(pomocnicza) >> id;
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
        
        plik_pomocniczy << "Tytul: " << nazwa << " zostal wypozyczony " << ilosc_wypozyczen << " razy oraz zarobil " << cena * ilosc_wypozyczen << "zl." << endl;
    }
    plik_pomocniczy.close();
    myFileStream.close();
    cout << "Raport zostal pomyslnie utworzony." << endl;
}
