/*
DESCRIPCION  : una bolsa de rosquillas
FICHERO      : /d/akallab/comun/objeto/comida/rosquillas.c
MODIFICACION : 2	0-04-98 [Angor@Simauria] Creacion
		16-01-05 [Gw] Arreglado un bug con el nombre del player.
--------------------------------------------------------------------------------
*/

inherit FOOD;

create() {
   ::create();
   SetFoodKind("food");
   SetFoodMsgs(({"Te comes una bolsa de rosquillas.\n","@@Pl_Name@@ se come unas rosquillas.\n"}));
   SetFoodStuff(15);
   SetFoodHeal(10);
   SetShort("una bolsa de rosquillas");
   SetLong("Es una pequenya bolsa de rosquillas con almendras.\n");
   AddId("rosquillas");
   AddId("comida");
   SetWeight(100);
   SetValue(60);
}
