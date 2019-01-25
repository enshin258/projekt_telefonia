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



int main()
{
	MYSQL *conn;
	conn = mysql_init(0);
	conn = mysql_real_connect(conn, "127.0.0.1", "root", "", "telefonia", 3306, NULL, 0);
	if (conn)
	{
		cout << "Udalo sie nawiazac polaczenie" << endl;

	}
	else
	{
		cout << "Nie udalo sie nawiazac polaczenia" << endl;
	}

	Telefonia t;










		while (1)
			{
				cout << "Witaj w programie telefoni. Prosze sie zalogowac" << endl;
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
					t.wyswietl_uzytkownikow(conn);
					break;
				}
				case 2:
				{
					t.dodaj_uzytkownika(conn);
					break;
				}
				case 3:
				{

				}
				case 4:
				{
					t.usun_uzytkownika(conn);
					break;

				}
				default:
					return 0;
					break;
				}
			}

}

