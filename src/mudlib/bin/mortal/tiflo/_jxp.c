/****************************************************************************
Fichero: _jxp.c
Autor: kastwey@simauria
Descripción: Devuelve la xp de jugador.
Creación: 23/01/2006
****************************************************************************/

#define MSG_SPEAK "all_speak:"

public int main()
{
    write((TP->QueryTiflo() ? MSG_SPEAK : "") + TP->QueryXP() + "\n");
    return 1;
}
