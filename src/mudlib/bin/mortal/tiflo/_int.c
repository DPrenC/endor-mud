/****************************************************************************
Fichero: _int.c
Autor: Kastwey@simauria
Descripci�n: Devuelve la inteligencia de un player.
Creaci�n: 23/01/2006
****************************************************************************/

#define MSG_SPEAK "all_speak:"
public int main()
{
    write((TP->QueryTiflo() ? MSG_SPEAK :"") + TP->QueryInt() + "\n");
    return 1;
}
