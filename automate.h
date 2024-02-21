using namespace std;

#ifndef GL_TP_H
#define GL_TP_H

#include <stack>
#include <string>

#include "symbole.h"
#include "lexer.h"
#include "etats.h"

class Automate
{
public:
    Automate(string chaine);
    void analyse();
    void decalage(Symbole *s, Etat *e);
    void reduction(int n, Symbole *s);
    void transitionsimple(Symbole *s, Etat *e);
    ~Automate();

protected:
    stack<Symbole *> symbolstack;
    stack<Etat *> statestack;

    Lexer *lexer;
};

#endif
