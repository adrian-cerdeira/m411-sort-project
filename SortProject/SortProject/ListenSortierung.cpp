// Catch Error of scanf
#define _CRT_SECURE_NO_WARNINGS
// Umlaute definieren
#define ue (unsigned char)129
#define oe (unsigned char)148

#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "string.h"

// Struktur PersonData erstellen: Mario Forrer
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
		bool isSecondElement = (i + 1) == Anzahl;
		if (isSecondElement) {
			pCurrent->pNext = NULL;
			pStart->pPrev = NULL;
		}
	}

	return pStart;
}

//Output Funktion erstellen: Mario Forrer
void Output(struPerson* pStart) {

	if (pStart != NULL) {
		for (struPerson* pOut = pStart; pOut != NULL; pOut = pOut->pNext) {
			// Ausgabe Daten: \nVorname: %s \nAlter: %i", pOut->pData->Nachname, pOut->pData->Vorname, pOut->pData->Jahrgang);
			printf("\n ---- \nElement:\n Name: ");
			for (int i = 0; pOut->pData->Nachname[i] != '\0'; i++) printf("%c", pOut->pData->Nachname[i]);
			printf("\n Vorname: ");
			for (int i = 0; pOut->pData->Vorname[i] != '\0'; i++) printf("%c", pOut->pData->Vorname[i]);
			printf("\n Geburtstag: %i\n", pOut->pData->Jahrgang);
		}
	}
	else {
		printf("Keine Elemente vorhanden");
	}

}

// TODO QUICKSORT: Fehler suchen, warum Werte nicht gewechselt werden
//(QuickSort) Partition Funktion erstellen: Mario Forrer
struPerson* Partition(struPerson* pStart, struPerson* pLow, struPerson* pHigh) {
	struPerson* pPivot = pHigh;
	struPerson* pI = pLow;
	short int state = 0; // 0 = Not done 1 = Checked 
//	if (pI->pPrev != NULL) pI = pI->pPrev;




	for (struPerson* pWork = pLow; pWork != pHigh; pWork = pWork->pNext) {
		state = 0;
		for (int j = 0; pWork->pData->Nachname[j] != '\0' && pPivot->pData->Nachname[j] != '\0'; j++) {
//			printf("\n----\nQuickSort: Nachname Loop, start");
			if (state == 0) {
//				printf("\n----\nQuickSort: Nachname Loop, inside state");
				if (pWork->pData->Nachname[j] == pPivot->pData->Nachname[j]);
				else if (pWork->pData->Nachname[j] < pPivot->pData->Nachname[j]) {
	//				printf("\n----\nQuickSort: Nachname Loop, Work smaller as Pivot");
					if (pI->pPrev != NULL) pI = pI->pPrev;
					struData* pTemp = pI->pData;
					pI->pData = pWork->pData;
					pWork->pData = pTemp;
					state = 1;
				}
				else if (pWork->pData->Nachname[j] > pPivot->pData->Nachname[j]) {
					state = 1;
//					printf("\n----\nQuickSort: Nachname Loop, Work bigger as Pivot");
				}
					
			}
		}

		if (state == 0) {
			for (int j = 0; pWork->pData->Vorname[j] != '\0' && pPivot->pData->Vorname[j] != '\0'; j++) {
//				printf("\n----\nQuickSort: Vorname Loop, start");
				if (state == 0) {
//					printf("\n----\nQuickSort: Vorname Loop, inside State");
					if (pWork->pData->Vorname[j] == pPivot->pData->Vorname[j]);
					else if (pWork->pData->Vorname[j] < pPivot->pData->Vorname[j]) {
//						printf("\n----\nQuickSort: Vorname Loop, Work smaller as Pivot");
						if (pI->pPrev != NULL) pI = pI->pPrev;
						struData* pTemp = pI->pData;
						pI->pData = pWork->pData;
						pWork->pData = pTemp;
						state = 1;
					}
					else if (pWork->pData->Vorname[j] > pPivot->pData->Vorname[j]) {
//						printf("\n----\nQuickSort: Nachname Loop, Work bigger as Pivot");
						state = 1;
					}
						
				}
			}
		}
	}

	struData* pTemp = pI->pData;
	pI->pData = pPivot->pData;
	pPivot->pData = pTemp;

	return pI;
}

//(QuickSort) QuickSort Funktion erstellen: Mario Forrer
void QuickSort(struPerson* pStart, struPerson* pLow, struPerson* pHigh) {
	if (pLow < pHigh) {
		printf("\n----\nQuickSort: wholeState if clause, calling Partition");
		struPerson* pivot = Partition(pStart, pLow, pHigh);

		QuickSort(pStart, pLow, pivot->pPrev);
		QuickSort(pStart, pivot->pNext, pHigh);
	}
}

//(QuickSort) QuickSortPrep Funktion erstellen: Mario Forrer WORKS
struPerson* QuickSortPrep(struPerson* pStart) {
	//	int max = countElements(pStart) - 1;
	struPerson* pLast = pStart;
	struPerson* pTemp = pStart;
	while (pTemp != NULL) {
		pLast = pTemp;
		pTemp = pTemp->pNext;
	};

	QuickSort(pStart, pStart, pLast);

	return pStart;
}

// Main-Funktion erstellen: Mario Forrer und Adrian Cerdeira
int main() {
	struPerson* pStart = Create(15);
	char input;

	while (true) {
		// TODO: Restliche verlangte Funktionen einbauen
		printf("Was m%cchten Sie tun?: Sortieren(s), Liste l%cschen(d), Liste leeren(d), Elemente l%cschen (e), Ausgeben(a), \n", oe, oe, oe);
		scanf("%c", &input);
		switch (input)
		{
		case 's':
			QuickSortPrep(pStart);
			break;
		case 'd':
			// Delete Funktion
			break;
		case 'a':
			Output(pStart);
			break;
		case 'l':
			// Listenauswahl
			break;
		case 'e':
			//Delete Funktion (Einzelne Elemente)
			break;
		case 'r':
			system("@cls||clear");
			break;
		default:
			printf("Die Eingabe ist Ung%cltig\n", ue);
			break;
		}
		// Um Buffer zu leeren
		fseek(stdin, 0, SEEK_END);
	}

}

//Bubblesort Funktion erstellen: Adrian Cerdeira
struPerson* BubbleSort(struPerson* pStart) {
	return 0;
}

// Counter-Funktion erstellen: Adrian Cerdeira
int countElements(struPerson* pStart) {
	int counter = 0;
	struPerson* pTemp = pStart;

	while (pTemp->pNext != NULL) {
		counter++;
	};
	return counter;
}
