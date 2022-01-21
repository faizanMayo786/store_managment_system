#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;
class Sale{
	private:
		int No,NOIS;//NOIS= Number Of Items Sold
		double Prc,Totalprc,Paid,Outstanding;
		char Saleitem[15], SaleCategory[20];
	public:
		Sale(int = 0, string = "", string = "", double = 0.0,int = 0, double = 0.0, double = 0.0,double = 0.0);
		int getNo() const;
		void setNo(int);
		string getSaleitem() const;
		void setSaleitem(string);
		string getSaleCategory() const;
		void setSaleCategory(string);
		double getPrc() const;
		void setPrc(double);
		int getNOIS() const;
		void setNOIS(int);
		double getTotalprc() const;
		void setTotalprc(double);
		double getPaid() const;
		void setPaid(double);
		double getOutstanding() const;
		void setOutstanding(double);
};
Sale::Sale(int no,string saleitem,string salecategory,double prc,int nois,double totalprc,double paid,double outstanding){
	setNo(no);
	setSaleitem(saleitem);
	setSaleCategory(salecategory);
	setPrc(prc);
	setNOIS(nois);
	setTotalprc(totalprc);
	setPaid(paid);
	setOutstanding(outstanding);
}
int Sale::getNo() const{
	return No;
}
void Sale::setNo(int no){
	No = no;
}
string Sale::getSaleitem() const{
	return Saleitem;
}
void Sale::setSaleitem(string saleitem){
	int length=saleitem.size();
	length = (length < 15? length : 14);
	saleitem.copy(Saleitem,length);
	Saleitem[length]='\0';
}
string Sale::getSaleCategory() const{
	return SaleCategory;
}
void Sale::setSaleCategory(string salecategory){
	int length=salecategory.size();
	length = (length < 20? length : 19);
	salecategory.copy(SaleCategory,length);
	SaleCategory[length]='\0';
}
double Sale::getPrc() const{
	return Prc;
}
void Sale::setPrc(double prc){
	Prc = prc;
}
int Sale::getNOIS() const{
	return NOIS;
}
void Sale::setNOIS(int nois){
	NOIS = nois;
}
double Sale::getTotalprc() const{
	return Totalprc;
}
void Sale::setTotalprc(double totalprc){
	Totalprc = totalprc;
}
double Sale::getPaid() const{
	return Paid;
}
void Sale::setPaid(double paid){
	Paid = paid;
}
double Sale::getOutstanding() const{
	return Outstanding;
}
void Sale::setOutstanding(double outstanding){
	Outstanding = outstanding;
}
