/*
DESCRIPCION : Interior de la Caravana (Ruta Zarkam-Nandor)
FICHERO     : /d/akallab/comun/objeto/transporte/caravana/interior_caravana.c
MODIFICACION: 28-10-99 [Angor@Simauria] creacion segun el modelo de Woo
--------------------------------------------------------------------------------
*/

inherit ROOM;

create()
{
 ::create();
 SetIntShort("la caravana de Zarkam");
 SetIntLong(
 "Estas en la caravana de Zarkam, una larga fila de carros de comerciantes "
   "que regularmente realiza la larga y peligrosa ruta que recorre de norte "
   "a sur este continente, desde la ciudad orca de Zarkam hasta la humana de "
   "Nandor. La caravana avanza lentamente, consciente del gran recorrido que "
   "debe realizar.\n");

 SetIndoors(0);
}