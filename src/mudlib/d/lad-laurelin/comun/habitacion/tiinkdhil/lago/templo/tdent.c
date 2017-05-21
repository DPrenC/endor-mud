/*****************************************************************************************
 ARCHIVO:       tdent.c
 AUTOR:         Chantiel, Alura
 FECHA:         08-5-1997
 DESCRIPCIÓN:   Templo de Dehim.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"
#include <moving.h>

inherit ROOM;

int abrir_puertas(string str);
int cerrar_puertas(string str);

public void create()
{
    ::create();

    SetIntShort("el Templo de Dehim");
    SetIntLong("Estas en la entrada de lo que antaño debió ser un gran templo, "
      		"aunque ahora no ves más que columnas destrozadas por el paso "
  		    "del tiempo y restos de figuras esparcidos por doquier. Las "
  	    	"puertas todavía permanecen intactas.\n");
    AddDetail("puertas", "Son muy grandes y parecen gruesas. Están cerradas.\n");
    AddDetail(({"pared", "paredes"}), "Son de mármol finamente tallado, parece obra de "
          "enano.\n");
    AddDetail("figuras", "Quizás sean estatuas de elfos druidas.\n");

    AddRoomCmd(({"abrir", "tirar"}), "abrir_puertas");
    AddRoomCmd("cerrar", "cerrar_puertas");

    AddExit("suroeste", ALULAGO("bosque/cam5.c"));

    AddItem(ALUPNJ("fanElfo.c"));
}

int abrir_puertas(string str)
{
    int dur; //Dureza de las bisagras...

    if(!str || str != "puertas") return 0;
    dur = random(TP->QueryStr() * 2);
    if(dur < ((TP->QueryStr() + TP->QueryDex()) / 2))
    {
        write("Te agarras con fuerza de las puertas y las bisagras ceden poco a "
                "poco... las puertas se abren y entras al templo....\n");
        say(CAP(TNAME)+ " entra al templo de Dehim.\n");
        TP->move(ALULAGO("templo/tdpas1"), M_SILENT);
        write("Las puertas se cierran tras de ti haciendo un gran ruido.\n\n");
        return 1;
    }
    write("Empujas con todas tus fuerzas las puertas, pero no consigues moverlas..."
            "Tal vez, con un poco de esfuerzo más, lo consigas...\n");
    return 1;
}

int cerrar_puertas(string str)
{
    if(!str) return 0;
    if(str != "puertas")
    {
        write("Intentas empujar " + str + ", pero como sólo está en tu mente, te caes "
                "al suelo.\n");
        return 1;
    }
    write("Empujas las puertas con todas tus fuerzas... Ahora están bien cerradas.\n");
    return 1;
}
