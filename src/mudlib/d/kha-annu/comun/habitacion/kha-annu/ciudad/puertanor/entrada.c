/*
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
 \\              << KHA-ANNU [w]  Woo@simauria >>               \\
  \\             << KHA-ANNU [i] Izet@simauria >>                \\
   \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
   /////////////////////////////////////////////////////////////////
  //               Creacion............. 07-05-97                //
 //                Ultima modificacion.. 09-01-97                    //
/////////////////////////////////////////////////////////////////
*/

#include "./path.h"
#include <moving.h>
inherit KHA_ROOM;
int abierto;

do_entrar()
{
    if (abierto == 0)
    {
        tell_room(TO,TP->QueryName()+" intenta entrar sin llamar y se da con "
            "la puerta en las narices.\n",filter(all_inventory(TO),
            (:query_once_interactive($1) && ($1 == TP || !$1->CanSeeObject(TP)):)));
        return notify_fail("Las puertas están cerradas, quizá deberías "
            "llamar.\n",NOTIFY_NOT_VALID);
    }
    if (abierto == 1)
    {
        write("Cruzas las puertas y entras en la ciudad de Kha-annu.  Te "
            "sientes algo desorientado.\n");
        tell_room(TO,TP->QueryName()+" entra en la ciudad de Kha-annu.\n",
            filter(all_inventory(TO),
            (:query_once_interactive($1) && ($1 == TP || !$1->CanSeeObject(TP)):)));
    return TP->move(PUERTANOR + "hall1",M_GO);
  }
}

void init()
{
    ::init();
    add_action("llama_puerta","llamar");
}

int llama_puerta(string str)
{
    if ((str !="puerta") && (str !="puertas") && (str !="a puerta") &&
        (str != "a puertas") && (str != "a la puerta") &&
        (str != "a las puertas") && (str !="en puerta") && (str !="en puertas")
        && (str !="en la puerta") && (str !="en las puertas")) return notify_fail("Llamar en "
            "dónde?\n",NOTIFY_NOT_VALID);
    if (abierto == 1) return notify_fail("Las puertas están abiertas, no "
        "hace falta que llames otra vez.\n",NOTIFY_NOT_VALID);
    if (abierto == 0)
    {
        write("Llamas a las puertas de Kha-annu:\n¡Toc, toc, toc!\n");
        tell_room(TO,TP->QueryName()+" llama a las puertas de Kha-annu:\n"
            "¡Toc, Toc, Toc!\n",filter(all_inventory(TO),
            (:query_once_interactive($1) && ($1 == TP || !$1->CanSeeObject(TP)):)));
        call_out("abre_puerta", 5);
        return 1;
    }
return 1;
}

int abre_puerta()
{
    if (abierto == 1) return 1;
    tell_room(TO,"Las puertas chirrían sobre sus goznes, y un enano feo y "
        "corcovado aparece detrás de ellas.\nEl enano te mira de arriba a "
        "abajo, y dice: Bienvenido a Kha-annu extranjero. Aquí tenemos "
        "grandes armas y armaduras, entre otros utensilios para la guerra.\n");
    abierto = 1;
    TO->HideExit("sur",0);
    call_out("cierra_puerta",30);
    return 1;
}

int cierra_puerta()
{
    if (abierto == 0) return 1;
    tell_room(TO,"El feo y corcovado enano murmura algo en un extraño "
        "idioma y cierra las puertas de nuevo.\n");
    abierto = 0;
    TO->HideExit("sur",1);
    return 1;
}

create()
{
    abierto = 0;
    ::create();
    SetIntShort("la entrada a Kha-annu");
    SetIntLong("Estás en un frondoso camino. Ante ti se alza una gran ciudad "
        "llamada Kha-annu, gran capital del reino de los enanos de Kha-annu. "
        "Kha-annu es famosa por su trabajo del metal, con el cual se forjan "
        "las mejores armas, armaduras y protecciones que jamás hayas podido "
        "ver.\nUnas inmensas puertas aceradas descansan sobre sus goznes "
        "impidiendo la entrada a la ciudad a personas que pudieran no ser "
        "deseadas.\n");
    SetIndoors(0);
    SetIntNoise("Oyes el murmullo de la gente, y los sonidos de las forjas.\n");
    SetIntSmell("Tu olfato no capta nada especial en este lugar.\n");
    AddDetail(({"gozne","goznes","bisagra","bisagras"}),
        "Son las grandes bisagras sobre las que ruedan las puertas.\n");
    AddDetail(({"camino","carretera"}),
        "Es el camino por donde has llegado hasta aquí.\n");
    AddExit("sur",SF(do_entrar));
    HideExit("sur",1);
    AddRoomCmd("llamar","llama_puerta");
    AddExit("norte",CARASURD + "cam1");
    SetLocate("Kha-annu");
}
