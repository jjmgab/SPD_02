#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <vector>
#include <functional>

#include <stdlib.h>

#include "functions.hpp"
#include "t_job.hpp"
#include "time_fun.hpp"


int main() {

	std::string names = "data/names.txt",	// nazwa listy nazw plikow
				output = "output.txt";		// nazwa pliku z danymi wyjsciowymi

	std::ifstream file_names;				// strumien wejsciowy do wczytywania nazw plikow

	std::filebuf file;						// plik z danymi wyjsciowymi
	file.open(output.c_str(), std::ios::out);
	std::ostream loader(&file);				// strumien wyjsciowy, zamiast std::cout

	int number_of_files = 0,				// potrzebne przy wczytywaniu danych z plikow, l. plikow
		i;									// indeks do petli

	// otwarcie listy nazw plikow
	file_names.open(names.c_str());
	if (file_names.is_open()) {
		file_names >> number_of_files;
	}
	else exit(-1);
	
	int x = 0b11111;
	int y = 0b00100;

	std::cout << std::bitset<5>(x ^ (int)std::pow(2.0, 2.0)) << std::endl;

/*
	// dla kazdego pliku na liscie
	for (i = 0; i < number_of_files; i++) {

		// wczytuje nazwe pliku
		std::string filename = "";
		file_names >> filename;
		
		// wczytuje dane z pliku
		std::vector<t_job>* job_list_default = load_data("data/"+filename+".txt");
		std::cout << filename << std::endl;

		loader << filename << std::endl;
		// suma wiTi dla nieuszeregowanej listy zadan
		loader << wiTi::sum(*job_list_default) << std::endl;
		// suma wiTi dla posortowanej po w malejaco listy zadan
		loader << wiTi::sortByW(*job_list_default) << std::endl;
		// suma wiTi dla sortowania dynamicznego
		loader << wiTi::dynamicSort(*job_list_default) << std::endl;



		// wykonywanie sie poszczegolnych algorytmow
		//int time;

		// std::cout << filename << std::endl;
		// loader << filename << std::endl;

		// time = measure_time(job_algorithm, job_list_default, loader);
		// loader << time << std::endl;


		delete job_list_default;
	}
*/
	file_names.close();

	return 0;
}