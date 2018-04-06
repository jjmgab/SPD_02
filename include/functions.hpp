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

/** * * * * * * * * * * * * * * * * * * * * * * *
 *                                              *
 *     FUNKCJE DO PRZETWARZANIA LIST ZADAN      *
 *                                              *
 * * * * * * * * * * * * * * * * * * * * * * * **/



/**
 * Wczytuje dane z podanego pliku do zaalokowanego wektora zadan,
 * na ktory wskaznik nastepnie zwraca.
 * 
 * @param nazwa pliku
 * @return wskaznik na wektor zadan
 */
std::vector<t_job>* load_data(const std::string& filename);

/**
 * Zwraca sume wiTi dla podanej permutacji.
 * 
 * @param lista zadan
 * @return suma wiTi
 */
int job_wiTi_sum(std::vector<t_job>& jobs);

#endif //FUNCTIONS_H