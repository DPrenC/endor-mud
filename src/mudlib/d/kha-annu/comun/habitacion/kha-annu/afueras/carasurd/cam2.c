/*
DESCRIPCION: Cordillera sur de Kha-annu
ARCHIVO: /d/Kha-annu/comun/habitacion/Kha-annu/afueras/carasurd/cam2.c
CREACION: 14-10-2001 [Alura]
MODIFICACION: 21/01/2005: [kastwey]: arreglo un problemilla con el mover
*/

#include "./path.h"
#include <moving.h>
#include <messages.h>


#define TIEMPO_VISIBLE (5 + random(5)) // tiempo que permanecerá abierta la gruta

inherit KHA_ROOM;

int abierta;

public int ir_gruta(); // función para mover al player a la ruta, si existe salida.
public int QueryAbierta() { return abierta; }
public int SetAbierta(int i) { return abierta = i; }

private void informar_cierre_gruta()
{
    object gruta = load_object(CARASURD + "gruta1");
    tell_room(gruta,({MSG_SEE,
        "Escuchas un golpe proveniente del sur. Cuando miras, observas que esa salida se haya "
            "ahora bloqueada por una gran roca.\n",
        "Escuchas un golpe seco proveniente del sur.\n"}));
}

public void cerrar_gruta()
{
    if (!abierta) return;
    tell_room(TO,"La enorme roca comienza a deslizarse por la pendiente hasta detenerse en un "
        "saliente de la pared, ocultando la entrada de la cueva.\n");
    abierta = 0;
    HideExit("norte",1);
    informar_cierre_gruta();
}

int cmd_mover(string str)
{
    if (!str) return notify_fail("Mover qué?\n");
    if (str != "roca") return notify_fail("No ves " + str + " para mover.\n");
    if(!abierta)
    {
        if(TP->QueryStr()<20)
        {
            write("Intentas empujar la roca pero no lo consigues, es demasiado pesada para ti.\n");
            say(CAP(TNAME) + " intenta mover la roca, pero no lo consigue.\n",TP);
            return 1;
        }
        write("Con todas tus fuerzas mueves la roca haciéndola rodar pendiente arriba, hasta "
            "que dejas al descubierto lo que parece la entrada a una gruta.\n");
        say(CAP(TNAME) + " hace rodar la roca cuesta arriba hasta que queda al "
            "descubierto lo que parece la entrada a una gruta.\n",TP);
        call_out("cerrar_gruta",TIEMPO_VISIBLE);
        abierta=1;
        HideExit("norte",0);
        return 1;
    }
    // la roca ya está abierta, así que la cierra
    write("Empujas suavemente la roca, que se desliza pendiente abajo hasta detenerse en un "
        "saliente de la pared, ocultando completamente la entrada a la gruta.\n");
    say(CAP(TNAME) + " empuja suavemente la roca, que comienza a rodar "
        "pendiente abajo hasta detenerse en un saliente de la pared, ocultando "
        "completamente la entrada de la gruta.\n",TP);
    abierta = 0;
    HideExit("norte",1);
    informar_cierre_gruta();
    remove_call_out("cerrar_gruta");
    return 1;
}

create()
{
    ::create();
    SetIntShort("las montañas de Kha-annu");
    SetIntLong("Estás en un sendero estrecho que se abre paso a través de la montaña. La zona "
        "en la que te encuentras es una pequeña parte de una hilera de cumbres que forman la "
        "gran cordillera sur de Kha-Annu, que limita con Kenton y Lad-laurelin. Hay rocas "
        "esparcidas a tu alrededor, parece que a causa de algún desprendimiento.\n");
    SetIndoors(0);
    SetIntNoise("El viento que azota fuerte tu cara te impide escuchar nada con claridad.\n");
    SetIntSmell("Tu olfato no capta nada especial en este lugar.\n");
    AddDetail(({"camino","carretera"}),"El suelo es de piedra. Está desgastado por el tiempo y "
        "principalmente por pies enanos.\n");
    AddDetail(({"montaña"}), "Las paredes son de dura y escarpada roca.\n");
    AddDetail(({"rocas","pared"}),"Ha habido desprendimientos. Una gran roca a tu izquierda te "
        "lo hace pensar.\n");
    AddDetail(({"roca","roca izquierda"}),"Mide metro y medio y tiene los cantos ovalados, "
        "como erosionados.\n");
    AddExit("sur","cam1");
    AddExit("norte",SF(ir_gruta));
    HideExit("norte",1);
    SetLocate("Kha-annu");
}

init()
{
    ::init();
    add_action("cmd_mover","mover");
}

public int ir_gruta()
{
    if (!abierta) return 0;
    else return TP->move(CARASURD + "gruta1",M_GO), 1;
}

public void reset()
{
    ::reset();
    // cerramos la roca
    abierta = 0;
    // y ocultamos la salida
    HideExit("norte",1);
}
