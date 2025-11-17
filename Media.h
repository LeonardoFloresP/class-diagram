#ifndef MEDIA_H
#define MEDIA_H

#include <string>
#include <iostream>

using namespace std;

class Media {
protected:

    string title; 

public:

    Media(string t) : title(t) {}
    

    virtual ~Media() {} 

    string getTitle() const { return title; }


    virtual void printInfo() const = 0; 
};

#endif // MEDIA_H
