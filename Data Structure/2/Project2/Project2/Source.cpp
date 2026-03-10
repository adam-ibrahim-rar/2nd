#include <iostream>
#include <string>
using namespace std;
//Write a program contains a class Student that has data members :
//name(string), ID(int), age(float), D[2](float), G[2](char),
//GPA(float).It contains a default constructor, constructor with
//parameters and copy constructor(use initialization list form), and
//a function to display data members.In main function define
//objects and display them



class student {

	string name;
	int id;
	float age;
	float d[2];
	char g[2];
	float gpa;
public:
	student() {
		name = "unknown";
		age = 0;
		id = 0;
		gpa = 0;
		g[0] = g[1] = 'A';
		d[0] = d[1] = 0;
	}
	student(string n,int i,float dd[],char gg[],float a,float gp) {
		name = n;
		id = i;
		for (int i = 0; i < 2; i++)
		{
			d[i] = dd[i];g[i] = gg[i];
		}
		age = a;
		gpa = gp;
	}
	student (string n, int i, float dd[], char gg[], float a, float gp):
		age(a),name(n),id(i),gpa(gp)
	{ 
		for (int i = 0; i < 2; i++)
		{
			d[i] = dd[i];g[i] = gg[i];
		}
	}
	void display() {
		cout << "name is" << name << endl;
		cout << "age is" << age << endl;
		cout << "id is" << id << endl;
		cout << "gpa is" << gpa << endl;
		for (int i = 0; i < 2; i++)
		{
			cout << "d is :"<<d[i] << endl;
			cout << "d is :" << g[i];
		}
	}
};

int main() {

	student x;
	x.display();
	float dd[2] = { 2,5 };
	float gg[2] = { '2','5' };
	string name = "adam;";
	student y(name, 5, dd[2], gg[2], 15, 3.4);
	y.display();
	return EXIT_SUCCESS;
}
