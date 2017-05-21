/****************************************************************************
Fichero: _con.c
Autor: kastwey@simauria
Descripción: Devuelve la constitución del player.
Creación: 19/11/2004
****************************************************************************/

#define MSG_SPEAK "all_speak:"

public int main()
{
    write((TP->QueryTiflo() ? MSG_SPEAK : "") + TP->QueryCon() + "\n");;
    return 1;
}
