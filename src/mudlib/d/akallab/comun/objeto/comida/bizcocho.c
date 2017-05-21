/*
DESCRIPCION  : un bizcocho
FICHERO      : /d/akallab/comun/objeto/comida/bizcocho.c
MODIFICACION : 	20-04-98 [Angor@Simauria] Creacion
		16-01-05 [Gw] Arreglado un bug con el nombre del player.
--------------------------------------------------------------------------------
*/

inherit FOOD;

create() {
   ::create();
   SetFoodKind("food");
   SetFoodMsgs(({"Te comes un dulce bizcocho.\n","@@Pl_Name@@ se come un bizcocho.\n"}));
   SetFoodStuff(30);
   SetFoodHeal(10);
   SetShort("un bizcocho");
   SetLong("Es un bizcocho tostado cubierto de azucar.\n");
   AddId("bizcocho");
   AddId("comida");
   SetWeight(100);
   SetValue(50);
}
