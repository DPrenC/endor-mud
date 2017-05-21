/*****************************************************************************************
 ARCHIVO:       tdhab8.c
 AUTOR:         Chantiel, Alura
 FECHA:         08-5-1997
 DESCRIPCI�N:   Habitaci�n de las runas totales de Dehim
 COMENTARIOS:   Modificaciones:

                19-Nov-2001 [Nemesis] A�adido un puntito de exploraci�n por leer
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

    SetIntShort("el sal�n");
    SetIntLong("Est�s en medio de un c�rculo que hay pintado en el suelo. Est� "
          "cubierto de runas bastante dif�ciles de entender. A tu alrededor contin�a la "
          "misma sala.\n");
    SetIndoors(1);
    SetIntBright(40);
    AddDetail(({"runa", "runas"}), "Son runas... podr�as intentar leerlas.\n");
    AddDetail(({"circulo", "c�rculo"}), "Est� compuesto por dos bandas conc�ntricas en "
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
        write("Leer �qu�?\n");
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
        write("Las runas son una oraci�n al dios Dehim. Puedes intentar "
                "recitarla.\n");
        s = 1;
        return 1;
    }
    write("Las runas son una oraci�n para invocar al dios Dehim. Puedes intentar "
            "recitarla... aunque tal vez no sea prudente... NADA PRUDENTE.\n");
    s = 2;
    return 1;

}

int recitar_oracion(string str)
{
    if(str != "oracion" && str != "oraci�n")
    {
        write("Recitar �QU�?\n");
        return 1;
    }

    if( s == 0 || s == 1)
    {
        write("Dices en voz alta una oraci�n que te ense�aron tus padres de ni�o.\n");
        return 1;
    }
    if(s == 2)
    {
        write("Al recitar la oraci�n el c�rculo brilla con intensidad. Miras hacia "
                "arriba y observas fascinado c�mo la b�veda se parte por la mitad.\n\n"
                "Y ... ���de repente todo empieza a temblar a tu alrededor ... !!!\n"
                "����������ZZZZZZZZFFFFFFFBBRRRRRRRRRROOOOOOOOOUMMM!!!!!! "
                "Un " + ANSI_YELLOW + "Rayo" + ANSI_NORMAL + " te cae encima.\n"
                " ... algo en ti te dice que has despertado la c�lera de Dehim ... "
                "EST�S CONDENADO A MORIR.\n");
        say("La b�veda se abre y un rayo destroza a " + CAP(TNAME) + ".\n");
        TP->SetHP(1);
        TP->SetExplored();
        return 1;
     }
}