/*
DESCRIPCION : pasillo de la posada
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/posada/comedor1
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
     "una chimenea al fondo repleta de mesas con clientes. Observas que al este de "
     "aqui se hallan unas escaleras que permiten subir a los pisos superiores de la " +
     tipo+".\n");

  AddDetail(({"cocina","puerta"}),
     "Al sur de esta habitacion esta la cocina en la que trabaja "+cocinero+", la mujer de " +
     posadero+". Para que sea facil entrar y salir a ella cargando con los platos de "
     "comida se ha instalado una puerta de doble hoja: para abrirla basta con emujarla "
     "y unos resortes hacen que se cierre sola.\n");

  AddDetail(({"mesas"}),
     "La "+tipo+" esta llena de ellas. Donde sino iban a comer los clientes?\n");

  AddDetail(({"escalera","escaleras"}),
     "Las escaleras se hallan al final del pasillo al este de aqui.\n");

  AddDetail(({"chimenea"}),
     "Al fondo del comedor hay una gran chimenea en la que siempre hay un "
     "agradable fuego que mantiene la "+TIPO+" a una confortable temperatura.\n");

  AddExit("este",Z_POSADA("pasillo00"));
  AddExit("norte",Z_POSADA("rincon"));
  AddExit("oeste",Z_POSADA("comedor01"));
}
