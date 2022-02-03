#include<iostream>
#include<string>
#include"Network.h"

Network :: Network(string n){
	name = n;
	sub = new Subscriber*[MAX_SUBS];
	numSubs = 0;
	//numPodarr = 0;
	pod = new PodArray();
}
Network :: ~Network(){
	for(int i =0; i < numSubs; i++){
		delete sub[i];
	}
	delete [] sub;
	delete pod;

}
bool Network :: addPodcast(const string& title, const string& host){
	Podcast *p1 = new Podcast(title, host);
	if(pod->addPodcast(p1))
		return true;
	else
		return false;
}
bool Network :: removePodcast(const string& podcast){
	Podcast *p1;
	if(pod->removePodcast(podcast, &p1)){
		delete p1;
		return true;
	}else{
		return false;
	}

}
bool Network :: addEpisode(const string& podcast, string& title, const string& content){
	Podcast *p;
	getPodcast(podcast, &p);
	if(p->addEpisode(title, content)){
		return true;
	}else{
		return false;
	}
}
bool Network :: addSubscriber(const string& name, const string& creditcard){
	if(numSubs >= MAX_SUBS)
		return false;
	Subscriber *new_sub = new Subscriber(name, creditcard);
	sub[numSubs] = new_sub;
	numSubs++;
	return true;
}
bool Network :: getPodcast(const string& podcast, Podcast** podArr){
	if(pod->getPodcast(podcast, podArr))
		return true;
	else	
		return false;
}
bool Network :: getSubscriber(string& name, Subscriber** subs){
	//for(int i = 0; i<)
	for(int i = 0; i < numSubs; i++){
		if(sub[i]->matches(name)){
			*subs = sub[i];
			return true;
		}
	}
	return false;

}
bool Network :: hasSubscriber(const string& name){
	for(int i = 0; i < numSubs; i++){
		if(sub[i]->matches(name)){
			return true;
		}
	}
	return false;
}
bool Network :: download(const string& subscriber, const string& pod, Podcast** podcast){
 
 if(hasSubscriber(subscriber) && getPodcast(pod, podcast)){
	 return true;
 }else{
	 cout<<"either the podcast or the subscriber does not exist"<<endl;
	 return false;
 }
}
bool Network :: stream(const string& subscriber, const string& pod, int epNum, Episode** episode){
	Podcast *podcast;
	if(hasSubscriber(subscriber) && getPodcast(pod, &podcast)){
		if(podcast->getEpisode(epNum, episode)){
			return true;
		}else{
		cout<<"index out of bound exception"<<endl;
		return false;
		}
		
	}else{
		cout<<"either the episode or the subscriber does not exist"<<endl;
	 	return false;
	}
	
}
void Network :: print(){
	cout<<"Name "<<name<<"numsubs "<<numSubs<<endl;
}
