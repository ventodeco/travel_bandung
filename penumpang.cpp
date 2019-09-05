#include "penumpang.h"
#include "travel.h"

address_pen alokasi_pen(infotype_pen x){
	address_pen P = new elmlist_pen;
    info(P).nama_penumpang = x.nama_penumpang;
    info(P).no_kursi = x.no_kursi;
    info(P).no_telp = x.no_telp;
    info(P).berangkat.tgl = x.berangkat.tgl;
    info(P).berangkat.bln = x.berangkat.bln;
    info(P).berangkat.thn = x.berangkat.thn;
    next(P) = NULL;
    
    return P;
}

void dealokasi_pen(address_pen P){
	delete P;
}

infotype_pen InsertInfo(){
    infotype_pen x;
    cout <<"\nMasukkan Nama Penumpang           : ";
    cin >> x.nama_penumpang;
    cout <<"Masukkan Nomor Kursi              : ";
    cin >> x.no_kursi;
    cout <<"Masukkan No Telepon (62)          : ";
    cin >> x.no_telp;
    cout <<"Masukkan Tanggal Keberangkatan    : ";
    cin >>x.berangkat.tgl;
    cout <<"Masukkan Bulan Keberangkatan      : ";
    cin >>x.berangkat.bln;
    cout <<"Masukkan Tahun Keberangkatan      : ";
    cin >>x.berangkat.thn;

    return x;
}

void printInfo(address P){
	if(P == NULL){
        cout <<"Data Penumpang Kosong" <<endl;
    }
    else{
        address_pen Q = down(P);
        cout <<"               DATA PENUMPANG DI " << info(P).nama_travel << endl;
        while(Q != NULL){
		cout <<"\nNama Penumpang           : " <<info(Q).nama_penumpang <<endl;
	    cout <<"No Kursi                 : " <<info(Q).no_kursi <<endl;
	    cout <<"Jam Keberangkatan        : " <<info(P).jam_keberangkatan<<".00 WIB"<<endl;
	    cout <<"Tujuan                   : " <<info(P).tujuan <<endl;
	    cout <<"Tanggal Keberangkatan    : " <<info(Q).berangkat.tgl <<" - " <<info(Q).berangkat.bln <<" - " <<info(Q).berangkat.thn <<endl;
		cout <<endl;
        Q = next(Q);
        }
    }
}

void findElm_ttl(List L, infotype_pen y){
	address_pen Q;
	long total = 0;
	long hitung;
	address P = first(L);
	while(P != NULL){
		cout << endl;
		Q = down(P);
		hitung = 0;
		cout << "Data Penumpang Di " << info(P).nama_travel << endl;
		while(Q != NULL){
			if(info(Q).berangkat.tgl == y.berangkat.tgl && info(Q).berangkat.bln == y.berangkat.bln && info(Q).berangkat.thn == y.berangkat.thn){
				cout << "Nama Penumpang : " << info(Q).nama_penumpang << endl;
				cout << "No. Kursi      : " << info(Q).no_kursi << endl;
				total = total + info(P).harga_tiket;
				hitung = hitung + info(P).harga_tiket;
			}
			Q = next(Q);
			cout << endl;
			cout << endl;
		}
		cout << "Pendapatan dari " << info(P).nama_travel << " : " << hitung << endl;
		P = next(P);
	}
	cout << endl;
	cout << endl;
	cout << "Jumlah Pendapatan Travel : " << total << endl;
	
}

void InsertFirst(address P, address_pen Q){
	if(down(P) == NULL){
		down(P) = Q;
	} else{
		next(Q) = down(P);
		down(P) = Q;
	}
}

void StatistikTravel(address P){
	address_pen A = down(P);
	int hitung = 0;
	long jumlah = 0;
	while(A != NULL){
		A = next(A);
		jumlah = jumlah + info(P).harga_tiket;
		hitung++;
	}
	
	
	cout << "DATA STATISTIK TRAVEL " << info(P).nama_travel << endl;
	cout << endl;
	cout << "1. Jumlah Penumpang         : " << hitung << " orang "<< endl;
	cout << "2. Jumlah Uang yang Didapat : " << jumlah << " rupiah" << endl;
}

void StatistikSemuaTravel(List L){
	address P = first(L);
	int hitung = 0;
	long jumlah = 0;
	while(P != NULL){
		address_pen Q = down(P);
		while(Q != NULL){
			jumlah = jumlah + info(P).harga_tiket;
			hitung++;
			Q = next(Q);
		}
		P = next(P);
	}
	cout << "DATA STATISTIK SEMUA TRAVEL " << endl;
	cout << endl;
	cout << "1. Jumlah Penumpang         : " << hitung << " orang" << endl;
	cout << "2. Jumlah Uang yang Didapat : " << jumlah << " rupiah" << endl;
}
