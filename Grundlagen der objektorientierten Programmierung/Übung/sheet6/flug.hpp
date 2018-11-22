/****************************************/
/* Thien Ngo  */
/* Matrikel: 1857010 */
/* Uebungsblatt: 06, Aufgabe: 18 */
/* Datum: 21.11.2018 */
/****************************************/
#ifndef FLUGHPP
#define FLUGHPP

using namespace std;

class Buchung {
private:
    string passenger;
    string seat;
public:
    Buchung(string name, string seated) : passenger(name), seat(seated) { }
    ~Buchung() { }

    struct buchung_reserved_seat {
    public:
        buchung_reserved_seat(string const& s) : seated(s) { }
        bool operator () (Buchung const& b) {
          return b.seat == seated;
        }
    private:
        string seated;
    };

    const string &getPassenger() const {
      return passenger;
    }

    const string &getSeat() const {
      return seat;
    }

    void setSeat(const string &seat) {
      Buchung::seat = seat;
    }

    friend std::ostream& operator << (std::ostream& os, const vector<Buchung>& bookings) {
      for(auto i = 0; i != bookings.size(); ++i) {
        cout << setw(16) << bookings[i].getPassenger() << " " << setw(4) << bookings[i].getSeat() << endl;
      }

      return os;
    }
};

class Flug {
private:
    string airline;
    string departure;
    string arrival;
    unsigned seats;
private:
    vector< Buchung > bookings;
    unsigned bookingsCount = 0;
public:
    Flug(string airl, string dep, string arrive, unsigned seatCount) : airline(airl), departure(dep), arrival(arrive), seats(seatCount) {
      vector< Buchung > bookings;
    }
    ~Flug() {
      // vector deletes itself when object gets destroyed
      cout << "Vector deleted and object destroyed" << endl;
    }

    void addBuchung(const Buchung& booking) {
      if (bookingsCount < seats) {

        bookings.push_back(booking);
        decSeats();
      } else {
        cout << "Flug ausgebucht!";
      }
    }

    void umbuchen(string oldS, string newS) {
      // find the passenger object that has the seat reserved
      auto it = find_if(bookings.begin(), bookings.end(), Buchung::buchung_reserved_seat(oldS));
      if (it != bookings.end()) {
        auto idx = distance(bookings.begin(), it);
        // when found update that corresponding seat attribute to newS
        bookings[idx].setSeat(newS);
      } else {
        cout << "Seat is not occupied" << endl;
      }
    }

    void decSeats() {
      --seats;
    }

    unsigned int getSeats() const {
      return seats;
    }

    friend std::ostream& operator << (std::ostream& os, const Flug& flug) {
      os << flug.airline << "  " << flug.departure << "  " << flug.arrival << "  " << flug.seats << endl;
      // and print all bookings
      cout << flug.bookings;

      return os;
    }
};

#endif