// Write a C++ program that simulates a library management system 
//by defining a `Student` class with attributes for name, roll number, 
//department, age, section, book name, and book issue date. Implement 
//methods to collect student details from the user, and ensure these details are 
//saved to a file named `library_records.txt` using file handling in append mode 
//to preserve existing data. In the `main` function, create an instance of the 
//`Student` class, use the methods to collect and validate the student's details, 
//save the data to the file, and display a confirmation message upon successful 
//registration of the book issue.

#include<iostream>
#include<fstream>
using namespace std;

class Student {
	public:
		string name, roll_number, department, age, section, book_name, issue_date;
	void getinfo(){
		cout << "Enter Name " << endl;
		getline(cin, name);
		cout << "Enter Roll Number " << endl;
		getline(cin, roll_number);	
		cout << "Enter Department " << endl;
		getline(cin, department);		
		cout << "Enter Age " << endl;
		getline(cin, age);
		cout << "Enter Section " << endl;
		getline(cin, section);
		cout << "Enter Book Name " << endl;
		getline(cin, book_name);
		cout << "Enter Issue Date " << endl;
		getline(cin, issue_date);
		}
};
int main () {
	
	Student student;
	student.getinfo();
	
	ofstream outputfile("library_records.txt");
	
	if(!outputfile.is_open()){
		cout << "Error Occured, file is not open " << endl;
		return 0;
	}
	outputfile << student.department << endl;
	outputfile << student.age << endl;
	outputfile << student.book_name << endl;
	outputfile << student.issue_date << endl;
	outputfile << student.name << endl;
	outputfile << student.roll_number << endl;
	outputfile << student.section << endl;
	
	outputfile.close();
		cout << "Data Has Been Saved " << endl;
	
	return 0;
}
