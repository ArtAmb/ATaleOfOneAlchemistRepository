#pragma once
#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <windows.h>
#include <vector>
#include <time.h>
#include "StosDialogow.h"
#include "Nuty.h"

void gotoxy(int x, int y);

using namespace std;
class CPlansza;
class CDom;
class CFabula;

struct ObszarWystepowania
{
	int MinX, MaxX, MinY, MaxY;
};

const ObszarWystepowania Las1 = { 4,9,43,62 };
const ObszarWystepowania Las2 = { 15,20,51,65 };
const ObszarWystepowania Las3 = { 22,27,68,77 };
const ObszarWystepowania Las4 = { 25,28,45,54 };
const ObszarWystepowania LasMiska = { 46,48,50,57 };
const ObszarWystepowania LasZaRzeka = { 46,48,77,87 };
const ObszarWystepowania RzekaMiska = { 22,26,89,96 };

struct pole                        
{
	int NumerZdarzenia;
	char SymbolPola;

	bool operator ==(pole);
};
struct EQ
{
	bool jest;
	int parametr;
	string nazwa;

};

enum ItemType { WEAPON, ARMOR, FOOD, USEABLE, ARIA, BOOK };

class CItem
{
public:
	string Nazwa, Opis;
	int cena, Rodzaj;
	ItemType TYP;
	void OgolnyKonstruktor(string Nazwa, string Opis, int cena, int Rodzaj) 
	{
		this->Nazwa = Nazwa; this->Opis = Opis; this->cena = cena; this->Rodzaj = Rodzaj;
	}

	CItem() {};
	CItem(string Nazwa,string Opis,int cena, int Rodzaj) : Nazwa(Nazwa),  Opis(Opis), cena(cena),  Rodzaj(Rodzaj)
	{}


};

struct CWeapon : public CItem
{
public:
	int DMG;
	CWeapon() {};
	CWeapon(string Nazwa, string Opis, int cena, int Rodzaj, int DMG) 
	{
		OgolnyKonstruktor(Nazwa, Opis, cena, Rodzaj);
		this->DMG = DMG;
		TYP = WEAPON;
	}
};

struct CArmor : public CItem
{
public:
	int DEF;
	CArmor() {};
	CArmor(string Nazwa, string Opis, int cena, int Rodzaj, int DEF) : DEF(DEF)
	{
		OgolnyKonstruktor(Nazwa, Opis, cena, Rodzaj);
		TYP = ARMOR;
	}
};

struct CUseableItem : public CItem
{
public:
	int ilosc;
	CUseableItem() {};
	CUseableItem(string Nazwa, string Opis, int cena, int Rodzaj, int ilosc) : ilosc(ilosc)
	{
		OgolnyKonstruktor(Nazwa, Opis, cena, Rodzaj);
		TYP = USEABLE;
	}

	bool Dodaj();
	bool Usun();


};
struct CFood : public CItem
{
public:
	int LeczoneHp, OdnawianyGlod;
	CFood() {};
	CFood(string Nazwa, string Opis, int cena, int Rodzaj, int LeczoneHp, int OdnawianyGlod) : LeczoneHp(LeczoneHp), OdnawianyGlod(OdnawianyGlod)
	{
		OgolnyKonstruktor(Nazwa, Opis, cena, Rodzaj);
		TYP = FOOD;
	}
};
struct CFragmentOfPoem : public CItem
{
public:
	int Kolejnosc, ObecnyNumer;
	static const int MaxNumber = 8;
	bool isGood = false;
	CFragmentOfPoem() {};
	CFragmentOfPoem(string Nazwa, string Opis, int cena, int Rodzaj, int kolejnosc) : Kolejnosc(kolejnosc)
	{
		OgolnyKonstruktor(Nazwa, Opis, cena, Rodzaj);
		TYP = ARIA;
		
		ObecnyNumer = 0;
	}

	bool UstawKolejnosc(CFabula* ) const;
	const int RetMaxNum() const { return MaxNumber; }
};
struct CBook : public CItem
{
public:
	int NumerKsiazki;
	fstream plik;
	CBook() {};
	CBook(string Nazwa, string Opis, int cena, int Rodzaj, int NumerKsiazki) : NumerKsiazki(NumerKsiazki)
	{
		OgolnyKonstruktor(Nazwa, Opis, cena, Rodzaj);
		TYP = BOOK;
	}

