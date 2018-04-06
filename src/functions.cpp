#include "functions.hpp"

std::vector<t_job>* load_data(const std::string& filename) {
	int n,	// liczba zadan
		v;	// ilosc parametrow na zadanie (niepotrzebne)
	
	std::ifstream file;				// plik z danymi
	std::vector<t_job>* job_list_default = new std::vector<t_job>();

	// ladowanie danych z pliku
	file.open(filename.c_str(), std::ios::in);
	if (file.is_open()) {
		file >> n;
		file >> v;

		for (int i = 0; i < n; i++) {
			t_job new_job;
			file >> new_job.p >> new_job.w >> new_job.d;
			job_list_default->push_back(new_job);
		}
	}
	else exit(-2);
	file.close();

	return job_list_default;
}