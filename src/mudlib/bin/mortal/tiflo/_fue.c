/****************************************************************************
Fichero: _fue.c
Autor: kastwey@simauria
Descripci�n: Devuelve la fuerza del player
Creaci�n: 23/01/2006
****************************************************************************/

#define MSG_SPEAK "all_speak:"

public int main()
{
    write((TP->QueryTiflo() ? MSG_SPEAK : "") + TP->QueryStr() + "\n");
    return 1;
}


