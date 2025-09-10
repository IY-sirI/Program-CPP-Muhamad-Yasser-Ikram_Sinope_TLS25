#include <iostream>
using namespace std;

int main(){
	
	//Deklarasi
	int n;
	int arr[n];
	
	//Input
	cout << "Banyak bilangan : ";
	cin >> n;
	cout << "\n";
	
	cout << "Input bilangan :\n";
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	cout << "\n";
	
	int simpan;
	//lompat dua (0, 2, 4, ...)
	for(int i=0; i<n; i+=2){
		
		//clear simpanan
		simpan = 0;
		
		while(arr[i] != 0){
			simpan *= 10;          //simpan dikalikan 10
			simpan += arr[i] % 10; //simpan dimasukkan digit paling kanan
			arr[i] /= 10;          // digit paling kanan dihapus
		}
		arr[i] = simpan; //hasil algoritma dimasukkan kembali pada array
	}
	
	int hasil = 0;
	
	//Penjumlahan
	for(int i=0; i<n; i++){
		hasil += arr[i];
	}
	
	cout << "Hasil : " << hasil;
	return 0;
}
