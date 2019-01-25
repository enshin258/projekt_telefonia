/*
Napisać program do obsługi historii połączeń. Program musi umożliwiać:
1. Zakładanie kont użytkowników przez Administratora
2. Wprowadzenie historii połączeń i ich parametrów przez Administratora
3. Podgląd historii połączeń i ich parametrów dotyczących zalogowanego Użytkownika
4. Wyliczanie przynajmniej dwóch różnych statystyk
5. Zapis i odczyt stanu aplikacji baza danych
6. Użycie biblioteki STL
7. Użycie przeciążania funkcji
8. Użycie operacji lambda
9. Wstawienie programu do repozytorium GIT i wykonanie przynajmniej dwóch commitów


*/

#include "pch.h"
#include <mysql.h>
#include <iostream>
#include "Telefonia.h"



using namespace std;

string login_admin = "admin";
string haslo_admin = "admin";


int main()
{
	MYSQL *polaczenie;
	polaczenie = mysql_init(0);
	polaczenie = mysql_real_connect(polaczenie, "127.0.0.1", "root", "", "telefonia", 3306, NULL, 0);
	if (polaczenie)
	{
		cout << "Udalo sie nawiazac polaczenie" << endl;

	}
	else
	{
		cout << "Nie udalo sie nawiazac polaczenia" << endl;
	}

	Telefonia t;
	string login;
	string haslo;
	while (1)
	{
		cout << "Witaj w programie telefoni. Prosze sie zalogowac" << endl;
		cout << "login: " << endl;
		cin >> login;
		cout << "haslo: " << endl;
		cin >> haslo;
		if (login == login_admin && haslo == haslo_admin)
		{
			while (1)
			{
				cout << "Zalogowano jako admin" << endl;
				cout << "Co chcesz zrobic?" << endl;
				cout << "1. Wyswietlic wszystkich uzytkownikow i ich dane" << endl;
				cout << "2. Dodac nowego uzytkownika" << endl;
				cout << "3. Edytowac dane uzytkownika" << endl;
				cout << "4. Usunać uzytkownika" << endl;
				cout << "5. Wyswietlic historie wszystkich operacji" << endl;
				cout << "6. Zmodyfikowac historie operacji" << endl;
				int wybor_admin;
				cin >> wybor_admin;
				switch (wybor_admin)
				{
				case 1:
				{
					t.dodaj_uzytkownika(polaczenie);
				}
				case 2:
				{
					t.usun_uzytkownika(polaczenie);
				}
				default:
					return 0;
					break;
				}
			}
		}
		cout << "ZLE DANE" << endl;
	}

}

