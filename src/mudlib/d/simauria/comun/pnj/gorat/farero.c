
#include <properties.h>
inherit NPC;
create() {
    ::create();
    SetStandard("El farero", "humano", 10+d2(), GENDER_MALE);
    SetShort("El farero");
    SetLong("Es un hombre de avanzada edad, con el pelo canoso y la cara arrugada"
    ", quizá por eso lo tienen en el faro como vigilante.\n");
    AddId(({"farero", "hombre"}));
    Set(P_NOGET,"No alcanzas a cogerlo.\n");
    SetCitizenship("gorat");
    AddQuestion("faro", "El farero dice: Aquí está esta vieja mole de piedra, lleva "
    "aguantando el temporal más tiempo que todos nosotros juntos.\n Pero ahora "
    "está averiado, la lente se ha roto y yo ya no tengo cuerpo para arreglarlo.\n");
    AddQuestion(({"información","informacion", "problema", "ayuda"}),
    "El hombre dice: El faro de Gorat se ha estropeado, necesito que alguien "
    "lo repare, si no mi empleo corre peligro, y yo ya no tengo edad para este "
    "tipo de trabajos.\n", 1);
    AddQuestion(({"arreglar faro","arreglar","quest"}),
   "El farero te dice: 'Necesitas el Certificado Oficial de Simauria para poder "
   "arreglar el faro.\n", 1);
    AddQuestion(({"JK23-H","impreso","certificado"}),
   "El farero suspira y te dice: 'El impreso lo tienes que pedir en la casa "
   "del registro que está al lado del ayuntamiento. El código del impreso es "
   "el JK23-H. Recuerda pedirlo por este nombre, ya que por otro no lo conocen.\n", 1);
    AddQuestion(({"código","codigo"}),
    "El farero te dice: 'El código del impreso es el JK23-H. Recuérdalo bien.'\n", 1);
    AddQuestion("lente", "El farero dice:\n La verdad es que es complicado encontrar "
    "una pieza como esa, no se me ocurre donde podrías buscarla. Quizá podrías "
    "recurir al contrabando como último recurso.\n", 1);
}
