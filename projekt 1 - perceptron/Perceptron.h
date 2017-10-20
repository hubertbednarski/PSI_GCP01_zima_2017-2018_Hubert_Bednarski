#pragma once
#include <iostream>

#define LEARNING_RATE    0.2
#define MAX_ITERATION    16

using namespace std;



class Perceptron {
public:
	static const int liczba_zmiennych = 2;//liczba zmiennych, w tym przypadku - x oraz y
	static const int liczba_testow = 80;//liczba zestawow testujacych (w tym przypadku 
private:
	double x[liczba_testow];
	double y[liczba_testow];
	int wynik[liczba_testow];
	double localError;
	double globalError;
	double waga[liczba_zmiennych+1];//[0]-waga x; [1]-waga y; [2] - bias
	int iteracje = 0;
	//??int klasa;

public:
	double losuj_punkty();
	double losuj_wagi();//w przedziale 0-1 do 3 miejsc po przecinku
	//double funkcja_sumujaca(int liczba_zmiennych_wejsciowych);
	int funkcja_sumujaca_i_aktywujaca(int);
	int nauczanie();
	int sprawdz_wartosc();
};