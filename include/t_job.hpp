#ifndef TJOB_H
#define TJOB_H


/**
 * Klasa definiujaca zadanie. 
 */
class t_job {
public:
	int p,	// czas wykonania
		w,	// wspolczynnik kary
		d;	// zadany termin zakonczenia

	t_job();
	t_job(const t_job &_job) : p(_job.p), w(_job.w), d(_job.d) {};
};


/**
 * Przeciazenie operatora mniejszosci.
 * 
 * Uzywany przez kolejke priorytetowa ktora sortuje
 * zadania wg. w malejaco.
 */
struct compare_jobs_w {

	bool operator()(const t_job& job1, const t_job& job2){
		if (job1.w < job2.w) return true;
		return false;
	}

};

#endif //TJOB_H