	bool Czytaj() const;

};

//Bron
//--------------------------------------------------------------
const CWeapon WeaponSiekiera = { "Siekiera", "Generalnie sluzy do scinania drzew, ale mozna ja wykorzystac takze i do scininia innych rzeczy...", 0, 0, 1 };
const CWeapon NozNaWilki = {"Noz na wilki", "10% na natychmiastowe zabicie wilka, +1 przeciw wilka", 100, 1, 2};
const CWeapon DlugiMiecz = { "Dlugi miecz", "zwykly miecz", 200, 0, 3 };
const CWeapon HolySword = { "Swiety kat", "+4 przeciwko istota ciemnosci", 500, 3, 3 };
const CWeapon AntiBearSword = { "BearSlayer", "Bron drzewcowa skuteczna przeciw duzym zwierza", 500, 2, 3 };
const CWeapon Poltorak = { "Miecz poltorareczny", "Bron przystosowana do walki jednoracznej lub oboracz", 500, 0, 4 };
const CWeapon RozrywaczCzasu = { "Rozrywacz Czasu", "Legendarna bron, mowi sie ze jej ciencia naginaja czas", 0, 4, 2 };
const CWeapon Bow = { "Luk", "Bron dystansowa", 700, 5, 0 };
const CWeapon Excalibur = { "Excalibur", "Legendarny miecz obiecanego zwyciestwa", 500, 2, 15 };
//Zbroje
//--------------------------------------------------------------
const CArmor WoodenArmor = { "Drewniana zbroja", "Wlasnorecznie robiona, niewugodna i dosc ciezka, ale na bezrybiu i rak ryba", 0, 1, 0 };

//Przedmioty uzywalne
//--------------------------------------------------------------
const CUseableItem KamienGlupcow = { "Kamien Glupcow", "Stan skupienia tej substancji przypomina polaczenie pozostalych trzech..", 50, 15, 0 };
const CUseableItem MiksturaOgnia = { "Plynny ognien", "Nie, to nie gorzalka", 50, 11, 0 };
const CUseableItem MiksturaTrucizna = { "Trucizna", "Filoka zawiera silna trucizne", 50, 13, 0 };
const CUseableItem MiksturaLecznicza = { "Eliksir leczniczy", "Leczy Twoje rany w trakcie walki", 50, 10, 0 };
const CUseableItem MiksturaAntiUndead = { "Biala woda", "Niegrozna dla ludzi, smiertelna dla istot ciemosci", 50, 12, 0 };
const CUseableItem NozDoRzucania = { "Kunai", "noz do rzucania", 50, 14, 0 };
const CUseableItem Kolczan = { "Kolczan", "zawiera strzaly", 500, 1, 1 };
const CUseableItem MagicalKolczan = { "Pusty kolczan", "Gdy tylko zblizam dlon, wypelnia sie migoczacymi strzalami ", 1000, 2, 1 };



//FOOD
//---------------------------------------------------------------
const CFood Chleb = { "Bochenek chleb", "Smakowicie wygladajacy bochenek chleba", 5, 1, 5, 100 };
const CFood RawMeat = { "Surowe miesa", "Jedz albo zostan zjedzonym", 5, 7, 3, 150};
const CFood Meat = { "Pieczone miesa", "Ladny zapach poteguje apetyt", 7, 3, 8, 250 };
const CFood KanapkaZSzynka = { "Kanapka z szynka", "Pyszna i pozywna kanapka", 7, 9, 15, 500 };

//ARIA
//---------------------------------------------------------------
const CFragmentOfPoem Fragment[9] =
{
 { "Fragment poematu", "Jestestwo me trzonem mego ostrza", 0, 1, 1 },
 { "Fragment poematu", "Zelazo cialem, ogien ma krwia", 0, 2, 2 },
 { "Fragment poematu", "Wykonawszy ponad tysiac ostrzy", 0, 3, 3 },
 { "Fragment poematu", "Nie zaznalem ni smierci, ni zycia", 0, 4, 4 },
 { "Fragment poematu", "Pomimo bolu tworzenia wielu broni", 0, 5, 5 },
 { "Fragment poematu", "Poprzysiaglem ze me dlonie zadnej nie poniosa", 0, 6, 6 },
 { "Fragment poematu", "Tak wiec wznosze swe modly,", 0, 7, 7 },
 { "Fragment poematu", "BEZKRESNA KUZNIO OSTRZY", 0, 8, 8 }
};

