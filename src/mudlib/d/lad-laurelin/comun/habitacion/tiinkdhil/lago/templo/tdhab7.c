/*****************************************************************************************
 ARCHIVO:       tdhab7.c
 AUTOR:         Chantiel, Alura
 FECHA:         08-5-1997
 DESCRIPCI�N:   Templo de Dehim.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"

inherit ROOM;

public void create()
{
    ::create();

    SetIntShort("el sal�n");
    SetIntLong("Est�s en una gran sala, bastante m�s estropeada que el resto del "
          "templo. A tu lado hay un c�rculo grisaceo que aparentemente no ha sido "
          "afectado por el polvo y la suciedad. Si avanzas un poco al oeste te situar�s "
          "en el centro. El sal�n contin�a a tu alrededor.\n");
    SetIndoors(1);
    SetIntBright(40);
    AddDetail("circulo", "Extra�as runas dibujan su interior.\n");
    AddDetail("techo", "Es una inmensa b�veda decorada con expresivos dibujos del "
          "dios. Dehim es el sanador celestial, la esperanza de los enfermos.\n");

    AddExit("este", ALULAGO("templo/tdhab6.c"));
    AddExit("oeste", ALULAGO("templo/tdhab8.c"));
    AddExit("norte", ALULAGO("templo/tdhab15.c"));
    AddExit("sur", ALULAGO("templo/tdhab3.c"));
    AddExit("noroeste", ALULAGO("templo/tdhab16.c"));
    AddExit("suroeste", ALULAGO("templo/tdhab4.c"));

    AddItem(ALUPNJ("rata"), REFRESH_DESTRUCT, 1);
    AddItem(ALUPNJ("vampiro"), REFRESH_DESTRUCT, 1);
}