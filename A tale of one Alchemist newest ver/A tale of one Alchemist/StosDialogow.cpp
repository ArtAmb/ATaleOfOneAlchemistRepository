#include "StosDialogow.h"
#include <fstream>
#include <conio.h>
using namespace std;


StosDialogow* push(StosDialogow* top, int set_id, int odp[3], string napis)
{
	StosDialogow* nowy = new StosDialogow;
	if (nowy)
	{
		nowy->id = set_id;
		nowy->MoliweOdp[0] = odp[0];
		nowy->MoliweOdp[1] = odp[1];
		nowy->MoliweOdp[2] = odp[2];
		nowy->dialog = napis;

		nowy->next = top;
		top = nowy;
		
	}
	

		return top;

}


StosDialogow* pop(StosDialogow* top)
{
	StosDialogow* memory;
	if (top == NULL) return top;

	memory = top->next;
	delete top;
	top = memory;

	return top;
}

void peek(StosDialogow* top)
{
	cout << top->dialog << endl;
}

StosDialogow* WyszukajDialog(StosDialogow* top, int numer, bool wypisywanie )
{
	if (numer == 0) return NULL;
	StosDialogow* poszukiwacz = top;

	while (poszukiwacz)
	{
		if (poszukiwacz->id == numer)
		{
			if(wypisywanie)
				cout << poszukiwacz->dialog << endl;
			break;
		}
		else
			poszukiwacz = poszukiwacz->next;
	}

	return poszukiwacz;
}

StosDialogow* ZnajdzDialog(StosDialogow* top, int numer)
{
	if (numer == 0)
	{
		cout << "Dialog nie zostal odnalezniony" << endl;
		return NULL;

	}
	StosDialogow* poszukiwacz = top;

	while (poszukiwacz)
	{
		if (poszukiwacz->id == numer)
		{
		
			break;
		}
		else
			poszukiwacz = poszukiwacz->next;
	}

	return poszukiwacz;
}

StosDialogow* ZaladujDialogiNaStos(StosDialogow* top, string NazwaPilkuDoOtwarcia)
{
	int id;
	string napis;
	char znak;
	int odp[3] = { 0, 0, 0};
	ifstream plik(NazwaPilkuDoOtwarcia.c_str());


	//plik.open(NazwaPilkuDoOtwarcia.c_str(), ios::in);
	if (plik.good() == false) return top;

	while (!plik.eof())
	{
		plik >> id;
		plik.get(znak);
		getline(plik, napis);
		plik >> odp[0];
		plik.get(znak);
		plik >> odp[1];
		plik.get(znak);
		plik >> odp[2];
		plik.get(znak);

		

		top = push(top, id, odp,napis);
		

	}
		
	plik.close();
	return top;
}

int WyswietlDialog(StosDialogow* StosOdpowiedzi, StosDialogow* StosOddzywek, int NumerTekstu, string Gracz, string NPC)
{

	if (NumerTekstu == 0)
	{


		return 0;
	}

	int decyzja, result = 0;
	bool koniec = false;
	StosDialogow* ObecnyDialogOdd = NULL;

	cout << endl;
	cout << NPC << ": ";
	StosDialogow* ObecnyDialogOdp = WyszukajDialog(StosOdpowiedzi, NumerTekstu, true);
	if (ObecnyDialogOdp == NULL) return 0;

	 cout << "1.";
	 WyszukajDialog(StosOddzywek, ObecnyDialogOdp->MoliweOdp[0], true);
	 
	 cout << "2.";
	 WyszukajDialog(StosOddzywek, ObecnyDialogOdp->MoliweOdp[1], true);
	 
	 cout << "3.";
	 WyszukajDialog(StosOddzywek, ObecnyDialogOdp->MoliweOdp[2], true);
	 cout << endl;
	 
	 do
	 {
		 decyzja = _getch();
		 if (decyzja == 224)
			 decyzja = _getch();
		 
		 
		 switch (decyzja)
		 {
		 case '1':
			 cout << Gracz << ": ";
			 ObecnyDialogOdd = WyszukajDialog(StosOddzywek, ObecnyDialogOdp->MoliweOdp[0], true);
			 koniec = true;
			 break;

		 case '2':
			 cout << Gracz << ": ";
			 ObecnyDialogOdd = WyszukajDialog(StosOddzywek, ObecnyDialogOdp->MoliweOdp[1], true);
			 koniec = true;
			 break;

		 case '3':
			 cout << Gracz << ": ";
			 ObecnyDialogOdd = WyszukajDialog(StosOddzywek, ObecnyDialogOdp->MoliweOdp[2], true);
			 koniec = true;
			 break;

		 }
		 
	 } while (koniec == false);
	 if (ObecnyDialogOdd == NULL) return 0;
	 cout << endl;

	 if (ObecnyDialogOdd->MoliweOdp[1] == 0)
	 {
		 result = ObecnyDialogOdd->MoliweOdp[2];
	 }
	 else result = 0;

	 //cout << (result + WyswietlDialog(StosOdpowiedzi, StosOddzywek, ObecnyDialogOdd->MoliweOdp[0], Gracz, NPC)) << endl;

	 return ( result + WyswietlDialog(StosOdpowiedzi, StosOddzywek, ObecnyDialogOdd->MoliweOdp[0],Gracz,NPC) );



}

