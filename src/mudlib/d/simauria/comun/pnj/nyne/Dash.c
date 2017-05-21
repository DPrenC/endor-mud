/*
DESCRIPCION    : Tendero del bosque de los contrabandistas.
FICHERO        : dash.c
CREACION       : [B] 10/10/01
MODIFICACION   : [B] 18/01/02 - Le cambio el nombre
*/

#include "./path.h"
#include <combat.h>
#include <gremios.h>
#include <properties.h>

inherit NPC;

create() {
    ::create();
    SetStandard("Dash","humano",([GC_LUCHADOR: 20]),GENERO_MASCULINO);
    SetShort("Dash, el tendero");
    SetLong("Dash es un humano común. Va vestido con ropas oscuras, y lleva un extraño "
        "tatuaje tapado casi por completo por sus ropajes. Podría ser el tatuaje "
        "identificativo del Gremio de los Contrabandistas, pero quien sabe, tal vez solo sea "
        "un rumor que están organizados en un Gremio. No ves que lleve ningún tipo de arma "
        "encima, pero sientes que mil ojos te vigilan, así que piensas que será mejor no "
        "iniciar ninguna acción ofensiva aquí dentro.\n");
    SetIds(({"humano","Dash","dash"}));
    Set(P_CANT_LURE,1);
    SetAlign(50);  
    SetAggressive(0);
}