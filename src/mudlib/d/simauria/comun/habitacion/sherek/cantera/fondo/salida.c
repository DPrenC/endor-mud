/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/fondo/salida.c
Autor: Lug y Yalin
Fecha: 31/12/2006
Descripción: Salida de las canteras de Sherek
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
    if (TP->QueryTP() < 2) return notify_fail("Estás muy cansad"+AO+" para nadar.\n",
        NOTIFY_NOT_VALID);
    play_sound(TO,SND_SUCESOS("chapuzon"),0,50);
    int nada = TP->UseSkill(HAB_NADAR,TP->QueryDex());
    /* Nada bien, consigue remontar el río. */
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
            write("Te lanzas con decisión al agua, y nadas como una "
                "nutria.\nTras largos esfuerzos, y con arduo empeño, vences la "
                "corriente del canal, y eres arrastrad"+AO+" corriente abajo.\n"
                "Tras dura pelea con el agua, eres arrojad"+AO+" a la orilla, en "
                "el límite de un bosque.\n");
            say(CAP(TP->QueryName())+" se lanza valientemente al agua, y se "
                "aleja nadando.\nEn pocos minutos, desaparece de tu vista.\n",TP);
            tell_room(MARH("nandor/bosque/bosque033"),CAP(TP->QueryName())+" llega "
                "nadando por el río, más bien arrastrad"+AO+" por el río.\nEn "
                "este punto, dada su debilidad, es arrojad"+AO+" a la ribera, "
                "entre los árboles.\n");
            TP->SetFollowers(0);
            return TP->move(MARH("nandor/bosque/bosque033"),M_GO);
        }
        /* Sabe nadar algo, remonta algo el río, por lo que se agota más, y al
        * retroceder traga más agua, y por tanto practicará menos en el
        * mismo tiempo. */
        else if (nada >= 20)
        {
            TP->AddTP(-4);
            TP->AddHP(-10);
            say(CAP(TP->QueryName())+" se arroja al agua y se aleja...\nA los pocos "
                "metros, ves cómo se agota, y regresa pateando y braceando a la "
                "orilla, vomitando agua.\n",TP);
            return notify_fail("Te lanzas al agua y nadas contra corriente, pero no "
                "nadas muy bien, y te agotas.\nEl río te devuelve medio ahogad"+AO+
                " a la orilla.\nEstás "+TP->QueryHealthMsg()+".\n",NOTIFY_NOT_VALID);
        }
    /* no sabe nadar, apenas entra al agua, pierde poca fuerza y poca
    * vida, y puede practicar más seguido. */
    TP->AddTP(-2);
    TP->AddHP(-5);
    say(CAP(TP->QueryName())+" se lanza al agua, pero no sabe nadar, y "
        "tiene que salir medio ahogad"+AO+".\n",TP);
    return notify_fail("Intentas remontar el río, pero..., ¡no sabes "
        "nadar!\nLa corriente te arroja a la orilla escupiendo agua.\nEstás "+
        TP->QueryHealthMsg()+".\n",NOTIFY_NOT_VALID);
    }
    say(CAP(TNAME)+" se lanza al agua sin ninguna convicción, y en un instante sale del río "
        "pálid"+AO+" de miedo.\n",TP);
    return notify_fail("¡Le tienes verdadero pánico al agua! Apenas entras en el río, "
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
    SetLocate("las montañas de Sherek");
    SetIntShort("la salida de la montaña");
    SetIntLong("Has ido a caer en una especie de gruta en la roca, que no es "
        "más que el hueco excavado por siglos de erosión del agua del río "
        "que discurre ante ti, el cuál ha formado un canal que se adentra en "
        "la roca, y es la única salida de este agujero.\n");
    SetIndoors(0);
    SetIntSmell("Huele a río..., humedad y vegetación podrida.\n");
    SetIntNoise("Suena el impetuoso caudal del río.\n");
    Set(P_TPORT,TPORT_NO);
    AddDetail("canal","El continuo golpe de la corriente a lo largo de los siglos, ha ido "
        "erosionando la piedra e introduciendo un brazo de agua, hasta formar un hueco en el "
        "sitio donde antes probablemente hubiera una plataforma de roca que descendía más o "
        "menos suavemente hasta el borde del agua.\n");
    AddDetail(({"rio","río","cauce","caudal",}),"Es el gran río Kandal, que "
        "viene desde el nordeste, y baja rodeando las montañas hasta el "
        "lejano mar del suroeste.\nEn este punto hace un recodo hacia el "
        "suroeste, y el golpe de la corriente ha creado el hueco en que te "
        "encuentras.\nUnos metros corriente arriba, unos bajíos y los "
        "troncos que han quedado encayados en ellos, hacen mortalmente "
        "peligroso el ascenso.\n");
    AddDetail(({"bajios","bajíos"}),"Son rocas que sobresalen del fondo, "
        "formando una barrera natural, con pasos tan estrechos que no "
        "permiten pasar apenas los troncos más delgados.\n");
    AddDetail(({"tronco","troncos"}),"Son troncos de árboles caídos en algún "
        "bosque río arriba, atrapados aquí contra los bajíos del cauce.\n");
    SetExplorable(1);
    ForbidAllMagic("Antiguos hechizos impiden hacer magia en esta montaña.\n");
    SetSoundEnvironment(SND_AMBIENTES("rio_cerca"));
    AddExit("nadar",SF(nadando));
}

init()
{
    ::init();
    write("¡Por fin! ¡Lo conseguiste!\n");
    call_out("verpiedra",1);
}
