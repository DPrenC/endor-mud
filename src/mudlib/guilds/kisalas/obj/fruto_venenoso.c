/****************************************************************************
Fichero: fruto_venenoso.c
Autor: Kastwey
Fecha: 05/03/2006
Descripción: Un fruto venenoso, para el escuálido árbol del gremio de las kisalas
****************************************************************************/


#include <colours.h>
#include <properties.h>
#include <damage.h>
#include <combat.h>
#include "path.h"




inherit THING;

public int cmd_apretar(string str)
{
    object pl;
    if (!pl = TP) return 0;
    if (!str ||member(QueryIds(), str) < 0)
    {
        return notify_fail("¿Apretar qué?\n", NOTIFY_NOT_VALID);
    }
    write("Aprietas el fruto con fuerza...\n"
          "........................................\n" +
          TC_RED + "¡¡¡PLAFFFF!!" + TC_NORMAL + " El fruto explota, llenándote "
          "enter" + pl->QueryGenderEndString() + " de un jugo pegajoso y maloliente.\n"
          "Al instante, notas un intenso picor por todo el cuerpo...\n");
    say(CAP(NNAME(pl)) + " aprieta el fruto, que explota con un desagradable sonido. "
        "Del interior del mismo, salta un líquido maloliente y pegajoso, salpicándol" +
        pl->QueryGenderEndString() + " por todo el cuerpo. Al instante, ves como "
        "comienzan a salirle ronchas de un color rojo intenso.\n");
    pl->SetLong(pl->QueryLong() + "Tiene todo el cuerpo cubierto de unas feas "
                "y rojizas ronchas.\n");
    pl->SetSmell("¡Puag! Huele a... a... No sabes lo que es, pero es realmente "
                 "desagradable.\n");
    remove();
    return 1;
}



public int cmd_comer(string str)
{
    object pl;
    if (!pl = TP) return 0;
    if (!str || member(QueryIds(), str) < 0)
    {
        return notify_fail("¿Comer qué?\n");
    }
    if (pl->QueryFood() == pl->QueryMaxFood())
    {
        return notify_fail("No tienes hambre.\n", NOTIFY_NOT_VALID);
    }
    write("Abres la boca, y de un solo bocado te comes el extraño fruto. Al instante, "
          "notas un intenso ardor por la garganta... " + TC_RED + "¡¡¡EL ARDOR "
          "ES INTENSÍSIMO Y SE TE EXTIENDE POR TODO EL CUERPO!!!" + TC_NORMAL +
          "...\n"
          "........................................\n");
    say(CAP(NNAME(pl)) + " se come una extraña fruta de un solo bocado. Al instante, "
        "ves como pone cara rara, y observas con asombro como todo su cuerpo "
        "toma una tonalidad rojiza. La verdad es que tiene aspecto de no estar "
        "pasándolo demasiado bien...\n"
        "........................................");
    pl->SetDieMsg("@#jug# murió por comerse algo que no debía...\n");
    pl->Defend(30, DT_POISON,
               DEFEND_F_NOLIV | DEFEND_F_NOMSG | DEFEND_NO_DEF_SK);
    if (pl->QueryHP() >= 0)
    // no muere
    {
        object env;
        write("Sin poder evitarlo, te aferras el estómago y vomitas hasta la primera "
              "papilla entre violentas arcadas.\n");
        say(CAP(NNAME(pl)) + " se aferra el estómago y vomita copiosamente.\n");
        pl->SetFood(-50);
        if (env = environment(pl))
        {
            seteuid(getuid());
            clone_object(AMAZONHOME "obj/vomito")->move(env);
        }
    }
    remove();
    return 1;
}





    create()
{
    ::create();
    SetShort("un pequeño fruto");
    SetLong("Se trata de un pequeño fruto, redondeado y de un color amarillo "
            "intenso. Posee una piel de tacto suave; casi te da la sensación "
            "de que si lo aprietas más de la cuenta podría reventar fácilmente.\n");
    Set(P_NOSELL,1);
    SetValue(0);
    SetWeight(150);
    SetIds(({"fruto","pequeño fruto","fruto amarillo"}));
}

init()
{
    ::init();
    if (environment() != TP) return;
    add_action("cmd_comer","comer");
    add_action("cmd_apretar","apretar");
}
