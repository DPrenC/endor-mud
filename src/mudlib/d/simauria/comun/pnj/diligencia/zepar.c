/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 01-05-97                |
 |               Ultima Modificacion.. 01-05-97                |
 |                                                             |
 *=============================================================*/

inherit NPC;

create()
{

 ::create();
 AddId("conductor");
 SetShort("El conductor");
 SetLong("Es un conductor de diligencias.\n");
 SetRace("humano");
 SetLevel(4);
 SetAlign(10);
 SetGender(1);
}


