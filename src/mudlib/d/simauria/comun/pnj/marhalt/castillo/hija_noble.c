/****************************************************************************
Fichero: hija_noble.c
Autor: Ratwor
Fecha: 17/09/2006
Descripción: una de las hijas del noble de Nandor
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
    SetShort("lady sherilin Dhes-Bláin");
    SetLong("Sherilin es la hija mayor del noble, se trata de una hermosa adolescente "
    "de suaves rasgos.\n  En Su angelical rostro, enmarcado en una cascada de bucles "
    "dorados,  destacan dos inocentes ojos azules. En su cuerpo, esquisitamente tapado "
    "por nobles ropajes, se insinúa la juventud, unos firmes senos junto a unas "
    "caderas poco desarrolladas, dejan constancia de su escasa edad.\n");
    SetWeight(50000);
    SetCitizenship("nandor");
    SetSmell("Un fresco aroma a labanda sale de su piel como si de un efecto natural se"
        " tratase.\n");
    AddSubDetail(({"pecho", "pechos", "senos", "tetas"}),
        "Para la edad que tiene quizá sean demasiado grandes, aunque, ni siquiera por su"
        " tamaño, se mantienen firmes y  ríjidos como si de músculos se tratara.\n");
    InitAChats(5, ({"Sherilin grita: ¡guardias!, ¡me atacan!\n",
        "Sherilin grita: ¡fuera de aquí salvaje!\n"
        "Sherilin dice: ¿serás mala bestia?\n",
        "Sherilin dice: mi padre te descuartizará y dará tus restos a los cuervos.\n"}));
    InitChats(3, ({
        "Sherilin suspira.\n",
        "Sherilin se mira interrogante.\n"}));
    Set(P_CANT_STEAL, "Sherilin te dice malhumorada: ¡no se te ocurra acercarte tanto a"
        " mí.\n");
    AddQuestion(({"padre", "noble", "rocher"}), "Sherilin te dice: umm mi padre, abajo lo"
        " tendrás supongo, pero para saber de él no tienes que venir a molestarme a mi,"
        " para eso están los sirvientes.\n", 1);
    AddQuestion(({"madre", "lilet", "Lilet", "su madre"}),
        "Sherilin te dice:¿mi madre?, déjame de preguntas.\n", 1);
    SetShrugMsg("Sherilin grita: ¡déjame de preguntas!\n");
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
