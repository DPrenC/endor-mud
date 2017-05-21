
#include <properties.h>
#include "./path.h"

inherit SIM_ROOM;

create() {
    ::create();

    SetIntShort("un dormitorio");
    SetIntLong(
   "Estás en uno de los dormitorios del castillo. Una gran lámpara cuelga del "
    "techo, sus cristales producen destello, prueba de su limpieza. La cama parece "
    "blanda y cómoda, perfecta para dormir agusto un rato.\n Un escabel de color "
    "púrpura descansa a sus piés.\n");
    SetIntBright(45);
    AddExit("norte", "./pasillo4");
    AddDoor("norte", "una puerta celeste",
    "Es una puerta de madera, aunque tiene algún tratamiento especial, pues su color "
    "celeste no debe de ser natural.\n",
    ({"puerta", "puerta de madera", "puerta celeste", "puerta del sur"}));
    SetLocate("el castillo de Nandor");
    AddItem(PNJCASTILLO("hija_noble"), REFRESH_DESTRUCT);
    AddItem(PNJCASTILLO("sirvienta_lady"), REFRESH_DESTRUCT);
}