//BOOK
//---------------------------------------------------------------
const CBook KsiazkaWilka = { "Brak tytulu", "Ksiazka znaleziona w laboratorium", 0, 1, 1 };
const CBook KsiazkaList = { "List", "Otrzymalego go w podziemiach od pewnego mezczyzny", 0, 1, 2 };
const CBook KsiazkaRaport = { "Raport", "Raport szpiega szwadronu", 0, 1,3 };
const CBook KsiazkaDziennikVectariana = { "Stary dziennik", "Znaleziony przy przywodcy bandy", 0, 1, 4 };



struct OpisFragmentu
{
	bool isGood = false;
	int ObecnyNum = 0;

};


struct UzywaneItemy
{
	const CWeapon* Sword;
	const CArmor* Armor;
	const CUseableItem* UseableItem;

};


struct Ekwipunek
{
	
	//Przedmoity do zbieractwa
	bool siekiera;
	bool kosa;
	bool ZestawAlchemika;
	bool tratwa;
	//Przedmioty do walki
	EQ zbroja;
	EQ bron;
	//Ogolne 
	unsigned int zloto;
	unsigned int exp;
	//surowce
	unsigned int drewno;
	unsigned int zboze;
	unsigned int woda;
	unsigned int fiolki;
	//Pola pomocnicze
	int MAX;
	//Metody zwiekaszania zasobow
	bool DodajDrewno();
	bool DodajZboze();
	bool DodajWode();
	bool DodajFiolke();
	//Metoda - prezentacja itemow
	void WyswietlEq();

	bool operator=(Ekwipunek Ekwip);
};



// Pola komnstrukcyjne
//-------------------
const pole sciana = {1, '|'};
const pole dach_lewa_strona = {1, '/' };
const pole dach_prawa_strona = {1, '\\' };
const pole podloga = {1,'_'};
const pole sufit = { 1, '-' };
const pole puste_pole = {0,' '};
const pole sciana_podziemia = { 1, static_cast<char>(4) };

const pole pola = { 5, '0'}; 
const pole drzewo = { 6, static_cast<char>(5) }; // 'Y'
const pole rzeka = { 7, '~' };
const pole drzwi = { 1, '='};
const pole grobek = { 1, '+' };

//Pola specjalne
//-----------------
const pole podloga_quest = { 4,'_' };
const pole siekiera = { 8 , '&'};
const pole kosa = { 9, 'J' };
const pole PoleStrzezone = { 10,' ' };
const pole MagicznaRoslina = { 11, 'O' };
const pole PrzejscieWMurze = { 12, '-' };
const pole Lozko = { 13, ' ' };
const pole DrzewoZSiekera = { 14, 'Y' };
const pole PoleGlejt = {15, '*' };
const pole PoleAriaDoor = { 17, '=' };


//Ekwipunek
//----------------
const EQ Brak = { false, 0, "BRAK" };
const EQ Siekiera = { true, 1, "Siekiera" };

enum MonsterTYPE { NORMAL = 0, FUR, UNDEAD, BEAR, BOSS };


struct parametry
{
	int sila, obrona, hp, moc;
};

//Parametry
//-------------------
const parametry Straznik = { 100, 0, 50, 10 };
const parametry Wilk = { 30, 0, 10, 5 };
const parametry Misiek = { 2, 0, 5, 15 };
const parametry HepoHepatis = { 80, 0, 100, 30 };
const parametry Bandito = { 40, 1, 30, 10 };
const parametry Truposz = { 40, 0, 40, 15 };
const parametry VectarianBoss = { 50, 0, 40, 20 };
const parametry ClockMasterBoss = { 50, 0, 40, 20 };
const parametry DrzewaczBoss = { 50, 0, 40, 20 };

class CCharacter
{
protected:
	int x, prevX = 0;
	int y, prevY = 0;
	string strName;
	pole PolePostaci;
	CPlansza* pPlansza;
	struct parametry parametry;


public:
	//konstruktorzy
	CCharacter() { x = y = 0; };
	CCharacter(int set_x, int set_y, struct parametry set_parametry);


