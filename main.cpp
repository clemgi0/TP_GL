#include <iostream>
#include <algorithm>

#include "automate.h"
#include "lexer.h"

int main(void)
{

    string chaine;

    cout << "Entrez l'expression à analyser :";
    getline(cin, chaine);
    chaine.erase(remove_if(chaine.begin(), chaine.end(), ::isspace), chaine.end());

    Automate *automate = new Automate(chaine);
    automate->analyse();

    return 0;
}
