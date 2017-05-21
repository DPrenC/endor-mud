/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/fondo/salida.c
Autor: Lug y Yalin
Fecha: 31/12/2006
Descripci�n: Salida de las canteras de Sherek
****************************************************************************/

#include "path.h"
#include <moving.h>
#include <properties.h>
#include <skills.h>
#include <sounds.h>
#include <magia.h>
inherit SIM_ROOM;
#define AO  (TP->QueryGenderEndString())

public int nadando()
{
    if (TP->QueryStatus() == STATUS_SLEEPING) return 0;
    if (TP->QueryTP() < 2) return notify_fail("Est�s muy cansad"+AO+" para nadar.\n",
        NOTIFY_NOT_VALID);
    play_sound(TO,SND_SUCESOS("chapuzon"),0,50);
    int nada = TP->UseSkill(HAB_NADAR,TP->QueryDex());
    /* Nada bien, consigue remontar el r�o. */
    if (nada>=0)
    {
        int azar;
        switch(nada)
        {
            case 0..19: azar=d20();break;
            case 20..49: azar=d10();break;
            default: azar=d4();break;
        }
        if (azar == 1 || nada >= 80)
        {
            write("Te lanzas con decisi�n al agua, y nadas como una "
                "nutria.\nTras largos esfuerzos, y con arduo empe�o, vences la "
                "corriente del canal, y eres arrastrad"+AO+" corriente abajo.\n"
                "Tras dura pelea con el agua, eres arrojad"+AO+" a la orilla, en "
                "el l�mite de un bosque.\n");
            say(CAP(TP->QueryName())+" se lanza valientemente al agua, y se "
                "aleja nadando.\nEn pocos minutos, desaparece de tu vista.\n",TP);
            tell_room(MARH("nandor/bosque/bosque033"),CAP(TP->QueryName())+" llega "
                "nadando por el r�o, m�s bien arrastrad"+AO+" por el r�o.\nEn "
                "este punto, dada su debilidad, es arrojad"+AO+" a la ribera, "
                "entre los �rboles.\n");
            TP->SetFollowers(0);
            return TP->move(MARH("nandor/bosque/bosque033"),M_GO);
        }
        /* Sabe nadar algo, remonta algo el r�o, por lo que se agota m�s, y al
        * retroceder traga m�s agua, y por tanto practicar� menos en el
        * mismo tiempo. */
        else if (nada >= 20)
        {
            TP->AddTP(-4);
            TP->AddHP(-10);
            say(CAP(TP->QueryName())+" se arroja al agua y se aleja...\nA los pocos "
                "metros, ves c�mo se agota, y regresa pateando y braceando a la "
                "orilla, vomitando agua.\n",TP);
            return notify_fail("Te lanzas al agua y nadas contra corriente, pero no "
                "nadas muy bien, y te agotas.\nEl r�o te devuelve medio ahogad"+AO+
                " a la orilla.\nEst�s "+TP->QueryHealthMsg()+".\n",NOTIFY_NOT_VALID);
        }
    /* no sabe nadar, apenas entra al agua, pierde poca fuerza y poca
    * vida, y puede practicar m�s seguido. */
    TP->AddTP(-2);
    TP->AddHP(-5);
    say(CAP(TP->QueryName())+" se lanza al agua, pero no sabe nadar, y "
        "tiene que salir medio ahogad"+AO+".\n",TP);
    return notify_fail("Intentas remontar el r�o, pero..., �no sabes "
        "nadar!\nLa corriente te arroja a la orilla escupiendo agua.\nEst�s "+
        TP->QueryHealthMsg()+".\n",NOTIFY_NOT_VALID);
    }
    say(CAP(TNAME)+" se lanza al agua sin ninguna convicci�n, y en un instante sale del r�o "
        "p�lid"+AO+" de miedo.\n",TP);
    return notify_fail("�Le tienes verdadero p�nico al agua! Apenas entras en el r�o, "
        "retrocedes asustad"+AO+".\n",NOTIFY_NOT_VALID);
}

verpiedra()
{
    if (!QUESTMASTER->QueryQuestSolved("DarylQuest",TP))
    {
        int sabe = TP->QueryAttribute("sabepiedra");
        int tiene = TP->QueryAttribute("tienepiedra");
        if ((sabe) && (!present("quest_piedra_ninyo",TP)))
        {
            if (!tiene)
            {
                TP->SetAttribute("tienepiedra",time());
                write("Caes entre las rocas, y te encuentras bajo la nariz "
                    "una bonita piedra amarilla, que naturalmente, ");
            }
            else write("Caes entre las rocas, y descubres con alivio la "
                "piedra que perdiste al salir nadando, que naturalmente, ");
            object piedra = clone_object(QUEST+"sherek/piedra");
            piedra->SetOwner(TP->QueryRealName());
            if (piedra->move(TP)) write("te apresuras a recoger.\n");
            else
            {
                piedra->move(TO);
                write("intentas recoger, pero llevas demasiadas cosas, y no consigues cogerla.\n");
            }
        }
    }
}

create()
{
    ::create();
    SetLocate("las monta�as de Sherek");
    SetIntShort("la salida de la monta�a");
    SetIntLong("Has ido a caer en una especie de gruta en la roca, que no es "
        "m�s que el hueco excavado por siglos de erosi�n del agua del r�o "
        "que discurre ante ti, el cu�l ha formado un canal que se adentra en "
        "la roca, y es la �nica salida de este agujero.\n");
    SetIndoors(0);
    SetIntSmell("Huele a r�o..., humedad y vegetaci�n podrida.\n");
    SetIntNoise("Suena el impetuoso caudal del r�o.\n");
    Set(P_TPORT,TPORT_NO);
    AddDetail("canal","El continuo golpe de la corriente a lo largo de los siglos, ha ido "
        "erosionando la piedra e introduciendo un brazo de agua, hasta formar un hueco en el "
        "sitio donde antes probablemente hubiera una plataforma de roca que descend�a m�s o "
        "menos suavemente hasta el borde del agua.\n");
    AddDetail(({"rio","r�o","cauce","caudal",}),"Es el gran r�o Kandal, que "
        "viene desde el nordeste, y baja rodeando las monta�as hasta el "
        "lejano mar del suroeste.\nEn este punto hace un recodo hacia el "
        "suroeste, y el golpe de la corriente ha creado el hueco en que te "
        "encuentras.\nUnos metros corriente arriba, unos baj�os y los "
        "troncos que han quedado encayados en ellos, hacen mortalmente "
        "peligroso el ascenso.\n");
    AddDetail(({"bajios","baj�os"}),"Son rocas que sobresalen del fondo, "
        "formando una barrera natural, con pasos tan estrechos que no "
        "permiten pasar apenas los troncos m�s delgados.\n");
    AddDetail(({"tronco","troncos"}),"Son troncos de �rboles ca�dos en alg�n "
        "bosque r�o arriba, atrapados aqu� contra los baj�os del cauce.\n");
    SetExplorable(1);
    ForbidAllMagic("Antiguos hechizos impiden hacer magia en esta monta�a.\n");
    SetSoundEnvironment(SND_AMBIENTES("rio_cerca"));
    AddExit("nadar",SF(nadando));
}

init()
{
    ::init();
    write("�Por fin! �Lo conseguiste!\n");
    call_out("verpiedra",1);
}
