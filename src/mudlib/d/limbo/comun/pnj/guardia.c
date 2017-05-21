/*
DESCRIPCION  : Sayek, el guardia del almacen de suministros
FICHERO      : /d/limbo/comun/pnj/guardia.c
MODIFICACION : 28-09-98 [Angor@Simauria] Creacion
               10-10-99 [Woo] Le pongo mucho mas nivel, hay que asegurarse
                        de que nadie entre sin consentimiento.
--------------------------------------------------------------------------------
*/


#include "./path.h"
#include <properties.h>
#include <moving.h>
#include <messages.h>
inherit NPC;
#define AO      (TP->QueryGenderEndString())
#define NOMBRE  (capitalize(TP->QueryName()))

int nolucho()
{
    tell_room(environment(),NOMBRE+" ataca a Sayek. Éste, con sus cuatro brazos, inmoviliza a "+
        NOMBRE+"mientras parece decirle algo.\nActo seguido, se dirige a la puerta y arroja a "+
        NOMBRE+" a la calle.\n",({TP}));
    tell_room(TEMPLO("plaza03"),"Se oye ruido de discusiones en el interior del edificio de "
        "suministros. De repente, Sayek, el guardia, aparece en la puerta con "+NOMBRE+
        " fuertemente sujet"+AO+" entre sus cuatro brazos. Sayek arroja a "+NOMBRE+" fuera del "
        "almacén, y vuelve a su puesto.\n");
    TP->move(TEMPLO("plaza03"),M_SILENT);
    return notify_fail("Sayek te sujeta fuertemente con sus cuatro brazos, mientras te dice "
        "enfadado: Escucha, hij"+AO+". Los siervos de los dioses sólo queremos ayudar, tienes "
        "que ser más agradecid"+AO+". A los dioses no les va a gustar que ataques a sus "
        "enviados.\nY a continuación te pone de patitas en la calle.\n",NOTIFY_NOT_VALID);
}

int esquivo()
{
    tell_room(environment(),"Sayek hace un movimiento rápido. Parece que "+NOMBRE+" intentaba "
        "lanzarle algo.\n",({TP}));
    write("Sayek hace un rápido quiebro, esquivando tu lanzamiento.\n");
    return 1;
}
    
create()
{
    ::create();
    SetStandard("Sayek","kainoak",70,GENERO_MASCULINO);
    SetChkFightFunction(SF(nolucho));
    SetChkMagicFunction(SF(nolucho));
    SetName("Sayek");
    SetShort("Sayek, el guardia");
    SetLong("Sayek es un kainoak adulto que trabaja al servicio de los dioses como guardia en "
        "el edificio de suministros. Su misión es la de permitir la entrada al almacén sólo a "
        "aquellos que acaban de llegar a este mundo y aún tienen poca experiencia. Es un tipo "
        "grande y fuerte de gesto serio. Con un arma en cada uno de sus cuatro brazos, mejor "
        "será no molestarle...\n");
    SetAlign(-200);
    SetIds(({"sayek","Sayek","guardia","kainoak"}));
    Set(P_CANT_LURE,1);
    Set(P_CANT_STEAL,1);
}

init()
{
    ::init();
    add_action("esquivo","lanzar");
}
