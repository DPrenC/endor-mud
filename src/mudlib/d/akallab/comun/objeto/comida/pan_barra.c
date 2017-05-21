/*
DESCRIPCION  : una barra de pan
FICHERO      : /d/akallab/comun/objeto/comida/pan_barra.c
MODIFICACION : 	20-04-98 [Angor@Simauria] Creacion
               	25-10-99 [woo] Un array es ({ }) no " "," "
               	16-01-05 [Gw] Arreglado un bug con el nombre del player.
--------------------------------------------------------------------------------
*/

inherit FOOD;

create() {
   ::create();
   SetFoodKind("food");
   SetFoodMsgs(({"Te comes una crujiente barra de pan.\n","@@Pl_Name@@ se come una barra de pan.\n"}));
   SetFoodStuff(20);
   SetFoodHeal(10);
   SetShort("una crujiente barra de pan");
   SetLong("Es una dorada y crujiente barra de pan recien hecho.\n");
   AddId("barra");
   AddId("comida");
   SetWeight(75);
   SetValue(25);
}
