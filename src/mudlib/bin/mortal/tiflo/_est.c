/****************************************************************************
Fichero: _est.c
Autor: kastwey@simauria
Descripci�n: Devuelve el estado de un personaje o cosa pasada como par�metro.
Creaci�n: 22/01/2006
****************************************************************************/

#include <properties.h>

#define MSG_SPEAK "all_speak:"
#define TIFLO(x) (TP->QueryTiflo() ? MSG_SPEAK : "") + x


private string calidad(object ob)
{
    string msg;
    if (!living(ob) && !function_exists("QueryQualityMsg",ob))
    {
        return "no puedes ver el estado de eso";
    }
    if (living(ob)) return (ob == TP ? "est�s " : "est� ") + ob->QueryHealthMsg();
    msg = (ob->Query(P_NUMBER) == NUMERO_PLURAL ? "est�n":"est�");
    return msg + " " + ob->QueryQualityMsg(1);
}


public int main(string str)
{
    object *cosas, ob;
    object pl = TP;
    if (!str)
    {
        return notify_fail(TIFLO("Sintaxis: est <objeto>, donde <objeto> es "
                                 "cualquier objeto de la habitaci�n o de tu inventario.\n"));
    }
    cosas = ({});
    ob = present(str,pl);
    if (ob) cosas += ({ob});
    ob = present(str,environment(pl));
    if (ob) cosas += ({ob});
    if (!sizeof(cosas))
    {
        return notify_fail(TIFLO("No puedes ver eso por aqu�.\n"));
    }
    if (sizeof(cosas) == 2)
    {
        write(TIFLO((cosas[0]->QueryShort() || "algo") + ", que llevas "
                     "contigo, " + calidad(cosas[0]) + ". " +
                     (cosas[1]->QueryShort() || "algo") + ", aqu�, " +
                     calidad(cosas[1]) + ".\n"));
        return 1;
    }
    write(TIFLO(CAP(calidad(cosas[0]) + ".\n")));
    return 1;
}
