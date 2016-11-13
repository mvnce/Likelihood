// Created by Vincent Ma
#include <algorithm>
#include <random>
#include "Bag.h"

using namespace std;

/**
* \brief Constructor
* \push 25 black balls and 25 white balls into bag
*/
Bag::Bag() {
	for (int i = 0; i < 25; i++) {
		Ball ball_a = Ball();
		ball_a.color = "black";
		Ball ball_b = Ball();
		ball_b.color = "white";

		this->mBalls.push_back(ball_a);
		this->mBalls.push_back(ball_b);
	}
	random_shuffle(this->mBalls.begin(), this->mBalls.end());
}

/** \brief Destructor */
Bag::~Bag() {}

/**
* \brief get random integer number from
* \param max_num the random number range [0, max_num]
*/
int Bag::RandomNumber(int max_num) {

	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(0, max_num);
	return distribution(generator);
}

/**
* \brief draw two balls from bag
*/
void Bag::DrawBalls() {
	// pull first ball out and remove it from the list to prevent same choice
	int index = this->RandomNumber(this->mBalls.size() - 1);
	Ball ball_a = this->mBalls[index];
	this->mBalls.erase(this->mBalls.begin() + index);

	index = this->RandomNumber(this->mBalls.size() - 1);
	Ball ball_b = this->mBalls[index];
	this->mBalls.erase(this->mBalls.begin() + index);
	
	// two black balls (push balls back)
	if (ball_a.color == ball_b.color && ball_a.color == "black") {
		this->mBalls.insert(this->mBalls.end(), {ball_a, ball_b});
		random_shuffle(this->mBalls.begin(), this->mBalls.end());
	}
	// two white balls (no push back)
	else if (ball_a.color == ball_b.color && ball_a.color == "white") {
		random_shuffle(this->mBalls.begin(), this->mBalls.end());
	}
	// one black ball and one white ball
	else {
		if (ball_a.color == "white") {
			this->mBalls.push_back(ball_a);
		}
		else {
			this->mBalls.push_back(ball_b);
		}
		random_shuffle(this->mBalls.begin(), this->mBalls.end());
	}
}

/**
* \brief check number of balls in same color
* \param color string of color name
*/
int Bag::GetCount(string color) {
	int count = 0;
	for (auto ball : this->mBalls) {
		if (ball.color == color) {
			count++;
		}
	}
	return count;
}

/**
* \brief check the bag is drawable or not
*/
bool Bag::IsDrawable() {
	if (this->mBalls.size() > 1) {
		return true;
	}
	return false;
}

std::string Bag::GetResult() {
	int black_cnt = this->GetCount("black");
	int white_cnt = this->GetCount("white");

	if (black_cnt == 1 && white_cnt == 0) {
		return "black";
	}
	else {
		return "white";
	}
}
