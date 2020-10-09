#include "stdafx.h"
#include "zweiteFigur.h"


zweiteFigur::zweiteFigur(void) {
	this->set_attackspeed(0);
	this->set_damage(0);
	this->set_image("Eisberg.png");
	this->set_price(100);
	this->set_range(200);
	this->set_slowrate(0.5);
	this->set_audio("Eisberg.wav");

}

void zweiteFigur::set_slowrate(const double sl) {
	this->slowrate = sl;
}
double zweiteFigur::get_slowrate(void) const {
	return this->slowrate;
}

void zweiteFigur::gegnerinrange(vector<Gegner*>* liste_ptr) {
	Vektoren d;
	auto t = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - this->get_zeitstempel()).count();
	for (int i = 0; i < liste_ptr->size(); i++)
	{
		d = liste_ptr->at(i)->get_position() - this->get_position();
		if (d.laenge() <= this->get_range())
		{
			liste_ptr->at(i)->set_richtung(liste_ptr->at(i)->get_richtung(), this->get_slowrate());
			if (t > 4000/1.3)
			{
				this->get_audio().play(1, 1.3);
				this->set_zeitstempel(std::chrono::steady_clock::now());
			}

		}
	}
}
void zweiteFigur::Zeichnen(void) {
	//this->get_image().draw_rot(this->get_x(), this->get_y(), 50, 0, 0.5, 0.5);
	this->get_image().draw(this->get_x(), this->get_y(), 50);
}