#pragma once
#include "pch.h"
#include <iostream>
#include <string>
#include <sstream>
#include <mysql.h>
#include <iomanip>
#include <regex>
#include <ctime>
#include <Windows.h>
#include <conio.h>
#include <time.h>
#include <vector>

using namespace std;

class Telefonia
{
public:
	//tylko admin
	int dodaj_uzytkownika(MYSQL *polaczenie);//zrobione
	int usun_uzytkownika(MYSQL *polaczenie);//zrobione
	int edytuj_uzytkownika(MYSQL *polaczenie);//zrobione
	void wyswietl_uzytkownikow(MYSQL *polaczenie);//zrobione
	void wyswietl_historie(MYSQL *polaczenie);//zrobione
	int dodaj_wpis_do_historii(MYSQL *polaczenie);
	void statystyka(MYSQL *polaczenie);
	//tylko uzytkownik
	void wyswietl_dane(MYSQL *polaczenie,char id);//zrobione
	void wyswietl_historie(MYSQL *polaczenie,string numer_uzytkownika);//zrobione
	//wszyscy
	int przeprowadz_polaczenie(MYSQL *polaczenie,string numer_nadawcy);//zrobione


};