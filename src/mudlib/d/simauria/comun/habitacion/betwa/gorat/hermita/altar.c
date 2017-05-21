
#include "./path.h"

inherit SIM_ROOM;
create () {
  ::create();
SetLocate("Gorat");
SetIntShort("la ermita de la diosa Valevissa");
SetIntLong(
"Estas frente al altar de la hermita de la diosa Valevissa, es un altar "
"de madera, en el que puedes ver unas runas grabadas, as� como unos trozos. "
"de vidrio.\n");
AddDetail("trozos de vidrio",
"Estos son los restos de lo que en su dia ser�a el santo caliz de la diosa "
"parece que alg�n v�ndalo lo ha roto.\n");
AddDetail("runas",
"son unas runas escritas en una lengua antigua y olvidada, que no logras "
"entender.\n");
AddDetail("altar",
"Es un altar de madera, seg�n la leyenda, est� hecho con la madera del casco "
"del barco de unos pescadores que se perdieron en la noche y se les apareci� "
"la diosa, les gui� a un islote en las cercan�as de Gorat, y all� les entreg� "
"comida hasta que pudieron ser rescatados.\n");
SetIndoors(1);
SetIntBright(30);
AddDetail("imagen",
"Es la imagen de la diosa del mar Valevissa, es una imagen humana femenina "
"de cabellos rubios y ojos azul mar, andando sobre las aguas del mar.\n");
//AddExit("sur","../calles/callep4"); al puerto, claro.
AddExit("sur","entrada");
AddItem(GORPNJ("sacerdotisa"));
//AddItem(GORPNJ("mujer"));
}