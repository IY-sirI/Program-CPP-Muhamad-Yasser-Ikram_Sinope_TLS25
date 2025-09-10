#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;

//deklarasi vektor
vector<char> vokal;
vector<string> list;

//Fungsi Kombinasi sisipan vokal
void Tulis(const string &kode, string simpan, int i){
	if(i == (int)(-2) ){
		list.push_back(simpan);
		return;
	}
	
	if(i >= 0) simpan.push_back(kode[i]);
	
	if(i == (int)(-1) ){
		Tulis(kode, simpan, i-1);
	}
	else{
		Tulis(kode, simpan, i-1);
		
		for(size_t a=0; a<vokal.size(); a++){
			Tulis(kode, simpan+vokal[a], i-1);
		}
	}
}

//Fungsi membalikkan urutan
string pembalik(const string &kata, string simpan){
	for(int i = kata.size()-1; i>=0; i--){
	    simpan.push_back(kata[i]);
	}
	return simpan;
}

//Fungsi menambahkan ASCII ditengah
string ASCII(const string &kata, string simpan, string angka){
	char akhir = kata[kata.size()-1];
	int nilai = (int)akhir;
	
	char digit;
	while(nilai != 0){
		digit = '0';
		digit += nilai % 10 ;
		angka.push_back(digit);
		nilai /= 10;
	}
	
	angka = pembalik(angka, "");
	
	int middle;
	if(kata.size() % 2 == 0) middle = kata.size()/2;
	else middle = kata.size()/2+1;
	
    for(int i=0; i<kata.size(); i++){
    	simpan.push_back(kata[i]);
	}
	simpan.insert(middle, angka);
	return simpan;
	
}

int main(){
	
	string kata;
	char pilihan;
	
LOOP:
    system("cls");
	cout << "(1) Create Code\n(2) Translate Code\nChoose Option : ";
	cin >> pilihan;
	
	if(pilihan == '1'){
		
	cout << "\nMasukkan kata sandi : ";
	cin >> kata;
	
	int m = kata.size();
	for(int i=0; i<m; i++){
		if(kata[i] == 'A' || kata[i] == 'I' || kata[i] == 'U' || kata[i] == 'E' || kata[i] == 'O'){
			kata.erase(i, 1);
			i--;
		}
		else if(kata[i] == 'a' || kata[i] == 'i' || kata[i] == 'u' || kata[i] == 'e' || kata[i] == 'o'){
			kata.erase(i, 1);
			i--;
		}
	}
	m = kata.size();
	
	kata = pembalik(kata, "");
	kata = ASCII(kata, "", "");
	
	cout << "Hasil : " << kata;
	}
	
	else if(pilihan == '2'){
		
    //deklarasi
	string kode;
	cout << "\nMasukkan Kode : ";
	
	//input
	cin >> kode;
	
	//buang angka
	int n = kode.size();
	
	for(int i=0; i<n; i++){
		if(kode[i] == '0' || kode[i] == '1' || kode[i] == '2' || kode[i] == '3' || kode[i] == '4'){
			kode.erase(i, 1);
			i--;
		}
		if(kode[i] == '5' || kode[i] == '6' || kode[i] == '7' || kode[i] == '8' || kode[i] == '9'){
			kode.erase(i, 1);
			i--;
		}
	}
	n = kode.size();
	
	//inisialisasi
	vokal.push_back('a');
	vokal.push_back('i');
	vokal.push_back('u');
	vokal.push_back('e');
	vokal.push_back('o');
	
	//algoritma
	Tulis(kode, "" , n-1);
	
	//output
	cout << "Total Kemungkinan : " << list.size() << endl;
	for(size_t i=0; i<list.size(); i++){
		cout << list[i] << endl;
	}
		
		
	}else{
		cout << "\nInvalid Input !?!\n";
		system("pause");
		goto LOOP;
	}
	
	
	return 0;
}
