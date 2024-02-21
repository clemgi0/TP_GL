#include <algorithm>
#include "automate.h"

Automate::Automate(string chaine)
{
    lexer = new Lexer(chaine);

    Etat *etat0 = new Etat_0("etat0");
    statestack.push_back(etat0);
}

void Automate::eval()
{
    bool retourTransition = true;
    while (retourTransition)
    {
        Symbole *symbole = lexer->Consulter();
        lexer->Avancer();
        retourTransition = statestack.back()->Transition(*this, symbole);
    }
    cout << "Fin de lecture" << endl;
}

void Automate::decalage(Symbole *s, Etat *e)
{
    symbolstack.push_back(s);
    statestack.push_back(e);
    lexer->Avancer();
}

void Automate::reduction(int n, Symbole *s)
{
    for (int i = 0; i < n; i++)
    {
        delete (statestack.back());
        statestack.pop_back();
    }
    statestack.back()->Transition(*this, s);
}

void Automate::transitionsimple(Symbole *s, Etat *e)
{
    statestack.push_back(e);
    symbolstack.push_back(s);
}

// int Automate::calcul(vector<Symbole *> tab)
// {

//     switch (tab.size())
//     {
//     case 1:
//         return tab[0]->eval();
//         break;
//     case 3:
//         if (tab[0]->avoirJeton() == OUVREPAR)
//         {
//             return tab[1]->eval();
//         }
//         else if (tab[1]->avoirJeton() == PLUS)
//         {
//             return tab[0]->eval() + tab[2]->eval();
//         }
//         else if (tab[1]->avoirJeton() == MULT)
//         {
//             return tab[0]->eval() * tab[2]->eval();
//         }
//         break;
//     }

//     return 0;
// }

Automate::~Automate()
{
    delete lexer;
}
