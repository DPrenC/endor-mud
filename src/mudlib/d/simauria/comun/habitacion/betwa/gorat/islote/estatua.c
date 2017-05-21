
#include "./path.h"

inherit SIM_ROOM;
create () {
  ::create();
SetLocate("Islote de Gorat");
SetIntShort("la estatua del islote de Gorat");
SetIntLong(
"Est�s en el centro del islote de Gorat, ves una estatua de la diosa "
"Valevissa, en su pedestal con unas runas grabadas. "
"El islote sigue en todas direcciones.\n");
AddDetail("runas",
"Ves unas runas que deben contener un salmo de adoraci�n a la diosa.\n");
//falta a�adir el addaction "copiar runas", en un pergamino.
SetIndoors(0);
AddExit("norte","playan");
AddExit("sur","playas");
AddExit("este","playae");
AddExit("oeste","playao");
}