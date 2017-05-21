#include "path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>
#include <moving.h>

inherit ARMOUR;

create()
{
    ::create();
    SetStandard(AT_TUNICA,1,P_SIZE_MEDIUM,M_TELA);
    Set(P_GENDER,GENERO_FEMENINO);
    Set(P_NUMBER,NUMERO_SINGULAR);
    SetIds(({"tunica","t�nica"}));
    AddAdjective(({"seda","de seda"}));
    SetShort("una t�nica de seda");
    SetLong("Es una preciosa t�nica de fina seda blanca, con listas alternas azules y verdes en las mangas y un bordado "
        "de oro en los pu�os y el borde inferior, y un bonito escudo en el pecho.\n");
    AddSubDetail(({"escudo"}),"Ves un c�rculo rojo sobre fondo blanco, y en su interior una "
        "torre cruzada por una S, lo que te hace pensar que tal vez sea un s�mbolo de los "
        "inmortales de Simauria.\n");
    Set(P_CANT_STEAL,1);
    Set(P_NOSELL,"No podr�s venderla, nadie quiere problemas con los inmortales...\n");
}

public varargs int move(mixed dest, int method, mixed extra)
{
	   if (method == M_GET && TP != YALIN)
	   {
	       write("Te dispones a cogerla, pero de pronto recuerdas que jam�s has visto a nadie "
    	       "llevar una t�nica semejante, s�lo a Yalin y su ni�o. Entonces te llama la "
    	       "atenci�n el escudo que la adorna, y decides no arriesgarte a tener problemas con "
    	       "los dioses.\n");
	       return ME_NO_GET;
	   }
	   return ::move(dest, method, extra);
}
    