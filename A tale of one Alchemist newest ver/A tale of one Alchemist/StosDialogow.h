#pragma once
#include <string>
#include <iostream>

using namespace std;

struct StosDialogow
{
	int id;
	string dialog;
	int MoliweOdp[3];


	StosDialogow* next;	
};


StosDialogow* push(StosDialogow* top, int set_id, int odp[3], string napis);
StosDialogow* pop(StosDialogow* top);
void peek(StosDialogow* top);
int WyswietlDialog(StosDialogow*, StosDialogow*, int, string Gracz, string NPC);
StosDialogow* WyszukajDialog(StosDialogow* top, int numer, bool wypisywanie = false);
StosDialogow* ZaladujDialogiNaStos(StosDialogow* top, string NazwaPilkuDoOtwarcia);
bool UsunStos(StosDialogow* top);
void PokazStos(StosDialogow* top);
StosDialogow* ZnajdzDialog(StosDialogow* top, int numer);

struct DodatkowyEkwipunek
{
	int IdPrzedmiotu;
	bool CzyJest = false;
	int Ilosc = 0;
	string Nazwa;
	int MAX = 5;
	void DodajPrzedmiot();
	void UsunPrzedmiot();
	void WyswietlPrzedmiot();

	DodatkowyEkwipunek* next;

};
DodatkowyEkwipunek* pushEq(DodatkowyEkwipunek* top, int set_id, string nazwa);
bool UsunEq(DodatkowyEkwipunek* top);
DodatkowyEkwipunek* popEq(DodatkowyEkwipunek* top);
void PokazCalyEq(DodatkowyEkwipunek* top);
DodatkowyEkwipunek* WyszukajPrzedmiot(DodatkowyEkwipunek* top, int id);