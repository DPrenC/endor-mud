/* Oficina de Correos de berat
 * [m] Mirill
 *
 * 24/01/98 Creacion
 * [j] jorus
 * 29/10/99 modifica para berat
 */

#include "./path.h"
#include <moving.h>

inherit SIM_ROOM;

public int rfolleto(string str)
{

  object ob;
  if (str == "folleto")
  {
  ob = clone_object("/d/simauria/comun/objeto/otro/follcor");
  if (ob->move(TP,M_SILENT)!=ME_OK)
    {
      write("No puedes llevar nada más.\n");
      ob->remove();
      if (ob) destruct(ob);
    }
  else
    write("Recoges un folleto.\n");
  }
  return 1;
}

create() {
  ::create();

 SetLocate("berat");
 SetIntNoise("Oyes el ruido de papeles que se doblan y se archivan.\n");
 SetIntSmell("Huele a papel.\n");
 SetIndoors(1);
  SetIntBright(50);
  SetIntShort("la oficina de correos de Berat");
  SetIntLong(W(
"Estás en el Departamento de Mensajería de la Hermandad de Banqueros, "
"ves al encargado detras de un mostrador clasificando mensajes en unos "
"grandes archivadores. Encima de la mesa puedes ver una caja con folletos. "
"En la mesa puedes escribir los correos que quieras mandar y leer los que "
"hayas recibido. "
"Al sur se encuentra el banco.\n"));

AddDetail(({"archivadores","achivador","grandes archivadores"}),
  "En estos grandes archivadores se clasifica el correo por zonas para "
  "que luego los mensajeros lo repartan.\n");
AddDetail(({"hombre","dependiente","cartero"}),W(
  "Es un humano normal. Su trabajo consiste en clasificar los mensajes "
  "por dominios en los archivadores para que luego los mensajeros los "
  "repartan.\n"));
AddExit("oeste","./cprin2");
AddExit("sur","./bancoh");
AddItem(PNJ("cartero"),REFRESH_DESTRUCT,1);
AddRoomCmd("recoger",SF(rfolleto));
}
