#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string>
#include <conio.h>
#include <time.h>
#include <string.h>
#include <fstream>
#include<sstream>
#include "csv.h"
#include "CSVWriter.h"
using namespace std;

class ATM{
	protected:
	string cardNo;
	int password;
	double balance;
	public:
		ATM() {
		}
		ATM(string cardNo,int password,double balance) {
				this->cardNo = cardNo;
				this->password = password;
				this->balance = balance;
		}
//		void set(long int Acc_num,string pass) {
//			this->Acc_num=Acc_num;
//			this->pass=pass;
//			bal=5000;
//		}
		
		virtual void main_menu(){}
};
class Balance : virtual public ATM {
//	protected :
//		double bal;
	public:
		Balance() {}
		void getBalance() {
			cout<<"currunt Balance : "<<balance<<endl;
		}
};
class Deposite : virtual public ATM{
	protected:
	int dep;
	public:
		Deposite() {}
		void recipt() {
			system("cls");
			//showLogo();
			char date[9];
			char time[9];
			_strdate(date);
			_strtime(time);
			cout << "\n\n\t\t\t\t\t PRINTING RECEIPT . . .\n";
			//waiting(3000);
			system("cls");
			//showLogo();
			cout << endl <<"\n\n\t\t\t|\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 BANCO DE ORO \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2|";
			cout << "\n\t\t\t|\t\t\t\t\t      |"
				 << "\n\t\t\t|\t     ATM TRANSACTION RECORD\t      |"
				 << "\n\t\t\t|\t\t\t\t\t      |"
				 << "\n\t\t\t|Deposite ammount:\t\t "<<dep<<"\t      |"
				 << "\n\t\t\t|Currunt Balance:\t\t "<<balance<<"\t      |"
				 << "\n\t\t\t|DATE:\t\t\t    "<<date<<"\t      |"
				 << "\n\t\t\t|TIME:\t\t\t    "<<time<<"\t      |"
				 << "\n\t\t\t|LOCATION:\t\t    Warangal \t      |"
				 << "\n\t\t\t|CARD NUM:\t\t    ************1215  |"
				 << "\n\t\t\t|_______________________________________________|"<<endl<<endl;
		}
		void deposite()
		{
			cout<<"Enter Ammount in multiple of 100 : ";
			cin>>dep;	
			if(dep%100==0)
			{
				balance+=dep;
				recipt();
			}
		}	
};
class Withdraw : virtual public ATM{
	protected:
		int withdrawAmmount;
	public:
		Withdraw(){}
		void recipt() {
			system("cls");
			//showLogo();
			char date[9];
			char time[9];
			_strdate(date);
			_strtime(time);
			cout << "\n\n\t\t\t\t\t PRINTING RECEIPT . . .\n";
			//waiting(3000);
			system("cls");
			//showLogo();
			cout << endl <<"\n\n\t\t\t|\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 PUBLIC BANK \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2|";
			cout << "\n\t\t\t|\t\t\t\t\t      |"
				 << "\n\t\t\t|\t     ATM TRANSACTION RECORD\t      "
				 << "\n\t\t\t|\t\t\t\t\t      |"
				 << "\n\t\t\t|Withdraw ammount:\t    "<<withdrawAmmount<<"\t      |"
				 << "\n\t\t\t|Currunt Balance :\t    "<<balance<<"\t      |"
				 << "\n\t\t\t|DATE:\t\t\t    "<<date<<"\t      |"
				 << "\n\t\t\t|TIME:\t\t\t    "<<time<<"\t      |"
				 << "\n\t\t\t|LOCATION:\t\t    Warangal \t      |"
				 << "\n\t\t\t|CARD NUM:\t\t    ************"<<cardNo<<"  |"
				 << "\n\t\t\t|_____________________________________________|"<<endl<<endl;
		}
		void withdraw() {
			cout<<"Enter Ammount in multiple of 100 : ";
			cin>>withdrawAmmount;
			if(withdrawAmmount < 0) {
				cout<<"Please correct ammount/n";
			}
			else if(withdrawAmmount > balance) {
				cout<<"Insufficient Balance\n";
			}
			else if(withdrawAmmount % 100 != 0) {
				cout<<"Please enter ammount in multiple of 100\n";
			}
			else {
				balance -= withdrawAmmount;
				updataBalance();
				recipt();
			}
		}
		void updataBalance() {
			// implementation remaining
		}	
};
class Main:public Deposite,public Withdraw,public Balance{
	int choise;
	public:
	
		Main(string A,int P,double B):ATM(A,P,B){
			}
		void main_menu()
		{
			
			cout<<"Press 1 for Withdraw"<<endl;
			cout<<"Press 2 for Deposite"<<endl;
			cout<<"Press 3 for Check Balance"<<endl;
			cout<<"Press 0 for Exit"<<endl;
			l:
			cout<<"Enter your choise : ";
			cin>>choise;
			switch(choise)
			{
				case 1:
					{
						withdraw();
						break;
					}
				case 2:
					{
						deposite();
						break;
					}
				case 3:
					{
						getBalance();
						break;
					}
				case 0:
					{
						exit(0);
					}
				default :
					{
						cout<<"Enter correct choise"<<endl;
					}
			}
			goto l;
		}
};


bool isValideUser(string cardNo, int password,double &bal) {

		io::CSVReader<3> in("data.csv");
	  	in.read_header(io::ignore_extra_column, "CardNo", "Pin" ,"Balance");
//	  	std::string vendor; int size; double speed;
	  	string cardNumber;
		int pass;
	  	double balance;
	  	
	  	while(in.read_row(cardNumber, pass, balance)){
//	    	cout<<cardNo << " " << pin << " " << balance << endl;
			if(cardNumber == cardNo) {
				if(password == pass) {
					bal = balance;
					return 1;
				}
				else {
					cout<<"Incorrect Password \n";
				}
			}
	  	}
	  	
    	cout<<"User Not Found\n"<<endl;
    	return 0;
}
void start() {
		string cardNo;
		int password;
		double balance;
		cin>>cardNo;
		cout<<"\n\t\t\t\t\t\tEnter PIN\n\t\t\t\t\t\t   ";
		cin>>password;
		
		if(isValideUser(cardNo,password,balance)){
			ATM *obj;
			Main o1(cardNo,password,balance);
			obj=&o1;
			
			obj->main_menu();
		}
}
int main()
{
	
	cout<<"                       ***              *************         ****        ****\n"
		<<"                    ***   ***           *************         ******    ******\n"
		<<"                   ***     ***              ****              ****   **   ****\n"
		<<"                  ***       ***             ****              ****        ****\n"
		<<"                  ***       ***             ****              ****        ****\n"
		<<"                  *************             ****              ****        ****\n"
		<<"                  *************             ****              ****        ****\n"
		<<"                  ***       ***             ****              ****        ****\n"
		<<"                  ***       ***             ****              ****        ****\n";
		
		
		cout<<"\n\n\t\t\t\t\tEnter Bank Account number\n\t\t\t\t\t\t";
		start();
		
	return 0;
}