	//metody
	bool RysujPostac(bool undergorund = false);
	bool LoadNpcToBoard();
	virtual bool sprawdz_pola(pole PolePlanszy) = 0;
	virtual void dialog(int,int,int) = 0;
	virtual void poruszanie(int) = 0;
	int retX() const { return x; };
	int retY() const { return y; };
	string RetName() { return strName; }

	int RetParametr(string);
	void SetXY(int x, int y) { this->x = x; this->y = y; }
	int RetPrevX() { return prevX; }
	int RetPrevY() { return prevY; }
	void UsunPostacZMapy(bool isUnderground = false);
	void UsunWskaznikPostaciZMapy();
	void UsunPostacWrazZWskaznikiem(bool isUnderground = false);
	void SetNumerZdarzenia(int a) { PolePostaci.NumerZdarzenia = a; }
	int RetNumerZdarzenia() { return PolePostaci.NumerZdarzenia; }
	void SetSymbolPola(char symbol) { PolePostaci.SymbolPola = symbol; }
	void UploadPosition(int x, int y);

	virtual bool Atak(CCharacter*, int, int*) { return true; };
	

	//destruktor
	virtual ~CCharacter() { pPlansza = NULL; };
};



class CMainHero : public CCharacter
{
private:
	bool isTratwa = false;
	bool isPole = true; 
	bool isUndergorund = false;
	bool bMagicznaRoslina = false;
	bool bKlepsydra = false; //!!!!!!!!!!!!!!!!!!
	bool bKopanie = false;
	
	int MaxHP = 20;
	int LicznikDrzew = 0;

	fstream plik;
	pole ObszarWokolGracza[3][3];

	int PoziomGlodu = 500;
	int MaxPoziomGlodu = 500;

	CFabula* pFabula = NULL;
public:

	void SetpFabula(CFabula* setpFabula) { pFabula = setpFabula; }

	vector<const CItem*> Plecak;
	UzywaneItemy NoszonePrzedmioty;
	Ekwipunek Itemy;
	DodatkowyEkwipunek* RozszerzenieEq = NULL;
	CMainHero(string name, int set_x, int set_y, CPlansza* set_pPlansza);
	bool sprawdz_pola(pole PolePlanszy);
	bool konstruowanie();
	void poruszanie(int);
	bool PoruszanieTratwa(int);
	void dialog(int,int,int);
	bool Zbieranie();
	bool DrawElement();
	bool PobierzObszarWokolGracza();
	bool ObszarWokolGraczaNaPlansze(pole,pole);
	bool SzukajPola(int);
	void MenuGracza(int);
	bool SzukajLiczPole(pole, int);
	bool RetisPole() { return isPole; }
	bool RetMagRoslina() { return bMagicznaRoslina; }
	int SzukajNPC();
	CCharacter* SzukajWskaznikaNPC();
	void SetHp(int);
	void ZarzadanieEq(bool sell);
	void AktualizujPlecak();
	int WyszukajItemWPlecaku(int Number, ItemType typ);
	void SetMaxHP(int);
	void SetMaxPoziomGlodu(int);
	bool TworzenieMikstur();
	void SetIsPole() { isPole = true; }
	int RetLicznikDrzew() { return LicznikDrzew; }

	bool RetisUndergorund() { return isUndergorund; }
	void Switch_undergorund();
	void GetKlepsydra() { bKlepsydra = true; }
	void SetKopanie() { bKopanie = true; }
	bool RetKlepsydra() { return bKlepsydra; }

	bool Walka(CCharacter* );
	bool Atak(CCharacter*, int, int*);
	
	
	

	~CMainHero();
};



class CPlansza
{
public:
	const int N = 50;
	const int M = 100;
	static pole Plansza[50][100];
	static pole Podziemia[50][100];
	static pole PlanszaSpec[50][100];
	static CCharacter* PlanszaWskaznikow[50][100];

public:
	CPlansza();
	bool RysujPlansze();
	bool RysujPodziemia(int HeroX, int HeroY);
	bool RysujWizje(int HeroX, int HeroY, int zasieg, bool IsUnderground);
	bool RysujPlanszeSpec(int HeroX, int HeroY);
	
