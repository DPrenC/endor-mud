/*****************************************************************************************
 ARCHIVO:       tdpas15.c
 AUTOR:         Chantiel, Alura
 FECHA:         08-5-1997
 DESCRIPCI�N:   Templo de Dehim.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"
#include <moving.h>

inherit ROOM;

private object obj1, obj3, obj4;
private int visto1, visto2;

string inst_cocina();
int abrir_puertap(string str);

public void create()
{
    ::create();

    SetIntShort("una cocina");
    SetIntLong("Esto era la cocina de los monjes. Ahora, los �nicos cocineros que hay "
          "son las ratas. Desde luego no vas a encontrar comida en buen estado. Hay una "
          "sucia y alargada mesa con cachivaches rotos por encima. Tambi�n ves un "
          "armario y alg�n que otro adorno colgado de la pared. Si vas al oeste, te "
          "encontrar�s con la despensa.\n");
    SetIndoors(1);
    SetIntBright(45);
    AddDetail("armario", "Tiene varias estanter�as y una peque�a puerta.\n");
    AddDetail(({"pared", "paredes"}), "En la pared cuelgan unos instrumentos de cocina "
          "cubiertos de telara�as.\n");
    AddDetail(({"instrumentos", "adorno", "adornos"}), SF(inst_cocina));
    AddDetail(({"estanter�as", "estanterias"}), "Todos los objetos est�n rotos.\n");
    AddDetail("mesa", "Todos los objetos est�n rotos, una pena.\n");
    //anyadir funcion abrir_armario que lo abra y ense�e un cacharro para cocinar
    //anyadir funcion inst_cocina que ense�e el otro instrumento para cocinar
    AddRoomCmd("abrir", "abrir_puertap");

    AddExit("norte",ALULAGO("templo/tdhab27.c"));
    AddExit("oeste",ALULAGO("templo/tdhab22.c"));
    AddExit("suroeste",ALULAGO("templo/tdpas14.c"));
}

string inst_cocina()
{
    if (visto2 == 1) return "Aunque ahora no hay nada, antes hab�a algo colgado.\n";
    /*
    obj3 = clone_object(ALUOBJ("otro/pedernal.c"));
    obj4 = clone_object(ALUOBJ("otro/yesca.c"));
    obj3->move(TO, M_SILENT);
    obj4->move(TO, M_SILENT);
    */
    visto2 = 1;
    return "Entre las telara�as de la pared ves un trozo de yesca y perdernal.\n";
}

int abrir_puertap(string str)
{
    if (str != "puerta peque�a" && str != "armario") return 0;
    if (visto1 == 1)
    {
    	  write("Ahora no hay nada, lo que hab�a lo han sacado.\n");
    	  return 1;
    }
    write("Sacas unas cerillas del armario.\n");
    obj1 = clone_object(ALUOBJ("otro/cerilla.c"));
    obj1->move(TP, M_SILENT);
    visto1 = 1;
    return 1;
}

public varargs void reset()
{
    visto1 = 0;
    visto2 = 0;
    ::reset();
}
