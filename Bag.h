// Created by Vincent Ma
#include <string>
#include <vector>
#include <map>

struct Ball {
	std::string color;
};

class Bag {
public:
	Bag();
	virtual ~Bag();

	int RandomNumber(int);
	int GetCount(std::string);
	void DrawBalls();
	bool IsDrawable();
	std::string GetResult();

private:
	std::vector<Ball> mBalls;
};

