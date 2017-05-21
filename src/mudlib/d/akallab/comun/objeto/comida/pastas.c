/*
DESCRIPCION  : una bolsa de pastas de te
FICHERO      : /d/akallab/comun/objeto/comida/pastas.c
MODIFICACION : 	20-04-98 [Angor@Simauria] Creacion
		16-01-05 [Gw] Arreglado un bug con el nombre del player.
--------------------------------------------------------------------------------
*/

inherit FOOD;

create() {
   ::create();
   SetFoodKind("food");
   SetFoodMsgs(({"Te comes una bolsa de pastas de te.\n","@@Pl_Name@@ se come unas pastas de te.\n"}));
   SetFoodStuff(25);
   SetFoodHeal(5);
   SetShort("una bolsa de pastas de te");
   SetLong("Es una pequenya bolsa llena con crujientes pastas de te.\n");
   AddId("pastas");
   AddId("pastas de te");
   AddId("comida");
   SetWeight(100);
   SetValue(40);
}
