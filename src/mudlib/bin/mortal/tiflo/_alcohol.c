/***
fichero: _alcohol.c
Autor: kastwey@simauria
Descripci�n: fichero que devuelve el estado de sobriedad de un jugador.
Creaci�n: 19/11/2004
***/

#include <properties.h>

#define AO (TP->QueryGenderEndString())
#define A (TP->QueryGender() == GENDER_FEMALE ? "a":"")
#define MSG_SPEAK "all_speak:"

int main()
{
    int i;
    string alcohol;
    i = (TP->QueryAlcohol()*100) / (TP->QueryMaxAlcohol()||1);
    switch(i)
    {
        case 90..101:
             alcohol = "JAJAJAJA �tas mu borrash" + AO +" xaval"+ A + "! :)";
             break;
        case 75.. 89:
             alcohol = "Te cuesta mantenerte en pie.";
             break;
        case 50.. 74:
             alcohol = "Te cuesta estar parad" + AO + ".";
             break;
        case 25.. 49:
             alcohol = "Est�s m�s alegre de lo normal.";
             break;
        case 10.. 24:
             alcohol ="La cabeza empieza a dolerte.";
        break;
        case  5..  9:
             alcohol ="No est�s del todo sobri" + AO + ".";
             break;
        case -1..  4:
             alcohol = "Est�s sobri" + AO + ".";
             break;
        default:
             alcohol = "Est�s muy borrach" + AO + " (" + i + ").";
    }
    write((TP->QueryTiflo() ? MSG_SPEAK : "") + alcohol);
    return 1;
}

