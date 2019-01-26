#pragma once
#include "pch.h"
#include <iostream>
#include <string>
#include <sstream>
#include <mysql.h>
#include <iomanip>
#include <regex>


using namespace std;

class Telefonia
{
public:
	//tylko admin
	int dodaj_uzytkownika(MYSQL *polaczenie);//zrobione
	int usun_uzytkownika(MYSQL *polaczenie);//zrobione
	int edytuj_uzytkownika(MYSQL *polaczenie);//zrobione
	void wyswietl_uzytkownikow(MYSQL *polaczenie);//zrobione
	void wyswietl_wszystkie_historie(MYSQL *polaczenie);
	int modyfikuj_historie(MYSQL *polaczenie);
	//tylko uzytkownik
	void wyswietl_dane(MYSQL *polaczenie,char id);
	void wyswietl_historie(MYSQL *polaczenie);
	//wszyscy
	int przeprowadz_polaczenie(MYSQL *polaczenie);


};