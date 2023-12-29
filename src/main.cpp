#include <iostream>
#include "MENU"
using namespace std;


int main(int argc,char**argv) {

	auto app=Gtk::Application::create("org.gtkmm.quizmatematico");

    /*
	//Scelta randomica della domanda
	Funzioni QUIZ;
	QUIZ.CreaDomanda();
	//Stampiamo a video la domanda
	cout << QUIZ << '=';
	//Attendere che l'utente inserisca il risultato
	cin >> QUIZ;
	//Verifica della risposta (corretta o sbagliata)
	if (QUIZ) {
		cout << "\033[32m" << "Bravo";
	} else {
		cout << "\033[31m" << "Studia Testone";
	}
	cout << "\033[0m" << endl;
	*/
	
    return app->make_window_and_run<GUI>(argc,argv);
}
