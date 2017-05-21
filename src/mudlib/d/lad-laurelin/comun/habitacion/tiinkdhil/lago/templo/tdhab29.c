/*****************************************************************************************
 ARCHIVO:       tdhab29.c
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

    SetIntShort("la biblioteca");
    SetIntLong("Entras en una pequeña habitación repleta de estanterías con libros, y "
          "en cuyo centro hay una mesa sencilla, blanca por el polvo. No queda gran cosa "
          "de los libros, pues los muebles están medio carbonizados. Alguien no quería "
          "que se leyeran.\n");
    SetIntNoise("De algún lugar viene un lamento desgarrador.\n");
    SetIndoors(1);
    SetIntBright(40);
    //anyadir funcion buscar_libros y que saque algún libro de magia curativa
    AddDetail("libros", "Desgraciadamente están tan destrozados que no consigues "
          "entender nada.\n");
    AddDetail("mesa", "Es una sucia mesa medio quemada. No tiene nada interesante.\n");

    AddExit("sur", ALULAGO("templo/tdhab13.c"));

    AddItem(ALUPNJ("monjef"), REFRESH_DESTRUCT, 1);
    AddItem(ALUPNJ("vampiro"), REFRESH_DESTRUCT, 1);
}


