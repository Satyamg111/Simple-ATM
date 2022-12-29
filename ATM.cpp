#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string>
#include <conio.h>
#include <time.h>
#include <string.h>
#include <fstream>
using namespace std;

class ATM{
	protected:
	long int Acc_num;
	string pass;
	double bal;
	public:
		ATM(){
		}
		ATM(long int Acc_num,string pass)
		{
				this->Acc_num=Acc_num;
			this->pass=pass;
			bal=5000;
		}
//		void set(long int Acc_num,string pass)
//		{
//			this->Acc_num=Acc_num;
//			this->pass=pass;
//			bal=5000;
//		}
		
		virtual void main_menu()
		{
			
		}
};
class Balance : virtual public ATM{
//	protected :
//		double bal;
	public:
		Balance(){
		}
		void balance()
		{
			
			cout<<"currunt Balance : "<<bal<<endl;
		}
	
};
class Deposite : virtual public ATM{
	protected:
	int dep;
	public:
		Deposite(){
		}
		void recipt()
		{
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
				 << "\n\t\t\t|Currunt Balance:\t\t "<<bal<<"\t      |"
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
				bal+=dep;
				recipt();
			}
		}	
};
class Withdraw : virtual public ATM{
	protected:
		int amm;
	public:
		Withdraw(){
		}
		void recipt()
		{
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
				 << "\n\t\t\t|Withdraw ammount:\t    "<<amm<<"\t      |"
				 << "\n\t\t\t|Currunt Balance :\t    "<<bal<<"\t      |"
				 << "\n\t\t\t|DATE:\t\t\t    "<<date<<"\t      |"
				 << "\n\t\t\t|TIME:\t\t\t    "<<time<<"\t      |"
				 << "\n\t\t\t|LOCATION:\t\t    Warangal \t      |"
				 << "\n\t\t\t|CARD NUM:\t\t    ************1215  |"
				 << "\n\t\t\t|_____________________________________________|"<<endl<<endl;
		}
		void withdraw()
		{
			cout<<"Enter Ammount in multiple of 100 : ";
			cin>>amm;
			if(amm%100==0)
			{
				bal-=amm;
				recipt();
			}
		}
	
};
class Main:public Deposite,public Withdraw,public Balance{
	int choise;
	public:
	
		Main(long int A,string P):ATM(A,P){
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
						balance();
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


int main()
{
	long int Acc_num;
	string pass;
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
		cin>>Acc_num;
		cout<<"\n\t\t\t\t\t\tEnter PIN\n\t\t\t\t\t\t   ";
		cin>>pass;
		if(Acc_num!=123456789 && pass!="1234")
		{
			cout<<"Invalid PIN"<<endl;
		}
		else
		{
			
			ATM *obj;
			Main o1(Acc_num,pass);
			obj=&o1;
			
			obj->main_menu();
		}
		
	return 0;
}
