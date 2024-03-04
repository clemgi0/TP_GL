#include <iostream>
#include "automate.h"
#include "lexer.h"

int main(void)
{

    string chaine;

    cout << "Entrez l'expression à analyser :";
    getline(cin, chaine);
    Automate *automate = new Automate(chaine);
    automate->analyse();

    return 0;
}
