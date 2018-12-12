#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "time.h"

// Struktur Person erstellen: Adrian Cerdeira
typedef struct Person {
	char Vorname[40];
	char Nachname[40];
	int Jahrgang;
	struct Person* pNext;
	struct Person* pPrev;
} struPerson;

// Main-Funktion erstellen: Mario Forrer und Adrian Cerdeira
int main() {
//	TODO: Bessere Speicherung der Eingabe
	char input = 'A';

// TODO: Restliche verlangte Funktionen einbauen.
// TODO: Umlaute einfacher formatieren
	printf("Was m%cchten Sie tun?: Sortieren(s), Liste l%cschen(d), Elemente l%cschen (e), Ausgeben(a), \n", 148, 148, 148);
	scanf("%s", input);
	switch (input)
	{
	case 's':
		// Sort Funktion
		break;
	case 'd':
		// Delete Funktion
	case 'a':
		// Print Funktion
		break;
	case 'l':
		// Listenauswahl
		break;
	case 'e':
		//Delete Funktion (Einzelne Elemente)
		break; 
	default:
		break;
	}
}

//Create Funktion erstellen: Mario Forrer
struPerson* Create(const int Anzahl) {
	srand((unsigned) time(NULL));
	struPerson *pStart = NULL;
	struPerson *pCurrent = NULL;
	struPerson *pPrevious = NULL;
	for (int i = 0; i < Anzahl; i++) {
		pCurrent = (struPerson *)malloc(sizeof(struPerson));
		pCurrent->Vorname[40] = 'A' + rand() % 26;
		pCurrent->Nachname[40] = 'A' + rand() % 26;
		pCurrent->Jahrgang = 1900 + rand() % 118;
		if (pPrevious == NULL) pStart = pCurrent;
		else {
			pCurrent->pPrev = pPrevious;
			pCurrent->pPrev->pNext = pCurrent;
		}
		pPrevious = pCurrent;
	}
	return pStart;
}

//Bubblesort Funktion erstellen: Adrian Cerdeira
struPerson* BubbleSort(struPerson* pStart) {
	return 0;
}

//*Sort Funktion erstellen: Mario Forrer
