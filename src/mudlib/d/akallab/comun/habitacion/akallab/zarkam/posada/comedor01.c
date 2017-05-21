/*
DESCRIPCION : pasillo de la posada
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/posada/comedor01.c
MODIFICACION: 15-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
#include "./posada.h"
inherit Z_POSADA("posada");

create() {
  posadero=POSADERO;
  cocinero=COCINERO;
  tipo=TIPO;
  pos_nom=POS_NOM;

  ::create();

  SetIntLong(
     "Te encuentras en el comedor de la "+tipo+" '"+pos_nom+"'. El local es "
     "regentado por el orco "+posadero+", quien atiende a los clientes, y su mujer " +
     cocinero+" que se encarga de la cocina. El comedor es una gran habitacion con "
     "una chimenea al fondo repleta de mesas con clientes. La entrada de la "+tipo+" "
     "queda al norte de aqui. Una puerta de doble hoja comunica con la cocina.\n");

  AddDetail(({"cocina","puerta"}),
     "Al sur de esta habitación está la cocina en la que trabaja "+cocinero+", la mujer "
     "de "+posadero+". Para que sea facil entrar y salir a ella cargando con los platos "
     "de comida se ha instalado una puerta de doble hoja: para abrirla basta con "
     "empujarla y unos resortes hacen que se cierre sola.\n");

  AddDetail(({"mesas"}),
     "La "+tipo+" esta llena de ellas. Donde sino iban a comer los clientes?\n");

  AddDetail(({"chimenea"}),
     "Al fondo del comedor hay una gran chimenea en la que siempre hay un "
     "agradable fuego que mantiene la "+tipo+" a una confortable temperatura.\n");

  AddExit("este",Z_POSADA("comedor02"));
  AddExit("norte",Z_POSADA("entrada"));
  AddExit("sur",Z_POSADA("cocina"));
}
