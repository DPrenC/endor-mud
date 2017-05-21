/****************************************************************************
Fichero: _poder.c
Autor: orome@endor-mud
Descripción: Devuelve los puntos de poder del jugador (SP, antiguo comando pm)
****************************************************************************/

//#define MSG_SPEAK "all_speak:"

public int main()
{
    write("\n\t"+(!TP->QueryTiflo() ? "Puntos de Poder: " : "Poder: ") + TP->QuerySP() + " de " + TP->QueryMaxSP() + "\n");
    return 1;
}
