#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;
class item{
	private:
		int itemno,stock;
		double price;
		char Title[15],Manufacturer[20],Dateofexp[12],Category[20];
	public:
		item(int = 0, string = "", string = "", string = "", string = "", double = 0.0 , int = 0);
		void setitemno(int);
		int getitemno() const;
		void setTitle(string);
		string getTitle() const;
		void setManufacturer(string);
		string getManufacturer() const;
		void setCategory(string);
		string getCategory() const;
		void setDateofexp(string);
		string getDateofexp() const;
		void setprice(double);
		double getprice() const;
		void setstock(int);
		int getstock() const;
};
item::item(int itno, string title, string manufacturer, string category, string DOE, double prize, int Stock){
	setitemno(itno);
	setTitle(title);
	setManufacturer(manufacturer);
	setCategory(category);
	setDateofexp(DOE);
	setprice(prize);
	setstock(Stock);
}
int item::getitemno() const{
	return itemno;
}
void item::setitemno(int itno){
	itemno = itno;
}
string item::getTitle() const{
	return Title;
}
void item::setTitle(string title){
	int length = title.size();
	length = (length < 15 ? length : 14);
	title.copy( Title, length);
	Title[length] = '\0';
}
string item::getManufacturer() const{
	return Manufacturer;
}
void item::setManufacturer(string manufacturer){
	int length = manufacturer.size();
	length = (length < 20 ? length : 19);
	manufacturer.copy( Manufacturer, length);
	Manufacturer[length] = '\0';
}
string item::getCategory() const{
	return Category;
}
void item::setCategory(string category){
	int length = category.size();
	length = (length < 20 ? length : 19);
	category.copy( Category, length);
	Category[length] = '\0';
}
string item::getDateofexp() const{
	return Dateofexp;
}
void item::setDateofexp(string DOE){
	int length = DOE.size();
	length = (length < 12 ? length : 11);
	DOE.copy( Dateofexp, length);
	Dateofexp[length] = '\0';
}
double item::getprice() const{
	return price;
}
void item::setprice(double prize){
	price = prize;
}
int item::getstock() const{
	return stock;
}
void item::setstock(int Stock){
	stock = Stock;
}

