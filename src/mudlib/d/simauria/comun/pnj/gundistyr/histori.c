/* **********************************************************
   *                                                        *
   *    Archivo: histori.c                                  *
   *    Autor: [a] Articman                                 *
   *    Modificación: [a] Creación                          *
   *                                                        *
   ********************************************************** */

#include "path.h"
#include <properties.h>

inherit NPC;

object manuscrito;

init() {
::init();
add_action("cmd_dar","dar");
}

int cmd_dar(string str) {

object ob,ob2;

string a;

if ((sscanf(str,"%s a historiador",a)==1) ||
	(sscanf(str,"%s a Ailan",a)==1) ||
	(sscanf(str,"%s a ailan",a)==1)) {
	  if(!TP || !str) return 0;
      ob=present(a,TP);
	  if (!ob) return notify_fail("No encuentras "+a+" para dar.\n",NOTIFY_NOT_VALID)&&0;
	  manuscrito=present("q_manuscritos_gargola",TP);
      if (manuscrito) {
	    manuscrito->remove();
		write(W("¡¡¡Muchísimas gracias!!! Ahora podré publicar el trabajo que "
              "les costó la vida a mis amigos. Será un gran homenaje hacia "
			  "ellos. Toma esto es lo único de valor que puedo darte como "
			  "agradecimiento. Lo encontré en una de nuestras expediciones. "
			  "Por favor, quédatelo.\n"));
        ob2=clone_object("/d/simauria/comun/objeto/proteccion/gundistyr/amuletozaf");
        ob2->move(TP);
		return 1;
	  }
	  else {
	   write("Ailan dice: No se para qué me das esto...\n");
       return 0;
	  }
    }
else notify_fail("¿Dar el qué a quién?\n",NOTIFY_NOT_VALID)&&0;
return 0;
}



 create(){
 ::create();
 SetStandard("Ailan el historiador","humano",9,GENERO_MASCULINO);
 SetMaxHP(50);
 SetHP(50);
 SetWhimpy(49); /* Es mu cobarde y tiene mucho miedo */
 SetAlign(300);
 SetAggressive(0);
 SetName("Ailan");
 SetIds(({"humano","ailan","Ailan","historiador"}));
 SetShort("Ailan el historiador");
 SetLong(W("Ailan es un humano que parece haber llegado a la "
 "cuarentena. Parece ser muy débil fisicamente, su cuerpo no está "
 "precisamente preparado para el combate. Sus ropas están sucias y "
 "destrozadas. Tiene el rostro muy nervioso y los ojos rojos. Parece "
 "que ha estado llorando.\n"));
 SetHP(50);
 //A partir de aqui viene lo relacionado con el quest

 InitChats(7,({"Ailan llora desconsoladamente.\n",
               "Ailan esconde el rostro entre sus brazos y vuelve "
               "a llorar.\n",
               "Ailan mira hacia tí con ojos temerosos.\n",
               "Ailan dice: Lo sabía, jamás debimos ir a la torre.\n",
               "Ailan dice: Están todos muertos... mis pobres compañeros....\n",
               "Ailan dice: Hemos perdido todas nuestras notas. "
               "¡Malditos demonios!\n"}));
 AddQuestion(({"torre","gundistyr","Gundistyr"}),W("Esa maltida torre de Gundistyr, jamás debimos "
 "ir allí, siempre lo he dicho... Unos demonios nos atacaron por la noche "
 "y mataron a mis compañeros.\n"));
 AddQuestion(({"demonios","demonio"}),W("Unas extrañas y chillonas criaturas nos atacaron por "
 "noche y mataron a mis compañeros. ¡Estoy seguro de que eran demonios!\n"));
 AddQuestion(({"compañeros","amigos","companyeros"}),W("Dos compañeros y yo fuimos a investigar las ruinas de "
 "Gundistyr para estudiarlas cuando nos vimos asaltados por esas criaturas... Yo logré huir, pero "
 "mis compañeros murieron y perdimos todos nuestros documentos.\n"));
 AddQuestion(({"documento","documentos","notas"}),W("Al huir no pude coger los escritos con nuestras notas. "
 "Me avergüenzo de mi cobardia. Ahora mis amigos están muertos. Ojalá pudiera recuperar los documentos "
 "para honrar a mis amigos.\n"));
 AddQuestion(({"amuleto","amuleto de zafiro","amuleto para gárgolas"}),W("¡Oh, sí, tengo un amuleto aquí "
 "conmigo. Es él quien nos ha llevado a todos a la desgracia. Aunque tenga mucho valor, se lo daría a "
 "cualquiera que me diera los manuscritos perdidos, esos sí tienen muchísimo más valor para mí. Es "
 "el último recuerdo de mis compañeros...\n"));
}