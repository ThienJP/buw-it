/****************************************/
/* Thien Ngo  */
/* Matrikel: 1857010 */
/* Uebungsblatt: 12, Aufgabe: 38 */
/* Datum: 16.01.2019 */
/****************************************/
#include "vereine.hpp"

using namespace std;

Verein::Verein(string name, int goals, int enemyGoals, int points) {
  Verein::name = name;
  Verein::goals = goals;
  Verein::enemyGoals = enemyGoals;
  Verein::points = points;
}

Verein::~Verein() {}

const string& Verein::getName() const {
  return name;
}

int Verein::getGoals() const {
  return goals;
}

int Verein::getEnemyGoals() const {
  return enemyGoals;
}

int Verein::getPoints() const {
  return points;
}

bool Verein::operator==(const Verein& rhs) const {
  return name == rhs.name;
}

bool Verein::operator<(const Verein& rhs) const {
  return name < rhs.name;
}

ostream& operator<< (ostream &out, const Verein &verein) {
  out << setw(20) << left << verein.name << verein.goals << ":" << setw(3) << left << verein.enemyGoals
      << setw(6) << right << verein.goals - verein.enemyGoals
      << setw(6) << right << verein.points;

  return out;
}

void Verein::setGoals(int goals) {
  Verein::goals = goals;
}

void Verein::setEnemyGoals(int enemyGoals) {
  Verein::enemyGoals = enemyGoals;
}

void Verein::setPoints(int points) {
  Verein::points = points;
}


Liga::Liga(string name) : Verein(name) {
  Liga::name = name;
}

Liga::~Liga() {}

void Liga::verein_hinzufuegen(Verein& verein) {
  vereine.push_back(verein);
}

void Liga::verein_entfernen(Verein& verein) {

  vereine.erase(find(vereine.begin(), vereine.end(), verein.getName()) );
}

struct Liga::sortBy {
    int category;
    sortBy(int category) {
      this->category = category;
    }

    bool operator() (const Verein& L, const Verein& R) const {
      switch (category) {
        case 1: return L.getName() < R.getName();
          break;
        case 2: return L.getPoints() > R.getPoints();
          break;
        case 3: return (L.getGoals() - L.getEnemyGoals()) > (R.getGoals() - R.getEnemyGoals());
          break;
        default: return false;
          break;
      }
    }
};

void Liga::sortieren(int category) {
  switch (category) {
    case 1: vereine.sort(sortBy(1));
      break;
    case 2: vereine.sort(sortBy(2));
      break;
    case 3: vereine.sort(sortBy(3));
      break;
    default: break;
  }
}

ostream& operator<< (ostream& out, const Liga &liga) {
  out << liga.name << endl;
  out << "Vereine: " << endl;

  int j = 1;
  for (const auto& i : liga.vereine) {
    out << j << ".   ";
    out << i << endl;
    j++;
  }

  return out;
}

void neueSaison(Liga &L, Liga&R) {
  auto it = L.vereine.begin();
  // last 2 elements
  advance(it, L.vereine.size() - 2);

  swap_ranges(it, L.vereine.end(), R.vereine.begin() );

  // reset goals, enemyGoals and points
  for (auto i = L.vereine.begin(); i != L.vereine.end(); ++i) {
    (*i).setGoals(0);
    (*i).setEnemyGoals(0);
    (*i).setPoints(0);
  }

  for (auto i = R.vereine.begin(); i != R.vereine.end(); ++i) {
    (*i).setGoals(0);
    (*i).setEnemyGoals(0);
    (*i).setPoints(0);
  }
}