#include "Header.h"
pole CPlansza::Plansza[50][100];
pole CPlansza::Podziemia[50][100];
pole CPlansza::PlanszaSpec[50][100];
CCharacter* CPlansza::PlanszaWskaznikow[50][100];
bool koniec = false; // !!!!!!!!!!!!!!!!!!!!!!!!!!!!

using namespace std;

bool pole::operator==(pole POLE)
{
	if (NumerZdarzenia == POLE.NumerZdarzenia && SymbolPola == POLE.SymbolPola)
		return true;

	return false;
}

CCharacter::CCharacter(int set_x, int set_y, struct parametry set_parametry)
{
	x = set_x;
	y = set_y;
	parametry = set_parametry;
}
int CCharacter::RetParametr(string ParametrDoZwrotu)
{
	if (ParametrDoZwrotu == "hp")
		return parametry.hp;
	if (ParametrDoZwrotu == "sila")
		return parametry.sila;
	if (ParametrDoZwrotu == "moc")
		return parametry.moc;
	if (ParametrDoZwrotu == "obrona")
		return parametry.obrona;

	return -1;
}
void CCharacter::UsunPostacZMapy(bool isUndergorund)
{
	if(isUndergorund)
		pPlansza->Podziemia[x][y] = puste_pole;
	else
		pPlansza->Plansza[x][y] = puste_pole;
}
void CCharacter::UsunWskaznikPostaciZMapy()
{
	pPlansza->PlanszaWskaznikow[x][y] = NULL;
}
void CCharacter::UsunPostacWrazZWskaznikiem(bool isUnderground)
{
	if (isUnderground)
		UsunPostacZMapy(true);
	else	
		UsunPostacZMapy();
	
	UsunWskaznikPostaciZMapy();
}

CObiekt::CObiekt()
{
	pPlansza = NULL;
	x = y = 0;
}
CObiekt::CObiekt(int set_x, int set_y, CPlansza* set_pPlansza)
{
	pPlansza = set_pPlansza;
	x = set_x;
	y = set_y;
}
CNPC_w_obiekcie::CNPC_w_obiekcie()
{
	x = y = 0;
	PolePostaci = puste_pole;
	strName = "NPC w obiekcie";
	parametry = {0,0,0,0};

}
void CNPC_w_obiekcie::poruszanie(int a)
{
	cout << a << endl;
}
void CNPC_w_obiekcie::SetNumDialogu(int Set_numDialogu)
{
	NumerDialogu = Set_numDialogu;
}
bool CNPC_w_obiekcie::sprawdz_pola(pole POLE)
{
	return true;
}
void CNPC_w_obiekcie::dialog(int a, int b, int c)
{
	cout << "Hejo" << endl;
}
CNPC_w_obiekcie::CNPC_w_obiekcie(string name, int set_NumDialogu, int set_x, int set_y, struct parametry set_parametry, CPlansza* set_pPlansza)
{
	strName = name;
	PolePostaci.SymbolPola = ' ';
	PolePostaci.NumerZdarzenia = 2;
	NumerDialogu = set_NumDialogu;
	x = set_x;
	y = set_y;
	parametry = set_parametry;

}
CMainHero::CMainHero(string name, int set_x, int set_y, CPlansza* set_pPlansza)
{
	pPlansza = set_pPlansza;
	strName = name;
	PolePostaci.SymbolPola = 'X';
	PolePostaci.NumerZdarzenia = 10;
	x = set_x;
	y = set_y;
	parametry = { 30,0,20,0 };
	Itemy = {false,false,false,false,Brak,Brak,100,100,0,0,0,5,5}; //!!!!!!!!!!!!!!!!! zloto jest 100 i exp
	
	RozszerzenieEq = pushEq(RozszerzenieEq, 1, "Bochenek chleba");
	RozszerzenieEq = pushEq(RozszerzenieEq, 2, "Maka");
	RozszerzenieEq = pushEq(RozszerzenieEq, 3, "Ciasto");
	RozszerzenieEq = pushEq(RozszerzenieEq, 4, "Wlokno"); // w³ókno
	RozszerzenieEq = pushEq(RozszerzenieEq, 5, "Lina"); // lina
	RozszerzenieEq = pushEq(RozszerzenieEq, 6, "Skora wilka"); // skora wilka
	RozszerzenieEq = pushEq(RozszerzenieEq, 7, "Mieso"); // mieso
	RozszerzenieEq = pushEq(RozszerzenieEq, 8, "Pieczone mieso"); // pieczone mieso
	RozszerzenieEq = pushEq(RozszerzenieEq, 9, "Kanapka z szynka"); // kanapka
	RozszerzenieEq = pushEq(RozszerzenieEq, 10, "Mikstura lecznicza");
	RozszerzenieEq = pushEq(RozszerzenieEq, 11, "Plynny ogien");
	RozszerzenieEq = pushEq(RozszerzenieEq, 12, "Biala woda"); 
	RozszerzenieEq = pushEq(RozszerzenieEq, 13, "Trucizna");
	RozszerzenieEq = pushEq(RozszerzenieEq, 14, "Kunai");
	RozszerzenieEq = pushEq(RozszerzenieEq, 15, "Skora niedzwiedzia");
	RozszerzenieEq = pushEq(RozszerzenieEq, 16, "Garbowana skora");
	RozszerzenieEq = pushEq(RozszerzenieEq, 17, "Zmutowane serce");
	RozszerzenieEq = pushEq(RozszerzenieEq, 18, "Sztabka zelaza");
	RozszerzenieEq = pushEq(RozszerzenieEq, 19, "Serce ZegarMistrza");
	RozszerzenieEq = pushEq(RozszerzenieEq, 20, "Fragment chochola");
	RozszerzenieEq = pushEq(RozszerzenieEq, 21, "Chochol");
	RozszerzenieEq = pushEq(RozszerzenieEq, 22, "Zywe drewno");
	RozszerzenieEq = pushEq(RozszerzenieEq, 23, "Kamien glupcow");
	Plecak.clear();
	/*
	//testy -------------------------------
	WyszukajPrzedmiot(RozszerzenieEq, 5)->DodajPrzedmiot();	
	WyszukajPrzedmiot(RozszerzenieEq, 1)->DodajPrzedmiot();
	WyszukajPrzedmiot(RozszerzenieEq, 9)->DodajPrzedmiot();
	WyszukajPrzedmiot(RozszerzenieEq, 9)->DodajPrzedmiot();
	WyszukajPrzedmiot(RozszerzenieEq, 9)->DodajPrzedmiot();
	WyszukajPrzedmiot(RozszerzenieEq, 9)->DodajPrzedmiot();

	Plecak.push_back(&AntiBearSword);
	Plecak.push_back(&Excalibur);

	
	Itemy.tratwa = true;
	for(int i = 0; i < 6; i++)
		WyszukajPrzedmiot(RozszerzenieEq, 6)->DodajPrzedmiot();
	for (int i = 0; i < Fragment[1].MaxNumber; i++)		
		Plecak.push_back(&Fragment[i]);
	*/

	
	

}
CNPC::CNPC(string name, char znak, int Numer, int set_x, int set_y, struct parametry set_parametry, CPlansza* SetpPlansza)
{
	pPlansza = SetpPlansza;
	strName = name;
	PolePostaci.SymbolPola = znak;
	PolePostaci.NumerZdarzenia = Numer;
	x = set_x;
	y = set_y;
	parametry = set_parametry;

}

CNPC::CNPC()
{
	x = y = 0;
	PolePostaci = puste_pole;
	strName = "NPC";
	parametry = { 0,0,0,0 };
}
bool CNPC::sprawdz_pola(pole POLE)
{
	return true;
}
void CNPC::dialog(int a, int b, int c)
{
	cout << "HEJ" << endl;

}
void CNPC::poruszanie(int a)
{
	cout << "Ide przed siebie" << endl;

}

bool CMainHero::DrawElement()
{
	
	pPlansza->Podziemia[x][y] = sufit;
	plik.open("Funkcja_trumna.txt", ios::out | ios::app);
	if (plik.good() == false)
		return false;
	
	plik << "pPlansza->Podziemia[" << retX() << "][" << retY() << "] = sufit;" << endl;
	
	
	plik.close();
	x = prevX;
	y = prevY;
	return true;
}

CMainHero::~CMainHero()
{
	UsunEq(RozszerzenieEq);
	pPlansza = NULL;
	Plecak.clear();
}
void CMainHero::dialog(int NumerPostaci, int oddzywkaNPC, int odpowiedz)
{
	cout << "Hej " << endl;
}
CPlansza::CPlansza()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			Plansza[i][j] = puste_pole;
			Podziemia[i][j] = puste_pole;
			PlanszaSpec[i][j] = puste_pole;
		}
	for (int i = 0; i < M; i++)
	{
		Plansza[0][i] = podloga;
		Podziemia[0][i] = podloga;
		PlanszaSpec[0][i] = podloga;
	}
	for (int i = 0; i < M; i++)
	{
		Plansza[49][i] = podloga;
		Podziemia[49][i] = podloga;
		PlanszaSpec[49][i] = podloga;

	}
	for (int i = 0; i < N; i++)
	{
		Plansza[i][0] = sciana;
		Podziemia[i][0] = sciana;
		PlanszaSpec[i][0] = sciana;
	}
	for (int i = 0; i < N; i++)
	{
		Plansza[i][99] = sciana;
		Podziemia[i][99] = sciana;
		PlanszaSpec[i][99] = sciana;
	}

	

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			PlanszaWskaznikow[i][j] = NULL;
}

bool CPlansza::RysujPlansze()
{
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << Plansza[i][j].SymbolPola;
		}

		cout << endl;
	}



	return true;
}

bool CPlansza::RysujPodziemia(int HeroX, int HeroY)
{
	int WidzianyObszar = 10;

	int StartX = HeroX - WidzianyObszar;
	if (StartX < 0) StartX = 0;
	int StartY = HeroY - WidzianyObszar;
	if (StartY < 0) StartY = 0;

	int EndX = StartX + 2*WidzianyObszar+1;
	if (EndX > N-1) EndX = N - 1;
	int EndY = StartY + 2 * WidzianyObszar + 1;
	if (EndY > M-1) EndY = M - 1;

	for (int i = StartX; i < EndX; i++)
	{
		for (int j = StartY; j < EndY; j++)
		{
			cout << Podziemia[i][j].SymbolPola;
		}

		cout << endl;
	}





	return true;
}

bool CPlansza::RysujWizje(int HeroX, int HeroY, int zasieg, bool IsUnderground)
{
	int WidzianyObszar = zasieg;

	int StartX = HeroX - WidzianyObszar;
	if (StartX < 0) StartX = 0;
	int StartY = HeroY - WidzianyObszar;
	if (StartY < 0) StartY = 0;

	int EndX = StartX + 2 * WidzianyObszar + 1;
	if (EndX > N - 1) EndX = N - 1;
	int EndY = StartY + 2 * WidzianyObszar + 1;
	if (EndY > M - 1) EndY = M - 1;


	if(IsUnderground)
	for (int i = StartX; i < EndX; i++)
	{
		for (int j = StartY; j < EndY; j++)
		{
			cout << Podziemia[i][j].SymbolPola;
		}

		cout << endl;
	}
	if (IsUnderground == false)
		for (int i = StartX; i < EndX; i++)
		{
			for (int j = StartY; j < EndY; j++)
			{
				cout << Plansza[i][j].SymbolPola;
			}

			cout << endl;
		}




	return true;
}

bool CPlansza::RysujPlanszeSpec(int HeroX, int HeroY) 
{
	int WidzianyObszar = 15;

	int StartX = HeroX - WidzianyObszar;
	if (StartX < 0) StartX = 0;
	int StartY = HeroY - WidzianyObszar;
	if (StartY < 0) StartY = 0;

	int EndX = StartX + 2 * WidzianyObszar + 1;
	if (EndX > N - 1) EndX = N - 1;
	int EndY = StartY + 2 * WidzianyObszar + 1;
	if (EndY > M - 1) EndY = M - 1;


	
		for (int i = StartX; i < EndX; i++)
		{
			for (int j = StartY; j < EndY; j++)
			{
				cout << PlanszaSpec[i][j].SymbolPola;
			}

			cout << endl;
		}
	



		return true;

}

bool CCharacter::RysujPostac(bool undergorund)
{
	if (pPlansza == NULL)
		return false;
	if(undergorund == false)
		pPlansza->Plansza[x][y] = PolePostaci;

	if(undergorund)
		pPlansza->Podziemia[x][y] = PolePostaci;

	LoadNpcToBoard();
	return true;
}


CMonster::CMonster(int set_x, int set_y, struct parametry set_parametry)
{
	x = set_x;
	y = set_y;
	parametry = set_parametry;
}
void CMonster::OgolnyKonstruktor(int set_x, int set_y, struct parametry set_parametry, int set_TabIndex, ObszarWystepowania setTerytorium, CPlansza* SetpPlansza)
{
	x = set_x;
	y = set_y;
	parametry = set_parametry;
	TabIndex = set_TabIndex;
	Terytorium = setTerytorium;
	pPlansza = SetpPlansza;

	int numer = 10000;
	numer += x * 100;
	numer += y;
	PolePostaci.NumerZdarzenia = numer;
	PolePostaci.SymbolPola = ' ';

}
bool CMonster::Atak(CCharacter* Enemy, int RodzajBroni, int* HeroHP)
{

	return true;
}


bool CWolf::Atak(CCharacter* Enemy, int RodzajBroni, int* HeroHP)
{

	if (RodzajBroni == 1) // noz na wilki
	{
		if ((rand() % 100) <= 10)
		{
			parametry.hp = 0;
			cout << "                                 Wilk skoczyl. Udalo mu sie powalic przeciwnika.. jednakze to bylo sotatnie co zrobil.. noz gleboko zatopil sie w jego sercu" << endl;
			return false;
		} // if false == trup
	}

	int enemy_hp = *HeroHP;
	int str = (50 - Enemy->RetParametr("sila")) + parametry.sila;
	int def = Enemy->RetParametr("obrona");
	int dmg = parametry.sila / 10;
	int lose_hp = 0;
	int power = parametry.moc;
	bool combo = false;





	//cout << "                                 " << strName << " hp: " << parametry.hp << endl << endl;
	//cout << "                                 Enemy hp: " << enemy_hp << endl << "                                 str " << str << endl << "                                 def " << def << endl << "                                 dmg " << dmg << endl << "                                 power " << power << endl;
	int szansa = (rand() % 100 + 1);
	cout << "                                 Szansa == " << szansa << endl;
	if (szansa <= str)
	{
		if ((rand() % 100 + 1) <= power) combo = true;
		do
		{
			lose_hp = (rand() % dmg) - def + 1;
			if (lose_hp < 0) lose_hp = 0;
			enemy_hp -= lose_hp;
			cout << "                                 " << strName << " uderza  za " << lose_hp << endl << endl;
			Beep(800, 500);
			Sleep(1000);
		} while (combo == true && !(combo = false));
	}
	else
	{
		cout << "                                 Przeciwnik uskoczyl..." << endl;
		Sleep(1000);
	}


	*HeroHP = enemy_hp;

	if (enemy_hp <= 0)
		return false;




	return true;




}

bool CWolf::GiveLoot(CMainHero* pHero)
{
	pHero->Itemy.exp += Experience;
	WyszukajPrzedmiot(pHero->RozszerzenieEq, 6)->DodajPrzedmiot();
	WyszukajPrzedmiot(pHero->RozszerzenieEq, 7)->DodajPrzedmiot();
	cout << endl << endl << "LOOT" << endl << "---------------------------------------" << endl << "Otrzymujesz " << Experience << " punktow doswiadczenia" 
		 << endl << "Otrzymujesz skore wilka" << endl << "Otrzymujesz kawalek surowego miesa" << endl;

	_getch();
	return true;
}


bool CBear::Atak(CCharacter* Enemy, int RodzajBroni, int* HeroHP)
{

	if (RodzajBroni == 1) // noz na wilki
	{
		if ((rand() % 100) <= 10)
			return false; // if false == trup
	}

	int enemy_hp = *HeroHP;
	int str = (50 - Enemy->RetParametr("sila")) + parametry.sila;
	int def = Enemy->RetParametr("obrona");
	int dmg = parametry.sila;
	int lose_hp = 0;
	int power = parametry.moc;
	bool combo = false;

	



	//cout << "                                 " << strName << " hp: " << parametry.hp << endl << endl;
	//cout << "                                 Enemy hp: " << enemy_hp << endl << "                                 str " << str << endl << "                                 def " << def << endl << "                                 dmg " << dmg << endl << "                                 power " << power << endl;
	int szansa = (rand() % 100 + 1);
	cout << "                                 Szansa == " << szansa << endl;
	if (szansa <= str)
	{
		if ((rand() % 100 + 1) <= power) combo = true;
		do
		{
			lose_hp = (rand() % dmg) - def + 1;
			if (lose_hp < 0) lose_hp = 0;
			enemy_hp -= lose_hp;
			cout << "                                 " << strName << " uderza  za " << lose_hp << endl << endl;
			Beep(800, 500);
			Sleep(1000);
		} while (combo == true && !(combo = false));
	}
	else
	{
		cout << "                                 Przeciwnik uskoczyl..." << endl;
		Sleep(1000);
	}


	*HeroHP = enemy_hp;

	if (enemy_hp <= 0)
		return false;


	

	return true;



}

bool CBear::GiveLoot(CMainHero* pHero)
{	
		pHero->Itemy.exp += Experience;
		WyszukajPrzedmiot(pHero->RozszerzenieEq, 15)->DodajPrzedmiot();
		WyszukajPrzedmiot(pHero->RozszerzenieEq, 7)->DodajPrzedmiot();
		WyszukajPrzedmiot(pHero->RozszerzenieEq, 7)->DodajPrzedmiot();
		cout << endl << endl << "LOOT" << endl << "---------------------------------------" << endl << "Otrzymujesz " << Experience << " punktow doswiadczenia"
			<< endl << "Otrzymujesz skore niedzwieda" << endl << "Otrzymujesz 2x kawalek surowego miesa" << endl;
		_getch();
		return true;
		
}

bool CUndead::GiveLoot(CMainHero* pHero)
{
	return true;
}

bool CUndead::Atak(CCharacter* Enemy, int RodzajBroni, int* HeroHp)
{
	return true;
}

bool CVectarian::Atak(CCharacter* Enemy, int RodzajBroni, int* HeroHP)
{

	return true;
}

bool CVectarian::GiveLoot(CMainHero* pHero)
{
	pHero->Itemy.exp += Experience;
	pHero->GetKlepsydra();
	cout << endl << endl << "LOOT" << endl << "---------------------------------------" << endl << "Otrzymujesz " << Experience << " punktow doswiadczenia"
		<< endl << "Otrzymujesz kelpsydre" << "Otrzymujesz dziennik" << endl;

	return true;
}

bool CClockMaster::Atak(CCharacter* Enemy, int RodzajBroni, int* HeroH)
{
	return true;
}
bool CClockMaster::GiveLoot(CMainHero* pHero)
{
	pHero->Itemy.exp += Experience;
	WyszukajPrzedmiot(pHero->RozszerzenieEq, 19)->DodajPrzedmiot();
	cout << endl << endl << "LOOT" << endl << "---------------------------------------" << endl << "Otrzymujesz " << Experience << " punktow doswiadczenia"
	<< endl << "Otrzymujesz serce zegarmistrza" << endl;
	return true;
}

bool CDrzewacz::Atak(CCharacter* Enemy, int RodzajBroni, int* HeroH)
{
	return true;
}

bool CDrzewacz::GiveLoot(CMainHero* pHero)
{
	pHero->Itemy.exp += Experience;
	WyszukajPrzedmiot(pHero->RozszerzenieEq, 22)->DodajPrzedmiot();
	cout << endl << endl << "LOOT" << endl << "---------------------------------------" << endl << "Otrzymujesz " << Experience << " punktow doswiadczenia"
		<< endl << "Otrzymujesz zyjace drewno" << endl;
	_getch();
	return true;

}


bool CMainHero::Atak(CCharacter* Enemy, int RodzajPotwora, int* MonsterHp)
{

	int enemy_hp = *MonsterHp;
	int str = (50 - Enemy->RetParametr("sila")) + parametry.sila;
	int def = Enemy->RetParametr("obrona");
	int dmg = NoszonePrzedmioty.Sword->DMG;
	int lose_hp = 0;
	int power = parametry.moc;
	bool combo = false;

	int BonusDMG_weapon = 0;
	int BonusDMG_item = 0;

	if (RodzajPotwora == 1 ) // || bron to noz na wilki
		BonusDMG_weapon = 1;
	if (NoszonePrzedmioty.UseableItem == &MiksturaTrucizna)
		BonusDMG_item = 2;

	if (NoszonePrzedmioty.UseableItem == &MiksturaOgnia )
		if(static_cast<CMonster*>(Enemy)->RetRodzaj() == FUR || static_cast<CMonster*>(Enemy)->RetRodzaj() == BEAR)
			BonusDMG_item = 3;
		else BonusDMG_item = 1;

	if (NoszonePrzedmioty.UseableItem == &MiksturaAntiUndead)
		if (static_cast<CMonster*>(Enemy)->RetRodzaj() == UNDEAD )
			BonusDMG_item = 3;


	

	//cout << strName << " hp: " << parametry.hp << endl << endl;
	//cout << "Enemy hp: " << enemy_hp << endl << "str " << str << endl << "def " << def << endl << "dmg " << dmg << endl << "power " << power << endl;
	
	int szansa = (rand() % 100 + 1);
	cout << "Szansa == " << szansa << endl;
	if (szansa <= str)	
	{
		if ((rand() % 100 + 1) <= power) combo = true;
		do
		{
			lose_hp = (rand() % dmg) - def + BonusDMG_weapon + 1;
			if (lose_hp < 0) lose_hp = 0;
			enemy_hp -= lose_hp;
			cout << strName << " uderza  za " << lose_hp << endl << endl;
			Beep(800, 500);
			Sleep(1000);
		} while (combo == true && !(combo = false));
	}
	else
	{
		cout << "Przeciwnik uskoczyl..." << endl;
		Sleep(1000);
	}
	enemy_hp -= BonusDMG_item;
	if (NoszonePrzedmioty.UseableItem == &MiksturaTrucizna)
		cout << "Trucizna zadaje " << BonusDMG_item << " punktow obrazen" << endl;
	if (NoszonePrzedmioty.UseableItem == &MiksturaOgnia)
		cout << "Plomienie zadaja " << BonusDMG_item << " punktow obrazen" << endl;
	if (NoszonePrzedmioty.UseableItem == &MiksturaAntiUndead)
		cout << "Plomienie zadaja " << BonusDMG_item << " punktow obrazen" << endl;



	if (enemy_hp <= 0)
		return false; // winner


		*MonsterHp = enemy_hp;

	return true;


}

bool CMainHero::Walka(CCharacter* Enemy)
{
	if (Enemy == NULL)
	{
		cout << "PUSTY WSKAZNIK" << endl;
		return false;
	}
	if (NoszonePrzedmioty.Sword == NULL)
	{
		cout << endl << endl << "Dzielnie stawiales opor.. ale Twoje umiejetnosci walki w recz nie robily wrazenia na porzerajacej Cie bestii" << endl;
		_getch();
		koniec = true;
		return false;
	}
	//cout << endl << "Numer zdarzneia dla x= "<< Enemy->retX() << " y= "<<Enemy->retY()<<" to   " << Enemy->RetNumerZdarzenia() << endl;
	//_getch();

	int HeroHP = parametry.hp;
	int MonsterHP = Enemy->RetParametr("hp");

	int Rodzaj_potwora = dynamic_cast<CMonster*>(Enemy)->RetRodzaj();

	if (NoszonePrzedmioty.UseableItem == &NozDoRzucania)
	{
		int KunaiDMG = rand() % 3 + 5;
		cout << "Szbyki rzut nozem zaskoczyl przeciwnika zadajac mu " << KunaiDMG << " obrazen " << endl;
		Beep(800, 500);
		Sleep(500);
		MonsterHP -= KunaiDMG;
	}

	if (NoszonePrzedmioty.Sword->Rodzaj == 5) // bow
		if (NoszonePrzedmioty.UseableItem->Rodzaj == 1 || NoszonePrzedmioty.UseableItem->Rodzaj == 2)
		{
			int BowDMG = 0;
			cout << "Duzy dystans zapewnia Ci mozliwosc szybkiej salwy " << endl;
			for (int i = 0; i < 3; i++)
			{
				BowDMG = (NoszonePrzedmioty.UseableItem->Rodzaj == 1 ? rand() % 4 + 7 : rand() % 6 + 10);
				cout << "Sztrzala trafia przeciwnika zadajac " << BowDMG << endl;
				MonsterHP -= BowDMG;
				Beep(800, 500);
				Sleep(500);
			}

			
		}



	if (MonsterHP <= 0)
		return true;

	cout << endl << endl;
	while (1)
	{
		cout << strName << " hp: " << HeroHP << endl << endl;
		if (!Atak(Enemy, Rodzaj_potwora, &MonsterHP)) break;
		cout << "                                 " << Enemy->RetName() << " hp: " << MonsterHP << endl << endl;
		if (!Enemy->Atak(this, NoszonePrzedmioty.Sword->Rodzaj , &HeroHP)) break;

		
		if(NoszonePrzedmioty.UseableItem == &MiksturaLecznicza)
		{
		int HealedHP = rand() % 3 + 1;
		cout << "Dzieki eliksirowi odzyskujesz " << HealedHP << endl << endl;
		 HeroHP += HealedHP;
		}
		
		
		
	}

	if (NoszonePrzedmioty.UseableItem != NULL)
	{
		WyszukajPrzedmiot(RozszerzenieEq, NoszonePrzedmioty.UseableItem->Rodzaj)->UsunPrzedmiot();
		if (WyszukajPrzedmiot(RozszerzenieEq, NoszonePrzedmioty.UseableItem->Rodzaj)->CzyJest == false)
			NoszonePrzedmioty.UseableItem = NULL;
	}
	_getch();

	if (HeroHP > 0)
	{
		parametry.hp = HeroHP;
		return true;
	}


	return false; // Hero has been slain
}

CDom::CDom()
{
	x = y = 0;
}
CDom::CDom(int set_x, int set_y, int set_NumZda, CPlansza* set_pPlansza)
{
	x = set_x;
	y = set_y;
	NumerZdarzenia = set_NumZda;
	pPlansza = set_pPlansza;
}

bool CDom::RysujObiekt()
{
	
		CPlansza::Plansza[x][y] = sciana;
		CPlansza::Plansza[x - 1][y] = sciana;

		CPlansza::Plansza[x - 1][y + 3] = sciana;
		CPlansza::Plansza[x][y + 3] = sciana;

		CPlansza::Plansza[x - 2][y + 1] = podloga;
		CPlansza::Plansza[x - 2][y + 2] = podloga;

		CPlansza::Plansza[x - 2][y] = dach_lewa_strona;
		CPlansza::Plansza[x - 3][y + 1] = dach_lewa_strona;

		CPlansza::Plansza[x - 3][y + 2] = dach_prawa_strona;
		CPlansza::Plansza[x - 2][y + 3] = dach_prawa_strona;
	

	return true;
}

bool CDom::RysujObiektHistoriaAsgaru()
{

	CPlansza::PlanszaSpec[x][y] = sciana;
	CPlansza::PlanszaSpec[x - 1][y] = sciana;

	CPlansza::PlanszaSpec[x - 1][y + 3] = sciana;
	CPlansza::PlanszaSpec[x][y + 3] = sciana;

	CPlansza::PlanszaSpec[x - 2][y + 1] = podloga;
	CPlansza::PlanszaSpec[x - 2][y + 2] = podloga;

	CPlansza::PlanszaSpec[x - 2][y] = dach_lewa_strona;
	CPlansza::PlanszaSpec[x - 3][y + 1] = dach_lewa_strona;

	CPlansza::PlanszaSpec[x - 3][y + 2] = dach_prawa_strona;
	CPlansza::PlanszaSpec[x - 2][y + 3] = dach_prawa_strona;

	return true;
}


CZamek::CZamek(int set_x, int set_y, int set_NumZda, CPlansza* set_pPlansza)
{
	x = set_x;
	y = set_y;
	NumerZdarzenia = set_NumZda;
	pPlansza = set_pPlansza;

}
bool CZamek::RysujObiekt()
{
	for (int i = x-3; i > x-8; i--)
	{
		pPlansza->Plansza[i][y-1] = sciana;
	}
	pPlansza->Plansza[x - 8][y] = sufit;
	pPlansza->Plansza[x - 8][y + 1] = sufit;
	pPlansza->Plansza[x - 9][y + 2] = sciana;

	for (int i = y + 3; i < y+5; i++)
		pPlansza->Plansza[x - 10][i] = sufit;

	pPlansza->Plansza[x - 9][y + 5] = sciana;
	pPlansza->Plansza[x - 8][y + 5] = sciana;

	pPlansza->Plansza[x - 8][y + 4] = podloga_quest;
	
	pPlansza->Plansza[x - 7][y + 3] = sciana;
	pPlansza->Plansza[x - 6][y + 3] = sciana;

	pPlansza->Plansza[x - 4][y + 3] = sciana;
	pPlansza->Plansza[x - 3][y + 3] = sciana;

	pPlansza->Plansza[x - 3][y + 4] = podloga_quest;

	pPlansza->Plansza[x - 2][y + 5] = sciana;
	pPlansza->Plansza[x - 1][y + 5] = sciana;

	for (int i = y + 3; i < y+5; i++)
		pPlansza->Plansza[x][i] = sufit;

	pPlansza->Plansza[x - 1][y + 2] = sciana;
	pPlansza->Plansza[x - 2][y + 1] = sufit;
	pPlansza->Plansza[x - 2][y] = sufit;


	return true;
}

CPole::CPole(int set_x, int set_y, int set_NumZda, CPlansza* set_pPlansza)
{
	x = set_x;
	y = set_y;
	NumerZdarzenia = set_NumZda;
	pPlansza = set_pPlansza;
}

bool CPole::RysujObiekt()
{
	for (int i = x; i > x - 4; i--)
		for (int j = y; j < y + 4; j++)
			pPlansza->Plansza[i][j] = pola;

	return true;
}
void CMainHero::poruszanie(int kierunek)
{
	if (isUndergorund)
	    pPlansza->Podziemia[x][y] = puste_pole;
	else
		pPlansza->Plansza[x][y] = puste_pole;
	//_getch();
	//int kierunek = _getch();
	prevX = x;
	prevY = y;
	if (isUndergorund)
	{
		switch (kierunek)
		{

		case 80: //strza³ka w dó³
		{
			if (sprawdz_pola(pPlansza->Podziemia[x + 1][y]))
			{
				pPlansza->Podziemia[x + 1][y] = PolePostaci;
				x += 1;
			}
			break;
		}

		case 72: //strza³ka w góre
		{

			if (sprawdz_pola(pPlansza->Podziemia[x - 1][y]))
			{
				pPlansza->Podziemia[x - 1][y] = PolePostaci;
				x -= 1;

			}
			break;
		}
		case 75: //strza³ka w lewo 
		{

			if (sprawdz_pola(pPlansza->Podziemia[x][y - 1]))
			{
				pPlansza->Podziemia[x][y - 1] = PolePostaci;
				y -= 1;
			}
			break;
		}
		case 77: //strza³ka w prawo
		{
			if (sprawdz_pola(pPlansza->Podziemia[x][y + 1]))
			{
				pPlansza->Podziemia[x][y + 1] = PolePostaci;
				y += 1;
			}
			break;
		}
		default: break;
		}
	}
	else
	{
		switch (kierunek)
		{

		case 80: //strza³ka w dó³
		{
			if (sprawdz_pola(pPlansza->Plansza[x + 1][y]))
			{
				pPlansza->Plansza[x + 1][y] = PolePostaci;
				x += 1;
			}
			break;
		}

		case 72: //strza³ka w góre
		{

			if (sprawdz_pola(pPlansza->Plansza[x - 1][y]))
			{
				pPlansza->Plansza[x - 1][y] = PolePostaci;
				x -= 1;

			}
			break;
		}
		case 75: //strza³ka w lewo
		{

			if (sprawdz_pola(pPlansza->Plansza[x][y - 1]))
			{
				pPlansza->Plansza[x][y - 1] = PolePostaci;
				y -= 1;
			}
			break;
		}
		case 77: //strza³ka w prawo
		{
			if (sprawdz_pola(pPlansza->Plansza[x][y + 1]))
			{
				pPlansza->Plansza[x][y + 1] = PolePostaci;
				y += 1;
			}
			break;
		}
		default: break;
		}
	}

	if(isUndergorund)
		pPlansza->Podziemia[x][y] = PolePostaci;
	else 
		pPlansza->Plansza[x][y] = PolePostaci;
}

bool CMainHero::PoruszanieTratwa(int kierunek)
{
	if (Itemy.tratwa == false)
		return false;
	

	ObszarWokolGraczaNaPlansze(drzwi, rzeka);


	pPlansza->Plansza[x][y] = rzeka;
	
	switch (kierunek)
	{

	case 80: //strza³ka w dó³
	{
		if (pPlansza->Plansza[x + 1][y].NumerZdarzenia == 7)
		{

			++x;
			
			pPlansza->Plansza[x][y] = PolePostaci;

			ObszarWokolGraczaNaPlansze(rzeka, drzwi);


		}
		break;
	}

	case 72: //strza³ka w góre
	{
		if (pPlansza->Plansza[x - 1][y].NumerZdarzenia == 7)
		{
			
			pPlansza->Plansza[x - 1][y] = PolePostaci;
			x -= 1;

			ObszarWokolGraczaNaPlansze(rzeka, drzwi);
		}

		break;
	}
	case 75: //strza³ka w lewo
	{
		if (pPlansza->Plansza[x][y - 1].NumerZdarzenia == 7)
		{
			
			pPlansza->Plansza[x][y - 1] = PolePostaci;
			y -= 1;

			ObszarWokolGraczaNaPlansze(rzeka, drzwi);
		}
		break;
	}
	case 77: //strza³ka w prawo
	{
		if (pPlansza->Plansza[x][y + 1].NumerZdarzenia == 7)
		{
			
			pPlansza->Plansza[x][y + 1] = PolePostaci;
			y += 1;

			ObszarWokolGraczaNaPlansze(rzeka, drzwi);
		}
		
		break;
	}
	default:;
	}



	return true;
}

bool CMainHero::Zbieranie()
{
	if (SzukajPola(6))	
	{ 
		if (Itemy.DodajDrewno())
		{
			if(++LicznikDrzew >= 500) //!!!!!!!!  TODO
			{
				pFabula->DrzewusCreatio();
				LicznikDrzew = 0;
			}
			return false;
		}
	return true; 
	}
	if (SzukajPola(5))
	{ 
		if (Itemy.DodajZboze())
			return false;
		return true;
	}
	if (SzukajPola(7))
	{ 
		if (Itemy.DodajWode())
			return false;
		return true; 
	}



	return false;

}

bool CMainHero::konstruowanie()
{
	DodatkowyEkwipunek* ObecnyPrzedmiot = NULL;
	int decyzja = '0';
	cout << endl << "Co chcesz stworzyc?" << endl;
	cout << "0. Tratwa" << endl;
	cout << "1. Ciasto" << endl;
	cout << "2. Wlokno" << endl;
	cout << "3. lina" << endl;
	cout << "4. ???" << endl;
	cout << "5. ???" << endl;
	
	if (RozszerzenieEq != NULL)
	{
		decyzja = _getch();
		if (decyzja == 224)
			decyzja = _getch();
	}
	else
	{
		cout << endl << endl << strName << ": Sprobuje zrobic tratwe.." << endl;
		_getch();
	}
	switch (decyzja)
	{
	case '0':// TRATWA
	{
		if (Itemy.drewno != 5)
		return false;
		if (Itemy.zboze != 5)
		return false;
	Itemy.tratwa = true;
	Itemy.drewno = 0;
	Itemy.zboze = 0;
	
	_getch();
	break;
	}

	case '1': // ciasto
	{
		 ObecnyPrzedmiot = WyszukajPrzedmiot(RozszerzenieEq, 2); // m¹ka
		if (ObecnyPrzedmiot->Ilosc < 2) return false;
		if (Itemy.woda != 5) return false;

		ObecnyPrzedmiot->UsunPrzedmiot();
		ObecnyPrzedmiot->UsunPrzedmiot();
		ObecnyPrzedmiot = WyszukajPrzedmiot(RozszerzenieEq, 3); // ciasto
		ObecnyPrzedmiot->DodajPrzedmiot();

		break;
	}

	case '2': // w³ókno 
	{
		if (!(Itemy.zboze >= 5))
			return false;

		Itemy.zboze -= 5;
		WyszukajPrzedmiot(RozszerzenieEq, 4)->DodajPrzedmiot(); // w³ókno

		break;


	}

	case '3': // lina
	{
		ObecnyPrzedmiot = WyszukajPrzedmiot(RozszerzenieEq, 4); // w³ókno
		if (ObecnyPrzedmiot->Ilosc < 5) return false;

		for (int i = 0; i < 5; i++)
			ObecnyPrzedmiot->UsunPrzedmiot();

		ObecnyPrzedmiot = WyszukajPrzedmiot(RozszerzenieEq, 5); // lina
		ObecnyPrzedmiot->DodajPrzedmiot();

		break;
		

	}

	default: cout << "Nieznane polecenie" << endl; return false;
	}


	return true;
}

bool CMainHero::PobierzObszarWokolGracza()
{	
int a = -1;
int b = -1;



if(isUndergorund == false)
for (int i = 0; i < 3; i++)
{
	if (i > 0) b = -1;
	for (int j = 0; j < 3; j++)
	{
		ObszarWokolGracza[i][j] = pPlansza->Plansza[x + a][y + b];
		++b;
	}
	++a;
}
else
for (int i = 0; i < 3; i++)
{
	if (i > 0) b = -1;
	for (int j = 0; j < 3; j++)
	{
		ObszarWokolGracza[i][j] = pPlansza->Podziemia[x + a][y + b];
		++b;
	}
	++a;
}




return true;
}

bool CMainHero::ObszarWokolGraczaNaPlansze(pole jezelico, pole tonato)
{
	int a = -1;
	int b = -1;
	for (int i = 0; i < 3; i++)
	{
		if (i > 0) b = -1;
		for (int j = 0; j < 3; j++)
		{
			if (pPlansza->Plansza[x + a][y + b] == jezelico)
				pPlansza->Plansza[x + a][y + b] = tonato;
			++b;
		}
		++a;
	}
	return true;
}
bool CMainHero::SzukajPola(int SzukanyNumerZdarzenia)
{
	PobierzObszarWokolGracza();
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (ObszarWokolGracza[i][j].NumerZdarzenia == SzukanyNumerZdarzenia)
				return true;

	return false;
}

void CMainHero::SetHp(int hp)
{
	parametry.hp = hp;

}
void CMainHero::ZarzadanieEq(bool sell)
{
	bool end = false;
	int ChosenOne = 0;
	
	while (!end)
	{
		system("cls");
		AktualizujPlecak();
		cout << strName << endl
			<< "HP: " << parametry.hp << " / " << MaxHP << endl
			<< "MOC:" << parametry.moc << endl
			<< "SILA: " << parametry.sila << endl
			<< "OBRONA: " << parametry.obrona << endl
			<< "GLOD: " << PoziomGlodu << " / " << MaxPoziomGlodu << endl
			<< "---------------------------------------------" << endl << endl;

		if (Plecak.empty())
		{
			cout << endl << "BRAK PRZEDMIOTOW UZYTKOWYCH" << endl;
			_getch();
			return;
		}


		if (sell)
			cout << endl << "Co chcesz sprzedac?" << endl << "---------------------------------------------" << endl << endl;

		cout << "Nacisnij esc by wrocic" << endl << endl;
	
		
		for (int i = 0; i < Plecak.size(); i++)
		{
			if (i == ChosenOne)
			{
				cout << "->" << Plecak[i]->Nazwa << "<-" << endl;
				continue;
			}
			cout << "  " << Plecak[i]->Nazwa << endl;
		}

		int decyzja = _getch();
		if (decyzja == 224)
			decyzja = _getch();

		switch (decyzja)
		{
		case 80: //strza³ka w dó³
		{
			if (++ChosenOne == Plecak.size())
				ChosenOne = 0;
			break;
		}

		case 72: //strza³ka w góre
		{

			if (--ChosenOne < 0)
				ChosenOne = static_cast<int>(Plecak.size()) - 1;
			break;
		}

		case 77: //strza³ka w prawo
		{
			system("cls");
			cout << strName << endl
				<< "HP: " << parametry.hp << " / " << MaxHP << endl
				<< "MOC:" << parametry.moc << endl
				<< "SILA: " << parametry.sila << endl
				<< "OBRONA: " << parametry.obrona << endl
				<< "GLOD: " << PoziomGlodu << " / " << MaxPoziomGlodu << endl
				<< "---------------------------------------------" << endl << endl;
				cout << "Nacisnij esc by wrocic" << endl << endl;
			for (int i = 0; i < Plecak.size(); i++)
			{
				if (i == ChosenOne)
				{
					cout << "->" << Plecak[i]->Nazwa << "---->" << Plecak[i]->Opis << "      cena: " << Plecak[i]->cena << endl;
					continue;
				}
				cout << "  " << Plecak[i]->Nazwa << endl;
			}

			_getch();
			break;

		}

		case 13:
		{
			if (sell == false)
			{
				switch (Plecak[ChosenOne]->TYP)
				{

				case WEAPON:
				{
					if (NoszonePrzedmioty.Sword == NULL)
					{
						NoszonePrzedmioty.Sword = static_cast<const CWeapon*>(Plecak[ChosenOne]); 
						Plecak.erase(Plecak.begin() + ChosenOne);
						break;
					}
					Plecak.push_back(NoszonePrzedmioty.Sword);
					NoszonePrzedmioty.Sword = static_cast<const CWeapon*>(Plecak[ChosenOne]);
					Plecak.erase(Plecak.begin() + ChosenOne);
					break;
				}
				case ARMOR:
				{
					if (NoszonePrzedmioty.Armor == NULL)
					{
						NoszonePrzedmioty.Armor = static_cast<const CArmor*>(Plecak[ChosenOne]); 
						Plecak.erase(Plecak.begin() + ChosenOne);
						break;
					}
					Plecak.push_back(NoszonePrzedmioty.Armor);
					NoszonePrzedmioty.Armor = static_cast<const CArmor*>(Plecak[ChosenOne]);
					Plecak.erase(Plecak.begin() + ChosenOne);
					break;
				}
				case USEABLE:
				{
					if (NoszonePrzedmioty.UseableItem == NULL)
					{
						NoszonePrzedmioty.UseableItem = static_cast<const CUseableItem*>(Plecak[ChosenOne]); 
						Plecak.erase(Plecak.begin() + ChosenOne);
						break;
					}
					Plecak.push_back(NoszonePrzedmioty.UseableItem);
					NoszonePrzedmioty.UseableItem = static_cast<const CUseableItem*>(Plecak[ChosenOne]);
					Plecak.erase(Plecak.begin() + ChosenOne);
					break;
				}
				case FOOD:
				{
					if (parametry.hp != MaxHP)
					{
						parametry.hp += static_cast<const CFood*>(Plecak[ChosenOne])->LeczoneHp;
						if (parametry.hp > MaxHP) parametry.hp = MaxHP;
					}

					if (PoziomGlodu != MaxPoziomGlodu)
					{
						PoziomGlodu += static_cast<const CFood*>(Plecak[ChosenOne])->OdnawianyGlod;
						if (PoziomGlodu > MaxPoziomGlodu) PoziomGlodu = MaxPoziomGlodu;
					}

					WyszukajPrzedmiot(RozszerzenieEq, static_cast<const CFood*>(Plecak[ChosenOne])->Rodzaj)->UsunPrzedmiot();

					break;
				}
				case ARIA:
				{
					
					static_cast<const CFragmentOfPoem*>(Plecak[ChosenOne])->UstawKolejnosc(pFabula);				

					break;
				}
				case BOOK:
				{

					if (!static_cast<const CBook*>(Plecak[ChosenOne])->Czytaj())
					{
						cout << "ERROR: Brak pliku lub nr ksiazki nie wlasciwy. Prosimy o kontakt z Ziutmelsonem" << endl;
						_getch();
					}

					break;
				}
				}
			}

			if (sell == true)
			{
				//int NumerPrzedmiotu;
				if (Plecak[ChosenOne]->cena == 0)
				{
					cout << "Przedmiot bezcenny - sprzedaz niemozliwa" << endl;
					break;
				}
				Itemy.zloto += Plecak[ChosenOne]->cena;
				if (Plecak[ChosenOne]->TYP == FOOD || Plecak[ChosenOne]->TYP == USEABLE)
				{
					WyszukajPrzedmiot(RozszerzenieEq, static_cast<const CFood* >(Plecak[ChosenOne])->Rodzaj)->UsunPrzedmiot();
					break;
				}
				
				
				WyszukajPrzedmiot(RozszerzenieEq, static_cast<const CFood* >(Plecak[ChosenOne])->Rodzaj)->UsunPrzedmiot();
				Plecak.erase(Plecak.begin() + ChosenOne);				

			}



			break;
		}
		case 27: end = true;
		default:;
		}
		
	}
	

}
bool CMainHero::TworzenieMikstur()
{
	

	return true;
}

void CMainHero::SetMaxHP(int number)
{
	MaxHP = number;
}
void CMainHero::SetMaxPoziomGlodu(int number)
{
	MaxPoziomGlodu = number;
}
void CMainHero::Switch_undergorund() 
{ 
	if(isUndergorund == true)
	{
		isUndergorund = false;
		pPlansza->Podziemia[x][y] = puste_pole;

	}
	else
	{
		isUndergorund = true;
		pPlansza->Plansza[x][y] = puste_pole;

	}


}
void CMainHero::AktualizujPlecak()
{
	int IndexItemuWPlecaku;
	if (RozszerzenieEq == NULL)
		return;

	IndexItemuWPlecaku = WyszukajItemWPlecaku(1, FOOD);
	if (WyszukajPrzedmiot(RozszerzenieEq, 1)->CzyJest && IndexItemuWPlecaku == -1)
		Plecak.push_back(&Chleb);
	if (WyszukajPrzedmiot(RozszerzenieEq, 1)->CzyJest == false && IndexItemuWPlecaku != -1)
		Plecak.erase(Plecak.begin() + IndexItemuWPlecaku);

	IndexItemuWPlecaku = WyszukajItemWPlecaku(7, FOOD);
	if (WyszukajPrzedmiot(RozszerzenieEq, 7)->CzyJest && IndexItemuWPlecaku == -1)
		Plecak.push_back(&RawMeat);
	if (WyszukajPrzedmiot(RozszerzenieEq, 7)->CzyJest == false && IndexItemuWPlecaku != -1)
		Plecak.erase(Plecak.begin() + IndexItemuWPlecaku);

	IndexItemuWPlecaku = WyszukajItemWPlecaku(8, FOOD);
	if (WyszukajPrzedmiot(RozszerzenieEq, 8)->CzyJest && IndexItemuWPlecaku == -1)
		Plecak.push_back(&Meat);
	if (WyszukajPrzedmiot(RozszerzenieEq, 8)->CzyJest == false && IndexItemuWPlecaku != -1)
		Plecak.erase(Plecak.begin() + IndexItemuWPlecaku);

	IndexItemuWPlecaku = WyszukajItemWPlecaku(9, FOOD);
	if (WyszukajPrzedmiot(RozszerzenieEq, 9)->CzyJest && IndexItemuWPlecaku == -1)
		Plecak.push_back(&KanapkaZSzynka);
	if (WyszukajPrzedmiot(RozszerzenieEq, 9)->CzyJest == false && IndexItemuWPlecaku != -1)
		Plecak.erase(Plecak.begin() + IndexItemuWPlecaku);
	
	IndexItemuWPlecaku = WyszukajItemWPlecaku(10, USEABLE);
	if (WyszukajPrzedmiot(RozszerzenieEq, 10)->CzyJest && IndexItemuWPlecaku == -1 && NoszonePrzedmioty.UseableItem != &MiksturaLecznicza )
		Plecak.push_back(&MiksturaLecznicza);
	if (WyszukajPrzedmiot(RozszerzenieEq, 10)->CzyJest == false && IndexItemuWPlecaku != -1)
		Plecak.erase(Plecak.begin() + IndexItemuWPlecaku);

	IndexItemuWPlecaku = WyszukajItemWPlecaku(11, USEABLE);
	if (WyszukajPrzedmiot(RozszerzenieEq, 11)->CzyJest && IndexItemuWPlecaku == -1 && NoszonePrzedmioty.UseableItem != &MiksturaOgnia)
		Plecak.push_back(&MiksturaOgnia);
	if (WyszukajPrzedmiot(RozszerzenieEq, 11)->CzyJest == false && IndexItemuWPlecaku != -1)
		Plecak.erase(Plecak.begin() + IndexItemuWPlecaku);

	IndexItemuWPlecaku = WyszukajItemWPlecaku(12, USEABLE);
	if (WyszukajPrzedmiot(RozszerzenieEq, 12)->CzyJest && IndexItemuWPlecaku == -1 && NoszonePrzedmioty.UseableItem != &MiksturaAntiUndead)
		Plecak.push_back(&MiksturaAntiUndead);
	if (WyszukajPrzedmiot(RozszerzenieEq, 12)->CzyJest == false && IndexItemuWPlecaku != -1)
		Plecak.erase(Plecak.begin() + IndexItemuWPlecaku);

	IndexItemuWPlecaku = WyszukajItemWPlecaku(13, USEABLE);
	if (WyszukajPrzedmiot(RozszerzenieEq, 13)->CzyJest && IndexItemuWPlecaku == -1 && NoszonePrzedmioty.UseableItem != &MiksturaTrucizna)
		Plecak.push_back(&MiksturaTrucizna);
	if (WyszukajPrzedmiot(RozszerzenieEq, 13)->CzyJest == false && IndexItemuWPlecaku != -1)
		Plecak.erase(Plecak.begin() + IndexItemuWPlecaku);

	IndexItemuWPlecaku = WyszukajItemWPlecaku(14, USEABLE);
	if (WyszukajPrzedmiot(RozszerzenieEq, 14)->CzyJest && IndexItemuWPlecaku == -1 && NoszonePrzedmioty.UseableItem != &NozDoRzucania)
		Plecak.push_back(&NozDoRzucania);
	if (WyszukajPrzedmiot(RozszerzenieEq, 14)->CzyJest == false && IndexItemuWPlecaku != -1)
		Plecak.erase(Plecak.begin() + IndexItemuWPlecaku);

	IndexItemuWPlecaku = WyszukajItemWPlecaku(15, USEABLE);
	if (WyszukajPrzedmiot(RozszerzenieEq, 23)->CzyJest && IndexItemuWPlecaku == -1 && NoszonePrzedmioty.UseableItem != &KamienGlupcow)
		Plecak.push_back(&KamienGlupcow);
	if (WyszukajPrzedmiot(RozszerzenieEq, 23)->CzyJest == false && IndexItemuWPlecaku != -1)
		Plecak.erase(Plecak.begin() + IndexItemuWPlecaku);
}

int CMainHero::WyszukajItemWPlecaku(int Number, ItemType typ)
{

	for (int i = 0; i < Plecak.size(); i++)
	{
		if (Plecak[i]->TYP == typ)
			if (Plecak[i]->Rodzaj == Number)
				return i;

	}
	return -1;
}

void CMainHero::MenuGracza(int decyzja)
{
	switch (decyzja)
	{
	case 13: Zbieranie(); break;

	case 115: DrawElement(); //115 to literka s czyli zapis
		break;
		
	case 105:// "i" czyli ekwpipunek
	{
		Itemy.WyswietlEq();
		if (bMagicznaRoslina) cout << "Posiadasz dziwna rosline" << endl;
		PokazCalyEq(RozszerzenieEq);
		_getch();
		break; 
	}

	case 120: // "x" uruchominie tratwy lub jej dezaktywacja
		if (Itemy.tratwa)
			if (SzukajLiczPole(rzeka, 3))
				isTratwa = true;


		if(isTratwa)
		if (SzukajLiczPole(puste_pole, 3) && SzukajLiczPole(drzwi, 3)) {
		isTratwa = false;
		Itemy.tratwa = false;
		ObszarWokolGraczaNaPlansze(drzwi, rzeka);
	}
		break; 
	case 99: // "c" konstruowanie
		konstruowanie();
		break;

	case 'p': ZarzadanieEq(false); break;
	
	case 'q': 
	{
		if (!bKopanie) return;

		if (x == 24 && y == 37)
		{
			cout << endl << strName << ": Hmm? Cos tu jest.. Jakas stara ksiazka.." << endl;
			cout << endl << endl << endl << "Otrzymales raport" << endl;
			
			Plecak.push_back(&KsiazkaRaport);
			_getch();
			return;
		}

		cout << endl << strName << ": Nic tu nie ma... " << endl;
		_getch();


		break;
	}

	//case '=': WyszukajPrzedmiot(RozszerzenieEq, 23)->DodajPrzedmiot(); //pFabula->HistoriaAsgaru(); break; //pFabula->OdzyskajEq(); break;

	default: if (isTratwa) PoruszanieTratwa(decyzja); else poruszanie(decyzja);
	}

}

bool CMainHero::SzukajLiczPole(pole ZliczanePole, int licznik)
{
	PobierzObszarWokolGracza();
	int k = 0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (ObszarWokolGracza[i][j] == ZliczanePole)
				++k;
	if(k >= licznik)
		return true;
	

	return false;
}

/*
bool CMainHero::sprawdz_pola(int kierunek, CPlansza* pPlansza)
{
	
	pole ObszarWokolGracza[3][3];
	int a = -1;
	int b = -1;
	for (int i = 0; i < 3; i++)
	{ 		
		a = 0;
		for (int j = 0; j < 3; j++)
		{
			ObszarWokolGracza[i][j] = pPlansza->Plansza[x+a][y+b];
			++b;
		}
		++a;
	}
	
	
	




	return true;
}
*/

bool CMainHero::sprawdz_pola(pole PolePlanszy)
{
	if (PolePlanszy.NumerZdarzenia == 1 
		|| PolePlanszy.NumerZdarzenia == 6
		|| PolePlanszy.NumerZdarzenia == 7) //  sciana, przeszkoda nie do pokonania 6 to drewno 7 woda
	{
		cout << "Illegal move";
		return false;
	}
		

	if (PolePlanszy.NumerZdarzenia == 2) // NPC w obiekcie
	{
		// tu potrzeba jakiejsc dodatkowej akcji
		return true;
	}

	if (PolePlanszy.NumerZdarzenia >= 100 && PolePlanszy.NumerZdarzenia < 10000) // NPC jako realna postac
	{
		// tu potrzeba jakiejsc dodatkowej akcji
		return false;
	}

	if (PolePlanszy.NumerZdarzenia == 4) // pole specjalne - podloga_quest (moze duch ?)
	{
		// tu potrzeba jakiejsc dodatkowej akcji
		return false;
	}

	if (PolePlanszy.NumerZdarzenia == 5) // pola, takie pszenicy czy czegos
	{
		if(isPole) isUndergorund == false ? pPlansza->Plansza[x][y] = pola : pPlansza->Podziemia[x][y] = pola;
		

		isPole = true;
		
		return true;
	}

	if (PolePlanszy.NumerZdarzenia == 8) // pole siekiery
	{
		int decyzja;

		if (pFabula->StanKlepsydra >= 6)
		{
			cout << endl << "Widzisz jakies zwloki" << endl << "Co robisz? " << endl;
			cout << "1. Zbadaj cialo " << endl << "2. Odejdz" << endl;
			decyzja = _getch();
			if (decyzja == 224)
				decyzja = _getch();
			switch (decyzja)
			{
			case '1':
				cout << strName << ": hmm... slady po zebach i pazurach... Cialo lezy tu juz troche czasu.." << endl;
				cout << "1. Przeszukaj" << endl << "2. Podejdz blizej" << endl << "3. Odejdz" << endl;
				decyzja = _getch();
				if (decyzja == 224)
					decyzja = _getch();

				switch (decyzja)
				{
				case '1':					
					{
						if(pFabula->StanKlepsydra == 9)
							cout << endl <<  strName << ": Teraz juz nic nie rozumiem... Tu powinna byc siekiera... Przeciez kosa wrocila tam skad ja zabralem ostatnio ..." << endl;
						else
							cout << endl << "Nie znajdujesz niczego ciekawego..." << endl;
						
						
						if (_getch() == 224)
							_getch();
					}
					break;

				case '2':
					cout << strName << ": Wiele ran klutych... widocznie nie tylko zwierzeta uczestniczyly w zabawie.. eh.. co za czasy.." << endl;
					if (_getch() == 224)
						 _getch();
					break;
				case '3': return false;
				}

			case '2': return false;

			}


			return false;
		}
		


		cout << endl << "Widisz jakies zwloki" << endl << "Co robisz? " << endl;
		cout << "1. Zbadaj cialo " << endl << "2. Odejdz" << endl;
		decyzja = _getch();
		if(decyzja == 224)
			decyzja = _getch();
		switch (decyzja)
		{
		case '1':		
			
			cout << strName << ": hmm... swieze cialo... slady po zebach i pazurach..."; 
			if (Itemy.siekiera == false)
			{
				cout << "Obok lezy siekiera, pewnie byl drwalem.." << endl;
				cout << "1. Wez siekiere" << endl;
			}
			else
				cout << endl << "1. Przeszukaj" << endl;

				cout << "2. Podejdz blizej" << endl << "3. Odejdz" << endl;

			decyzja = _getch();
			if (decyzja == 224)
				decyzja = _getch();
		
			switch (decyzja)
			{
			case '1':
				if (Itemy.siekiera == false)
				{
					cout << strName << ": siekiera... jemu juz sie chyba nie przyda..." << endl;
					Itemy.siekiera = true;
					Itemy.bron = Siekiera;
					NoszonePrzedmioty.Sword = &WeaponSiekiera;
					_getch();
					break;
				}

				cout << strName << ": Nie ma tu juz nic ciekawego..." << endl;
				_getch();
				break;

			case '2':
				cout << strName << ": Wiele ran klutych... widocznie nie tylko zwierzeta uczestniczyly w zabawie.. eh.. co za czasy.." << endl; 
				_getch();
				break;
			case '3': return false;
			}

		case '2': return false;
			
		}

		
		return false;

	}

	if (PolePlanszy.NumerZdarzenia == 9) // pole kosy
	{	
		if (pFabula->StanKlepsydra >= 6)
		{
			Itemy.kosa = true;
			cout << endl << "Widzisz kose" << endl;
			if (_getch() == 224)
				_getch();
			cout << strName << ": Dobra.. To zaczyna sie robic przerazajace... Ta kosa znowu wyglada jakby na mnie czekala..." << endl;
			if (_getch() == 224)
				_getch();

			pFabula->StanKlepsydra = 9;

			pPlansza->Plansza[39][96] = pola;
			return false;
		}



		Itemy.kosa = true;		
		cout << endl << "Widzisz kose" << endl;
		if (_getch() == 224)
			_getch();
		cout << strName << ": Nie wiem czemu, ale wydaje mi sie, ze ta kosa specjalnie tu na mnie czeka..." << endl;
		if (_getch() == 224)
			_getch();

		pPlansza->Plansza[39][96] = pola;
		return false;
	}

	if (PolePlanszy.NumerZdarzenia == 10)
	{
		cout << endl;
		cout << "Straznik: Przejscia nie ma!" << endl;
		_getch();

		return false;
	}

	if (PolePlanszy.NumerZdarzenia == 11) // MAGICZNA ROSLINA
	{
		
		bMagicznaRoslina = true;
		cout << endl;
		cout << RetName() <<": Takiej rosliny jeszce nie widzialem hmm.." << endl;
		_getch();
		pPlansza->Plansza[4][7] = pola;

	
		return false;
	}

	if (PolePlanszy.NumerZdarzenia == 12) // przejscie w murze
	{

		if (prevX == 29 && prevY == 13)
		{
			cout << endl << endl << strName << ": Hmm... Cos jest nie tak z tym murem... Wyglada na hm.. odnowiony..." << endl;
			_getch();
			return false;
		}

		if (prevX == 32 && prevY == 13)
		{
			cout << endl << endl << strName << ": Sekretne przejscie przez mur..." << endl;
			x = 29;
			y = 13;
			_getch();
			return false;
		}

		return false;
	}

	if (PolePlanszy.NumerZdarzenia == 13) // lozko
	{
		if (pFabula->StanKlepsydra >= 10)
		{
			pFabula->OdzyskajEq();
			cout << endl << strName << ": Dobrze ze tutaj jest wszystko na miejsu..." << endl;
			_getch();
			return false;
		}


		if (Itemy.drewno < 5)
		{
			cout << endl << strName << ": Zgodnie z umowa musze przyniesc 5 klod drewna..." << endl;
			_getch();
			return false;
		}

		Itemy.drewno -= 5;
		if (pFabula->StanKlepsydra == 2)
			pFabula->StanKlepsydra = 3;
		

		return false;
	}

	if (PolePlanszy.NumerZdarzenia == 14) // Drzewo z siekera KLEPSYDRA
	{

		cout << endl << strName << ": Siekiera wbita w drzewo... hm.. " << endl;
		if(_getch() == 224)
			_getch();

		Itemy.siekiera = true;
		Itemy.bron = Siekiera;
		NoszonePrzedmioty.Sword = &WeaponSiekiera;
		
		pFabula->PolaFabularne.push_back(CFabulaPola(drzewo, 34, 75));
		pPlansza->Podziemia[34][75] = drzewo;

		return false;
	}

	if (PolePlanszy.NumerZdarzenia == 15) // glejt na ziemii
	{

		cout << endl << strName << ": A to co za pergamin? " << endl;
		Sleep(1500);
		cout << strName << ": ... " << endl;
		Sleep(1500);
		cout << endl << strName << ": Przeciez to moj glejt... Co on tu robi... " << endl;

		if (_getch() == 224)
			_getch();
		pFabula->StanKlepsydra = 11;
		

		return true;
	}

	if (PolePlanszy.NumerZdarzenia == 16)
	{
		int strzalka;
		if (pFabula->Wytrych == true)
		{
			//case 75: strza³ka w lewo || case 77: //strza³ka w prawo


			string wzor = "<<<><<<><<>>><><>>>><";

			//if ((strzalka = _getch()) == 224) strzalka = _getch();

			for (int i = 0; i < wzor.length(); i++)
			{
				strzalka = _getch();
				if (strzalka == 224) strzalka = _getch();
				if (strzalka != 75 && strzalka != 77) return false;
				if (wzor[i] != (strzalka == 75 ? '<' : '>'))
				{
					cout << endl << endl << strName << ": Cholera musze zaczac od poczatku..." << endl;
					_getch();

					return false;
				}
				cout << endl << endl << strName << ": Brzmi niezle..." << endl;
			}

			this->x = 15;
			this->y = 97;

		}
		return false;
	}

	if (PolePlanszy.NumerZdarzenia == 17)
	{

		if (pFabula->SprPoprawnoscArii())
		{
			pPlansza->Podziemia[41][20] = puste_pole;
			pFabula->DrzwiAria = false;
		}

		return false;
	}


	if (PolePlanszy.NumerZdarzenia >= 50000) //  drzwi i frgmenty
	{
		int numer = PolePlanszy.NumerZdarzenia;
		numer %= 100;
		string odp;

		switch (numer)
		{
		case 0:
		{
			cout << endl << endl << "Gdy wrogow kupa a mi przyjdzie stanac na przeciw nim" << endl << "Nie zlekne sie, a z usmiechem na twarzy spojrze w niebo"
				<< endl << "Za mna zas stanie tysiace mieczy i toporow gotowych walczyc ramie w ramie przy moim boku" << endl
				<< "Wiesz co to jest? :";
			cin >> odp;
			if (odp == "PRZYJAZN")
			{

				return true;
			}
			break;
		}
		case 1:
		{
			cout << endl << endl << "Wyjmuja jej mozg przez nos.. Co to jest ?: ";
			cin >> odp;
			if (odp == "MUMIA")
			{

				return true;
			}
			break;
		}
		case 2:
		{
			cout << endl << endl << "Czerwone i zle wplywa na zeby: ";
			cin >> odp;
			if (odp == "CEGLA")
			{

				return true;
			}

			break;
		}
		case 3:
		{
			cout << endl << endl << "W solidnym murze dostrzegasz brak cegly" << endl;
			cout <<  "Nad ubytkiem ktos wyryl w kamieniu napis: " << endl;
			cout << endl <<"SYMBOL ODWAGI" << endl;
			if (WyszukajItemWPlecaku(4, ARIA) != -1)
			{
				cout << endl << endl << strName << ": Hmm.. Brak ubytku w murze..." << endl;
				_getch();
				return false;
			}
			if (WyszukajPrzedmiot(RozszerzenieEq, 15)->Ilosc > 0)
			{
				WyszukajPrzedmiot(RozszerzenieEq, 15)->UsunPrzedmiot();
				Plecak.push_back(&Fragment[3]);
				cout << endl << endl << "Oddano: " << WyszukajPrzedmiot(RozszerzenieEq, 15)->Nazwa << endl;
				cout << "Otrzymano: Fragment poematu " << endl;
				_getch();
				return false;

			}

			cout << endl << endl << "Hmm... raczej nie mam nic takiego..." << endl;
			_getch();
			return false;
		}
		case 4:
		{
			cout << endl << endl << "W solidnym murze dostrzegasz brak cegly" << endl;
			cout << "Nad ubytkiem ktos wyryl w kamieniu napis: " << endl;
			cout << endl << "SYMBOL ZELAZNEJ WOLI" << endl;
			if (WyszukajItemWPlecaku(4, ARIA) != -1)
			{
				cout << endl << endl << strName << ": Hmm.. Brak ubytku w murze..." << endl;
				_getch();
				return false;
			}
			if (WyszukajPrzedmiot(RozszerzenieEq, 18)->Ilosc > 0)
			{
				WyszukajPrzedmiot(RozszerzenieEq, 18)->UsunPrzedmiot();
				Plecak.push_back(&Fragment[5]);
				cout << endl << endl << "Oddano: " << WyszukajPrzedmiot(RozszerzenieEq, 18)->Nazwa << endl;
				cout << "Otrzymano: Fragment poematu " << endl;
				_getch();
				return false;
			}

			cout << endl << endl << "Hmm... raczej nie mam nic takiego..." << endl;
			_getch();
			return false;
		}
		case 5:
		{
			cout << endl << endl << "W solidnym murze dostrzegasz brak cegly" << endl;
			cout << "Nad ubytkiem ktos wyryl w kamieniu napis: " << endl;
			cout << endl << "SYMBOL LITOSCI" << endl;
			if (WyszukajItemWPlecaku(5, ARIA) != -1)
			{
				cout << endl << endl << strName << ": Hmm.. Brak ubytku w murze..." << endl;
				_getch();
				return false;
			}
			if (WyszukajPrzedmiot(RozszerzenieEq, 17)->Ilosc > 0)
			{
				WyszukajPrzedmiot(RozszerzenieEq, 17)->UsunPrzedmiot();
				Plecak.push_back(&Fragment[4]);
				cout << endl << endl << "Oddano: " << WyszukajPrzedmiot(RozszerzenieEq, 17)->Nazwa << endl;
				cout << "Otrzymano: Fragment poematu " << endl;
				_getch();
				return false;

			}


			cout << endl << endl << "Hmm... raczej nie mam nic takiego..." << endl;
			_getch();
			return false;
		}
		case 6:
		{
			pFabula->bOtwieranieDrzwiLina = true;
			return false;
		}
		case 7:
		{
			cout << endl << endl << "W solidnym murze dostrzegasz brak cegly" << endl;
			cout << "Nad ubytkiem ktos wyryl w kamieniu napis: " << endl;
			cout << endl << "SYMBOL MARAZMU" << endl;

			if (WyszukajItemWPlecaku(8, ARIA) != -1)
			{
				cout << endl << endl << strName << ": Hmm.. Brak ubytku w murze..." << endl;
				_getch();
				return false;
			}

			if (WyszukajPrzedmiot(RozszerzenieEq, 21)->Ilosc > 0)
			{
				WyszukajPrzedmiot(RozszerzenieEq, 21)->UsunPrzedmiot();
				Plecak.push_back(&Fragment[7]);
				cout << endl << endl << "Oddano: " << WyszukajPrzedmiot(RozszerzenieEq, 21)->Nazwa << endl;
				cout << "Otrzymano: Fragment poematu " << endl;
				_getch();
				return false;

			}


			cout << endl << endl << strName << ": Hmm... raczej nie mam nic takiego..." << endl;
			_getch();
			return false;
		}
		case 8:
		{
			cout << endl << endl << "W solidnym murze dostrzegasz brak cegly" << endl;
			cout << "Nad ubytkiem ktos wyryl w kamieniu napis: " << endl;
			cout << endl << "SYMBOL OPIEKI" << endl;

			if (WyszukajItemWPlecaku(7, ARIA) != -1)
			{
				cout << endl << endl << strName << ": Hmm.. Brak ubytku w murze..." << endl;
				_getch();
				return false;
			}

			if (WyszukajPrzedmiot(RozszerzenieEq, 22)->Ilosc > 0)
			{
				WyszukajPrzedmiot(RozszerzenieEq, 22)->UsunPrzedmiot();
				Plecak.push_back(&Fragment[6]);
				cout << endl << endl << "Oddano: " << WyszukajPrzedmiot(RozszerzenieEq, 22)->Nazwa << endl;
				cout << "Otrzymano: Fragment poematu " << endl;
				_getch();
				return false;

			}


			cout << endl << endl << "Hmm... raczej nie mam nic takiego..." << endl;
			_getch();
			return false;
		}
		case 9: 
		{
			cout << endl << endl << "W solidnym murze dostrzegasz brak cegly" << endl;
			cout << "Nad ubytkiem ktos wyryl w kamieniu napis: " << endl;
			cout << endl << "SYMBOL ODMIENNOSCI" << endl;

			if (WyszukajItemWPlecaku(6, ARIA) != -1)
			{
				cout << endl << endl << strName << ": Hmm.. Brak ubytku w murze..." << endl;
				_getch();
				return false;
			}

			if (bMagicznaRoslina)
			{
				bMagicznaRoslina = false;
				Plecak.push_back(&Fragment[5]);
				cout << endl << endl << "Oddano: dziwna rosline" << endl;
				cout << "Otrzymano: Fragment poematu " << endl;
				_getch();
				return false;

			}


			cout << endl << endl << "Hmm... raczej nie mam nic takiego..." << endl;
			_getch();
			return false;
		}
		case 10:
		{
			system("cls");
			cout << strName << ": Hmm... Na tym murze zostalo cos wygrawerowane..." << endl << endl;
			pPlansza->RysujWizje(32, 5, 5, false);
			_getch();
			return false;
		}
		case 11:
		{
			system("cls");
			cout << strName << ": Hmm... Na tym murze zostalo cos wygrawerowane..." << endl << endl;
			pPlansza->RysujWizje(34, 98, 10, false);
			_getch();
			return false;
		}
		case 12:
		{
			system("cls");
			cout << strName << ": Hmm... Na tym murze zostalo cos wygrawerowane..." << endl << endl;
			pPlansza->RysujWizje(0, 0, 5, false);
			_getch();
			return false;
		}
		case 13:
		{
			if (x == 47 && y == 43)
			{
				y = 45;
				return false;
			}
			if (bKlepsydra && pFabula->StanKlepsydra == 23)
			{				
				bKlepsydra = false;
				pFabula->StanKlepsydra = 24;
				cout << endl << endl << "Umiesciles klepsydre na piedestale " << endl;
				Sleep(2000);
				cout << endl << "Uslyszles chrzest otwieranych drzwi.. " << endl;
				Sleep(2000);
				cout << endl << "gdy ponownie spojrzales na piedestal.. byl pusty.. " << endl;
				Sleep(2000);
				cout << endl << "niepozostalo Ci nic innego jak przejsc przez drzwi.. tak wiec wzruszyles ramionami i ..." << endl;
				Sleep(2000);
				cout << endl << "przeszedles.. " << endl;
				if (x == 47 && y == 45)
				{
					y = 43;
				}
				_getch();
			}


			cout << endl << endl << strName << ": Hmm.. jakis piedestal... pewnie otwiera drzwii... " << endl;
			_getch();

			return false;
		}

		case 14:
		{
			if (pFabula->ZlotyPosag == false)
			{
				cout << endl << endl << "Hmm.. Miedziany posag.. przedstawiajacy jakby gryfa ? .." << endl;
				_getch();
				return false;
			}

			if (pFabula->StanFinalQuest == 2)
			{
				cout << endl << endl << strName << ": Hmm.. ten posag blokuje droge.." << endl;
				cout << endl << strName <<": YYYCH... Cholera.. nie dam rady tego przesunac.. musze cos wymyslic.." << endl;
				_getch();
				
				if (WyszukajPrzedmiot(RozszerzenieEq, 23)->CzyJest)
				{
					WyszukajPrzedmiot(RozszerzenieEq, 23)->UsunPrzedmiot();
					pFabula->StanFinalQuest = 3;
					pFabula->ZlotyPosag = false;
					pPlansza->Podziemia[30][1].SymbolPola = '&';
					system("cls");
					pPlansza->RysujPodziemia(x, y);
					cout << endl << strName << ": Udalo sie! Teraz ten Gryf jest z miedzi!" << endl;
					
					cout << endl << strName << ": Teraz powinienem dac rade" << endl;
					cout << endl << strName << ": YYYYYYCH!!!" << endl;
					int licznik = 0;

					cout << endl << "< Wciskaj spacje >" << endl;
					while (licznik < 200)
					{
						if (_getch() == 32)
						{
							cout << "|";
							++licznik;
						}
					}


					pPlansza->Podziemia[30][1] = puste_pole;
					pPlansza->Podziemia[30][2].SymbolPola = '&';
					pPlansza->Podziemia[30][2].NumerZdarzenia = 50014;
					system("cls");
					pPlansza->RysujPodziemia(x, y);

					cout << endl << strName << ": < ciezki oddech > Uffff.. U.. Ud.. Udalo sie.. Ufff" << endl;

					cout << endl << strName << ": Moj kregoslup Uffff..." << endl;

					cout << endl << endl << "Oddales kamien glupcow" << endl;
					Sleep(3000);
					_getch();

				}


				return false;
			}

			cout << endl << endl << "Hmm.. Zloty posag.. przedstawiajacy jakby gryfa ? .." << endl;
			_getch();
			return false;
		}

		case 15:
		{
			if (pFabula->bKsiazkaWilka)
			{
				cout << endl << endl << strName << ": Juz raczej nic tu nie znajde" << endl;
				_getch();
				return false;
			}
			pFabula->bKsiazkaWilka = true;
			cout << endl << endl << strName << ": Hmm.. To chyba to.. " << endl;
			Plecak.push_back(&KsiazkaWilka);
			_getch();
			return false;
		}

		default: cout << "Nieznany numer !!!!! DRZWI!!!! " << numer << endl; _getch();
		}

		//system("cls");cout << "Rozszalaly plomien ogarnal twe cialo.. Zakonczyles swoj zywot w okrutnych mekach...." << endl;_getch();
		//koniec = true;
		return false;
	}

	if (PolePlanszy.NumerZdarzenia >= 30000) // pole przedmiotow
	{
		
		int numer = PolePlanszy.NumerZdarzenia;
		numer = numer % 10000;		
		numer = numer % 100;
		const CItem* Przemiot;
		switch (numer)
		{
		case 1:  Przemiot = &RozrywaczCzasu; break;
		case 2:  Przemiot = &Fragment[2]; break;
		case 3:  Przemiot = &DlugiMiecz; break;
		default: { cout << endl << endl << "!!!!!!!!!!!!! NIEZNANY PRZEDMIOT  !!!!!!!!!!!!" << endl;
			_getch();
			return true; }
			
		}

		Plecak.push_back(Przemiot);
		cout << endl << endl << "Otrzymales " << Przemiot->Nazwa << "." << endl;	
		pFabula->TabPrzedmioty[numer] = true;
		_getch();

		return true;
	}

	if (PolePlanszy.NumerZdarzenia >= 20000) // podziemne przjesice
	{
		Switch_undergorund();
		int numer = PolePlanszy.NumerZdarzenia;
		numer = numer % 10000;
		this->x = numer / 100;
		this->y = numer % 100;
		
		

		return false;
	}

	if (PolePlanszy.NumerZdarzenia >= 10000) // walka z potworkiem 1->walka 00-> wspolrzedne x 00-> wspolrzedne y 
	{
		int x, y, numer = PolePlanszy.NumerZdarzenia;
		numer = numer % 10000;
		x = numer / 100;
		y = numer % 100;
		CMonster* Monster = static_cast<CMonster*>(pPlansza->PlanszaWskaznikow[x][y]);

		if (!Walka(pPlansza->PlanszaWskaznikow[x][y]))
			koniec = true;
		else
		{
			Monster->GiveLoot(this);
			pFabula->DeleteMonster(Monster->RetIndex(), Monster->RetID());
			
		}

		return true;
	}


	if (isPole) isUndergorund == false ? pPlansza->Plansza[x][y] = pola : pPlansza->Podziemia[x][y] = pola;
	isPole = false;
	return true; // dla NumZdarzenia == 0, czyli zwyklego pola
}


int CMainHero::SzukajNPC()
{
	int Numer = 0;
	PobierzObszarWokolGracza();
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			if (ObszarWokolGracza[i][j].NumerZdarzenia >= 100 && ObszarWokolGracza[i][j].NumerZdarzenia < 10000)
			{
				Numer = ObszarWokolGracza[i][j].NumerZdarzenia;
				break;
			}
			
		}
	return Numer;
}
CCharacter* CMainHero::SzukajWskaznikaNPC()
{
	int pX = x, pY = y;
	PobierzObszarWokolGracza();
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			if (ObszarWokolGracza[i][j].NumerZdarzenia >= 100 && ObszarWokolGracza[i][j].NumerZdarzenia < 10000)
			{
				/*
				switch (i)
				{
				case 0:
					--pX;
					if (j == 0)
						--pY;
					if (j == 1)
						++pY;
					break;

				case 1:
					if (j == 0)
						--pY;
					if (j == 1)
						++pY;

					break;

				case 2:
					++pX;

					if (j == 0)
						--pY;
					if (j == 1)
						++pY;
					break;

				}
			*/
				switch (i)
				{
				case 0:
					--pX;
					if (j == 0)
						--pY;
					if (j == 2)
						++pY;
					break;

				case 1:
					if (j == 0)
						--pY;
					if (j == 2)
						++pY;
					break;

				case 2:
					++pX;

					if (j == 0)
						--pY;
					if (j == 2)
						++pY;
					break;

				}

				return pPlansza->PlanszaWskaznikow[pX][pY];
			}

		}
	
	
	return NULL;


}
CGilgamesh::CGilgamesh()
{
	pPlansza = NULL;

	Tablica_Domow[0] = CDom(37, 16, 45, pPlansza);
	Tablica_Domow[1] = CDom(37, 24, 45, pPlansza);
	Tablica_Domow[2] = CDom(37, 32, 45, pPlansza);

	Tablica_Domow[3] = CDom(45, 16, 45, pPlansza);
	Tablica_Domow[4] = CDom(45, 24, 45, pPlansza);
	Tablica_Domow[5] = CDom(45, 32, 45, pPlansza);

	Tablica_Domow[6] = CDom(11,  4, 45, pPlansza);
	Tablica_Domow[7] = CDom(11, 10, 45, pPlansza);
	Tablica_Domow[8] = CDom(11, 16, 45, pPlansza);
	Tablica_Domow[9] = CDom(11, 22, 45, pPlansza);
	

}
CGilgamesh::CGilgamesh(CPlansza* set_pPlansza)
{
	pPlansza = set_pPlansza;

	Tablica_Domow[0] = CDom(37, 16, 45, pPlansza);
	Tablica_Domow[1] = CDom(37, 24, 45, pPlansza);
	Tablica_Domow[2] = CDom(37, 32, 45, pPlansza);

	Tablica_Domow[3] = CDom(45, 16, 45, pPlansza);
	Tablica_Domow[4] = CDom(45, 24, 45, pPlansza);
	Tablica_Domow[5] = CDom(45, 32, 45, pPlansza);

	Tablica_Domow[6] = CDom(11,  4, 45, pPlansza);
	Tablica_Domow[7] = CDom(11, 10, 45, pPlansza);
	Tablica_Domow[8] = CDom(11, 16, 45, pPlansza);
	Tablica_Domow[9] = CDom(11, 22, 45, pPlansza);

	Tablica_Pol[0] = CPole(6, 6, 45, pPlansza);
	Tablica_Pol[1] = CPole(6, 12, 45, pPlansza);
	Tablica_Pol[2] = CPole(6, 18, 45, pPlansza);
	Tablica_Pol[3] = CPole(6, 24, 45, pPlansza);

	Tablica_Pol[4] = CPole(42, 95, 45, pPlansza);
	Tablica_Pol[5] = CPole(42, 91, 45, pPlansza);	
	Tablica_Pol[6] = CPole(46, 95, 45, pPlansza);
	

}

CGilgamesh::~CGilgamesh()
{
	for (int i = 0; i < 10; i++)
		Tablica_Domow[i].~CDom();

	for (int i = 0; i < 7; i++)
		Tablica_Pol[i].~CPole();

	pPlansza = NULL;

}
bool CGilgamesh::RysujMur()
{
	for (int i = 1; i < 40; i++)
		pPlansza->Plansza[31][i] = sufit;

	for (int i = 1; i < 41; i++)
		pPlansza->Plansza[30][i] = sufit;

	for (int i = 32; i < 49;i++)
		pPlansza->Plansza[i][40] = sciana;

	for (int i = 31; i < 49; i++)
		pPlansza->Plansza[i][41] = sciana;


	for (int i = 38; i < 42; i++)
		pPlansza->Plansza[i][40] = puste_pole;

	for (int i = 38; i < 42; i++)
		pPlansza->Plansza[i][41] = puste_pole;


	pPlansza->Plansza[30][13] = PrzejscieWMurze;
	pPlansza->Plansza[31][13] = PrzejscieWMurze;

	return true;
}

bool CGilgamesh::RysujPolaPrzejsc()
{
	pPlansza->Plansza[15][98].NumerZdarzenia = 24002;
	pPlansza->Podziemia[40][1].NumerZdarzenia = 21597;

	pPlansza->Plansza[32][98].NumerZdarzenia = 24320;
	pPlansza->Podziemia[43][21].NumerZdarzenia = 23297;

	pPlansza->Plansza[1][1].NumerZdarzenia = 20201;
	pPlansza->Podziemia[1][1].NumerZdarzenia = 20201;

	pPlansza->Plansza[13][92].NumerZdarzenia = 22305;
	pPlansza->Podziemia[22][5].NumerZdarzenia = 21391;

	pPlansza->Plansza[44][18].NumerZdarzenia = 24348;
	pPlansza->Podziemia[42][48].NumerZdarzenia = 24518;
	
	pPlansza->Plansza[43][4].NumerZdarzenia = 22701;
	pPlansza->Podziemia[26][1].NumerZdarzenia = 24404;

	pPlansza->Plansza[3][85].NumerZdarzenia = 22493;
	pPlansza->Podziemia[24][92].NumerZdarzenia = 20285;

	return true;
}
bool CGilgamesh::RysujPolaPrzedmiotow()
{
	pPlansza->Podziemia[10][1].NumerZdarzenia = 30001;
	pPlansza->Podziemia[10][1].SymbolPola = '*';

	pPlansza->Podziemia[22][1].NumerZdarzenia = 30002;
	pPlansza->Podziemia[22][1].SymbolPola = '*';     // potwory straznicy (trupy ?) -> pPlansza->Podziemia[24][1]  pPlansza->Podziemia[22][3]  pPlansza->Podziemia[24][4]

	pPlansza->Podziemia[6][16].NumerZdarzenia = 30003;
	pPlansza->Podziemia[6][16].SymbolPola = '*';

	return true;
}
bool CGilgamesh::RysujDrzwi()
{
	pPlansza->Podziemia[4][1].NumerZdarzenia = 50000;
	pPlansza->Podziemia[4][1].SymbolPola = '=';

	pPlansza->Podziemia[6][1].NumerZdarzenia = 50001;
	pPlansza->Podziemia[6][1].SymbolPola = '=';

	pPlansza->Podziemia[8][1].NumerZdarzenia = 50002;
	pPlansza->Podziemia[8][1].SymbolPola = '=';

	pPlansza->Podziemia[40][10].NumerZdarzenia = 50006;
	pPlansza->Podziemia[40][10].SymbolPola = '#';

	pPlansza->Podziemia[47][44].NumerZdarzenia = 50013;
	pPlansza->Podziemia[47][44].SymbolPola = '#';

	//fragmenty
	pPlansza->Podziemia[43][15].NumerZdarzenia = 50003;
	pPlansza->Podziemia[37][14].NumerZdarzenia = 50004;
	pPlansza->Podziemia[38][19].NumerZdarzenia = 50005;
	pPlansza->Podziemia[44][22].NumerZdarzenia = 50007;
	pPlansza->Plansza[32][1].NumerZdarzenia = 50008;
	pPlansza->Plansza[34][98].NumerZdarzenia = 50009;
	

	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//pPlansza->Plansza[43][98].NumerZdarzenia = 500;
	//pPlansza->Plansza[43][98].SymbolPola = '=';
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	return true;
}

bool CGilgamesh::RysujObiekty()
{
	for (int i = 0; i < 10; i++)
		Tablica_Domow[i].RysujObiekt();

	for (int i = 0; i < 7; i++)
		Tablica_Pol[i].RysujObiekt();

	RysujMur();
	RysujWiezienie(6,77);
	RysujWiezienie(6, 81);
	RysujWiezienie(6, 85);
	RysujLas();
	RysujRzeke();

	pPlansza->Plansza[48][97] = siekiera;
	pPlansza->Plansza[39][96] = kosa;
	

	RysujCmentarz();	
	RysujPodziemia();
	RysujWiezeMaga();
	RysujPolaPrzejsc();

	RysujPolaPrzedmiotow();
	RysujDrzwi();
	

	return true;
}
bool CGilgamesh::RysujWiezienie(int x, int y)
{
	for (int i = x; i > x - 3; i--)
		pPlansza->Plansza[i][y] = sciana;
	
	for (int i = x; i > x - 3; i--)
		pPlansza->Plansza[i][y+4] = sciana;

	pPlansza->Plansza[x][y + 2] = drzwi;

	pPlansza->Plansza[x][y + 1] = podloga;
	pPlansza->Plansza[x][y + 3] = podloga;

	for (int i = y + 1; i < y+4; i++)
		pPlansza->Plansza[x-3][i] = sufit;

	return true;
}
bool CGilgamesh::RysujWiezeMaga()
{
	pPlansza->Plansza[33][98] = sufit;
	pPlansza->Plansza[33][97] = sufit;
	pPlansza->Plansza[33][96] = sufit;
	pPlansza->Plansza[33][95] = sufit;
	pPlansza->Plansza[33][94] = sufit;
	pPlansza->Plansza[33][93] = sufit;
	pPlansza->Plansza[33][92] = sufit;
	pPlansza->Plansza[33][91] = sufit;
	pPlansza->Plansza[33][90] = sufit;
	pPlansza->Plansza[33][89] = sufit;
	pPlansza->Plansza[28][93] = sufit;
	pPlansza->Plansza[28][94] = sufit;
	pPlansza->Plansza[28][95] = sufit;
	pPlansza->Plansza[28][96] = sufit;
	pPlansza->Plansza[28][97] = sufit;
	pPlansza->Plansza[28][98] = sufit;
	pPlansza->Plansza[29][92] = sufit;
	pPlansza->Plansza[29][91] = sufit;
	pPlansza->Plansza[31][89] = sufit;
	pPlansza->Plansza[30][90] = sciana;
	pPlansza->Plansza[29][92] = sciana;
	pPlansza->Plansza[29][91] = podloga;
	pPlansza->Plansza[31][98] = sufit;
	pPlansza->Plansza[31][97] = sufit;
	pPlansza->Plansza[31][96] = sufit;
	pPlansza->Plansza[32][94] = sciana;
	pPlansza->Plansza[31][94] = sciana;


	pPlansza->Plansza[32][89].NumerZdarzenia = 1;
	pPlansza->Plansza[32][89].SymbolPola = '#';

	

	return true;
}
bool CGilgamesh::RysujLas()
{
	pPlansza->Plansza[15][52] = drzewo;
	pPlansza->Plansza[15][54] = drzewo;
	pPlansza->Plansza[17][56] = drzewo;
	pPlansza->Plansza[16][58] = drzewo;
	pPlansza->Plansza[18][61] = drzewo;
	pPlansza->Plansza[20][60] = drzewo;
	pPlansza->Plansza[21][57] = drzewo;
	pPlansza->Plansza[20][52] = drzewo;
	pPlansza->Plansza[17][49] = drzewo;
	pPlansza->Plansza[18][53] = drzewo;
	pPlansza->Plansza[16][65] = drzewo;
	pPlansza->Plansza[15][62] = drzewo;
	pPlansza->Plansza[19][65] = drzewo;
	pPlansza->Plansza[21][63] = drzewo;
	pPlansza->Plansza[23][68] = drzewo;
	pPlansza->Plansza[21][71] = drzewo;
	pPlansza->Plansza[24][73] = drzewo;
	pPlansza->Plansza[22][76] = drzewo;
	pPlansza->Plansza[23][78] = drzewo;
	pPlansza->Plansza[27][70] = drzewo;
	pPlansza->Plansza[25][67] = drzewo;
	pPlansza->Plansza[25][70] = drzewo;
	pPlansza->Plansza[26][75] = drzewo;
	pPlansza->Plansza[28][67] = drzewo;
	pPlansza->Plansza[23][60] = drzewo;
	pPlansza->Plansza[26][55] = drzewo;
	pPlansza->Plansza[27][53] = drzewo;
	pPlansza->Plansza[28][51] = drzewo;
	pPlansza->Plansza[26][48] = drzewo;
	pPlansza->Plansza[26][51] = drzewo;
	pPlansza->Plansza[23][45] = drzewo;
	pPlansza->Plansza[24][47] = drzewo;
	pPlansza->Plansza[25][44] = drzewo;
	pPlansza->Plansza[28][44] = drzewo;
	pPlansza->Plansza[27][46] = drzewo;
	pPlansza->Plansza[30][50] = drzewo;
	pPlansza->Plansza[31][52] = drzewo;
	pPlansza->Plansza[30][55] = drzewo;
	pPlansza->Plansza[48][49] = drzewo;
	pPlansza->Plansza[47][51] = drzewo;
	pPlansza->Plansza[47][54] = drzewo;
	pPlansza->Plansza[48][56] = drzewo;
	pPlansza->Plansza[46][58] = drzewo;
	pPlansza->Plansza[45][54] = drzewo;
	pPlansza->Plansza[24][36] = drzewo;
	pPlansza->Plansza[24][38] = drzewo;
	pPlansza->Plansza[24][40] = drzewo;
	pPlansza->Plansza[26][40] = drzewo;
	pPlansza->Plansza[26][38] = drzewo;
	pPlansza->Plansza[26][36] = drzewo;
	pPlansza->Plansza[5][57] = drzewo;
	pPlansza->Plansza[4][59] = drzewo;
	pPlansza->Plansza[6][63] = drzewo;
	pPlansza->Plansza[8][63] = drzewo;
	pPlansza->Plansza[7][60] = drzewo;
	pPlansza->Plansza[9][56] = drzewo;
	pPlansza->Plansza[9][60] = drzewo;
	pPlansza->Plansza[4][52] = drzewo;
	pPlansza->Plansza[5][49] = drzewo;
	pPlansza->Plansza[6][46] = drzewo;
	pPlansza->Plansza[8][48] = drzewo;
	pPlansza->Plansza[4][46] = drzewo;
	pPlansza->Plansza[8][42] = drzewo;
	pPlansza->Plansza[9][44] = drzewo;
	pPlansza->Plansza[21][1] = drzewo;
	pPlansza->Plansza[20][4] = drzewo;
	pPlansza->Plansza[22][7] = drzewo;
	pPlansza->Plansza[22][4] = drzewo;
	pPlansza->Plansza[25][3] = drzewo;
	pPlansza->Plansza[25][6] = drzewo;
	pPlansza->Plansza[20][10] = drzewo;
	pPlansza->Plansza[24][10] = drzewo;
	pPlansza->Plansza[48][83] = drzewo;
	pPlansza->Plansza[46][85] = drzewo;
	pPlansza->Plansza[45][87] = drzewo;
	pPlansza->Plansza[47][88] = drzewo;
	pPlansza->Plansza[48][91] = drzewo;
	pPlansza->Plansza[44][80] = drzewo;
	pPlansza->Plansza[46][79] = drzewo;
	pPlansza->Plansza[46][82] = drzewo;

	pPlansza->Plansza[38][95] = pola;
	pPlansza->Plansza[38][96] = pola;
	pPlansza->Plansza[38][97] = pola;
	pPlansza->Plansza[38][98] = pola;
	pPlansza->Plansza[37][95] = pola;
	pPlansza->Plansza[38][94] = pola;
	pPlansza->Plansza[36][96] = pola;
	pPlansza->Plansza[37][96] = pola;
	pPlansza->Plansza[37][97] = pola;
	pPlansza->Plansza[37][98] = pola;
	pPlansza->Plansza[36][97] = pola;
	pPlansza->Plansza[36][98] = pola;
	pPlansza->Plansza[40][90] = pola;
	pPlansza->Plansza[41][90] = pola;
	pPlansza->Plansza[41][89] = pola;
	pPlansza->Plansza[42][90] = pola;
	pPlansza->Plansza[43][91] = pola;
	pPlansza->Plansza[43][92] = pola;
	pPlansza->Plansza[43][93] = pola;
	pPlansza->Plansza[43][94] = pola;
	pPlansza->Plansza[44][91] = pola;
	pPlansza->Plansza[44][92] = pola;
	pPlansza->Plansza[44][93] = pola;
	pPlansza->Plansza[44][94] = pola;
	pPlansza->Plansza[45][93] = pola;
	pPlansza->Plansza[45][94] = pola;





	return true;
}
bool CGilgamesh::RysujRzeke()
{
	pPlansza->Plansza[48][68] = rzeka;
	pPlansza->Plansza[48][69] = rzeka;
	pPlansza->Plansza[48][70] = rzeka;
	pPlansza->Plansza[48][71] = rzeka;
	pPlansza->Plansza[48][72] = rzeka;
	pPlansza->Plansza[48][73] = rzeka;
	pPlansza->Plansza[48][74] = rzeka;
	pPlansza->Plansza[48][75] = rzeka;
	pPlansza->Plansza[47][69] = rzeka;
	pPlansza->Plansza[47][70] = rzeka;
	pPlansza->Plansza[47][71] = rzeka;
	pPlansza->Plansza[47][72] = rzeka;
	pPlansza->Plansza[47][73] = rzeka;
	pPlansza->Plansza[47][74] = rzeka;
	pPlansza->Plansza[47][75] = rzeka;
	pPlansza->Plansza[47][76] = rzeka;
	pPlansza->Plansza[46][70] = rzeka;
	pPlansza->Plansza[46][71] = rzeka;
	pPlansza->Plansza[46][72] = rzeka;
	pPlansza->Plansza[46][73] = rzeka;
	pPlansza->Plansza[46][74] = rzeka;
	pPlansza->Plansza[46][75] = rzeka;
	pPlansza->Plansza[46][76] = rzeka;
	pPlansza->Plansza[45][69] = rzeka;
	pPlansza->Plansza[45][70] = rzeka;
	pPlansza->Plansza[45][71] = rzeka;
	pPlansza->Plansza[45][72] = rzeka;
	pPlansza->Plansza[45][73] = rzeka;
	pPlansza->Plansza[45][74] = rzeka;
	pPlansza->Plansza[45][75] = rzeka;
	pPlansza->Plansza[44][68] = rzeka;
	pPlansza->Plansza[44][69] = rzeka;
	pPlansza->Plansza[44][70] = rzeka;
	pPlansza->Plansza[44][71] = rzeka;
	pPlansza->Plansza[44][72] = rzeka;
	pPlansza->Plansza[44][73] = rzeka;
	pPlansza->Plansza[44][74] = rzeka;
	pPlansza->Plansza[43][69] = rzeka;
	pPlansza->Plansza[43][70] = rzeka;
	pPlansza->Plansza[43][71] = rzeka;
	pPlansza->Plansza[43][72] = rzeka;
	pPlansza->Plansza[43][73] = rzeka;
	pPlansza->Plansza[43][74] = rzeka;
	pPlansza->Plansza[43][75] = rzeka;
	pPlansza->Plansza[43][76] = rzeka;
	pPlansza->Plansza[42][71] = rzeka;
	pPlansza->Plansza[42][72] = rzeka;
	pPlansza->Plansza[42][73] = rzeka;
	pPlansza->Plansza[42][74] = rzeka;
	pPlansza->Plansza[42][75] = rzeka;
	pPlansza->Plansza[42][76] = rzeka;
	pPlansza->Plansza[42][77] = rzeka;
	pPlansza->Plansza[41][71] = rzeka;
	pPlansza->Plansza[41][72] = rzeka;
	pPlansza->Plansza[41][73] = rzeka;
	pPlansza->Plansza[41][74] = rzeka;
	pPlansza->Plansza[41][75] = rzeka;
	pPlansza->Plansza[41][76] = rzeka;
	pPlansza->Plansza[41][77] = rzeka;
	pPlansza->Plansza[40][72] = rzeka;
	pPlansza->Plansza[40][73] = rzeka;
	pPlansza->Plansza[40][74] = rzeka;
	pPlansza->Plansza[40][75] = rzeka;
	pPlansza->Plansza[40][76] = rzeka;
	pPlansza->Plansza[40][77] = rzeka;
	pPlansza->Plansza[40][78] = rzeka;
	pPlansza->Plansza[40][79] = rzeka;
	pPlansza->Plansza[39][73] = rzeka;
	pPlansza->Plansza[39][74] = rzeka;
	pPlansza->Plansza[39][75] = rzeka;
	pPlansza->Plansza[39][76] = rzeka;
	pPlansza->Plansza[39][77] = rzeka;
	pPlansza->Plansza[39][78] = rzeka;
	pPlansza->Plansza[39][79] = rzeka;
	pPlansza->Plansza[39][80] = rzeka;
	pPlansza->Plansza[38][74] = rzeka;
	pPlansza->Plansza[38][75] = rzeka;
	pPlansza->Plansza[38][76] = rzeka;
	pPlansza->Plansza[38][77] = rzeka;
	pPlansza->Plansza[38][78] = rzeka;
	pPlansza->Plansza[38][79] = rzeka;
	pPlansza->Plansza[38][80] = rzeka;
	pPlansza->Plansza[37][75] = rzeka;
	pPlansza->Plansza[37][76] = rzeka;
	pPlansza->Plansza[37][77] = rzeka;
	pPlansza->Plansza[37][78] = rzeka;
	pPlansza->Plansza[37][79] = rzeka;
	pPlansza->Plansza[37][80] = rzeka;
	pPlansza->Plansza[37][81] = rzeka;
	pPlansza->Plansza[36][74] = rzeka;
	pPlansza->Plansza[36][75] = rzeka;
	pPlansza->Plansza[36][76] = rzeka;
	pPlansza->Plansza[36][77] = rzeka;
	pPlansza->Plansza[36][78] = rzeka;
	pPlansza->Plansza[36][79] = rzeka;
	pPlansza->Plansza[36][80] = rzeka;
	pPlansza->Plansza[35][74] = rzeka;
	pPlansza->Plansza[35][75] = rzeka;
	pPlansza->Plansza[35][76] = rzeka;
	pPlansza->Plansza[35][77] = rzeka;
	pPlansza->Plansza[35][78] = rzeka;
	pPlansza->Plansza[35][79] = rzeka;
	pPlansza->Plansza[35][80] = rzeka;
	pPlansza->Plansza[34][75] = rzeka;
	pPlansza->Plansza[34][76] = rzeka;
	pPlansza->Plansza[34][77] = rzeka;
	pPlansza->Plansza[34][78] = rzeka;
	pPlansza->Plansza[34][79] = rzeka;
	pPlansza->Plansza[34][80] = rzeka;
	pPlansza->Plansza[34][81] = rzeka;
	pPlansza->Plansza[34][82] = rzeka;
	pPlansza->Plansza[33][76] = rzeka;
	pPlansza->Plansza[33][77] = rzeka;
	pPlansza->Plansza[33][78] = rzeka;
	pPlansza->Plansza[33][79] = rzeka;
	pPlansza->Plansza[33][80] = rzeka;
	pPlansza->Plansza[33][81] = rzeka;
	pPlansza->Plansza[33][82] = rzeka;
	pPlansza->Plansza[33][83] = rzeka;
	pPlansza->Plansza[33][84] = rzeka;
	pPlansza->Plansza[32][77] = rzeka;
	pPlansza->Plansza[32][78] = rzeka;
	pPlansza->Plansza[32][79] = rzeka;
	pPlansza->Plansza[32][80] = rzeka;
	pPlansza->Plansza[32][81] = rzeka;
	pPlansza->Plansza[32][82] = rzeka;
	pPlansza->Plansza[32][83] = rzeka;
	pPlansza->Plansza[32][84] = rzeka;
	pPlansza->Plansza[32][85] = rzeka;
	pPlansza->Plansza[31][78] = rzeka;
	pPlansza->Plansza[31][79] = rzeka;
	pPlansza->Plansza[31][80] = rzeka;
	pPlansza->Plansza[31][81] = rzeka;
	pPlansza->Plansza[31][82] = rzeka;
	pPlansza->Plansza[31][83] = rzeka;
	pPlansza->Plansza[31][84] = rzeka;
	pPlansza->Plansza[31][85] = rzeka;
	pPlansza->Plansza[30][80] = rzeka;
	pPlansza->Plansza[29][81] = rzeka;
	pPlansza->Plansza[30][81] = rzeka;
	pPlansza->Plansza[30][82] = rzeka;
	pPlansza->Plansza[29][82] = rzeka;
	pPlansza->Plansza[29][83] = rzeka;
	pPlansza->Plansza[29][84] = rzeka;
	pPlansza->Plansza[29][85] = rzeka;
	pPlansza->Plansza[29][86] = rzeka;
	pPlansza->Plansza[30][83] = rzeka;
	pPlansza->Plansza[30][84] = rzeka;
	pPlansza->Plansza[30][85] = rzeka;
	pPlansza->Plansza[30][86] = rzeka;
	pPlansza->Plansza[30][87] = rzeka;
	pPlansza->Plansza[29][87] = rzeka;
	pPlansza->Plansza[29][88] = rzeka;
	pPlansza->Plansza[29][89] = rzeka;
	pPlansza->Plansza[29][90] = rzeka;
	pPlansza->Plansza[31][86] = rzeka;
	pPlansza->Plansza[31][87] = rzeka;
	pPlansza->Plansza[31][88] = rzeka;
	pPlansza->Plansza[28][88] = rzeka;
	pPlansza->Plansza[28][89] = rzeka;
	pPlansza->Plansza[28][90] = rzeka;
	pPlansza->Plansza[28][91] = rzeka;
	pPlansza->Plansza[27][89] = rzeka;
	pPlansza->Plansza[27][90] = rzeka;
	pPlansza->Plansza[27][91] = rzeka;
	pPlansza->Plansza[27][92] = rzeka;
	pPlansza->Plansza[28][86] = rzeka;
	pPlansza->Plansza[27][87] = rzeka;
	pPlansza->Plansza[26][90] = rzeka;
	pPlansza->Plansza[26][91] = rzeka;
	pPlansza->Plansza[26][92] = rzeka;
	pPlansza->Plansza[26][93] = rzeka;
	pPlansza->Plansza[26][94] = rzeka;
	pPlansza->Plansza[26][95] = rzeka;
	pPlansza->Plansza[26][96] = rzeka;
	pPlansza->Plansza[26][97] = rzeka;
	pPlansza->Plansza[26][98] = rzeka;
	pPlansza->Plansza[27][93] = rzeka;
	pPlansza->Plansza[27][94] = rzeka;
	pPlansza->Plansza[27][95] = rzeka;
	pPlansza->Plansza[27][96] = rzeka;
	pPlansza->Plansza[27][97] = rzeka;
	pPlansza->Plansza[28][92] = rzeka;
	pPlansza->Plansza[27][98] = rzeka;
	pPlansza->Plansza[25][94] = rzeka;
	pPlansza->Plansza[25][95] = rzeka;
	pPlansza->Plansza[25][96] = rzeka;
	pPlansza->Plansza[25][97] = rzeka;
	pPlansza->Plansza[25][93] = rzeka;
	pPlansza->Plansza[24][93] = rzeka;
	pPlansza->Plansza[24][94] = rzeka;
	pPlansza->Plansza[24][95] = rzeka;
	pPlansza->Plansza[24][96] = rzeka;
	pPlansza->Plansza[24][97] = rzeka;
	pPlansza->Plansza[23][95] = rzeka;
	pPlansza->Plansza[23][96] = rzeka;
	pPlansza->Plansza[23][97] = rzeka;
	pPlansza->Plansza[22][97] = rzeka;
	pPlansza->Plansza[27][88] = rzeka;
	pPlansza->Plansza[25][98] = rzeka;
	pPlansza->Plansza[25][90] = rzeka;
	pPlansza->Plansza[24][98] = rzeka;
	pPlansza->Plansza[23][98] = rzeka;
	pPlansza->Plansza[22][98] = rzeka;
	pPlansza->Plansza[28][88] = rzeka;
	pPlansza->Plansza[23][96] = rzeka;
	pPlansza->Plansza[23][97] = rzeka;
	pPlansza->Plansza[22][97] = rzeka;
	pPlansza->Plansza[25][91] = rzeka;
	pPlansza->Plansza[25][92] = rzeka;
	pPlansza->Plansza[28][87] = rzeka;



	return true;
}

bool CGilgamesh::RysujPodziemia()
{
	// las
	{
		pPlansza->Podziemia[35][98] = drzewo;
		pPlansza->Podziemia[35][97] = drzewo;
		pPlansza->Podziemia[35][96] = drzewo;
		pPlansza->Podziemia[35][95] = drzewo;
		pPlansza->Podziemia[35][94] = drzewo;
		pPlansza->Podziemia[35][93] = drzewo;
		pPlansza->Podziemia[35][92] = drzewo;
		pPlansza->Podziemia[35][91] = drzewo;
		pPlansza->Podziemia[35][90] = drzewo;
		pPlansza->Podziemia[35][89] = drzewo;
		pPlansza->Podziemia[35][88] = drzewo;
		pPlansza->Podziemia[35][87] = drzewo;
		pPlansza->Podziemia[35][86] = drzewo;
		pPlansza->Podziemia[35][85] = drzewo;
		pPlansza->Podziemia[35][84] = drzewo;
		pPlansza->Podziemia[35][83] = drzewo;
		pPlansza->Podziemia[35][82] = drzewo;
		pPlansza->Podziemia[35][81] = drzewo;
		pPlansza->Podziemia[35][80] = drzewo;
		pPlansza->Podziemia[35][79] = drzewo;
		pPlansza->Podziemia[34][79] = drzewo;
		pPlansza->Podziemia[33][79] = drzewo;
		pPlansza->Podziemia[32][79] = drzewo;
		pPlansza->Podziemia[31][79] = drzewo;
		pPlansza->Podziemia[31][78] = drzewo;
		pPlansza->Podziemia[31][77] = drzewo;
		pPlansza->Podziemia[31][76] = drzewo;
		pPlansza->Podziemia[31][75] = drzewo;
		pPlansza->Podziemia[31][74] = drzewo;
		pPlansza->Podziemia[31][73] = drzewo;
		pPlansza->Podziemia[31][72] = drzewo;
		pPlansza->Podziemia[31][71] = drzewo;
		pPlansza->Podziemia[31][70] = drzewo;
		pPlansza->Podziemia[32][70] = drzewo;
		pPlansza->Podziemia[33][70] = drzewo;
		pPlansza->Podziemia[34][70] = drzewo;
		pPlansza->Podziemia[35][70] = drzewo;
		pPlansza->Podziemia[35][69] = drzewo;
		pPlansza->Podziemia[35][68] = drzewo;
		pPlansza->Podziemia[35][67] = drzewo;
		pPlansza->Podziemia[35][66] = drzewo;
		pPlansza->Podziemia[35][65] = drzewo;
		pPlansza->Podziemia[35][64] = drzewo;
		pPlansza->Podziemia[32][71] = drzewo;
		pPlansza->Podziemia[33][72] = drzewo;
		pPlansza->Podziemia[34][75] = drzewo;
		pPlansza->Podziemia[32][78] = drzewo;
		pPlansza->Podziemia[33][78] = drzewo;
		pPlansza->Podziemia[33][77] = drzewo;
		pPlansza->Podziemia[32][77] = drzewo;
		pPlansza->Podziemia[32][73] = drzewo;
		pPlansza->Podziemia[35][63] = drzewo;
		pPlansza->Podziemia[35][62] = drzewo;
		pPlansza->Podziemia[34][98] = drzewo;
		pPlansza->Podziemia[34][98] = drzewo;
		pPlansza->Podziemia[34][98] = drzewo;
		pPlansza->Podziemia[34][97] = drzewo;
		pPlansza->Podziemia[34][96] = drzewo;
		pPlansza->Podziemia[34][95] = drzewo;
		pPlansza->Podziemia[34][94] = drzewo;
		pPlansza->Podziemia[34][93] = drzewo;
		pPlansza->Podziemia[34][92] = drzewo;
		pPlansza->Podziemia[34][91] = drzewo;
		pPlansza->Podziemia[34][90] = drzewo;
		pPlansza->Podziemia[34][89] = drzewo;
		pPlansza->Podziemia[34][88] = drzewo;
		pPlansza->Podziemia[34][87] = drzewo;
		pPlansza->Podziemia[34][87] = drzewo;
		pPlansza->Podziemia[34][86] = drzewo;
		pPlansza->Podziemia[34][85] = drzewo;
		pPlansza->Podziemia[34][84] = drzewo;
		pPlansza->Podziemia[34][83] = drzewo;
		pPlansza->Podziemia[34][82] = drzewo;
		pPlansza->Podziemia[34][81] = drzewo;
		pPlansza->Podziemia[34][80] = drzewo;
		pPlansza->Podziemia[33][80] = drzewo;
		pPlansza->Podziemia[33][81] = drzewo;
		pPlansza->Podziemia[33][82] = drzewo;
		pPlansza->Podziemia[33][83] = drzewo;
		pPlansza->Podziemia[33][84] = drzewo;
		pPlansza->Podziemia[33][85] = drzewo;
		pPlansza->Podziemia[33][86] = drzewo;
		pPlansza->Podziemia[33][87] = drzewo;
		pPlansza->Podziemia[33][88] = drzewo;
		pPlansza->Podziemia[33][89] = drzewo;
		pPlansza->Podziemia[33][90] = drzewo;
		pPlansza->Podziemia[33][91] = drzewo;
		pPlansza->Podziemia[33][92] = drzewo;
		pPlansza->Podziemia[33][93] = drzewo;
		pPlansza->Podziemia[33][94] = drzewo;
		pPlansza->Podziemia[33][95] = drzewo;
		pPlansza->Podziemia[33][96] = drzewo;
		pPlansza->Podziemia[33][97] = drzewo;
		pPlansza->Podziemia[33][98] = drzewo;
		pPlansza->Podziemia[32][80] = drzewo;
		pPlansza->Podziemia[32][80] = drzewo;
		pPlansza->Podziemia[30][79] = drzewo;
		pPlansza->Podziemia[30][78] = drzewo;
		pPlansza->Podziemia[31][80] = drzewo;
		pPlansza->Podziemia[32][81] = drzewo;
		pPlansza->Podziemia[31][82] = drzewo;
		pPlansza->Podziemia[31][81] = drzewo;
		pPlansza->Podziemia[31][81] = drzewo;
		pPlansza->Podziemia[30][80] = drzewo;
		pPlansza->Podziemia[30][81] = drzewo;
		pPlansza->Podziemia[30][82] = drzewo;
		pPlansza->Podziemia[32][82] = drzewo;
		pPlansza->Podziemia[32][83] = drzewo;
		pPlansza->Podziemia[31][83] = drzewo;
		pPlansza->Podziemia[31][83] = drzewo;
		pPlansza->Podziemia[30][83] = drzewo;
		pPlansza->Podziemia[34][63] = drzewo;
		pPlansza->Podziemia[34][64] = drzewo;
		pPlansza->Podziemia[34][65] = drzewo;
		pPlansza->Podziemia[34][66] = drzewo;
		pPlansza->Podziemia[34][67] = drzewo;
		pPlansza->Podziemia[34][68] = drzewo;
		pPlansza->Podziemia[34][69] = drzewo;
		pPlansza->Podziemia[33][69] = drzewo;
		pPlansza->Podziemia[32][69] = drzewo;
		pPlansza->Podziemia[33][68] = drzewo;
		pPlansza->Podziemia[33][67] = drzewo;
		pPlansza->Podziemia[32][68] = drzewo;
		pPlansza->Podziemia[31][69] = drzewo;
		pPlansza->Podziemia[30][70] = drzewo;
		pPlansza->Podziemia[30][71] = drzewo;
		pPlansza->Podziemia[30][72] = drzewo;
		pPlansza->Podziemia[30][73] = drzewo;
		pPlansza->Podziemia[30][74] = drzewo;
		pPlansza->Podziemia[30][75] = drzewo;
		pPlansza->Podziemia[30][76] = drzewo;
		pPlansza->Podziemia[30][77] = drzewo;
		pPlansza->Podziemia[33][63] = drzewo;
		pPlansza->Podziemia[33][64] = drzewo;
		pPlansza->Podziemia[33][65] = drzewo;
		pPlansza->Podziemia[31][65] = drzewo;
		pPlansza->Podziemia[32][66] = drzewo;
		pPlansza->Podziemia[32][65] = drzewo;
		pPlansza->Podziemia[32][65] = drzewo;
		pPlansza->Podziemia[32][64] = drzewo;
		pPlansza->Podziemia[30][67] = drzewo;
		pPlansza->Podziemia[31][67] = drzewo;
		pPlansza->Podziemia[31][66] = drzewo;
		pPlansza->Podziemia[30][68] = drzewo;
		pPlansza->Podziemia[30][69] = drzewo;
		pPlansza->Podziemia[32][98] = drzewo;
		pPlansza->Podziemia[31][97] = drzewo;
		pPlansza->Podziemia[32][97] = drzewo;
		pPlansza->Podziemia[31][95] = drzewo;
		pPlansza->Podziemia[32][96] = drzewo;
		pPlansza->Podziemia[32][94] = drzewo;
		pPlansza->Podziemia[31][93] = drzewo;
		pPlansza->Podziemia[31][94] = drzewo;
		pPlansza->Podziemia[30][95] = drzewo;
		pPlansza->Podziemia[30][96] = drzewo;
		pPlansza->Podziemia[30][97] = drzewo;
		pPlansza->Podziemia[31][92] = drzewo;
		pPlansza->Podziemia[32][91] = drzewo;
		pPlansza->Podziemia[31][89] = drzewo;
		pPlansza->Podziemia[31][90] = drzewo;
		pPlansza->Podziemia[30][88] = drzewo;
		pPlansza->Podziemia[31][87] = drzewo;
		pPlansza->Podziemia[31][85] = drzewo;
		pPlansza->Podziemia[30][86] = drzewo;
		pPlansza->Podziemia[30][85] = drzewo;
		pPlansza->Podziemia[30][84] = drzewo;
		pPlansza->Podziemia[32][84] = drzewo;
		pPlansza->Podziemia[32][90] = drzewo;
		pPlansza->Podziemia[32][89] = drzewo;
		pPlansza->Podziemia[32][85] = drzewo;
		pPlansza->Podziemia[29][81] = drzewo;
		pPlansza->Podziemia[28][82] = drzewo;
		pPlansza->Podziemia[28][83] = drzewo;
		pPlansza->Podziemia[29][84] = drzewo;
		pPlansza->Podziemia[28][80] = drzewo;
		pPlansza->Podziemia[29][78] = drzewo;
		pPlansza->Podziemia[28][76] = drzewo;
		pPlansza->Podziemia[29][74] = drzewo;
		pPlansza->Podziemia[27][74] = drzewo;
		pPlansza->Podziemia[28][78] = drzewo;
		pPlansza->Podziemia[27][76] = drzewo;
		pPlansza->Podziemia[27][78] = drzewo;
		pPlansza->Podziemia[27][77] = drzewo;
		pPlansza->Podziemia[27][77] = drzewo;
		pPlansza->Podziemia[29][71] = drzewo;
		pPlansza->Podziemia[28][72] = drzewo;
		pPlansza->Podziemia[28][73] = drzewo;
		pPlansza->Podziemia[28][69] = drzewo;
		pPlansza->Podziemia[29][70] = drzewo;
		pPlansza->Podziemia[29][69] = drzewo;
		pPlansza->Podziemia[29][68] = drzewo;
	
	} // las

	pPlansza->Podziemia[34][75] = DrzewoZSiekera;
	pPlansza->Podziemia[41][20] = PoleAriaDoor;


	//pola	

	for (int i = 36; i <= 48; i++)
		for (int j = 82; j <= 98; j++)
			pPlansza->Podziemia[i][j] = pola;

	for (int i = 41; i <= 48; i++)
		for (int j = 62; j <= 81; j++)	
			pPlansza->Podziemia[i][j] = pola;

	{
	pPlansza->Podziemia[37][81] = pola;
	pPlansza->Podziemia[38][80] = pola;
	pPlansza->Podziemia[39][80] = pola;
	pPlansza->Podziemia[40][79] = pola;
	pPlansza->Podziemia[40][78] = pola;
	pPlansza->Podziemia[36][64] = pola;
	pPlansza->Podziemia[37][65] = pola;
	pPlansza->Podziemia[37][66] = pola;
	pPlansza->Podziemia[38][66] = pola;
	pPlansza->Podziemia[39][67] = pola;
	pPlansza->Podziemia[39][68] = pola;
	pPlansza->Podziemia[39][69] = pola;
	pPlansza->Podziemia[40][70] = pola;
	pPlansza->Podziemia[40][69] = pola;
	pPlansza->Podziemia[40][68] = pola;
	pPlansza->Podziemia[40][67] = pola;
	pPlansza->Podziemia[40][66] = pola;
	pPlansza->Podziemia[39][66] = pola;
	pPlansza->Podziemia[38][81] = pola;
	pPlansza->Podziemia[39][81] = pola;
	pPlansza->Podziemia[40][81] = pola;
	pPlansza->Podziemia[40][80] = pola;
	pPlansza->Podziemia[36][65] = pola;
	pPlansza->Podziemia[38][65] = pola;
	pPlansza->Podziemia[39][65] = pola;
	pPlansza->Podziemia[40][65] = pola;
	pPlansza->Podziemia[40][64] = pola;
	pPlansza->Podziemia[40][63] = pola;
	pPlansza->Podziemia[36][62] = pola;
	pPlansza->Podziemia[36][63] = pola;
	pPlansza->Podziemia[37][63] = pola;
	pPlansza->Podziemia[38][64] = pola;
	pPlansza->Podziemia[37][62] = pola;
	pPlansza->Podziemia[39][64] = pola;
	pPlansza->Podziemia[37][64] = pola;

	}

	// pod wieza maga przejscia
	{
		pPlansza->Podziemia[41][4] = sufit;
		pPlansza->Podziemia[41][5] = sufit;
		pPlansza->Podziemia[41][6] = sufit;
		pPlansza->Podziemia[41][7] = sufit;
		pPlansza->Podziemia[41][8] = sufit;
pPlansza->Podziemia[39][4] = sufit;
pPlansza->Podziemia[39][5] = sufit;
pPlansza->Podziemia[39][6] = sufit;
pPlansza->Podziemia[39][7] = sufit;
pPlansza->Podziemia[39][8] = sufit;
pPlansza->Podziemia[43][2] = sufit;
pPlansza->Podziemia[43][1] = sufit;
pPlansza->Podziemia[37][2] = sufit;
pPlansza->Podziemia[37][1] = sufit;
pPlansza->Podziemia[39][9] = sufit;
pPlansza->Podziemia[41][9] = sufit;
pPlansza->Podziemia[46][11] = sufit;
pPlansza->Podziemia[46][12] = sufit;
pPlansza->Podziemia[46][13] = sufit;
pPlansza->Podziemia[46][14] = sufit;
pPlansza->Podziemia[46][15] = sufit;
pPlansza->Podziemia[46][16] = sufit;
pPlansza->Podziemia[34][11] = sufit;
pPlansza->Podziemia[34][12] = sufit;
pPlansza->Podziemia[34][13] = sufit;
pPlansza->Podziemia[34][14] = sufit;
pPlansza->Podziemia[34][15] = sufit;
pPlansza->Podziemia[34][16] = sufit;
pPlansza->Podziemia[44][13] = sufit;
pPlansza->Podziemia[44][14] = sufit;
pPlansza->Podziemia[44][15] = sufit;
pPlansza->Podziemia[41][13] = sufit;
pPlansza->Podziemia[41][15] = sufit;
pPlansza->Podziemia[39][13] = sufit;
pPlansza->Podziemia[39][15] = sufit;
pPlansza->Podziemia[36][14] = sufit;
pPlansza->Podziemia[36][15] = sufit;
pPlansza->Podziemia[36][13] = sufit;
pPlansza->Podziemia[39][19] = sufit;
pPlansza->Podziemia[39][21] = sufit;
pPlansza->Podziemia[36][20] = sufit;
pPlansza->Podziemia[36][19] = sufit;
pPlansza->Podziemia[36][21] = sufit;
pPlansza->Podziemia[41][19] = sufit;
pPlansza->Podziemia[41][21] = sufit;
pPlansza->Podziemia[44][20] = sufit;
pPlansza->Podziemia[44][19] = sufit;
pPlansza->Podziemia[44][21] = sufit;
pPlansza->Podziemia[46][17] = sufit;
pPlansza->Podziemia[46][18] = sufit;
pPlansza->Podziemia[46][19] = sufit;
pPlansza->Podziemia[46][20] = sufit;
pPlansza->Podziemia[46][21] = sufit;
pPlansza->Podziemia[46][22] = sufit;
pPlansza->Podziemia[46][23] = sufit;
pPlansza->Podziemia[34][17] = sufit;
pPlansza->Podziemia[34][18] = sufit;
pPlansza->Podziemia[34][19] = sufit;
pPlansza->Podziemia[34][20] = sufit;
pPlansza->Podziemia[34][21] = sufit;
pPlansza->Podziemia[34][23] = sufit;
pPlansza->Podziemia[34][22] = sufit;

pPlansza->Podziemia[38][3] = sciana;
pPlansza->Podziemia[42][3] = sciana;
pPlansza->Podziemia[35][10] = sciana;
pPlansza->Podziemia[38][10] = sciana;
pPlansza->Podziemia[37][10] = sciana;
pPlansza->Podziemia[36][10] = sciana;
pPlansza->Podziemia[42][10] = sciana;
pPlansza->Podziemia[43][10] = sciana;
pPlansza->Podziemia[44][10] = sciana;
pPlansza->Podziemia[45][10] = sciana;
pPlansza->Podziemia[37][12] = sciana;
pPlansza->Podziemia[38][12] = sciana;
pPlansza->Podziemia[38][16] = sciana;
pPlansza->Podziemia[37][16] = sciana;
pPlansza->Podziemia[37][18] = sciana;
pPlansza->Podziemia[38][18] = sciana;
pPlansza->Podziemia[38][22] = sciana;
pPlansza->Podziemia[37][22] = sciana;
pPlansza->Podziemia[42][22] = sciana;
pPlansza->Podziemia[43][22] = sciana;
pPlansza->Podziemia[43][18] = sciana;
pPlansza->Podziemia[42][18] = sciana;
pPlansza->Podziemia[42][16] = sciana;
pPlansza->Podziemia[43][16] = sciana;
pPlansza->Podziemia[43][12] = sciana;
pPlansza->Podziemia[42][12] = sciana;
pPlansza->Podziemia[45][24] = sciana;
pPlansza->Podziemia[44][24] = sciana;
pPlansza->Podziemia[43][24] = sciana;
pPlansza->Podziemia[42][24] = sciana;
pPlansza->Podziemia[41][24] = sciana;
pPlansza->Podziemia[40][24] = sciana;
pPlansza->Podziemia[39][24] = sciana;
pPlansza->Podziemia[38][24] = sciana;
pPlansza->Podziemia[37][24] = sciana;
pPlansza->Podziemia[36][24] = sciana;
pPlansza->Podziemia[35][24] = sciana;

pPlansza->Podziemia[34][17].NumerZdarzenia = 50010;
pPlansza->Podziemia[46][17].NumerZdarzenia = 50011;
pPlansza->Podziemia[40][24].NumerZdarzenia = 50012;

	}

	// bron na zagramistrza
	{
		pPlansza->Podziemia[1][2] = sciana;
		pPlansza->Podziemia[2][2] = sciana;
		pPlansza->Podziemia[3][2] = sciana;
		pPlansza->Podziemia[4][2] = sciana;
		pPlansza->Podziemia[5][2] = sciana;
		pPlansza->Podziemia[6][2] = sciana;
		pPlansza->Podziemia[7][2] = sciana;
		pPlansza->Podziemia[8][2] = sciana;
		pPlansza->Podziemia[11][2] = sciana;
		pPlansza->Podziemia[10][2] = sciana;
		pPlansza->Podziemia[9][2] = sciana;
		pPlansza->Podziemia[11][1] = podloga;
		pPlansza->Podziemia[0][0] = sciana; // !!!! MIECZ !!!

	}
	{
		pPlansza->Podziemia[42][40] = sciana;
		pPlansza->Podziemia[43][40] = sciana;
		pPlansza->Podziemia[44][40] = sciana;
		pPlansza->Podziemia[45][40] = sciana;
		pPlansza->Podziemia[46][40] = sciana;
		pPlansza->Podziemia[42][49] = sciana;
		pPlansza->Podziemia[43][49] = sciana;
		pPlansza->Podziemia[44][49] = sciana;
		pPlansza->Podziemia[45][49] = sciana;
		pPlansza->Podziemia[46][49] = sciana;
		pPlansza->Podziemia[47][49] = sciana;
		pPlansza->Podziemia[47][40] = sciana;
		pPlansza->Podziemia[42][47] = sciana;
		pPlansza->Podziemia[43][47] = sciana;
		pPlansza->Podziemia[46][44] = sciana;

		for (int i = 41; i < 49; i++)
		{
			pPlansza->Podziemia[41][i] = sufit;
			pPlansza->Podziemia[48][i] = sufit;
		}

		for (int i = 41; i < 44; i++)
		{
			pPlansza->Podziemia[45][i] = sufit;
			
		}

	}
	{// trap na cemntarzy

		for (int i = 22; i < 25 ; i++)
			pPlansza->Podziemia[i][6] = sciana;

		for (int i = 1; i < 6; i++)
			pPlansza->Podziemia[25][i] = sufit;

		for (int i = 1; i < 6; i++)
			pPlansza->Podziemia[21][i] = sufit;

		pPlansza->Podziemia[23][4] = sciana;
		pPlansza->Podziemia[22][4] = sciana;
		pPlansza->Podziemia[23][2] = sciana;

	}

	//	skarbiec krolewski

	{
		pPlansza->Podziemia[26][2] = sciana;
		pPlansza->Podziemia[27][2] = sciana;
		pPlansza->Podziemia[28][2] = sciana;
		pPlansza->Podziemia[29][2] = sciana;
		pPlansza->Podziemia[31][4] = sciana;
		pPlansza->Podziemia[32][4] = sciana;
		pPlansza->Podziemia[32][4].NumerZdarzenia = 50015;
		pPlansza->Podziemia[30][3] = sufit;
		pPlansza->Podziemia[33][1] = sufit;
		pPlansza->Podziemia[33][2] = sufit;
		pPlansza->Podziemia[33][3] = sufit;


	}

	//jaskinia teodora

	{
		pPlansza->Podziemia[1][14] = sciana_podziemia;
		pPlansza->Podziemia[1][15] = sciana_podziemia;
		pPlansza->Podziemia[1][16] = sciana_podziemia;
		pPlansza->Podziemia[1][17] = sciana_podziemia;
		pPlansza->Podziemia[1][18] = sciana_podziemia;
		pPlansza->Podziemia[1][19] = sciana_podziemia;
		pPlansza->Podziemia[1][20] = sciana_podziemia;
		pPlansza->Podziemia[1][21] = sciana_podziemia;
		pPlansza->Podziemia[1][22] = sciana_podziemia;
		pPlansza->Podziemia[2][22] = sciana_podziemia;
		pPlansza->Podziemia[3][22] = sciana_podziemia;
		pPlansza->Podziemia[4][22] = sciana_podziemia;
		pPlansza->Podziemia[5][22] = sciana_podziemia;
		pPlansza->Podziemia[6][22] = sciana_podziemia;
		pPlansza->Podziemia[7][22] = sciana_podziemia;
		pPlansza->Podziemia[7][21] = sciana_podziemia;
		pPlansza->Podziemia[7][20] = sciana_podziemia;
		pPlansza->Podziemia[6][19] = sciana_podziemia;
		pPlansza->Podziemia[6][18] = sciana_podziemia;
		pPlansza->Podziemia[6][17] = sciana_podziemia;
		pPlansza->Podziemia[5][16] = sciana_podziemia;
		pPlansza->Podziemia[5][15] = sciana_podziemia;
		pPlansza->Podziemia[6][14] = sciana_podziemia;
		pPlansza->Podziemia[7][13] = sciana_podziemia;
		pPlansza->Podziemia[8][12] = sciana_podziemia;
		pPlansza->Podziemia[8][10] = sciana_podziemia;
		pPlansza->Podziemia[7][10] = sciana_podziemia;
		pPlansza->Podziemia[6][10] = sciana_podziemia;
		pPlansza->Podziemia[5][10] = sciana_podziemia;
		pPlansza->Podziemia[4][11] = sciana_podziemia;
		pPlansza->Podziemia[3][12] = sciana_podziemia;
		pPlansza->Podziemia[2][13] = sciana_podziemia;
		pPlansza->Podziemia[9][10] = sciana_podziemia;
		pPlansza->Podziemia[10][11] = sciana_podziemia;
		pPlansza->Podziemia[10][12] = sciana_podziemia;
		pPlansza->Podziemia[10][13] = sciana_podziemia;
		pPlansza->Podziemia[9][14] = sciana_podziemia;
		pPlansza->Podziemia[8][15] = sciana_podziemia;
		pPlansza->Podziemia[8][16] = sciana_podziemia;
		pPlansza->Podziemia[8][17] = sciana_podziemia;
		pPlansza->Podziemia[9][18] = sciana_podziemia;
		pPlansza->Podziemia[9][19] = sciana_podziemia;
		pPlansza->Podziemia[9][20] = sciana_podziemia;
		pPlansza->Podziemia[8][22] = sciana_podziemia;
		pPlansza->Podziemia[10][21] = sciana_podziemia;
		pPlansza->Podziemia[9][22] = sciana_podziemia;
		pPlansza->Podziemia[7][19].NumerZdarzenia = 22511;

	} 


	//trumna
	{
		//pPlansza->Podziemia[9][94] = sciana;
		pPlansza->Podziemia[8][94] = sciana;
		pPlansza->Podziemia[7][94] = sciana;
		pPlansza->Podziemia[6][94] = sciana;
		//pPlansza->Podziemia[9][96] = sciana;
		pPlansza->Podziemia[8][96] = sciana;
		pPlansza->Podziemia[7][96] = sciana;
		pPlansza->Podziemia[6][96] = sciana;
		pPlansza->Podziemia[3][96] = sciana;
		pPlansza->Podziemia[3][94] = sciana;

		pPlansza->Podziemia[4][93] = dach_lewa_strona;
		pPlansza->Podziemia[5][93] = dach_prawa_strona;
		pPlansza->Podziemia[4][97] = dach_prawa_strona;
		pPlansza->Podziemia[5][97] = dach_lewa_strona;

		pPlansza->Podziemia[4][95] = grobek;
		pPlansza->Podziemia[2][95] = podloga;
		pPlansza->Podziemia[8][95] = podloga;
		


	}

	//lab HepoHepatisa
	{
		//pPlansza->Podziemia[8][81] = sciana_podziemia;
		pPlansza->Podziemia[7][81] = sciana_podziemia;
		pPlansza->Podziemia[9][81] = sciana_podziemia;
		pPlansza->Podziemia[7][82] = sciana_podziemia;
		pPlansza->Podziemia[7][83] = sciana_podziemia;
		pPlansza->Podziemia[7][84] = sciana_podziemia;
		pPlansza->Podziemia[7][85] = sciana_podziemia;
		pPlansza->Podziemia[7][85] = sciana_podziemia;
		pPlansza->Podziemia[7][86] = sciana_podziemia;
		pPlansza->Podziemia[7][87] = sciana_podziemia;
		pPlansza->Podziemia[7][88] = sciana_podziemia;
		pPlansza->Podziemia[7][89] = sciana_podziemia;
		pPlansza->Podziemia[1][91] = sciana_podziemia;
		pPlansza->Podziemia[2][91] = sciana_podziemia;
		pPlansza->Podziemia[3][91] = sciana_podziemia;
		pPlansza->Podziemia[4][91] = sciana_podziemia;
		pPlansza->Podziemia[5][91] = sciana_podziemia;
		pPlansza->Podziemia[5][91] = sciana_podziemia;
		pPlansza->Podziemia[6][91] = sciana_podziemia;
		pPlansza->Podziemia[7][90] = sciana_podziemia;
		pPlansza->Podziemia[9][82] = sciana_podziemia;
		pPlansza->Podziemia[9][83] = sciana_podziemia;
		pPlansza->Podziemia[9][84] = sciana_podziemia;
		pPlansza->Podziemia[9][85] = sciana_podziemia;
		pPlansza->Podziemia[9][86] = sciana_podziemia;
		pPlansza->Podziemia[9][87] = sciana_podziemia;
		pPlansza->Podziemia[9][88] = sciana_podziemia;
		pPlansza->Podziemia[9][88] = sciana_podziemia;
		pPlansza->Podziemia[9][89] = sciana_podziemia;
		pPlansza->Podziemia[9][89] = sciana_podziemia;
		pPlansza->Podziemia[9][90] = sciana_podziemia;
		pPlansza->Podziemia[9][90] = sciana_podziemia;
		pPlansza->Podziemia[10][91] = sciana_podziemia;
		pPlansza->Podziemia[10][92] = sciana_podziemia;
		pPlansza->Podziemia[10][93] = sciana_podziemia;
		pPlansza->Podziemia[10][94] = sciana_podziemia;
		pPlansza->Podziemia[10][95] = sciana_podziemia;
		pPlansza->Podziemia[10][96] = sciana_podziemia;
		pPlansza->Podziemia[10][97] = sciana_podziemia;
		pPlansza->Podziemia[10][98] = sciana_podziemia;
		pPlansza->Podziemia[7][80] = sciana_podziemia;
		pPlansza->Podziemia[9][80] = sciana_podziemia;
		pPlansza->Podziemia[7][79] = sciana_podziemia;
		pPlansza->Podziemia[9][79] = sciana_podziemia;
		pPlansza->Podziemia[8][79] = sciana_podziemia;


		pPlansza->Podziemia[6][79] = sciana_podziemia;
		pPlansza->Podziemia[5][80] = sciana_podziemia;
		pPlansza->Podziemia[4][80] = sciana_podziemia;
		pPlansza->Podziemia[3][79] = sciana_podziemia;
		pPlansza->Podziemia[3][78] = sciana_podziemia;
		pPlansza->Podziemia[3][77] = sciana_podziemia;
		pPlansza->Podziemia[6][77] = sciana_podziemia;
		pPlansza->Podziemia[5][76] = sciana_podziemia;
		pPlansza->Podziemia[4][76] = sciana_podziemia;

		pPlansza->Podziemia[7][77] = sciana_podziemia;
		pPlansza->Podziemia[7][76] = sciana_podziemia;
		pPlansza->Podziemia[7][74] = sciana_podziemia;
		pPlansza->Podziemia[7][75] = sciana_podziemia;
		pPlansza->Podziemia[5][74] = sciana_podziemia;
		pPlansza->Podziemia[4][74] = sciana_podziemia;
		pPlansza->Podziemia[3][73] = sciana_podziemia;
		pPlansza->Podziemia[3][72] = sciana_podziemia;
		pPlansza->Podziemia[3][71] = sciana_podziemia;
		pPlansza->Podziemia[4][70] = sciana_podziemia;
		pPlansza->Podziemia[5][70] = sciana_podziemia;
		pPlansza->Podziemia[6][71] = sciana_podziemia;
		pPlansza->Podziemia[6][73] = sciana_podziemia;
		pPlansza->Podziemia[7][71] = sciana_podziemia;
		pPlansza->Podziemia[7][73] = sciana_podziemia;

		pPlansza->Podziemia[9][78] = sciana_podziemia;
		pPlansza->Podziemia[9][77] = sciana_podziemia;
		pPlansza->Podziemia[9][76] = sciana_podziemia;
		pPlansza->Podziemia[9][75] = sciana_podziemia;
		pPlansza->Podziemia[9][74] = sciana_podziemia;
		pPlansza->Podziemia[9][73] = sciana_podziemia;
		pPlansza->Podziemia[9][72] = sciana_podziemia;
		pPlansza->Podziemia[9][71] = sciana_podziemia;
		pPlansza->Podziemia[9][70] = sciana_podziemia;
		pPlansza->Podziemia[9][69] = sciana_podziemia;
		pPlansza->Podziemia[7][70] = sciana_podziemia;
		pPlansza->Podziemia[7][69] = sciana_podziemia;
		pPlansza->Podziemia[7][68] = sciana_podziemia;
		pPlansza->Podziemia[7][67] = sciana_podziemia;
		pPlansza->Podziemia[7][66] = sciana_podziemia;
		pPlansza->Podziemia[9][68] = sciana_podziemia;
		pPlansza->Podziemia[9][67] = sciana_podziemia;
		pPlansza->Podziemia[9][66] = sciana_podziemia;
		pPlansza->Podziemia[9][64] = sciana_podziemia;
		pPlansza->Podziemia[7][65] = sciana_podziemia;
		pPlansza->Podziemia[7][64] = sciana_podziemia;
		pPlansza->Podziemia[7][63] = sciana_podziemia;
		pPlansza->Podziemia[9][63] = sciana_podziemia;
		pPlansza->Podziemia[6][62] = sciana_podziemia;
		pPlansza->Podziemia[10][62] = sciana_podziemia;
		pPlansza->Podziemia[11][62] = sciana_podziemia;
		pPlansza->Podziemia[12][62] = sciana_podziemia;
		pPlansza->Podziemia[5][62] = sciana_podziemia;
		pPlansza->Podziemia[4][62] = sciana_podziemia;
		pPlansza->Podziemia[10][64] = sciana_podziemia;
		pPlansza->Podziemia[11][64] = sciana_podziemia;
		pPlansza->Podziemia[12][64] = sciana_podziemia;
		pPlansza->Podziemia[20][64] = sciana_podziemia;		
		pPlansza->Podziemia[20][66] = sciana_podziemia;
		pPlansza->Podziemia[19][64] = sciana_podziemia;
		pPlansza->Podziemia[18][64] = sciana_podziemia;
		pPlansza->Podziemia[17][64] = sciana_podziemia;
		pPlansza->Podziemia[16][64] = sciana_podziemia;
		pPlansza->Podziemia[15][64] = sciana_podziemia;
		pPlansza->Podziemia[14][64] = sciana_podziemia;
		pPlansza->Podziemia[13][64] = sciana_podziemia;
		pPlansza->Podziemia[13][62] = sciana_podziemia;
		pPlansza->Podziemia[14][62] = sciana_podziemia;
		pPlansza->Podziemia[15][62] = sciana_podziemia;
		pPlansza->Podziemia[16][62] = sciana_podziemia;
		pPlansza->Podziemia[17][62] = sciana_podziemia;
		pPlansza->Podziemia[18][62] = sciana_podziemia;
		pPlansza->Podziemia[19][62] = sciana_podziemia;
		pPlansza->Podziemia[20][62] = sciana_podziemia;
		pPlansza->Podziemia[21][62] = sciana_podziemia;		
		pPlansza->Podziemia[10][66] = sciana_podziemia;
		pPlansza->Podziemia[11][66] = sciana_podziemia;
		pPlansza->Podziemia[12][66] = sciana_podziemia;
		pPlansza->Podziemia[13][66] = sciana_podziemia;
		pPlansza->Podziemia[14][66] = sciana_podziemia;
		pPlansza->Podziemia[15][66] = sciana_podziemia;
		pPlansza->Podziemia[16][66] = sciana_podziemia;
		pPlansza->Podziemia[17][66] = sciana_podziemia;
		pPlansza->Podziemia[18][66] = sciana_podziemia;

		pPlansza->Podziemia[19][66] = sciana_podziemia;
		pPlansza->Podziemia[20][67] = sciana_podziemia;
		pPlansza->Podziemia[20][68] = sciana_podziemia;
		pPlansza->Podziemia[20][69] = sciana_podziemia;
		pPlansza->Podziemia[20][70] = sciana_podziemia;
		pPlansza->Podziemia[20][71] = sciana_podziemia;
		pPlansza->Podziemia[20][72] = sciana_podziemia;
		pPlansza->Podziemia[20][73] = sciana_podziemia;
		pPlansza->Podziemia[20][74] = sciana_podziemia;
		pPlansza->Podziemia[22][67] = sciana_podziemia;
		pPlansza->Podziemia[22][66] = sciana_podziemia;
		pPlansza->Podziemia[22][65] = sciana_podziemia;
		pPlansza->Podziemia[22][64] = sciana_podziemia;
		pPlansza->Podziemia[21][64] = sciana_podziemia;
		pPlansza->Podziemia[22][68] = sciana_podziemia;
		pPlansza->Podziemia[22][69] = sciana_podziemia;
		pPlansza->Podziemia[22][70] = sciana_podziemia;
		pPlansza->Podziemia[22][71] = sciana_podziemia;
		pPlansza->Podziemia[22][72] = sciana_podziemia;
		pPlansza->Podziemia[22][73] = sciana_podziemia;

		pPlansza->Podziemia[23][73] = sciana_podziemia;
		pPlansza->Podziemia[24][73] = sciana_podziemia;
		pPlansza->Podziemia[24][74] = sciana_podziemia;
		pPlansza->Podziemia[24][75] = sciana_podziemia;
		pPlansza->Podziemia[23][75] = sciana_podziemia;
		pPlansza->Podziemia[22][75] = sciana_podziemia;
		pPlansza->Podziemia[22][76] = sciana_podziemia;
		pPlansza->Podziemia[22][77] = sciana_podziemia;
		pPlansza->Podziemia[23][77] = sciana_podziemia;
		pPlansza->Podziemia[24][77] = sciana_podziemia;
		pPlansza->Podziemia[24][78] = sciana_podziemia;
		pPlansza->Podziemia[24][79] = sciana_podziemia;
		pPlansza->Podziemia[23][79] = sciana_podziemia;
		pPlansza->Podziemia[22][79] = sciana_podziemia;
		pPlansza->Podziemia[22][80] = sciana_podziemia;
		pPlansza->Podziemia[22][81] = sciana_podziemia;
		pPlansza->Podziemia[23][81] = sciana_podziemia;
		pPlansza->Podziemia[24][81] = sciana_podziemia;
		pPlansza->Podziemia[24][82] = sciana_podziemia;
		pPlansza->Podziemia[24][83] = sciana_podziemia;
		pPlansza->Podziemia[23][83] = sciana_podziemia;
		pPlansza->Podziemia[22][83] = sciana_podziemia;
		pPlansza->Podziemia[22][84] = sciana_podziemia;
		pPlansza->Podziemia[22][85] = sciana_podziemia;
		pPlansza->Podziemia[23][85] = sciana_podziemia;
		pPlansza->Podziemia[24][85] = sciana_podziemia;
		pPlansza->Podziemia[24][86] = sciana_podziemia;
		pPlansza->Podziemia[24][87] = sciana_podziemia;
		pPlansza->Podziemia[23][87] = sciana_podziemia;
		pPlansza->Podziemia[22][87] = sciana_podziemia;
		pPlansza->Podziemia[22][88] = sciana_podziemia;
		pPlansza->Podziemia[22][89] = sciana_podziemia;
		pPlansza->Podziemia[22][90] = sciana_podziemia;
		pPlansza->Podziemia[20][75] = sciana_podziemia;
		pPlansza->Podziemia[20][76] = sciana_podziemia;
		pPlansza->Podziemia[20][77] = sciana_podziemia;
		pPlansza->Podziemia[20][78] = sciana_podziemia;
		pPlansza->Podziemia[20][79] = sciana_podziemia;
		pPlansza->Podziemia[20][80] = sciana_podziemia;
		pPlansza->Podziemia[20][81] = sciana_podziemia;
		pPlansza->Podziemia[20][82] = sciana_podziemia;
		pPlansza->Podziemia[20][83] = sciana_podziemia;
		pPlansza->Podziemia[20][84] = sciana_podziemia;
		pPlansza->Podziemia[20][85] = sciana_podziemia;
		pPlansza->Podziemia[20][86] = sciana_podziemia;
		pPlansza->Podziemia[20][87] = sciana_podziemia;
		pPlansza->Podziemia[20][88] = sciana_podziemia;
		pPlansza->Podziemia[20][89] = sciana_podziemia;
		pPlansza->Podziemia[20][90] = sciana_podziemia;
		pPlansza->Podziemia[20][91] = sciana_podziemia;
		pPlansza->Podziemia[20][92] = sciana_podziemia;
		pPlansza->Podziemia[20][93] = sciana_podziemia;
		pPlansza->Podziemia[20][94] = sciana_podziemia;
		pPlansza->Podziemia[20][95] = sciana_podziemia;
		
		pPlansza->Podziemia[22][86] = drzwi;
		pPlansza->Podziemia[22][82] = drzwi;
		pPlansza->Podziemia[22][78] = drzwi;
		pPlansza->Podziemia[22][74] = drzwi;

		pPlansza->Podziemia[20][96] = sufit;
		pPlansza->Podziemia[20][97] = sufit;	
		pPlansza->Podziemia[22][91] = sufit;
		pPlansza->Podziemia[22][92] = sufit;
		pPlansza->Podziemia[22][93] = sufit;
		pPlansza->Podziemia[26][95] = sufit;
		pPlansza->Podziemia[26][96] = sufit;
		pPlansza->Podziemia[26][97] = sufit;

		pPlansza->Podziemia[21][98] = sciana;
		pPlansza->Podziemia[22][98] = sciana;
		pPlansza->Podziemia[23][98] = sciana;
		pPlansza->Podziemia[24][98] = sciana;
		pPlansza->Podziemia[25][98] = sciana;
		pPlansza->Podziemia[23][94] = sciana;
		pPlansza->Podziemia[24][91] = sciana;
		pPlansza->Podziemia[25][91] = sciana;

		pPlansza->Podziemia[23][93] = podloga;
		pPlansza->Podziemia[23][92] = podloga;

		pPlansza->Podziemia[21][93] = drzwi;
		pPlansza->Podziemia[21][93].SymbolPola = '#';

		pPlansza->Podziemia[26][92] = sufit;
		pPlansza->Podziemia[26][93] = sufit;
		pPlansza->Podziemia[26][94] = sufit;
		pPlansza->Podziemia[24][94] = sciana;

	}

	return true;
}


bool CGilgamesh::RysujCmentarz()
{
	/*
	pPlansza->Plansza[18][98] = sufit;
	pPlansza->Plansza[18][97] = sufit;
	pPlansza->Plansza[18][96] = sufit;
	pPlansza->Plansza[18][95] = sufit;
	pPlansza->Plansza[18][94] = sufit;
	pPlansza->Plansza[18][94] = sufit;
	pPlansza->Plansza[18][94] = sufit;
	pPlansza->Plansza[18][93] = sufit;
	pPlansza->Plansza[18][92] = sufit;
	pPlansza->Plansza[18][91] = sufit;
	pPlansza->Plansza[18][90] = sufit;
	pPlansza->Plansza[18][89] = sufit;
	pPlansza->Plansza[12][89] = sufit;
	pPlansza->Plansza[12][90] = sufit;
	pPlansza->Plansza[12][91] = sufit;
	pPlansza->Plansza[12][92] = sufit;
	pPlansza->Plansza[12][92] = sufit;
	pPlansza->Plansza[12][93] = sufit;
	pPlansza->Plansza[12][94] = sufit;
	pPlansza->Plansza[12][95] = sufit;
	pPlansza->Plansza[12][96] = sufit;
	pPlansza->Plansza[12][97] = sufit;
	pPlansza->Plansza[12][98] = sufit;

	pPlansza->Plansza[17][88] = sciana;
	pPlansza->Plansza[16][88] = sciana;
	pPlansza->Plansza[13][88] = sciana;
	pPlansza->Plansza[14][88] = sciana;

	pPlansza->Plansza[13][90] = grobek;
	pPlansza->Plansza[13][92] = grobek;
	pPlansza->Plansza[13][94] = grobek;
	pPlansza->Plansza[13][96] = grobek;
	pPlansza->Plansza[13][98] = grobek;
	pPlansza->Plansza[17][98] = grobek;
	pPlansza->Plansza[17][96] = grobek;
	pPlansza->Plansza[17][94] = grobek;
	pPlansza->Plansza[17][92] = grobek;
	pPlansza->Plansza[17][90] = grobek;
	pPlansza->Plansza[15][92] = grobek;
	pPlansza->Plansza[15][94] = grobek;
	pPlansza->Plansza[15][96] = grobek;
	pPlansza->Plansza[15][98] = grobek;
	*/

	pPlansza->Plansza[19][88] = sufit;
	pPlansza->Plansza[19][89] = sufit;
	pPlansza->Plansza[19][90] = sufit;
	pPlansza->Plansza[19][91] = sufit;
	pPlansza->Plansza[19][92] = sufit;
	pPlansza->Plansza[19][93] = sufit;
	pPlansza->Plansza[19][94] = sufit;
	pPlansza->Plansza[19][95] = sufit;
	pPlansza->Plansza[19][96] = sufit;
	pPlansza->Plansza[19][97] = sufit;
	pPlansza->Plansza[19][98] = sufit;
	pPlansza->Plansza[11][98] = sufit;
	pPlansza->Plansza[11][97] = sufit;
	pPlansza->Plansza[11][96] = sufit;
	pPlansza->Plansza[11][95] = sufit;
	pPlansza->Plansza[11][94] = sufit;
	pPlansza->Plansza[11][93] = sufit;
	pPlansza->Plansza[11][92] = sufit;
	pPlansza->Plansza[11][91] = sufit;
	pPlansza->Plansza[11][90] = sufit;
	pPlansza->Plansza[11][89] = sufit;
	pPlansza->Plansza[11][88] = sufit;

	pPlansza->Plansza[18][87] = sciana;
	pPlansza->Plansza[12][87] = sciana;
	pPlansza->Plansza[13][87] = sciana;
	pPlansza->Plansza[17][87] = sciana;
	pPlansza->Plansza[16][87] = sciana;
	pPlansza->Plansza[14][87] = sciana;

	pPlansza->Plansza[12][89] = grobek;
	pPlansza->Plansza[12][91] = grobek;
	pPlansza->Plansza[12][93] = grobek;
	pPlansza->Plansza[12][95] = grobek;
	pPlansza->Plansza[12][97] = grobek;
	//pPlansza->Plansza[14][95] = grobek;
	pPlansza->Plansza[14][93] = grobek;
	pPlansza->Plansza[14][91] = grobek;
	pPlansza->Plansza[16][91] = grobek;
	pPlansza->Plansza[16][93] = grobek;
	//pPlansza->Plansza[16][95] = grobek;
	pPlansza->Plansza[18][97] = grobek;
	pPlansza->Plansza[18][95] = grobek;
	pPlansza->Plansza[18][93] = grobek;
	pPlansza->Plansza[18][91] = grobek;
	pPlansza->Plansza[18][89] = grobek;
	pPlansza->Plansza[14][89] = grobek;
	pPlansza->Plansza[16][89] = grobek;

	pPlansza->Plansza[14][98] = sufit;
	pPlansza->Plansza[14][97] = sufit;
	pPlansza->Plansza[16][98] = sufit;
	pPlansza->Plansza[16][97] = sufit;
	pPlansza->Plansza[14][96] = sufit;
	pPlansza->Plansza[16][96] = sufit;

	pPlansza->Plansza[15][96].NumerZdarzenia = 16;
	pPlansza->Plansza[15][96].SymbolPola = '#';
	return true;
}

bool Ekwipunek::DodajDrewno()
{
	if (siekiera == false)
		return false;
	if (drewno == MAX)
		return false;
	++drewno;
	return true;
}

bool Ekwipunek::DodajZboze()
{
	if (kosa == false)
		return false;
	if (zboze == MAX)
		return false;
	++zboze;
	return true;
}

bool Ekwipunek::DodajWode()
{
	if (fiolki == 0)
		return false;
	if (woda == MAX)
		return false;
	++woda;
	--fiolki;
	return true;
}
bool Ekwipunek::DodajFiolke()
{
	if (fiolki == MAX)
		return false;
	++fiolki;
	return true;
}
void Ekwipunek::WyswietlEq()
{
	
	cout << endl << "TWOJ EKWIPUNEK" << endl;
	if (siekiera)
		cout << "Masz siekiere" << endl;

	if (kosa)
		cout << "Masz kose" << endl;

	if (ZestawAlchemika)
		cout << "Masz zestaw alchemika" << endl;

	if (tratwa)
		cout << "Mozesz skorzystac z tratwy" << endl;
	/*
	if (zbroja.jest)
	{
		cout << "Posiadana zbroja to " << zbroja.nazwa << endl;
		cout << "Obrona: " << zbroja.parametr << endl;
		
	}
	if (bron.jest)
	{
		cout << "Posiadana bron to " << bron.nazwa << endl;
		cout << "Atak: " << bron.parametr << endl;

	}
	*/
	cout << "Zloto: " << zloto << endl;
	cout << "Exp: " << this->exp << endl;

	cout << "Drewno: " << drewno << endl;
	cout << "Zboze: " << zboze << endl;	
	cout << "Woda: " << woda << endl;
	cout << "Fiolki: " << fiolki << endl;
	
	
}

bool Ekwipunek::operator=(Ekwipunek Ekwip)
{
	
	siekiera = Ekwip.siekiera;
	kosa = Ekwip.kosa;
	ZestawAlchemika = Ekwip.ZestawAlchemika;
	tratwa = Ekwip.tratwa;
	
	//Ogolne 
	zloto = Ekwip.zloto;	
	//surowce
	drewno = Ekwip.drewno;
	zboze = Ekwip.zboze;
	woda = Ekwip.woda;
	fiolki = Ekwip.fiolki;
	//Pola pomocnicze
	MAX = Ekwip.MAX;


	return true;
}

/*

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

bool dialog()
{
std::fstream plik;

plik.open("Odpowiedzi.txt", ios::in);
if (plik.good() == false)
return false;



return true;
}

*/



CFabula::CFabula()
{
	 pHero = NULL;
	 pPlansza = NULL;
	 Odpowiedzi = NULL;
	 Oddzywki = NULL; 
}

CFabula::CFabula(CMainHero* SetpHero, CPlansza* SetpPlansza)
{
	pHero = SetpHero;
	pPlansza = SetpPlansza;

	

	Odpowiedzi = NULL;
	Oddzywki = NULL;
	Odpowiedzi = ZaladujDialogiNaStos(Odpowiedzi, "Odpowiedzi.txt");
	Oddzywki = ZaladujDialogiNaStos(Oddzywki, "Oddzywki.txt");

	pFarmer = new CNPC("Farmer", 'F', 114, 14, 21, Straznik, pPlansza);
	pFarmer->RysujPostac();
	{
		pWiezien = new CNPC("Wiezien", 'W', 317, 4, 79, Straznik, pPlansza);
		pWiezien->RysujPostac();
		pKsiezniczka = new CNPC("Ksiezniczka", 'K', 316, 36, 9, Straznik, pPlansza);
		pKsiezniczka->RysujPostac();
	    pWiezniarz = new CNPC("Zarzadca wiezienia", 'W', 178, 10, 81, Straznik, pPlansza);
		pWiezniarz->RysujPostac();
		pWiezniarz->LoadNpcToBoard();
		pStraznikMiasta1 = new CNPC("Straznik", 'S', 122, 38, 40, Straznik, pPlansza);
		pStraznikMiasta1->RysujPostac();
		pStraznikMiasta1->LoadNpcToBoard();
		pStraznikMiasta2 = new CNPC("Straznik", 'S', 122, 41, 40, Straznik, pPlansza);
		pStraznikMiasta2->RysujPostac();
		pStraznikMiasta2->LoadNpcToBoard();
		pStraznikZiuta1 = new CNPC("Straznik", 'S', 195, 39, 9, Straznik, pPlansza);
		pStraznikZiuta1->RysujPostac();
		pStraznikZiuta1->LoadNpcToBoard();
		pStraznikZiuta2 = new CNPC("Straznik", 'S', 195, 41, 9, Straznik, pPlansza);
		pStraznikZiuta2->RysujPostac();
		pStraznikZiuta2->LoadNpcToBoard();
		pZiutmelson = new CNPC("Ziutmelson", 'Z', 314, 40, 6, Straznik, pPlansza);
		pZiutmelson->RysujPostac();
		pZiutmelson->LoadNpcToBoard();
		pZlodziejSzef = new CNPC("Przywodca gildii", 'N', 213, 46, 2, Straznik, pPlansza);
		pZlodziejSzef->RysujPostac();
		pZlodziejSzef->LoadNpcToBoard();
		pZlodziej1 = new CNPC("Nieznany mezczyzna", 'N', 211, 48, 1, Straznik, pPlansza);
		pZlodziej1->RysujPostac();
		pZlodziej1->LoadNpcToBoard();
		pZlodziej2 = new CNPC("Nieznana kobieta", 'N', 212, 48, 3, Straznik, pPlansza);
		pZlodziej2->RysujPostac();
		pZlodziej2->LoadNpcToBoard();
		pGrabarz = new CNPC("Grabarz", 'G', 290, 17, 85, Straznik, pPlansza);
		pGrabarz->RysujPostac();
		pSzefStrazy = new CNPC_w_obiekcie("Kapitan Strazy", 201, 37, 17, Straznik, pPlansza);
		pPrzydupasSzefaStrazy = new CNPC_w_obiekcie("Doradca", 224, 37, 18, Straznik, pPlansza);
		pZonaTeodora = new CNPC_w_obiekcie("Elwira", 126, 11, 12, Straznik, pPlansza);
		pTeodorPoOdnalezieniu = NULL;
		pMlynarz = new CNPC_w_obiekcie("Mlynarz", 136, 11, 24, Straznik, pPlansza);
		pPiec = new CNPC_w_obiekcie("Piec", 138, 11, 5, Straznik, pPlansza);
		pKarczmarz = new CNPC_w_obiekcie("Karczmarka", 249, 44, 25, Straznik, pPlansza);
		pGosc1 = new CNPC_w_obiekcie("Mezczyzna", 234, 45, 25, Straznik, pPlansza);
		pGosc2 = new CNPC_w_obiekcie("Mezczyzna", 233, 44, 26, Straznik, pPlansza);
		pKupiec = new CNPC_w_obiekcie("Kupiec", 250, 45, 26, Straznik, pPlansza);
		pStajenny = new CNPC_w_obiekcie("Najemnik", 287, 44, 34, Straznik, pPlansza);
		
	}

	
	pClockMaster = new CClockMaster(0, 0, ClockMasterBoss, 0, Las1, pPlansza);
	pVampire = NULL;

	//if(StanKlepsydry >= ?)
	pVectarian = new CVectarian(29, 98, VectarianBoss, 0, Las1, SetpPlansza);
	pVectarian->RysujPostac();

	if(bDostepDoZiutka == false)
		pPlansza->Plansza[40][9] = PoleStrzezone;
	if (bDostepDoMiasta == false)
	{
		pPlansza->Plansza[39][40] = PoleStrzezone;
		pPlansza->Plansza[40][40] = PoleStrzezone;
	}

	if(pHero->RetMagRoslina() == false)
		pPlansza->Plansza[4][7] = MagicznaRoslina;

	if (DrzwiWiezyMaga == false)
		pPlansza->Plansza[32][89] = puste_pole;

	if (DrzwiAria == false)
		pPlansza->Podziemia[41][20] = puste_pole;

	for (int i = 0; i < AmountOfItems; i++)
		TabPrzedmioty[i] = false;



	//???????????????????????? odczyt
	//--------------- PRZEDMIOTY -----------------------------------------------------
	if(TabPrzedmioty[1] == true) // ropruwacz czasu
		pPlansza->Podziemia[10][1] = puste_pole;

	if (TabPrzedmioty[2] == true) // fragment poematu[2]
		pPlansza->Podziemia[22][1] = puste_pole;

	if (TabPrzedmioty[3] == true) // miecz w podziemiach teodora
		pPlansza->Podziemia[6][16] = puste_pole;

	//---------------------------------------------------------------------------------
	if (DrzwiPulapka == false) // 
		pPlansza->Podziemia[40][10] = puste_pole;
	
	if (ZlotyPosag == false) // posag gryfa w skarbcu
	{
		pPlansza->Podziemia[30][2].SymbolPola = '&';
		pPlansza->Podziemia[30][2].NumerZdarzenia = 50014;
	}
	else
	{
		pPlansza->Podziemia[30][1].SymbolPola = '$';
		pPlansza->Podziemia[30][1].NumerZdarzenia = 50014;
	}
	
	if (bDolTeodora == true) // dol teodora
		pPlansza->Plansza[23][3].NumerZdarzenia = 20319;

	/* DO TESTOW
	pTeodor = new CNPC("Teodor", 'T', 143, 41, 97, Straznik, pPlansza);
	pTeodor->LoadNpcToBoard();
	pTeodor->RysujPostac();
	StanSzacunekStraznika = 5;
	*/
	
	/*
	cout << "ODPOWIEDZI:" << endl;
	PokazStos(Odpowiedzi);
	cout << endl << endl << "ODPOWIEDZI:" << endl;
	PokazStos(Oddzywki);
	*/


	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//WyszukajDialog(Odpowiedzi, 211)->MoliweOdp[0] = 144;
	//WyszukajDialog(Odpowiedzi, 212)->MoliweOdp[0] = 144;
	//WyszukajDialog(Odpowiedzi, 213)->MoliweOdp[0] = 135;
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
}

CFabula::~CFabula()
{
	pHero = NULL;
	pPlansza = NULL;

	UsunStos(Odpowiedzi);
	UsunStos(Oddzywki);

	if (pKolesZaRzeka)
		delete pKolesZaRzeka;
	if (pTeodor)
		delete pTeodor;
	if (pTeodorPoOdnalezieniu)
		delete pTeodorPoOdnalezieniu;
	if (pWskazowka)
		delete pWskazowka;
	if (pVectarian)
		delete pVectarian;
	if(pClockMaster)
		delete pClockMaster;
	if(pVampire)
		delete pVampire;
	if (pTajemniczyMezczyzna)
		delete pTajemniczyMezczyzna;


	delete pFarmer;
	
	delete pWiezniarz;
	delete pStraznikMiasta1;
	delete pStraznikMiasta2;
	delete pStraznikZiuta1;
	delete pStraznikZiuta2;
	delete pZiutmelson;
	delete pZlodziejSzef;
	delete pZlodziej1;
	delete pZlodziej2;
	delete pSzefStrazy;
	delete pPrzydupasSzefaStrazy;
	delete pZonaTeodora;
	delete pMlynarz;
	delete pPiec;
	delete pKarczmarz;
	delete pGosc1;
	delete pGosc2;
	delete pKupiec;
	delete pStajenny;
	delete pGrabarz;
	delete pWiezien;
	delete pKsiezniczka;
	


	for(int i = 0; i<AmountOfBear; i++)
		delete TabBear[i];
	for (int i = 0; i<AmountOfWolf; i++)
		delete TabWolf[i];
	for (int i = 0; i<AmountOfBandits; i++)
		delete TabBandits[i];
	for (int i = 0; i<AmountOfUndead; i++)
		delete TabUndead[i];
	for (int i = 0; i<AmountOfGuardian; i++)
		if(TabGuardian[i])
			delete TabGuardian[i];
	for (int i = 0; i<AmountOfGuards; i++)
		if (TabGuards[i])
			delete TabGuards[i];

}
void CFabula::DrzewusCreatio()
{
	if (pDrzewacz) return;

	pDrzewacz = new CDrzewacz(pHero->RetPrevX(), pHero->RetPrevY(), DrzewaczBoss, 0, Las1, pPlansza);
	int decyzja;

	cout << endl << endl << "Ulyszales cichy szelst" << endl;
	Sleep(2000);
	cout << endl << "Korona drzew zaczela gestniec" << endl;
	Sleep(2000);
	cout << endl << "Przerazliwe krakanie przecielo cisze" << endl;
	Sleep(2000);
	cout << endl << "Potepiencze wycie uderzylo niczym grom" << endl;
	Sleep(2000);
	cout << endl << "ON nadchodzil..." << endl;
	Sleep(2000);
	cout << "1. WALCZ" << endl << "2. UCIEKAJ" << endl;

	while (1)
	{
		
		if ((decyzja = _getch()) == 224)
			decyzja = _getch();

		switch (decyzja)
		{
		case '1':
		{
		if (!pHero->Walka(pDrzewacz))
			koniec = true;
		else
		{
			static_cast<CMonster*>(pDrzewacz)->GiveLoot(pHero);
			pDrzewacz->UsunPostacWrazZWskaznikiem();
			delete pDrzewacz;
			pDrzewacz = NULL;

		}

		return;
	}

		case '2':
		{
			pDrzewacz->RysujPostac();
			pHero->UsunPostacWrazZWskaznikiem();
			pHero->SetXY(39, 47);
			pHero->RysujPostac();
		return;
		}

		default: break;
		}

	}
}

void CFabula::WyjscieZPol()
{
	if (bWyjscieZPol) return;
	if (pHero->RetisPole() == false)
	{
		
		WyswietlDialog(Odpowiedzi, Oddzywki, 100, pHero->RetName(), pHero->RetName());
		bWyjscieZPol = true;
	}
}
void CFabula::BrakMostu()
{
	if (bBrakMostu) return;
	if (bWyjscieZPol == false) return;
	if (pHero->retY() == 85)
	{
		WyswietlDialog(Odpowiedzi, Oddzywki, 101, pHero->RetName(), pHero->RetName());
		bBrakMostu = true;
	}


}

void CFabula::MarszDrzew()
{
	if (pDrzewacz == NULL) return;
	int x = pDrzewacz->retX();
	int y = pDrzewacz->retY();
	int HeroX = pHero->retX();
	int HeroY = pHero->retY();
	bool isOK = false;

	if (HeroX > x)
		++x;
	if (HeroX < x)
		--x;
	if (HeroY > y)
		++y;
	if (HeroY < y)
		--y;
	
	

	if (x == HeroX && y == HeroY)	
	{
		if (!pHero->Walka(pDrzewacz))
			koniec = true;
		else
		{
			static_cast<CMonster*>(pDrzewacz)->GiveLoot(pHero);
			pDrzewacz->UsunPostacWrazZWskaznikiem();
			delete pDrzewacz;
			pDrzewacz = NULL;

		}
	}
	

	if (!(CzyJestWTymObszarze(x, y, 43, 77, 15, 5) || CzyJestWTymObszarze(x, y, 1, 35, 45, 33) || CzyJestWTymObszarze(x, y, 18, 1, 12, 9) || CzyJestWTymObszarze(x, y, 44, 48, 12, 4)))
		return;
	
	
	

	if (pPlansza->Plansza[x][y] == puste_pole)
	{
		pDrzewacz->UsunPostacWrazZWskaznikiem();
		pDrzewacz->SetXY(x, y);
		pDrzewacz->RysujPostac();
	}


}
void CFabula::HistoriaAsgaru()
{
	for (int i = 18; i > 9; i--)
	{
		pPlansza->PlanszaSpec[i][39] = sciana;
		pPlansza->PlanszaSpec[i][40] = sciana;
	}
	pPlansza->PlanszaSpec[9][40] = sciana;
	for (int i = 35; i > 26; i--)
	{
		pPlansza->PlanszaSpec[i][39] = sciana;
		pPlansza->PlanszaSpec[i][40] = sciana;
	}
	for (int i = 26; i > 18; i--)
		pPlansza->PlanszaSpec[i][39] = sciana;

	pPlansza->PlanszaSpec[36][40] = sciana;

	for (int i = 1; i < 39; i++)
	{
		pPlansza->PlanszaSpec[8][i] = sufit;
		pPlansza->PlanszaSpec[9][i] = sufit;
		pPlansza->PlanszaSpec[36][i] = sufit;
		pPlansza->PlanszaSpec[37][i] = sufit;
	}
	pPlansza->PlanszaSpec[37][39] = sufit;
	pPlansza->PlanszaSpec[8][39] = sufit;


	CNpcSpec Topornicy[49];
	CNpcSpec Topornicy2[49];
	CNpcSpec Piki[49];
	CNpcSpec Piki2[49];
	CNpcSpec Luki[49];
	CNpcSpec Luki2[49];
	CNpcSpec Wrog1[459];
	CNpcSpec Wrog2[50];
	CNpcSpec Wrog3[144];


	CDom(17, 27, 1, pPlansza).RysujObiektHistoriaAsgaru();
	CDom(17, 21, 1, pPlansza).RysujObiektHistoriaAsgaru();
	CDom(17, 14, 1, pPlansza).RysujObiektHistoriaAsgaru();
	CDom(17, 7, 1, pPlansza).RysujObiektHistoriaAsgaru();
	CDom(27, 28, 1, pPlansza).RysujObiektHistoriaAsgaru();
	CDom(27, 21, 1, pPlansza).RysujObiektHistoriaAsgaru();
	CDom(27, 13, 1, pPlansza).RysujObiektHistoriaAsgaru();
	CDom(27, 7, 1, pPlansza).RysujObiektHistoriaAsgaru();
	CDom(34, 11, 1, pPlansza).RysujObiektHistoriaAsgaru();
	CDom(34, 33, 1, pPlansza).RysujObiektHistoriaAsgaru();
	CDom(34, 23, 1, pPlansza).RysujObiektHistoriaAsgaru();


	int k = 0;
	for (int i = 0; i < 7; i++)
		for (int j = 0; j < 7; j++)
			Topornicy[k++] = CNpcSpec(14 + i, 58 + j, pPlansza, 'T');

	k = 0;
	for (int i = 0; i < 7; i++)
		for (int j = 0; j < 7; j++)
			Topornicy2[k++] = CNpcSpec(26 + i, 58 + j, pPlansza, 'T');

	k = 0;
	for (int i = 0; i < 7; i++)
		for (int j = 0; j < 7; j++)
			Piki[k++] = CNpcSpec(14 + i, 70 + j, pPlansza, 'P');

	k = 0;
	for (int i = 0; i < 7; i++)
		for (int j = 0; j < 7; j++)
			Piki2[k++] = CNpcSpec(26 + i, 70 + j, pPlansza, 'P');

	k = 0;
	for (int i = 0; i < 7; i++)
		for (int j = 0; j < 7; j++)
			Luki[k++] = CNpcSpec(14 + i, 82 + j, pPlansza, 'L');

	k = 0;
	for (int i = 0; i < 7; i++)
		for (int j = 0; j < 7; j++)
			Luki2[k++] = CNpcSpec(26 + i, 82 + j, pPlansza, 'L');

	CNpcSpec Albert(23, 66, pPlansza, 'A');

	CNpcSpec Zwiadowcy[3];
	Zwiadowcy[0] = CNpcSpec(22, 55, pPlansza, 'Z');
	Zwiadowcy[1] = CNpcSpec(23, 55, pPlansza, 'Z');
	Zwiadowcy[2] = CNpcSpec(24, 55, pPlansza, 'Z');


	bool test = true; //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	//  WLASCIWA HISTORIA !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	for (int i = 0; i < 9; i++)
	{
		system("cls");
		Zwiadowcy[0].Ruch(22, 55 + i);
		Zwiadowcy[1].Ruch(23, 55 + i);
		Zwiadowcy[2].Ruch(24, 55 + i);
		pPlansza->RysujPlanszeSpec(Albert.x, Albert.y);
		Sleep(500);

	}
	//....................................................................................................
	if (test)
	{
	cout << endl << endl << "Zwiadowca: Panie.. <ciezko oddech> Wlasnie wracamy ze zwiadu" << endl;
	Sleep(4000);
	cout << endl << "Albert Talbarski: Mow!" << endl;
	Sleep(3000);
	cout << endl << "Zwiadowca: Wioska pusta, sami wiesniacy, jedyne co, to wzniesli prowizoryczna brame" << endl;
	Sleep(5000);
	cout << endl << "Albert Talbarski: Ha! Co oni sobie mysla?! Wtedy padla to teraz ma nie pasc?! Taki gniot? HA!" << endl;
	Sleep(5000);
	cout << endl << "Albert Talbarski: TOPORNICY! DO DZIELA Macie mi rozskiekac te brame!" << endl;
	Sleep(5000);
	system("cls");
	}

		Zwiadowcy[1].Ruch(24, 62);
		for (int i = 0; i < 3; i++)
			Zwiadowcy[i].SetStartCoords();

		for (int i = 1; i < 9; i++)
		{
			system("cls");
			Albert.Ruch(Albert.sX, Albert.sY - i);
			for (int j = 0; j < 49; j++)
			{
				Topornicy[j].Ruch(Topornicy[j].sX, Topornicy[j].sY - i);
				Topornicy2[j].Ruch(Topornicy2[j].sX, Topornicy2[j].sY - i);
			}
			pPlansza->RysujPlanszeSpec(Albert.x, Albert.y);
			Sleep(500);

		}
		Albert.SetStartCoords();
		for (int j = 0; j < 49; j++)
		{
			Topornicy[j].SetStartCoords();
			Topornicy2[j].SetStartCoords();
		}
		k = 0;
		for (int i = 1; i < 7; i++) // 6 pol w lewo TOPORY
		{
			system("cls");
			Albert.Ruch(Albert.sX, Albert.sY - i);
			Zwiadowcy[1].Ruch(Zwiadowcy[1].sX, Zwiadowcy[1].sY - i);
			for (int j = 21; j < 49; j +=7)
			{
				
				Topornicy[j].Ruch(Topornicy[j].sX, Topornicy[j].sY - i);
				Topornicy2[k].Ruch(Topornicy2[k].sX, Topornicy2[k].sY - i);
				k += 7;
			}
			pPlansza->RysujPlanszeSpec(Albert.x, Albert.y);
			Sleep(500);
			k = 0;

		}
		Albert.SetStartCoords();
		Zwiadowcy[1].SetStartCoords();
		for (int j = 0; j < 49; j += 7 )
		{
			Topornicy[j].SetStartCoords();
			Topornicy2[j].SetStartCoords();
		}
		k = 0;
		for (int i = 1; i < 3; i++) // 2 pol w gore OR  w dol TOPORY
		{
			system("cls");
			Albert.Ruch(Albert.sX, Albert.sY - i);
			Zwiadowcy[1].Ruch(Zwiadowcy[1].sX, Zwiadowcy[1].sY - i);
			for (int j = 42; j > 15; j -= 7)
			{
				Topornicy[j].Ruch(Topornicy[j].sX + i, Topornicy[j].sY);
				Topornicy2[k].Ruch(Topornicy2[k].sX - i, Topornicy2[k].sY);
				k += 7;
			}
			pPlansza->RysujPlanszeSpec(Albert.x, Albert.y);
			Sleep(500);
			k = 0;
		}
		for (int i = 0; i < 22; i += 7)
			Topornicy2[i].Ruch(Topornicy2[i].sX - 3, Topornicy2[i].sY); // 3 krok w gore TOPORTY2
		
		Zwiadowcy[1].Ruch(Zwiadowcy[1].sX, Zwiadowcy[1].sY - 3);

		Zwiadowcy[1].SetStartCoords();
		Albert.SetStartCoords();
		for (int j = 0; j < 49; j += 7)
		{
			Topornicy[j].SetStartCoords();
			Topornicy2[j].SetStartCoords();
		}

		for (int i = 1; i < 5; i++) // 4 pola w lewo TOPORY -> pozycje przy bramie
		{
			system("cls");
			
			for (int j = 21; j < 49; j += 7)
			{

				Topornicy[j].Ruch(Topornicy[j].sX, Topornicy[j].sY - i);
				Topornicy2[k].Ruch(Topornicy2[k].sX, Topornicy2[k].sY - i);
				k += 7;
			}
			pPlansza->RysujPlanszeSpec(Albert.x, Albert.y);
			Sleep(500);
			k = 0;
			if (i > 2) continue;
			Zwiadowcy[1].Ruch(Zwiadowcy[1].sX, Zwiadowcy[1].sY - i);
		}
		for (int j = 0; j < 49; j += 7)
		{
			Topornicy[j].SetStartCoords();
			Topornicy2[j].SetStartCoords();
		}

		if (test)
		{
			cout << endl << endl << "Zwiadowca: Imponujace zgranie i harmonia" << endl;
			Sleep(4000);
			cout << endl << "Albert Talbarski: HA! Pewnie, ze tak! To wkoncy zolnierze Talbaru! A nie jacys chromoleni Dragonczycy!" << endl;
			Sleep(3000);
			cout << endl << "Albert Talbarski: Zelazna dyscyplina i pofesjonalizm! A nie jakies deryktywy obrony!" << endl;
			Sleep(5000);
			cout << endl << "Albert Talbarski: Cholera! Obrony! Kto to widzial zeby OBRONA wiazala sie ze wsparciem agresora!" << endl;
			Sleep(5000);
			//system("cls");
		}

		for (int i = 1; i < 5; i++)
		{
			system("cls");
			Albert.Ruch(Albert.sX, Albert.sY - i);
			pPlansza->RysujPlanszeSpec(Albert.x, Albert.y);
			Sleep(500);

		}
		Albert.SetStartCoords();

		if (test)
		{
			cout << endl << "Albert Talbarski: Co JEST CHOLPY! NIE PIESCIC SIE Z TYM DREWNEM!" << endl;
			Sleep(3000);
			cout << endl << "Albert Talbarski: RAB I SIECZ!" << endl;
			Sleep(2000);
			cout << endl << "Talbarczycy: WAL I KROJ!" << endl;
			Sleep(2000);
			cout << endl << "Talbarczycy: WSZYSTKIE BRAMY POJDA W WIOR!" << endl;
			Sleep(2000);
			cout << endl << "Talbarczycy: RAB I SIECZ!" << endl;
			Sleep(2000);
			cout << endl << "Talbarczycy: WAL I KROJ!" << endl;
			Sleep(2000);
			cout << endl << "Talbarczycy: WSZYSTKIE BRAMY POJDA W WIOR!" << endl;
			Sleep(1000);
			cout << endl << "Talbarczycy: RAB I SIECZ!" << endl;
			Sleep(2000);
			cout << endl << "Talbarczycy: WAL I KROJ!" << endl;
			Sleep(2000);
			cout << endl << "Talbarczycy: WSZYSTKIE BRAMY POJDA W WIOR!" << endl;
			Sleep(2000);
		}



		for (int i = 1; i < 6; i++)
		{
			system("cls");
			Albert.Ruch(Albert.sX, Albert.sY - i);
			pPlansza->RysujPlanszeSpec(Albert.x, Albert.y);
			Sleep(500);
		}
		Albert.SetStartCoords();
		cout << endl << "Albert Talbarski: POKAZE WAM JAK TO SIE ROBI!" << endl;
		Sleep(3000);

		system("cls");
		Topornicy2[0].Ruch(24, 41);
		pPlansza->RysujPlanszeSpec(Albert.x, Albert.y);
		Sleep(500);
		cout << endl << "Albert Talbarski: Z DROGI!" << endl;
		Sleep(2000);
		system("cls");
		Albert.Ruch(Albert.x, Albert.y-1);
		pPlansza->RysujPlanszeSpec(Albert.x, Albert.y);
		Sleep(500);

		if (test)
		{
			cout << endl << "Albert Talbarski: Z ZYCIEM LENIWE KLUCHY" << endl;
			Sleep(2000);
			cout << endl << "Albert Talbarski: RAB I SIECZ!" << endl;
			Sleep(2000);
			cout << endl << "Talbarczycy: WAL I KROJ!" << endl;
			Sleep(2000);
			cout << endl << "Talbarczycy: WSZYSTKIE BRAMY POJDA W WIOR!" << endl;
			Sleep(2000);
		}
		for (int i = 19; i < 27; i++)
		{
			pPlansza->PlanszaSpec[i][39] = puste_pole;
		}
		system("cls");
		pPlansza->RysujPlanszeSpec(Albert.x, Albert.y);
		cout << endl << "Albert Talbarski: Swietna robota panowie! " << endl;
		Sleep(2000);
		
		Albert.SetStartCoords();
		
		for (int i = 1; i < 5; i++)
		{
			system("cls");
			Albert.Ruch(Albert.sX, Albert.sY - i);
			if (i == 3)
			{
				Topornicy2[0].Ruch(23, 40);
				Topornicy2[0].SetStartCoords();
			}
			pPlansza->RysujPlanszeSpec(Albert.x, Albert.y);
			Sleep(500);

		}
		Albert.SetStartCoords();
		cout << endl << "Albert Talbarski: Za mna, bracia! Czas zebrac danine!" << endl;
		Sleep(3000);
		cout << endl << "Albert Talbarski: Do boju! KU CHWALE TALBARU!" << endl;
		Sleep(3000);

		//..............................................................................................

		system("cls");
		pPlansza->RysujPlanszeSpec(23, 58);
		k = 0;
		int proY = 0;
		for (int i = 1; i < 50; i++) 
		{
			system("cls");
			
			for (int j = 0; j < 49; j ++)
			{
				if ((proY = Topornicy[j].sY - i) > 41)
					Topornicy[j].Ruch(Topornicy[j].sX, proY);
				if ((proY = Topornicy2[j].sY - i) > 41)
					Topornicy2[j].Ruch(Topornicy2[j].sX, proY);
				if ((proY = Piki[j].sY - i) > 41)
					Piki[j].Ruch(Piki[j].sX, proY);
				if ((proY = Piki2[j].sY - i) > 41)
					Piki2[j].Ruch(Piki2[j].sX, proY);
				if ((proY = Luki[j].sY - i) > 41)
					Luki[j].Ruch(Luki[j].sX, proY);
				if ((proY = Luki2[j].sY - i) > 41)
					Luki2[j].Ruch(Luki2[j].sX, proY);
				
				
			}
			pPlansza->RysujPlanszeSpec(23, 58);
			Sleep(500);
		

		}
		
		system("cls");
		for (int j = 0; j < 49; j++)
		{
				Topornicy[j].Ruch(0, 0);			
				Topornicy2[j].Ruch(0, 0);		
				Piki[j].Ruch(0, 0);			
				Piki2[j].Ruch(0, 0);			
				Luki[j].Ruch(0, 0);		
				Luki2[j].Ruch(0, 0);
		}




		system("cls");

		{
			pPlansza->PlanszaSpec[26][13].SymbolPola = 'L';
			pPlansza->PlanszaSpec[26][9].SymbolPola = 'L';
			pPlansza->PlanszaSpec[27][8].SymbolPola = 'L';
			pPlansza->PlanszaSpec[29][3].SymbolPola = 'L';
			pPlansza->PlanszaSpec[28][3].SymbolPola = 'L';
			pPlansza->PlanszaSpec[32][2].SymbolPola = 'L';
			pPlansza->PlanszaSpec[29][15].SymbolPola = 'L';
			pPlansza->PlanszaSpec[32][15].SymbolPola = 'L';
			pPlansza->PlanszaSpec[34][12].SymbolPola = 'L';
			pPlansza->PlanszaSpec[24][28].SymbolPola = 'L';
			pPlansza->PlanszaSpec[34][30].SymbolPola = 'L';
			pPlansza->PlanszaSpec[32][29].SymbolPola = 'L';
			pPlansza->PlanszaSpec[27][30].SymbolPola = 'L';
			pPlansza->PlanszaSpec[29][33].SymbolPola = 'L';
			pPlansza->PlanszaSpec[29][37].SymbolPola = 'L';
			pPlansza->PlanszaSpec[35][37].SymbolPola = 'L';
			pPlansza->PlanszaSpec[12][15].SymbolPola = 'L';
			pPlansza->PlanszaSpec[10][17].SymbolPola = 'L';
			pPlansza->PlanszaSpec[13][17].SymbolPola = 'L';
			pPlansza->PlanszaSpec[20][21].SymbolPola = 'L';
			pPlansza->PlanszaSpec[16][23].SymbolPola = 'P';
			pPlansza->PlanszaSpec[15][24].SymbolPola = 'P';
			pPlansza->PlanszaSpec[12][26].SymbolPola = 'P';
			pPlansza->PlanszaSpec[11][32].SymbolPola = 'P';
			pPlansza->PlanszaSpec[12][35].SymbolPola = 'P';
			pPlansza->PlanszaSpec[16][35].SymbolPola = 'P';
			pPlansza->PlanszaSpec[19][36].SymbolPola = 'P';
			pPlansza->PlanszaSpec[22][27].SymbolPola = 'P';
			pPlansza->PlanszaSpec[23][23].SymbolPola = 'P';
			pPlansza->PlanszaSpec[23][19].SymbolPola = 'P';
			pPlansza->PlanszaSpec[27][18].SymbolPola = 'P';
			pPlansza->PlanszaSpec[27][15].SymbolPola = 'P';
			pPlansza->PlanszaSpec[27][14].SymbolPola = 'P';
			pPlansza->PlanszaSpec[30][6].SymbolPola = 'P';
			pPlansza->PlanszaSpec[29][3].SymbolPola = 'P';
			pPlansza->PlanszaSpec[31][4].SymbolPola = 'P';
			pPlansza->PlanszaSpec[31][9].SymbolPola = 'P';
			pPlansza->PlanszaSpec[26][15].SymbolPola = 'P';
			pPlansza->PlanszaSpec[30][18].SymbolPola = 'P';
			pPlansza->PlanszaSpec[32][21].SymbolPola = 'P';
			pPlansza->PlanszaSpec[30][24].SymbolPola = 'P';
			pPlansza->PlanszaSpec[28][26].SymbolPola = 'P';
			pPlansza->PlanszaSpec[26][26].SymbolPola = 'P';
			pPlansza->PlanszaSpec[31][36].SymbolPola = 'P';
			pPlansza->PlanszaSpec[16][12].SymbolPola = 'P';
			pPlansza->PlanszaSpec[21][15].SymbolPola = 'T';
			pPlansza->PlanszaSpec[18][20].SymbolPola = 'T';
			pPlansza->PlanszaSpec[14][20].SymbolPola = 'T';
			pPlansza->PlanszaSpec[12][21].SymbolPola = 'T';
			pPlansza->PlanszaSpec[11][22].SymbolPola = 'T';
			pPlansza->PlanszaSpec[13][24].SymbolPola = 'T';
			pPlansza->PlanszaSpec[13][25].SymbolPola = 'T';
			pPlansza->PlanszaSpec[16][22].SymbolPola = 'T';
			pPlansza->PlanszaSpec[18][27].SymbolPola = 'T';
			pPlansza->PlanszaSpec[17][32].SymbolPola = 'T';
			pPlansza->PlanszaSpec[14][33].SymbolPola = 'T';
			pPlansza->PlanszaSpec[13][30].SymbolPola = 'T';
			pPlansza->PlanszaSpec[11][28].SymbolPola = 'T';
			pPlansza->PlanszaSpec[27][9].SymbolPola = 'T';
			pPlansza->PlanszaSpec[33][8].SymbolPola = 'T';
			pPlansza->PlanszaSpec[31][6].SymbolPola = 'T';
			pPlansza->PlanszaSpec[33][4].SymbolPola = 'T';
			pPlansza->PlanszaSpec[28][15].SymbolPola = 'T';
			pPlansza->PlanszaSpec[27][15].SymbolPola = 'T';
			pPlansza->PlanszaSpec[30][20].SymbolPola = 'T';
			pPlansza->PlanszaSpec[35][14].SymbolPola = 'T';
			pPlansza->PlanszaSpec[34][19].SymbolPola = 'T';
			pPlansza->PlanszaSpec[19][12].SymbolPola = 'T';




		}

		pPlansza->RysujPlanszeSpec(Albert.x, Albert.y);
		Zwiadowcy[0].Ruch(44, 38);
		Zwiadowcy[1].Ruch(44, 40);
		Zwiadowcy[2].Ruch(44, 36);

		if (test)
		{
			cout << endl << endl << "ARGHHHHHHHHHH" << endl;
			Sleep(1000);
			cout << endl << "< swist >" << endl;
			Sleep(1000);
			cout << endl << "OUGHHHHH" << endl;
			Sleep(1000);
			cout << endl << "LUCZNICY NA DACHACH" << endl;
			Sleep(2000);
			cout << endl << "Albert Talbarski: DO BUDYNKOW! ZA TARCZE!" << endl;
			Sleep(2000);
			cout << endl << "Albert Talbarski: RAZEM! FORMACJA!" << endl;
			Sleep(2000);
			cout << endl << "Panie, nieprzyjaciel naciera z glebi wioski" << endl;
			Sleep(2000);
		}
		k = 0;
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 10; j++)
				Wrog2[k++] = CNpcSpec(18 + i, j, pPlansza, 1);

		k = 0;
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 18; j++)
				Wrog3[k++] = CNpcSpec(28 + i, j, pPlansza, 1);

		system("cls");
		pPlansza->RysujPlanszeSpec(22, 13);

		cout << endl << "Albert Talbarski: CHOLERNI ZWIADOWCY! WSZYSCY ZAWISNA!" << endl;
		Sleep(2000);
		cout << endl << "Albert Talbarski: ODWROT! ODWROT!" << endl;
		Sleep(2000);
		


		k = 0;
		for (int i = 0; i < 17; i++)
			for (int j = 0; j < 27; j++)
				Wrog1[k++] = CNpcSpec(13 + i, 41 + j, pPlansza, 1);

		system("cls");
		pPlansza->RysujPlanszeSpec(22, 36);
		cout << endl << "Albert Talbarski: CHOLERA!" << endl;
		Sleep(2000);
		cout << endl << "Albert Talbarski: RAZEM! BEZ STRACHU W SERCU!" << endl;
		Sleep(2000);
		cout << endl << "Albert Talbarski: UTRZYMAC TEREN! UTRZYMAC TEREN!" << endl;
		Sleep(2000);
		system("cls");
		{
			pPlansza->PlanszaSpec[22][31].SymbolPola = 'P';
			pPlansza->PlanszaSpec[21][31].SymbolPola = 'P';
			pPlansza->PlanszaSpec[19][34].SymbolPola = 'P';
			pPlansza->PlanszaSpec[19][35].SymbolPola = 'P';
			pPlansza->PlanszaSpec[19][37].SymbolPola = 'P';
			pPlansza->PlanszaSpec[21][38].SymbolPola = 'P';
			pPlansza->PlanszaSpec[23][38].SymbolPola = 'P';
			pPlansza->PlanszaSpec[26][38].SymbolPola = 'P';
			pPlansza->PlanszaSpec[33][32].SymbolPola = 'P';
			pPlansza->PlanszaSpec[31][32].SymbolPola = 'P';
			pPlansza->PlanszaSpec[33][31].SymbolPola = 'P';
			pPlansza->PlanszaSpec[31][31].SymbolPola = 'P';
			pPlansza->PlanszaSpec[29][31].SymbolPola = 'P';
			pPlansza->PlanszaSpec[27][31].SymbolPola = 'P';
			pPlansza->PlanszaSpec[24][31].SymbolPola = 'T';
			pPlansza->PlanszaSpec[23][31].SymbolPola = 'T';
			pPlansza->PlanszaSpec[20][31].SymbolPola = 'T';
			pPlansza->PlanszaSpec[19][31].SymbolPola = 'T';
			pPlansza->PlanszaSpec[19][32].SymbolPola = 'T';
			pPlansza->PlanszaSpec[19][33].SymbolPola = 'T';
			pPlansza->PlanszaSpec[19][38].SymbolPola = 'T';
			pPlansza->PlanszaSpec[20][38].SymbolPola = 'T';
			pPlansza->PlanszaSpec[22][38].SymbolPola = 'T';
			pPlansza->PlanszaSpec[24][38].SymbolPola = 'T';
			pPlansza->PlanszaSpec[25][38].SymbolPola = 'T';
			pPlansza->PlanszaSpec[28][31].SymbolPola = 'T';
			pPlansza->PlanszaSpec[35][32].SymbolPola = 'T';
			pPlansza->PlanszaSpec[34][32].SymbolPola = 'T';
			pPlansza->PlanszaSpec[32][32].SymbolPola = 'T';
			pPlansza->PlanszaSpec[34][31].SymbolPola = 'T';
			pPlansza->PlanszaSpec[32][31].SymbolPola = 'T';
			pPlansza->PlanszaSpec[30][31].SymbolPola = 'T';
			pPlansza->PlanszaSpec[28][31].SymbolPola = 'T';
			pPlansza->PlanszaSpec[26][31].SymbolPola = 'T';

			pPlansza->PlanszaSpec[25][32].SymbolPola = 'L';
			pPlansza->PlanszaSpec[24][32].SymbolPola = 'L';
			pPlansza->PlanszaSpec[23][32].SymbolPola = 'L';
			pPlansza->PlanszaSpec[22][32].SymbolPola = 'L';
			pPlansza->PlanszaSpec[21][32].SymbolPola = 'L';
			pPlansza->PlanszaSpec[20][32].SymbolPola = 'L';
			pPlansza->PlanszaSpec[20][33].SymbolPola = 'L';
			pPlansza->PlanszaSpec[20][34].SymbolPola = 'L';
			pPlansza->PlanszaSpec[20][35].SymbolPola = 'L';
			pPlansza->PlanszaSpec[20][36].SymbolPola = 'L';
			pPlansza->PlanszaSpec[20][37].SymbolPola = 'L';
			pPlansza->PlanszaSpec[20][38].SymbolPola = 'L';
			pPlansza->PlanszaSpec[21][38].SymbolPola = 'L';
			pPlansza->PlanszaSpec[22][38].SymbolPola = 'L';
			pPlansza->PlanszaSpec[23][38].SymbolPola = 'L';
			pPlansza->PlanszaSpec[25][38].SymbolPola = 'L';
			pPlansza->PlanszaSpec[24][38].SymbolPola = 'L';
			pPlansza->PlanszaSpec[30][32].SymbolPola = 'L';
			pPlansza->PlanszaSpec[29][32].SymbolPola = 'L';
			pPlansza->PlanszaSpec[28][32].SymbolPola = 'L';
			pPlansza->PlanszaSpec[27][32].SymbolPola = 'L';
			pPlansza->PlanszaSpec[26][32].SymbolPola = 'L';
			pPlansza->PlanszaSpec[31][33].SymbolPola = 'L';
			pPlansza->PlanszaSpec[30][33].SymbolPola = 'L';
			pPlansza->PlanszaSpec[29][33].SymbolPola = 'L';
			pPlansza->PlanszaSpec[28][33].SymbolPola = 'L';
			pPlansza->PlanszaSpec[27][33].SymbolPola = 'L';
			pPlansza->PlanszaSpec[26][33].SymbolPola = 'L';
			pPlansza->PlanszaSpec[25][33].SymbolPola = 'L';
			pPlansza->PlanszaSpec[24][33].SymbolPola = 'L';
			pPlansza->PlanszaSpec[23][33].SymbolPola = 'L';
			pPlansza->PlanszaSpec[22][33].SymbolPola = 'L';
			pPlansza->PlanszaSpec[21][33].SymbolPola = 'L';
			pPlansza->PlanszaSpec[21][34].SymbolPola = 'L';
			pPlansza->PlanszaSpec[21][35].SymbolPola = 'L';
			pPlansza->PlanszaSpec[21][36].SymbolPola = 'L';
			pPlansza->PlanszaSpec[21][37].SymbolPola = 'L';
			pPlansza->PlanszaSpec[21][38].SymbolPola = 'L';


		}


		


		CNpcSpec GrupaRatunkowa[4];
		
		GrupaRatunkowa[0] = CNpcSpec(25, 34, pPlansza, 'T');
		GrupaRatunkowa[1] = CNpcSpec(25, 35, pPlansza, 'X');
		GrupaRatunkowa[2] = CNpcSpec(25, 36, pPlansza, 'P');
		GrupaRatunkowa[3] = CNpcSpec(26, 37, pPlansza, 'P');
		pPlansza->RysujPlanszeSpec(GrupaRatunkowa[1].x, GrupaRatunkowa[1].y);

		if (test)
		{
			Sleep(2000);
			cout << endl << "Albert Talbarski: Musicie wydostac sie z miasta!" << endl;
			Sleep(2000);
			cout << endl << "Albert Talbarski: Za rzeka stacjonuje wojska Ksiecia!" << endl;
			Sleep(2000);
			cout << endl << "Albert Talbarski: Proscie o wsparcie.. Kawaleria powinna zdarzyc!" << endl;
			Sleep(2000);
			cout << endl << pHero->RetName() << ": Ale.." << endl;
			Sleep(500);
			cout << endl << "Albert Talbarski: ZADNYCH ALE! TO JEST CHROMOLONY ROZKAZ!" << endl;
			Sleep(2000);
			cout << endl << "Albert Talbarski: WYKONAC!" << endl;
			Sleep(1000);
			cout << endl << "Albert Talbarski: Tam, wysoki budynek! Jesli dostaniecie sie na dach powinno Wam sie udac! A teraz BIEGNIJCIE!" << endl;
			Sleep(5000);
			cout << endl << pHero->RetName() << ": Tak jest...." << endl;
			Sleep(1000);

			cout << endl << endl << "Albert Talbarski: PANOWIE! TERAZ ZOBACZYMY ILE JESTEMY WARCI!" << endl;
			Sleep(4000);
			cout << endl << endl << "Albert Talbarski: Smierc to nasz odwieczny towarzysz." << endl;
			Sleep(4000);
			cout << endl << "Albert Talbarski: Zawsze podaza po naszej lewej, na wyci¹gniêcie reki za nami. " << endl;
			Sleep(4000);
			cout << endl << "Albert Talbarski: To jedyny madry doradca, na jakiego mo¿e liczyc wojownik. " << endl;
			Sleep(4000);
			cout << endl << "Albert Talbarski: Jesli wydaje mu sie, ze wszystko zmierza ku zlemu i ze za chwile zostanie unicestwiony, wojownik moze obrocic sie ku smierci i spytac, czy faktycznie tak jest. " << endl;
			Sleep(6000);
			cout << endl << "Albert Talbarski: Smierc odpowie mu wowczas, ¿e sie myli, ze jedynie jej dotkniêcie siê liczy. " << endl;
			Sleep(4000);
			cout << endl << "Albert Talbarski: A ja jeszcze Cie nie dotknelam, powie.!" << endl;
			Sleep(6000);
			//Carlos Castaneda, Journey to Ixtlan



			system("cls");
			pPlansza->RysujPlanszeSpec(GrupaRatunkowa[0].x, GrupaRatunkowa[0].y);
			cout << "Albert Talbarski: PLACZCIE! KRZYCZCIE! WOLAJCIE MATKE! MOCZCIE SPODNIE!" << endl;
			Sleep(3000);
			cout << endl << "Albert Talbarski: ALE ROZKAZ MA BYC WYKONANY! TYLKO TO SIE LICZY!" << endl;
			Sleep(3000);
			cout << endl << "Albert Talbarski: A ROZKAZ BRZMI!" << endl;
			Sleep(3000);
			cout << endl << "Albert Talbarski: UPUSCIE KRWII TYM ***********!" << endl;
			Sleep(4000);

			cout << endl << endl << "ARGHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH" << endl;
			Sleep(3000);

		}


		for (int i = 1; i < 3 ; i++)
		{
			system("cls");
			GrupaRatunkowa[0].Ruch(GrupaRatunkowa[0].sX+i, GrupaRatunkowa[0].sY);
			GrupaRatunkowa[1].Ruch(GrupaRatunkowa[1].sX+i, GrupaRatunkowa[1].sY);
			GrupaRatunkowa[2].Ruch(GrupaRatunkowa[2].sX+i, GrupaRatunkowa[2].sY);
			if(i == 1)
				GrupaRatunkowa[3].Ruch(GrupaRatunkowa[3].sX, GrupaRatunkowa[3].sY-1);
			
			pPlansza->RysujPlanszeSpec(GrupaRatunkowa[1].x, GrupaRatunkowa[1].y);
			Sleep(500);
			
		}

		for (int i = 0; i < 4; i++)
			GrupaRatunkowa[i].SetStartCoords();

		

		k = 0;
		for (int i = 1; i < 18; i++)
		{
			system("cls");

			for (int j = 3; j > -1; j--)
			{
				proY = GrupaRatunkowa[j].sY + i;
				if (proY < 39)
					GrupaRatunkowa[j].Ruch(GrupaRatunkowa[j].sX, proY);
				else 
					GrupaRatunkowa[j].Ruch(GrupaRatunkowa[j].x + 1, GrupaRatunkowa[j].y);
			}

			pPlansza->RysujPlanszeSpec(GrupaRatunkowa[1].x, GrupaRatunkowa[1].y);
			Sleep(500);

		}
		

		GrupaRatunkowa[0].Ruch(43, 36);
		GrupaRatunkowa[1].Ruch(43, 38);
		GrupaRatunkowa[2].Ruch(43, 37); 
		GrupaRatunkowa[3].Ruch(43, 39);
		system("cls");
		pPlansza->RysujPlanszeSpec(GrupaRatunkowa[1].x, GrupaRatunkowa[1].y);
		cout << endl << pHero->RetName() << ": Pomozcie! Blagam !" << endl;
		Sleep(3000);
		cout << endl << pHero->RetName() << ": Jako zwiadowcy macie najlepsze konie!" << endl;
		Sleep(3000);
		cout << endl << pHero->RetName() << ": Kazdy skrot!" << endl;
		Sleep(1500);
		cout << endl << pHero->RetName() << ": Ksiaze MUSI sie o wszystkim dowiedziec!" << endl;
		Sleep(3000);
		cout << endl << pHero->RetName() << ": Bedziecie za rzeka szybcej niz my!" << endl;
		Sleep(3000);
		cout << endl << pHero->RetName() << ": Potrzebujemy wsparcie.. BLAGAM.. pomozcie...." << endl;
		Sleep(3000);
		cout << endl << "Zwiadowca: Wybacz... niestety nie mozemy tego zrobic..." << endl;
		Sleep(3000);
		//27,38
		/*
		GrupaRatunkowa[0] = CNpcSpec(25, 35, pPlansza, 'X');
		GrupaRatunkowa[1] = CNpcSpec(25, 35, pPlansza, 'T');
		GrupaRatunkowa[2] = CNpcSpec(25, 36, pPlansza, 'P');
		GrupaRatunkowa[3] = CNpcSpec(26, 37, pPlansza, 'P');
		*/

		/*
	int x = 25, y = 25, prevX = 0, prevY = 0;
	pole PolePostaci;
	pole Soldier = { 1, 'S' };
	PolePostaci.SymbolPola = 'X';
	PolePostaci.NumerZdarzenia = 10;
	fstream plik;
	while (1)
	{
		
		system("cls");
		pPlansza->RysujPlanszeSpec(x, y);
		
		cout << "X = " << x << ", " << "Y = " << y;
		pPlansza->PlanszaSpec[x][y] = puste_pole;
		prevX = x;
		prevY = y;
		int decyzja = _getch();
		if (decyzja == 224)
			decyzja = _getch();
		switch (decyzja)
		{
		case 27: return;

		case 80: //strza³ka w dó³
		{
			if (pPlansza->PlanszaSpec[x + 1][y].NumerZdarzenia == 0)
			{
				pPlansza->PlanszaSpec[x + 1][y] = PolePostaci;
				x += 1;
			}
			break;
		}
		case 72: //strza³ka w góre
		{

			if (pPlansza->PlanszaSpec[x + 1][y].NumerZdarzenia == 0)
			{
				pPlansza->PlanszaSpec[x - 1][y] = PolePostaci;
				x -= 1;

			}
			break;
		}
		case 75: //strza³ka w lewo
		{

			if (pPlansza->PlanszaSpec[x + 1][y].NumerZdarzenia == 0)
			{
				pPlansza->PlanszaSpec[x][y - 1] = PolePostaci;
				y -= 1;
			}
			break;
		}
		case 77: //strza³ka w prawo
		{
			if (pPlansza->PlanszaSpec[x + 1][y].NumerZdarzenia == 0)
			{
				pPlansza->PlanszaSpec[x][y + 1] = PolePostaci;
				y += 1;
			}
			break;
		}
		
		case '1': {

			pPlansza->PlanszaSpec[x][y] = sciana;
			plik.open("Funkcja_sciana.txt", ios::out | ios::app);
			if (plik.good() == false)
				return;

			plik << "pPlansza->PlanszaSpec[" << x << "][" << y << "] = sciana;" << endl;


			plik.close();
			x = prevX-1;
			y = prevY;
			break;
		}

		case '2': {

			pPlansza->PlanszaSpec[x][y] = sufit;
			plik.open("Funkcja_sufit.txt", ios::out | ios::app);
			if (plik.good() == false)
				return;

			plik << "pPlansza->PlanszaSpec[" << x << "][" << y << "] = sufit;" << endl;


			plik.close();
			x = prevX - 1;
			y = prevY;
			break;
		}

		case '3': {

			pPlansza->PlanszaSpec[x][y] = drzewo;
			plik.open("Funkcja_las.txt", ios::out | ios::app);
			if (plik.good() == false)
				return;

			plik << "pPlansza->PlanszaSpec[" << x << "][" << y << "] = drzewo;" << endl;


			plik.close();
			x = prevX - 1;
			y = prevY;
			break;
		}

		case 'k': 
		{
			x += 10;
			break;
		}

		case 'l':
		{
			y += 10;
			break;
		}
		case 'j':
		{
			y -= 10;
			break;
		}
		case 'i':
		{
			x -= 10;
			break;
		}

		case '5':
		{
			for (int i = 0; i < 7; i++)
				for (int j = 0; j < 7; j++)
					pPlansza->PlanszaSpec[x + i][y + j] = Soldier;

			break;
		}

		case '6':
		{
			CDom(x, y, 1, pPlansza).RysujObiektHistoriaAsgaru();
			plik.open("Funkcja_Domki.txt", ios::out | ios::app);
			if (plik.good() == false)
				return;

			plik << "CDom(" << x << ", " << y << ", 1, pPlansza).RysujObiektHistoriaAsgaru();" << endl;


			plik.close();

		}

		case '8':
		{
			pPlansza->PlanszaSpec[x][y].SymbolPola = 'T';
			plik.open("Funkcja_topory.txt", ios::out | ios::app);
			if (plik.good() == false)
				return;

			plik << "pPlansza->PlanszaSpec[" << x << "][" << y << "].SymbolPola = 'T';" << endl;


			plik.close();
			x = prevX - 1;
			y = prevY;
			
			break;
		}

		case '9':
		{
			pPlansza->PlanszaSpec[x][y].SymbolPola = 'P';
			plik.open("Funkcja_piki.txt", ios::out | ios::app);
			if (plik.good() == false)
				return;

			plik << "pPlansza->PlanszaSpec[" << x << "][" << y << "].SymbolPola = 'P';" << endl;


			plik.close();
			x = prevX - 1;
			y = prevY;

			break;
		}

		case '0':
		{
			pPlansza->PlanszaSpec[x][y].SymbolPola = 'L';
			plik.open("Funkcja_luki.txt", ios::out | ios::app);
			if (plik.good() == false)
				return;

			plik << "pPlansza->PlanszaSpec[" << x << "][" << y << "].SymbolPola = 'L';" << endl;


			plik.close();
			x = prevX - 1;
			y = prevY;

			break;
		}	


		default: cout << "Nie ma czegos takiego" << endl;




		}

		pPlansza->PlanszaSpec[x][y] = PolePostaci;
		
	}
	*/

}


bool CFabula::CzyJestWTymObszarze(int x, int y, int ObszarX, int ObszarY, int width, int heigth)
{
	if (x >= ObszarX && x <= (ObszarX + heigth))
	{
		if (y >= ObszarY && y <= (ObszarY + width))
			return true;
	}


	return false;
}

void CFabula::DostepDoMiasta()
{
	if (bDostepDoMiasta) return;
	if (bBrakMostu == false) return;
	
	if (bSzacunekStraznika == true && bSzacunekFarmera == true && bSzacunekWiezniarza == true)
	{
		pPlansza->Plansza[39][40] = puste_pole;
		pPlansza->Plansza[40][40] = puste_pole;
		bDostepDoMiasta = true;
		StanKlepsydra = 1;

	}
}

bool CFabula::SprPoprawnoscArii()
{
	int Ilosc = Fragment[1].MaxNumber;
	int poprawnosc = 0;
	
	
	/*
	for (int i = 0; i < pHero->Plecak.size(); i++)
	{
		if (pHero->Plecak[i]->Rodzaj == ARIA)
		{
			if (static_cast<const CFragmentOfPoem*>(pHero->Plecak[i])->UstawKolejnosc(this))
			{
				++poprawnosc;
				
				continue;
			}

			
		}
	}
	*/

	system("cls");

	for (int i = 0; i < Ilosc; i++)
	{
		if (FragmentOpis[i].isGood == false)
		{
			cout << endl << endl << pHero->RetName() << ": Hmm... Chyba cos tu pokrecilem..." << endl;
			_getch();

			return false;
		}

		cout << "                  " << Fragment[i].Opis << endl << endl;
		Sleep(2000);
	}

	
	cout << endl << endl << pHero->RetName() << ": Chyba sie udalo..." << endl << endl;
	_getch();



	return true;	
}

void CFabula::SprFabula()
{
	if (Akt1)  // AKT PIERWSZY
	{
		WyjscieZPol();
		BrakMostu();
		KolesZaRzeka();
		SzacunekStraznika();
		Klepsydra();
		PrzejscieNaPolach();
		GildiaZlodzieji();
		OtwieranieDrzwiLina();
		MarszDrzew();
		FinalQuest();
		TeodorPodziemia();
	}


}
void CFabula::SzacunekStraznika() // eksorta Teodora
{
	if (StanSzacunekStraznika != 6) return;
	
	
		if ( pHero->retY() == 29 )
		{
			pHero->UsunPostacZMapy();
			pHero->SetXY(pHero->RetPrevX(), pHero->RetPrevY());
			pHero->RysujPostac();
			cout << endl << endl << "Teodor: Mysle ze zle skrecilismy, juz widac las... Do farmy to nie w te srone.." << endl;
			_getch();
			return;
		}
		if (pHero->retX() == 27)
		{
			pHero->UsunPostacZMapy();
			pHero->SetXY(pHero->RetPrevX(), pHero->RetPrevY());
			pHero->RysujPostac();
			cout << endl << endl << "Teodor: Musimy isc na farmy a nie do miasta..." << endl;
			_getch();
			return;
		}

		if (pHero->retX() == 27)
		{
			pHero->UsunPostacZMapy();
			pHero->SetXY(pHero->RetPrevX(), pHero->RetPrevY());
			pHero->RysujPostac();
			cout << endl << endl << "Teodor: Musimy isc na farmy a nie do miasta..." << endl;
			_getch();
			return;
		}


		if (pHero->retX() == 7)
		{
			pHero->UsunPostacZMapy();
			pHero->SetXY(pHero->RetPrevX(), pHero->RetPrevY());
			pHero->RysujPostac();
			cout << endl << endl  << "Teodor: Chyba poszlismy za daleko..." << endl;
			_getch();
			return;
		}


		if (pHero->retX() == 16 && pHero->retY() <= 13)
		{		
			
				cout << endl << endl << "Teodor: Oho.. Juz widac moj dom!..." << endl;
				_getch();	

		}

		if (pHero->retX() == 11 && pHero->retY() == 11 || pHero->retX() == 11 && pHero->retY() == 12)
		{

			cout << endl << endl << "Teodor chwycil niepewnie za klamke drzwi..." << endl;
			Sleep(1000);
			cout << "." << endl;
			Sleep(1000);
			cout << "." << endl;
			Sleep(1000);
			cout << "." << endl;
			Sleep(1000);
			cout << "Dom zdaje sie byc pusty..." << endl;			
			Sleep(1000);
			cout << "." << endl;
			Sleep(1000);
			cout << "." << endl;
			Sleep(1000);
			cout << "." << endl;
			Sleep(1000);
			cout << "Teodor niespokojnie rozglada sie po pokojach..." << endl;					
			Sleep(1000);
			cout << "." << endl;
			Sleep(1000);
			cout << "." << endl;
			Sleep(1000);
			cout << "." << endl;
			Sleep(1000);
			cout << "Skrzyp otwieranych drzwi..." << endl;
			Sleep(1000);
			cout << "Dostrzegacie w drzwiach kobiete, niosaca kosz jablek..." << endl;
			Sleep(1000);
			cout << "." << endl;
			Sleep(1000);
			cout << "." << endl;
			Sleep(1000);
			cout << "." << endl;
			Sleep(1000);
			cout << "Jej oczy wypelniaja sie lzami" << endl;
			Sleep(1000);
			cout << "Dzwiek upuszczanego kosza i turlajacych sie jablek..." << endl;
			Sleep(1000);
			cout << "Teodor: Wybacz...Nie udalo mi sie zdobyc drewna..." << endl;
			Sleep(1000);
			cout << "." << endl;
			Sleep(1000);
			cout << "." << endl;
			Sleep(1000);
			cout << "." << endl;
			Sleep(1000);
			cout << "Kobieta skrywa sie w ramionach meza..." << endl;
			Sleep(1000);
			cout << "." << endl;
			Sleep(1000);
			cout << "." << endl;
			Sleep(1000);
			cout << "." << endl;
			cout << pHero->RetName() <<": < Nie bede im przeszkadzal... >" << endl;
			_getch();



			pTeodor->UsunPostacZMapy();
			StanSzacunekStraznika = 7;
			pTeodor->SetXY(13,11);			

			pTeodor->SetNumerZdarzenia(154);
			if (StanOpowiescTeodora == 1)
				pTeodor->SetNumerZdarzenia(160);

			pTeodor->LoadNpcToBoard();
			pTeodor->RysujPostac();


			pZonaTeodora->SetNumDialogu(100);
			
			return;

		}

		pTeodor->UsunWskaznikPostaciZMapy();
		pTeodor->UsunPostacZMapy();
		pTeodor->SetXY(pHero->RetPrevX(), pHero->RetPrevY());
		pTeodor->RysujPostac();
	
	
}

void CFabula::TeodorPodziemia()
{
	if (!bTeodorPodziemia)
		return;



	if (pHero->RetisUndergorund() == false)
	{
		cout << endl << endl << pHero->RetName() << ": Heh.. A jednak sie udalo.." << endl;
		cout << endl << pHero->RetName() << ": TEODOR! HEJJ! TEODOR! WYJSCIE! ZNALAZLEM WYJSCIE" << endl;


		system("cls");

		pTeodor->UsunPostacWrazZWskaznikiem(true);
		pTeodor->SetXY(pHero->retX(), pHero->retY() + 1);
		pTeodor->SetNumerZdarzenia(143);
		pTeodor->RysujPostac();
		pPlansza->RysujPlansze();

		
		bTeodorPodziemia = false;


	}


}

void CFabula::KolesZaRzeka()
{
	if (bKolesZaRzeka) return;
	if (bBrakMostu == false) return;
	if (pHero->retY() == 64)
	{
		pKolesZaRzeka = new CNPC("Straznik", 'S', 102, pHero->retX(), 63, Straznik,pPlansza);
		pKolesZaRzeka->RysujPostac();
		pKolesZaRzeka->LoadNpcToBoard();
	
		AkcjaWynikajacaZDiagolu(WyswietlDialog(Odpowiedzi, Oddzywki, 102, pHero->RetName(), pKolesZaRzeka->RetName()), pKolesZaRzeka);

		WyszukajDialog(Oddzywki, 9)->MoliweOdp[0] = 0;
		pKolesZaRzeka->SetNumerZdarzenia(166);
		pKolesZaRzeka->RysujPostac();






		bKolesZaRzeka = true;
	}

}

void CFabula::Dialog(int NumerZdarzenia, string ImieNPC, CCharacter* character)
{
	if(NumerZdarzenia >= 100 && character == NULL)
	{
		cout << endl << pHero->RetName() << ": Nie mamy czasu na pogawedke..." << endl; 
		return;
	}
	cout << endl;
	AkcjaWynikajacaZDiagolu(WyswietlDialog(Odpowiedzi, Oddzywki, NumerZdarzenia,pHero->RetName(), ImieNPC), character);
	//_getch();
}

void CFabula::SzacunekFarmera()
{
	if (bSzacunekFarmera) return;

	static int ilosc_drewna = 0;
	ilosc_drewna += pHero->Itemy.drewno;
	pHero->Itemy.drewno = 0;

	if (ilosc_drewna == 25)
	{
		cout << pFarmer->RetName() <<": Tyle powinno wystarczyc, dziekuje. Oto Twoje 10 sztuk zlota" << endl;
		_getch();
		pHero->Itemy.zloto += 10;
		bSzacunekFarmera = true;
		StanSzacunekFarmera = 2;

	}
	

}

void CFabula::FinalQuest()
{
	if (StanFinalQuest == 0 && pHero->retX() == 40 && pHero->retY() == 9 )
	{
		StanFinalQuest = 1;
		cout << endl << endl << pHero->RetName() << ": Moj krolu..." << endl;
		Sleep(2000);
		cout << endl << "Ziutmelson: Czekalem na Ciebie.. To Ty walczyles pod Asgarem?" << endl;
		Sleep(2000);
		cout << endl << pHero->RetName() << ": Tak, Wasza Wysokosc..." << endl;
		Sleep(2000);
		cout << endl << "Krol spojrzal spojrzal na grupe mezczyz i kobiet stojacych w poblizu drzwi do jednej z komnat..." << endl;
		Sleep(4000);
		cout << endl << "Ziutmelson: A Wy na co czekacie?! Przyniescie jakas strawe!" << endl;
		Sleep(2000);
		cout << endl << "Ziutmelson: A Ty synu siadaj i opowiadaj" << endl;
		Sleep(2000);

		WyszukajPrzedmiot(pHero->RozszerzenieEq, 1)->DodajPrzedmiot();
		WyszukajPrzedmiot(pHero->RozszerzenieEq, 1)->DodajPrzedmiot();
		WyszukajPrzedmiot(pHero->RozszerzenieEq, 8)->DodajPrzedmiot();
		WyszukajPrzedmiot(pHero->RozszerzenieEq, 8)->DodajPrzedmiot();
		WyszukajPrzedmiot(pHero->RozszerzenieEq, 8)->DodajPrzedmiot();
		WyszukajPrzedmiot(pHero->RozszerzenieEq, 9)->DodajPrzedmiot();
		WyszukajPrzedmiot(pHero->RozszerzenieEq, 9)->DodajPrzedmiot();
		WyszukajPrzedmiot(pHero->RozszerzenieEq, 9)->DodajPrzedmiot();
		WyszukajPrzedmiot(pHero->RozszerzenieEq, 11)->DodajPrzedmiot();
		// TODO specjalna pieczen jakis kurczak po zjedzeniu daje moc i sile

		
		cout << endl << endl << "Otrzymales 2x bochenek chleba" << endl;
		cout << "Otrzymales 3x pieczone mieso" << endl;
		cout << "Otrzymales 3x kanapke z szynka" << endl;
		cout << "Otrzymales plynny ogien" << endl;
		cout << "Otrzymales pieczen" << endl;
		_getch();
		return;
	}

	if (StanFinalQuest == 3)
	{
		if (pHero->RetisUndergorund() && pHero->retX() == 31 && pHero->retY() == 1)
		{

			cout << endl << endl << pHero->RetName() << ": Hmm.. cos w rodzaju laboratorium.. Imponujace..." << endl;
			Sleep(2000);
			cout << endl <<  "< rozleglo sie rytmiczne skrzypienie> "<< endl;
			Sleep(2000);
			cout << endl << pHero->RetName() << ": Hmm ?" << endl;
			Sleep(2000);
			cout << endl << "Mezczyzna: Witam.. " << endl;
			Sleep(2000);
			pTajemniczyMezczyzna = new CNPC("Mezczyzna", 'M', 100, 27, 1, Straznik, pPlansza);
			pTajemniczyMezczyzna->RysujPostac(true);
			system("cls");
			pPlansza->RysujPodziemia(pHero->retX(), pHero->retY());
			Sleep(500);

			for (int i = 0; i < 3; i++)
			{
				pTajemniczyMezczyzna->UsunPostacWrazZWskaznikiem(true);
				pTajemniczyMezczyzna->SetXY(pTajemniczyMezczyzna->retX()+1, pTajemniczyMezczyzna->retY());
				pTajemniczyMezczyzna->RysujPostac(true);
				system("cls");
				pPlansza->RysujPodziemia(pHero->retX(), pHero->retY());
				Sleep(1000);
			}

			cout << endl << endl << "Mezczyzna: Mam nadzieje ze zdajesz sobie sprawe z powagi i rangi Twojej misji" << endl;
			Sleep(2000);
			cout << endl << endl << "Mezczyzna: Ilosc osob ktore o niej wiedza mozna policzyc na palcach jedej reki i licze ze tak pozostanie..." << endl;
			Sleep(2000);
			cout << endl << pHero->RetName() << ": Oczywiscie" << endl;
			Sleep(2000);
			cout << endl << "Mezczyzna: To dobrze" << endl;
			Sleep(2000);
			cout << endl << "Mezczyzna: A teraz sie skup bo nie bede powtarzal" << endl;
			Sleep(2000);
			cout << endl << "Mezczyzna: Naszemu kraju zagraza niebezpieczny najezdzca " << endl;
			Sleep(2000);
			cout << endl << "Mezczyzna: To barbazyncy! Bez zasad i honoru.. Przy zyciu utrzymuje ich jednynie zadza krwii i niepochamane chcec niszczenia" << endl;
			Sleep(2000);
			cout << endl << "Mezczyzna: kaza sie zwac Szwadronem" << endl;
			Sleep(2000);
			cout << endl << "Mezczyzna: Udalo sie nam pojmac jednego z ich szpiegow, znajduje sie on teraz w wiezieniu" << endl;
			Sleep(2000);
			cout << endl << "Mezczyzna: I tu zaczyna sie Twoje zadanie" << endl; // varulv
			Sleep(2000);
			cout << endl << "Mezczyzna: Musisz zdobyc jego zaufanie, tylko osoba z zwenatrz moze tego dokonac" << endl;
			Sleep(2000);
			cout << endl << "Mezczyzna: Ale pierw musisz dostac sie do wiezienia. Pamietaj, nikt nie moze wiedziec o Twoim zadaniu" << endl;
			Sleep(2000);
			cout << endl << pHero->RetName() << ": Rozumiem. Zrobie co w mojej mocy" << endl;
			Sleep(2000);
			cout << endl << "Mezczyzna: A i jeszcze jedno nasz wywiad uzyskal pewna ksiazke, mysle ze moze byc kluczem.. Wez ja.. Lezy na jednej z polek.." << endl;
			_getch();


			pTajemniczyMezczyzna->UsunPostacWrazZWskaznikiem(true);
			pTajemniczyMezczyzna->SetXY(31,2);
			pTajemniczyMezczyzna->RysujPostac(true);
			StanFinalQuest = 4;
		}
		return;
	}

	if (StanFinalQuest == 4)
	{
		if (pHero->retX() == 30 && pHero->retY() == 1 && bKsiazkaWilka == false)
		{

			cout << endl << endl << "Mezczyzna: Pospiesz sie i wez te ksiazke.. Ona moze byc kluczem..." << endl;
			_getch();
			pHero->SetXY(31, 1);
			pPlansza->Podziemia[30][1] = puste_pole;
			return;
		}

		if (pHero->retX() == 30 && pHero->retY() == 1 && bKsiazkaWilka )
		{
			StanFinalQuest = 5;
			cout << endl << endl << "Mezczyzna: Prawie bym zapomnial.. Jeszcze ten list.. Powodzenia.." << endl;
			Sleep(2000);
			pHero->Plecak.push_back(&KsiazkaList);
			cout << endl << endl << "Otrzymales list" << endl;
			_getch();

			WyszukajDialog(Odpowiedzi, 316)->MoliweOdp[0] = 248;
		}
		
		return;
	}
	
}

void CFabula::Klepsydra()
{
	if (bKlepsydra)
		return;

	if (StanKlepsydra == 1) // koniecznosc noclegu
	{
		if ((pHero->retX() == 40 && pHero->retY() == 39) || (pHero->retX() == 39 && pHero->retY() == 39))
		{
			cout << endl << endl << "Straznik: STAC! Przejscia nie ma!" << endl;
			Sleep(1000);
			cout << endl << endl << pHero->RetName() <<": Posiadam glejt. Tak wiec legalnie i zgodnie z prawem moge przekorczyc mury miasta" << endl;
			Sleep(2000);
			cout << endl << endl << "Straznik: Nie tak predko przyjacielu.. Nie Ty tu decydujesz o prawie.." << endl;
			Sleep(1000);
			cout << endl << endl << pHero->RetName() << ": Ale nie mozecie..." << endl;
			Sleep(1000);
			cout << endl << endl << "Straznik: Mozemy! Rozkaz jest nie przepuszac nikogo chodzby i glejt mial, jesli przychodzi w czasie nocnym" << endl;
			Sleep(2000);
			cout << endl << endl << "Straznik: A czas nocny obowiazuje od zmierzchu do switu, a slonce zaszlo.. tak wiec dozobaczenia rano.. zegnam" << endl;
			Sleep(2000);
			cout << endl << endl << pHero->RetName() <<": Ale chwila..." << endl;
			Sleep(1000);
			cout << endl << endl << "Straznik: ZEGNAM!" << endl;
			Sleep(1000);
			cout << endl << endl << pHero->RetName() << ": <do siebie> musze znalesc jakis nocleg..." << endl;
			StanKlepsydra = 2;
			_getch();

			pPlansza->Plansza[40][39] = pPlansza->Plansza[39][39] = PoleStrzezone;
			pHero->SetXY(pHero->retX(), 42);

			WyszukajDialog(Odpowiedzi, 114)->MoliweOdp[0] = 117;
			return;
		}

	}

	// 3 stan daje lozko

	if (StanKlepsydra == 3) // odlozenie eq
	{
		if (pHero->NoszonePrzedmioty.Sword != NULL)
			pHero->Plecak.push_back(pHero->NoszonePrzedmioty.Sword);
		if (pHero->NoszonePrzedmioty.Armor != NULL)
			pHero->Plecak.push_back(pHero->NoszonePrzedmioty.Armor);
		if (pHero->NoszonePrzedmioty.UseableItem != NULL)
			pHero->Plecak.push_back(pHero->NoszonePrzedmioty.UseableItem);
		FabulaPlecak = pHero->Plecak;
		pHero->Plecak.clear();
		pHero->NoszonePrzedmioty.Sword = &WeaponSiekiera;
		//pHero->Plecak.push_back(&WeaponSiekiera);
		
			cout << endl << endl << pHero->RetName() << ": Slonce juz swita.. Mysle ze teraz powinni wpuscic mnie do miasta" << endl;
			Sleep(1000);
			cout << endl << endl << pHero->RetName() << ": Ten przewrazliwiony straznik pewnie doczepi sie jeszcze o bron..." << endl;
			Sleep(2000);
			cout << endl << endl << pHero->RetName() << ": Najlepiej wiec bedzie jak go tu zostawie.. Odbiore go potem.. " << endl;
			Sleep(1000);
			cout << "." << endl;
			Sleep(1000);
			cout << "." << endl;
			Sleep(1000);
			cout << "." << endl;
			Sleep(1000);
			cout << endl << endl << pHero->RetName() << ": Dobra.. Tutaj nikt tego nie znajdzie..." << endl;
			Sleep(1000);
			cout << endl << endl << pHero->RetName() << ": Hmm... Siekiera i kosa to narzedzia.. A ja teoretycznie moge byc drwalem.. Tak wiec lepiej to zachowam.. " << endl;
			Sleep(2000);
			cout << endl << endl << pHero->RetName() << ": Co jeszce hmm..." << endl;
			Sleep(2000);
			cout << endl << endl << pHero->RetName() << ": Zloto tez zostawie.. Wezme tylko garsc kto wie jakie oprychy kreca sie po lokalnych karczmach..." << endl;
			Sleep(2000);
			if ( StanWdziecznoscTeodora == 1)
			{
				cout << endl << endl << pHero->RetName() << ": Noz na wilki... Coz teoretycznie to bron ale ... niewielka... latwo mozna schowac.. moze sie przyda..." << endl;
				pHero->Plecak.push_back(&NozNaWilki);

				for (int i = 0; i < FabulaPlecak.size(); i++)
					if (FabulaPlecak[i]->TYP == WEAPON)
						if (FabulaPlecak[i]->Rodzaj == 1)
							FabulaPlecak.erase(FabulaPlecak.begin() + i);

				
				
			}
			Sleep(1000);
			cout << endl << endl << pHero->RetName() << ": Coz... Jestem gotowy.. Lepiej bede uzywac sprawdzonych drog.. Jestem przygotowany do przetrwania w miescie a nie w lesie.." << endl;
			_getch();

						
			FabulaRozszerzenieEq = pHero->RozszerzenieEq;
			pHero->RozszerzenieEq = NULL;


			FabulaItemy = pHero->Itemy;
			FabulaItemy.zloto -= 60;
			FabulaExp = pHero->Itemy.exp;

			pHero->Itemy = { true,true,false,false,Brak,Brak,60,FabulaExp,0,0,0,0,5 };
			
			
			StanKlepsydra = 4;
			
			pPlansza->Plansza[40][39] = pPlansza->Plansza[39][39] = puste_pole;
			
			return;
	}

	if (StanKlepsydra == 4) // cofniecie w czasie (pola)
	{
		if ((pHero->retX() == 40 && pHero->retY() == 39) || (pHero->retX() == 39 && pHero->retY() == 39))
		{
			pHero->Switch_undergorund();
			pHero->SetXY(42, 98);
			pHero->SetIsPole();
			
			StanKlepsydra = 5;
			bPrzejscieNaPolach = true;
			pHero->Plecak.clear();
			pHero->Itemy.siekiera = pHero->Itemy.kosa = false;
			pHero->Itemy.zloto = 0;
		}
	
		pPlansza->Plansza[39][96] = kosa;
		return;
	}

	if (StanKlepsydra == 5) // o co chodzi ? gdzie moje eq ? itd
	{
		if (pHero->RetisUndergorund() == true)
		{
			static int dialog = 0;
			if (pHero->retY() == 97 && dialog == 0)
			{
				cout << endl << endl << pHero->RetName() << ": Gdzie ja jestem?! Co sie stalo ?! " << endl;
				if (_getch() == 224)
					_getch();
				dialog = 1;

			}

			if (pHero->retY() == 96 && dialog == 1)
			{
				cout << endl << endl << pHero->RetName() <<": Hej! Gdzie sa moje przedmioty ?! Gdzie moja siekiera?! Kosa?! " << endl;
				if(_getch() == 224)
					_getch();
				dialog = 2;
				
			}

			if (pHero->retY() == 94 && dialog == 2)
			{
				cout << endl << endl << pHero->RetName() << ": Pieniadze! Gdzie sa moje pieniadze?! Nawet Wy mnie zostawilyscie... " << endl;
				if (_getch() == 224)
					_getch();
				StanKlepsydra = 6;
			}
		}
				
		return;
	}	

	static bool DejaVu = false;

	if (StanKlepsydra == 6) // wyjscie z pola przed rzeka
	{
		if (pHero->RetisUndergorund() == false)
		{
			if (pHero->RetisPole() == false)		
			{
				cout << endl << pHero->RetName() << ": Wreszcie... Mam dosc tego CIAGLEGO przedzierania sie przez pola..." << endl;
				if (_getch() == 224)
					_getch();
				StanKlepsydra = 7;
				DejaVu = true;
			}

		}

		return;
	}
	
	
		if(DejaVu)
			if (pHero->RetisUndergorund() == false)
			{
				if (pHero->retY() == 86)
				{
					cout << endl << pHero->RetName() << ": Powrot tutaj zajal mi troche czasu.. Slonce niedlugo bedzie w zenicie..." << endl;
					Sleep(2000);
					cout << pHero->RetName() << ": To wszystko jest jakies chore..." << endl;
					if (_getch() == 224)
						_getch();
					
					DejaVu = false;
					return;
				}
			}
		

		
	

	// 9 stan daje siekera lub kosa

	if (StanKlepsydra == 9) // ponowne spotkanie straznika
	{
		if (pHero->RetisUndergorund() == false)
		{
			if (pHero->retY() == 66)
			{
				cout << endl << "Straznik: Stoj! Kim jestes i gdzie.. Hej! To Ty ?! Co Ty znowu robisz za rzeka?" << endl;
				Sleep(2000);
				cout << endl << pHero->RetName() << ": Nie uwierzysz.. Ale gdy dzis rano przekroczylem mur miasta nagle znalazlem sie w polach... ponad godzina drogii stad.." << endl;
				Sleep(2000);
				cout << endl << "Straznik: masz racje nie uwierze... Lepiej mow prawde... Bo zaczynam zalowac ze podoarowalem Ci glejt.." << endl;
				Sleep(2000);
				cout << endl << pHero->RetName() << ": Ale to jest prawda! Dzieje sie tu cos dziwnego.. Tak jakby czas sie co... Glejt?! " << endl;
				Sleep(2000);
				cout << endl << "Zaczynasz nerwowo przeszukiwac swoje ubranie" << endl;
				Sleep(2000);
				cout << endl << pHero->RetName() << ": Moj glejt tez zniknal.. Tak jak i reszta przedmiotow... " << endl;
				Sleep(2000);
				cout << endl << "Straznik: Pewnie... Teleporatcje.. Znikajace przedmioty.. i co jeszcze? Pewnie zes sie schal w karczmie a przedmioty i rozkradli.. Tak to jest jak cholota dostaje sie do miasta.." << endl;
				Sleep(2000);
				cout << endl << pHero->RetName() << ": Bacz na slowa, strazniku.. Powiedz mi, czy nie wydarzylo sie tu ostatnio cos dziwnego?" << endl;
				Sleep(2000);
				cout << endl << "Straznik: Jesli pytasz o teleporatcje i magiczne znikanie przedmiotow to nic .. " << endl;
				Sleep(2000);
				cout << endl << "Straznik: ale za to mamy dzielnego bohatera z Asgaru.. jesli chcesz sie dowiedziec jak w jedna noc nagle znalesc sie w polach bez przedmiotow to on jest specjalista.. " << endl;
				Sleep(2000);
				cout << endl << "Straznik: Poza tym wszystko wporzadku.. " << endl;
				Sleep(2000);
				cout << endl << pHero->RetName() << ": Hmm.. No tak rutyna zabija.. No nic.. Bywaj!" << endl;
				if (_getch() == 224)
					_getch();
				int x = pKolesZaRzeka->retX();
				int y = pKolesZaRzeka->retY();

				
				PolaFabularne.push_back(CFabulaPola(PoleGlejt, x, y));
				pKolesZaRzeka->UsunPostacWrazZWskaznikiem();
				pKolesZaRzeka->SetXY(pHero->retX(),65);
				pKolesZaRzeka->RysujPostac();
				pKolesZaRzeka->LoadNpcToBoard();

				pPlansza->Plansza[39][40] = PoleStrzezone;
				pPlansza->Plansza[40][40] = PoleStrzezone;
				pPlansza->Plansza[x][y] = PoleGlejt;

				StanKlepsydra = 10;
			}

		}

		return;
	}

	// 11 stan daje glejt

	if (StanKlepsydra == 11) // ponowny dostep do miasta
	{
		for (int i = 0; i < PolaFabularne.size(); i++)
		{
			if (PolaFabularne[i].PolePlanszy.NumerZdarzenia == 15)
			{
				PolaFabularne[i].PolePlanszy = puste_pole;
				return;
			}
		}

		pPlansza->Plansza[39][40] = puste_pole;
		pPlansza->Plansza[40][40] = puste_pole;
		StanKlepsydra = 12;
		return;
	}

	// 13 stan daje dialog z kupcem

	// 14 stan daje dialog z stajennymi



	if (StanKlepsydra == 16) // cofniecie w wiezy maga
	{
		if (pHero->retX() == 32)
			if (pHero->retY() == 91)
			{

				pHero->UsunPostacZMapy();
				pHero->SetXY(36, 42);
				pHero->RysujPostac();

				StanKlepsydra = 17;
				DrzwiWiezyMaga = true;
				pPlansza->Plansza[32][89].NumerZdarzenia = 1;
				pPlansza->Plansza[32][89].SymbolPola = '#';
				WyszukajDialog(Odpowiedzi, 290)->MoliweOdp[2] = 230;
			}


		return;
	}

	if (StanKlepsydra == 17) // zdziwenie po przeniesieniu
	{
		cout << endl << endl << pHero->RetName() << ": Co do ... Ehh.. znowu to samo .." << endl;
		if (_getch() == 224) _getch();

		StanKlepsydra = 18;
		return;
	}

	if (StanKlepsydra == 18) //
	{
		cout << endl << endl << pHero->RetName() << ": Ktos zatarl caly trop ..." << endl;
		if (_getch() == 224) _getch();

		StanKlepsydra = 19;
		return;
	}
	
	// 19 -> spawn ClockMastera

	if (StanKlepsydra == 20 && WyszukajPrzedmiot(pHero->RozszerzenieEq, 19)->CzyJest)
	{
		WyszukajDialog(Odpowiedzi, 290)->MoliweOdp[2] = 239;
		StanKlepsydra = 21;

		return;
	}
	
	// 21 -> uzyskanie wytrychu

	if (StanKlepsydra == 22 && pHero->RetKlepsydra())
	{
		StanKlepsydra = 23;
		WyszukajDialog(Odpowiedzi, 250)->MoliweOdp[0] = 240;


		return;
	}

	if (StanKlepsydra == 24 && pHero->RetisUndergorund() == false)
	{
		StanKlepsydra = 25;
		ReturnOfTheKing();
		WyszukajDialog(Odpowiedzi, 195 )->MoliweOdp[1] = 246;


		return;
	}

/*
	if (StanKlepsydra == 14) // tropienie
	{
		pWskazowka = new CNPC_w_obiekcie(pHero->RetName(), 100, 47, 36, Straznik, pPlansza);
		pWskazowka->SetSymbolPola('.');
		pWskazowka->RysujPostac();


	
		StanKlepsydra = 15;
		return;
	}

	if (StanKlepsydra == 15) // tropienie
	{
		int x = 0, y = 0;

		switch (StanTropienia)
		{
		case 1: x = 36; y = 42; break;
		case 2: x = 30; y = 41; break;
		case 3: x = 27; y = 32; break;
		case 4: x = 19; y = 32; break;
		case 5: x = 13; y = 42; break;
		case 6: x = 14; y = 67; break;
		case 7: x = 24; y = 78; break;
		case 8: x = 28; y = 85; break;

		}
		pWskazowka->UsunPostacZMapy();
		pWskazowka->SetXY(x, y);
		pWskazowka->RysujPostac();

		if(++StanTropienia > 8)
			StanKlepsydra = 16;
		
		return;
	}
*/

	return;
}

void CFabula::GildiaZlodzieji()
{
	if (bGildiaZlodzieji == false) return;	


	if (pHero->retX() <= 19)
		if (pHero->retY() <= 24)
		{
			time_t wynik = static_cast<time_t>(difftime((time(NULL)), GildiaZlodziejiSTART));
			cout << endl << endl << "Bieg trwal: " << wynik << " sekund" << endl;
			cout << endl << endl << "Wcisniej enter aby kontynuowac... " << endl;
			while (_getch() != 13) {};
			bGildiaZlodzieji = false;

			if (wynik <= 10)
			{
				StanGildiaZlodzieji = 5;
				WyszukajDialog(Odpowiedzi, 213)->MoliweOdp[1] = 148;
			}
		}
}

void CFabula::OtwieranieDrzwiLina()
{
	if (!bOtwieranieDrzwiLina) return;
	if (pHero->retY() == 2 && pHero->retX() == 40 || pHero->retY() == 1 && pHero->retX() == 39 || pHero->retY() == 1 && pHero->retX() == 41)
	{
		cout << endl << endl << pHero->RetName() << ": Nie moge dalej isc.. Lina jest za krotka..." << endl;
		_getch();
		pPlansza->Podziemia[pHero->retX()][pHero->retY()] = puste_pole;
		pHero->SetXY(pHero->RetPrevX(), pHero->RetPrevY());
		return;
	}
	if (pHero->retY() == 2 && (pHero->retX() == 38 || pHero->retX() == 42))
	{
		
		int licznik = 0;
		pPlansza->Podziemia[pHero->RetPrevX()][pHero->RetPrevY()].SymbolPola = '.';
		system("cls");
		pPlansza->RysujPodziemia(pHero->retX(), pHero->retY());

		cout << endl << endl << pHero->RetName() << ": Musze mocna naciagnac line..." << endl;
		cout << endl << endl << "Wciskaj spacje" << endl;

		while (licznik < 200)
		{
			if (_getch() == 32)
				++licznik;
		}
		cout << endl << "Ogien rozszalal sie w korytarzu" << endl;
		Sleep(2000);
		cout << endl << "Tulisz sie do sciany tak bardzo jak tylko mozesz..." << endl;
		Sleep(2000);
		cout << endl << "Po chwili plomien znikl" << endl;
		Sleep(2000);
		cout << endl << pHero->RetName() << ": Uff.. Udalo sie..." << endl;
		Sleep(2000);
		cout << endl << "< odetchnales >" << endl;
		_getch();


		bOtwieranieDrzwiLina = false;
		DrzwiPulapka = false;

		for (int i = 10; i > 2; i--)
			pPlansza->Podziemia[40][i] = puste_pole;
		for (int i = 39; i < 42; i++)
			pPlansza->Podziemia[i][2] = puste_pole;
		for (int i = 39; i < 42; i++)
			pPlansza->Podziemia[i][3] = puste_pole;
		
		return;
	}

	static int kierunek = -4;
	int kierunek2 = 0;
	static bool cofanie = false;
	

	int kX = pHero->RetPrevX() - pHero->retX();
	int kY = pHero->RetPrevY() - pHero->retY();
	
	if (kX == kY)
		return;

	if (kX == 1)
	{
		kierunek2 = 8;
	}
	if (kX == -1)
	{
		kierunek2 = -8;
	}
	if (kY == 1)
	{
		kierunek2 = -4;
	}
	if (kY == -1)
	{
		kierunek2 = 4;
	}


	if (kierunek + kierunek2 == 0 )
	{		
		kierunek = kierunek2;
		
		
		cofanie = cofanie == true ? false : true;		

		if(cofanie == false)
			pPlansza->Podziemia[pHero->RetPrevX()][pHero->RetPrevY()].SymbolPola = '.';

		
		return;
	}

	if (pHero->RetPrevY() == 3 && pHero->RetPrevX() == 40 )
	{
		if(cofanie == true)
		if (kierunek == -8 || kierunek == 8)
		{
			cofanie = false;
			pPlansza->Podziemia[pHero->RetPrevX()][pHero->RetPrevY()].SymbolPola = '.';
			
		}


		if (kierunek2 == 4)
		{
			cofanie = true;
			kierunek = kierunek2;
			pPlansza->Podziemia[pHero->RetPrevX()][pHero->RetPrevY()] = puste_pole;
			return;
		}
			kierunek = kierunek2;
			pPlansza->Podziemia[pHero->RetPrevX()][pHero->RetPrevY()].SymbolPola = '.';
		return;
	}
	
	if (cofanie )
	{		
		kierunek = kierunek2;
		return;
	}

	

	pPlansza->Podziemia[pHero->RetPrevX()][pHero->RetPrevY()].SymbolPola = '.';
	kierunek = kierunek2;
}
void CFabula::PrzejscieNaPolach()
{
	if (bPrzejscieNaPolach == false)
		return;

	if (pHero->RetisUndergorund())
	{
		if (pHero->retY() == 65 && pHero->retX() >= 36)
		{
			system("cls");
			for (int i = 0; i < 5; i++)
			{
				cout << "                                                ." << endl;
				Sleep(1000);
			}
			cout << "                                         Po dlugiej i meczacej podrozy" << endl;
			cout << "                                               ..." << endl;
			_getch();
			pHero->Switch_undergorund();
			pPlansza->Podziemia[pHero->retX()][pHero->retY()] = pola;
			pHero->SetXY(42, 98);
			return;

		}
	}
	else if (pHero->retY() == 98)
	{
		if (pHero->retX() == 41 || pHero->retX() == 42 || pHero->retX() == 43)
		{
			system("cls");
			for (int i = 0; i < 5; i++)
			{
				cout << "                                                ." << endl;
				Sleep(1000);
			}
			cout << "                                         Po dlugiej i meczacej podrozy" << endl;
			cout << "                                               ..." << endl;
			_getch();
			pHero->Switch_undergorund();
			pPlansza->Plansza[pHero->retX()][pHero->retY()] = pola;
			pHero->SetXY(44, 67);
			return;
		}
	}

	
}

void CFabula::OdzyskajEq()
{

	pHero->RozszerzenieEq = FabulaRozszerzenieEq;
	FabulaRozszerzenieEq = NULL;

	pHero->Itemy = FabulaItemy;
	//FabulaItemy = ? ? ;

	pHero->Plecak = FabulaPlecak;

	pHero->NoszonePrzedmioty.Sword = NULL;
	//pHero->Itemy.exp += FabulaExp;


}

void CFabula::AkcjaWynikajacaZDiagolu(int DalszaAkcja, CCharacter* Enemy)
{
	//static int stan = 0;
	StosDialogow* ModyfikowanyDialog = NULL;
	DodatkowyEkwipunek* ObecnyPrzedmiot = NULL;
	

	switch (DalszaAkcja)
	{
		case 1: //walka

			if (Walka(Enemy) == false)
				koniec = true;
			_getch();
			break;

		case 2: // quest SzacunekFarmera
		{
			if (StanSzacunekFarmera == 0)
			{
				SzacunekFarmera();
				ModyfikowanyDialog = ZnajdzDialog(Odpowiedzi, 114);
				ModyfikowanyDialog->MoliweOdp[0] = 21;
				ModyfikowanyDialog = ZnajdzDialog(Odpowiedzi, 117);
				ModyfikowanyDialog->MoliweOdp[2] = 21;
				StanSzacunekFarmera = 1;
			}
			if (StanSzacunekFarmera == 1)
			{				
				SzacunekFarmera();
				if (StanSzacunekFarmera == 1)
				{
					cout << endl;
					cout << pFarmer->RetName() << ": Swietnie, oby tak dalej" << endl;
					_getch();
				}
			}
			if (StanSzacunekFarmera == 2)
			{
				ModyfikowanyDialog = ZnajdzDialog(Odpowiedzi, 114);
				ModyfikowanyDialog->MoliweOdp[0] = 22;
				ModyfikowanyDialog = ZnajdzDialog(Odpowiedzi, 117);
				ModyfikowanyDialog->MoliweOdp[2] = 22;
				StanSzacunekFarmera = 3;
			}
			break;
		}

		case 3: // quest SzacunekStraznika
		{
			bool WyjscieZLasu = false;
			

			    // rozmowa z elwira
				if (StanSzacunekStraznika == 0) 
				{
					pTeodorPoOdnalezieniu = new CNPC_w_obiekcie("Teodor", 130, 23, 3, Straznik, pPlansza);
					StanSzacunekStraznika = 1;
					ModyfikowanyDialog = ZnajdzDialog(Oddzywki, 28);
					ModyfikowanyDialog->MoliweOdp[2] = 0;
					break;
				}

				// krzyki teodora w lesie - pierwsze spotkanie
				if (StanSzacunekStraznika == 1)
				{
					while (WyjscieZLasu == false)
					{
					cout << endl;
					cout << "Znajdujesz sie w srodku gestego lasu. Wokol Ciebie znajduje sie duza ilosc drzew lisciastych, krzewow oraz innych rolslin lesniych" << endl;
					cout << "Ot zwykly las" << endl;
					cout << "W tym miejscu zwraca Twoja uwage jedynie niewielki glaz, stare bezlistne drzewo oraz dziwnie wygladajacy krzak..." << endl;
					cout << "Co robisz? " << endl;
					cout << "Ide do: " << endl;
					cout << endl;
					cout << "1. glazu" << endl;
					cout << "2. drzewa" << endl;
					cout << "3. krzaka" << endl;
					int decyzja = _getch();
					if (decyzja == 224)
						decyzja = _getch();
					cout << endl;

					switch (decyzja)
					{
						case '1': // glaz
						{
							cout << "Dostrzegasz niewielka bialowlosa dziewczynke" << endl;
							cout << endl;
							cout << "Illya: Witaj. Nazwam sie Illasviel von Einzbern" << endl;
							_getch();
							break;
						}
						case '2': // drzewa
						{
							cout << endl;
							cout << "Zblizasz sie niepewnie do dosc wysokiego drzewa.." << endl;
							cout << "Jest bardzo stare. Dziwisz sie ze wogole jeszce stoi.." << endl;
							cout << "Wyglada lekko przerazajaco" << endl;
							cout << "Bezlistne galezie przypominaja dlonie" << endl;
							cout << "Co robisz?" << endl;
							cout << "1. Dokladnie obserwuje" << endl;
							cout << "2. Zawracam" << endl;
							int decyzja = _getch();
							if (decyzja == 224)
								decyzja = _getch();
							cout << endl;

							switch (decyzja)
							{
							case '1':
							{
								cout << "Widzisz niewiekla dziure w pniu" << endl;
								cout << "Przeszukujesz ja..." << endl;
								cout << "Jednakze poza robactwem i odchodami jakis zwierzat nie znajdujesz nic ciekawego..." << endl;
								_getch();
								break;
							}
							default: break;
							}


							break;
						}
						case '3': // krzak
						{
						cout << "Podchodzac blizej zauwazasz ze krzak jest zgnieciony, a wiele jego galezi zostalo polamanych" << endl;
						cout << "Oho... - myslisz - pewnie jakas bestyja zrobila sobie tu leze.." << endl;
						cout << endl;
						
						cout << "Co robisz?" << endl;
						cout << "1. Ide dalej" << endl;
						cout << "2. Zawracam" << endl;
						int decyzja = _getch();
						if (decyzja == 224)
							decyzja = _getch();
						cout << endl;

						switch (decyzja)
						{
							case '1': // ide dalej
							{
								cout << endl;
								cout << "Podchodzisz blizej" << endl;
								cout << "Okrzyki staja sie coraz wyrazniejsze" << endl;
								cout << "Dostrzegasz w ziemii niewielki dol prowdzacy do glebin" << endl;
								cout << "Widzisz takze fragmenty materialu na galeziach krzewu" << endl;
								cout << "Dostrzegasz w ziemii niewielki dol prowdzacy do glebin" << endl;
								cout << "Chyba ktos tam wpadl... - myslisz - za ta teoria przemawia fakt ze slychac krzyki z wewnatrz..." << endl;
								cout << endl;
								pTeodorPoOdnalezieniu->SetNumDialogu(132);
								_getch();
								WyjscieZLasu = true;
								StanSzacunekStraznika = 2;
								return;
								break;
							}
							default: break;
						}



						break;
					}
					default: cout << pHero->RetName() << ": Cholera! Uciekam z tego dziwnego lasu" << endl; _getch();
						WyjscieZLasu = true; break;
					}

				}

			} 

				// oferta pomocy
			    if (StanSzacunekStraznika == 2 )
			{

				ModyfikowanyDialog = ZnajdzDialog(Odpowiedzi, 132);
				ModyfikowanyDialog->MoliweOdp[1] = 50;				
				StanSzacunekStraznika = 3;	
				return;
			}

				// danie chleba teodorowi
				if (StanSzacunekStraznika == 3)
				{
					if (WyszukajPrzedmiot(pHero->RozszerzenieEq, 1)->CzyJest) // chleb
					{
						cout << "Teodor: Dziekuje! Dziekuje! Serdecznie dziekuje! Ratujesz mi zycie!" << endl;
						cout << pHero->RetName() << " : Drobiazg, pojde rozejrzec sie za jakas lina" << endl;
						_getch();
						WyszukajPrzedmiot(pHero->RozszerzenieEq, 1)->UsunPrzedmiot();

						ModyfikowanyDialog = ZnajdzDialog(Odpowiedzi, 132);
						ModyfikowanyDialog->MoliweOdp[1] = 51;


						StanSzacunekStraznika = 4;
						return;

						break;
					}
					cout << "Teodor: Zartujesz sobie ze mnie?! Nie masz nawet okruszka chleba!" << endl;
					_getch();
				}

				// wciaganie za pomoaca liny
				if(StanSzacunekStraznika == 4)
				{
					if (WyszukajPrzedmiot(pHero->RozszerzenieEq, 5)->CzyJest) // lina
					{
						bool KoniecAkcjiRatunkowej = false;

						while (!KoniecAkcjiRatunkowej)
						{
							cout << endl;
							cout << "Co robisz?" << endl;					
							cout << endl;
							cout << "1. Chwytasz line i rzucasz" << endl;
							cout << "2. Obwiazujesz wokol drzewa i rzucasz" << endl;
							cout << "3. Odchodzisz" << endl;
							int decyzja = _getch();
							if (decyzja == 224)
								decyzja = _getch();
							cout << endl;

							switch (decyzja)
							{
							case '1': // Chwytasz line i rzucasz
							{
								cout << endl;
								cout << "Gwaltowne szarpniecie..." << endl;
								cout << "." << endl;
								Sleep(1000);
								cout << "." << endl;
								Sleep(1000);
								cout << "." << endl;
								Sleep(1000);
								cout << "." << endl;
								Sleep(1000);
								cout << "Nie byles na to przygotowany..." << endl;
								_getch();
								KoniecAkcjiRatunkowej = true;
							
								pHero->Switch_undergorund();
								pTeodor = new CNPC("Teodor", 'T', 321, 3, 18, Straznik, pPlansza);
								pTeodor->LoadNpcToBoard();
								pTeodor->RysujPostac(true);
								system("cls");
								pHero->SetXY(3, 19);
								pPlansza->RysujPodziemia(pHero->retX(), pHero->retY());
								cout << "Teodor: NIEEEEE!!! JAK MOGLES!!!" << endl;
								Sleep(3000);
								cout << "Teodor: Teraz przez Ciebie zginiemy tu obaj!" << endl;
								Sleep(3000);
								cout << "Teodor: O ja nieszczesny! Juz nigdy nie zobacze swojej Elwiry!" << endl;
								Sleep(3000);
								cout << pHero->RetName() << ": Spokojnie... Napewno jest tu jakies wyjscie.." << endl;
								Sleep(3000);
								cout << "Teodor: Wyjscie? WYJSCIE?! MYSLISZ ZE JESLI BYLOBY TU WYJSCIE TO DALEJ BYM TU TKWIL?!" << endl;
								Sleep(3000);
								cout << pHero->RetName() << ": Niemniej jednak sie rozejrze.." << endl;
								Sleep(3000);
								cout << "Teodor: O ja nieszczesny!" << endl;
								Sleep(3000);
								_getch();

								bNostalgia = true;
								bTeodorPodziemia = true;




								break;
							}
							case '2': // obwiazanie woklo drzewa
							{
								cout << endl;
								cout << "Obwiazujesz line dokladnie wokol pnia pobliskiego drzewa..." << endl;
								cout << "." << endl;
								Sleep(1000);
								cout << "." << endl;
								Sleep(1000);
								cout << "." << endl;
								Sleep(1000);
								cout << "." << endl;
								Sleep(1000);
								cout << "Lina po chwili sie napreza..." << endl;
								cout << "." << endl;
								Sleep(1000);
								cout << "." << endl;
								Sleep(1000);
								cout << "." << endl;
								Sleep(1000);
								cout << "." << endl;
								cout << "Jakas postac wylania sie spod ziemii..." << endl;
								KoniecAkcjiRatunkowej = true;
								_getch();

								delete pTeodorPoOdnalezieniu;
								pTeodorPoOdnalezieniu = NULL;

								pTeodor = new CNPC("Teodor", 'T' , 143, 23, 3, Straznik, pPlansza);
								pTeodor->LoadNpcToBoard();
								pTeodor->RysujPostac();
								StanSzacunekStraznika = 5;
								pHero->SetXY(23, 4);
								pHero->RysujPostac();

								return;
								}

							default: break;

							}
							
						
						
						}

						break;
					}
												

						
					
					cout << "Teodor: No i? Gdzie ta lina?" << endl;
					cout << pHero->RetName() <<": Czekaj chwile.. Zaraz wracam.." << endl;
					cout << "Teodor: ..." << endl;
					_getch();

				}

				// odprowadzanie Todora
				if (StanSzacunekStraznika == 5)
				{
					StanSzacunekStraznika = 6;
					return;
				}

				if (StanSzacunekStraznika == 7)
				{

					cout << endl << endl << "Teodor: Prosze o to zaplata za Twoj wysilek" << endl;					
					Sleep(2000);
					cout << endl << pHero->RetName() << ": Nie pomagalem Ci dla zysku... Nie chce pieniedzy.. Grunt ze wszystko wporzadku" << endl;
					Sleep(2000);
					cout << endl << "Teodor: Zechciej przyjac chociaz ten noz na wilki.. Mi i tak sie do niczego nie przyda a wiem ze Ty zrobisz z niego wlasciwy uzytek" << endl;
					Sleep(2000);
					cout << pHero->RetName() << ": Niech bedzie. Dziekuje i uwazaj na siebie. Bywaj!" << endl;
					Sleep(2000);
					cout << endl << "Teodor: Do zobaczenia! Zawsze bedziesz tu mile widziany. Wpadnij wkrotce!" << endl;
					StanSzacunekStraznika = 8;
					StanWdziecznoscTeodora = 1;
					WyszukajDialog(Odpowiedzi, 155)->MoliweOdp[1] = 92;
					WyszukajDialog(Oddzywki, 92)->MoliweOdp[0] = 0;
					WyszukajDialog(Oddzywki, 92)->MoliweOdp[2] = 0;
					pHero->Plecak.push_back(&NozNaWilki);
					return;
				}


			break;
		}

		case 4: // robienie maki
		{
			if (pHero->Itemy.zboze != 5)
			{
				cout << endl;
				cout << "Mlynarz: Przynies caly plecak, nie mam czasu na zabawe..." << endl;
				_getch();
				return;
			}

			ObecnyPrzedmiot = WyszukajPrzedmiot(pHero->RozszerzenieEq, 2);
			ObecnyPrzedmiot->DodajPrzedmiot();
			pHero->Itemy.zboze = 0;
			cout << "Mlynarz: Prosze. Oto garnek pelen maki" << endl;
			_getch();
			return;
		}

		case 5: // robienie chleba
		{
			ObecnyPrzedmiot = WyszukajPrzedmiot(pHero->RozszerzenieEq, 3);
			if (ObecnyPrzedmiot->CzyJest == false)
			{
				cout << endl;
				cout << pHero->RetName() << ": Nie moge upiec chleba bez ciasta..." << endl;
				_getch();
				return;
			}

			ObecnyPrzedmiot->UsunPrzedmiot();
			ObecnyPrzedmiot = WyszukajPrzedmiot(pHero->RozszerzenieEq, 1);
			ObecnyPrzedmiot->DodajPrzedmiot();

			cout << pHero->RetName() << ": Wspaniale! Udalo mi sie upiec chleb" << endl;
			_getch();
			return;
		}

		case 6: // zemsta Teodora
		{
			if (StanZemstaTeodora == 0)
			{
				if (StanSzacunekStraznika >= 5)
				{
					cout << endl << endl << "Teodor: Tak..Tak.. Naturalnie" << endl;
					cout << endl << "Zyskujesz 50 sztuk zlota" << endl;
					pHero->Itemy.zloto += 50;
					StanSzacunekStraznika = 8;
					_getch();
					return;
				}
				pHero->Itemy.zloto += 25;
				cout << "Zyskujesz 25 sztuk zlota" << endl;
				_getch();
				ModyfikowanyDialog = ZnajdzDialog(Odpowiedzi, 132);
				ModyfikowanyDialog->MoliweOdp[1] = 50;
				StanSzacunekStraznika = 3;
				StanZemstaTeodora = 1;
				return;
			}

			if (StanZemstaTeodora == 1)
			{
				cout << endl << endl << "Teodor: A jakze! Bierz te pieniadze i wynos sie stad, lajdaku!" << endl;
				Sleep(2000);
				cout  << endl << "Mezczyzna rzucil Ci pod nogi mieszek z pieniedzmi" << endl;
				Sleep(2000);
				cout << endl << pHero->RetName() << ": Wiecej szacunku! Tylko dzieki mnie zyjesz..." << endl;
				Sleep(2000);
				cout << endl << "Teodor: WYNOS SIE STAD I NIE WRACAJ!" << endl;
				pHero->Itemy.zloto += 100;
				cout << endl << "Zyskujesz 100 sztuk zlota" << endl;
				_getch();
				pTeodor->SetNumerZdarzenia(176);
				pTeodor->RysujPostac();
				if (WyszukajDialog(Odpowiedzi, 166)->MoliweOdp[1] == 84)
					WyszukajDialog(Odpowiedzi, 176)->MoliweOdp[0] = 0;
				
				StanSzacunekStraznika = 8;
				StanZemstaTeodora = 2;
				return;
			}



			break;
		}
		
		case 7: // opowiesc Teodora
		{
			if (StanOpowiescTeodora == 0 && StanSzacunekStraznika >= 7)
			{
				
					pTeodor->SetNumerZdarzenia(162); 
					StanOpowiescTeodora = 1;

			}
			if (StanOpowiescTeodora == 0)
			{
				StanOpowiescTeodora = 1;
				AkcjaWynikajacaZDiagolu(WyswietlDialog(Odpowiedzi, Oddzywki, 153, pHero->RetName(), pTeodor->RetName()), pTeodor);
				
				return;
			}
			if (StanOpowiescTeodora == 1)
			{
				
				cout << endl << endl << "Teodor: Wiele wiosen temu, beztrosko zylo trzech braci..." << endl;
				Sleep(2500);
				cout << endl << "Teodor: Kazdy z nich chcialbyc awanturnikiem, poszukiwaczem przygod..." << endl;
				Sleep(2500);
				cout << endl << "Teodor: Wspolnie wiec ich szukali..." << endl;
				Sleep(2500);
				cout << endl << "Teodor: Cwiczyli walke mieczem, udawali sie na niebezpiczne i dlugie wedrowki, polowali na \"potwory\"..." << endl;
				Sleep(3500);
				cout << endl << "< mezczyzna zasmial sie do siebie >" << endl;
				Sleep(2000);
				cout << endl << "Teodor: Ale pewnego razu..." << endl;
				Sleep(1500);
				cout << endl << pHero->RetName() << ": A jakzeby inaczej... - myslisz ..." << endl;
				Sleep(2500);
				cout << endl << "Teodor: przesadzili... udawali dzikie zwierzeta w sezonie polowan..." << endl;
				Sleep(2500);
				cout << endl << "Teodor: Dobrze ze mysliwy na ktorego trafili nie mial calnego oka..." << endl;
				Sleep(2500);
				cout << endl << "Teodor: Jeden z chopcow dostal strzala w kolano..." << endl;
				Sleep(2500);
				cout << endl << "Wyraz smutku maluje sie na twarzy mezczyzny, ktory juz od dawna patrzy tam gdzie Ty wzrokiem siegnac nie mozesz..." << endl;
				Sleep(3500);
				cout << endl << "Teodor: I tak oto zakonczyla sie jego kariera poszukiuwacza przygod..." << endl;
				Sleep(2500);
				cout << endl << "Teodor: Bracia wiec solidarnie zaprzestali awanturnictwa..." << endl;
				Sleep(2500);
				cout << endl << "Teodor: Pragnienie przygody bylo zbyt silne, ale nie mogli pozostawic brata samego ..." << endl;
				Sleep(2500);
				cout << endl << "Teodor: Tak wiec wymyslili gre..." << endl;
				Sleep(2500);
				cout << endl << pHero->RetName() <<": Gre mowisz? " << endl;
				Sleep(2500);
				cout << endl << "Teodor: Tak gre..." << endl;
				Sleep(1000);
				cout << endl << "Teodor: Teraz czas na wlasciwa opowiesc..." << endl;
				Sleep(2500);
				cout << endl << pHero->RetName() << ": Czekam z niecierpliwoscia... " << endl;
				Sleep(2500);
				cout << endl << "Teodor: Gra ta pozwalala przezywac przygody nie ruszajac sie z domu ..." << endl;
				Sleep(2500);
				cout << endl << pHero->RetName() << ": Jak to wogole mozliwe ?!" << endl;
				Sleep(2500);
				cout << endl << "Teodor: Cierpliwosci... juz wyjasniam..." << endl;
				Sleep(2500);
				cout << endl << "Teodor: Bylo to mozliwe poniewaz przygody rozgrywaly sie w wyobrazni..." << endl;
				Sleep(2500);
				cout << endl << pHero->RetName() << ": Wyobrazni ?!" << endl;
				Sleep(2500);
				cout << endl << "Teodor: Tak, w wyobrazni. Nie przerywaj mi..." << endl;
				Sleep(2500);
				cout << endl << pHero->RetName() << ": Wybacz" << endl;
				Sleep(2500);
				cout << endl << "Teodor: Ekhem... Tak wiec, kazdego dnia od samego rana do wieczora byli najzwyklejszymi dzieciakami, prawcowaly i pomagaly rodzicom jak umieli a psocili.. ot jak zwykle dzieciaki" << endl;
				Sleep(4000);
				cout << endl << "Teodor: Wieczorem zas kazdy stawal sie meznym paladynem, poteznym magiem czy niezwyciezonym barbarzynskim wojownikiem..." << endl;
				Sleep(2500);
				cout << endl << "Teodor: Pomagali slabym i bezbronnym, tepili potwory i inne plugastwa, odkrywali niezbadane tereny i wladali legendarnymi przedmiotami..." << endl;
				Sleep(3500);
				cout << endl << "Teodor: Z dnia na dzien stawali sie coraz silniejsi, nawet smoki odczuwaly przed nimi lek..." << endl;
				Sleep(2500);
				cout << endl << pHero->RetName() << ": Smoki? Odrobine przesadzasz..." << endl;
				Sleep(2500);
				cout << endl << "Teodor: Tak bylo! A Ty wreszcie przestan mi przerywac..." << endl;
				Sleep(2500);
				cout << endl << pHero->RetName() << ": Przepraszam... Kontynuuj" << endl;
				Sleep(2500);
				cout << endl << "Teodor: Dzielna druzyna postanowila wkoncu rzucic wyzwanie samemu wladcy ciemnosci..." << endl;
				Sleep(2500);
				cout << endl << pHero->RetName() << ": Wladcy ciemnosci ? W to juz nie uwierze..." << endl;
				Sleep(2500);
				cout << endl << "Teodor: Miales nieprzerywac! " << endl;
				Sleep(2500);
				cout << endl << pHero->RetName() << ": Ale to wszystko jest takie niewiarygodne!" << endl;
				Sleep(2500);
				cout << endl << "Teodor: I oto chodzi! Tak mialobyc ! To wszystko bylo gra aktorska, zabawa... GRA WYOBRAZNI..." << endl;
				Sleep(2500);
				cout << endl << pHero->RetName() << ": Zaiste, niesmowite! I co z tym wladca ?" << endl;
				Sleep(2500);
				cout << endl << "Teodor: Jedynym sposobem jego pokonania, bylo zniszenie pierscienia ktory mi przekazales..." << endl;
				Sleep(2500);
				cout << endl << "Teodor: Nalezalo go wrzucic w czelusci ogniste z ktorych powstal..." << endl;
				Sleep(2500);
				cout << endl << pHero->RetName() << ": I jak skonczyla sie ta przygoda ?" << endl;

				StanOpowiescTeodora = 2;
				AkcjaWynikajacaZDiagolu(WyswietlDialog(Odpowiedzi, Oddzywki, 161, pHero->RetName(), pTeodor->RetName()), pTeodor);
				
				return;
			}
			if(StanOpowiescTeodora == 2)
			{
				// wpis aby odpwiediec sie o co chodzi
				StanOpowiescTeodora = 3;
				return;
			}





			break;
		}

		case 8: // oddanie piersciania
		{

			
			//if (WyszukajDialog(Odpowiedzi, 166)->MoliweOdp[1] == 84 && StanOddaniePierscienia == 1)
			if (StanOddaniePierscienia == 1)
			{
				WyszukajDialog(Odpowiedzi, 166)->MoliweOdp[1] = 85;
				bSzacunekStraznika = true;
				StanOddaniePierscienia = 2;
				return;
			}

		
			if (pTeodor != NULL)
			{
				StanOddaniePierscienia = 1;

				if (StanZemstaTeodora < 1)
				{
					if (StanSzacunekStraznika < 7)
						AkcjaWynikajacaZDiagolu(WyswietlDialog(Odpowiedzi, Oddzywki, 152, pHero->RetName(), pTeodor->RetName()), pTeodor);
					if (StanSzacunekStraznika > 6)
						AkcjaWynikajacaZDiagolu(WyswietlDialog(Odpowiedzi, Oddzywki, 159, pHero->RetName(), pTeodor->RetName()), pTeodor);
				}
				WyszukajDialog(Odpowiedzi, 166)->MoliweOdp[1] = 84;
				WyszukajDialog(Odpowiedzi, 176)->MoliweOdp[0] = 0;

				WyszukajDialog(Oddzywki, 62)->MoliweOdp[2] = 0;
				WyszukajDialog(Oddzywki, 62)->MoliweOdp[0] = 152;

			}

			if (WyszukajDialog(Odpowiedzi, 166)->MoliweOdp[1] == 78 && StanOddaniePierscienia == 0)
			{
				WyszukajDialog(Odpowiedzi, 166)->MoliweOdp[1] = 83;
				return;
			}



			break;
		}

		case 9: // uzyskanie glejtu
		{
			cout << endl << endl << pKolesZaRzeka->RetName() << ": Popytaj okolicznych.. Zaprzyjaznij sie.. a Twoja sytuacja napewno sie poprawi" << endl;
			Sleep(2000);
			if (bSzacunekStraznika)
				cout << endl << pKolesZaRzeka->RetName() << ": Ja nie bede stawal Ci na drodze" << endl;
			Sleep(2000);
			if(bSzacunekFarmera)
				cout << endl << pKolesZaRzeka->RetName() << ": Farmerzy maja o Tobie dobre zdanie" << endl;
			Sleep(2000);
			if (bSzacunekWiezniarza)
				cout << endl << pKolesZaRzeka->RetName() << ": Zarzadca wiezenia jest Ci bardzo wdzieczny" << endl;
			Sleep(2000);
			if (bSzacunekFarmera && bSzacunekStraznika && bSzacunekWiezniarza)
			{
				cout << endl << pKolesZaRzeka->RetName() << ": Mysle ze udalo Ci sie zyskac przychylnosc okolicznych. Zasluzyles na glejt" << endl;
				DostepDoMiasta();
				return;
			}
				cout << endl << pKolesZaRzeka->RetName() << ": Musisz jeszcze popracowac.. Wiele osob wogole o Tobie nie slyszalo..." << endl;

				_getch();
				break;

		}

		case 10: // Szacunek Wiezniarza
		{
			if (StanSzacunekWiezniarza == 0)
			{
				StanSzacunekWiezniarza = 1;
					WyszukajDialog(Odpowiedzi, 178)->MoliweOdp[1] = 116;
					return;
			}
			if (StanSzacunekWiezniarza == 1)
			{
				ObecnyPrzedmiot = WyszukajPrzedmiot(pHero->RozszerzenieEq, 6);
				if (ObecnyPrzedmiot->Ilosc >= 5)
				{
					ObecnyPrzedmiot->Ilosc -= 4;
					ObecnyPrzedmiot->UsunPrzedmiot();
					pHero->Itemy.zloto += 50;
					WyszukajDialog(Odpowiedzi, 178)->MoliweOdp[1] = 104;
					cout << "Zarzadca wiezienia: Swietnie! Jestem Ci bardzo wdzieczny. Oto zaplata." << endl;
					cout << endl << "Otrzymales 50 sztuk zlota" << endl;
					bSzacunekWiezniarza = true;
				}
				else
				{
					cout << "Zarzadca wiezienia: Wiem ze jestem stary i oczy juz nie te.. ale skora jest na tyle duza ze jestem wstanie policzyc ile mi dajesz... Sprobuj z czyms mniejszym.." << endl;
					cout << endl << "Zarzadca wiezienia: <do siebie> Jadro ciemnosci.. Jadro ciemnosci jest wszedzie... biedny czlowiek..." << endl;
				}

				_getch();
				return;
			}
			break;
		}

		case 11: // Udowodnic mozliwoc pozbycia sie cienia
		{
			break;
		}

		case 12: // nocleg
		{
			pPlansza->Plansza[10][6] = Lozko;
			cout << endl << endl <<"Farmer: Mozesz skorzystac z domu wysunietego najbardziej na zachod farmy" << endl;
			Sleep(2000);
			cout << pHero->RetName() << ": Dziekuje" << endl;
			Sleep(1000);
			cout <<  "Farmer: Jednak nie mozemy Cie przyjac za darmo ale mam pomysl " << endl;
			Sleep(2000);
			cout << "Farmer: Pamietam ze pomagales mi z drewnem. Jestes wprawnym drwalem a my uzywamy tego domku jako skladzik na drewno.. " << endl;
			Sleep(2000);
			cout << "Farmer: Tak wiec jesli bedziesz chcial z nego skorzystac to poprostu dorzuc do sterty 5 klod drewna i bedzemy kwita " << endl;
			Sleep(2000);
			cout << "Farmer: Jako pracownik farmy bedzisz mial prawo do noclegu " << endl;
			Sleep(2000);
			cout << pHero->RetName() << ": Dziekuje bardzo raz jeszce" << endl;
			Sleep(2000);
			cout << "Farmer: Nie ma za co.. Wkoncu my tez na tym skorzystamy" << endl;
			_getch();
			break;
		}

		case 13: //Szajka zlodzieji
		{
			if (StanGildiaZlodzieji == 0) // rozmowa z kapitanem
			{

				cout << endl << endl << "Kapitan Strazy: Nie irytuj sie. Cos za cos.. Po za tym zapewniam Cie ze to niezbedne.. Tylko najbardziej zaufane osoby moga dojsc do krola Ziutmelsona" << endl;
				Sleep(3000);
				cout << endl << "Kapitan Strazy: A ja juz po tym jednym zadaniu uznam Cie za taka. Mamy prawo ustawione przez Jego Wysokosc, a tam doklanie opisane sa procedury dojscia do Jego majestatu" << endl;
				Sleep(3000);
				cout << endl << "Kapitan Strazy: Zrozum ze ja i tak robie duzy wyjatek" << endl;
				Sleep(2000);
				cout << endl << pHero->RetName() << ": Wporzadku.. Rozumiem.. Ehh.. Nasz krol nigdy nie blyszczal w dziedzinie administracji i zarzadzania..." << endl;
				Sleep(2000);
				cout << endl << endl << "Kapitan Strazy: Uwazaj co mowisz! Za takie slowa grozi szafot.. Uznam ze nic nie slyszalem.. Idz juz.." << endl;
				if (_getch() == 224) _getch();

				pSzefStrazy->SetNumDialogu(210);
				StanGildiaZlodzieji = 1;
				WyszukajDialog(Odpowiedzi, 224)->MoliweOdp[2] = 156;
				
				return;
			}
			
			if (StanGildiaZlodzieji == 1) // rozmowa z doradca
			{
				WyszukajDialog(Odpowiedzi, 224)->MoliweOdp[2] = 30;
				StanGildiaZlodzieji = 2;
				WyszukajDialog(Odpowiedzi, 233)->MoliweOdp[1] = 174; // szpieg
				WyszukajDialog(Odpowiedzi, 234)->MoliweOdp[1] = 173;
				WyszukajDialog(Odpowiedzi, 249)->MoliweOdp[1] = 172; // karczmarka
				WyszukajDialog(Odpowiedzi, pKupiec->RetNumDialogu())->MoliweOdp[1] = 171; // kupiec
				
				return;
			}

			if (StanGildiaZlodzieji == 2) // werendi
			{
				cout << endl << endl << "Mezczyzna: Czy to jasne ?" << endl;
				Sleep(1000);
				cout << endl << pHero->RetName() << ": Jak slonce" << endl;
				Sleep(1000);
				cout << endl << "Mezczyzna: No to swietnie.. Powodzenia a teraz zmykaj.. zanim Cie zabardzo polubie.." << endl;
				Sleep(2000);
				cout << endl << pHero->RetName() << ": Bywaj!" << endl;
				if(_getch() == 224) _getch();

				WyszukajDialog(Odpowiedzi, 211)->MoliweOdp[0] = 144;
				WyszukajDialog(Odpowiedzi, 212)->MoliweOdp[0] = 144;
				WyszukajDialog(Odpowiedzi, 213)->MoliweOdp[0] = 135;
				WyszukajDialog(Odpowiedzi, 233)->MoliweOdp[1] = 30; // szpieg
				StanGildiaZlodzieji = 3;
				return;
			}

			if (StanGildiaZlodzieji == 3) // ustawienie dialogow przed biegiem
			{
				WyszukajDialog(Odpowiedzi, 213)->MoliweOdp[0] = 146;
				WyszukajDialog(Odpowiedzi, 213)->MoliweOdp[1] = 147;
				StanGildiaZlodzieji = 4;
				// w tym miejscu CELOWY brak retturn !!!!
			}

			if (StanGildiaZlodzieji == 4) // bieg
			{
				bGildiaZlodzieji = true;
				cout << endl << "Czas start" << endl;
				_getch();
				GildiaZlodziejiSTART = time(NULL);
				//StanGildiaZlodzieji = 4;
				return;
			}

			if (StanGildiaZlodzieji == 5) // udalo sie przebiedz w mniej niz 10 sec
			{
				pZlodziejSzef->SetNumerZdarzenia(223);
				pZlodziejSzef->RysujPostac();
				StanGildiaZlodzieji = 6;
				AkcjaWynikajacaZDiagolu(WyswietlDialog(Odpowiedzi, Oddzywki, 223, pHero->RetName(), "Przywodca gildii"), pZlodziejSzef);
				//StanGildiaZlodzieji = 4;
				return;
			}

			if (StanGildiaZlodzieji == 6) // wciagniecie w pulapke
			{
				cout << endl << endl << "Zlodzieje wymienili spojrzenia" << endl;
				Sleep(2000);
				cout << endl << "Kobieta skinela.." << endl;
				Sleep(2000);
				cout << endl << "a zaraz a nia mezczyzna..." << endl;
				Sleep(2000);
				cout << endl << pZlodziejSzef->RetName() << ": Nie wiesz bo i nikt wiedziec nie moze..." << endl;
				Sleep(2000);
				cout << endl << pZlodziejSzef->RetName() << ": Niech bedzie... pomozemy Ci liczymy jednak na polowe zysku.." << endl;
				Sleep(2000);
				cout << endl << pHero->RetName() << ": Co najzwyzej 1/3.. wiecej zaoferowac nie moge.." << endl;
				Sleep(2000);
				cout << endl << pZlodziejSzef->RetName() << ": Wstepnie.. Jeszcz bedziemy rozmawiac jak juz skarb bedzie nasz.." << endl;
				Sleep(2000);
				cout << endl << pHero->RetName() << ": Stoi.. Widzimy sie o 3 za zamkiem.. " << endl;
				Sleep(2000);
				cout << endl << pZlodziejSzef->RetName() << ": dlaczego akurat wtedy..." << endl;
				Sleep(2000);
				cout << endl << pHero->RetName() << ": Czesc planu.. O tej porze Ci co jeszcze nie spali ida spac a Ci co maja wstac sa jeszce zbyt rozespani by dzialac.. " << endl;
				Sleep(2000);
				cout << endl << pZlodziejSzef->RetName() << ": Niech bedzie... Do zobaczenia na miejscu..." << endl;
				if (_getch() == 224) _getch();

				pZlodziejSzef->SetNumerZdarzenia(282);
				pZlodziej1->SetNumerZdarzenia(282);
				pZlodziej2->SetNumerZdarzenia(282);


				pZlodziejSzef->UsunPostacWrazZWskaznikiem();
				pZlodziejSzef->SetXY(40, 2);
				pZlodziejSzef->RysujPostac();
				pZlodziejSzef->LoadNpcToBoard();

				pZlodziej1->UsunPostacWrazZWskaznikiem();
				pZlodziej1->SetXY(38, 2);
				pZlodziej1->RysujPostac();
				pZlodziej1->LoadNpcToBoard();

				pZlodziej2->UsunPostacWrazZWskaznikiem();
				pZlodziej2->SetXY(42, 2);
				pZlodziej2->RysujPostac();
				pZlodziej2->LoadNpcToBoard();
				
				WyszukajDialog(Odpowiedzi, 210)->MoliweOdp[0] = 215;
			

				StanGildiaZlodzieji = 7;
				return;
			}

			if (StanGildiaZlodzieji == 7) // finalna rozmowa ze kapitanem strazy
			{
				pZlodziejSzef->UsunPostacWrazZWskaznikiem();
				pZlodziejSzef->SetXY(4, 83);
				pZlodziejSzef->RysujPostac();
				pZlodziejSzef->LoadNpcToBoard();

				pZlodziej1->UsunPostacWrazZWskaznikiem();
				pZlodziej1->SetXY(5, 86);
				pZlodziej1->RysujPostac();
				pZlodziej1->LoadNpcToBoard();

				pZlodziej2->UsunPostacWrazZWskaznikiem();
				pZlodziej2->SetXY(4, 88);
				pZlodziej2->RysujPostac();
				pZlodziej2->LoadNpcToBoard();

				pSzefStrazy->SetNumDialogu(201);
				WyszukajDialog(Odpowiedzi, 201)->MoliweOdp[0] = 216;

				cout << endl << endl << "Otrzymales 250 sztuk zlota" << endl;
				if (_getch() == 244) _getch();

				pHero->Itemy.zloto += 250;

				StanGildiaZlodzieji = 8;

				cout << endl << "Kapitan: Wez jeszcze to. Nie wiem co to jest ani do czego sluzy. IM i tak jest juz nie potrzebne a Tobie moze sie przyda. Dziekuje raz jeszce! Bywaj!" << endl;
				pHero->Plecak.push_back(&Fragment[1]); // FRAGMENT 2 !!!!!!!!!!!!!!!!!!!!! JEST TU !!!!!!!!!!!!!
				cout << endl << endl << "Otrzymales fragment poematu" << endl;
				return;
			}


			return;
		}

		case 14: //Szajka zlodzieji -> GAME OVER
		{
			
			cout << endl << endl << "Przeszywajacy bol.." << endl;
			Sleep(1000);
			cout << "." << endl;
			Sleep(1000);
			cout << "." << endl;
			Sleep(1000);
			cout << "." << endl;
			Sleep(1000);
			cout << "Przyjemne uczucie ciepla" << endl;
			Sleep(1000);
			cout << "." << endl;
			Sleep(1000);
			cout << "." << endl;
			Sleep(1000);
			cout << "." << endl;
			Sleep(1000);
			cout << "Slabniesz.. Widzisz juz tylko ciemnosc" << endl;
			Sleep(1000);
			cout << "." << endl;
			Sleep(1000);
			cout << "." << endl;
			Sleep(1000);
			cout << "." << endl;
			Sleep(1000);
			cout << "i czujesz chlod.. Przerazliwy chlod" << endl;
			Sleep(1000);
			cout << "." << endl;
			Sleep(1000);
			cout << "." << endl;
			Sleep(1000);
			cout << "." << endl;
			Sleep(1000);
			cout << "teraz nie czujesz juz nic..." << endl;
			if (_getch() == 224) _getch();
			koniec = true;
			return;
		}

		case 15: //Czemu nie mozna sie dosiasc
		{
			cout << endl << endl << "Mezczyzna: Nie mozna, bo bede musial Cie zabic.." << endl;
			_getch();
			cout << endl  << pHero->RetName() << ": Moge chociaz znac powod?" << endl;
			_getch();
			cout << endl << "Mezczyzna: Ehh.. Jesli sie dosiadziesz to zaczniemy rozmawiac..." << endl;
			_getch();
			cout << endl << "Mezczyzna: Jesli zaczniemy rozmawiac to pewnie sie zaprzyjaznimy..." << endl;
			_getch();
			cout << endl << "Mezczyzna: Jesli sie zaprzyjaznimy to kiedys zaprosze Cie do swojego domu..." << endl;
			_getch();
			cout << endl << "Mezczyzna: Jesli zaprosze Cie do domu, to pewnie kiedysz przyjdziesz w odwiedzny..." << endl;
			_getch();
			cout << endl << "Mezczyzna: Jesli przyjdziesz w odwiedziny, to poznasz moja corke..." << endl;
			_getch();
			cout << endl << "Mezczyzna: Jesli poznasz moja corke, to pewnie sie w niej zakochasz..." << endl;
			_getch();
			cout << endl << "Mezczyzna: Jesli sie w niej zakochasz, to bedziesz chcial slubu..." << endl;
			_getch();
			cout << endl << "Mezczyzna: Jesli bedziesz chcial slubu, bediesz potrzebowal mojego blogoslawienstwa a ja Ci go nie udziele..." << endl;
			_getch();
			cout << endl << "Mezczyzna: Jesli juz Ci go nie udziele to pewnie uciekniesz z moja córka..." << endl;
			_getch();
			cout << endl << "Mezczyzna: A jak juz uciekniesz to ja Cie znajde i zabije..." << endl;
			_getch();
			cout << endl << "Mezczyzna: Juz rozmumiesz dlaczego nie mozesz sie dosiasc?" << endl;
			_getch();
			cout << endl << pHero->RetName() << ": Taaa..." << endl;
			if(_getch() == 224) _getch();


			return;

		}

		case 16: //handel z karczmarka
		{



			return;
		}

		case 17: //klepsydra
		{
			if (StanKlepsydra == 12)
			{
				cout << endl << endl << "Kupiec: Sprobuj zaczac od stajni.. Tam po raz ostatni widzialem woz z zawartoscia.." << endl;
				Sleep(2000);
				cout << endl << "Kupiec: Wypytaj stajennych.. Mieli sie nim opiekowac przez wieczor..." << endl;
				Sleep(2000);
				cout << endl << pHero->RetName() <<": Zobacze co da sie zrobic... ale niczego nie obiecuje... Bywaj" << endl;
				_getch();

				WyszukajDialog(Odpowiedzi, 250)->dialog = "Jakies postepy ?";
				WyszukajDialog(Odpowiedzi, 250)->MoliweOdp[0] = 217;
				WyszukajDialog(Odpowiedzi, 287)->MoliweOdp[1] = 220;

				StanKlepsydra = 13;
				return;
			}

			if (StanKlepsydra == 13) // dialog ze stajennymi -> poczetek tropienia
			{
				WyszukajDialog(Odpowiedzi, 287)->MoliweOdp[1] = 30;
				cout << endl << endl << "Najemnik: Dobra juz dobra.." << endl;
				Sleep(2000);
				cout << endl << "Najemnik: Noc byla ciemna..." << endl;
				Sleep(2000);
				cout << endl << pHero->RetName() <<": taa.. Jedzenie bylo dobre a piwo zimne ? ..." << endl;
				Sleep(2000);
				cout << endl << "Najemnik: Skad wiedziales?! Ja zem tego jeszce nie opowiadal! Tys wroz jaki ?" << endl;
				Sleep(2000);
				cout << endl << pHero->RetName() << ": Pewnie.. mozesz mi mowic Maciej..." << endl;
				Sleep(2000);
				cout << endl << "Najemnik: Panie Maciej... uwaz pan z tym wrozowaniem.. bo na stosie za czary skanczyc mozna!" << endl;
				Sleep(2000);
				cout << endl << pHero->RetName() << ": Ciesze sie niezmiernie ze sie o mnie troszczysz.. ale kontynuuj.." << endl;
				Sleep(2000);
				cout << endl << "Najemnik: No i ja zem panie wrozu przysnal.." << endl;
				Sleep(2000);
				cout << endl << "Najemnik: A jak mnie halas obudzil to widzialem z 5 ludzi, jeden taki nienaturalnie maly a drugi jakis pan wazny .. szlachcic lub czarodziej.." << endl;
				Sleep(2000);
				cout << endl << "Najemnik: Juz mialem ich obezwladnic ale poczulem bol i znowu zem przysnal..." << endl;
				Sleep(2000);
				cout << endl << "Najemnik: Rano znalazlem jedzynie troche kosztownosci ktore pan Korneliusz przewozil, widac bardzo sie spieszyli..." << endl;
				Sleep(2000);
				cout << endl << "Najemnik: Widac bardzo sie spieszyli.. Rozejrzyj sie panie Maciej to moze jeszcze uda sie cos znalezc.." << endl;
				Sleep(2000);
				cout << endl << pHero->RetName() << ": Albo uzyje moich wrozbarskich mocy.. " << endl;
				Sleep(2000);
				cout << endl << "Najemnik: Ano.. tysz mozna.. tylko pamietaj panie Maciej com panu o stosie mowil.." << endl;
				Sleep(2000);
				cout << endl << pHero->RetName() << ": Tak czy siak dziekuje za pomoc.. Bywaj!" << endl;
				_getch();

				StanKlepsydra = 14;
				//celowy brak return;
			}

			if (StanKlepsydra == 14) // tropienie
			{
				pWskazowka = new CNPC_w_obiekcie(pHero->RetName(), 286, 47, 36, Straznik, pPlansza);
				pWskazowka->SetSymbolPola('.');
				pWskazowka->RysujPostac();
				StanTropienia = 1;
				pPlansza->Plansza[47][36].SymbolPola = '.';


				StanKlepsydra = 15;
				return;
			}

			if (StanKlepsydra == 15) // tropienie
			{
				int x = 0, y = 0;

				switch (StanTropienia)
				{
				case 1: x = 36; y = 42; break;
				case 2: x = 30; y = 41; break;
				case 3: x = 27; y = 32; break;
				case 4: x = 19; y = 32; break;
				case 5: x = 13; y = 42; break;
				case 6: x = 14; y = 67; break;
				case 7: x = 24; y = 78; break;
				case 8: x = 28; y = 85; break;
				default: cout << endl << "Stan tropienia  > 8 lub < 1" << endl; _getch(); break;

				}
				pWskazowka->UsunPostacWrazZWskaznikiem();
				pWskazowka->SetXY(x, y);
				pWskazowka->RysujPostac();

				pPlansza->Plansza[x][y].SymbolPola = '.';

				
				if (++StanTropienia > 8)
				{
					StanKlepsydra = 16;
					pWskazowka->UsunPostacWrazZWskaznikiem();
					pPlansza->Plansza[32][89] = puste_pole;
					DrzwiWiezyMaga = false;
					delete pWskazowka;
					pWskazowka = NULL;
				}
				return;
			}

			if (StanKlepsydra == 19) //spawn clock mastera
			{
				pClockMaster = new CClockMaster(3, 81, ClockMasterBoss, 0, Las1, pPlansza);
				pClockMaster->RysujPostac();

				StanKlepsydra = 20;
				return;
			}

			if (StanKlepsydra == 21) // uzyskanie wytrychu
			{
				cout << endl << endl << pHero->RetName() << ": Trzymaj.." << endl;
				Sleep(2000);
				cout << endl << "Grabarz: Swietnie.. Dobra robota.." << endl;
				Sleep(2000);
				cout << endl << "Mezczyzna wyjal jakies dziwne urzadrzenie" << endl;
				Sleep(2000);
				cout << endl << "Grabarz: Wystarzczy ze teraz nalozyc..  " << endl;
				Sleep(2000);
				cout << endl << "Grabarz: Tutaj troche przekrecic..  " << endl;
				Sleep(2000);
				cout << endl << "Grabarz: a tu docisnac... " << endl;
				Sleep(2000);
				cout << endl << "Grabarz: Gotowe... i powodzenia.. " << endl;
				Sleep(2000);
				cout << endl << endl << pHero->RetName() << ": Dzieki.. Do zobaczenia" << endl;
				Sleep(2000);
				cout << endl << "Grabarz: Raczej zegnaj.. Moje zadanie zostalo wykonane.. Juz nigdy sie nie zobaczymy... " << endl;
				_getch();
				Wytrych = true;
				StanKlepsydra = 22;
				pGrabarz->UsunPostacWrazZWskaznikiem();
				pPlansza->Plansza[pGrabarz->retX()][pGrabarz->retY()] = puste_pole;
				pGrabarz->SetSymbolPola(' ');
				pGrabarz->SetXY(5, 82);
				pGrabarz->RysujPostac();
				WyszukajPrzedmiot(pHero->RozszerzenieEq, 19)->UsunPrzedmiot();


				return;
			}

			if (StanKlepsydra == 23)
			{
				cout << endl << endl << "Kupiec: Teraz dokonamy transakcji.." << endl;
				Sleep(2000);
				cout << endl << "Kupiec: W bibliotece czeka na Ciebie nagroda zgodnie z umowa" << endl;
				Sleep(2000);
				cout << endl << "Kupiec: Dostep do niej otrzymasz kladac artefakt na piedestale.." << endl;
				Sleep(2000);
				cout << endl << pHero->RetName() << ": Po co to cale przedstawienie?" << endl;
				Sleep(2000);
				cout << endl << "Kupiec: Dla bezpieczenstwa... piedestal sprawdzi czy artefakt jest prawdziwy a Ty bedziesz mial pewnosc ze nikt wczesniej nie ukradl Twojej nagrody" << endl;
				Sleep(2000);
				cout << endl << pHero->RetName() << ": Nie ufasz mi?" << endl;
				Sleep(2000);
				cout << endl << "Kupiec: Nie sadze bys mnie oklamal ale ostroznosci nigdy za wiele, po za tym tak juz zostalo to zaprojektowane i nic tego nie zmieni" << endl;
				Sleep(2000);
				cout << endl << pHero->RetName() << ": Niech bedzie, bywaj!" << endl;
				Sleep(2000);
				cout << endl << "Kupiec: Mam nadzieje ze interesy z Toba okaza sie czysta przyjemnoscia. Bywaj!" << endl;
				_getch();
				pKupiec->SetNumDialogu(310);
				StanKlepsydra = 24;
				return;
			}

			if (StanKlepsydra == 25)
			{
				bKlepsydra = true;
				pPlansza->Plansza[40][9] = puste_pole;
				bDostepDoZiutka = true;
				WyszukajDialog(Oddzywki, 246)->MoliweOdp[2] = 0;
				StanKlepsydra = 26;
				return;
			}


			return;
		}

		case 18: // Kim jest grabarz...
		{
			cout << endl << endl << "Grabarz: Straznikiem tego smutnego miejsca.. " << endl;
			Sleep(2000);
			cout << endl << "Grabarz: i osoba, ktora spotkasz na koncu swej drogii... " << endl;
			Sleep(2000);
			cout << endl << "Mowiac to Grabarz zaczal unosic kose" << endl;
			Sleep(2000);
			cout << endl << "Nie czekajac az Cie nia przezegna, uskoczyles na bezpieczna odleglosc " << endl;
			Sleep(3000);
			cout << endl << "Grabarz: heh.. " << endl;
			Sleep(1000);
			cout << endl << "Grabarz: Spokojnie.. ten czas jeszcze nie nadszedl.." << endl;
			Sleep(2000);
			cout << endl << pHero->RetName() << ": He he.. Swietny zart.. " << endl;
			Sleep(1000);
			cout << endl << "Powoli oddaliles sie z tego miejsca nie spuszczajc mezczyzny z oczu.... " << endl;
			_getch();



			return;
		}

		case 19: // Final Quest
		{
			if (StanFinalQuest == 1)
			{
				HistoriaAsgaru();
				StanFinalQuest = 2;

				system("cls");
				pPlansza->RysujPlansze();
				cout << endl << endl << pHero->RetName() << ": Potem nas zaatakowali...." << endl;
				Sleep(2000);
				cout << endl << pHero->RetName() << ": Ciezko ustalic cos sie stalo potem bo stracilem przytomnosc..." << endl;
				Sleep(3000);
				cout << endl << pHero->RetName() << ": Mozliwe, ze uznali mnie za martwego i przeoczyli.." << endl;
				Sleep(3000);
				cout << endl << pHero->RetName() << ": Potem tualem sie bez celu az wkoncu udalo mi sie znalezc droge do Dragonii" << endl;
				Sleep(3000);
				cout << endl << "Ziutmelson: Na kamien filozoficzny! Swietnie sie spisales!" << endl;
				Sleep(3000);
				cout << endl << "Ziutmelson: < do siebie > Alchemicy znow musza sie zebrac... " << endl;
				Sleep(3000);
				cout << endl << "Ziutmelson: Zostaniesz sowicie nagrodzony!" << endl;
				Sleep(3000);
				cout << endl << pHero->RetName() << ": Panie, to byl moj obowiazek" << endl;
				Sleep(3000);
				cout << endl << "Ziutmelson: Wiem ze duzo przeszedles ale musze prosic Cie o pomoc" << endl;
				Sleep(3000);
				cout << endl << "Ziutmelson: Tego zadania nie moze wykonac nikt inny" << endl;
				Sleep(3000);
				cout << endl << pHero->RetName() << ": Dlaczego ja?" << endl;
				Sleep(3000);
				cout << endl << "Ziutmelson: Jestes osoba z zwenatrz a na dodatek osoba ktora zginela w Asgarze.." << endl;
				Sleep(3000);
				cout << endl << pHero->RetName() << ": Co mam robic ?" << endl;
				Sleep(3000);
				cout << endl << "Ziutmelson: Nie tutaj... Szczegoly otrzymasz w skarbcu.. Udaj sie tam.. Zejscie jest za zamkiem.." << endl;

				pZiutmelson->SetNumerZdarzenia(315);
				pZiutmelson->RysujPostac();

				_getch();
				return;
			}
			if (StanFinalQuest == 5)
			{
				string password;
				cout << endl << endl << pHero->RetName() << ": ";
				cin >> password;
				
				if (password == "VARULV")
				{

					StanFinalQuest = 6;
					cout << endl << "Wiezien: Nie.. niemozliwe... Kim.. Kim jestes?" << endl;
					Sleep(4000);
					cout << endl << pHero->RetName() << ": Przyjacielem.." << endl;	
					Sleep(4000);
					cout << endl << "Wiezien: I co teraz?" << endl;
					Sleep(4000);
					cout << endl << pHero->RetName() << ": Jak to co? Miales zdac raport.." << endl;
					Sleep(4000);
					cout << endl << "Wiezien: Ale obaj jestesmy w wiezieniu" << endl;
					Sleep(4000);
					cout << endl << pHero->RetName() << ": Spelnij swoj obowiazek abym i ja mogl.." << endl;
					Sleep(4000);
					cout << endl << pHero->RetName() << ": Slyszalem ze jakis przybysz trafil za kraty skazany za zdrade i szpiegostwo" << endl;
					Sleep(4000);
					cout << endl << pHero->RetName() << ": Wiec musialem tu trafic i to sprawdzic.." << endl;
					Sleep(4000);
					cout << endl << pHero->RetName() << ": Duzo czasu minelo zenim Cie znalalzem wiec musimy dzialac" << endl;
					Sleep(4000);
					cout << endl << pHero->RetName() << ": Ja wkrotce stad wyjde za sprawa kaucji" << endl;
					Sleep(4000);
					cout << endl << "Wiezien: Rozumiem.. Wszystko czego sie dowiadzialem zakopalem w lesie" << endl;
					Sleep(4000);
					cout << endl << pHero->RetName() << ": W lesie ?! Jak mam to teraz znalezc? Mam zajrzec pod kazdego krzaka.." << endl;
					Sleep(4000);
					cout << endl << "Wiezien: Musialem jakos ratowac siebie i misje" << endl;
					Sleep(4000);
					cout << endl << "Wiezien: z tego co pamietam to schwytali mnie w krolewskim lesie..." << endl;
					Sleep(4000);
					cout << endl << pHero->RetName() << ": Dobra.. To bedzie musialo wystarczyc.. Dziekuje Ci za wszytko. Bywaj!" << endl;
					Sleep(4000);
					cout << endl << "Wiezien: To byl moj obowiazek! Niech zyje SZWA!" << endl;
					Sleep(4000);
					_getch();



					system("cls");
					pHero->UsunPostacWrazZWskaznikiem();
					pHero->SetXY(7, 79);
					pHero->RysujPostac();
					pPlansza->RysujPlansze();

					cout << endl << endl << "Zarzadca wiezienia: Wylaz! Zostala wplacona kaucja.. Badz grzeczny bo inaczej do nas wrocisz" << endl;
					Sleep(4000);
					cout << endl << "Zarzadca wiezienia:  A my nastepnym razem mozemy juz nie byc tacy mili..." << endl; 
					Sleep(4000);
					_getch();


					cout << endl << endl << endl << "< Od teraz mozesz rozkopywac ziemie wciskajac klawisz 'Q' >" << endl;
					Sleep(2000);
					_getch();

					pHero->SetKopanie();
					return;
				}

				cout << endl << "Wiezien: Co Ty tam belkoczesz? ..." << endl;

				_getch();

				return;
			}



			return;
		}

		case 20:
		{
			int decyzja;
			bool quit = false;
			
			cout << endl << endl << "1. Na architekta" << endl
				                 << "2. Na poete" << endl
							   	 << "3. Szczerze od serca" << endl;

			while (!quit)
			{
				decyzja = _getch();
				if (decyzja == 224)
					decyzja = _getch();

				switch (decyzja)
				{
				case '1':
				{
					cout << endl << endl << pHero->RetName() << ": Inspirujesz mnie architektonicznie... Kopuly i te sprawy... " << endl;
					Sleep(3000);
					cout << endl << "Ksiezniczka: JAK SMIESZ! STRAZ! STRAZ!" << endl;
					quit = true;
					break;
				}

				case '2':
				{
					cout << endl << endl << pHero->RetName() << ": Pani.. Twe oczy jak gwiazdy na niebie..." << endl;
					Sleep(3000);
					cout << endl << "Ksiezniczka: Odlegle i zimne.. Zalosne! STRAZ! STRAZ!" << endl;
					quit = true;
					break;
				}

				case '3':
				{
					cout << endl << endl << pHero->RetName() << ": Podobasz mi sie.. Chcialbym miec z Toba gromadke dzieci.." << endl;
					Sleep(3000);
					cout << endl << "Ksiezniczka: AAAAAAAA! RATUNKU! RATUNKU! STRAZ! STRAZ!" << endl;
					quit = true;
					break;
				}

				default: break;
				}
			}

			_getch();


			pHero->UsunPostacWrazZWskaznikiem();
			pHero->SetXY(5, 78);
			pHero->RysujPostac();

			system("cls");
			pPlansza->RysujPlansze();

			cout << endl << endl << pHero->RetName() << ": Ehhh.. Przynajmniej dotarlem do wiezienia..." << endl;
			_getch();

			WyszukajDialog(Odpowiedzi, 316)->MoliweOdp[0] = 0;

			return;
		}

		case 21:
		{



			return;
		}





		default: return;

	}

}
void CFabula::SprDialogNPCwDomu()
{
	if (pHero->RetisUndergorund() == true) return;

	int x = pHero->retX();
	int y = pHero->retY();

	DialogNPCwDomu(x, y, pSzefStrazy);
	DialogNPCwDomu(x, y, pPrzydupasSzefaStrazy);
	DialogNPCwDomu(x, y, pZonaTeodora);
	DialogNPCwDomu(x, y, pTeodorPoOdnalezieniu);
	DialogNPCwDomu(x, y, pMlynarz);
	DialogNPCwDomu(x, y, pPiec);
	DialogNPCwDomu(x, y, pKarczmarz);
	DialogNPCwDomu(x, y, pGosc1);
	DialogNPCwDomu(x, y, pGosc2);
	DialogNPCwDomu(x, y, pKupiec);	
	DialogNPCwDomu(x, y, pWskazowka);
	DialogNPCwDomu(x, y, pStajenny);

}

void CFabula::DialogNPCwDomu(int x, int y, CNPC_w_obiekcie* pointer)
{
	if (pointer == NULL) return;
	if (x == pointer->retX() && y == pointer->retY())
	{
		Dialog(pointer->RetNumDialogu(), pointer->RetName(), pointer);
		_getch();
	}
}

void CFabula::SprMonsters()
{
	int x, y;
	for (int i = 0; i < 3; i++)
	{
		GenerateXY(20, 15, 65, 51, &x, &y);
		TabWolf[i] = new CWolf(x, y, Wilk, i, Las2, pPlansza);
		
		
	}

	for (int i = 3; i < 8; i++)
	{
		GenerateXY(9, 4, 62, 43, &x, &y);
		TabWolf[i] = new CWolf(x, y, Wilk, i, Las1, pPlansza);
		
		
	}

	for (int i = 8; i < 9; i++)
	{
		GenerateXY(27, 22, 77, 68, &x, &y);
		TabWolf[i] = new CWolf(x, y, Wilk, i, Las3, pPlansza);
		
		
		
	}

	for (int i = 9; i < AmountOfWolf; i++)
	{
		GenerateXY(28, 25, 54, 45, &x, &y);
		TabWolf[i] = new CWolf(x, y, Wilk, i, Las4, pPlansza);
			
	}
	for(int i =0; i < AmountOfWolf; i++)
		TabWolf[i]->RysujPostac();

	GenerateXY(LasMiska.MaxX, LasMiska.MinX, LasMiska.MaxY, LasMiska.MinY, &x, &y);
	TabBear[0] = new CBear(x, y, Misiek, 0, LasMiska, pPlansza);
	GenerateXY(RzekaMiska.MaxX, RzekaMiska.MinX, RzekaMiska.MaxY, RzekaMiska.MinY, &x, &y);
	TabBear[1] = new CBear(x, y, Misiek, 1, RzekaMiska, pPlansza);
	GenerateXY(Las1.MaxX, Las1.MinX, Las1.MaxY, Las1.MinY, &x, &y);
	TabBear[2] = new CBear(x, y, Misiek, 2, Las1, pPlansza);
	GenerateXY(LasZaRzeka.MaxX, LasZaRzeka.MinX, LasZaRzeka.MaxY, LasZaRzeka.MinY, &x, &y);
	TabBear[3] = new CBear(x, y, Misiek, 3, LasZaRzeka, pPlansza);
	//TabBear[3] = new CBear(pHero->retX()+1, pHero->retY(), Misiek, 3, LasZaRzeka, pPlansza);
	
	for (int i = 0; i < AmountOfBear; i++)
		TabBear[i]->RysujPostac();

	TabGuardian[0] = new CUndead(24, 1, Truposz, 0, Las1, pPlansza);
	TabGuardian[1] = new CUndead(22, 3, Truposz, 1, Las1, pPlansza);
	TabGuardian[2] = new CUndead(24, 4, Truposz, 2, Las1, pPlansza);

	for (int i = 0; i < AmountOfGuardian; i++)
	{
		static_cast<CMonster* >(TabGuardian[i])->SetGuardian();
		TabGuardian[i]->RysujPostac(true);
	}


}
void CFabula::GenerateXY(int MaxX, int MinX, int MaxY, int MinY, int* X, int* Y)
{
	
	while (1)
	{
		*X = rand() % (MaxX - MinX + 1) + MinX;
		*Y = rand() % (MaxY - MinY + 1) + MinY;

		if (pPlansza->Plansza[*X][*Y] == puste_pole && pPlansza->PlanszaWskaznikow[*X][*Y] == NULL)
			return;
	}
	
}
bool CFabula::DeleteMonster(int index, int TYP)
{
	if (index < 0 )
	{
		cout << endl <<"Index nie moze byc mniejszy od zera" << endl;
		return false;
	}

	CMonster* Monster = NULL;
	int X,Y;
	ObszarWystepowania Teren;


	switch (TYP)
	{
	case 1: // WOLF
	{
		if (index >= AmountOfWolf)
		{
			cout << endl << "Index wychodzi poza tablice" << endl;
			return false;
		}
		Monster =  static_cast<CMonster*>(TabWolf[index]);
		Teren = Monster->RetTerytorium();
		Monster->UsunWskaznikPostaciZMapy();
		GenerateXY(Teren.MaxX, Teren.MinX, Teren.MaxY, Teren.MinY, &X,&Y);
		delete TabWolf[index];
		TabWolf[index] = new CWolf(X, Y, Wilk, index, Teren, pPlansza);
		TabWolf[index]->RysujPostac();
		TabWolf[index]->LoadNpcToBoard();
		break;
	}

	case 2: // BEAR
	{
		if (index >= AmountOfBear)
		{
			cout << endl << "Index wychodzi poza tablice" << endl;
			return false;
		}
		Monster = static_cast<CMonster*>(TabBear[index]);
		Teren = Monster->RetTerytorium();
		Monster->UsunWskaznikPostaciZMapy();
		GenerateXY(Teren.MaxX, Teren.MinX, Teren.MaxY, Teren.MinY, &X, &Y);
		delete TabBear[index];
		TabBear[index] = new CBear(X, Y, Misiek, index, Teren, pPlansza);
		TabBear[index]->RysujPostac();
		TabBear[index]->LoadNpcToBoard();
		break;
	}

	case 3: // Undead
	{
		if (index >= AmountOfUndead)
		{
			cout << endl << "Index wychodzi poza tablice" << endl;
			return false;
		}
		Monster = static_cast<CMonster*>(TabUndead[index]);
		Teren = Monster->RetTerytorium();
		Monster->UsunWskaznikPostaciZMapy();
		GenerateXY(Teren.MaxX, Teren.MinX, Teren.MaxY, Teren.MinY, &X, &Y);
		delete TabUndead[index];
		TabUndead[index] = new CBear(X, Y, Truposz, index, Teren, pPlansza);
		TabUndead[index]->RysujPostac();
		TabUndead[index]->LoadNpcToBoard();
		break;
	}

	case 4: // Vampire
	{		
	 break;
	}

	case 5: // Bandito
	{
		if (index >= AmountOfBandits)
		{
			cout << endl << "Index wychodzi poza tablice" << endl;
			return false;
		}
		Monster = static_cast<CMonster*>(TabBandits[index]);
		Teren = Monster->RetTerytorium();
		Monster->UsunWskaznikPostaciZMapy();
		GenerateXY(Teren.MaxX, Teren.MinX, Teren.MaxY, Teren.MinY, &X, &Y);
		delete TabBandits[index];
		TabBandits[index] = new CBear(X, Y, Bandito, index, Teren, pPlansza);
		TabBandits[index]->RysujPostac();
		TabBandits[index]->LoadNpcToBoard();
		break;
	}

	case 6: // Vectarian
	{
		delete pVectarian;
		pVectarian = NULL;
		break;
	}

	case 8: // Drzewacz
	{
		pDrzewacz->UsunWskaznikPostaciZMapy();
		delete pDrzewacz;
		pDrzewacz = NULL;
		break;
	}

	case 10:
	{
		if (index >= AmountOfGuardian)
		{
			cout << endl << "Index wychodzi poza tablice" << endl;
			return false;
		}
		Monster = static_cast<CMonster*>(TabUndead[index]);
		delete TabGuardian[index];
		TabGuardian[index] = NULL;
		break;
	}

	}



	return true;
}

void CFabula::ReturnOfTheKing()
{
	int a = 9;
	for (int i = 0; i < AmountOfGuards; i+=2)
	{
		a += 2;
		TabGuards[i] = new CNPC("Gwardzista", 'S', 311, 39, a, Straznik, pPlansza);
		TabGuards[i]->RysujPostac();
		TabGuards[i+1] = new CNPC("Gwardzista", 'S', 311, 41, a, Straznik, pPlansza);
		TabGuards[i + 1]->RysujPostac();
	}


	int ZiutX = 40;
	int ZiutY = 37;
	pZiutmelson->UploadPosition(ZiutX, ZiutY);

	{
		for (int i = 0; i < 4; i++)
		{
			CwiercNuta.Wywolaj(G4);
			Osemka.Wywolaj(G4);
			Szesnastka.Wywolaj(G4);
			Szesnastka.Wywolaj(G4);
			Szesnastka.Wywolaj(G4);
			Osemka.Wywolaj(G4);
			Szesnastka.Wywolaj(G4);
			Szesnastka.Wywolaj(G4);

			Szesnastka.Wywolaj(Dis4);
			Szesnastka.Wywolaj(Dis4);
			Osemka.Wywolaj(Dis4);
			PauzaCwiercNutowa.Wywolaj();
			pZiutmelson->UploadPosition(ZiutX, --ZiutY);
		}
		
		
		CwiercNuta.Wywolaj(G4);
		pZiutmelson->UploadPosition(ZiutX, --ZiutY);
		CwiercNuta.Wywolaj(G4);
		pZiutmelson->UploadPosition(ZiutX, --ZiutY);
		CwiercNuta.Wywolaj(G4);
		pZiutmelson->UploadPosition(ZiutX, --ZiutY);
		Osemka.Wywolaj_K(Dis4);
		pZiutmelson->UploadPosition(ZiutX, --ZiutY);
		Szesnastka.Wywolaj(Ais4);
		pZiutmelson->UploadPosition(ZiutX, --ZiutY);

		CwiercNuta.Wywolaj(G4);
		pZiutmelson->UploadPosition(ZiutX, --ZiutY);
		Osemka.Wywolaj_K(Dis4);
		pZiutmelson->UploadPosition(ZiutX, --ZiutY);
		Szesnastka.Wywolaj(Ais4);
		pZiutmelson->UploadPosition(ZiutX, --ZiutY);
		PolNuta.Wywolaj(G4);
		pZiutmelson->UploadPosition(ZiutX, --ZiutY);

		CwiercNuta.Wywolaj(D5);
		pZiutmelson->UploadPosition(ZiutX, --ZiutY);
		CwiercNuta.Wywolaj(D5);
		pZiutmelson->UploadPosition(ZiutX, --ZiutY);
		CwiercNuta.Wywolaj(D5);
		pZiutmelson->UploadPosition(ZiutX, --ZiutY);
		Osemka.Wywolaj_K(Dis5);
		pZiutmelson->UploadPosition(ZiutX, --ZiutY);
		Szesnastka.Wywolaj(Ais4);
		pZiutmelson->UploadPosition(ZiutX, --ZiutY);

		CwiercNuta.Wywolaj(Fis4);
		pZiutmelson->UploadPosition(ZiutX, --ZiutY);
		Osemka.Wywolaj_K(Dis4);
		pZiutmelson->UploadPosition(ZiutX, --ZiutY);
		Szesnastka.Wywolaj(Ais4);
		pZiutmelson->UploadPosition(ZiutX, --ZiutY);
		PolNuta.Wywolaj(G4);
		pZiutmelson->UploadPosition(ZiutX, --ZiutY);

		CwiercNuta.Wywolaj(G5);
		pZiutmelson->UploadPosition(ZiutX, --ZiutY);
		Osemka.Wywolaj_K(G4);
		pZiutmelson->UploadPosition(ZiutX, --ZiutY);
		Szesnastka.Wywolaj(G4);
		pZiutmelson->UploadPosition(ZiutX, --ZiutY);
		CwiercNuta.Wywolaj(G5);
		pZiutmelson->UploadPosition(ZiutX, --ZiutY);
		Osemka.Wywolaj_K(Fis5);
		pZiutmelson->UploadPosition(ZiutX, --ZiutY);
		Szesnastka.Wywolaj(F5);
		pZiutmelson->UploadPosition(ZiutX, --ZiutY);


		Szesnastka.Wywolaj(E5);
		pZiutmelson->UploadPosition(ZiutX, --ZiutY);
		Szesnastka.Wywolaj(Dis5);
		pZiutmelson->UploadPosition(ZiutX, --ZiutY);
		Osemka.Wywolaj(E5);
		pZiutmelson->UploadPosition(ZiutX, --ZiutY);
		PauzaOsemkowa.Wywolaj();
		Osemka.Wywolaj(Gis5);
		CwiercNuta.Wywolaj(Cis5);
		Osemka.Wywolaj(C5);
		Szesnastka.Wywolaj(B4);

		Szesnastka.Wywolaj(Ais4);
		Szesnastka.Wywolaj(A4);
		Osemka.Wywolaj(Ais4);
		PauzaOsemkowa.Wywolaj();
		Osemka.Wywolaj(Dis4);
		CwiercNuta.Wywolaj(G4);
		Osemka.Wywolaj_K(Dis4);
		Szesnastka.Wywolaj(G4);

		CwiercNuta.Wywolaj(Ais4);
		Osemka.Wywolaj_K(G4);
		Szesnastka.Wywolaj(Ais4);
		PolNuta.Wywolaj(D5);
	}




	for (int i = 2; i < AmountOfGuards; i ++)
		TabGuards[i]->UsunPostacWrazZWskaznikiem();		
	
	TabGuards[2]->SetXY(43, 11);
	TabGuards[3]->SetXY(37, 11);
	TabGuards[4]->SetXY(36, 11);
	TabGuards[5]->SetXY(44, 11);

	TabGuards[6]->SetXY(38, 2);
	TabGuards[7]->SetXY(40, 1);
	TabGuards[8]->SetXY(40, 3);
	TabGuards[9]->SetXY(42, 1);
	TabGuards[10]->SetXY(42, 3);

	TabGuards[11]->SetXY(46, 1);
	TabGuards[12]->SetXY(48, 1);
	TabGuards[13]->SetXY(46, 3);
	TabGuards[14]->SetXY(48, 3);
	TabGuards[15]->SetXY(46, 5);
	TabGuards[16]->SetXY(48, 5);
	TabGuards[17]->SetXY(47, 7);

	TabGuards[18]->SetXY(37, 15);
	TabGuards[19]->SetXY(37, 20);
	TabGuards[20]->SetXY(37, 43);
	TabGuards[21]->SetXY(42, 43);
	TabGuards[22]->SetXY(38, 5);
	TabGuards[23]->SetXY(42, 5);

	TabGuards[24]->SetXY(7, 80);
	TabGuards[25]->SetXY(7, 78);
	TabGuards[26]->SetXY(29, 12);

	TabGuards[27]->SetXY(43, 43);


	for (int i = 2; i < AmountOfGuards-1; i++)
		TabGuards[i]->RysujPostac();

	TabGuards[27]->RysujPostac(true);

	pPlansza->Plansza[40][9] = PoleStrzezone;
}

bool CFabula::Walka(CCharacter* Potwor)
{
	int hp = pHero->RetParametr("hp");
	int enemy_hp = Potwor->RetParametr("hp");
	int str = (50 - Potwor->RetParametr("sila")) + pHero->RetParametr("sila");
	int enemy_str = (50 - pHero->RetParametr("sila")) + Potwor->RetParametr("sila");
	int def = pHero->RetParametr("obrona");
	int enemy_def = Potwor->RetParametr("obrona");
	int dmg = pHero->Itemy.bron.parametr;
	int enemy_dmg = pHero->RetParametr("sila") / 10;
	int lose_hp = 0;
	int power = pHero->RetParametr("moc");
	int enemy_power = Potwor->RetParametr("moc");
	bool win = false;
	bool combo = false;


	if ( hp == 0)
	{
		cout << pHero->RetName() << ": Jestem zbyt zmeczony aby walczyc..." << endl;
		return false;
	}

	while (!win)
	{
		cout << pHero->RetName() << " hp: " << hp << endl << endl;
		if ((rand() % 100 + 1) <= str)
		{

			if ((rand() % 100 + 1) <= power) combo = true;
			do 
			{
				lose_hp = rand() % dmg - enemy_def;
				if (lose_hp < 0) lose_hp = 0;
				enemy_hp -= lose_hp;
				cout << pHero->RetName() << " uderza " << pHero->Itemy.bron.nazwa << " za " << lose_hp << endl << endl;
				Beep(494, 500); // B
				Sleep(1000);
			} while (combo == true && !(combo = false));
			
		}
		else
		{
			cout << "Przeciwnik uskoczyl..." << endl;
			Sleep(1000);
		}


		
		cout <<"                                 " << Potwor->RetName() << " hp: " << enemy_hp << endl << endl;
		if ((rand() % 100 + 1) <= str)
		{
			if ((rand() % 100 + 1) <= enemy_power) combo = true;
			do
			{
				lose_hp = rand() % enemy_dmg - def;
				if (lose_hp < 0) lose_hp = 0;
				hp -= lose_hp;
				cout << "                                 " << Potwor->RetName() << " uderza  za " << lose_hp << endl << endl;
				Beep(800, 500);
				Sleep(1000);
			} while (combo == true && !(combo = false));
		}
		else
		{
			cout << "                                 Przeciwnik uskoczyl..." << endl;
			Sleep(1000);
		}
		
		if (hp <= 0)
		{
			cout << "Arghhh... " << endl;
			return false;
		}
		if (enemy_hp <= 0)
		{
			cout << "Wygralem ! " << endl;
			pHero->SetHp(hp);
			return true;
		}


	}


	return false;
}


bool CCharacter::LoadNpcToBoard()
{
	pPlansza->PlanszaWskaznikow[x][y] = this;
	
	return true;
}

void CCharacter::UploadPosition(int x, int y)
{
	system("cls");
	UsunPostacWrazZWskaznikiem();
	this->x = x;
	this->y = y;
	RysujPostac();
	pPlansza->RysujPlansze();
}

bool CFragmentOfPoem::UstawKolejnosc(CFabula* pFabula) const
{
	int sign;
	
	

	do {
		system("cls");
		cout << endl << endl << ":::::::::::::   " << Opis << "   :::::::::::::" << endl;
		cout << "                 Chronologia: " << pFabula->FragmentOpis[Kolejnosc - 1].ObecnyNum << endl;
		cout << "<--                 ENTER                 ->" << endl;

		sign = _getch();
		if (sign == 224)
			sign = _getch();


		if (sign == 75)
			if (--(pFabula->FragmentOpis[Kolejnosc-1].ObecnyNum) <= 0)
				pFabula->FragmentOpis[Kolejnosc-1].ObecnyNum = MaxNumber;

		if (sign == 77)
			if (++(pFabula->FragmentOpis[Kolejnosc-1].ObecnyNum) > MaxNumber)
				pFabula->FragmentOpis[Kolejnosc-1].ObecnyNum = 1;

	} while (sign != 13 );
	
	
	if (pFabula->FragmentOpis[Kolejnosc-1].ObecnyNum == Kolejnosc)
		pFabula->FragmentOpis[Kolejnosc-1].isGood = true;


	return true;
}


void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void CNpcSpec::Ruch(int x, int y)
{
	pPlansza->PlanszaSpec[this->x][this->y] = puste_pole;
	this->x = x;
	this->y = y;
	pPlansza->PlanszaSpec[this->x][this->y] = PolePostaci;
}


bool CBook::Czytaj() const
{
	fstream plik;

	plik.open("Books.txt", ios::in);
	
	if (!plik.good())
		return false;

	char znak;
	int Num = -1;
	system("cls");
	cout << "###################################################" << endl;
	cout << Nazwa << endl;
	cout << "###################################################" << endl << endl;
	while (!plik.eof())
	{
		plik.get(znak);
		if (znak == '$')
		{
			plik.get(znak);
			plik >> Num;
			if (Num == NumerKsiazki)
				break;
				
			Num = -1;
		}

	}

	if(Num != -1)
	while (!plik.eof())
	{
		plik.get(znak);
		if (znak == '$')
			break;
		cout << znak;

	}




	plik.close();

	_getch();

	return true;

}