	~CPlansza() {};

	friend CDom;
};

class CNPC_w_obiekcie : public CCharacter
{
private:
	int NumerDialogu;
public:
	CNPC_w_obiekcie();
	CNPC_w_obiekcie(string name,int set_NumerDialogu, int set_x, int set_y, struct parametry set_parametry, CPlansza* set_pPlansza);

	bool sprawdz_pola(pole POLE);
	void dialog(int a, int b, int c);
	void poruszanie(int a);
	void SetNumDialogu(int Set_numDialogu);

	int RetNumDialogu() { return NumerDialogu; };
	~CNPC_w_obiekcie() { pPlansza = NULL; };
};

class CMonster : public CCharacter
{
protected:
	MonsterTYPE RodzajPotwora;
	int Experience;
	int TabIndex;
	ObszarWystepowania Terytorium;
	int ID;
public:
	//konstruktorzy
	CMonster() { x = y = 0; };
	CMonster(int set_x, int set_y, struct parametry set_parametry);


	//metody
	void OgolnyKonstruktor(int set_x, int set_y, struct parametry set_parametry, int TabIndex, ObszarWystepowania setTerytorium, CPlansza* SetpPlansza);
	bool sprawdz_pola(pole PolePlanszy) { return true; };
	void dialog(int a, int b, int c) {};
	void poruszanie(int a) {};
	int RetRodzaj() { return static_cast<int>(RodzajPotwora); }
	int RetIndex() { return TabIndex; }
	ObszarWystepowania RetTerytorium() { return Terytorium; }
	int RetID() { return ID; }
	void SetGuardian() { ID = 10; PolePostaci.SymbolPola = 15;	}

	virtual bool GiveLoot(CMainHero*) = 0; 
	virtual bool Atak(CCharacter*, int, int*);

	

	//destruktor
	virtual ~CMonster() { pPlansza = NULL; };
};



class CBear : public CMonster
{
protected:

public:
	CBear() { x = y = 0; }	 
	CBear(int set_x, int set_y, struct parametry set_parametry, int set_TabIndex, ObszarWystepowania setTerytorium, CPlansza* SetpPlansza)
	{
		OgolnyKonstruktor(set_x, set_y, set_parametry, set_TabIndex, setTerytorium, SetpPlansza);
		RodzajPotwora = BEAR;
		Experience = 250;
		ID = 2;
		strName = "Niedzwiedz";
	}
	

	bool Atak(CCharacter*, int, int*);
	bool GiveLoot(CMainHero*);
	virtual ~CBear() { pPlansza = NULL; };
};

class CWolf : public CMonster
{
protected:

public:
	CWolf() { x = y = 0; };
	CWolf(int set_x, int set_y, struct parametry set_parametry, int set_TabIndex, ObszarWystepowania setTerytorium, CPlansza* SetpPlansza)
	{
		OgolnyKonstruktor(set_x, set_y, set_parametry, set_TabIndex, setTerytorium, SetpPlansza);
		RodzajPotwora = FUR;
		Experience = 10;
		ID = 1;
		strName = "Wilk";
	}

	bool Atak(CCharacter*, int, int*);
	bool GiveLoot(CMainHero*);

	virtual ~CWolf() { pPlansza = NULL; };
};

class CVampire : public CMonster
{
protected:

public:
	CVampire() { x = y = 0; };
	CVampire(int set_x, int set_y, struct parametry set_parametry, int set_TabIndex, ObszarWystepowania setTerytorium, CPlansza* SetpPlansza)
	{
		OgolnyKonstruktor(set_x, set_y, set_parametry, set_TabIndex, setTerytorium, SetpPlansza);
		RodzajPotwora = UNDEAD;
		ID = 4;
		strName = "Hrabia Hepo Hepatis";
	}

	bool Atak(CCharacter*, int, int*);
	bool GiveLoot(CMainHero*);
	virtual ~CVampire() { pPlansza = NULL; };
};

class CUndead : public CMonster
{
protected:

public:
	CUndead() { x = y = 0; };
	CUndead(int set_x, int set_y, struct parametry set_parametry, int set_TabIndex, ObszarWystepowania setTerytorium, CPlansza* SetpPlansza)
	{
		OgolnyKonstruktor(set_x, set_y, set_parametry, set_TabIndex, setTerytorium, SetpPlansza);
		RodzajPotwora = UNDEAD;
		ID = 3;
		strName = "Sir Trup";
	}

