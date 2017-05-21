// DESCRIPCION : Cubierta del carguero "Tormenta" (ruta Azzor-Morhugok)
// MODIFICACION: 26-05-2008 [Angor] Creacion

#include "./path.h"
inherit ROOM;

#define N_BARCO	"Tormenta"

public void create()
{
::create();
SetIntShort("la cubierta del carguero "+N_BARCO);
SetIntLong(
"Este viejo carguero cruje a cada embestida del oleaje. Son muchos los años "
"a sus espaldas e incontables las reparaciones pero este barco se resiste a "
"morir varado en una playa cualquiera. Es un navio lento, pesado, ancho y de "
"gran calado. Las velas que lo empujan lentamente cuelgan de dos gruesos "
"mástiles entre los que se hallan dos grandes trampillas que dan acceso a la "
"bodega de carga. Este carguero realiza el trayecto entre Azzor y Morhugok.\n");

SetIndoors(0);

AddDetail(({N_BARCO, "carguero", "barco", "cubierta"}), QueryIntLong());

#include "./detalles_barco.h"

}
