/****************************************************************************
Fichero: manak.c
Autor: Riberales
Creaci�n: 06/12/05
Descripci�n: Un peacho orco en Azzor.
****************************************************************************/

#include "path.h"
#include <properties.h>
#include <guild.h>
#include <combat.h>

#define GRITO_GUERREROS "Est�s asustado.\n"
inherit NPC;

public create()
{
    ::create();
    seteuid(getuid());

    SetStandard("Manak","orco",([GC_LUCHADOR:103]),GENDER_MALE);
    SetShort("Manak el marino");
    SetLong("Manak es un orco, dedicado al mar y sus secretos durante toda "
            "su vida. Su espalda, brazos, piernas, y cicatrices y tatuajes "
            "por todo su cuerpo te demuestran que desde joven se tom� su "
            "profesi�n muy en serio. Su cara muestra fiereza, rasgo l�gico al "
            "tratarse de un orco, aunque en el fondo de sus ojos puedes "
            "divisar un atisbo de sabidur�a, imprescindible para surcar las "
            "aguas con �xito.\n");

    AddId(({"marino","marinero","marino mercante","marinero mercante",
            "manak","Manak","orco"}));

    AddSubDetail(({"cicatriz","cicatrices"}),
                   "Observas que las tiene distribuidas por todo su cuerpo, "
                   "formando grotescos surcos, pero que le dan un toque de "
                   "respeto a su portador.\n");

    AddSubDetail(({"tatuaje","tatuajes"}),
                   "Son s�mbolos ininteligibles, quitando uno que lleva en "
                   "el brazo izquierdo que muestra un hacha clavada en el "
                   "tronco de un �rbol.\n");

    AddQuestion(({"arbol","�rbol","hacha","hacha de arbol","hacha de �rbol"}),
                  (:"Manak dice: " +CAP(TNAME)+ ", el hacha y el �rbol era el "
                    "s�mbolo de nuestro mercante. Nosotros �ramos comerciantes "
                    "pac�ficos y nunca tuvimos problemas con ninguna raza.\n":));


    InitChats(3,({
             "Manak murmura: Ay, dulce y salado mar... �que habr�a sido de mi "
             "vida sin ti?\n","Manak dice: Marinero y mercante, eso s� son "
            "profesiones.\n"}));

    InitAChats(2,({"Manak grita: Pero bueno! �Ser� posible?\n"
                   "Manak gru�e.\n"}));


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