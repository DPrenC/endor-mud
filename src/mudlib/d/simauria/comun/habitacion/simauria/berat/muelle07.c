/*
DESCRIPCION  : Continuacion del muelle del puerto
FICHERO      : /d/simauria/comun/habitacion/simauria/berat/muelle07.c
[Ratwor] 02/07/2010 Añado estivadores y corrijo textos y sangrado.
--------------------------------------------------------------------------------
*/

#include "./path.h"
#include <properties.h>
inherit SIM_ROOM;
create() {
    ::create();
    SetIntShort("un muelle de carga");
    SetIntLong("Estás en el puerto de Berat donde se une con uno de los exttremos de "
    "la calle principal hacia el norte.\n El muelle continúa de este a oeste con "
    "sus distintas embarcaciones amarradas.\n También por algunas zonas se ven "
    "barcos mercantes y sus marineros descargando las mercancías.\n");

    SetIndoors(0);
    AddDetail(({"muelle","el muelle"}),"El muelle está hecho de madera, es bastante "
    "viejo pero sólido.\n");
    AddDetail(({"cajas","mercancías","mercancía"}),"En el suelo puedes ver muchas "
    "cajas traídas de lugares exóticos con raras mercancías.\n");
    AddDetail(({"trabajadores", "hombres","estibadores","estibador","humano", 
      "marineros", "marinos"}),
    "Ves a bastantes hombres descargando cajas que dejan en el muelle, mientras "
    "otros los cargan en carros de caballos.\n");
    AddDetail(({"barcos","barco"}),"Ves algunos grandes barcos de mercancías de "
    "donde los hombres descargan la carga.\n");
    SetIntNoise("De fondo escuchas a las olas chocar contra el muelle.\n");
    SetIntSmell("Huele a agua de mar.\n");
    SetLocate("Berat");
    AddDetail(({"mar", "agua","el mar"}),"Te sientes empequeñecido ante la inmensidad "
    "del océano.\n");
    AddExit("oeste","./muelle06");
    AddExit("este","./muelle08");
    AddExit("norte", "./cprin8");
    AddItem(PNJ("simauria/berat/marino"), REFRESH_DESTRUCT, d2());
    if (d2()==1) AddItem(PNJ("simauria/berat/estivador"), REFRESH_DESTRUCT);
    if (d2()==1) AddItem(PNJ("simauria/berat/estivador"), REFRESH_DESTRUCT);
    if (d2()==1) AddItem(PNJ("simauria/berat/estivador"), REFRESH_DESTRUCT);
}
