#include "Nuty.h"

void ImperialMarch()
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
	}
	PauzaCwiercNutowa.Wywolaj();

	CwiercNuta.Wywolaj(G4);
	CwiercNuta.Wywolaj(G4);
	CwiercNuta.Wywolaj(G4);
	Osemka.Wywolaj_K(Dis4);
	Szesnastka.Wywolaj(Ais4);

	CwiercNuta.Wywolaj(G4);
	Osemka.Wywolaj_K(Dis4);
	Szesnastka.Wywolaj(Ais4);
	PolNuta.Wywolaj(G4);

	CwiercNuta.Wywolaj(D5);
	CwiercNuta.Wywolaj(D5);
	CwiercNuta.Wywolaj(D5);
	Osemka.Wywolaj_K(Dis5);
	Szesnastka.Wywolaj(Ais4);

	CwiercNuta.Wywolaj(Fis4);
	Osemka.Wywolaj_K(Dis4);
	Szesnastka.Wywolaj(Ais4);
	PolNuta.Wywolaj(G4);

	CwiercNuta.Wywolaj(G5);
	Osemka.Wywolaj_K(G4);
	Szesnastka.Wywolaj(G4);
	CwiercNuta.Wywolaj(G5);
	Osemka.Wywolaj_K(Fis5);
	Szesnastka.Wywolaj(F5);

	
	Szesnastka.Wywolaj(E5);
	Szesnastka.Wywolaj(Dis5);
	Osemka.Wywolaj(E5);
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