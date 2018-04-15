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

int wiTi::sum(std::vector<t_job>& jobs) {
	
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

int wiTi::sortByW(std::vector<t_job>& jobs) {

	std::priority_queue<t_job, std::vector<t_job>, compare_jobs_w> j(jobs.begin(), jobs.end());
	std::vector<t_job> j_vec;
	//std::sort(j_vec.begin(), j_vec.end(), compare_jobs_by_w);

	while (!j.empty()) {
		j_vec.push_back(j.top());
		j.pop();
	}

	return wiTi::sum(j_vec);

}

int wiTi::penalty(const t_job& job, const int& finish_time) {

	int penalty = (finish_time - job.d) * job.w;
	return std::max(penalty, 0);

}

int wiTi::dynamicSort(std::vector<t_job>& jobs) {

	int i=0, j=0, k=0,
		toReturn=0;
	const int combinations = (int)std::pow(2.0, (double)jobs.size()) - 1; 	// liczba mozliwych krokow
	int* penalties = new int[combinations + 1];	// tablica przechowujaca wiTi dla danego ciagu


	for (i = 1; i < combinations; i++) {
		int actives = wiTi::numberOfActiveJobs(i, combinations);
		int* actives_array = new int[actives];

		// std::cout << "-> loop " << i << std::endl;

		// zero zadan aktywnych, blad
		if (actives == 0) exit(-1);

		// jedno zadanie aktywne, podstawowy szereg	
		else if (actives == 1) { 
			// std::cout << " * " << "one job active" << std::endl;
			k = 0;
			while (!wiTi::isJobActive(i, k)) k++;	// szuka aktywnego zadania
			// std::cout << "seek for actives" << std::endl;
			actives_array[0] = std::max(jobs.at(k).p - jobs.at(k).d, 0) * jobs.at(k).w;
		}

		// wiecej niz jedno zadanie aktywne
		else if (actives > 1) { 
			// std::cout << " * " << actives << " jobs active" << std::endl;

			// wyznaczanie listy zadan aktywnych
			int* whichActive = new int[actives];
			for (j = 0; j < actives; j++) whichActive[0] = 0;
			k = 0;
			for (j = 0; j < jobs.size(); j++) {
				// std::cout << "j=" << j << std::endl;
				if (wiTi::isJobActive(i,j)) {
					whichActive[k] = j;
					// std::cout << "whichActive[" << k << "] = " << j << std::endl;
					k++;
				}
			}

			int sumOfP = 0;
			for (j = 0; j < actives; j++) {
				// std::cout << "+ sum of p\n\tloop " << j << std::endl;
				// std::cout << "\tsize: " << jobs.size() << std::endl;
				// std::cout << "\tactives: " << actives << std::endl;	
				// std::cout << "\twhichActive[" << j << "]: " << whichActive[j] << std::endl;
				sumOfP += jobs.at(whichActive[j]).p;
			}
			
			k = 0;
			for (j = 0; j < actives; j++) {
				// TODO -- tu cos jest nie tak
				actives_array[j] = std::max(sumOfP - jobs.at(whichActive[j]).d, 0) * jobs.at(whichActive[j]).w + penalties[i ^ (int)std::pow(2.0, (double)whichActive[j])];
				std::cout << "aa = " << penalties[i ^ (int)std::pow(2.0, (double)whichActive[j])] << std::endl;
			}
			delete [] whichActive;
		}

		int minimum = LARGE_NUMBER;

		for (j = 0; j < actives; j++) {

			minimum = std::min(minimum, penalties[i]);
		}		
		// std::cout << minimum << std::endl;
		penalties[i] = minimum;
	}

	toReturn = penalties[combinations-1];
	// std::cout << toReturn << std::endl;
	delete [] penalties;

	return toReturn;

}

int wiTi::numberOfActiveJobs(int& sequence, const int& steps) {
	int i,
		number = 0;

	for (i = 0; (1 << i) < steps; i++)
		number += (sequence >> i) & 1;
	
	return number;
}

bool wiTi::isJobActive(int& sequence, const int& number) {
	return ((sequence >> number) & 1) == 1;
}

int wiTi::numberOfJobs(int& sequence, const int& steps) {
	int i,
		number = 0;

	for (i = 0; (1 << i) < steps; i++)
		number++;
	
	return number;
}