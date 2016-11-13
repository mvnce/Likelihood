# Created by Vincent Ma

likelihood:
	g++ -std=c++11 main.cpp Bag.h Bag.cpp Adapter.h Adapter.cpp -o likelihood

clean:
	rm *.o *.gch likelihood -f 