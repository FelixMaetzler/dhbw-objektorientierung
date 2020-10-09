#pragma once
#ifndef GEGNER_H
#define GEGNER_H
#include "Vektoren.h"
#include "Grid.h"

class Gegner {
private:
	double leben;
	double geschwindigkeit;
	Vektoren position;//linke obere Ecke
	Vektoren richtung;
	int naechsterwegpunkt = 0;
	Gosu::Image image;
	

public:


	//Konstruktoren

	//Standartkonstruktor
	//Gegner(void);
	Gegner(void);

	//Konstruktor f�r Leben und Geschwindigkeit
	Gegner(int l, double g);
	
	

	//Destruktor
	~Gegner(void);

	//Get/Set Methoden:

	double get_leben(void)const;
	void set_leben(const double);
	double get_geschwindigkeit(void)const;
	void set_geschwindigkeit(const double);
	int get_x(void)const;
	void set_x(const int);
	int get_y(void)const;
	void set_y(const int);
	Vektoren get_richtung(void)const;
	void set_richtung(Vektoren, double = 1);
	Vektoren get_position(void)const;
	void set_position(const Vektoren);
	int get_naechsterwegpunkt(void)const;
	void set_naechsterwegpunkt(const int);
	Gosu::Image get_image(void)const;
	void set_image(const string);


	//andere Methoden

	//setzt die Richtung des Gegners zu dem als Argument angegebenen Punkrt
	void RichtungZuPunkt(const Vektoren);

	void Zeichnen(void)const;
	//Diese Funktion sorgt daf�r, dass der Gegner den richtigen Weg abf�hrt. Daf�r wird die Richtung gesetzt
	void wegpunkt(vector<Kachel>);
	//Zieht die Anzahl an Leben ab
	void lebenAbziehen(double);
	//Wenn der gegner das Ende des Paths erreicht hat
	void endeErreicht(void);
	virtual Gegner* schwaecherenGegnerSpawnen(Vektoren, int) = 0;
	
};


#endif // !GEGNER_H
