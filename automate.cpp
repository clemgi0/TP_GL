#include <algorithm>
#include "automate.h"

Automate::Automate(string chaine)
{
    lexer = new Lexer(chaine);

    Etat *etat0 = new Etat_0("etat0");
    statestack.push(etat0);
}

void Automate::analyse()
{
    bool nouvelEtat = true;
    while (nouvelEtat)
    {
        Symbole *symbole = lexer->Consulter();
        lexer->Avancer();
        nouvelEtat = statestack.top()->Transition(*this, symbole);
    }
    cout << "Fin de lecture" << endl;
    if (*symbolstack.top() != ERREUR)
    {

        int resultat = symbolstack.top()->getValue();
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
    symbolstack.push(s);
    statestack.push(e);
    // affiche la symbolstack
    stack<Symbole *> symbolstackCopy = symbolstack;
    cout << "symbolstack : ";
    while (!symbolstackCopy.empty())
    {
        cout << symbolstackCopy.top()->getValue() << " ";
        symbolstackCopy.pop();
    }
}

void Automate::reduction(int n, Symbole *s)
{
    stack<Symbole *> aEnlever;

    for (int i = 0; i < n; i++)
    {
        delete (statestack.top());
        statestack.pop();
        aEnlever.push(symbolstack.top());
        symbolstack.pop();
    }

    int val;

    if (n == 1)
    {
        val = aEnlever.top()->getValue();
    }
    else if (n == 3)
    {
        if (*aEnlever.top() == OPENPAR)
        {
            aEnlever.pop();
            val = aEnlever.top()->getValue();
        }
        else
        {
            val = aEnlever.top()->getValue();
            aEnlever.pop();
            if (*aEnlever.top() == MULT)
            {
                aEnlever.pop();
                val = val * aEnlever.top()->getValue();
            }
            else
            {
                aEnlever.pop();
                val = val + aEnlever.top()->getValue();
            }
        }
    }
    cout << "val : " << val << endl;

    statestack.top()->Transition(*this, new Expr(val));
    lexer->addSymbol(s);
}
