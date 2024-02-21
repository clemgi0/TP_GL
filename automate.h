#ifndef GL_TP_H
#define GL_TP_H

#include <vector>
#include <string>
#include "symbole.h"
#include "lexer.h"

class Etat;
class E0;
using namespace std;

class Automate
{
public:
    Automate(string chaine);
    void eval();
    void decalage(Symbole *s, Etat *e);
    void reduction(int n, Symbole *s);
    int calcul(vector<Symbole *> v);
    ~Automate();

protected:
    vector<Symbole *> symbols;
    vector<Etat *> states;

    Lexer *lexer;
    Symbole *reserve;
};

#endif // GL_TD2_AUTOMATE_H
