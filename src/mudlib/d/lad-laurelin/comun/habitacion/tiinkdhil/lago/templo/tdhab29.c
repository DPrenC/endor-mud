/*****************************************************************************************
 ARCHIVO:       tdhab29.c
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

    SetIntShort("la biblioteca");
    SetIntLong("Entras en una peque�a habitaci�n repleta de estanter�as con libros, y "
          "en cuyo centro hay una mesa sencilla, blanca por el polvo. No queda gran cosa "
          "de los libros, pues los muebles est�n medio carbonizados. Alguien no quer�a "
          "que se leyeran.\n");
    SetIntNoise("De alg�n lugar viene un lamento desgarrador.\n");
    SetIndoors(1);
    SetIntBright(40);
    //anyadir funcion buscar_libros y que saque alg�n libro de magia curativa
    AddDetail("libros", "Desgraciadamente est�n tan destrozados que no consigues "
          "entender nada.\n");
    AddDetail("mesa", "Es una sucia mesa medio quemada. No tiene nada interesante.\n");

    AddExit("sur", ALULAGO("templo/tdhab13.c"));

    AddItem(ALUPNJ("monjef"), REFRESH_DESTRUCT, 1);
    AddItem(ALUPNJ("vampiro"), REFRESH_DESTRUCT, 1);
}


