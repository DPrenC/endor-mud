/*
DESCRIPCION: Cordillera sur de Kha-annu: Gruta secreta que lleva al Valle de Dehim
ARCHIVO: /d/Kha-annu/comun/habitacion/Kha-annu/afueras/carasurd/gruta1.c
CREACION: 14-10-2001 [Alura]
MODIFICACION: 08-11-2001 [Neme] Comentada la salida a la zona de Dehim.
*/

#include "./path.h"
#include <moving.h>

inherit KHA_ROOM;

int ir_camino()
{
    object camino = load_object(CARASURD + "cam2");
    if (camino->QueryAbierta())
    {
        TP->move(CARASURD + "cam2",M_GO);
        return 1;
    }
    // si está cerrada...
    if (TP->QueryStr() < 20)
    {
        write("Intentas empujar la roca con todas tus fuerzas para poder salir, pero parece "
            "que no tienes la suficiente.\n");
        say(CAP(TNAME) + " intenta empujar la roca con todas sus fuerzas, pero "
            "parece que no puede con ella.\n",TP);
        tell_room(camino,"Ves como la gran roca del norte se mueve de forma casi imperceptible...\n");
        return 1;
    }
    // la empuja, sale y la roca se vuelve a cerrar
    tell_room(camino,"Ves como la roca se desliza lentamente cuesta arriba, como si alguien "
        "estuviese empujándola desde detrás.\n");
    write("Empujas la roca con todas tus fuerzas hasta que consigues deslizarla lo justo para "
        "pasar. Rápidamente te apretujas por el estrecho hueco y sales de la gruta.\n");
    say(CAP(TNAME) + " empuja la roca con todas sus fuerzas hasta que consigue "
        "deslizarla lo suficiente para poder salir. Rápidamente, pasa por el "
        "pequeño hueco, y sale de la gruta.\n",TP);
    TP->move(CARASURD +"cam2",M_GO);
    tell_room(TO,"La roca vuelve a su sitio con un sonido hueco.\n");
    tell_room(camino,"La roca vuelve a su sitio con un sonido hueco.\n");
    return 1;
}

private string desc_larga()
{
    string mensaje = "Esta cueva no parece pensada para albergar conservas ni vinos. No "
        "contiene nada y no tiene una forma geométrica definida, como si la naturaleza la "
        "hubiera creado.\n";
    if (!load_object(CARASURD + "cam2")->QueryAbierta()) mensaje += "Solo hay una salida, "
        "hacia el norte, pues la salida sur esta bloqueada desde fuera por una gran roca.\n";
    return mensaje;
}

create()
{
    ::create();
    SetIntShort("una gruta");
    SetIntLong(SF(desc_larga));
    SetIndoors(0);
    SetIntBright(2);
    SetIntNoise("No escuchas nada, sólo hay silencio.\n");
    SetIntSmell("Huele mucho a tierra y humedad.\n");
    AddExit("sur", SF(ir_camino));
    AddExit("norte","/d/lad-laurelin/comun/habitacion/tiinkdhil/lago/bosque/cam1");
    SetLocate("Kha-annu");
}
