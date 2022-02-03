#include<iostream>
#include<string>
#include"Episode.h"
using namespace std;
Episode :: Episode(){
	podcast = "hey";
	number = 3;
	name = "Khalid";
	content = "World";	
}
Episode :: Episode(Episode& ep){
	podcast = ep.podcast;
	number = ep.number;
	name = ep.name;
	content = ep.content;
}
Episode :: Episode(const string& pod, int num , const string& n, const string& c){
	podcast = pod;
	number = num;
	name = n;
	content = c;		
}
void Episode :: play(){
	//cout<<"Episode ";
	cout<<podcast<<", "<<name<<", "<<number<<", "<<content<<endl;
}
void Episode :: print(){
	play();
}
