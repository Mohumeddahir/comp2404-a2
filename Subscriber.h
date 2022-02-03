#ifndef Subscriber_h
#define Subscriber_h
#include<iostream>
#include<string>
using namespace std;
class Subscriber{
	string name;
	string creditcard;
	public:
	Subscriber(string n,string c);
	bool matches(const string& name);
	  
};
#endif
