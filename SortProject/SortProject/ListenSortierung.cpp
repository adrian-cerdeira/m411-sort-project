#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "time.h"

// Struktur Person erstellen: Mario Forrer

typedef struct PersonData {
	char Vorname[40];
	char Nachname[40];
	int Jahrgang;
} struData;

// Struktur Person erstellen: Adrian Cerdeira
typedef struct Person {
	struData* pData;
	struct Person* pNext;
	struct Person* pPrev;
} struPerson;



// User-Interface: Mario Forrer
void createUserInterface() {

	char input;

	// TODO: Restliche verlangte Funktionen einbauen & Umlaute einfacher formatieren
	printf("Was m%cchten Sie tun?: Sortieren(s), Liste l%cschen(d), Elemente l%cschen (e), Ausgeben(a), \n", 148, 148, 148);
	scanf("%c", &input);
	switch (input)
	{
	case 's':
		// sort Funktion
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
		printf("Die eingabe ist Ungültig");
		break;
	}
	
}

// Main-Funktion erstellen: Mario Forrer und Adrian Cerdeira
int main() {
	createUserInterface();
}

//Create Funktion erstellen: Mario Forrer
struPerson* Create(const int Anzahl) {
	srand((unsigned)time(NULL));
	struPerson *pStart = NULL;
	struPerson *pCurrent = NULL;
	struPerson *pPrevious = NULL;

	for (int i = 0; i < Anzahl; i++) {
		pCurrent = (struPerson *)malloc(sizeof(struPerson));
		pCurrent->pData = (struData *)malloc(sizeof(struData));
		pCurrent->pData->Vorname[40] = 'A' + rand() % 26;
		pCurrent->pData->Nachname[40] = 'A' + rand() % 26;
		pCurrent->pData->Jahrgang = 1900 + rand() % 118;
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

//QuickSort Funktion erstellen: Mario Forrer
struPerson* QuickSort(struPerson* pStart) {
	return 0;
}

// Counter-Funktion erstellen: Adrian Cerdeira
int countElements(struPerson* pStart) {
	int counter = 0;
	while (pStart->pNext == NULL) {
		counter++;
	};
	return counter;
}
