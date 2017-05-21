/****************************************************************************
Fichero: viejo01.c
Autor: Riberales
Creación: 09/12/05
Descripción: Un viejo en la posada.
****************************************************************************/

#include "path.h"
#include <properties.h>
#include <guild.h>

inherit NPC;

string tirar_libro();


public create()
{
    ::create();

    seteuid(getuid());

    SetStandard("Marvag","orco",([GC_NINGUNO:45]),GENDER_MALE);
    SetShort("Marvag");
    SetLong("Marvag es un orco de pelaje marrón y largos colmillos que le "
               "salen de una boca que parece que no deje de decir "
               "barbaridades. Su cara no muestra afabilidad, pero su raza no "
               "es que se caracterice por ello.\n");

    SetIds(({"marvag","Marvag","orco"}));

    AddQuestion(({"pueblo","el pueblo"}),
              "Marvak se gira hacia ti y te dice: ¿Y a ti qué demonios te "
              "importa lo que me pase con mi pueblo?\n",1);

    InitChats(4,({
              "Marvag grita: ¡Qué asco de pueblo!\n",
              "Marvag escupe al suelo.\n",
              "Marvag dice: Si pudiera irme, iba a estar aquí aguantando "
            "esta porquería de pueblo.\n",SF(tirar_libro)}));

    AddItem("/obj/money",REFRESH_REMOVE,(["Money":([
            "cobre":5+random(10),
            "plata":4+random(8),
            "oro":5+random(3)])]));
}


string tirar_libro()
{
    object libro;
    object env = environment();
    object sabio = present("sabio",env);
    if (libro = present("libro_orco",env))
    {
        string msg = "Marvag coge el libro del suelo y sigilosamente lo "
                     "echa a la chimenea.\n";
        if (env->QueryEstadoChimenea())
        {
            env->SetIntSmell("Un fuerte olor a papel quemado "
                             "inunda la estancia.\n");
            msg += "El libro comienza a arder rapidamente mientras Marvag "
                   "sonríe divertido.\n";
        }
        libro->remove();
        return msg;
    }

    if (sabio && present("libro",sabio))
    {
        return "Marvag dice: Eh, Proruk, te vas a volver loco con tanta lectura.\n";
    }
    return "Marvag te mira con mala cara.\n";
}
