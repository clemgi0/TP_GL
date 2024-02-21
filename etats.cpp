#include "etats.h"

void Etat::Afficher(Symbole *symbole) {
    cout << name << " | Symbole: " ;
    symbole->Affiche();
    cout << endl;
}

bool Etat_0::Transition(Automate &automate, Symbole *symbole) {
    switch(*symbole) {
        case EXPR:
            Afficher(symbole);
            automate->decalage(symbole, new Etat_1("etat_1"));
            break;
        case OPENPAR:
            Afficher(symbole);
            automate->decalage(symbole, new Etat_2("etat_2"));
            break;
        case INT:
            Afficher(symbole);
            automate->decalage(symbole, new Etat_3("etat_3"));
            break;
        default:
            AfficherErreur();
            return false;
    }

    return true;
}

bool Etat_1::Transition(Automate &automate, Symbole *symbole) {
    switch(*symbole) {
        case PLUS:
            Afficher(symbole);
            automate->decalage(symbole, new Etat_4("etat_4"));
            break;
        case MULT:
            Afficher(symbole);
            automate->decalage(symbole, new Etat_5("etat_5"));
            break;
        case FIN:
            Afficher(symbole);
            return false;
        default:
            AfficherErreur();
            return false;
    }
    
    return true;
}

bool Etat_2::Transition(Automate &automate, Symbole *symbole) {
    switch(*symbole) {
        case OPENPAR:
            Afficher(symbole);
            automate->decalage(symbole, new Etat_2("etat_2"));
            break;
        case INT:
            Afficher(symbole);
            automate->decalage(symbole, new Etat_3("etat_3"));
            break;
        case EXPR:
            Afficher(symbole);
            automate->decalage(symbole, new Etat_6("etat_6"));
            break;
        default:
            AfficherErreur();
            return false;
    }
    
    return true;
}

bool Etat_3::Transition(Automate &automate, Symbole *symbole) {
    switch(*symbole) {
        case PLUS:
            Afficher(symbole);
            automate->decalage(symbole, new Etat_3("etat_2"));
            break;
        case MULT:
            Afficher(symbole);
            automate->decalage(symbole, new Etat_3("etat_3"));
            break;
        case CLOSEPAR:
            Afficher(symbole);
            automate->decalage(symbole, new Etat_6("etat_6"));
            break;
        default:
            AfficherErreur();
            return false;
    }
    
    return true;
}