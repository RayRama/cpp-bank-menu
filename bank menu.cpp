/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
using namespace std;

// Fungsi tanpa kembalian / return

void showMenu() {
    cout << "============ MENU ============" << endl;
    cout << "0. Check Account Info / Cek Informasi Akun" << endl;
    cout << "1. Check Balance / Cek Saldo" << endl;
    cout << "2. Add Balance / Tambah Saldo" << endl;
    cout << "3. Withdraw / Tarik Tunai" << endl;
    cout << "4. Exit / Keluar" << endl;
    cout << "==============================" << endl;
}

void bankSystem(string user, string password) {
    int options;
    double balance = 0;
    char ulang;
	
    start:
    do {
        showMenu();
        cout << "Chosse Options / Pilih Opsi: ";
        cin >> options;
        
        system("cls");
        
        switch (options) {
            case 0:
                cout << "\n";
                cout << "Id Akun Anda: " << user << endl;
                cout << "Pin Akun Anda: " << password << endl;
                cout << "\n";
                break;
            case 1:
				cout << "\n";
                cout << "Saldo Anda Tersisa: Rp. " << balance << endl;
				cout << "\n";
                break;
            case 2:
                double addBalance;
				
				cekAdd:
                cout << "\n";
                cout << "Masukan Jumlah Saldo yang ingin Ditambahkan: Rp. ";
                cin >> addBalance;
				cout << "\n";
				
				cout << "Apakah anda ingin menambahkan saldo sebesar Rp. " << addBalance << " ke rekening anda ? [Y/N] ";
				cin >> ulang;
                
				if(ulang == 'Y' || ulang == 'y'){
            	    balance += addBalance;
            	    cout << "Rekening anda ditambahkan saldo sebesar Rp. " << addBalance << endl << endl;
            	} else if(ulang == 'N' || ulang == 'n'){
            	    system("cls");
            	    goto cekAdd;
            	} else {
                    goto cekAdd;
                }
                
                break;
            case 3:
                double withdrawAmmount;
				
				cekWithdraw:
                cout << "\n";
                cout << "Masukan Jumlah Saldo yang Ingin Ditarik: Rp. ";
                cin >> withdrawAmmount;
                cout << "\n";
                
				cout << "Apakah anda ingin menarik saldo sebesar Rp. " << withdrawAmmount << " dari rekening anda ? [Y/N] ";
				cin >> ulang;
                
				if(ulang == 'Y' || ulang == 'y'){
            	    if (withdrawAmmount <= balance) {
						balance -= withdrawAmmount;
						cout << "Penarikan saldo berhasil" << endl << endl;
					} else {
						cout << "\n";
						cout << "Saldo yang Anda Miliki Tidak Cukup" << endl;
						cout << "Sisa Saldo Anda Sebesar: Rp. " << balance << endl;
						cout << "\n";
					}
            	} else if(ulang == 'N' || ulang == 'n'){
            	    system("cls");
            	    goto cekWithdraw;
            	} else {
                    goto cekWithdraw;
                }
				
                
                break;
            case 4:
                cekExit:
    
                cout<<"Apakah anda ingin keluar dari program [Y/N] : ";
            	cin >> ulang;
 
	            if(ulang == 'Y' || ulang == 'y'){
            	    system("cls");
            	    cout << "Program dihentikan.\nSemoga harimu menyenangkan!!!" << endl;
					#ifdef _WIN32
						Sleep(2000);
					#else
						sleep(2);
					#endif
            	    exit(0);
            	} else if(ulang == 'N' || ulang == 'n'){
            	    system("cls");
            	    goto start;
            	} else {
                    goto cekExit;
                }
        }
        
    } while ( options != 4);
    
    // system("pause > 0");
}

int main()
{
	srand (time(NULL));
    int number[4], pass;
    char ulang;
    string accInput, passInput, accVerif, passVerif;
	
	for (int i = 0; i < 4; i++) {
		number[i] = rand() % 9000 + 1000;
	}
	
	start:
	system("cls");
	stringstream userId, userPass;

	userId << number[0] << "-" << number[1] << "-" << number[2] << "-" << number[3];
    
    cout << "============ Random Bank Account Generator ============" << endl << endl;
    cout << "Bank Account ID: " << userId.str();
	cout << "\n";

	pass = rand() % 9000 + 1000;
	userPass << pass;
	cout << "Your Pin: " << pass << endl << endl;
	cout << "=======================================================" << endl;
	
	userId >> accVerif;
	userPass >> passVerif;
	
	cout << "Masukan ID akun anda: ";
    cin >> accInput;
	cout << "Masukan pin akun anda: ";
	cin >> passInput;
	
	if (accInput == accVerif && passVerif == passInput) {
	    system("cls");
	    bankSystem(accInput, passInput);
	} else {
	    system("cls");
	    
	    cout << "User Tidak Ditemukan" << endl;
	    cout << "Program Akan Mengulang Secara Otomatis Dalam 2 Detik" << endl;
	    #ifdef _WIN32
			Sleep(2000);
		#else
			sleep(2);
		#endif
	    
	    goto start;
	}
	
    return 0;
}
