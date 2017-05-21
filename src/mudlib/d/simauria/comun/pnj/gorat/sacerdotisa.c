
#include "./path.h"
inherit NPC;
#include <properties.h>
create ()
{
    ::create();
    SetStandard("Marla","humano",13,GENERO_FEMENINO);
    SetShort("una sacerdotisa");
    SetLong(
    "Es Marla, la sacerdotisa de la diosa Valevissa, una mujer alta, y fuerte "
    "está apenada porque alguien le ha roto el cáliz sagrado con el que realizaba "
    "las ofrendas a la diosa para que favoreciera la pesca.\n");
    AddId(({"mujer", "humana","Sacerdotisa","Marla", "marla"}));
    SetCitizenship("gorat");
    InitChats(3,({
          "La sacerdotisa dice: ¿quién podría ayudarme?\n",
        "La sacerdotisa exclama:\n ¡Me han roto el cáliz, que voy a hacer ahora!\n"}));

    AddQuestion(({"cáliz", "caliz"}),
    "Marla dice: es el cáliz para la ceremonia de la pesca, si pudieras conseguirme otro "
    "te estaría eternamente agradecida, el Cáliz debe estar forjado en vidrio "
    "proveniente de las playas del islote donde se apareció la diosa por primera "
    "vez, y debe tener una sólida base de oro tallada a mano.\n"), 1;
    AddQuestion("islote",
    "Marla dice: Según cuenta la leyenda, la diosa se le apareció a unos pescadores que se "
    "perdieron en el mar durante una tormenta, les guió a un pequeño islote "
    "que se encuentra en las cercanías de gorat, donde se le levantó una estatua, "
    "allí es donde tienes que conseguir la arena para poder hacer el cáliz.\n", 1);
    AddQuestion("talla",
    "Marla dice: El caliz sagrado tiene que estar tallado con unas runas que enseñó la diosa "
    "al grupo de pescadores, sin las cuales el caliz no tiene validez.\n", 1);
}

public varargs int DoDamage (int damage, int type, int gentle, mixed xtras) {

    if(QueryHP()==QueryMaxHP())
        write("La sacerdotisa grita: ¡Valevissa, protégeme!\n");

    return ::DoDamage(damage, type, gentle, &xtras);
}
