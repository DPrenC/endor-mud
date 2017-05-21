/*
DESCRIPCION  : cantera al norte del bosque de Morak
FICHERO      : cantera1.c
MODIFICACION : 16-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
#include AK_MACRO
inherit BOSQUE_MORAK("cantera");

create()
{
    ::create();
   SetIntShort("la entrada a la cantera del bosque de Morak");
    SetIntLong("Estás en medio de la cantera del bosque de Morak. En el "
        "suelo arenoso de la cantera puedes ver algunas de las profundas "
        "huellas que dejan las carretas cargadas con las pesadas piedras que "
        "se extraen de este lugar.\nAl oeste de aquí se halla una rústica "
        "cabaña de madera y al sur se extiende el bosque.\n");
    AddExit("norte",BOSQUE_MORAK("cantera3"));
    AddExit("oeste",BOSQUE_MORAK("cantera_cabanya"));
    AddExit("sur",BOSQUE_MORAK("bosque16"));
    AddExit("este",BOSQUE_MORAK("cantera0"));
}
