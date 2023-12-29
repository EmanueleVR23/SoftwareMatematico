#include "Funzioni.h"


Funzioni::Funzioni() {
    srand(time(NULL));
    correzione=0;
    risposta=0;
}

Glib::ustring Funzioni::CreaDomanda() {
    int x=rand()%range+1;    //primo numero per operazione
    int y=rand()%range+1;    //Secondo numero per operazione
    char operatori[]={'x',':','+','-'};
    int z=rand()%4;    		 //numero indice operatore

    domanda= to_string(x);          //Conversione implicita di un intero a carattere
    domanda+=operatori[z];   	    //Aggiunta dell'operatore per l'operazione
    domanda+= to_string(y);         //Conversione implicita di intero a carattere per il secondo termine


    //Controllo operazione
    if(operatori[z]=='x'){
        correzione=x*y;
    }
    else if(operatori[z]==':'){
        //Siccome il programma dava da fare anche divisioni a risultato reale facciamo in modo che non accada
        while(x%y!=0){
            x=rand()%range+1;
            y=rand()%range+1;
        }
        correzione=x/y;

        domanda= to_string(x);          //Conversione implicita di un intero a carattere
        domanda+=operatori[z];    //Aggiunta dell'operatore per l'operazione
        domanda+= to_string(y);         //Conversione implicita di intero a carattere per il secondo termine
    }
    else if(operatori[z]=='+'){
        correzione=x+y;
    }else{
        correzione=x-y;
    }
    
    return domanda+" =";
}

ostream& operator<<(ostream& output, Funzioni& p){
    output<<p.domanda;
    return output;
}

istream& operator>>(istream& input, Funzioni& p){
    input>>p.risposta;
    return input;
}

Funzioni::operator bool() {
    if(risposta==correzione){
        return true;
    }else{
        return false;
    }
}
