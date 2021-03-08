
#ifndef PTIME_H
#define PTIME_H

/*
BIBLIOTECA DE AUTORIA PRÓPRIA

FELIPE SENA DE MEDEIROS
last updated: 11/12/20
*/

#include <ostream>
#include <chrono>
#include <map>

using namespace std::chrono;

template <class cast>
class ptime
{
private:
	std::map<int, time_point<high_resolution_clock>> points;
	int current_point = 0;
public:
	ptime()
	{}

	using time_iterator = typename std::map<int, time_point<high_resolution_clock>>::iterator;

	time_iterator begin()
	{
		return this->points.begin();
	}

	time_iterator end()
	{
		return this->points.end();
	}

	void start()
	{
		this->current_point = 0;
		this->points.clear();
		this->points[this->current_point] = this->now();
	}

	void restart()
	{
		this->start();
	}

	int point()
	{
		this->current_point++;
		this->points[this->current_point] = this->now();

		return this->current_point;
	}

	double elapsed(int point)
	{
		if (point < 1)
		{
			return 0;
		}
		return duration_cast<cast>(this->points[point] - this->points[point - 1]).count();
	}

	double elapsed()
	{
		if (this->current_point < 1)
		{
			return 0;
		}
		return duration_cast<cast>(this->now() - this->points[this->current_point]).count();
	}

	double between(int begin, int end)
	{
		if (begin < 0 || end > this->current_point)
		{
			return -1;
		}
		return duration_cast<cast>(this->points[end] - this->points[begin]).count();
	}

	double total()
	{
		return duration_cast<cast>(this->now() - this->points[0]).count();
	}

	time_point<high_resolution_clock> now()
	{
		return high_resolution_clock::now();
	}

	friend std::ostream& operator<<(std::ostream& o, time_iterator p)
	{
		o << duration_cast<cast>(p).count();

		return o;
	}
};

#endif