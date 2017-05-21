//*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*
//*   dentro.c                         *
//* Archivo de: Gorthem, El forjador    *
//* Email: jorcama@euibbs.upv.es        *
//* Basado en --------.c                *
//* Creacion: 03.12.98                  *
//* Modificacion: 03.12.98              *
//* Agradecimientos: Woo , Cheto        *
//*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*/

inherit ROOM;

create()
{
::create();

SetPreIntShort("dentro de");
SetIntShort("la caravana Khandor");
SetIntLong(
 "Estas dentro de la carvana Khandor.\n"
 "Esta caravana une la ciudad enana de Kha-annu, con el puerto de Nandor.\n"
 "Vas rodeado por un monton de viajeros, principalmente enanos y humanos.\n"
 "Algunos van en carretas y otros en sus propias monturas.\n"
 "No puedes dejar la caravana hasta que llegues a la parada.\n");

SetIndoors(0);

}