/****************************************************************************
Fichero: _fue.c
Autor: kastwey@simauria
Descripción: Devuelve la fuerza del player
Creación: 23/01/2006
****************************************************************************/

#define MSG_SPEAK "all_speak:"

public int main()
{
    write((TP->QueryTiflo() ? MSG_SPEAK : "") + TP->QueryStr() + "\n");
    return 1;
}