	bool Atak(CCharacter*, int, int*);
	bool GiveLoot(CMainHero*);
	virtual ~CUndead() { pPlansza = NULL; };
};

class CBandit : public CMonster
{
protected:

public:
	CBandit() { x = y = 0; };
	CBandit(int set_x, int set_y, struct parametry set_parametry, int set_TabIndex, ObszarWystepowania setTerytorium, CPlansza* SetpPlansza)
	{
		OgolnyKonstruktor(set_x, set_y, set_parametry, set_TabIndex, setTerytorium, SetpPlansza);
		RodzajPotwora = FUR;
		Experience = 10;
		ID = 5;
		strName = "El Bandito";
	}

	bool Atak(CCharacter*, int, int*);
	bool GiveLoot(CMainHero*);

	virtual ~CBandit() { pPlansza = NULL; };
};

class CVectarian : public CMonster
{
protected:

public:
	CVectarian() { x = y = 0; };
	CVectarian(int set_x, int set_y, struct parametry set_parametry, int set_TabIndex, ObszarWystepowania setTerytorium, CPlansza* SetpPlansza)
	{
		OgolnyKonstruktor(set_x, set_y, set_parametry, set_TabIndex, setTerytorium, SetpPlansza);
		RodzajPotwora = NORMAL;
		Experience = 500;
		ID = 6;
		strName = "Vectarian";
		PolePostaci.SymbolPola = 15;
	}

	bool Atak(CCharacter*, int, int*);
	bool GiveLoot(CMainHero*);

	virtual ~CVectarian() { pPlansza = NULL; };
};

class CClockMaster : public CMonster
{
protected:

public:
	CClockMaster() { x = y = 0; };
	CClockMaster(int set_x, int set_y, struct parametry set_parametry, int set_TabIndex, ObszarWystepowania setTerytorium, CPlansza* SetpPlansza)
	{
		OgolnyKonstruktor(set_x, set_y, set_parametry, set_TabIndex, setTerytorium, SetpPlansza);
		RodzajPotwora = NORMAL;
		Experience = 400;
		ID = 7;
		strName = "Zegar Mistrz";
		//PolePostaci.SymbolPola = 15;
	}

	bool Atak(CCharacter*, int, int*);
	bool GiveLoot(CMainHero*);

	virtual ~CClockMaster() { pPlansza = NULL; };
};

class CDrzewacz : public CMonster
{
protected:

public:
	CDrzewacz() { x = y = 0; };
	CDrzewacz(int set_x, int set_y, struct parametry set_parametry, int set_TabIndex, ObszarWystepowania setTerytorium, CPlansza* SetpPlansza)
	{
		OgolnyKonstruktor(set_x, set_y, set_parametry, set_TabIndex, setTerytorium, SetpPlansza);
		RodzajPotwora = NORMAL;
		Experience = 600;
		ID = 8;
		strName = "Piastun Knieji";
		PolePostaci.SymbolPola = 'Y';
	}

	bool Atak(CCharacter*, int, int*);
	bool GiveLoot(CMainHero*);

	virtual ~CDrzewacz() { pPlansza = NULL; };
};


class CNPC : public CCharacter
{
private:	
public:
	CNPC();
	CNPC(string name, char znak, int Numer , int set_x, int set_y, struct parametry set_parametry, CPlansza* pPlansza);

	bool sprawdz_pola(pole POLE);	
	void dialog(int a, int b, int c);	
	void poruszanie(int a);
	

	~CNPC() { pPlansza = NULL; };

};

class CObiekt
{
public:
	int x, y;
	int NumerZdarzenia;
	CPlansza* pPlansza;
public:
	CObiekt(); 
	CObiekt(int set_x, int set_y, CPlansza* set_pPlansza);
	virtual bool RysujObiekt() = 0;
	virtual ~CObiekt() { pPlansza = NULL; };


};

class CDom : public CObiekt
{
public:
	CDom();
	CDom(int set_x, int set_y, int set_NumZda, CPlansza* set_pPlansza);
	bool RysujObiekt();
	bool RysujObiektHistoriaAsgaru();
	~CDom() { pPlansza = NULL; };
};

