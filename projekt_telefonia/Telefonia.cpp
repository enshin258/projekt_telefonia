#pragma once
#include "pch.h"
#include "Telefonia.h"

int Telefonia::dodaj_uzytkownika(MYSQL *polaczenie)
{
	string imie, nazwisko, wiek, login, haslo, numer, admin;
	bool same_litery_imie;
	bool same_litery_nazwisko;
	bool same_cyfry_wiek;
	bool same_cyfry_numer;

	cout << "Prosze podac dane uzytkownika do dodania" << endl;
	cout << "Imie: " << endl;
	cin >> imie;
	same_litery_imie= regex_match(imie, regex("^[A-Za-z]+$"));
	if (same_litery_imie == false)
	{
		cout << "Blad wprowadzania danych" << endl;
		return -1;
	}
	cout << "Nazwisko: " << endl;
	cin >> nazwisko;
	same_litery_nazwisko = regex_match(nazwisko, regex("^[A-Za-z]+$"));
	if (same_litery_nazwisko == false)
	{
		cout << "Blad wprowadzania danych" << endl;
		return -1;
	}
	cout << "Wiek: " << endl;
	cin >> wiek;
	same_cyfry_wiek = regex_match(wiek, regex("^[0-9]+$"));
	if (same_cyfry_wiek == false)
	{
		cout << "Blad wprowadzania danych" << endl;
		return -1;
	}
	cout << "Login do jego konta: " << endl;
	cin >> login;
	cout << "Haslo do jego konta: " << endl;
	cin >> haslo;
	cout << "Numer telefonu: " << endl;
	cin >> numer;
	same_cyfry_numer = regex_match(numer, regex("^[0-9]+$"));
	if (same_cyfry_wiek == false || numer.length() != 9)
	{
		cout << "Blad wprowadzania danych" << endl;
		return -1;
	}

	cout << "Czy uzytkownik ten ma byc adminem ?" << endl;
	cout << "1.Tak" << endl;
	cout << "2.Nie" << endl;
	int czy_admin;
	cin >> czy_admin;

	switch (czy_admin)
	{
	case 1:
	{
		admin = '1';
		break;
	}
	case 2:
	{
		admin = '0';
		break;
	}
	default:
		cout << "Blad wprowadzania danych" << endl;
		return -1;
		break;
	}


	int poprawnosc = 0;
	stringstream ss;
	ss << "INSERT INTO uzytkownicy (imie,nazwisko,wiek,login,haslo,numer,admin) VALUES ('" << imie << "','" << nazwisko << "'," << wiek << ",'" << login << "','" << haslo << "'," << numer << "," << admin << ")";

	//w celu weryfikacji czy zapytanie sql jest poprawne
	string test = ss.str();
	cout << test << endl << endl;

	string zapytanie = ss.str();
	const char* q = zapytanie.c_str();
	poprawnosc = mysql_query(polaczenie, q);

	if (poprawnosc == 0)
	{
		cout << "Pomyœlnie dodano uzytkownika" << endl;
		return 0;

	}
	else
	{
		cout << mysql_error(polaczenie) << endl;
		cout << "Blad w wprowadzaniu uzytkowania" << endl;
		return -1;

	}

	return 0;
}


int Telefonia::usun_uzytkownika(MYSQL *polaczenie)
{
	string id_usuniecia;
	bool same_cyfry_id_usuniecia;
	cout << "Prosze podac ID uzytkownika do usunieca" << endl;
	cin >> id_usuniecia;
	same_cyfry_id_usuniecia = regex_match(id_usuniecia, regex("^[0-9]+$"));
	if (same_cyfry_id_usuniecia == false)
	{
		cout << "Blad wprowadzania danych" << endl;
		return -1;
	}


	int poprawnosc = 0;
	stringstream ss;
	ss << "DELETE FROM uzytkownicy WHERE id = " << id_usuniecia;
	string test = ss.str();
	cout << test << endl;

	string zapytanie = ss.str();
	const char* q = zapytanie.c_str();
	poprawnosc = mysql_query(polaczenie, q);



	if (poprawnosc == 0)
	{
		cout << "Pomyœlnie usunieto uzytkownika" << endl;
	}
	else
	{
		cout << mysql_error(polaczenie) << endl;
		cout << "Blad w usuwaniu uzytkowania" << endl;
	}

}


void Telefonia::wyswietl_uzytkownikow(MYSQL *polaczenie)
{
	MYSQL_ROW row;
	MYSQL_RES* res;

	int poprawnosc = 0;


	poprawnosc = mysql_query(polaczenie, "SELECT * FROM uzytkownicy ");


	if (poprawnosc == 0)
	{
		res = mysql_store_result(polaczenie);
		
		cout << fixed << "id | imie | nazwisko | wiek | login | haslo | numer | admin" << endl;

		while (row = mysql_fetch_row(res))
		{
			cout<<row[0] << " | " << row[1] << " | " << row[2] << " | " << row[3] << " | " << row[4] << " | " << row[5] << " | " << row[6] << " | " << row[7] << endl << endl;
		}

		cout << "Pomyslnie wyswietlono uzytkownikow " << endl;
	}
	else
	{
		cout << mysql_error(polaczenie) << endl;
		cout << "Blad w wyswietlaniu uzytkownikow" << endl;
	}
}


