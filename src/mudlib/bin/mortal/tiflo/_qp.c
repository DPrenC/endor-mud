/****************************************************************************
Fichero: _qp.c
Autor: Kastwey@simauria
Descripci�n: Devuelve los puntos de quest del jugador
Creaci�n: 23/01/2006
****************************************************************************/

#define MSG_SPEAK "all_speak:"

public int main()
{
    write((TP->QueryTiflo() ? MSG_SPEAK : "") + QUESTMASTER->QueryQuestPoints(TP) + " / " + QUESTMASTER->QueryTotalQuestPoints() + "\n");
    return 1;
}
