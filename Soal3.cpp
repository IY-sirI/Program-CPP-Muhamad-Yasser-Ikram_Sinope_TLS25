#include <iostream>
using namespace std;

int main(){
	int n;
	int arr[n];
	
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	
	for(int i=0; i<n; i++){
		if( (arr[i]-24) % 103 <= 20) cout << "Hijau\n";
		else if( (arr[i]-24) % 103 <= 23) cout << "Kuning\n";
		else cout << "Merah\n";
	}
	
	return 0;
}
