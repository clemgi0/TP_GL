using namespace std;

#ifndef GL_TP_H
#define GL_TP_H

#include <vector>
#include <string>

#include "symbole.h"
#include "lexer.h"
#include "etats.h"

class Automate
{
public:
    Automate(string chaine);
    void eval();
    void decalage(Symbole *s, Etat *e);
    void reduction(int n, Symbole *s);
    void transitionsimple(Symbole *s, Etat *e);
    int calcul(vector<Symbole *> v);
    ~Automate();

protected:
    vector<Symbole *> symbolstack;
    vector<Etat *> statestack;

    Lexer *lexer;
    Symbole *reserve;
};

#endif
