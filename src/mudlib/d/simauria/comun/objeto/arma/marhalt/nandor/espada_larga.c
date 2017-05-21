#include <properties.h>
#include <combat.h>
inherit WEAPON;
create()
{
    ::create();
    SetStandard(WT_ESPADA, 7, P_SIZE_LARGE, M_ACERO);
    SetShort("una espada larga");
    SetLong("Es una espada larga sencilla pero muy funcional. La hoja de acero mide "
    "aproximadamente un metro, con filos rectos y punta triangular poco pronunciada.\n"
    "A lo largo de la hoja aunque sin llegar a su extremo, tiene una leve acanaladura "
    "que sirve para aligerar un poco el peso del arma y prestarle flexibilidad.\n"
    "La sencilla empuñadura de gabilanes rectos cuyos extremos acaban en ángulo recto "
    "hacia adelante y pomo cuadrangular, está adornada con unos bajorrelieves "
    "romboidales que evitan el deslizamiento de la mano al propinar golpes y tajos.\n"
    "La espada larga es la mejor compañera de aventureros, guerreros y caballeros "
    "y se puede adquirir en casi cualquier parte.\n");
    AddId(({"espada larga", "larga", "arma", "espada"}));
    Set(P_GENDER, GENDER_FEMALE);
    SetWeight(3500);
    SetNumberHands(1);
}
