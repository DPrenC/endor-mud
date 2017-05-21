/*****************************************************************************************
 ARCHIVO:       tdhab34.c
 AUTOR:         Chantiel, Alura
 FECHA:         08-5-1997
 DESCRIPCI�N:   Templo de Dehim.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"
#include <moving.h>

inherit ROOM;

int vis;
object ob;

int mirar_bote(string str);

public void create()
{
    ::create();

    SetIntShort("la enfermer�a");
    SetIntLong("Te encuentras en lo que antes era una enfermer�a. La habitaci�n est� "
          "llena de camas polvorientas y varios armarios. Tambi�n hay estanter�as en "
          "las que hay muchos frascos rotos. Tal vez quede alguno intacto.\n");
    SetIndoors(1);
    SetIntBright(40);
    AddDetail(({"estanter�as", "estanterias"}), "Casi todos los botes est�n rotos, tal "
          "vez alguno se halla salvado.\n");

    //Metido bote de l�quido aleatorio de +fue
    AddRoomCmd("buscar", "mirar_bote");

    AddExit("sur", ALULAGO("templo/tdhab30.c"));
    AddExit("suroeste", ALULAGO("templo/tdhab31.c"));
    AddExit("este", ALULAGO("templo/tdpas8.c"));

    AddItem(ALUPNJ("adepto"), REFRESH_DESTRUCT, 1);
}

int mirar_bote(string str)
{
    if (vis == 0 &&
       (str == "frasco" || str == "frascos" || str == "bote" || str == "botes"))
    {
        ob = clone_object(ALUOBJ("magico/potf.c"));
        ob->move(TO, M_SILENT);
        write("Ves un bote intacto lleno de un l�quido rojo.\n");
        say(CAP(TNAME) + "descubre un frasco.\n");
        vis = 1;
        return 1;
    }
    return 0;
}

public varargs void reset()
{
	  vis = 0;
	  ::reset();

}
