/****************************************************************************
Fichero: _con.c
Autor: kastwey@simauria
Descripci�n: Devuelve la constituci�n del player.
Creaci�n: 19/11/2004
****************************************************************************/

#define MSG_SPEAK "all_speak:"

public int main()
{
    write((TP->QueryTiflo() ? MSG_SPEAK : "") + TP->QueryCon() + "\n");;
    return 1;
}
