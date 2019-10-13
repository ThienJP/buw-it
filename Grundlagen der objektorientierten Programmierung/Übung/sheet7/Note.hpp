/****************************************/
/* Thien Ngo  */
/* Matrikel: 1857010 */
/* Uebungsblatt: 07, Aufgabe: 21 */
/* Datum: 26.11.2018 */
/****************************************/

#ifndef NOTE_HPP
#define NOTE_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

class Note {
private:
    string subject;
    int cp;
    double grade;
public:
    Note(string subj, int credits, double grd);
    ~Note();
    string getSubject() const;
    int getCP() const;
    double getGrade() const;
    friend std::ostream& operator << (std::ostream& os , const Note& grade);
};

#endif
