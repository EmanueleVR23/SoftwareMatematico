#include "GUI.h"

GUI::GUI() :
	Contenitore_di_gioco(Orientation::HORIZONTAL, 5),		//Parametri cotruttore box con orientamento di 5 pixel di distanza tra gli elementi che si concatenano orizzontalmente
	Domanda(QUIZ.CreaDomanda(), Align::CENTER)				//Parametri costruttore label con allineamento al centro della box in cui è contenuto

{
    set_title("QuizMatematico");      					    //Nome della finestra
    set_default_size(1280,720);         					//Setta la dimensione della finestra in pixel
    Contenitore_di_gioco.set_halign(Align::CENTER);			//Allineamento al centro orizzontale dei widget sulla finestra
    Contenitore_di_gioco.set_valign(Align::CENTER);			//E verticale
    set_child(Contenitore_di_gioco);						//Setto il figlio della finestra, ovvero il contenitore sarà nella finestra
    Contenitore_di_gioco.append(Domanda);					//Contenuto della box
    Contenitore_di_gioco.append(Risposta);
    Bottone.signal_clicked().connect(sigc::mem_fun(*this,&GUI::Enter));
    Contenitore_di_gioco.append(Bottone);
    
	auto cssProvider = Gtk::CssProvider::create();
	cssProvider->load_from_path("style.css");

	auto styleContext = this->get_style_context();

	//get default screen
	auto screen = this->get_display();

	//add provider for screen in all application
	styleContext->add_provider_for_display(screen, cssProvider, GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
    
}

void GUI::Enter(){
	string marco=Risposta.get_text();

	if(all_of(marco.begin(),marco.end(),::isdigit) || ((marco[0]=='-' || marco[0]=='+') && all_of(std::next(marco.begin(),1),marco.end(),::isdigit))){
		QUIZ.risposta=stoi(marco);
		if (QUIZ) {
			std::cout << "\033[32m" << "Bravo";
			Bottone.set_label("Bravo");
			Domanda.set_label(QUIZ.CreaDomanda());
			Risposta.set_text("");
		} else {
			std::cout << "\033[31m" << "Studia Testone";
			Bottone.set_label("Testa di QUIZ!");
			Risposta.set_text("");
		}
	std::cout<<"\033[0m\n";
	}else{
	Bottone.set_label("Testa di QUIZ!");
	Risposta.set_text("");	
	}
}

