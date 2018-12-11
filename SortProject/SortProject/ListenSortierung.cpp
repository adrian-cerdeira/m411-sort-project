#include "stdio.h";
#include "stdlib.h";
#include "time.h";

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

//	TODO: String-Dreck reparieren (hate it) 
	char ansc;
// TODO: Restliche verlangte Funktionen einbauen.
	printf("Was möchten Sie tun?: Sortieren(s), Liste löschen(d), Elemente löschen (e), Ausgeben(a), \n");
	scanf("%c", ansc);
	switch (ansc)
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
//		TODO: Speichern von Namen und vornamen.
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




}

//*Sort Funktion erstellen: Mario Forrer
