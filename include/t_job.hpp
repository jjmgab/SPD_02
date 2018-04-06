#ifndef TJOB_H
#define TJOB_H


/**
 * Klasa definiujaca zadanie. 
 */
class t_job {
public:
	int p,	// 
		w,	// 
		d;	// 

	t_job();
	t_job(const t_job &_job);


	// /**
	//  * Operator porownania ze wzgledu na dlugosc
	//  * czasu przygotowywania zadania.
	//  * 
	//  * @param referencja na zadanie
	//  * @return czy zadanie jest rowne
	//  */
	// bool operator==(const t_job &_job) {
	// 	return this->r == _job.r;
	// }
};



// struct compare_jobs_r {

// 	bool operator()(const t_job& job1, const t_job& job2){
// 		if (job1.r > job2.r) return true;
// 		return false;
// 	}

// };

#endif //TJOB_H