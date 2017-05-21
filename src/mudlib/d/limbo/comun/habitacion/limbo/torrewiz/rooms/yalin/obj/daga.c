#include "path.h"
#include <combat.h>
#include <properties.h>
#include <materials.h>
#include <moving.h>
inherit WEAPON;

create()
{
    ::create();
    SetStandard(WT_CUCHILLO,15,P_SIZE_MEDIUM,M_ACERO);
    SetShort("una daga de plata");
    SetLong("Es una bell�sima daga, cuya extra�a factura te hace pensar que no es de este mundo. Cincelada en una �nica "
        "pieza de plata, su pu�o est� guarnecido por hileras de esmeraldas, y dos cabezas de gato con ojos de topacio "
        "amarillo forman la cruz de la guarda.\nS�lo al mirarla, sientes helarse tu coraz�n, por lo que adivinas el "
        "terrible poder que emana de ella.\nEn el centro de la cruz, puedes ver un emblema en un lado y un escudo en el "
        "otro, y sobre la hoja, extremadamente afilada, puedes ver grabada una inscripci�n.\n");
    AddSubDetail(({"escudo"}),"Ves un c�rculo rojo sobre fondo blanco, y en su interior una "
        "torre cruzada por una S, lo que te hace pensar que tal vez sea un s�mbolo de los "
        "inmortales de Simauria.\n");
    AddSubDetail(({"emblema"}),"Ves el emblema de la Reina de las Hadas: una varita m�gica cruzada por una espada.\n");
    AddSubDetail(({"inscripcion","inscripci�n","grabado"}),"'Preciosa y m�gica como el amor, como el amor hiero y mato.'\n");
    SetIds(({"daga","daga de plata","daga magica","daga m�gica"}));
    Set(P_GENDER,GENERO_FEMENINO);
    Set(P_NUMBER,NUMERO_SINGULAR);
    SetNumberHands(1);
    SetQuality(101);
    SetResetQuality(100);
    Set(P_CANT_STEAL,1);
    Set(P_NOSELL,"No podr�s venderla, nadie quiere problemas con los inmortales...\n");
}

public varargs int move(mixed dest, int method, mixed extra)
{
	  if (method == M_GET && TP!=YALIN)
	  {
	      write("Te dispones a cogerla, pero de pronto recuerdas que a la �nica que has visto llevar "
    	      "una daga semejante es la Reina Yalin.\nEntonces te llama la atenci�n el emblema que "
    	      "la adorna, y  decides no arriesgarte a tener problemas con los inmortales.\n");
	      return ME_NO_GET;
	  }
	  return ::move(dest, method, extra);
}
    