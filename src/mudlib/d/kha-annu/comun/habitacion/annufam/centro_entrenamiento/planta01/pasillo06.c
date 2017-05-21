/****************************************************************************
Fichero: pasillo06.c
Autor: Riberales
Fecha: 06/03/2006
Descripción: Pasillo del CAGE, salida a arena.
****************************************************************************/


#include "path.h"

inherit HAB_PRIMERA_ANNUFAM("pasillo_base");

create()
{
    ::create();

    SetIntShort("un pasillo del centro");
    SetIntLong("Estás en la salida del pasillo a la Arena. Aquí los reclutas "
               "enanos esperan su turno para salir a poner en práctica las "
               "habilidades que han estudiado en el interior. Al sur puedes "
               "ver la escalera que da acceso a los pisos superiores y al "
               "norte, la Arena.\n");

    AddDetail(({"pared","paredes"}),
                "En esta parte del pasillo parece que los enanos han decidido "
                "trabajarse un poco más lo de los detalles, pero muy poco, la "
                "verdad. Apoyados en la pared puedes ver unos bancos sobre "
                "los que los guerreros aguardan que les llegue su turno para "
                "salir a La Arena. Imaginas que tras los combates también los "
                "utilizarán para descansar.\n");

    AddDetail(({"banco","bancos"}),
             "Son unos bancos de madera en no muy buen estado. Los enanos "
             "los utilizan para esperar su turno o para descansar del "
             "entrenamiento en la arena.\n");

    AddDetail("arena",
              "En la parte de fuera ves el principio de una gran explanada de "
              "arena, donde se entrenan los guerreros enanos.\n");

    AddExit("norte",HAB_ARENA_ANNUFAM("arena51"));
    AddExit("sur",HAB_PRIMERA_ANNUFAM("pasillo05"));

    AddItem(PNJ_CENTRO_ANNUFAM("recluta"), REFRESH_DESTRUCT);
    AddItem(PNJ_CENTRO_ANNUFAM("soldado"), REFRESH_DESTRUCT);
    AddItem(PNJ_CENTRO_ANNUFAM("maestro_guerrero"), REFRESH_DESTRUCT);

}
