#include<iostream>
#include<cstring>
#include<conio.h>
#include<conio.h>
using namespace std;
class Saleperson{
	private:
		int ID;
		double Salary;
		char Fname[15],Lname[10],City[15],Dateofjoin[12],Phnum[18];
	public:
		Saleperson( int = 0, string = "", string = "", string = "", string = "",double = 0.0, string = "");
		int getID() const;
		void setID(int);
		string getFname() const;
		void setFname(string);
		string getLname() const;
		void setLname(string);
		string getCity() const;
		void setCity(string);
		string getDateofjoin() const;
		void setDateofjoin(string);
		double getSalary() const;
		void setSalary(double);
		string getPhnum() const;
		void setPhnum(string);
};
Saleperson::Saleperson(int id,string fname,string lname,string city,string doj,double salary,string phnum){
	setID(id);
	setFname(fname);
	setLname(lname);
	setCity(city);
	setDateofjoin(doj);
	setSalary(salary);
	setPhnum(phnum);
}
int Saleperson::getID() const{
	return ID;
}
void Saleperson::setID(int id){
	ID = id;
}
string Saleperson::getFname() const{
	return Fname;
}
void Saleperson::setFname(string fname){
	int length = fname.size();
	length = (length <15? length : 14);
	fname.copy(Fname,length);
	Fname[length]='\0';
}
string Saleperson::getLname() const{
	return Lname;
}
void Saleperson::setLname(string lname){
	int length = lname.size();
	length = (length <10? length : 9);
	lname.copy(Lname,length);
	Lname[length]='\0';
}
string Saleperson::getCity() const{
	return City;
}
void Saleperson::setCity(string city){
	int length = city.size();
	length = (length <15? length : 14);
	city.copy(City,length);
	City[length]='\0';
}
string Saleperson::getDateofjoin() const{
	return Dateofjoin;
}
void Saleperson::setDateofjoin(string doj){
	int length = doj.size();
	length = (length <12? length : 11);
	doj.copy(Dateofjoin,length);
	Dateofjoin[length]='\0';
}
double Saleperson::getSalary() const{
	return Salary;
}
void Saleperson::setSalary(double salary){
	Salary = salary;
}
string Saleperson::getPhnum() const{
	return Phnum;
}
void Saleperson::setPhnum(string phnum){
	int length = phnum.size();
	length = (length <18? length : 18);
	phnum.copy(Phnum,length);
	Phnum[length]='\0';
}

