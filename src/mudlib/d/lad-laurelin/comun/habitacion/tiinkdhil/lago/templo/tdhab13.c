/*****************************************************************************************
 ARCHIVO:       tdhab13.c
 AUTOR:         Chantiel, Alura
 FECHA:         08-5-1997
 DESCRIPCIÓN:   Templo de Dehim. ESTANCIA EN DONDE SE ENCUENTRA EL PASADIZO SECRETO
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"
//#include <door.h>

inherit ROOM;

int descubrir_tramp(string str);

public void create()
{
    ::create();

    SetIntShort("la habitación del orador");
    SetIntLong("Estás en lo que era la habitación del orador de los monjes. Delante de "
          "ti, entre dos estanterías para libros vacías, hay un escritorio cubierto de "
          "polvo. Oyes un largo y prolongado quejido cerca de ti. Al norte ves una "
          "puerta.\n");
    SetIntBright(40);
    SetIndoors(1);
    AddDetail("suelo", "Está cubierto de polvo. Cerca de la pared crees ver el "
          "contorno de un cuadrado. Tal vez si limpiaras un poco el sitio, lo verías "
          "mejor.\n");
    SetIntNoise("Parece que el lamento viene de alguna habitación contigua.\n");
    AddRoomCmd("limpiar", "descubrir_tramp");

    AddExit("norte", ALULAGO("templo/tdhab29.c"));
    AddExit("sur", ALULAGO("templo/tdpas6.c"));
    AddExit("este", ALULAGO("templo/tdhab12.c"));
    AddExit("trampilla", ALULAGO("templo/tdhab14.c"));
    HideExit("trampilla", 1);
    /*
    AddDoor("idtrampilla","abajo",ALULAGO("templo/tdhab14.c)","trampilla","Tiene un mango para ABRIRLA.\n",
      ([P_MATERIAL: M_BRONCE,P_PUERTA_OCULTA:PUERTA_ACTIVO, P_PUERTA_VIDA:173,P_PUERTA_VIDA_MAX:173 ]) );
    pasaje secreto a la habitacion 14 (tdhab14) abajo
    */
}

int descubrir_tramp(string str)
{
    object ob;

    if(!str || str != "suelo")
    {
        write("¿Limpiar QUÉ?\n");
        return 1;
    }
    write("Descubres una trampilla a tus pies.\n");
    /*
    if (ob = FindDoor("idtrampilla"))
    {
        ob->Set(P_PUERTA_OCULTA,PUERTA_INACTIVO);
    }
    */
    HideExit("trampilla", 0);
    return 1;

}
