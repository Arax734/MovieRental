#ifndef USER_H
#define USER_H
#include <string>
using namespace std;
class User
{
public:
    
    int id;
    int film_wyp;
    string imie;
    string nazwisko;
    string nick;
    string email;
    string haslo;
    string wypozyczone_filmy;
    string input;
    short unsigned int status;
    char administrator;
    char aktywowane;
    char actual;
    bool zalogowany;
    bool wylacz;
    int wiek;
    int dlug;
    void rejestracja();
    void wyswietl_uzytkownikow();
    void wybierz_film();
    void wypozycz_film(int id, int id2);
    void logowanie();
    void moje_dane();
    void oddaj_film(int id);
    void nadaj_prawa();
    void odbierz_prawa();
    void wyloguj();
    void dezaktywuj();
    void aktywuj();
    void wylacz_program();
private:
    
};

#endif // USER_H