int Telefonia::edytuj_uzytkownika(MYSQL *polaczenie)
{
	string id_modyfikacja;
	bool same_cyfry_id_modyfikacja;
	cout << "Prosze podac id uzytkownika do modyfikacji" << endl;
	cin >> id_modyfikacja;
	same_cyfry_id_modyfikacja = regex_match(id_modyfikacja, regex("^[0-9]+$"));
	if (same_cyfry_id_modyfikacja == false)
	{
		cout << "Blad wprowadzania danych" << endl;
		return -1;
	}

	MYSQL_ROW row;
	MYSQL_RES* res;


	int poprawnosc = 0;
	cout << "Aktualne dane uzytkownika:" << endl;
	stringstream ss;
	ss << "SELECT * FROM uzytkownicy WHERE id = " << id_modyfikacja;
	string test = ss.str();
	cout << test << endl;

	string zapytanie = ss.str();
	const char* q = zapytanie.c_str();
	poprawnosc = mysql_query(polaczenie, q);
	if (poprawnosc == 0)
	{
		res = mysql_store_result(polaczenie);
		cout << fixed << "id | imie | nazwisko | wiek | login | haslo | numer | admin" << endl;

		while (row = mysql_fetch_row(res))
		{
			cout << row[0] << " | " << row[1] << " | " << row[2] << " | " << row[3] << " | " << row[4] << " | " << row[5] << " | " << row[6] << " | " << row[7] << endl << endl;

		}

	}
	else
	{
		cout << mysql_error(polaczenie) << endl;
		cout << "Blad w wyswietlaniu uzytkownikow" << endl;
	}

	string imie, nazwisko, wiek, login, haslo, numer, admin;
	bool same_litery_imie;
	bool same_litery_nazwisko;
	bool same_cyfry_wiek;
	bool same_cyfry_numer;

	cout << "Prosze podac dane uzytkownika do zmodyfikowania" << endl;
	cout << "Imie: " << endl;
	cin >> imie;
	same_litery_imie = regex_match(imie, regex("^[A-Za-z]+$"));
	if (same_litery_imie == false)
	{
		cout << "Blad wprowadzania danych" << endl;
		return -1;
	}
	cout << "Nazwisko: " << endl;
	cin >> nazwisko;
	same_litery_nazwisko = regex_match(nazwisko, regex("^[A-Za-z]+$"));
	if (same_litery_nazwisko == false)
	{
		cout << "Blad wprowadzania danych" << endl;
		return -1;
	}
	cout << "Wiek: " << endl;
	cin >> wiek;
	same_cyfry_wiek = regex_match(wiek, regex("^[0-9]+$"));
	if (same_cyfry_wiek == false)
	{
		cout << "Blad wprowadzania danych" << endl;
		return -1;
	}
	cout << "Login do jego konta: " << endl;
	cin >> login;
	cout << "Haslo do jego konta: " << endl;
	cin >> haslo;
	cout << "Numer telefonu: " << endl;
	cin >> numer;
	same_cyfry_numer = regex_match(numer, regex("^[0-9]+$"));
	if (same_cyfry_wiek == false || numer.length() != 9)
	{
		cout << "Blad wprowadzania danych" << endl;
		return -1;
	}

	cout << "Czy uzytkownik ten ma byc adminem ?" << endl;
	cout << "1.Tak" << endl;
	cout << "2.Nie" << endl;
	int czy_admin;
	cin >> czy_admin;

	switch (czy_admin)
	{
	case 1:
	{
		admin = '1';
		break;
	}
	case 2:
	{
		admin = '0';
		break;
	}
	default:
		cout << "Blad wprowadzania danych" << endl;
		return -1;
		break;
	}


	int poprawnosc_2 = 0;
	stringstream ss_2;
	ss_2 << "UPDATE uzytkownicy SET imie =" << "'" << imie << "'" << ",nazwisko=" << "'" << nazwisko << "'" << ",wiek=" << wiek << ",login=" << "'" << login << "'" << ",haslo=" << "'" << haslo << "'" << ",numer=" << numer << ",admin=" << admin << " WHERE id=" << "'" << id_modyfikacja << "'";

	//w celu weryfikacji czy zapytanie sql jest poprawne
	string test_2 = ss_2.str();
	cout << test_2 << endl << endl;
	string zapytanie_2 = ss_2.str();
	const char* q_2 = zapytanie_2.c_str();
	poprawnosc_2 = mysql_query(polaczenie, q_2);

	if (poprawnosc_2 == 0)
	{
		cout << "Pomyœlnie zmodyfikowanie uzytkownika" << endl;
		return 0;

	}
	else
	{
		cout << mysql_error(polaczenie) << endl;
		cout << "Blad w modyfikowaniu danych uzytkowania" << endl;
		return -1;

	}

	return 0;
}

void Telefonia::wyswietl_dane(MYSQL *polaczenie,char id)
{
	MYSQL_ROW row;
	MYSQL_RES* res;

	int poprawnosc = 0;
	stringstream ss;
	ss << "SELECT * FROM uzytkownicy WHERE id=" << id;

	//w celu weryfikacji czy zapytanie sql jest poprawne
	string test = ss.str();
	cout << test << endl << endl;

	string zapytanie = ss.str();
	const char* q = zapytanie.c_str();
	poprawnosc = mysql_query(polaczenie, q);
	if(poprawnosc==0)
	{
		res = mysql_store_result(polaczenie);

		cout << fixed << "id | imie | nazwisko | wiek | login | haslo | numer | admin" << endl;

		while (row = mysql_fetch_row(res))
		{
			cout << row[0] << " | " << row[1] << " | " << row[2] << " | " << row[3] << " | " << row[4] << " | " << row[5] << " | " << row[6] << " | " << row[7] << endl << endl;
		}
		cout << "Pomyslnie wyswietlono dane uzytkownika" << endl;
	}
	else
	{
		cout << mysql_error(polaczenie) << endl;
		cout << "Blad w wyswietlaniu uzytkownikow" << endl;
	}
}


