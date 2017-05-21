/****************************************************************************
Fichero: hija_noble.c
Autor: Ratwor
Fecha: 17/09/2006
Descripci�n: una de las hijas del noble de Nandor
****************************************************************************/

#include "./path.h"
#include <properties.h>
#include <gremios.h>
inherit NPC;

create()
{
    ::create();

    SetStandard("Sherilin", "humano", ([GC_TORPE:11]), GENDER_FEMALE);
    AddId(({"hija", "sherilin", "adolescente", "chica", "humana", "lady"}));
    SetShort("lady sherilin Dhes-Bl�in");
    SetLong("Sherilin es la hija mayor del noble, se trata de una hermosa adolescente "
    "de suaves rasgos.\n  En Su angelical rostro, enmarcado en una cascada de bucles "
    "dorados,  destacan dos inocentes ojos azules. En su cuerpo, esquisitamente tapado "
    "por nobles ropajes, se insin�a la juventud, unos firmes senos junto a unas "
    "caderas poco desarrolladas, dejan constancia de su escasa edad.\n");
    SetWeight(50000);
    SetCitizenship("nandor");
    SetSmell("Un fresco aroma a labanda sale de su piel como si de un efecto natural se"
        " tratase.\n");
    AddSubDetail(({"pecho", "pechos", "senos", "tetas"}),
        "Para la edad que tiene quiz� sean demasiado grandes, aunque, ni siquiera por su"
        " tama�o, se mantienen firmes y  r�jidos como si de m�sculos se tratara.\n");
    InitAChats(5, ({"Sherilin grita: �guardias!, �me atacan!\n",
        "Sherilin grita: �fuera de aqu� salvaje!\n"
        "Sherilin dice: �ser�s mala bestia?\n",
        "Sherilin dice: mi padre te descuartizar� y dar� tus restos a los cuervos.\n"}));
    InitChats(3, ({
        "Sherilin suspira.\n",
        "Sherilin se mira interrogante.\n"}));
    Set(P_CANT_STEAL, "Sherilin te dice malhumorada: �no se te ocurra acercarte tanto a"
        " m�.\n");
    AddQuestion(({"padre", "noble", "rocher"}), "Sherilin te dice: umm mi padre, abajo lo"
        " tendr�s supongo, pero para saber de �l no tienes que venir a molestarme a mi,"
        " para eso est�n los sirvientes.\n", 1);
    AddQuestion(({"madre", "lilet", "Lilet", "su madre"}),
        "Sherilin te dice:�mi madre?, d�jame de preguntas.\n", 1);
    SetShrugMsg("Sherilin grita: �d�jame de preguntas!\n");
}

int ayuda;
public varargs int Defend(int dam, int dam_type, mixed flags, string *xtras)
{
    object proteccion;
    if (!ayuda)
    {
        tell_room(environment(), "Los gritos de Lady Sherilin alertan a los guardias y "
        "acude un hombre de armas de inmediato para defenderla.\n");
        proteccion = clone_object(PNJ("marhalt/castillo/hombre_armas"));
        proteccion->move(environment(TO));
        ayuda=1;
    }

    return ::Defend(dam, dam_type, flags, &xtras);
}
