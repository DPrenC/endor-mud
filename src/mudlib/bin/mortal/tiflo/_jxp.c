/****************************************************************************
Fichero: _jxp.c
Autor: kastwey@simauria
Descripci�n: Devuelve la xp de jugador.
Creaci�n: 23/01/2006
****************************************************************************/

#define MSG_SPEAK "all_speak:"

public int main()
{
    write((TP->QueryTiflo() ? MSG_SPEAK : "") + TP->QueryXP() + "\n");
    return 1;
}
