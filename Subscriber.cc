#include<iostream>
#include<string>
#include"Subscriber.h"
using namespace std;


Subscriber ::  Subscriber(string n,string c){
	name = n;
	creditcard = c;
}
bool Subscriber :: matches(const string& name){
	if(this->name == name){
		return true;
	}else{
		return false;
	}
}
  

