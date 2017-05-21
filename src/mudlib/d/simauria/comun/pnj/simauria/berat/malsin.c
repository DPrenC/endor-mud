/*
DESCRIPCION : tabernero malsin
FICHERO     : /d/simauria/comun/pnj/simauria/berat/malsin.c
MODIFICACION: 4-11-99 [Icaro];2-6-00[Maler]guaaaauuuu sin retornos de carro
sustituyo el /std/npc por NPC;En principio sustituyo el setshort, si quereis
q se llame El Malsin pos lo descambiais. En la setlong pone q es un tio, y en
el ids viene humana, lo he cambiao
--------------------------------------------------------------------------------
*/
#include "./path.h"
#include <properties.h>
inherit NPC;

create()
{
    ::create();
    SetStandard("Malsin","humano",15,GENERO_MASCULINO);
    SetShort("Malsin, el tabernero");
    SetLong("Puedes ver a Malsin, un humano de aspecto recio, que parece haber pasado "
        "demasiado tiempo en estos parajes. Mira con mala cara a todo el que se acerca a pedirle "
        "algo.\n");
    AddId(({"humano","Malsin","tabernero","malsin"}));
    Set(P_CANT_LURE,1);
    SetCitizenship("berat");
}
