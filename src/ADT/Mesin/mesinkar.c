/* File: mesinkarakter.c */
/* Implementasi Mesin Karakter : Model Modifikasi Input File Eksternal */
#include "mesinkar.h"

/* State Mesin */
char currentChar;
boolean EOP;

/* State File Eksternal */
static FILE *pita;
static int retval;

void STARTFILE(char *filename)
{
   pita = fopen(filename, "r");

   if (pita != Nil)
   {
      ADVFILE();
   }
   else
   {
      printf("File konfigurasi tidak ditemukan\n");
      EOP = true;
   }
}
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   Pita baca diambil dari File Eksternal.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */
void ADVFILE()
{

   retval = fscanf(pita, "%c", &currentChar);
   EOP = (retval < 0);
   if (EOP)
   {
      fclose(pita);
   }
}
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
          currentChar mungkin = MARK
          Jika  currentChar = MARK maka EOP akan menyala (true) */

char GetCC()
{
   return currentChar;
}
/* Mengirimkan currentChar */

boolean IsEOP()
{
   return EOP;
}
/* Mengirimkan true jika currentChar = MARK */