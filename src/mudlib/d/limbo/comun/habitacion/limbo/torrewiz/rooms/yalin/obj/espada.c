#include "path.h"
#include <combat.h>
#include <properties.h>
#include <materials.h>
#include <moving.h>
inherit WEAPON;

create()
{
    ::create();
    SetStandard(WT_ESPADA,15,P_SIZE_MEDIUM,M_ACERO);
    SetShort("una espada");
    SetLong("Es una poderos�sima espada de acero, especialmente invocada por "
        "Yalin para su ni�o.\nLleva grabado en una cara el emblema de la reina de las hadas: "
        "una varita m�gica cruzada por una espada, y un extra�o escudo en la otra.\n");
    AddSubDetail(({"escudo"}),"Ves un c�rculo rojo sobre fondo blanco, y en su interior una "
        "torre cruzada por una S, lo que te hace pensar que tal vez sea un s�mbolo de los "
        "inmortales de Simauria.\n");
    SetIds(({"espada","espada de acero"}));
    Set(P_GENDER,GENERO_FEMENINO);
    Set(P_NUMBER,NUMERO_SINGULAR);
    SetNumberHands(1);
    SetQuality(100);
    SetResetQuality(101);
    Set(P_CANT_STEAL,1);
    Set(P_NOSELL,"No podr�s venderla, nadie quiere problemas con los inmortales...\n");
}

public varargs int move(mixed dest, int method, mixed extra)
{
	  if (method == M_GET && TP != YALIN)
	  {
	      write("Te dispones a cogerla, pero de pronto recuerdas que s�lo has visto a una "
    	      "persona llevar una espada como �sa: el ni�o de Yalin. Entonces te llama la atenci�n "
    	      "el escudo, y decides no arriesgarte a tener problemas con los dioses.\n");
	      return ME_NO_GET;
	  }
	  return ::move(dest, method, extra);
}
    