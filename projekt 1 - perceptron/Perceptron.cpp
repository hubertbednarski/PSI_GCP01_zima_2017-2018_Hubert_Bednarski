#include <ctime>
#include <cstdlib>

#include "Perceptron.h"

double Perceptron::losuj_punkty() {
	srand(time(NULL));
	for (int i = 0; i < liczba_testow; ++i) {
		if (i % 2 == 0) {
			x[i] = (rand() % (35 - -15) + 1) - 15;
			x[i] /= 10;
			y[i] = (rand() % (35 - -15) + 1) - 15;// (rand() % (max-min)+1)+min
			y[i] /= 10;
			wynik[i] = 0;
			cout << x[i] << "\t" << y[i] << "\t" << wynik[i] << endl;
		}
		else {
			x[i] = (rand() % (90 - 40) + 1) + 40;
			x[i] /= 10;
			y[i] = (rand() % (90 - 40) + 1) + 40;
			y[i] /= 10;
			wynik[i] = 1;
			cout << x[i] << "\t" << y[i] << "\t" << wynik[i] << endl;
		}
	}
	return 0;
}

double Perceptron::losuj_wagi() {
	srand(time(NULL));
	for (int i = 0; i <= liczba_zmiennych; ++i) {
		waga[i] = (double)(rand() % 1000) / 1000;
		//cout << waga[i] << endl;
	}
	return 0;
}

/*double Perceptron::funkcja_sumujaca(int liczba_zmiennych_wejsciowych) {//jako liczba zmiennych wejsciowych bedzie liczba testow
	double suma = 0;
	for (int i = 0; i < liczba_zmiennych_wejsciowych; ++i) {
		suma += x[i] * waga[0] + y[i] * waga[1] + waga[2];
	}
	return suma;
}*/

int Perceptron::funkcja_sumujaca_i_aktywujaca(int index){
	double suma = 0;
	suma += x[index] * waga[0] + y[index] * waga[1] + waga[2];
	if (suma >= 0)
		return 1;
	else
		return 0;
}

int Perceptron::nauczanie() {
	int wynik;
	do {
		globalError = 0;
		iteracje++;
		for (int i = 0; i < MAX_ITERATION; i++)
		{
			wynik = funkcja_sumujaca_i_aktywujaca(i);

			localError = this->wynik[i] - wynik;

			waga[0] += LEARNING_RATE * localError * x[i];
			waga[1] += LEARNING_RATE * localError * y[i];
			waga[2] += LEARNING_RATE * localError;
			globalError += (localError*localError);
		}
		cout << "Liczba iteracji:\t" << iteracje << "\nBlad obliczen:\t\t" << sqrt(globalError / MAX_ITERATION) << endl << endl;

	} while (globalError !=0 && iteracje <= MAX_ITERATION);


	cout << "Wagi koncowe, otrzymane po nauczaniu:\t" << waga[0] << "\t" << waga[1] << "\t" << waga[2] << endl;
	return 0;
}

int Perceptron::sprawdz_wartosc() {
	int wartosc;
	double x, y;
	cout << "Podaj x: " << endl;
	cin >> x;
	//x *= 10;
	cout << "Podaj y: " << endl;
	cin >> y;
	//y *= 10;
	double suma = 0;
	suma += x * waga[0] + y * waga[1] + waga[2];
	if (suma >= 0)
		wartosc = 1;
	else
		wartosc = 0;
	cout << "Wartosc dla podanych punktow wyniesie: " << wartosc << endl;
	return wartosc;
}