#include "path.h"
#include <properties.h>
#include <materials.h>
#include <combat.h>
#include <moving.h>
inherit ARMOUR;

create()
{
    ::create();
    SetStandard(AT_BOTAS, 2,P_SIZE_MEDIUM,M_TELA);
    SetShort("unas zapatillas de terciopelo");
    SetLong("Son unas lindas zapatillas de terciopelo negro, forradas de seda por dentro.\nSobre el empeine llevan bordado "
        "un escudo, y sobre él, justo donde empieza a verse el pie del niño, una hebilla de plata sostiene un lazo de raso "
        "rojo en forma de rosa.\n");
    AddSubDetail(({"escudo"}),"Ves un círculo rojo sobre fondo blanco, y en su interior una "
        "torre cruzada por una S, lo que te hace pensar que tal vez sea un símbolo de los "
        "inmortales de Simauria.\n");
    SetIds(({"zapatillas"}));
    AddAdjective(({"negras","de terciopelo","lindas"}));
    Set(P_GENDER,GENERO_FEMENINO);
    Set(P_NUMBER,NUMERO_PLURAL);
    SetQuality(100);
        SetResetQuality(100);
    Set(P_CANT_STEAL,1);
    Set(P_NOSELL,"No podrás venderlas, nadie quiere problemas con los inmortales...\n");
}

public varargs int move(mixed dest, int method, mixed extra)
{
	   if (method == M_GET && (TP != YALIN))
	   {
	       write("Te dispones a cogerlas, pero de pronto recuerdas que jamás has visto a nadie llevar unas zapatillas como "
	           "ésas, salvo al niño de la reina. Entonces te llama la atención el emblema que las adorna, y decides no "
	           "arriesgarte a tener problemas con los dioses.\n");
	       return ME_NO_GET;
	   }
	   return ::move(dest, method, extra);
}
    