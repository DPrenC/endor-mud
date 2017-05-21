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
    SetLong("Dash es un humano com�n. Va vestido con ropas oscuras, y lleva un extra�o "
        "tatuaje tapado casi por completo por sus ropajes. Podr�a ser el tatuaje "
        "identificativo del Gremio de los Contrabandistas, pero quien sabe, tal vez solo sea "
        "un rumor que est�n organizados en un Gremio. No ves que lleve ning�n tipo de arma "
        "encima, pero sientes que mil ojos te vigilan, as� que piensas que ser� mejor no "
        "iniciar ninguna acci�n ofensiva aqu� dentro.\n");
    SetIds(({"humano","Dash","dash"}));
    Set(P_CANT_LURE,1);
    SetAlign(50);  
    SetAggressive(0);
}