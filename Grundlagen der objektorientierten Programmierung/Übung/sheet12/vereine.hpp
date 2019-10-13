/****************************************/
/* Thien Ngo  */
/* Matrikel: 1857010 */
/* Uebungsblatt: 12, Aufgabe: 38 */
/* Datum: 16.01.2019 */
/****************************************/

#ifndef VEREINE_HPP
#define VEREINE_HPP

#include <string>
#include <list>
#include <algorithm>
#include <iomanip>

using namespace std;

class Verein {
protected:
    string name;
    int goals;
    int enemyGoals;
    int points;
public:
    Verein(string name, int goals = 0, int enemyGoals = 0, int points = 0);
    ~Verein();

    const string &getName() const;
    int getGoals() const;
    int getEnemyGoals() const;
    int getPoints() const;
    void setGoals(int goals);
    void setEnemyGoals(int enemyGoals);
    void setPoints(int points);
    bool operator==(const Verein& rhs) const;
    bool operator<(const Verein& rhs) const;
    friend ostream& operator<< (ostream &out, const Verein &verein);
};

class Liga : public Verein {
private:
    string name;
    list<Verein> vereine;
public:
    Liga(string name);
    ~Liga();

    void verein_hinzufuegen(Verein& verein);
    void verein_entfernen(Verein& verein);
    struct sortBy;
    void sortieren(int category = 1);
    friend ostream& operator<< (ostream& out, const Liga &liga);
    friend void neueSaison(Liga &L, Liga&R);
};

#endif //VEREINE_HPP