class CZamek : public CObiekt
{
public:
	bool RysujObiekt();
	CZamek() { x = y = NumerZdarzenia = 0; };
	CZamek(int set_x, int set_y, int set_NumZda, CPlansza* set_pPlansza);

	~CZamek() { pPlansza = NULL; };
};

class CPole : public CObiekt
{
public:
	bool RysujObiekt();
	CPole() { x = y = NumerZdarzenia = 0; };
	CPole(int set_x, int set_y, int set_NumZda, CPlansza* set_pPlansza);

	~CPole() { pPlansza = NULL; };
};

class CGilgamesh
{
private:
	CDom Tablica_Domow[10];
	CPole Tablica_Pol[8];
	CPlansza* pPlansza;
public:
	//Metody 
	bool RysujObiekty();
	bool RysujMur();
	bool RysujLas();
	bool RysujWiezienie(int,int);
	bool RysujRzeke();
	bool RysujCmentarz();
	bool RysujPodziemia();
	bool RysujWiezeMaga();
	bool RysujPolaPrzejsc();
	bool RysujPolaPrzedmiotow();
	bool RysujDrzwi();

	//KONSTRUKTOR
	CGilgamesh();
	CGilgamesh(CPlansza* set_pPlansza);

	//DESTRUKTOR
	~CGilgamesh();


};

struct CFabulaPola
{
	pole PolePlanszy;
	int x, y;
	CFabulaPola(pole Pole ,int x, int y) : PolePlanszy(Pole), x(x), y(y)
	{};
};

class CFabula
{
private:
	vector<const CItem*> FabulaPlecak;
	Ekwipunek FabulaItemy;
	DodatkowyEkwipunek* FabulaRozszerzenieEq = NULL;
	unsigned int FabulaExp;

	time_t GildiaZlodziejiSTART;
	int StanTropienia = 0;
	bool DrzwiWiezyMaga = true;
	bool DrzwiAria = true;
	bool DrzwiPulapka = true;
	bool ZlotyPosag = true;
	bool bDolTeodora = false;
	bool bNostalgia = false;
	
	
	
	vector<CFabulaPola> PolaFabularne;
	

	CMainHero* pHero;
	CPlansza* pPlansza;
	StosDialogow* Odpowiedzi;
	StosDialogow* Oddzywki;

	CNPC* pKolesZaRzeka = NULL;
	CNPC* pFarmer = NULL;
	CNPC* pWiezniarz = NULL;
	CNPC* pStraznikMiasta1 = NULL;
	CNPC* pStraznikMiasta2 = NULL;
	CNPC* pStraznikZiuta1 = NULL;
	CNPC* pStraznikZiuta2 = NULL;
	CNPC* pZiutmelson = NULL;
	CNPC* pZlodziejSzef = NULL;
	CNPC* pZlodziej1 = NULL;
	CNPC* pZlodziej2 = NULL;
	CNPC* pTeodor = NULL;
	CNPC* pGrabarz = NULL;
	CNPC* pTajemniczyMezczyzna = NULL;
	CNPC* pWiezien = NULL;
	CNPC* pKsiezniczka = NULL;

	CNPC_w_obiekcie* pSzefStrazy = NULL;
	CNPC_w_obiekcie* pPrzydupasSzefaStrazy = NULL;
	CNPC_w_obiekcie* pZonaTeodora = NULL;
	CNPC_w_obiekcie* pTeodorPoOdnalezieniu = NULL;
	CNPC_w_obiekcie* pMlynarz = NULL;
	CNPC_w_obiekcie* pPiec = NULL;
	CNPC_w_obiekcie* pKarczmarz = NULL;
	CNPC_w_obiekcie* pGosc1 = NULL;
	CNPC_w_obiekcie* pGosc2 = NULL;
	CNPC_w_obiekcie* pKupiec = NULL;
	CNPC_w_obiekcie* pStajenny = NULL;
	

	CNPC_w_obiekcie* pWskazowka = NULL;


	static const int AmountOfBear = 4;
	static const int AmountOfWolf = 10;
	static const int AmountOfUndead = 5;
	static const int AmountOfVampire = 1;
	static const int AmountOfBandits = 5;
	static const int AmountOfGuardian = 3;
	static const int AmountOfGuards = 28;

