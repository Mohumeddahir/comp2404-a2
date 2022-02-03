#include<iostream>
#include<string>
#include "Client.h"
using namespace std;

Client :: Client(const string& n){
    name = n;
    p1 = new PodArray();
}
Client :: ~Client(){
    delete p1;

}
void Client :: download(Network* network, const string& podcast){
    Podcast *pod;
    if(network->download(name, podcast, &pod)){
        p1->addPodcast(new Podcast(*pod));
    }else{
        cout<<"the podcast is not in the network class"<<endl;
    }
}
void Client :: stream (Network* network ,string& podcast, int ep){
    Episode *epi;
    if(network->stream(name, podcast, ep, &epi)){
        epi->play();
    }else{
        cout<<"the episode is not in the network class"<<endl;
    }
}
void Client :: playLocal(const string& podcast, int n){
    Podcast *pod;
    if(p1->getPodcast(podcast, &pod)){
        Episode *ep;
        if(pod->getEpisode(n, &ep)){
            ep->play();
        }
    }
}