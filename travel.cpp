#include "travel.h"

address alokasi(infotype x){
    address P;
    P = new elmlist;
    info(P) = x;
    next(P) = NULL;
    prev(P) = NULL;
    down(P) = NULL;
    return P;
}

void dealokasi(address P){
    delete P;
}

address findElm(List L, infotype x){
    address p;
    bool cek;
    cek = false;
    if (first(L) != NULL){
        p = first(L);
        while ((cek==false) && (p != NULL)){
            if (info(p).id == x.id){
                cek = true;
            }
            else {
                p = next(p);
            }
        }
    }
    if (cek==true) {
        return p;
    }
    else{
        return NULL;
    }
}

void printInfo(List L){
	if(first(L) == NULL){
        cout <<"Data Travel Kosong" <<endl;
    }
    else{
        address P = first(L);
        cout <<"               DATA TRAVEL        " << endl;
        while(P != NULL){
		cout <<"\nNama Travel              : " <<info(P).nama_travel <<endl;
		cout <<"ID Travel                : " <<info(P).id << endl;
	    cout <<"Jumlah Kursi             : " <<info(P).jumlah_kursi <<endl;
	    cout <<"Jam Keberangkatan        : " <<info(P).jam_keberangkatan <<".00 WIB"<<endl;
	    cout <<"Tujuan                   : " <<info(P).tujuan <<endl;
	    cout <<"Harga Tiket              : " << info(P).harga_tiket << endl;
	    cout <<endl;
        P = next(P);
        }
    }
}

infotype insertInfo(){
    infotype x;
    cout <<"\nMasukkan Nama Travel            : ";
    cin >>x.nama_travel;
    cout <<"Masukkan ID Travel              : ";
    cin >> x.id;
    cout <<"Masukkan Jumlah Kursi           : ";
    cin >> x.jumlah_kursi;
    cout <<"Masukkan Tujuan Travel          : ";
	cin >> x.tujuan;
    cout <<"Masukkan Jam Keberangkatan      : ";
    cin >> x.jam_keberangkatan;
    cout <<"Masukkan Harga Tiket            : ";
    cin >> x.harga_tiket;

    return x;
}

void createList(List &L){
    if (first(L) != NULL){
        first(L) = NULL;
        last(L)= NULL;
    }
}

void delData(List &L, address &P){
     if(first(L)!=NULL){
     	down(P) = NULL;
        if (first(L)==last(L)){
            P = first(L);
            first(L) = NULL;
            last(L) = NULL;
        }
        else if (last(L)==P){
            P = last(L);
            last(L) = prev(last(L));
            next(last(L)) = NULL;
            prev(P) = NULL;
        }
        else if (first(L)==P){
            P = first(L);
            first(L) = next(P);
            prev(first(L)) = NULL;
            next(P) = NULL;
        }
        else{
            next(prev(P)) = next(P);
            prev(next(P)) = prev(P);
            next(P) = NULL;
            prev(P) = NULL;
        }
        dealokasi(P);
    }
}

void insertLast(List &L, address P){
    if (first(L)==NULL){
        first(L)=P;
        last(L)=P;
    }
    else {
        next(last(L))=P;
        prev(P)=last(L);
        last(L)=P;
    }
}

void editList(List &L, address P){
    infotype x;
    char pilih;

    cout <<"\nData yang ingin diubah : "<<endl;
    cout <<"1. Nama Travel             " <<endl;
    cout <<"2. Jam Keberangkatan       " <<endl;
    cout <<"3. Jumlah Kursi            " <<endl;
    cout <<"4. Tujuan                  " <<endl;
    cout <<"5. ID                      " << endl;
    cout <<"6. Harga Tiket             " << endl;
    cin>>pilih;
    switch (pilih) {
    case '1' :
            cout <<"Masukkan Nama Travel Baru       : ";
            cin >>info(P).nama_travel;

        break;
    case '2' :
            cout <<"Masukkan Jam Keberangkatan Baru : ";
            cin >>info(P).jam_keberangkatan;

        break;
    case '3' :
        cout <<"Masukkan Jumlah Kursi Baru          : ";
            cin >>info(P).jumlah_kursi;

        break;
    case '4' :
        cout <<"Masukkan Tujuan Baru : ";
            cin >>info(P).tujuan;

        break;
    case '5' :
        cout <<"Masukkan ID Baru : ";
            cin >>info(P).id;

        break;
	case '6' :
        cout << "Masukkan Tiket Harga Baru : ";
        	cin >> info(P).harga_tiket;

        break;
        };

}
