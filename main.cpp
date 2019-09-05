#include "travel.h"
#include "penumpang.h"

int main() {
	List travel;
	createList(travel);
	infotype x;
	int id;
	infotype_pen y;
	address P;
	address_pen Q;
	char pilih;
	
	x.nama_travel = "BARAYA TRAVEL";
	x.id = 15;
	x.jumlah_kursi = 15;
	x.jam_keberangkatan = 9;
	x.tujuan = "BINTARO";
	x.harga_tiket = 80000;
	
	P = alokasi(x);
	insertLast(travel, P);
	
	x.nama_travel = "INDO TRAVEL";
	x.id = 10;
	x.jumlah_kursi = 18;
	x.jam_keberangkatan = 12;
	x.tujuan = "JAKARTA";
	x.harga_tiket = 90000;
	
	P = alokasi(x);
	insertLast(travel, P);
	
	x.nama_travel = "TANGSEL TRAVEL";
	x.id = 12;
	x.jumlah_kursi = 16;
	x.jam_keberangkatan = 15;
	x.tujuan = "TANGERANG";
	x.harga_tiket = 100000;
	
	P = alokasi(x);
	insertLast(travel, P);
	
	do{
		system("cls");	
		cout << "              TRAVEL BANDUNG        " << endl;
		cout << endl;
		cout << "1. Masukkan Data Travel Baru " << endl;
		cout << "2. Lihat Data Info Travel    " << endl;
		cout << "3. Pemesanan Tiket           " << endl;
		cout << "4. Lihat Daftar Penumpang    " << endl;
		cout << "5. Data Statistik Travel Menurut Tanggal    " << endl;
		cout << "6. Data Statistik Keseluruhan" << endl;
		cout << "7. Hapus Data Travel " << endl;
		cout << "8. Keluar           " << endl;
		cout << "\nPilih Menu : ";
		cin >> pilih;
		switch(pilih){
			case '1' :
				x = insertInfo();
				P = alokasi(x);
				insertLast(travel, P);
				cout << "Data Berhasil Dimasukkan! " << endl;
				getch();
				break;
			case '2' :
				printInfo(travel);
				getch();
				break;
			case '3' :
				printInfo(travel);
				cout << "Pesan Tiket Travel dengan ID : ";
				cin >> id;
				x.id = id;
				P = findElm(travel, x);
				if(P == NULL){
					cout << "Data Tidak Ada" << endl;
					getch();
					break;
				} else{
					y = InsertInfo();
					Q = alokasi_pen(y);
					InsertFirst(P, Q);
					char a;
					cout << "Print Tiket? Y/N" << endl;
					cin >> a;
					if(a == 'Y'){
						cout << "          Tiket Travel " << endl;
						cout <<"\nNama Penumpang           : " <<y.nama_penumpang <<endl;
					    cout <<"No Kursi                 : " <<y.no_kursi <<endl;
					    cout <<"Jam Keberangkatan        : " <<info(P).jam_keberangkatan<<".00 WIB" <<endl;
					    cout <<"Tujuan                   : " <<info(P).tujuan <<endl;
					    cout <<"Tanggal Keberangkatan    : " <<y.berangkat.tgl <<" - " <<y.berangkat.bln <<" - " <<y.berangkat.thn <<endl;
						cout <<"Harga Tiket              : " <<info(P).harga_tiket << endl;
					}														
				}
				getch();
				break;
			case '4' :
				cout << "ID Travel : ";
				cin >> id;
				x.id = id;
				P = findElm(travel, x);
				if(P == NULL){
					cout << "Data Tidak Ada" << endl;
					getch();
					break;
				} else{
					printInfo(P);
				}
				getch();
				break;
			case '5' :
				int tgl, bln, thn;
				cout << "Cari Tanggal : ";
				cin >> tgl;
				cout << "     Bulan   : ";
				cin >> bln;
				cout << "     Tahun   : ";
				cin >> thn;
				y.berangkat.tgl = tgl;
				y.berangkat.bln = bln;
				y.berangkat.thn = thn;
				findElm_ttl(travel, y);
				getch();
				break;
			case '6' :
				StatistikSemuaTravel(travel);
				getch();
				break;
			case '7' :
				cout << "ID Travel : ";
				cin >> id;
				x.id = id;
				P = findElm(travel, x);
				if(P == NULL){
					cout << "Data Tidak Ada" << endl;
					getch();
					break;
				} else{
					delData(travel, P);
					cout << "Data Travel Berhasil Dihapus " << endl;
				}
				getch();
		}
	} while(pilih != '8');
	
}
