#ifndef Network_h
#define Network_h
#include<iostream>
#include<string>

#include "Subscriber.h"
#include "Episode.h"
#include "defs.h"
#include "PodArray.h"
#include "Podcast.h"

//#include "Subscriber.h"

class Network{
	string name;
	PodArray *pod;
	Subscriber **sub;
	int numSubs;
	//int numPodarr;
	public:
	Network(string n);
	~Network();
	bool addPodcast(const string&, const string&);
	bool removePodcast(const string&);
	bool addEpisode(const string&, string&, const string&);
	bool addSubscriber(const string&, const string&);
	bool getPodcast(const string&, Podcast**);
	bool getSubscriber(string&, Subscriber**);
	bool hasSubscriber(const string&);
	bool download(const string&, const string&, Podcast**);
	bool stream(const string&, const string&, int, Episode**);
	void print();
	
};
#endif
