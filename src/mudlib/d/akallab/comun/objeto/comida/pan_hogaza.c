/*
DESCRIPCION  : una hogaza de pan
FICHERO      : /d/akallab/comun/objeto/comida/pan_hogaza.c
MODIFICACION : 	14-02-98 [Angor@Simauria] Creacion
		16-01-05 [Gw] Arreglado un bug con el nombre del player.
--------------------------------------------------------------------------------
*/

inherit FOOD;

create() {
   ::create();
   SetFoodKind("food");
   SetFoodMsgs(({"Te comes una gran hogaza de pan.\n","@@Pl_Name@@ se come una hogaza de pan.\n"}));
   SetFoodStuff(60);
   SetFoodHeal(35);
   SetShort("una hogaza de pan");
   SetLong("Es una gran hogaza de pan.\n");
   AddId("hogaza");
   AddId("comida");
   SetWeight(1000);
   SetValue(300);
}
