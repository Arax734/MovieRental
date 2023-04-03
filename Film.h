#ifndef FILM_H
#define FILM_H
#include <string>
using namespace std;
class Film
{
public:
    int id;
    string nazwa;
    string rezyser;
    string firma;
    string gatunek;
    int dostepny;
    int rok_premiery;
    int ile_sztuk;
    int cena;
    int ilosc_wypozyczen;
    void dodaj_film();
    void wyswietl_wszystkie_filmy();
    void sprawdz_czy_dostepny(int a);
    void zmiana_ilosci();
    void odejmij(int a);
    void dodaj(int a);
    void raportogolny();
    void raport_zaro();

private:
    
};

#endif // DANE_H