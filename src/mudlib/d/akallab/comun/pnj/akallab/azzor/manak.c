/****************************************************************************
Fichero: manak.c
Autor: Riberales
Creación: 06/12/05
Descripción: Un peacho orco en Azzor.
****************************************************************************/

#include "path.h"
#include <properties.h>
#include <guild.h>
#include <combat.h>

#define GRITO_GUERREROS "Estás asustado.\n"
inherit NPC;

public create()
{
    ::create();
    seteuid(getuid());

    SetStandard("Manak","orco",([GC_LUCHADOR:103]),GENDER_MALE);
    SetShort("Manak el marino");
    SetLong("Manak es un orco, dedicado al mar y sus secretos durante toda "
            "su vida. Su espalda, brazos, piernas, y cicatrices y tatuajes "
            "por todo su cuerpo te demuestran que desde joven se tomó su "
            "profesión muy en serio. Su cara muestra fiereza, rasgo lógico al "
            "tratarse de un orco, aunque en el fondo de sus ojos puedes "
            "divisar un atisbo de sabiduría, imprescindible para surcar las "
            "aguas con éxito.\n");

    AddId(({"marino","marinero","marino mercante","marinero mercante",
            "manak","Manak","orco"}));

    AddSubDetail(({"cicatriz","cicatrices"}),
                   "Observas que las tiene distribuidas por todo su cuerpo, "
                   "formando grotescos surcos, pero que le dan un toque de "
                   "respeto a su portador.\n");

    AddSubDetail(({"tatuaje","tatuajes"}),
                   "Son símbolos ininteligibles, quitando uno que lleva en "
                   "el brazo izquierdo que muestra un hacha clavada en el "
                   "tronco de un árbol.\n");

    AddQuestion(({"arbol","árbol","hacha","hacha de arbol","hacha de árbol"}),
                  (:"Manak dice: " +CAP(TNAME)+ ", el hacha y el árbol era el "
                    "símbolo de nuestro mercante. Nosotros éramos comerciantes "
                    "pacíficos y nunca tuvimos problemas con ninguna raza.\n":));


    InitChats(3,({
             "Manak murmura: Ay, dulce y salado mar... ¿que habría sido de mi "
             "vida sin ti?\n","Manak dice: Marinero y mercante, eso sí son "
            "profesiones.\n"}));

    InitAChats(2,({"Manak grita: Pero bueno! ¿Será posible?\n"
                   "Manak gruñe.\n"}));


}

void no_se_asusta()
{
    tell_room(environment(),"Parece que " + QueryName() + " no se ha asustado mucho.\n");
}


public varargs int SetCombatDelay(int time, string s)
{
    if (random(100) > 40 && s == GRITO_GUERREROS)
    // no le afecta
    {
        if (find_call_out("no_se_asusta") == -1) call_out("no_se_asusta",1);
        return 0;
    }
    return ::SetCombatDelay(time, s);
}