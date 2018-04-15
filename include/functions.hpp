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
#include <cmath>

#include <bitset>

#include "t_job.hpp"

#define LARGE_NUMBER 999999999

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
 * Funkcje dotyczace jednomaszynowego problemu wiTi.
 */
namespace wiTi {

/**
 * Zwraca sume wiTi dla podanej permutacji.
 * 
 * @param lista zadan
 * @return suma wiTi
 */
int sum(std::vector<t_job>& jobs);

/**
 * Zwraca sume wiTi dla zadania posortowanego wedlug w (wspolczynnika kary) malejaco.
 *  
 * @param lista zadan
 * @return suma wiTi
 */
int sortByW(std::vector<t_job>& jobs);

/**
 * Zwraca wspolczynnik kary dla danego zadania przy podanym czasie jego zakonczenia.
 * 
 * @param lista zadan
 * @param czas zakonczenia
 * @return wspolczynnik kary
 */
int penalty(const t_job& job, const int& finish_time);

/**
 * Realizuje algorytm sortowania dynamicznego.
 * 
 * @param lista zadan
 * @return suma wiTi (wspolczynnikow kar)
 */
int dynamicSort(std::vector<t_job>& jobs);

/**
 * Podaje, ile zadan w ciagu binarnym jest aktywnych.
 * 
 * @param aktualny ciag
 * @param maksymalna liczba krokow
 * @return liczba aktywnych zadan
 */
int numberOfActiveJobs(int& sequence, const int& steps);

/**
 * Podaje, czy zadanie o danym numerze jest aktywne.
 * 
 * @param aktualny ciag
 * @param numer zadania
 * @return czy zadanie jest aktywne
 */
bool isJobActive(int& sequence, const int& number);

/**
 * Podaje, ile zadan jest w podanym ciagu binarnym.
 * 
 * @param aktualny ciag
 * @param maksymalna liczba krokow
 * @return liczba aktywnych zadan
 */
int numberOfJobs(int& sequence, const int& steps);

}
#endif //FUNCTIONS_H