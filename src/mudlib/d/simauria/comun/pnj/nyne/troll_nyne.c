/*
DESCRIPCION: Troll para el bosque de Nyne
FICHERO: troll_nyne.c
CREACION: 27-11-01 [BOMBER] Bomber@simauria.upv.es
MODIFICACION: 01-05-02 [B]     	Le bajo un poco los stats... Es q era muy cañero...
	      06-03-03 [ChS]   	Bajo el nivel de los trolls, ahora  varian su
	      			nivel desde 10 a 12.
	      			Dan mas Xp usando la formula de NVL*500 mas la base
*/
#define NVL  (24+d3())
#include <gremios.h>
#include <properties.h>

#include "./path.h"
inherit NPC;

create()
{
    ::create();
    SetStandard("un troll","troll",([GC_LUCHADOR: NVL]),GENERO_MASCULINO);
    SetIds(({"troll"}));
    SetShort("un troll");
    SetLong("Es un enorme troll con un oscuro pelaje que le innunda toda la superficie "
    "de su cuerpo y su altura debe superar a la de cualquier raza media. Unos grandes "
    "y feos colmillos le salen del morro. Este debe de ser uno de los tantos que "
    "habitan en el bosque de Nyne.\n");
   SetAggressive(1);
    SetHands(({ ({"garra izquierda",0,NVL/2}),({"garra derecha",0,NVL/2}) }) );
    SetGoChance(50);
    AddWalkZones(BOSQUE_NYNE);
    //AddItem(ARMA("maza_hierro_g"),REFRESH_REMOVE,SF(wieldme));
    //AddItem(PROT("coraza_cuero_g"),REFRESH_REMOVE,SF(wearme));
}