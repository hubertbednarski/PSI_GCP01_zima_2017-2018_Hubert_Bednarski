#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Perceptron.h"

using namespace std;

int main() {
	//srand(time(NULL));

	Perceptron * p = new Perceptron();

	p->losuj_punkty();
	p->losuj_wagi();
	p->nauczanie();

	//p->sprawdz_wartosc();

	system("pause");
	return 0;
}