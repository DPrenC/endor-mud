/****************************************************************************
Fichero: guardian_porton.c
Autor: Kastwey
Creaci�n: 25/07/2005
Descripci�n: guardi�n del port�n de la ciudad de Annufam
****************************************************************************/

#include "./path.h"
#include <guild.h>
#include <moving.h>



inherit NPC;

int es_amigo(object ob)
// comprueba si el que llega es o no amigo
{
    if (!ob || !living(ob) || member(RAZASENEMIGAS,ob->QueryRace()) < 0)
    {
        return 1;
    }

    tell_room(environment(),W("El guardi�n mira a " + CAP(NNAME(ob)) +
              " sorprendido mientras blande su hacha y grita:\n"
              "�Eh t�! maldit" + OBAO(ob) + " " + CAP(ob->QueryRace()) + "! "
              "�C�mo osas siquiera intentar entrar en nuestra ciudad?\n"),
              ({ob}));
        tell_object(ob,W("Un guardia te mira sorprendido y blande su hacha "
                         "amenazadoramente mientras te grita:\n"
                         "�Eh t�! maldit" + OBAO(ob) + " " +
                         CAP(ob->QueryRace()) + "! �C�mo osas siquiera "
                         "intentar entrar en nuestra ciudad?\n"));
    return 0;
}


string fumar()
// chats del guardia para fumar
{
    object tabaco;
    if (!(tabaco = present("tabaco_picado",TO)))
    {
        return W("El guardia mira triste la pipa y dice: Maldita sea, no "
                 "me queda m�s tabaco.\n");
    }
    tabaco->fmenos();
    return W("El guardia pone un poco de tabaco picado en la pipa y aspira "
             "el humo con deleite.\n");
}

void agradecer(object ob, object pl)
// funci�n para agradecer a un player si le da tabaco para la pipa
{
    if (!ob) return;
    if (!pl || environment(pl) != environment() || !CanSeeObject(pl))
    // el player que le ha dado el tabaco no est� o el guardia no lo ve
    {
        tell_room(environment(),W("El guardia mira hacia todos lados como si "
                                  "buscase a alguien. Con una sonrisa de "
                                  "satisfacci�n en los labios, pone un poco "
                                  "de tabaco en la pipa y aspira el humo con evidente deleite.\n"));
        return;
    }
    write(W("El guardia te mira y te dice: �eeih! amig" + AO + "! �Muchas "
            "gracias por el tabaco!\n"
            "Hmmmm qu� buena pinta...\n\n"
            "A continuaci�n, introduce un poco de tabaco en la pipa y "
            "comienza a fumar mientras murmura:\n"
            "hufff.. Eesto s� que es viida...\n"));
    say(W("El guardia agradece a " + CAP(TNAME) + " el tabaco que le acaba "
          "de dar.\n"
          "A continuaci�n, pone un poco en la pipa y comienza a "
          "fumar mientras murmura: Huffff. Eesto s� que es viida.\n"),TP);
}

    public void create()
{
    ::create();
    seteuid(getuid());
    SetStandard("el guardi�n del port�n","enano",([GC_LUCHADOR:50]),GENDER_MALE);
    SetLong(W("Es un enano bastante corpulento que controla quien entra y quien "
              "sale de Annufam. Tambi�n, por las noches, vigila que nadie "
              "intente entrar a la ciudad. Su hacha parece ser una buena "
              "cerradura.\n"));
    SetAggressive(2);
    SetFriendFunction(#'es_amigo);
    AddId(({"guardi�n","guardian","guardia","guardia_annufam","guardian_porton"}));
    InitChats(5,({#'fumar,"El guardi�n te mira receloso.\n",
                  "El guardi�n silba una melod�a.\n",
                  W("El guardi�n murmura: A veces me gustar�a que viniesen "
                    "esos malditos orcos. As� habr�a algo de acci�n por "
                    "aqu�.\n")}));
    AddItem(OTRO("pipa.c"),REFRESH_REMOVE);
    AddItem(OTRO("tabaco.c"),REFRESH_REMOVE);
    AddItem(ARMA_CENTRO_ANNUFAM("hacha_guerreros.c"),REFRESH_REMOVE,1,#'wieldme);

}



public int allow_enter(int method, mixed extra)
// si le das algo de tabaco al guardia, este se pone contento.
{
    object ob = PO;
    int val;
    if (Fighting())
    // est� luchando
    {
        write(W("No crees que sea muy buena idea darle nada en este "
                "momento.\n"));
        return ME_NO_GIVE;
    }
    val = ::allow_enter(method, extra);
    if (TP != TO && val == ME_OK && ob->id("tabaco_picado"))
    {
        call_out("agradecer",1,ob,TP);
    }

    return val;
}

