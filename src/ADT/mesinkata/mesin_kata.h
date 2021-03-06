/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "../../console.h"

#define NMax 100 //bisa 299 ga karena butuh untuk kasus 100 petak dan 98 portal dll
#define NEWLINE '\n'
#define BLANK ' '

typedef struct {
   char TabKata[NMax+1]; /* container penyimpan kata, indeks yang dipakai [1..NMax] */
   int Length;
} Kata;

/* State Mesin Kata */
extern boolean EndKata;
extern Kata CKata;

void IgnoreBlank();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */

void SalinKata(Map *CurrentMap);
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
          
void STARTKATA(Map *CurrentMap);
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = MARK;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */

void ADVKATA(Map *CurrentMap);
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.
   Proses : Akuisisi kata menggunakan procedure SalinKata */



void STARTKATA2(char *namafile);
/* Implementasi STARTKATA untuk membaca file save.
   I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = MARK;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */

void IgnoreBlank2();
/* Mengabaikan satu atau beberapa BLANK. Implementasi ADVKATA untuk membaca file save.
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */

void ADVKATA2();
/* Implementasi ADVKATA untuk membaca file save.
   I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.
   Proses : Akuisisi kata menggunakan procedure SalinKata*/

void SalinKata2();
/* Mengakuisisi kata, menyimpan dalam CKata. Implementasi STARTKATA untuk membaca file save.
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" 
          Digunakan untuk prosedur load*/

int KataToInt (Kata K);
/* Mengubah Kata yang berisi tipe integer tapi dalam format teks(kata) menjadi integer */

#endif
