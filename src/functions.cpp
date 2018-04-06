#include "functions.hpp"

std::vector<t_job>* load_data(const std::string& filename) {
	int n;	// liczba zadan
	
	std::ifstream file;				// plik z danymi
	std::vector<t_job>* job_list_default = new std::vector<t_job>();

	// ladowanie danych z pliku
	file.open(filename.c_str(), std::ios::in);
	if (file.is_open()) {
		file >> n;

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

int job_wiTi_sum(std::vector<t_job>& jobs) {
	
	int i;			// dla indeksowania
	int C = 0;		// moment zakonczenia i-tego zadania
	int T;			// spoznienie
	int wiTi = 0;	// suma kar / suma wiTi


	for (i = 0; i < jobs.size(); i++) {
		C += jobs.at(i).p;
		T = std::max(C - jobs.at(i).d, 0);
		wiTi += jobs.at(i).w * T;
		
		//std::cout << "index=" << i << std::endl;
		//std::cout << "p=" << jobs.at(i).p << " w=" << jobs.at(i).w << " d=" << jobs.at(i).d << std::endl;
		//std::cout << "C=" << C << " T=" << T << " wiTi=" << wiTi << std::endl;
	}

	return wiTi;
}