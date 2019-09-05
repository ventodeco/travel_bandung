#ifndef TRAVEL_H_INCLUDED
#define TRAVEL_H_INCLUDED

#include <iostream>
using namespace std;
#include <conio.h>
#define prev(P) P->prev
#define down(P) P->down
#define next(P) P->next
#define info(P) P->info
#define first(L) L.first
#define last(L) L.last


struct infotype {
	int jam_keberangkatan, jumlah_kursi, id;
	long harga_tiket;
    string nama_travel, tujuan;
};

typedef struct elmlist *address;
typedef struct elmlist_pen *address_pen;

struct elmlist{
    infotype info;
    address next;
    address prev;
    address_pen down;
};


struct List {
    address first;
    address last;
};


address alokasi(infotype x);
void dealokasi(address P);
address findElm(List L, infotype x);
void printInfo(List L);
infotype insertInfo();

void createList(List &L);

void insertLast(List &L, address P);

void delData(List &L, address &P);

void editList(List &L, address P);

#endif // TRAVEL_H_INCLUDED
