/* SIMAURIA 'Interior de la caravana Nahlin'
   ========================================
   [w] Woo@simauria

   20-11-98 [w] Creacion.
*/

inherit ROOM;

public void create()
{
    ::create();
    SetIntShort("la caravana de Nahlin");
    SetIntLong("\Estás siguiendo la caravana de Nahlin, compuesta mayoritariamente por "
        "caballos, aunque ves alguna que otra mula.\n");
    SetIndoors(0);
}