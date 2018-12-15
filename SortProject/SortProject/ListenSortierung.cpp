#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "string.h"

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

//Create Funktion erstellen: Mario Forrer
struPerson* Create(const int Anzahl) {
	srand((unsigned)time(NULL));
	struPerson *pStart = NULL;
	struPerson *pCurrent = NULL;
	struPerson *pPrevious = NULL;

	for (int i = 0; i < Anzahl; i++) {
		pCurrent = (struPerson *)malloc(sizeof(struPerson));
		pCurrent->pData = (struData *)malloc(sizeof(struData));
//		char temp = (65 + +rand() % 26);
		
// TODO: Zufälliger Buchstaben einfügen (Anstelle von kevin Nachname)
		strcpy(pCurrent->pData->Vorname, "Kevin");
		strcpy(pCurrent->pData->Nachname, "Nachname");
		pCurrent->pData->Jahrgang = 1900 + rand() % 118;
		if (pPrevious == NULL) pStart = pCurrent;
		else {
			pCurrent->pPrev = pPrevious;
			pCurrent->pPrev->pNext = pCurrent;
		}
		pPrevious = pCurrent;
		if ((i + 1) == Anzahl) pCurrent->pNext = NULL;
	}
	return pStart;
}

//Output Funktion erstellen: Mario Forrer
void Output(struPerson* pStart) {

	if (pStart != NULL) {
		for (struPerson* pOut = pStart; pOut != NULL; pOut = pOut->pNext) {
			printf("\n ---- \nElement:\n Name: "); // \nVorname: %s \nAlter: %i", pOut->pData->Nachname, pOut->pData->Vorname, pOut->pData->Jahrgang);
			for (int i = 0; pOut->pData->Nachname[i] != '\0'; i++) printf("%c", pOut->pData->Nachname[i]);
			printf("\n Vorname: ");
			for (int i = 0; pOut->pData->Vorname[i] != '\0'; i++) printf("%c", pOut->pData->Vorname[i]);
			printf("\n Geburtstag: %i", pOut->pData->Jahrgang);
		}
	}
	else {
		printf("Keine Elemente vorhanden");
	}
	
}

// Main-Funktion erstellen: Mario Forrer und Adrian Cerdeira
int main() {
	struPerson* pStart = Create(15);
	char input;
	while (true) {
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
			Output(pStart);
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
		char input = NULL;
	}
	
}

//Bubblesort Funktion erstellen: Adrian Cerdeira
struPerson* BubbleSort(struPerson* pStart) {
	return 0;
}

//(QuickSort) QuickSortPrep Funktion erstellen: Mario Forrer
struPerson* QuickSortPrep(struPerson* pStart) {
//	int max = countElements(pStart) - 1;
	struPerson* pLast;
	struPerson* pTemp = pStart;
	while (pTemp->pNext == NULL) {
		pLast = pTemp;
		pTemp = pTemp->pNext;
	};


	return pStart;
}

//(QuickSort) Partition Funktion erstellen: Mario Forrer
struPerson* Partition(struPerson* pStart, struPerson* pLow, struPerson* pHigh) {
	struPerson* pPivot = pHigh;
	struPerson* pI = pLow->pPrev;
	return pStart;
}

//(QuickSort) QuickSort Funktion erstellen: Mario Forrer
struPerson* QuickSort(struPerson* pStart, struPerson* pLow, struPerson* pHigh) {
	if (pLow < pHigh) {
		struPerson* pivot = Partition(pStart, pLow, pHigh);
	}
	return pStart;
}

// Counter-Funktion erstellen: Adrian Cerdeira
int countElements(struPerson* pStart) {
	int counter = 0;
	struPerson* pTemp = pStart;
	while (pTemp->pNext == NULL) {
		counter++;
	};
	return counter;
}