bool UsunStos(StosDialogow* top)
{
	if (top == NULL) return false;
	while (top)
		top = pop(top);

	return true;

}

void PokazStos(StosDialogow* top)
{
	StosDialogow* podgladacz = top;

	while (podgladacz)
	{
		cout << "Id: " << podgladacz->id << endl;
		cout << "Dialog: " << podgladacz->dialog << endl;
		cout << "Moliwe odp1: " << podgladacz->MoliweOdp[0] << endl;
		cout << "Moliwe odp2: " << podgladacz->MoliweOdp[1] << endl;
		cout << "Moliwe odp2: " << podgladacz->MoliweOdp[2] << endl;
		podgladacz = podgladacz->next;
	}
	

}

void DodatkowyEkwipunek::DodajPrzedmiot()
{
	if (CzyJest == false) CzyJest = true;
	if(Ilosc <= MAX)
		++Ilosc;
	
}
void DodatkowyEkwipunek::UsunPrzedmiot()
{
	if (Ilosc > 0)
		--Ilosc;

	if (Ilosc == 0) CzyJest = false;
}
void DodatkowyEkwipunek::WyswietlPrzedmiot()
{
	if (CzyJest)
		cout << "Masz " << Nazwa << "w ilosci: " << Ilosc << "sztuk"<< endl;
}

DodatkowyEkwipunek* pushEq(DodatkowyEkwipunek* top, int set_id, string nazwa)
{
	DodatkowyEkwipunek* nowy = new DodatkowyEkwipunek;
	if (nowy)
	{
		nowy->IdPrzedmiotu = set_id;
	
		nowy->Nazwa = nazwa;

		nowy->next = top;
		top = nowy;

	}


	return top;

}
bool UsunEq(DodatkowyEkwipunek* top)
{
	if (top == NULL) return false;
	while (top)
		top = popEq(top);

	return true;

}

DodatkowyEkwipunek* popEq(DodatkowyEkwipunek* top)
{
	DodatkowyEkwipunek* memory;
	if (top == NULL) return top;

	memory = top->next;
	delete top;
	top = memory;

	return top;
}
void PokazCalyEq(DodatkowyEkwipunek* top)
{
	if (top == NULL) return;
	DodatkowyEkwipunek* podgladacz = top;

	while (podgladacz)
	{
		podgladacz->WyswietlPrzedmiot();
		podgladacz = podgladacz->next;
	}

}
DodatkowyEkwipunek* WyszukajPrzedmiot(DodatkowyEkwipunek* top, int id)
{
	if (top == NULL) return top;

	DodatkowyEkwipunek* poszukiwacz = top;

	while (poszukiwacz)
	{
		if (poszukiwacz->IdPrzedmiotu == id)
		{
			break;
		}
		else
			poszukiwacz = poszukiwacz->next;
	}

	return poszukiwacz;
}
