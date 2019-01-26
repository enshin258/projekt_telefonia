/*
Napisać program do obsługi historii połączeń. Program musi umożliwiać:
1. Zakładanie kont użytkowników przez Administratora-ok
2. Wprowadzenie historii połączeń i ich parametrów przez Administratora
3. Podgląd historii połączeń i ich parametrów dotyczących zalogowanego Użytkownika
4. Wyliczanie przynajmniej dwóch różnych statystyk
5. Zapis i odczyt stanu aplikacji baza danych-ok
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


	MYSQL_ROW row;
	MYSQL_RES* res;
	string login;
	string haslo;

	int poprawnosc = 0;

	while (1)//sprawdzanie kto sie zalogowal
	{
		cout << "Witaj w programie telefonni. Prosze sie zalogowac" << endl;
		cout << "Prosze podac login:" << endl;
		cin >> login;
		cout << "Prosze podac haslo" << endl;
		cin >> haslo;

		stringstream ss;
		ss << "SELECT id,admin,numer FROM uzytkownicy WHERE login = " << "'" << login << "'" << "AND haslo =" << "'" << haslo << "'";
		//weryfikacja sql
		string test = ss.str();
		cout << test << endl << endl << endl;
		string zapytanie = ss.str();
		const char* q = zapytanie.c_str();

		poprawnosc = mysql_query(polaczenie,q);

		if (poprawnosc == 0)
		{
			res = mysql_store_result(polaczenie);
			while (row = mysql_fetch_row(res))
			{

				if (*row[1] == '1')//admin
				{
					while (1)//panel dostepu admina
					{
						cout << "Zalogowano jako uzytkownik z prawami admina" << endl;
						cout << "Co chcesz zrobic?" << endl;
						cout << "1. Wyswietlic wszystkich uzytkownikow i ich dane" << endl;
						cout << "2. Dodac nowego uzytkownika" << endl;
						cout << "3. Edytowac dane uzytkownika" << endl;
						cout << "4. Usunać uzytkownika" << endl;
						cout << "5. Wyswietlic historie wszystkich operacji" << endl;
						cout << "6. Zmodyfikowac historie operacji" << endl;
						int wybor;
						cin >> wybor;
						switch (wybor)
						{
						case 1:
						{
							t.wyswietl_uzytkownikow(polaczenie);
							break;
						}
						case 2:
						{
							t.dodaj_uzytkownika(polaczenie);
							break;
						}
						case 3:
						{
							t.edytuj_uzytkownika(polaczenie);
							break;
						}
						case 4:
						{
							t.usun_uzytkownika(polaczenie);
							break;

						}
						case 5:
						{
							break;
						}
						case 6:
						{
							break;
						}
						default:
							return 0;
							break;
						}
					}
				}
				else if (*row[1] == '0')
				{
					cout << "Panel dostepu uzytkownika" << endl;
					while (1)//panel dostepu uzytkownika
					{
						cout << "Zalogowano na konto zwyklego uzytkownika:" << endl;
						int wybor;
						cout << "Co chcesz zrobic" << endl;
						cout << "1.Przejrzec swoje dane osobowe" << endl;
						cout << "2.Wykonac polaczenie" << endl;
						cout << "3.Wyswietlic swoja histoire polaczen" << endl;
						cin >> wybor;
						switch (wybor)
						{
						case 1:
						{
							char id = *row[0];
							t.wyswietl_dane(polaczenie, id);
							break;
						}
						case 2:
						{
							string numer_nadawcy = row[2];
							t.przeprowadz_polaczenie(polaczenie,numer_nadawcy);
							break;
						}
						case 3:
						{
							break;
						}
						default:
							return -1;
							break;
						}

					}
				}
				else
				{
					cout << "blad, prosze podac poprawny login i haslo" << endl;
					return -1;
				}
			}

		}
		else
		{
			cout << "blad, nie ma uzytkownika z takim loginem i haslem" << endl;
			return -1;
		}

		

		cout << "Prosze podac poprawne dane!" << endl;
	}
}

