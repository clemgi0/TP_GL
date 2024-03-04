#pragma once

#include <string.h>
#include "symbole.h"
using namespace std;

class Lexer
{

public:
   Lexer(string s);
   ~Lexer() {}

   Symbole *Consulter();
   void addSymbol(Symbole *s);
   bool finDeChaine();
   void Avancer();
   string parseEntry(string chaine);

protected:
   string flux;
   int tete;
   Symbole *tampon;
};
