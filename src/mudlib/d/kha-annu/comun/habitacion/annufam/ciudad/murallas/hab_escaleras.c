/***************************************************************************
fichero: hab_escaleras.c
autor: Kastwey
Descripción: Subiendo por las escaleras de las murallas de la ciudad de Annufam.
[t] 27/02/2008: Cambio la room de las murallas para que estas contengan la ciuda, que estaba desplazado 2 rooms als este.
***************************************************************************/

#include "./path.h"
#include <moving.h>
#define BAJA        HAB_MURALLAS_ANNUFAM("escaleras")
#define DESCANSILLO HAB_MURALLAS_ANNUFAM("descansillo")
//#define MURALLAS    HAB_MURALLAS_ANNUFAM("murallas_00")
#define MURALLAS    HAB_MURALLAS_ANNUFAM("murallas_02")
#define SUBIENDO 1
#define BAJANDO  2

inherit HAB_MURALLAS_ANNUFAM("escalera_base");

string desc_larga()
{
    return W("Te encuentras " +
             (TP->QueryAttribute("escalera_murallas_dir") == SUBIENDO ?
              "as" : "des") + "cendiendo por las escaleras de la torre de "
             "acceso a las murallas de la ciudad.\n");
}


public void create()
{
    ::create();
    SetIntShort("unas escaleras");
    SetIntLong(SF(desc_larga));
}


void ir_destino(object ob, string dest, int dir)
{
    string msg_aqui, msg_pj;
    if (!ob || (!living(ob) && (-1 == member(ob->QueryIds(), "esfera"))) || !present(ob) || !dest) return;
    if (ob->Fighting())
    // Está luchando... Renovamos el call_out hasta que deje de luchar.
    {
        return call_out("ir_destino",10,ob,dest,dir);
    }
    switch(dest)
    {
        case BAJA: // llega a la planta baja
             msg_pj = "Llegas a la planta baja de la torre";
             msg_aqui = " llega a la planta baja de la torre";
             break;
        case DESCANSILLO: // llega al descansillo
             msg_pj = "Llegas a un descansillo";
             msg_aqui = " llega al descansillo";
             break;
        case MURALLAS: // llega a las murallas
             msg_pj = "Llegas a lo alto de las murallas de la ciudad";
             msg_aqui = " llega a las murallas de la ciudad";
             break;
    }
    ob->move(dest,M_SPECIAL,
             ({msg_aqui,"llega " + (dir == SUBIENDO ? "subiendo" : " bajando")+
               " por las escaleras",msg_pj}));
    ob->RemoveAttribute("escalera_murallas_dir");
    ob->RemoveAttribute("escalera_murallas_dest");
}



public void notify_enter(mixed from, int method, mixed extra)
{
    object ob;
    string dest = ((ob = PO)?ob->QueryAttribute("escalera_murallas_dest"):0);
    int dir = (ob ? ob->QueryAttribute("escalera_murallas_dir") : 0);
    ::notify_enter(from, method, extra);
    if (!dir || !dest)
    {
        switch(object_name(from))
        {
            case BAJA: // está subiendo de la base al descansillo
                 dest = DESCANSILLO;
                 dir = SUBIENDO;
                 break;
            case DESCANSILLO:
                 if (extra == "arriba")
                 { // está subiendo del descansillo a las murallas
                     dest = MURALLAS;
                     dir = SUBIENDO;
                     break;
                 }
                 dest = BAJA;
                 dir = BAJANDO;
                 break;
            case MURALLAS: // va bajando hacia el descansillo
                 dest = DESCANSILLO;
                 dir = BAJANDO;
                 break;
        }
        ob->SetAttribute("escalera_murallas_dir",dir);
        ob->SetAttribute("escalera_murallas_dest",dest);
    }
    if (extra)
    {
        tell_room(TO,W(CAP(ob->QueryName() || ob->QueryShort() || "algo") + " aparece " +
                       (dir == SUBIENDO ? "subiendo" : "bajando") +
                       " las escaleras.\n"),({ob}));
    }
    call_out("ir_destino", 10, ob, dest, dir);
}
