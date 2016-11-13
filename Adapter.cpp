// Created by Vincent Ma

#include "Adapter.h"

using namespace std;

Adapter::Adapter(int times) {
	this->mTimes = times;
	this->mCounter["black"] = 0;
	this->mCounter["white"] = 0;
}

Adapter::~Adapter() {}

void Adapter::Process() {
	for (int i = 0; i < this->mTimes; i++) {
		Bag bag = Bag();
		
		while (bag.IsDrawable()) {
			bag.DrawBalls();
		}

		this->mCounter[bag.GetResult()]++;
	}
}

map<string, double> Adapter::GetResult() {
	map<string, double> probs;

	probs["black"] = double(this->mCounter["black"]) / double(this->mTimes);
	probs["white"] = double(this->mCounter["white"]) / double(this->mTimes);
	
	return probs;
}
