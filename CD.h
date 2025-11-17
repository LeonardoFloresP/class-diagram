#ifndef CD_H
#define CD_H

#include "Media.h"
#include <iostream>

using namespace std;

class CD : public Media {
private:
    string artist;
    int duration; 

public:

    CD(string t, string a, int d) : Media(t), artist(a), duration(d) {}

    string getArtist() const { return artist; }


    void printInfo() const override {
        cout << "CD Title: " << title << " | Artist: " << artist << " | Duration: " << duration << " mins." << endl;
    }
};

#endif // CD_H
