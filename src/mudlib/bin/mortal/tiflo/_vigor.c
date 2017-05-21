/****************************************************************************
Fichero: _vigor.c
Autor: orome@endor
Descripción: Devuelve puntos de vigor del jugador (TP, antiguo comando pf)

****************************************************************************/

//#define MSG_SPEAK "all_speak:"
#include <colours.h>
public int main()
{
    int agotamiento = ((TP->QueryMaxTP() - TP->QueryTP())*100)/TP->QueryMaxTP();
    write("\n\t"+(!TP->QueryTiflo() ? "Puntos de Vigor: " : "Vigor: ") + TP->QueryTP() + " de " + TP->QueryMaxTP() + "\n");
    write("\t"+(agotamiento>100 ? TC_RED+"Te sientes agotad"+TP->QueryGenderEndString()+", debes descansar."+TC_NORMAL : agotamiento+"% de agotamiento.")+"\n");

    return 1;
}
