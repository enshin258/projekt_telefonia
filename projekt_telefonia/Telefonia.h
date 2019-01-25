#pragma once
#include "pch.h"
#include <iostream>
#include <string>
#include <sstream>
#include <mysql.h>


using namespace std;

class Telefonia
{
public:
	void dodaj_uzytkownika(MYSQL *polaczenie);
	void usun_uzytkownika(MYSQL *polaczenie);
	void edytuj_uzytkownika(MYSQL *polaczenie);
	void przeprowadz_polaczenie(MYSQL *polaczenie);
	void wyswietl_uzytkownikow(MYSQL *polaczenie);
	void wyswietl_historie(MYSQL *polaczenie);
	void modyfikuj_historie(MYSQL *polaczenie);

};