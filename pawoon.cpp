//penggunaan library dan namespace
#include <iostream>
using namespace std;

/***
	Langkah Penggunaan Aplikasi PaWooN:
	1. Default akan memulai perhitungan kasir dengan melampirkan banyak barang dan harga barang.
	2. Program juga menyertakan konfirmasi diskon dan pajak
	3. Setelah seluruh operasi berhasil, program akan membutuhkan data pembayaran transaksi pelanggan.
	4. Program dapat dijalankan ulang melalui tahapan konfirmasi tanpa memuat ulang program.
	
	Note:
	-Program bersifat dinamis.
	-Program sudah dilengkapi dengan fungsi, percabangan, dan pengulangan.
***/

//fungsi void untuk perkenalan nama dan anggota kelompok
void perkenalan() {
    cout<<"\n\n";
    cout<<"         Perkenalkan Anggota Kelompok PMnM:\n\n"; 
    cout<<"Nama       : Rashid\n";
    cout<<"NIM        : 23.66.2066\n\n";
    cout<<"Nama       : Ainun Mardiah\n";
    cout<<"NIM        : 23.66.2005\n\n";
    cout<<"Nama       : Rita Theresia Sitohang\n";
    cout<<"NIM        : 23.66.2072\n\n";
}

//fungsi mengembalikan total belanja
int hitungTotal(int arrayBarang[],int banyakProduk) {
	int totalBelanja = 0;
	for (int j = 1; j <= banyakProduk; j++) {
		totalBelanja += arrayBarang[j];
	}
	return totalBelanja;
}

//fungsi mengembalikan operasi diskon
int hitungDiskon(int hargaKotor, int persenDiskon) {
	return hargaKotor * persenDiskon/100;
}

//fungsi void untuk program memulai kasir
void mulaiKasir() {
	//deklarasi variabel
	int banyakBarang, nilaiDiskon, totalBarang, totalBelanja, besarPajak, uangKonsumen;
	char konfirmasi, pajakBarang;
	
	cout<<"\nMasukkan banyak barang yang dibeli : ";
	cin>>banyakBarang;
	cout<<endl;
	int listBarang[banyakBarang];
	
	//penggunaan pengulangan tipe for
	for (int i = 1; i <= banyakBarang; i++) {
		cout<<"Masukkan harga barang Ke-"<<i<<" : Rp.";
		cin>>listBarang[i];
	}
	
	totalBarang = hitungTotal(listBarang, banyakBarang);
	
	cout<<"\nTotal Belanja sebelum diskon dan pajak : Rp."<<totalBarang<<endl;
	
	cout<<"\nApakah mendapatkan diskon? (y/t) : ";
	cin>>konfirmasi;
	//penggunaan percabangan switch-case
	switch (konfirmasi) {
	    case 'y':
	        int banyakDiskon;
	        cout << "Masukkan persentase diskon yang diterima (%) : ";
	        cin >> banyakDiskon;
            nilaiDiskon = hitungDiskon(totalBarang, banyakDiskon);
            break;
		case 't':
	        nilaiDiskon = hitungDiskon(totalBarang, 0);
	        break;
	}
	
	cout<<"\nApakah dikenakan PPN 11%? (y/t): ";cin>>pajakBarang;
	//pencabangan boolean secara direct
	besarPajak = (pajakBarang == 'y') ? totalBarang * 11/100 : 0;
	
	totalBelanja = totalBarang - nilaiDiskon + besarPajak;
	cout<<"\n\nTotal belanja keseluruhan adalah : Rp."<<totalBelanja<<endl;
	
	//fungsi pengulangan dengan do-while
	do {
		cout<<"\nMasukkan jumlah uang yang dibayarkan : Rp.";
		cin>>uangKonsumen;
		if (uangKonsumen > totalBelanja) {
			cout<<"Menerima kembalian uang senilai Rp."<<uangKonsumen-totalBelanja<<endl;
		} else if (uangKonsumen == totalBelanja) {
			cout<<"Jumlah uang yang dibayarkan pas"<<endl;
		} else {
			cout<<"Jumlah uang yang dibayarkan kurang"<<endl;
		}
	} while (uangKonsumen < totalBelanja);
}

//fungsi utama (main)
int main() {
	perkenalan();
	char mulai = 'y';
	cout<<"\n\nSelamat datang di aplikasi kasir PaWooN\n"<<endl;
	while (mulai == 'y') {
		mulaiKasir();
		cout << "\nApakah ingin melakukan transaksi lagi? (y/t): ";
		cin >> mulai;
	}
	cout<<"\n\nTerima Kasih telah menggunakan aplikasi PaWooN"; //output akhir
	return 0;
}
