#include "t_job.hpp"

t_job::t_job() {
    
}

t_job::t_job(const t_job &_job) {
		p = _job.p;
		w = _job.w;
		d = _job.d;
}