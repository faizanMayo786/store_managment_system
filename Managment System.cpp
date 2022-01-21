// Store Management System
#include <iostream>
#include <fstream>
#include <iomanip>
#include "Saleperson.h"//Saleperson  Class Definition
#include "SaleItems.h"// SaleItems Class Definition
#include "Item.h"// Items Class Definition
// Presentation Fuctions
void stockmenu();
void search();
void headline();
void outline(item &);
void content();
void welcome();
void loginmenu();
void personmenu();
void personhead();
void personline(Saleperson&);
void seaperson();
void personcontent();
void Salemenu();
void salehead();
void saleline(Sale &);
void seasale();
using namespace std;
int main(){//Varibles Declaration
	welcome();
	system("pause");
	system("cls");
	// Item Record
	int itemno,stock,option;
	double price;
	string Title,Manufacturer,Dateofexp,Category;
	///////////////////////////////	
	// Sale Person Record
	int ID;
	double Salary;
	string Fname,Lname,City,Dateofjoin,Phnum;
	
	// Sale an Item
	int No,stocks,NOIS;//NOIS= Number Of Items Sold
	double Prc,Totalprc,Paid,Outstanding;
	string Saleitem, SaleCategory;
	while(true){
		int login;
		loginmenu();
		cin>>login;
		if(login==1){
			while(true){
				system("cls");
				stockmenu();
				cin>>option;
				//Input Record
				if(option==1){
					fstream outrecord("Items.dat",ios::in|ios::out|ios::binary);// Writing Data
					if(!outrecord){
						cerr<<"File Couldn\'t be Opened! \nPlease Run the Setup.exe Application.";//Error
					}
					item orecord;
					system("cls");
					// Input Loop
					while(true){
						cout<<"\n\t\t\t\t------------------------------------------------\n";
						cout<<"\t\t\t\t---------------Input Item Record----------------\n";
						cout<<"\t\t\t\t------------------------------------------------\n\n";
						cout<<"Enter Item Number: ";
						cin>>itemno;// Item Number
						outrecord.seekg((itemno-1)*sizeof(item));
						outrecord.read(reinterpret_cast < char * > ( &orecord ) , sizeof(item));
						if(itemno<=1000&&itemno>0&&orecord.getitemno()!=itemno){
							cout<<"Enter item\'s Title: ";
							cin>>Title;
							cout<<"Enter item\'s Manufacturer: ";
							cin>>Manufacturer;
							cout<<"Enter item\'s Category: ";
							cin>>Category;
							cout<<"Enter item\'s Date of Expiry: ";
							cin>>Dateofexp;
							cout<<"Enter item\'s Price: ";
							cin>>price;
							cout<<"Enter item\'s Stock: ";
							cin>>stock;
							// Setting Values by Calling Functions
							orecord.setitemno(itemno);
							orecord.setTitle(Title);
							orecord.setManufacturer(Manufacturer);
							orecord.setCategory(Category);
							orecord.setDateofexp(Dateofexp);
							orecord.setprice(price);
							orecord.setstock(stock);
							// Random Accessing of Specified Record According to Item Number
							outrecord.seekp((orecord.getitemno()-1)*sizeof(item));
							outrecord.write(reinterpret_cast < const char * > ( &orecord ) , sizeof(item));
						}else{
							cerr<<"Some Information is already Stored on that Location!\n\nTry Inputing another Item Number!!!\n\n";//Error
						}
						char ask;//Loop Breaker
						cout<<"Do You Want to Add more Items(Y/N)?";
						cin>>ask;
						if(ask=='N'||ask=='n'){
							break;
						}
						system("cls");
					}
					system("Pause");
					system("cls");
					outrecord.close();//End of Input Record
				}
				// Display All Record
				else if(option==2){
					ifstream inrecord("Items.dat",ios::in|ios::binary);//Reading Mod
					if(!inrecord){
						cerr<<"File Couldn'\t be Opened.\n";//Error
						return 0;
					}
					system("cls");
					cout<<"\n\t\t\t\t------------------------------------------------\n";
					cout<<"\t\t\t\t--------------Display All Records---------------\n";
					cout<<"\t\t\t\t------------------------------------------------\n\n";
					headline();
					item irecord;// Class Object
					//Reading Records Sequentialy
					inrecord.read(reinterpret_cast < char * > ( &irecord ) , sizeof(item) );
					while(inrecord && !inrecord.eof()){
						if(irecord.getitemno()!=0){
							outline(irecord);// Outline Function
						}
						inrecord.read(reinterpret_cast < char * > ( &irecord ) , sizeof(item) );
					}
					cout<<endl;
					system("Pause");
					system("cls");
					inrecord.close();//End of Outputting Record
				}
				// Searching Records
				else if(option == 3){
					ifstream searchrecord("Items.dat",ios::in|ios::binary);// Reading Mod
					if(!searchrecord){
						cerr<<"File Couldn\'t be opened.\n";//Error
						return 0;
					}
					item srecord;// Class Object
					system("cls");
					int opt;
					search();// Function Call
					cin>>opt;// Condition option
					if(opt==1){
						cout<<"Enter Title of Item: ";
						cin>>Title;
						headline();// function call
						// searching records by title Sequentialy
						searchrecord.read(reinterpret_cast < char * > ( &srecord ) , sizeof(item));
						while(searchrecord&&!searchrecord.eof()){
							if(Title==srecord.getTitle()){
								outline(srecord);
							}
							searchrecord.read(reinterpret_cast < char * > ( &srecord ) , sizeof(item));
						}
						system("pause");
						system("cls");
					}
					else if(opt==2){
						cout<<"Enter Manufacturer of Item: ";
						cin>>Manufacturer;
						headline();
						// searching records by Manufacturer Sequentialy
						searchrecord.read(reinterpret_cast < char * > ( &srecord ) , sizeof(item));
						while(searchrecord&&!searchrecord.eof()){
							if(Manufacturer==srecord.getManufacturer()){
								outline(srecord);
							}
							searchrecord.read(reinterpret_cast < char * > ( &srecord ) , sizeof(item));
						}
						system("pause");
						system("cls");
					}
					else if(opt==3){
						cout<<"Enter Category of Item: ";
						cin>>Category;
						headline();
						// searching records by Category Sequentialy
						searchrecord.read(reinterpret_cast < char * > ( &srecord ) , sizeof(item));
						while(searchrecord&&!searchrecord.eof()){
							if(Category==srecord.getCategory()){
								outline(srecord);
							}
							searchrecord.read(reinterpret_cast < char * > ( &srecord ) , sizeof(item));
						}
						system("pause");
						system("cls");
					}else if(opt==4){
						cerr<<"\n\n\n\n\n\t\t\t\t\t------------------\n\t\t\t\t\tAction Terminated.\n\t\t\t\t\t------------------\n\n\n\n\n";
						system("pause");system("cls");
						break;
					}else{
						cerr<<"Wrong Inputs!\n";
						break;
					}
					searchrecord.close();
					//End of Searching
				}
				// Searching Zero Stock Items
				else if(option == 4){
					ifstream zerorecord("Items.dat",ios::in|ios::binary);//Reading Mod
					if(!zerorecord){
						cerr<<"File Couldn\'t be opened.\n";//Error
						return 0;
					}
					item zrecord;// Class Object
					system("cls");
					cout<<"\n\t\t\t\t------------------------------------------------\n";
					cout<<"\t\t\t\t--------------Finished Stock Items--------------\n";
					cout<<"\t\t\t\t------------------------------------------------\n\n";
					headline();
					// Searching Zero Stock Items Sequentialy
					zerorecord.read( reinterpret_cast < char * > ( &zrecord ) , sizeof(item) );
					int i=0;
					while(zerorecord&&!zerorecord.eof()){
						if(zrecord.getstock()==0&&zrecord.getitemno()!=0){
							outline(zrecord);
							i++;
						}
						zerorecord.read( reinterpret_cast < char * > ( &zrecord ) , sizeof(item) );
					}if(i==0){
						cout<<"No Item With Zero Stock!\n";
					}
					system("pause");
					system("cls");
					zerorecord.close();//End of Searching Zero Stock Items
				}
				// Update item Record
				else if(option == 5){
					fstream updrecord("Items.dat",ios::in|ios::out|ios::binary);// writing and reading mod
					if(!updrecord){
						cerr<<"File Couldn\'t be opened.\n";//Error
						return 0;
					}
					item urecord;// Class Object
					cout<<"Enter Item Number which you Want to Update: ";
					cin>>itemno;
					system("cls");
					updrecord.seekg( ( itemno - 1 ) * sizeof(item) );
					updrecord.read( reinterpret_cast < char * > ( &urecord ) , sizeof(item) );
					// Seeking Record to Update
					if(itemno>0&&itemno<=1000&&urecord.getitemno()!=0){
						cout<<"\n\t\t\t\t------------------------------------------------\n";
						cout<<"\t\t\t\t ------------Updating Record No. "<<itemno<<"-----------\n";
						cout<<"\t\t\t\t------------------------------------------------\n\n";
						cout<<"Enter item\'s Title: ";
						cin>>Title;
						cout<<"Enter item\'s Manufacturer: ";
						cin>>Manufacturer;
						cout<<"Enter item\'s Category: ";
						cin>>Category;
						cout<<"Enter item\'s Date of Expiry: ";
						cin>>Dateofexp;
						cout<<"Enter item\'s Price: ";
						cin>>price;
						cout<<"Add item\'s Stock: ";
						cin>>stock;
						// Setting Values 
						stock=urecord.getstock()+stock;
						urecord.setitemno(itemno);
						urecord.setTitle(Title);
						urecord.setManufacturer(Manufacturer);
						urecord.setCategory(Category);
						urecord.setDateofexp(Dateofexp);
						urecord.setprice(price);
						urecord.setstock(stock);
						// Seeking Record to Update Randomly
						updrecord.seekp((itemno-1)*sizeof(item));
						updrecord.write(reinterpret_cast < const char * > ( &urecord ) , sizeof(item));
					}else{
						cerr<<"Record Doesn\'t Exist!";//Error
						return 0;
					}
					cout<<"\n\t\t\t\t------------------------------------------------\n";
					cout<<"\t\t\t\t-------Updated Record No. "<<itemno<<" Successfully--------\n";
					cout<<"\t\t\t\t------------------------------------------------\n\n";
					updrecord.close();
					system("pause");
					system("cls");//End of Updating
				}
				// Update Records Indivdual Content
				else if(option == 6){
					fstream updindrecord("Items.dat",ios::in|ios::out|ios::binary);// writing and reading mod
					if(!updindrecord){
						cerr<<"File Couldn\'t be opened.\n";//Error
						return 0;
					}
					item uirecord;// Class Object
					cout<<"Enter Item Number which you Want to Update: ";
					cin>>itemno;
					system("cls");
					// Seeking Record to Update
					updindrecord.seekg( ( itemno - 1 ) * sizeof(item) );
					updindrecord.read( reinterpret_cast < char * > ( &uirecord ) , sizeof(item) );
					if(itemno>0&&itemno<=1000&&uirecord.getitemno()!=0){
						cout<<"\n\t\t\t\t------------------------------------------------\n";
						cout<<"\t\t\t\t ------------Updating Record No. "<<itemno<<"-----------\n";
						cout<<"\t\t\t\t------------------------------------------------\n\n";
						content();
						int ask;
						cin>>ask;
						if(ask==1&&uirecord.getitemno()!=0){
							cout<<"Enter item\'s Title: ";
							cin>>Title;
							uirecord.setTitle(Title);
							updindrecord.seekp((itemno-1)*sizeof(item));
							updindrecord.write(reinterpret_cast < const char * > ( &uirecord ) , sizeof(item));
						}else if(ask==2&&uirecord.getitemno()!=0){
							cout<<"Enter item\'s Manufacturer: ";
							cin>>Manufacturer;
							uirecord.setManufacturer(Manufacturer);
							updindrecord.seekp((itemno-1)*sizeof(item));
							updindrecord.write(reinterpret_cast < const char * > ( &uirecord ) , sizeof(item));
						}else if(ask==3&&uirecord.getitemno()!=0){
							cout<<"Enter item\'s Category: ";
							cin>>Category;
							uirecord.setCategory(Category);
							updindrecord.seekp((itemno-1)*sizeof(item));
							updindrecord.write(reinterpret_cast < const char * > ( &uirecord ) , sizeof(item));
						}else if(ask==4&&uirecord.getitemno()!=0){
							cout<<"Enter item\'s Date of Expiry: ";
							cin>>Dateofexp;
							uirecord.setDateofexp(Dateofexp);
							updindrecord.seekp((itemno-1)*sizeof(item));
							updindrecord.write(reinterpret_cast < const char * > ( &uirecord ) , sizeof(item));
						}else if(ask==5&&uirecord.getitemno()!=0){
							cout<<"Enter item\'s Price: ";
							cin>>price;
							uirecord.setprice(price);
							updindrecord.seekp((itemno-1)*sizeof(item));
							updindrecord.write(reinterpret_cast < const char * > ( &uirecord ) , sizeof(item));
						}else if(ask==6&&uirecord.getitemno()!=0){
							cout<<"Add item\'s Stock: ";
							cin>>stock;
							stock=uirecord.getstock()+stock;
							uirecord.setstock(stock);
							updindrecord.seekp((itemno-1)*sizeof(item));
							updindrecord.write(reinterpret_cast < const char * > ( &uirecord ) , sizeof(item));
						}else if(ask==7){
							cerr<<"\n\n\n\n\n\t\t\t\t\t------------------\n\t\t\t\t\tAction Terminated.\n\t\t\t\t\t------------------\n\n\n\n\n";
							system("pause");system("cls");
							break;
						}else{
							cerr<<"Record Doesn\'t Exist!\n";
							cerr<<"Wrong Inputs!\n";
							system("pause");system("cls");
							break;
						}
						
					}else{
						cerr<<"Record Doesn\'t Exist!";//Error
						return 0;
					}
					cout<<"\n\t\t\t\t------------------------------------------------\n";
					cout<<"\t\t\t\t-------Updated Record No. "<<itemno<<" Successfully--------\n";
					cout<<"\t\t\t\t------------------------------------------------\n\n";
					updindrecord.close();
					system("pause");
					system("cls");//End of Updating
				}
				// Delete Item Record
				else if(option == 7){
					fstream delrecord("Items.dat",ios::in|ios::out|ios::binary);//writing and reading mod
					if(!delrecord){
						cerr<<"File Couldn\'t be Opened!";//error
						return 0;
					}
					system("cls");
					item drecord;// class object
					cout<<"Enter Item Number which you Want to Delete Form Records->";
					cin>>itemno;
					// Seeking Record to Delete
					delrecord.seekg( ( itemno - 1 ) * sizeof(item) );
					delrecord.read( reinterpret_cast < char * > ( &drecord ) , sizeof(item));
					if(itemno>0&&itemno<=1000&&drecord.getitemno()!=0){
						item blankrecord; // Black Record
						// Place Blank Record to Replace Existing
						delrecord.seekp( ( itemno - 1 ) * sizeof(item) );
						delrecord.write( reinterpret_cast < const char * > ( &blankrecord ) , sizeof(item) );
						system("cls");
						cout<<"\n\t\t\t\t-------------------------------------------------------------\n";
						cout<<"\t\t\t\t---Item No. "<<itemno<<" Deleted Successfully from Records---\n";
						cout<<"\t\t\t\t-------------------------------------------------------------\n\n";
						system("pause");
						system("cls");
					}else{
						cerr<<"Record doesn\'t Exist.\n";//error
						system("pause");
						system("cls");				
					}
					delrecord.close();
					//End of Deleting Record
				}
				//Sort Items With Price Range
				else if(option == 8){
					ifstream prcrecord("Items.dat",ios::in|ios::binary);//Reading Mod
					if(!prcrecord){
						cerr<<"File Couldn\'t be Opened!";//Error
						return 0;
					}
					item precord;// Class Object
					system("cls");
					cout<<"\n\t\t\t\t------------------------------------------------\n";
					cout<<"\t\t\t\t---------------Price Range Sorting--------------\n";
					cout<<"\t\t\t\t------------------------------------------------\n\n";
					int amount;
					cout<<"Enter Price Range: ";
					cin>>amount;
					cout<<"\n\t\t\t\t\t1-------->Below "<<amount;
					cout<<"\n\t\t\t\t\t2-------->Above "<<amount;
					cout<<"\n\t\t\t\t\t3-------->Terminate\n";
					int ask;
					cout<<"\n\t\t\t\t\tChoose---> ";
					cin>>ask;
					// sorting files Sequentialy
					prcrecord.read( reinterpret_cast < char * > ( &precord ) , sizeof(item) );
					if(ask==1){//Below
						cout<<"\n\t\t\t\t\t-------Below "<<amount<<"-------\n";
						headline();
						while(prcrecord&&!prcrecord.eof()){
							if(precord.getprice()<amount&&precord.getprice()!=0){// Condition
								outline(precord);
							}
							prcrecord.read( reinterpret_cast < char * > ( &precord ) , sizeof(item) );
						}
					}
					else if(ask==2){//Above
						cout<<"\n\t\t\t\t\t-------Above "<<amount<<"-------\n";
						headline();
						while(prcrecord&&!prcrecord.eof()){
							if(precord.getprice()>amount&&precord.getprice()!=0){//Condition
								outline(precord);
							}
							prcrecord.read( reinterpret_cast < char * > ( &precord ) , sizeof(item) );
						}
					}else if(ask==3){
						cerr<<"\n\n\n\n\n\t\t\t\t\t------------------\n\t\t\t\t\tAction Terminated.\n\t\t\t\t\t------------------\n\n\n\n\n";
						system("pause");system("cls");
						break;
					}else{
						cerr<<"Wrong Inputs!\n";
						system("pause");system("cls");
						break;
					}
					system("pause");
					system("cls");
					prcrecord.close();// End of Price Sorting
				}
				// Sign Out of Items Record
				else if(option == 9){
					system("cls");
					cout<<"\n\t\t\t\t------------------------------------------------\n";
					cout<<"\t\t\t\t----------Signing Out of Items Record-----------\n";
					cout<<"\t\t\t\t------------------------------------------------\n\n";
					system("pause");
					system("cls");
					break;
				}
				// Terminate Program
				else if(option == 10){
					cout<<"Program Terminated\n";
					system("pause");
					system("cls");
					cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
					cout<<"\n\t\t\t\t------------------------------------------------\n";
					cout<<"\t\t\t\t---------------Thanks for Using-----------------\n";
					cout<<"\t\t\t\t------------------------------------------------\n\n";
					cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n";
					return 0;
				}else{
					cerr<<"Wrong Inputs!\n";
					system("pause");system("cls");
					break;
				}
			}
		}
		else if(login==2){
			while(true){
				system("cls");
				personmenu();
				int choose;
				cin>>choose;
				// Input New Record
				if(choose==1){
					fstream newperson("Saleperson.dat",ios::in|ios::out|ios::binary);
					if(!newperson){
						cerr<<"File Could\'t be Opened!\n";
						return 0;
					}
					Saleperson nperson;
					system("cls");
					// Input Loop
					while(true){
						cout<<"\n\t\t\t\t------------------------------------------------\n";
						cout<<"\t\t\t\t--------------Input Person Record---------------\n";
						cout<<"\t\t\t\t------------------------------------------------\n\n";
						cout<<"Enter ID: ";
						cin>>ID;// Item Number
						newperson.seekg((ID-1)*sizeof(Saleperson));
						newperson.read(reinterpret_cast < char * > ( &nperson ) , sizeof(Saleperson));
						if(ID<=100&&ID>0&&nperson.getID()!=ID){
							cout<<"Enter First Name: ";
							cin>>Fname;
							cout<<"Enter Last Name: ";
							cin>>Lname;
							cout<<"Enter City: ";
							cin>>City;
							cout<<"Enter Date of Join: ";
							cin>>Dateofjoin;
							cout<<"Enter Sallary: ";
							cin>>Salary;
							cout<<"Enter Phone Number: ";
							cin>>Phnum;
							// Setting Values by Calling Functions
							nperson.setID(ID);
							nperson.setFname(Fname);
							nperson.setLname(Lname);
							nperson.setCity(City);
							nperson.setDateofjoin(Dateofjoin);
							nperson.setSalary(Salary);
							nperson.setPhnum(Phnum);
							// Random Accessing of Specified Record According to Item Number
							newperson.seekp((nperson.getID()-1)*sizeof(Saleperson));
							newperson.write(reinterpret_cast < const char * > ( &nperson ) , sizeof(Saleperson));
						}else{
							cerr<<"Some Information is already Stored on that Location!\n\nTry Inputing another Item Number!!!\n\n";//Error
						}
						char ask;//Loop Breaker
						cout<<"Do You Want to Add more Items(Y/N)?";
						cin>>ask;
						if(ask=='N'||ask=='n'){
							break;
						}
						system("cls");
					}
				}
				// Output SalePerson Record
				else if(choose==2){
					ifstream inperson("Saleperson.dat",ios::in|ios::binary);//Reading Mod
					if(!inperson){
						cerr<<"File Couldn'\t be Opened.\n";//Error
						return 0;
					}
					system("cls");
					cout<<"\n\t\t\t\t------------------------------------------------\n";
					cout<<"\t\t\t\t--------------Display All Records---------------\n";
					cout<<"\t\t\t\t------------------------------------------------\n\n";
					personhead();
					Saleperson iperson;// Class Object
					//Reading Records Sequentialy
					inperson.read(reinterpret_cast < char * > ( &iperson ) , sizeof(Saleperson) );
					while(inperson && !inperson.eof()){
						if(iperson.getID()!=0){
							personline(iperson);// Outline Function
						}
						inperson.read(reinterpret_cast < char * > ( &iperson ) , sizeof(Saleperson) );
					}
					cout<<endl;
					system("Pause");
					system("cls");
					inperson.close();//End of Outputting Record
				}
				// Search with  First, Last Name, City
				else if(choose==3){
					ifstream searchperson("Saleperson.dat",ios::in|ios::binary);// Reading Mod
					if(!searchperson){
						cerr<<"File Couldn\'t be opened.\n";//Error
						return 0;
					}
					Saleperson sperson;// Class Object
					system("cls");
					int opt;
					seaperson();// Function Call
					cin>>opt;// Condition option
					if(opt==1){
						cout<<"Enter First Name: ";
						cin>>Fname;
						personhead();// function call
						// searching records by title Sequentialy
						searchperson.read(reinterpret_cast < char * > ( &sperson ) , sizeof(Saleperson));
						while(searchperson&&!searchperson.eof()){
							if(Fname==sperson.getFname()){
								personline(sperson);
							}
							searchperson.read(reinterpret_cast < char * > ( &sperson ) , sizeof(Saleperson));
						}
						system("pause");
						system("cls");
					}
					else if(opt==2){
						cout<<"Enter Last Name: ";
						cin>>Lname;
						personhead();
						// searching records by Manufacturer Sequentialy
						searchperson.read(reinterpret_cast < char * > ( &sperson ) , sizeof(Saleperson));
						while(searchperson&&!searchperson.eof()){
							if(Lname==sperson.getLname()){
								personline(sperson);
							}
							searchperson.read(reinterpret_cast < char * > ( &sperson ) , sizeof(Saleperson));
						}
						system("pause");
						system("cls");
					}
					else if(opt==3){
						cout<<"Enter City: ";
						cin>>City;
						personhead();
						// searching records by Category Sequentialy
						searchperson.read(reinterpret_cast < char * > ( &sperson ) , sizeof(Saleperson));
						while(searchperson&&!searchperson.eof()){
							if(City==sperson.getCity()){
								personline(sperson);
							}
							searchperson.read(reinterpret_cast < char * > ( &sperson ) , sizeof(Saleperson));
						}
						system("pause");
						system("cls");
					}else if(opt==4){
						cerr<<"\n\n\n\n\n\t\t\t\t\t------------------\n\t\t\t\t\tAction Terminated.\n\t\t\t\t\t------------------\n\n\n\n\n";
						system("pause");system("cls");
						break;
					}else{
						cout<<"Invalid Inputs.\n Try Again\n";
						system("Pause");
						system("cls");// SalePerson Record Ended
					}
					searchperson.close();
					//End of Searching
				}
				/// Sallary Range
				else if(choose==4){
					ifstream salaryperson("Saleperson.dat",ios::in|ios::binary);//Reading Mod
					if(!salaryperson){
						cerr<<"File Couldn\'t be Opened!";//Error
						return 0;
					}
					Saleperson salperson;// Class Object
					system("cls");
					cout<<"\n\t\t\t\t------------------------------------------------\n";
					cout<<"\t\t\t\t--------------Sallary Range Sorting-------------\n";
					cout<<"\t\t\t\t------------------------------------------------\n\n";
					int amount;
					cout<<"Enter Sallary Range: ";
					cin>>amount;
					cout<<"\n\t\t\t\t\t1-------->Below "<<amount;
					cout<<"\n\t\t\t\t\t2-------->Above "<<amount;
					cout<<"\n\t\t\t\t\t3-------->Terminate\n";
					int ask;
					cout<<"\n\t\t\t\t\tChoose---> ";
					cin>>ask;
					// sorting files Sequentialy
					salaryperson.read( reinterpret_cast < char * > ( &salperson ) , sizeof(Saleperson) );
					if(ask==1){//Below
						cout<<"\n\t\t\t\t\t-------Below "<<amount<<"-------\n";
						personhead();
						while(salaryperson&&!salaryperson.eof()){
							if(salperson.getSalary()<amount&&salperson.getSalary()!=0){// Condition
								personline(salperson);
							}
							salaryperson.read( reinterpret_cast < char * > ( &salperson ) , sizeof(Saleperson) );
						}
					}
					else if(ask==2){//Above
						cout<<"\n\t\t\t\t\t-------Above "<<amount<<"-------\n";
						personhead();
						while(salaryperson&&!salaryperson.eof()){
							if(salperson.getSalary()>amount&&salperson.getSalary()!=0){//Condition
								personline(salperson);
							}
							salaryperson.read( reinterpret_cast < char * > ( &salperson ) , sizeof(Saleperson) );
						}
					}else if(ask==3){
						cerr<<"\n\n\n\n\n\t\t\t\t\t------------------\n\t\t\t\t\tAction Terminated.\n\t\t\t\t\t------------------\n\n\n\n\n";
						system("pause");system("cls");
						break;
					}else{
						cout<<"Invalid Inputs.\n Try Again\n";
						system("Pause");
						system("cls");// SalePerson Record Ended
					}
					system("pause");
					system("cls");
					salaryperson.close();// End of Sallary Sorting
				}
				// Update Record
				else if(choose == 5){
					fstream updateperson("Saleperson.dat",ios::in|ios::out|ios::binary);// writing and reading mod
					if(!updateperson){
						cerr<<"File Couldn\'t be opened.\n";//Error
						return 0;
					}
					Saleperson uperson;// Class Object
					cout<<"Enter ID of Person: ";
					cin>>ID;
					system("cls");
					// Seeking Record to Update
					updateperson.seekg( ( ID - 1 ) * sizeof(Saleperson) );
					updateperson.read( reinterpret_cast < char * > ( &uperson ) , sizeof(Saleperson) );
					if(ID>0&&ID<=100){
						cout<<"\n\t\t\t\t------------------------------------------------\n";
						cout<<"\t\t\t\t ------------Updating Record No. "<<ID<<"-----------\n";
						cout<<"\t\t\t\t------------------------------------------------\n\n";
						personcontent();
						int ask;
						cin>>ask;
						if(ask==1){
							cout<<"Enter First Name: ";
							cin>>Fname;
							uperson.setFname(Fname);
							updateperson.seekp((uperson.getID()-1)*sizeof(Saleperson));
							updateperson.write(reinterpret_cast < const char * > ( &uperson ) , sizeof(Saleperson));
						}else if(ask==2){
							cout<<"Enter Last Name: ";
							cin>>Lname;
							uperson.setLname(Lname);
							updateperson.seekp((uperson.getID()-1)*sizeof(Saleperson));
							updateperson.write(reinterpret_cast < const char * > ( &uperson ) , sizeof(Saleperson));
						}else if(ask==3){
							cout<<"Enter City: ";
							cin>>City;
							uperson.setCity(City);
							updateperson.seekp((uperson.getID()-1)*sizeof(Saleperson));
							updateperson.write(reinterpret_cast < const char * > ( &uperson ) , sizeof(Saleperson));
						}else if(ask==4){
							cout<<"Enter Date of Joining: ";
							cin>>Dateofjoin;
							uperson.setDateofjoin(Dateofjoin);
							updateperson.seekp((uperson.getID()-1)*sizeof(Saleperson));
							updateperson.write(reinterpret_cast < const char * > ( &uperson ) , sizeof(Saleperson));
						}else if(ask==5){
							cout<<"Enter Sallary: ";
							cin>>Salary;
							uperson.setSalary(Salary);
							updateperson.seekp((uperson.getID()-1)*sizeof(Saleperson));
							updateperson.write(reinterpret_cast < const char * > ( &uperson ) , sizeof(Saleperson));
						}else if(ask==6){
							cout<<"Enter Phone Number: ";
							cin>>Phnum;
							uperson.setPhnum(Phnum);
							updateperson.seekp((uperson.getID()-1)*sizeof(Saleperson));
							updateperson.write(reinterpret_cast < const char * > ( &uperson ) , sizeof(Saleperson));
						}else if(ask==7){
							cerr<<"\n\n\n\n\n\t\t\t\t\t------------------\n\t\t\t\t\tAction Terminated.\n\t\t\t\t\t------------------\n\n\n\n\n";
							system("pause");system("cls");
							break;
						}else{
							cout<<"Invalid Inputs.\n Try Again\n";
							system("Pause");
							system("cls");// SalePerson Record Ended
						}
						
					}else{
						cerr<<"Record Doesn\'t Exist!";//Error
						return 0;
					}
					cout<<"\n\t\t\t\t------------------------------------------------\n";
					cout<<"\t\t\t\t-------Updated Record No. "<<ID<<" Successfully--------\n";
					cout<<"\t\t\t\t------------------------------------------------\n\n";
					updateperson.close();
					system("pause");
					system("cls");//End of Updating
				}
				// Delete Record
				else if(choose==6){
					fstream delperson("Saleperson.dat",ios::in|ios::out|ios::binary);//writing and reading mod
					if(!delperson){
						cerr<<"File Couldn\'t be Opened!";//error
						return 0;
					}
					system("cls");
					Saleperson dperson;// class object
					cout<<"Enter SalePerson\'s ID which you Want to Delete Form Records->";
					cin>>ID;
					// Seeking Record to Delete
					delperson.seekg( ( ID - 1 ) * sizeof(Saleperson) );
					delperson.read( reinterpret_cast < char * > ( &dperson ) , sizeof(Saleperson));
					if(ID>0&&ID<=1000&&dperson.getID()!=0){
						Saleperson blankperson; // Black Record
						// Place Blank Record to Replace Existing
						delperson.seekp( ( ID - 1 ) * sizeof(Saleperson) );
						delperson.write( reinterpret_cast < const char * > ( &blankperson ) , sizeof(Saleperson) );
						system("cls");
						cout<<"\n\t\t\t\t-------------------------------------------------------------\n";
						cout<<"\t\t\t\t---------ID # "<<ID<<" Deleted Successfully from Records-+-------\n";
						cout<<"\t\t\t\t-------------------------------------------------------------\n\n";
						system("pause");
						system("cls");
					}else{
						cerr<<"Record doesn\'t Exist.\n";//error
						system("pause");
						system("cls");				
					}
					delperson.close();
					//End of Deleting Record
				}
				// Sign Out of SalePersons
				else if(choose == 7){
					system("cls");
					cout<<"\n\t\t\t\t------------------------------------------------\n";
					cout<<"\t\t\t\t-------Signing Out of SalePerson\'s Record-------\n";
					cout<<"\t\t\t\t------------------------------------------------\n\n";
					system("pause");
					system("cls");
					break;
				}
				// Terminate Program
				else if(choose == 8){
					cout<<"Program Terminated\n";
					system("pause");
					system("cls");
					cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
					cout<<"\n\t\t\t\t------------------------------------------------\n";
					cout<<"\t\t\t\t---------------Thanks for Using-----------------\n";
					cout<<"\t\t\t\t------------------------------------------------\n\n";
					cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n";
					return 0;
				}else{
					cout<<"Invalid Inputs.\n Try Again\n";
					system("Pause");
					system("cls");// SalePerson Record Ended
				}
			}
		}
		//Sale Items
		else if(login==3){
			while(true){
				system("cls");
				int chose;
				Salemenu();
				cin>>chose;
				if(chose==1){
					fstream outsale("Sales.dat",ios::in|ios::app|ios::binary);
					fstream outitem("Items.dat",ios::in|ios::out|ios::binary);
					if(!outsale){
						cerr<<"File Couldn\'t be Opened!";
						return 0;
					}
					if(!outitem){
						cerr<<"File Couldn\'t be Opened!";
						return 0;
					}
					system("cls");
					cout<<"\n\t\t\t\t------------------------------------------------\n";
					cout<<"\t\t\t\t-------------------Sale Items-------------------\n";
					cout<<"\t\t\t\t------------------------------------------------\n\n";
					
					Sale osale;
					item oitem;
					cout<<"Enter Title of Item: ";
					cin>>Saleitem;
					
					int exist=0;
					outitem.read(reinterpret_cast < char * > ( &oitem ) , sizeof(item));
					while(outitem&&!outitem.eof()){
						if(Saleitem==oitem.getTitle()){
							exist=1;
							stocks=oitem.getstock();
							No=oitem.getitemno();
							Prc=oitem.getprice();
							SaleCategory=oitem.getCategory();
							break;
						}
						outitem.read(reinterpret_cast < char * > ( &oitem ) , sizeof(item));
					}
					if(exist==1){
						cout<<"Enter Amount of Item: ";
						cin>>NOIS;
						if(NOIS<=stocks){
							Totalprc=NOIS*Prc;
							cout<<"Total Price: "<<Totalprc<<endl;
							cout<<"Amount Paid: ";
							cin>>Paid;
							Outstanding=Paid-Totalprc;
							cout<<"Outstandings: "<<Outstanding<<endl;
							osale.setNo(No);
							osale.setSaleitem(Saleitem);
							osale.setSaleCategory(SaleCategory);
							osale.setPrc(Prc);
							osale.setNOIS(NOIS);
							osale.setTotalprc(Totalprc);
							osale.setPaid(Paid);
							osale.setOutstanding(Outstanding);
							
							stocks = stocks-NOIS;
							oitem.setstock(stocks);
							
							outitem.seekp((oitem.getitemno()-1)*sizeof(item));
							outitem.write(reinterpret_cast<const char *>( &oitem ),sizeof(item));
							
							outsale.write(reinterpret_cast<const char *>( &osale ),sizeof(Sale));
							outsale.close();
							outitem.close();
							system("cls");
						}else{
							cerr<<"Item Out of Stock!\n";
							system("Pause");
							system("cls");
							break;
							
						}
						
					}else{
						cerr<<"Incorrect Title or Item Doesn\'t Found!!\n";
						system("Pause");
						system("cls");
						break;
					}
					system("pause");
					system("cls");	
				}
				// Sales Record
				else if(chose == 2){
					ifstream insale("Sales.dat",ios::in|ios::binary);
					if(!insale){
						cerr<<"File Couldn\'t be Opened!";
						return 0;
					}
					
					system("cls");
					cout<<"\n\t\t\t\t------------------------------------------------\n";
					cout<<"\t\t\t\t------------------Sales Record------------------\n";
					cout<<"\t\t\t\t------------------------------------------------\n\n";
					Sale isale;
					salehead();
					int i=0,a=0;
					int earn=0;
					insale.read(reinterpret_cast<char*>(&isale),sizeof(Sale));
					while(insale&&!insale.eof()){
						if(isale.getNo()!=0){
							saleline(isale);
							i++;a++;
							earn=isale.getTotalprc()+earn;
						}
						insale.read(reinterpret_cast<char*>(&isale),sizeof(Sale));
					}if(a==0){
						cout<<"\tZero Sales!\n";
					}
					cout<<'\t'<<setw(11)<<"---- ---  ";
					cout<<setw(15)<<"-----";
					cout<<setw(15)<<"--------";
					cout<<setw(10)<<"-----";
					cout<<setw(10)<<"------";
					cout<<setw(15)<<"----- -----";
					cout<<setw(7)<<"----";
					cout<<setw(9)<<"------------\n";
					cout<<"\n\n\t\t\t\tTotal Sales: "<<i<<'\t'<<'\t'<<"Total Earning: "<<earn<<endl;
					cout<<"\t\t\t\t----------------- "<<'\t'<<"------------------- "<<endl;
					insale.close();
					system("pause");
					system("cls");
				}
				// Search with title
				else if(chose == 3){
					ifstream searchsale("Sales.dat",ios::in|ios::binary);// Reading Mod
					if(!searchsale){
						cerr<<"File Couldn\'t be opened.\n";//Error
						return 0;
					}
					Sale ssale;// Class Object
					system("cls");
					int opt;
					seasale();// Function Call
					cin>>opt;// Condition option
					if(opt==1){
						cout<<"Enter Title of Item: ";
						cin>>Saleitem;
						salehead();// function call
						// searching records by title Sequentialy
						searchsale.read(reinterpret_cast < char * > ( &ssale ) , sizeof(Sale));
						while(searchsale&&!searchsale.eof()){
							if(Saleitem==ssale.getSaleitem()){
								saleline(ssale);
							}
							searchsale.read(reinterpret_cast < char * > ( &ssale ) , sizeof(Sale));
						}
						system("pause");
						system("cls");
					}
					else if(opt==2){
						cout<<"Enter Manufacturer of Item: ";
						cin>>Manufacturer;
						headline();
						// searching records by Manufacturer Sequentialy
						searchsale.read(reinterpret_cast < char * > ( &ssale ) , sizeof(Sale));
						while(searchsale&&!searchsale.eof()){
							if(SaleCategory==ssale.getSaleCategory()){
								saleline(ssale);
							}
							searchsale.read(reinterpret_cast < char * > ( &ssale ) , sizeof(Sale));
						}
						system("pause");
						system("cls");
					}
					else if(opt==3){
						cerr<<"\n\n\n\n\n\t\t\t\t\t------------------\n\t\t\t\t\tAction Terminated.\n\t\t\t\t\t------------------\n\n\n\n\n";
						system("pause");system("cls");
						break;
					}else{
						cerr<<"Wrong Inputs!\n";
						system("pause");system("cls");
						break;
					}
					system("pause");
					system("cls");
					searchsale.close();
					//End of Searching
				}else if(chose == 4){
					system("cls");
					cout<<"\n\t\t\t\t------------------------------------------------\n";
					cout<<"\t\t\t\t-----------Signing Out of Selling Item----------\n";
					cout<<"\t\t\t\t------------------------------------------------\n\n";
					system("pause");
					system("cls");
					break;
				}
				// Terminate Program
				else if(chose == 5){
					cout<<"Program Terminated\n";
					system("pause");
					system("cls");
					cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
					cout<<"\n\t\t\t\t------------------------------------------------\n";
					cout<<"\t\t\t\t---------------Thanks for Using-----------------\n";
					cout<<"\t\t\t\t------------------------------------------------\n\n";
					cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n";
					return 0;
				}else{
					cerr<<"Invalid Inputs.\nTry Again\n";
					system("pause");
					system("cls");
				}
		}// Sale Items Ended
			}
		else if(login==4){
			cout<<"Program Terminated\n";
			system("pause");
			system("cls");
			cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
			cout<<"\n\t\t\t\t------------------------------------------------\n";
			cout<<"\t\t\t\t---------------Thanks for Using-----------------\n";
			cout<<"\t\t\t\t------------------------------------------------\n\n";
			cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n";
			return 0;
		}else{
			cerr<<"Invalid Inputs.\nTry Again\n";
			system("pause");
			system("cls");
		}
	}
}
void welcome(){
	cout<<"\n\n\n\n\n\n\n\n\n\n\n";
	cout<<"\t\t\t\t=============================================\n";
	cout<<"\t\t\t\t---------------------------------------------\n";
	cout<<"\t\t\t\t=====Welcome to Store Management System======\n";
	cout<<"\t\t\t\t---------------------------------------------\n";
	cout<<"\t\t\t\t=============================================\n";
	cout<<"\n\n\n\n\n\n\n\n\n\n\n";
}
void loginmenu(){
	cout<<"\t\t\t\t<---------------Login Menu---------------->\n";
	cout<<"\t\t\t\t1------------------>Item Records\n";
	cout<<"\t\t\t\t2------------------>Sale Person Records\n";
	cout<<"\t\t\t\t3------------------>Sell an Item\n";
	cout<<"\t\t\t\t4------------------>Exit\n";
	cout<<"----->Enter Chocice-> ";
}
void Salemenu(){
	cout<<"\t\t\t\t<---------------Sales Menu---------------->\n";
	cout<<"\t\t\t\t1------------------>Sale Items\n";
	cout<<"\t\t\t\t2------------------>Display All Sales\n";
	cout<<"\t\t\t\t3------------------>Search with  Title, Category\n";
	cout<<"\t\t\t\t4------------------>Sign Out of Sale Person Record\n";
	cout<<"\t\t\t\t5------------------>Exit\n\n";
	cout<<"----->Enter Choice-> ";
}
void personmenu(){
	cout<<"\t\t\t\t<----------Sale Person Records------------>\n";
	cout<<"\t\t\t\t1------------------>Input New Record\n";
	cout<<"\t\t\t\t2------------------>Display All\n";
	cout<<"\t\t\t\t3------------------>Search with  First, Last Name, City\n";
	cout<<"\t\t\t\t4------------------>Search With Sallary Limit\n";
	cout<<"\t\t\t\t5------------------>Update Record\n";
	cout<<"\t\t\t\t6------------------>Delete Sale Person\'s Record\n";
	cout<<"\t\t\t\t7------------------>Sign Out of Sale Person Record\n";
	cout<<"\t\t\t\t8------------------>Exit\n\n";
	cout<<"----->Enter Choice-> ";
}
void stockmenu(){
	cout<<"\t\t\t\t<--------------Items Record--------------->\n";
	cout<<"\t\t\t\t1------------------>Input New Item\n";
	cout<<"\t\t\t\t2------------------>Display All\n";
	cout<<"\t\t\t\t3------------------>Search with  Title,Category,Manufacturer\n";
	cout<<"\t\t\t\t4------------------>Search Zero Stock Items\n";
	cout<<"\t\t\t\t5------------------>Update a Single Item\'s Complete Record\n";
	cout<<"\t\t\t\t6------------------>Update Record\'s Individual Content\n";
	cout<<"\t\t\t\t7------------------>Delete an Item Record\n";
	cout<<"\t\t\t\t8------------------>Search Items within Price Range\n";
	cout<<"\t\t\t\t9------------------>Sign Out of Items Record\n";
	cout<<"\t\t\t\t10----------------->Exit\n\n";
	cout<<"----->Enter Choice-> ";	
}
void personhead(){
	cout<<'\t'<<setw(5)<<left<<"ID ";
	cout<<setw(15)<<left<<"First Name";
	cout<<setw(13)<<"Last Name";
	cout<<setw(15)<<"City";
	cout<<setw(20)<<"Date of Join";
	cout<<setw(10)<<"Sallary";
	cout<<setw(13)<<"Phone Number\n";
	cout<<'\t'<<setw(3)<<"--   ";
	cout<<setw(15)<<"----- ----";
	cout<<setw(13)<<"---- ----";
	cout<<setw(15)<<"----";
	cout<<setw(20)<<"---- -- ----";
	cout<<setw(10)<<"-------";
	cout<<setw(13)<<"----- ------ \n";
}
void salehead(){
	cout<<'\t'<<setw(11)<<left<<"Item No.  ";
	cout<<setw(15)<<left<<"Title";
	cout<<setw(15)<<"Category";
	cout<<setw(10)<<"Price";
	cout<<setw(10)<<"Amount";
	cout<<setw(15)<<"Total Price ";
	cout<<setw(7)<<"Paid";
	cout<<setw(9)<<"OutStandings\n";
	cout<<'\t'<<setw(11)<<"---- ---  ";
	cout<<setw(15)<<"-----";
	cout<<setw(15)<<"--------";
	cout<<setw(10)<<"-----";
	cout<<setw(10)<<"------";
	cout<<setw(15)<<"----- -----";
	cout<<setw(7)<<"----";
	cout<<setw(9)<<"------------\n";
}
void headline(){
	cout<<'\t'<<setw(5)<<left<<"No.";
	cout<<setw(15)<<left<<"Title";
	cout<<setw(20)<<"Manufacturer";
	cout<<setw(15)<<"Category";
	cout<<setw(20)<<"Date of Expiry";
	cout<<setw(10)<<"Price";
	cout<<setw(6)<<"Stock\n";
	cout<<'\t'<<setw(3)<<"---  ";
	cout<<setw(15)<<"-----";
	cout<<setw(20)<<"------------";
	cout<<setw(15)<<"--------";
	cout<<setw(20)<<"---- -- ------";
	cout<<setw(10)<<"-----";
	cout<<setw(6)<<"-----\n";
}
void seaperson(){
	cout<<"\t\t\t\t<--------------Search By--------------->\n";
	cout<<"\t\t\t\t1------------------>First Name\n";
	cout<<"\t\t\t\t2------------------>Last Name\n";
	cout<<"\t\t\t\t3------------------>City\n";
	cout<<"\t\t\t\t4------------------>Terminate\n\n";
	cout<<"----->Enter Choice-> ";	
}
void seasale(){
	cout<<"\t\t\t\t<--------------Search By--------------->\n";
	cout<<"\t\t\t\t1------------------>Title\n";
	cout<<"\t\t\t\t2------------------>Category\n";
	cout<<"\t\t\t\t3------------------>Terminate Action\n\n";
	cout<<"----->Enter Choice-> ";	
}
void search(){
	cout<<"\t\t\t\t<--------------Search By--------------->\n";
	cout<<"\t\t\t\t1------------------>Title\n";
	cout<<"\t\t\t\t2------------------>Manufacturer\n";
	cout<<"\t\t\t\t3------------------>Category\n";
	cout<<"\t\t\t\t4------------------>Terminate\n\n";
	cout<<"----->Enter Choice-> ";	
}
void saleline(Sale &isale){
	cout<<'\t'<<setw(11)<<isale.getNo();
	cout<<setw(15)<<isale.getSaleitem();
	cout<<setw(15)<<isale.getSaleCategory();
	cout<<setw(10)<<isale.getPrc();
	cout<<setw(10)<<isale.getNOIS();
	cout<<setw(15)<<isale.getTotalprc();
	cout<<setw(7)<<isale.getPaid();
	cout<<setw(9)<<isale.getOutstanding()<<endl;
}
void personline(Saleperson &iperson){
	cout<<'\t'<<setw(5)<<iperson.getID();
	cout<<setw(15)<<iperson.getFname();
	cout<<setw(13)<<iperson.getLname();
	cout<<setw(15)<<iperson.getCity();
	cout<<setw(20)<<iperson.getDateofjoin();
	cout<<setw(10)<<iperson.getSalary();
	cout<<setw(13)<<iperson.getPhnum()<<endl;			
}
void outline(item &irecord){
	cout<<'\t'<<setw(5)<<irecord.getitemno();
	cout<<setw(15)<<irecord.getTitle();
	cout<<setw(20)<<irecord.getManufacturer();
	cout<<setw(15)<<irecord.getCategory();
	cout<<setw(20)<<irecord.getDateofexp();
	cout<<setw(10)<<irecord.getprice();
	cout<<setw(6)<<irecord.getstock()<<endl;			
}
void personcontent(){
	cout<<"\t\t\t\t<----------------Update By--------------->\n";
	cout<<"\t\t\t\t1------------------>First Name\n";
	cout<<"\t\t\t\t2------------------>Last Name\n";
	cout<<"\t\t\t\t3------------------>City\n";
	cout<<"\t\t\t\t4------------------>Date of Joining\n";
	cout<<"\t\t\t\t5------------------>Sallary\n";
	cout<<"\t\t\t\t6------------------>Phone Number\n";
	cout<<"\t\t\t\t7------------------>Terminate\n\n";
	cout<<"----->Enter Choice-> ";
}
void content(){
	cout<<"\t\t\t\t<----------Update Individualy By----------->\n";
	cout<<"\t\t\t\t1------------------>Title\n";
	cout<<"\t\t\t\t2------------------>Manufacturer\n";
	cout<<"\t\t\t\t3------------------>Category\n";
	cout<<"\t\t\t\t4------------------>Date of Expiry\n";
	cout<<"\t\t\t\t5------------------>Price\n";
	cout<<"\t\t\t\t6------------------>Stock\n";
	cout<<"\t\t\t\t7------------------>Terminate\n\n";
	cout<<"----->Enter Choice-> ";
}
