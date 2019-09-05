#ifndef PENUMPANG_H_INCLUDED
#define PENUMPANG_H_INCLUDED

#include <iostream>
using namespace std;
#include "travel.h"

#define next(P) P->next
#define info(P) P->info
#define first(L) L.first
#define last(L) L.last

struct ttl{
	int tgl, bln, thn;
};

struct infotype_pen {
	int no_kursi;
    string nama_penumpang, no_telp;
    ttl berangkat;
};

typedef struct elmlist *address;
typedef struct elmlist_pen *address_pen;

struct elmlist_pen{
    address_pen next;
    infotype_pen info;
};


address_pen alokasi_pen(infotype_pen x);
void dealokasi_pen(address_pen P);
void printInfo(address P);
void InsertFirst(address P, address_pen Q);
void findElm_ttl(List L, infotype_pen y);

void StatistikTravel(address P);
void StatistikSemuaTravel(List L);
infotype_pen InsertInfo();

#endif // PENUMPANG_H_INCLUDED
