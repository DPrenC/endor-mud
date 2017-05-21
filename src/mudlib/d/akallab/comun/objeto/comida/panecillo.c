/*
DESCRIPCION  : un panecillo
FICHERO      : /d/akallab/comun/objeto/comida/panecillo.c
MODIFICACION : 	20-04-98 [Angor@Simauria] Creacion
		16-01-05 [Gw] Arreglado un bug con el nombre del player.
--------------------------------------------------------------------------------
*/

inherit FOOD;

create() {
   ::create();
   SetFoodKind("food");
   SetFoodMsgs(({"Te comes un crujiente panecillo.\n","@@Pl_Name@@ se come un panecillo.\n"}));
   SetFoodStuff(10);
   SetFoodHeal(5);
   SetShort("un panecillo");
   SetLong("Es un crujiente panecillo.\n");
   AddId("panecillo");
   AddId("comida");
   SetWeight(50);
   SetValue(30);
}
