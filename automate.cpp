#include <algorithm>
#include "automate.h"

Automate::Automate(string chaine)
{
    lexer = new Lexer(chaine);

    Etat *etat0 = new Etat_0("etat0");
    statestack.push_back(etat0);
}

void Automate::analyse()
{
    bool nouvelEtat = true;
    while (nouvelEtat)
    {
        Symbole *symbole = lexer->Consulter();
        lexer->Avancer();
        nouvelEtat = statestack.back()->Transition(*this, symbole);
    }
    cout << "Fin de lecture" << endl;
    if (*symbolstack.back() != ERREUR)
    {

        int resultat = symbolstack.back()->getValue();
        cout << "Expression syntaxiquement correcte" << endl
             << "Résultat de l'analyse : " << resultat << endl;
    }
    else
    {
        cout << "Expression non correcte syntaxiquement : caractère invalide" << endl;
    }
}

void Automate::decalage(Symbole *s, Etat *e)
{
    symbolstack.push_back(s);
    statestack.push_back(e);
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

void Automate::reduction(int n, Symbole *s)
{
    vector<Symbole *> aDepiler;

    for (int i = 0; i < n; i++)
    {
        delete (statestack.back());
        statestack.back();
        aDepiler.push_back(symbolstack.back());
        symbolstack.pop_back();
    }

    int val;

    if (n == 1)
    {
        val = aDepiler.back()->getValue();
    }
    else if (n == 3)
    {
        if (*aDepiler.back() == OPENPAR)
        {
            aDepiler.pop_back();
            val = aDepiler.back()->getValue();
        }
        else
        {
            val = aDepiler.back()->getValue();
            aDepiler.pop_back();
            if (*aDepiler.back() == MULT)
            {
                aDepiler.pop_back();
                val = val * aDepiler.back()->getValue();
            }
            else
            {
                aDepiler.pop_back();
                val = val + aDepiler.back()->getValue();
            }
        }
    }

    statestack.back()->Transition(*this, new expression(val));
    lexer->addSymbol(s);
}
