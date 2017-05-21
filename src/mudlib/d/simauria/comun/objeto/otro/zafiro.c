/*   zafiro.c
     Creado por : Nemesis
     Fecha :      29-09-98
     Descripcion: Un premio para los que tengan la paciencia de recorrerse el
                  laberinto bajo el castillo de Nandor.
*/


inherit THING;

create() {
::create();
SetShort("una piedra preciosa");
SetLong("Es un zafiro negro. Una rara piedra preciosa de un azul muy oscuro, "
"casi completamente negro. Si es autentico, estas de suerte.\n");
AddId(({"zafiro","piedra","piedra preciosa"}));
SetWeight(35);
AddId(({"spell_bola_ereldil"}));
SetValue(8500);
}
