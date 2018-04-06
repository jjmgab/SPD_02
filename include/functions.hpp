#ifndef FUNCTIONS_H
#define FUNCTIONS_H


#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <string>
#include <limits>
#include <queue>

#include "t_job.hpp"


/**
 * Wczytuje dane z podanego pliku do zaalokowanego wektora zadan,
 * na ktory wskaznik nastepnie zwraca.
 * 
 * @param nazwa pliku
 * @return wskaznik na wektor zadan
 */
std::vector<t_job>* load_data(const std::string& filename);

#endif //FUNCTIONS_H