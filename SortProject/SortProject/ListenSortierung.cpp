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

		pCurrent->pData->Vorname[0] = 'A' + (rand() % 26);
		pCurrent->pData->Vorname[1] = '\0';
		pCurrent->pData->Nachname[0] = 'A' + (rand() % 26);
		pCurrent->pData->Nachname[1] = '\0';
		pCurrent->pData->Jahrgang = 1900 + rand() % 118;

		if (pPrevious == NULL) {
			pStart = pCurrent;
		}
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

//searchElement Funktion erstellen: Adrian Cerdeira
struPerson* searchElement(struPerson *pStart, char lastName[], char firstName[]) {
	struPerson* pSearch = NULL;
	while (pStart != NULL) {
		bool isFirstNameAndLastName = pStart->pData->Nachname[0] == lastName[0] && pStart->pData->Vorname[0] == firstName[0];
		if (isFirstNameAndLastName) {
			return pSearch = pStart;
		}
		pStart = pStart->pNext;
	}
}

//deleteElement Funktion erstellen: Adrian Cerdeira
struPerson* deleteElement(struPerson *pStart, struPerson *pSearchElement) {
	struPerson* pCurrent = pStart;
	struPerson* pNewList = NULL;

	// TODO: Delete Element correctly and return new List
	while (pCurrent != NULL) {
		struPerson* pDel = pCurrent;
		if (pDel == pSearchElement) {
			pCurrent->pPrev = pDel->pNext;
			free(pSearchElement);
		}
		pDel = pDel->pNext;
	}

	return pNewList;
}

// Counter-Funktion erstellen: Adrian Cerdeira
int countElements(struPerson* pStart) {
	int counter = 0;
	struPerson* pTemp = pStart;

	while (pTemp != NULL) {
		counter++;
		pTemp = pTemp->pNext;
	};

	return counter;
}

// putDataToConsole Funktion erstellen: Adrian Cerdeira
void putDataToConsole(struPerson* pOut, int elementNumber) {
	struPerson *pCurrent = pOut;
	//TODO: Aktuelles Jahr abfragen
	int alter = 2018 - pCurrent->pData->Jahrgang;

	printf("\n ---- \nElement:%i\n", elementNumber);
	printf("Name: %c\n", pCurrent->pData->Nachname[0]);
	printf("Vorname: %c\n", pCurrent->pData->Vorname[0]);
	printf("Geburtstag: %i\n", pCurrent->pData->Jahrgang);
	printf("Alter: %i\n", alter);
}

//Output Funktion erstellen: Mario Forrer
void Output(struPerson* pStart, int amountElements) {
	if (pStart != NULL) {
		if (amountElements != 0) {
			int existingElements = countElements(pStart);
			if (amountElements < existingElements) {
				int i = 1;
				for (struPerson* pOut = pStart; i <= amountElements; pOut = pOut->pNext) {
					putDataToConsole(pOut, i);
					i++;
				}
			}
			else {
				printf("Es k%cnnen maximal %i Elemente ausgegeben werden\n", oe, existingElements);
			}
		}
		else {
			int i = 1;
			for (struPerson* pOut = pStart; pOut != NULL; pOut = pOut->pNext) {
				putDataToConsole(pOut, i);
				i++;
			}
		}
	}
	else {
		printf("Keine Elemente vorhanden");
	}

}

//Bubblesort Funktion erstellen: Adrian Cerdeira
struPerson* BubbleSort(struPerson* pStart) {
	//TODO: Warum werden Werte nicht passend sortiert

	for (pStart; pStart != NULL; pStart = pStart->pNext) 
	{
		if (pStart->pData->Nachname[0] > pStart->pPrev->pData->Nachname[0])
		{
			pStart->pData->Nachname[0] = pStart->pPrev->pData->Nachname[0];
			pStart->pPrev->pData->Nachname[0] = pStart->pData->Nachname[0];
		}
	}

	printf("Liste wurde per Bubblesort sortiert\n");
	return pStart;
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

// createList-Funktion erstellen: Adrian Cerdeira
struPerson* createList(struPerson *pStart) {
	int amount = 0;

	printf("Wie viele Elemente m%cchten Sie erstellen?\n", oe);
	scanf("%i", &amount);
	pStart = Create(amount);
	printf("Liste wurde erstellt\n", oe);

	// Um Buffer zu leeren
	fseek(stdin, 0, SEEK_END);

	return pStart;
}

// Main-Funktion erstellen: Mario Forrer und Adrian Cerdeira
int main() {
	struPerson* pStart = NULL;
	struPerson *pSearchElement = NULL;

	char input;
	int  inputAmoutElements = 0;
	char inputSort;
	char inputFirstName[40];
	char inputLastName[40];
;
	while (true) {
		if (pStart != NULL) {
			// TODO: Restliche verlangte Funktionen einbauen
			printf("Was m%cchten Sie tun?: Liste sortieren(s), Liste l%cschen(d), Element l%cschen (e), Ausgeben(a), Programm beenden(x)\n, Console leeren(r)\n", oe, oe, oe);
			scanf("%c", &input);
			switch (input)
			{
			case 's':
				// TODO: Abfrage welche Sortierungsart
				printf("M%cchten Sie per Quicksort sortieren(J/N):\n", oe);
				scanf("%s", &inputSort); 
				inputSort == 'J' ? pStart = QuickSortPrep(pStart) : pStart = BubbleSort(pStart);
				break;
			case 'd':
				pStart = NULL;
				printf("Liste gel%cscht\n", oe);
				break;
			case 'a':
				printf("Wie viele Elemente m%cchten Sie ausgeben? (0 = Alle)\n", oe);
				scanf("%i", &inputAmoutElements);
				Output(pStart, inputAmoutElements);
				break;
			case 'l':
				// Listenauswahl
				break;
			case 'e':
				// TODO: With get_s falls möglich
				printf("Name:\n");
				scanf("%s", &inputLastName[0]);

				printf("Vorname:\n");
				scanf("%s", &inputFirstName[0]);

				pSearchElement = searchElement(pStart, inputLastName, inputFirstName);
				if (pSearchElement != NULL) {
					pStart = deleteElement(pStart, pSearchElement);
					printf("Element/Elemente wurde/n gel%cscht\n", oe);
				}
				else {
					printf("Element wurde nicht gefunden oder konnte nicht gel%cscht werden\n", oe);
				}

				break;
			case 'r':
				system("@cls||clear");
				break;
			case 'x':
				return 0;
				break;
			default:
				printf("Die Eingabe ist Ung%cltig\n", ue);
				break;
			}
			// Um Buffer zu leeren
			fseek(stdin, 0, SEEK_END);
		}
		else {
			pStart = createList(pStart);
		}
	}
}