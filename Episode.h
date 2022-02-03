#ifndef Episode_h
#define Episode_h
#include<iostream>
#include<string>
using namespace std;
class Episode{
	//friend class Podcast;
	string name;
	string content;
	string podcast;
	int number;
	public:
	Episode();
	Episode(Episode&);
	Episode(const string&, int, const string&, const string&);
	void play();
	void print();
};
#endif
