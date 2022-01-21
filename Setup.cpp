#include <iostream>
#include <fstream>
#include "Item.h"
#include "Saleperson.h"
#include "SaleItems.h"
using namespace std;
int main(){
	ofstream outrecord("Items.dat",ios::out|ios::binary);
	if(!outrecord){
		cerr<<"File Couldn't be Created!";
		return 0;
	}
	item blankrecord;
	for(int i=1;i<=1000;i++){
		outrecord.write( reinterpret_cast < const char * > (&blankrecord), sizeof(item));
	}
	outrecord.close();
	ofstream outSalePerson("Saleperson.dat",ios::out|ios::binary);
	if(!outSalePerson){
		cerr<<"File Couldn't be Created!";
		return 0;
	}
	Saleperson blankperson;
	for(int i=1;i<=100;i++){
		outSalePerson.write(reinterpret_cast< const char * >(&blankperson),sizeof(Saleperson));
	}
	outSalePerson.close();
	ofstream outsale("Sales.dat",ios::out|ios::binary);
	if(!outsale){
		cerr<<"File Couldn't be Created!";
		return 0;
	}
	Sale blanksale;
	for(int i=1;i<=1000;i++){
		outsale.write( reinterpret_cast < const char * > (&blanksale), sizeof(Sale));
	}
	outsale.close();
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout<<"\t\t\t\t\t\t------------------------\n";
	cout<<"\t\t\t\t\t\tSystem is Ready to use!!\n";
	cout<<"\t\t\t\t\t\t------------------------";
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n";
	system("Pause");
}
