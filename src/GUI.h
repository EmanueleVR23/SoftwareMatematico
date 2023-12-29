#include <gtkmm.h>
#include "Funzioni.h"
#include <iostream>
using namespace Gtk;

#ifndef SOFTWAREMATEMATICO_GUI_H
#define SOFTWAREMATEMATICO_GUI_H


class GUI:public Gtk::Window{
private:
		Funzioni QUIZ;

public:
    GUI();
    
protected:
	Box Contenitore_di_gioco;
	Label Domanda;
	Entry Risposta;
	Button Bottone;
	void Enter();
	
};


#endif //SOFTWAREMATEMATICO_GUI_H
