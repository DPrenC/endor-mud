/* Tienda de Armas personalizada de Kha-annu.
Fichero: tienda1.c
Autor: [I] Izet@Simauria.
Creacion: 28 Enero 1998.
Ultima modificacion: 28 Enero 1998.
                     Izet@Simauria 18 Febrero 1998.
                     Icaro 3 Noviembre 1999. Modificado para Berat
                     Icaro2@universitaariosmix.com
 */

#include "./path.h"
#include <sounds.h>
#include <door.h>
#include <scheduler.h>

inherit "/room/herreria";

object ob;

create() {
    ::create();
    SetLocate("berat");
    SetIntShort("la Forja de Kolkson");
    SetIntBright(30);
    SetShopkeeper(PNJ("simauria/berat/armero"));
    SetIntLong("Estás en la forja de Kolkson, al fondo puedes ver una enorme fragua donde se calienta "
    "el acero al blanco. Las paredes estan llenas de espadas, y todo tipo de armas, barriles "
    "y maderas se amontonan en las esquinas, esperando ayudar en la construcción de las armas. "
    "Una cabeza de oso adorna la chimenea de la fragua.\n");
    AddDetail( ({"tienda","forja","herreria","forja de Kolkson"}),SF(IntLong));
    AddDetail( ({"espadas","arma","armas","pared"}),
    "Son adornos creados por Kolkson el herrero.\n");
  /* AddDetail( ({"cartel"}),"Es un cartel de madera. Tiene algo escrito.\n");
   AddReadMsg( ({"cartel"}),
"El cartel pone:\n"
"Puedes 'encargar' tu espada a medida en esta herreria. Despues de hacer tu\n"
"encargo podras poner tu propia descripcion al objeto que compres.\n"); */
    AddArticle(ARMA("claymore"),REFRESH_REMOVE,1);
    AddArticle(ARMA("cadena"),REFRESH_REMOVE,1);
    AddArticle(ARMA("latigo"),REFRESH_REMOVE,1);
    AddArticle(ARMA("berdiche"),REFRESH_REMOVE,1);
    AddArticle(ARMA("daga"),REFRESH_REMOVE,2);
    AddArticle("/obj/arco",REFRESH_REMOVE,1);
    AddArticle("/obj/carcaj",REFRESH_REMOVE,4);
    AddExit("oeste","./cmerc1");
    SetLastDest("./cmerc1");
    SetNotifyExits("oeste");
    AddDoor("oeste", "la puerta de la calle",
    "La puerta de salida que va a dar a la calle del mercado.\n",
    ({"puerta", "puerta del oeste", "puerta de salida"}),
    ([P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
    P_DOOR_CLOSE_SOUND: SND_SUCESOS("abrir_puerta_campanillas"), P_DOOR_CLOSE_TIME : S_CLOSED_AT_NIGHT]));
    RemoveDustbin();
    RemoveExit("almacen");
}
