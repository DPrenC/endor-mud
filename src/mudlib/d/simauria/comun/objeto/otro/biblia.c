/*   biblia.c
     Creada por : Blackrider
     Fecha 1-11-97
*/


inherit THING;

create() {
::create();
SetShort("una biblia");
SetLong("Es un libro muy grande que se llama Biblia.\n");
AddId("biblia");
SetWeight(350);
SetValue(10);
}
