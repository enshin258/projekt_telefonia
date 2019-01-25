#pragma once
#include "pch.h"
#include "Telefonia.h"

void Telefonia::dodaj_uzytkownika(MYSQL *polaczenie)
{
	string imie, nazwisko, wiek, login, haslo, numer;

	cout << "Prosze podac dane uzytkownika do dodania" << endl;
	cout << "Imie: " << endl;
	cin >> imie;
	cout << "Nazwisko: " << endl;
	cin >> nazwisko;
	cout << "Wiek: " << endl;
	cin >> wiek;
	cout << "Login do jego konta: " << endl;
	cin >> login;
	cout << "Haslo do jego konta: " << endl;
	cin >> haslo;
	cout << "Numer telefonu: " << endl;
	cin >> numer;


	int poprawnosc = 0;
	stringstream ss;
	ss << "INSERT INTO uzytkownicy (imie,nazwisko,wiek,login,haslo,numer) VALUES ('" << imie << "','" << nazwisko << "'," << wiek << ",'" << login << "','" << haslo << "'," << numer << ")";
	string test = ss.str();

	cout<<test<<endl;

	string zapytanie = ss.str();
	const char* q = zapytanie.c_str();
	poprawnosc = mysql_query(polaczenie, q);



	if (poprawnosc == 0)
	{
		cout << "Pomyœlnie dodano uzytkownika" << endl;
	}
	else
	{
		cout << mysql_error(polaczenie) << endl;
		cout << "Blad w wprowadzaniu uzytkowania" << endl;
	}


}
void Telefonia::usun_uzytkownika(MYSQL *polaczenie)
{
	string id;

	cout << "Prosze podac ID uzytkownika do usunieca" << endl;
	cin >> id;


	int poprawnosc = 0;
	stringstream ss;
	ss << "DELETE FROM uzytkownicy WHERE id= " << id;
	string test = ss.str();
	cout << test << endl;

	string zapytanie = ss.str();
	const char* q = zapytanie.c_str();
	poprawnosc = mysql_query(polaczenie, q);



	if (poprawnosc == 0)
	{
		cout << "Pomyœlnie dodano uzytkownika" << endl;
	}
	else
	{
		cout << mysql_error(polaczenie) << endl;
		cout << "Blad w wprowadzaniu uzytkowania" << endl;
	}

}