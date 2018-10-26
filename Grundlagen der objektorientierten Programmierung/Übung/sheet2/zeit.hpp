/*
 *  Grundlagen der objektorientierten Programmierung
 *  Hochleistungsrechnen / Softwaretechnologie
 *  Bergische Universitaet Wuppertal
 *
 *  Dieser Header stellt Funktionen fuer zwei Arten von Zeitmessungen zur Verfuegung:
 *
 *  1. Messung der verstrichenen Realzeit
 *
 *  Anwendung:
 *  double start = GetTime();
 *  IrgendEineBerechnung();
 *  double end = GetTime();
 *  print_time_used(start,end); //Gibt zwischen start und end vergangene Zeit aus
 *
 *  2. Messung der CPU-Zeit, also der tatsaechlich vom Programm verbrauchten Rechenzeit ohne
 *     Beruecksichtigung parallel laufender Programme.
 *
 *  Anwendung:
 *  clock_t start = clock();
 *  IrgendEineBerechnung();
 *  clock_t end = clock();
 *  print_time_used(start,end); //Gibt zwischen start und end vergangene Zeit aus
 *
 */

#include <ctime>
#include <iostream>
#include "sys/time.h"

inline double GetTime() {
   struct timeval _tp;

   gettimeofday(&_tp,0);

   return _tp.tv_sec + _tp.tv_usec / 1000000.0;
}

inline void print_time_used(clock_t start, clock_t end) {
  std::cout << difftime(end,start)/CLOCKS_PER_SEC << "s" << std::endl;
}

inline void print_time_used(double start, double end) {
  std::cout << end-start << "s" << std::endl;
}
