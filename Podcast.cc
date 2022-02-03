#include<iostream>
#include<string>
#include"Podcast.h"
using namespace std;
Podcast :: Podcast(string t, string h){
	title= t;
	host = h;
	e1 = new Episode* [MAX_EPS];
	numeps = 0;
}
Podcast :: ~Podcast(){
	for (int i = 0; i < numeps; ++i){
		delete e1[i];
	}
	delete [] e1;
}
Podcast :: Podcast(Podcast &p){
	title = p.title;
	host = p.host;
	numeps = p.numeps;
	e1 = new Episode* [MAX_EPS];
	
	for(int i = 0; i < p.numeps; i++){
		//e1[i] = new Episode(p.e1[i]->podcast, p.e1[i]->number, p.e1[i]->name, p.e1[i]->content);
		e1[i] = new Episode(*(p.e1[i]));
	}
	
	
}
string Podcast :: getTitle(){ 
	return title;
	}
string Podcast :: getHost(){
	return host;
	}
int Podcast :: getNumEpisodes(){
	return numeps;
}
bool Podcast :: addEpisode(string title, string content){
	if(numeps >= MAX_EPS){
		return false;
	}else{
		
		Episode *new_ep = new Episode(this->title, numeps+1, title, content);
		e1[numeps] = new_ep;
		numeps++;
		return true;
	}
}
bool Podcast :: getEpisode(int index, Episode** ep){
	if(index<0 || index >= numeps)
		return false;
	else{
		*ep = e1[index];
		return true;
	}
}
bool Podcast :: lessThan(Podcast& pod){
	if(this->title < pod.title)
		return true;
	else
		return false;
}
void Podcast :: print(){
	cout<<title<<", "<<host<<endl;
}
