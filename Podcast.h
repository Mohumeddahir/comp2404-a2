#ifndef Podcast_h
#define Podcast_h
#include<iostream>
#include<string>
#include "Episode.h"
#include"defs.h"

using namespace std;
class Podcast{
	string title;
	string host;
	Episode** e1;
	int numeps;
	public:
	Podcast(string, string);
	Podcast(Podcast &p);
	~Podcast();
	string getTitle();
	string getHost();
	int getNumEpisodes();
	bool addEpisode(string, string);
	bool getEpisode(int index, Episode** ep);
	bool lessThan(Podcast& pod);
	void print();

};

#endif
