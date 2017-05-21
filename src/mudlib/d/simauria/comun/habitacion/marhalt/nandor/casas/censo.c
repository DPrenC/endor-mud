/**************************************************************************/
/*                                                                        */
/*  Censo de Nandor                                                       */
/*  /d/simauria/comun/habitacion/marhalt/nandor/casas/censo               */
/*  [k] Kintups                                                           */
/*                                                                        */
/**************************************************************************/

#include "./path.h"

inherit "/room/censo";
inherit SCHEDULER_ROOM;
create() {
    ::create();
    SetCity("Nandor");
    SetLocate("Aldea de Nandor");
    SetIntShort("el censo de Nandor");
    SetIntLong("Te encuentras en el censo de la aldea de Nandor, donde te puedes hacer "
    "aldeano de esta noble villa .\n Si necesitas información pregúntale al responsable"
    " del censo.\n");
    SetIntBright(30);
    AddExit("abajo", "./casa4");
    AddItem(PNJ("marhalt/lewl"),REFRESH_DESTRUCT,1);
    SetMainRoom("./casa4");
    SetNotifyExits(({}));
    SetLastDest("../calle42n");
}
