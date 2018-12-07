#include "stdio.h";
#include "stdlib.h";

// Struktur Person erstellen: Adrian Cerdeira
typedef struct Person {
	char Vorname[40];
	char Nachname[40];
	int Jahrgang;
	struct Person* pNext;
	struct Person* pPrev;
} struPerson;

int main() {

}