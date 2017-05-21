/*
DESCRIPCION  : un pan de molde
FICHERO      : /d/akallab/comun/objeto/comida/pan_molde.c
MODIFICACION : 	20-04-98 [Angor@Simauria] Creacion
		16-01-05 [Gw] Arreglado un bug con el nombre del player.
--------------------------------------------------------------------------------
*/

inherit FOOD;

create() {
   ::create();
   SetFoodKind("food");
   SetFoodMsgs(({"Te comes un mullido pan de molde.\n","@@Pl_Name@@ se come un pan de molde.\n"}));
   SetFoodStuff(35);
   SetFoodHeal(12);
   SetShort("un pan de molde");
   SetLong("Es un mullido pan de molde.\n");
   AddId("pan");
   AddId("pan de molde");
   AddId("comida");
   SetWeight(100);
   SetValue(50);
}
