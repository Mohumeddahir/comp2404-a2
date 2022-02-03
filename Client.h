#ifndef Client_h
#define Client_h
#include<iostream>
#include<string>
#include "PodArray.h"
#include "Network.h"
using namespace std;
class Client{
	string name;
    PodArray *p1;
    public:
    Client(const string&);
    ~Client();
    void download(Network*, const string&);
    void stream (Network*,string&, int);
    void playLocal(const string&, int);
    void print();
};
#endif
