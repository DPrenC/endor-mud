/* camino01
   Frente al Gremio de Psiónicos
   Creación: [n] Nemesis, 10-Abr-2001 00:42:54 CEST
*/

#include "./path.h"
inherit SIM_ROOM;

create() {
::create();
SetLocate("Antiguo Camino");
SetPreIntShort("frente a");
SetIntShort("el Gremio de Psiónicos");
SetIntLong(
"Estás ante las ruinas del antiguo Gremio de Psiónicos. Hoy en día sólo\
 quedan estas ruinas como recuerdo de su existencia, pero hubo un tiempo\
 en el que fue uno de los gremios más poderosos del mundo.\
 Puedes entrar hacia el oeste, o cruzar el abismo por un puente hacia el oeste.\n");
SetIndoors(0);

AddDetail(({"puente"}),
"Es un poderoso puente de piedra que salva el abismo que hay entre el lugar "
"donde te encuentras y el otro lado de la montaña.\n");
AddDetail(({"edificio","ruinas","gremio","gremio de psiónicos","gremio de psionicos"}),
"Es un edificio de mármol blanco y piedra. Aunque lleva muchos siglos "
"abandonado, todavía posee cierta majestad que sólo poseen las construcciones "
"antiguas. Una amplia puerta, flanqueada por dos extrañas imágenes, da acceso "
"al interior. Sin embargo, las ventanas rotas y las desencajadas hojas de la "
"puerta dan una sensación de abandono y de tristeza por la gloria un tiempo "
"que nunca volverá.\n");
AddDetail(({"puertas","puerta"}),
"En su momento estas puertas metálicas fueron majestuosas. Hoy en día, sin "
"embargo, yacen rotas y oxidadas colgando precariamente de sus goznes, "
"contribuyendo a la sensación de abandono que desprende el edificio.\n");
AddDetail(({"abismo"}),
"Es profundo e insondable. Si te caes, no esperes sobrevivir.\n");
AddDetail(({"abajo"}),"No se ve el fondo.\n");
AddDetail(({"imágenes","estatuas","extrañas imágenes","extranyas imagenes","extrañas imagenes","extranyas imágenes"}),
"Representan a dos seres alados que se miran fijamente.\n");

AddExit("este","camino02");
AddExit("oeste","./psi_ruins01");

}
