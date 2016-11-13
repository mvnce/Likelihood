// Created by Vincent Ma

#include <string>
#include <map>
#include "Bag.h"

class Adapter {
public:
	Adapter(int);
	virtual ~Adapter();

	void Process();
	std::map<std::string, double> GetResult();

private:
	int mTimes;
	std::map<std::string, int> mCounter;
};
