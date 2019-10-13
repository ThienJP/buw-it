//
// Created by Thien Ngo on 17.12.18.
//

#ifndef POLYMORPHIE_KLIMA_H
#define POLYMORPHIE_KLIMA_H

#include <iostream>
#include <iomanip>
#include <string>
#include <ssteram>
#include <fstream>
#include <vector>

class Klima {
private:
    string city;
    vector<double> temp;
    vector<double> rain;
    ifstream dataStream;
public:
    // opens file and parse line by line and store to corresponding vector
    Klima(string filename, Ausgabe * obj);
    ~Klima() {}
    setAusgabe();
};

#endif //POLYMORPHIE_KLIMA_H
