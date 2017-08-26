#include "Nuty.h"
#include "Header.h"
#include <windows.h>
#include <time.h>

extern bool koniec;




void ASCIItable()
{
	int j = 0;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	for (int i = 0; i < 224; i++)
	{		
		cout << i << " = " << static_cast<char>(i) << "   ";
		if (++j == 10)
		{
			cout << endl;
			j = 0;
		}
		
	}
	_getch();
}
void beepsong()
{
	//Oktawa 5 tylko B jest z 4 
	Beep(554, 250); // C#
	Beep(554, 250); // C#
	Beep(659, 500); // E
    Beep(622, 500); // D#

	Beep(494, 500); // B
	Beep(554, 500); // C#
	Beep(554, 250); // C#
	Beep(659, 500); // E
	Beep(622, 500); // D#
	Beep(494, 500); // B
	Sleep(500); // pauza ósemkwa
	Beep(831, 500); // G#

	Beep(659, 250); // E
	Beep(740, 500); // F#
	Beep(622, 500); // D#
	Beep(659, 500); // E
	Beep(554, 500); // C#
	Beep(622, 500); // D#
	Beep(494, 500); // B

	Sleep(500); // pauza ósemkwa
	Beep(831, 500); // G#
	Beep(659, 250); // E
	Beep(740, 500); // F#
	Beep(622, 500); // D#
	Beep(659, 500); // E
	Beep(622, 500); // D#

	Beep(554, 500); // C#
	Beep(494, 500); // B
	Sleep(500); // pauza ósemkwa
	Beep(988, 500); // B  w 5 oktawie
	Beep(784, 500); // G
	Beep(880, 500); // A
	Beep(740, 500); // F#
	Beep(784, 500); // G

	Beep(659, 500); // E
	Beep(740, 500); // F#
	Beep(587, 500); // D
	Sleep(500); // pauza ósemkwa
	Beep(988, 500); // B  w 5 oktawie
	Beep(784, 500); // G
	Beep(880, 500); // A

	Beep(740, 500); // F#
	Beep(784, 500); // G
	Beep(740, 500); // F#
	Beep(659, 500); // E
	Beep(622, 500); // D#
	
	Sleep(4000); // pauza calonutowa

	Beep(622, 500); // D#
	Beep(494, 500); // B
	Beep(554, 500); // C#
	Beep(466, 500); // A# w 4 oktawie

	Beep(494, 500); // B
	Beep(415, 500); // G# w 4 oktawie
	Beep(466, 500); // A# w 4 oktawie
	Beep(370, 500); // F# w 4 oktawie 
	Sleep(500); // pauza ósemkwa
	Beep(622, 500); // D#
	Beep(494, 500); // B
	Beep(554, 500); // C#

	Beep(466, 500); // A# w 4 oktawie
	Beep(494, 500); // B
	Beep(466, 500); // A# w 4 oktawie
	Beep(415, 500); // G# w 4 oktawie
	Beep(370, 500); // F# w 4 oktawie 
	Sleep(500); // pauza ósemkwa

	Beep(622, 500); // D#
	Beep(494, 250); // B
	Beep(554, 500); // C#
	Beep(466, 500); // A# w 4 oktawie
	Beep(494, 250); // B
	Beep(415, 500); // G# w 4 oktawie
	Beep(466, 500); // A# w 4 oktawie

	Beep(370, 500); // F# w 4 oktawie 
	Sleep(500); // pauza ósemkwa
	Beep(622, 500); // D#
	Beep(494, 250); // B
	Beep(554, 500); // C#
	Beep(466, 500); // A# w 4 oktawie
	Beep(494, 250); // B
	Beep(466, 500); // A# w 4 oktawie

	Beep(415, 500); // G# w 4 oktawie
	Beep(370, 500); // F# w 4 oktawie
	Sleep(500); // pauza ósemkwa
	Beep(622, 500); // D#
	Beep(494, 250); // B
	Beep(554, 500); // C#
	Beep(466, 500); // A# w 4 oktawie

















}



int main()
{	
	
	
	CPlansza MainBoard;
	CPlansza* pPlansza = &MainBoard; // wskaznik na plansze
	
	CGilgamesh Gilgamesh(pPlansza); // GILGAMESH

	CMainHero Hero("Frimer", 42, 98, pPlansza); // 42,98
	//Hero.Switch_undergorund(); // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1
	CMainHero* pHero = &Hero; // wskaznik na bohatera
	Hero.RysujPostac();	

	//Obiekty na planszy 
	Gilgamesh.RysujObiekty();
	
	CZamek Zamek(45, 5, 45, pPlansza);
	Zamek.RysujObiekt();

	CFabula Fabula(pHero, pPlansza); // FABULA	
	Hero.SetpFabula(&Fabula);
	
	srand(static_cast<unsigned int>(time(NULL)));
	Fabula.SprMonsters();
	while(1)
	{
		
		if(Hero.RetisUndergorund())
			MainBoard.RysujPodziemia(Hero.retX(),Hero.retY());
		else
			MainBoard.RysujPlansze();

			cout << "X = " << Hero.retX() << ", " << "Y = " << Hero.retY();
		
			int decyzja = _getch();
			if (decyzja == 224)
				decyzja = _getch();
			switch (decyzja)
			{
			case 27: koniec = true; break;
			case 9: {
				CCharacter* NPC = Hero.SzukajWskaznikaNPC();
				if (NPC == NULL) break;
				Fabula.Dialog(Hero.SzukajNPC(), NPC->RetName(), NPC); break;
				} //"tab"

			case 'z': Hero.Switch_undergorund();
			default: Hero.MenuGracza(decyzja); 
			}

		if (koniec) break;
		Fabula.SprFabula();
		Fabula.SprDialogNPCwDomu();
		//gotoxy(0, 0);
		system("cls");
	}

	cout << " GAME OVER" << endl;
	//ASCIItable();
	//ImperialMarch();
	//beepsong();

		
	pPlansza = NULL;
	pHero = NULL;

	return 0;
}


// Sojusz jest jak malzenstwo, w ktorym zazdrosc jest wieksza od milosci
// Wiek dziececy sie po to  zeby robic glupstwa, a dojrzaly aby ich potem zalowac...

/*
case 13:
{
if (Hero.DrawElement())
cout << " Plik otwarto poprawnie";
else
cout << " Plik NIE ZOSTALA OTWARTY";
break;
}
*/