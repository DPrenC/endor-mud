/* camino01
   Frente al Gremio de Psi�nicos
   Creaci�n: [n] Nemesis, 10-Abr-2001 00:42:54 CEST
*/

#include "./path.h"
inherit SIM_ROOM;

create() {
::create();
SetLocate("Antiguo Camino");
SetPreIntShort("frente a");
SetIntShort("el Gremio de Psi�nicos");
SetIntLong(
"Est�s ante las ruinas del antiguo Gremio de Psi�nicos. Hoy en d�a s�lo\
 quedan estas ruinas como recuerdo de su existencia, pero hubo un tiempo\
 en el que fue uno de los gremios m�s poderosos del mundo.\
 Puedes entrar hacia el oeste, o cruzar el abismo por un puente hacia el oeste.\n");
SetIndoors(0);

AddDetail(({"puente"}),
"Es un poderoso puente de piedra que salva el abismo que hay entre el lugar "
"donde te encuentras y el otro lado de la monta�a.\n");
AddDetail(({"edificio","ruinas","gremio","gremio de psi�nicos","gremio de psionicos"}),
"Es un edificio de m�rmol blanco y piedra. Aunque lleva muchos siglos "
"abandonado, todav�a posee cierta majestad que s�lo poseen las construcciones "
"antiguas. Una amplia puerta, flanqueada por dos extra�as im�genes, da acceso "
"al interior. Sin embargo, las ventanas rotas y las desencajadas hojas de la "
"puerta dan una sensaci�n de abandono y de tristeza por la gloria un tiempo "
"que nunca volver�.\n");
AddDetail(({"puertas","puerta"}),
"En su momento estas puertas met�licas fueron majestuosas. Hoy en d�a, sin "
"embargo, yacen rotas y oxidadas colgando precariamente de sus goznes, "
"contribuyendo a la sensaci�n de abandono que desprende el edificio.\n");
AddDetail(({"abismo"}),
"Es profundo e insondable. Si te caes, no esperes sobrevivir.\n");
AddDetail(({"abajo"}),"No se ve el fondo.\n");
AddDetail(({"im�genes","estatuas","extra�as im�genes","extranyas imagenes","extra�as imagenes","extranyas im�genes"}),
"Representan a dos seres alados que se miran fijamente.\n");

AddExit("este","camino02");
AddExit("oeste","./psi_ruins01");

}
