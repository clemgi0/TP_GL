#include "automate.h"

void Etat::Afficher(Symbole *symbole)
{
    cout << name << " | Symbole: ";
    symbole->Affiche();
    cout << endl;
}

bool Etat_0::Transition(Automate &automate, Symbole *symbole)
{
    switch (*symbole)
    {
    case EXPR:
        Afficher(symbole);
        automate.decalage(symbole, new Etat_1("etat_1")); // si automate. marche pas mettre automate. partout dans ce file et dans le .h aussi ptetre
        break;
    case OPENPAR:
        Afficher(symbole);
        automate.decalage(symbole, new Etat_2("etat_2"));
        break;
    case INT:
        Afficher(symbole);
        automate.decalage(symbole, new Etat_3("etat_3"));
        break;
    default:
        AfficherErreur();
        Afficher(symbole);
        return false;
    }

    return true;
}

bool Etat_1::Transition(Automate &automate, Symbole *symbole)
{
    switch (*symbole)
    {
    case PLUS:
        Afficher(symbole);
        automate.decalage(symbole, new Etat_4("etat_4"));
        break;
    case MULT:
        Afficher(symbole);
        automate.decalage(symbole, new Etat_5("etat_5"));
        break;
    case FIN:
        Afficher(symbole);
        return false;
    default:
        AfficherErreur();
        Afficher(symbole);
        return false;
    }

    return true;
}

bool Etat_2::Transition(Automate &automate, Symbole *symbole)
{
    switch (*symbole)
    {
    case OPENPAR:
        Afficher(symbole);
        automate.decalage(symbole, new Etat_2("etat_2"));
        break;
    case INT:
        Afficher(symbole);
        automate.decalage(symbole, new Etat_3("etat_3"));
        break;
    case EXPR:
        Afficher(symbole);
        automate.decalage(symbole, new Etat_6("etat_6"));
        break;
    default:
        AfficherErreur();
        Afficher(symbole);
        return false;
    }

    return true;
}

bool Etat_3::Transition(Automate &automate, Symbole *symbole)
{
    switch (*symbole)
    {
    case PLUS:
        Afficher(symbole);
        automate.reduction(1, new Plus);
        break;
    case MULT:
        Afficher(symbole);
        automate.reduction(1, new Mult);
        break;
    case CLOSEPAR:
        Afficher(symbole);
        automate.reduction(1, new Closepar);
        break;
    case FIN:
        Afficher(symbole);
        automate.reduction(1, new Fin);
        break;
    default:
        AfficherErreur();
        Afficher(symbole);
        return false;
    }

    return true;
}

bool Etat_4::Transition(Automate &automate, Symbole *symbole)
{
    switch (*symbole)
    {
    case CLOSEPAR:
        Afficher(symbole);
        automate.decalage(symbole, new Etat_2("etat_2"));
        break;
    case INT:
        Afficher(symbole);
        automate.decalage(symbole, new Etat_3("etat_3"));
        break;
    case EXPR:
        Afficher(symbole);
        automate.decalage(symbole, new Etat_7("etat_7"));
        break;
    default:
        AfficherErreur();
        Afficher(symbole);
        return false;
    }

    return true;
}

bool Etat_5::Transition(Automate &automate, Symbole *symbole)
{
    switch (*symbole)
    {
    case CLOSEPAR:
        Afficher(symbole);
        automate.decalage(symbole, new Etat_2("etat_2"));
        break;
    case INT:
        Afficher(symbole);
        automate.decalage(symbole, new Etat_3("etat_3"));
        break;
    case EXPR:
        Afficher(symbole);
        automate.decalage(symbole, new Etat_8("etat_8"));
        break;
    default:
        AfficherErreur();
        Afficher(symbole);
        return false;
    }

    return true;
}

bool Etat_6::Transition(Automate &automate, Symbole *symbole)
{
    switch (*symbole)
    {
    case PLUS:
        Afficher(symbole);
        automate.decalage(symbole, new Etat_4("etat_4"));
        break;
    case MULT:
        Afficher(symbole);
        automate.decalage(symbole, new Etat_5("etat_5"));
        break;
    case CLOSEPAR:
        Afficher(symbole);
        automate.decalage(symbole, new Etat_9("etat_9"));
        break;
    default:
        AfficherErreur();
        Afficher(symbole);
        return false;
    }

    return true;
}

bool Etat_7::Transition(Automate &automate, Symbole *symbole)
{
    switch (*symbole)
    {
    case PLUS:
        Afficher(symbole);
        automate.reduction(3, new Plus);
        break;
    case MULT:
        Afficher(symbole);
        automate.decalage(symbole, new Etat_5("etat_5"));
        break;
    case CLOSEPAR:
        Afficher(symbole);
        automate.reduction(3, new Closepar);
        break;
    case FIN:
        Afficher(symbole);
        automate.reduction(3, new Fin);
        break;
    default:
        AfficherErreur();
        Afficher(symbole);
        return false;
    }

    return true;
}

bool Etat_8::Transition(Automate &automate, Symbole *symbole)
{
    switch (*symbole)
    {
    case PLUS:
        Afficher(symbole);
        automate.reduction(3, new Plus);
        break;
    case MULT:
        Afficher(symbole);
        automate.reduction(3, new Mult);
        break;
    case CLOSEPAR:
        Afficher(symbole);
        automate.reduction(3, new Closepar);
        break;
    case FIN:
        Afficher(symbole);
        automate.reduction(3, new Fin);
        break;
    default:
        AfficherErreur();
        Afficher(symbole);
        return false;
    }

    return true;
}

bool Etat_9::Transition(Automate &automate, Symbole *symbole)
{
    switch (*symbole)
    {
    case PLUS:
        Afficher(symbole);
        automate.reduction(3, new Plus);
        break;
    case MULT:
        Afficher(symbole);
        automate.reduction(3, new Mult);
        break;
    case CLOSEPAR:
        Afficher(symbole);
        automate.reduction(3, new Closepar);
        break;
    case FIN:
        Afficher(symbole);
        automate.reduction(3, new Fin);
        break;
    default:
        AfficherErreur();
        Afficher(symbole);
        return false;
    }

    return true;
}