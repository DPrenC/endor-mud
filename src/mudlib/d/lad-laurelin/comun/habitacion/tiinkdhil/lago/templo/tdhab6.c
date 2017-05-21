/*****************************************************************************************
 ARCHIVO:       tdhab6.c
 AUTOR:         Chantiel, Alura
 FECHA:         08-5-1997
 DESCRIPCIÓN:   Templo de Dehim.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"

inherit ROOM;

public void create()
{
    ::create();

    SetIntShort("el salón");
    SetIntLong("Esta parte del edificio ha sufrido serios derrumbamientos. A ambos "
          "lados de ti hay grandes rocas y partes de alguna columna. Sólo te puedes "
          "mover hacia delante.\n");
    SetIndoors(1);
    SetIntBright(40);
    AddDetail("techo", "Tiene muchas grietas, y está en parte destrozado, pero a pesar "
          "de ello puedes distinguir que tenía escenas pintadas de algún tipo.\n");

    AddExit("este",ALULAGO("templo/tdpas6.c"));
    AddExit("oeste",ALULAGO("templo/tdhab7.c"));
}
