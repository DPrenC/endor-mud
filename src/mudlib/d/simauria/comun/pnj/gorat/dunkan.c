
#include <properties.h>
inherit NPC;
create() {
    ::create();
    SetStandard("Dunkan", "humano", 11, GENDER_MALE);
    SetShort("El responsable del censo");
    SetLong("Dunkan es un hombre delgado y de media estatura. Viste elegantemente y "
    "tiene pinta de sobrarle inteligencia.\n  A pesar de su carencia de músculos tiene "
    "buena presencia.\n");
    AddId(({"hombre","dunkan","humano","oficinista"}));
    SetCitizenship("gorat");
    InitChats(4,({"El oficinista silba.\n",
    "El oficinista hojea el libro de censos.\n",
    "El oficinista se queja.\n",
    "El oficinista dice: Hmmm, a este no lo he visto nunca....\n",
    "El oficinista repasa el censo.\n",
    "El hombre te pregunta: quieres algo?\n",
    "El hombre dice: Hmm, este me ha dado mal sus datos\n Y tira la ficha del censo "
    "a un cubo.\n"}));

    AddQuestion(({"informacion","censo", "información"}),
    "El hombre dice: para censarte escribe censar, y para consultar el censo, "
    "consultar, sin parámetros, pues solo puede censarse o consultar uno mismo.\n");
}