	CCharacter* TabBear[AmountOfBear];
	CCharacter* TabWolf[AmountOfWolf];
	CCharacter* TabBandits[AmountOfBandits];
	CCharacter* TabUndead[AmountOfUndead];
	CCharacter* TabGuardian[AmountOfGuardian];
	CCharacter* TabGuards[AmountOfGuards];

	// BOSS
	CCharacter* pVectarian = NULL;
	CCharacter* pClockMaster = NULL;
	CCharacter* pVampire = NULL;
	CCharacter* pDrzewacz = NULL;

	int Quest;

	bool Akt1 = true;
	bool bWyjscieZPol = false;
	bool bBrakMostu = false;
	bool bKolesZaRzeka = false;
	bool Wytrych = false; //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	bool bDostepDoMiasta = false; //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	bool bDostepDoZiutka = false;
	bool bSzacunekStraznika = false;
	bool bSzacunekFarmera = false;
	bool bSzacunekWiezniarza = false;
	bool bPrzejscieNaPolach = false; //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	bool bGildiaZlodzieji = false;
	bool bKlepsydra = false;
	bool bOtwieranieDrzwiLina = false;
	bool bFinalQuest = false;
	bool bKsiazkaWilka = false;
	bool bTeodorPodziemia = false;

	int StanSzacunekFarmera = 0;
	int StanSzacunekStraznika = 0; 
	int StanSzacunekWiezniarza = 0;
	int StanOpowiescTeodora = 0;
	int StanZemstaTeodora = 0;
	int StanWdziecznoscTeodora = 0;
	int StanGildiaZlodzieji = 0; 
	int StanOddaniePierscienia = 0;
	int StanKlepsydra = 0; //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	int StanFinalQuest = 0; //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	
	static const int AmountOfItems = 10;

public:

	OpisFragmentu FragmentOpis[Fragment[1].MaxNumber];
	bool TabPrzedmioty[AmountOfItems];

	bool LoadNpcToBoard(int, int);

	void WyjscieZPol();
	void BrakMostu();
	void KolesZaRzeka();
	void DostepDoMiasta();
	void SzacunekFarmera();
	void SzacunekStraznika();
	void Klepsydra();
	void GildiaZlodzieji();
	void OdzyskajEq();
	bool SprPoprawnoscArii();
	void OtwieranieDrzwiLina();
	void ReturnOfTheKing();
	void DrzewusCreatio();
	void MarszDrzew();
	void FinalQuest();
	void HistoriaAsgaru();
	void TeodorPodziemia();

	void PrzejscieNaPolach();

	bool Walka(CCharacter* );
	//bool WalkaMonster(CCharacter* );



	void DialogNPCwDomu(int x, int y, CNPC_w_obiekcie* pointer);
	void SprFabula();
	void SprDialogNPCwDomu();
	void Dialog(int,string, CCharacter*);
	void AkcjaWynikajacaZDiagolu(int, CCharacter*);
	void SprMonsters();
	void GenerateXY(int MaxX, int MinX, int MaxY, int MinY, int* X, int* Y);
	bool DeleteMonster(int index, int TYP);
	bool CzyJestWTymObszarze(int x, int y, int ObszarX, int ObszarY, int width, int heigth);

	CFabula();
	CFabula::CFabula(CMainHero* SetpHero, CPlansza* SetpPlansza);
	~CFabula();

	friend CMainHero;

};


struct CNpcSpec
{
	int x, y, sX, sY;
	pole PolePostaci;
	CPlansza* pPlansza;
	CNpcSpec(int x, int y, CPlansza* setPPlansza, char znak)
	{
		sX = x;
		sY = y;
		PolePostaci.NumerZdarzenia = 1;
		PolePostaci.SymbolPola = znak;
		this->x = x;
		this->y = y;
		pPlansza = setPPlansza;
		pPlansza->PlanszaSpec[x][y] = PolePostaci;

	}
	CNpcSpec() {};
	void Ruch(int x, int y);
	void SetStartCoords(int x, int y) { sX = x; sY = y; }
	void SetStartCoords() { sX = x; sY = y; }
};