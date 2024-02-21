#include <iostream>
#include "automate.h"
#include "lexer.h"

int main(void)
{

    string chaine;

    cout << "Indiquez la phrase à analyser :" << endl;
    cin >> chaine;
    Automate *a = new Automate(chaine);
    a->eval();

    return 0;
}
