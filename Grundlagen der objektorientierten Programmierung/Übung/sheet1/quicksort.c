/****************************************/
/* Thien Ngo  */
/* Matrikel: 1857010 */
/* Uebungsblatt: 01, Aufgabe: 1 */
/* Datum: 23.10.2018 */
/* Status: lauffaehig */
/****************************************/

#include <stdio.h>
#include <stdlib.h>

/*
 * Hier die Funktionen quicksort, teile und swap einfuegen
 */
void quicksort (int *daten, int links, int rechts);
int teile (int *daten, int links, int rechts);
void swap (int *daten1, int* daten2);

int main()
{
  int i, anz;
  int* feld;

  printf("Anzahl der Elemente: ");
  scanf("%d", &anz);
  feld = (int*) calloc(anz, sizeof(int));
  if (feld == NULL)
    return 1;

  printf("Zahlen eingeben: ");
  for (i = 0; i < anz; ++i)
    scanf("%d", &feld[i]);

  printf("Das eingegebene Feld: ");
  for(i = 0; i < anz; ++i)
    printf("%d  ", feld[i]);
  printf("\n\n");

  quicksort(feld, 0, anz-1);
  printf("Das sortierte Feld: ");
  for (i = 0; i < anz; ++i)
    printf("%d  ", feld[i]);
  printf("\n\n");

  free(feld);

  return 0;
}

void quicksort (int *daten, int links, int rechts) {
  if (links < rechts) {
    int teiler = teile(daten, links, rechts);
    quicksort(daten, links, teiler-1);
    quicksort(daten, teiler+1, rechts);
  }
}

int teile (int *daten, int links, int rechts) {
  int i = links;
  int j = rechts-1;
  int pivot = daten[rechts];

  do
  {   
    while (daten[i] <= pivot && i < rechts) {
      i++;
    }
    
    while (daten[j] >= pivot && j > links) {
      j--;
    }
    
    if (i < j) {
      swap(&daten[i], &daten[j]);
    }
  } while(i < j);
  
  if (daten[i] > pivot) {
    swap(&daten[i], &daten[rechts]);
  }
  
  return i;
}

void swap (int *daten1, int* daten2) {
  int i = 0;

  i = *daten1;
  *daten1 = *daten2;
  *daten2 = i;
}

