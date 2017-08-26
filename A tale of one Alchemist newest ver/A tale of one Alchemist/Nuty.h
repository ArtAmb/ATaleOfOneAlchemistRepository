#pragma once
#include <iostream>
#include <conio.h>
#include <windows.h>


struct pauza
{
	int ms_czas;
	void Wywolaj() const { Sleep(ms_czas); }
};


struct nuta
{
	int ms_czas;
	void Wywolaj(int freq) const { Beep(freq, ms_czas); }
	void Wywolaj_K(int freq) const { Beep(freq, ms_czas + ms_czas/2); }
};

const pauza PauzaOsemkowa = { 500/2 };
const pauza PauzaCwiercNutowa = { 1000/2 };
const pauza PauzaPolNutowa = { 2000 };
const pauza PauzaCaloNutowa = { 4000 };

const nuta Szesnastka = { 250/2 };
const nuta Osemka = { 500/2 };
const nuta CwiercNuta = { 1000/2 };
const nuta PolNuta = { 2000/2 };
const nuta CalaNuta = { 4000/2 };

enum Oktawa0 { C0 = 16, Cis0, D0, Dis0 = 20, E0, F0, Fis0, G0 = 25, Gis0, A0 = 28, Ais0, B0 = 31 };
enum Oktawa1 { C1 = 33, Cis1 = 35, D1 = 37, Dis1 = 39, E1 = 41, F1= 44, Fis1= 46, G1 = 49, Gis1 = 52, A1 = 55, Ais1 = 58, B1 = 62 };
enum Oktawa2 { C2 = 65, Cis2 = 69, D2 = 73, Dis2 = 78, E2 = 82, F2 = 87, Fis2 = 93, G2 = 98, Gis2 = 104, A2 = 110, Ais2 = 117, B2 = 124 };
enum Oktawa3 { C3 = 131, Cis3 = 139, D3 = 147, Dis3 = 156, E3 = 165, F3 = 175, Fis3 = 185, G3 = 196, Gis3 = 208, A3 = 220, Ais3 = 233, B3 = 247 };
enum Oktawa4 { C4 = 262, Cis4 = 278, D4 = 294, Dis4 = 311, E4 = 330, F4 = 349, Fis4 = 370, G4 = 392, Gis4 = 415, A4 = 440, Ais4 = 466, B4 = 494 };
enum Oktawa5 { C5 = 523, Cis5 = 554, D5 = 587, Dis5 = 622, E5 = 659, F5 = 699, Fis5 = 740, G5 = 784, Gis5 = 831, A5 = 880, Ais5 = 932, B5 = 988 };
enum Oktawa6 { C6 = 1047, Cis6 = 1109, D6 = 1175, Dis6 = 1245, E6 = 1319, F6 = 1397, Fis6 = 1475, G6 = 1568, Gis6 = 1661, A6 = 1760, Ais6 = 1865, B6 = 1976 };
enum Oktawa7 { C7 = 2093, Cis7 = 2218, D7 = 2349, Dis7 = 2489, E7 = 2637, F7 = 2794, Fis7 = 2960, G7 = 3136, Gis7 = 3322, A7 = 3520, Ais7 = 3729, B7 = 3951 }; 
enum Oktawa8 { C8 = 4186, Cis8 = 4435, D8 = 4699, Dis8 = 4978, E8 = 5274, F8 = 5588, Fis8 = 5920, G8 = 6272, Gis8 = 6645, A8 = 7040, Ais8 = 7459, B8 = 7902 };


void ImperialMarch();