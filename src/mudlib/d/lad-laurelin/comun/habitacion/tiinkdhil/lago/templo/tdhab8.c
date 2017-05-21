/*****************************************************************************************
 ARCHIVO:       tdhab8.c
 AUTOR:         Chantiel, Alura
 FECHA:         08-5-1997
 DESCRIPCIÓN:   Habitación de las runas totales de Dehim
 COMENTARIOS:   Modificaciones:

                19-Nov-2001 [Nemesis] Añadido un puntito de exploración por leer
                las runas :)
                Ya que estaba, cambio raLLo por raYo, que es lo correcto
                hasta que la RAE decida lo contrario...
                Y ya puestos, castellanizo un poco, que falta le hace...
*****************************************************************************************/

#include "./path.h"
#include <ansi.h>

#define INTELIG TP->QueryInt()

inherit ROOM;

private int s;

int leer_runas(string str);
int recitar_oracion(string str);

public void create()
{
    ::create();

    SetIntShort("el salón");
    SetIntLong("Estás en medio de un círculo que hay pintado en el suelo. Está "
          "cubierto de runas bastante difíciles de entender. A tu alrededor continúa la "
          "misma sala.\n");
    SetIndoors(1);
    SetIntBright(40);
    AddDetail(({"runa", "runas"}), "Son runas... podrías intentar leerlas.\n");
    AddDetail(({"circulo", "círculo"}), "Está compuesto por dos bandas concéntricas en "
          "cuyo interior hay runas grabadas.\n");

    s = 0;

    AddRoomCmd("recitar", "recitar_oracion");
    AddRoomCmd("leer", "leer_runas");

    AddExit("este", ALULAGO("templo/tdhab7.c"));
    AddExit("oeste", ALULAGO("templo/tdhab9.c"));
    AddExit("norte", ALULAGO("templo/tdhab16.c"));
    AddExit("sur", ALULAGO("templo/tdhab4.c"));
    AddExit("noroeste", ALULAGO("templo/tdhab17.c"));
    AddExit("nordeste", ALULAGO("templo/tdhab15.c"));
    AddExit("suroeste", ALULAGO("templo/tdhab5.c"));
    AddExit("sudeste", ALULAGO("templo/tdhab3.c"));
}

int leer_runas(string str)
{
    if(str != "runa" && str != "runas")
    {
        write("Leer ¿qué?\n");
        return 1;
    }

    if(INTELIG <= 10)
    {
        write("No consigues entender nada.\n");
        s = 0;
        return 1;
    }
    if(INTELIG > 10 && INTELIG <= 15)
    {
        write("Las runas son una oración al dios Dehim. Puedes intentar "
                "recitarla.\n");
        s = 1;
        return 1;
    }
    write("Las runas son una oración para invocar al dios Dehim. Puedes intentar "
            "recitarla... aunque tal vez no sea prudente... NADA PRUDENTE.\n");
    s = 2;
    return 1;

}

int recitar_oracion(string str)
{
    if(str != "oracion" && str != "oración")
    {
        write("Recitar ¿QUÉ?\n");
        return 1;
    }

    if( s == 0 || s == 1)
    {
        write("Dices en voz alta una oración que te enseñaron tus padres de niño.\n");
        return 1;
    }
    if(s == 2)
    {
        write("Al recitar la oración el círculo brilla con intensidad. Miras hacia "
                "arriba y observas fascinado cómo la bóveda se parte por la mitad.\n\n"
                "Y ... ¡¡¡de repente todo empieza a temblar a tu alrededor ... !!!\n"
                "¡¡¡¡¡¡¡¡¡¡ZZZZZZZZFFFFFFFBBRRRRRRRRRROOOOOOOOOUMMM!!!!!! "
                "Un " + ANSI_YELLOW + "Rayo" + ANSI_NORMAL + " te cae encima.\n"
                " ... algo en ti te dice que has despertado la cólera de Dehim ... "
                "ESTÁS CONDENADO A MORIR.\n");
        say("La bóveda se abre y un rayo destroza a " + CAP(TNAME) + ".\n");
        TP->SetHP(1);
        TP->SetExplored();
        return 1;
     }
}