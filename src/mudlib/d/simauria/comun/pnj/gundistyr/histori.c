/* **********************************************************
   *                                                        *
   *    Archivo: histori.c                                  *
   *    Autor: [a] Articman                                 *
   *    Modificaci�n: [a] Creaci�n                          *
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
		write(W("���Much�simas gracias!!! Ahora podr� publicar el trabajo que "
              "les cost� la vida a mis amigos. Ser� un gran homenaje hacia "
			  "ellos. Toma esto es lo �nico de valor que puedo darte como "
			  "agradecimiento. Lo encontr� en una de nuestras expediciones. "
			  "Por favor, qu�datelo.\n"));
        ob2=clone_object("/d/simauria/comun/objeto/proteccion/gundistyr/amuletozaf");
        ob2->move(TP);
		return 1;
	  }
	  else {
	   write("Ailan dice: No se para qu� me das esto...\n");
       return 0;
	  }
    }
else notify_fail("�Dar el qu� a qui�n?\n",NOTIFY_NOT_VALID)&&0;
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
 "cuarentena. Parece ser muy d�bil fisicamente, su cuerpo no est� "
 "precisamente preparado para el combate. Sus ropas est�n sucias y "
 "destrozadas. Tiene el rostro muy nervioso y los ojos rojos. Parece "
 "que ha estado llorando.\n"));
 SetHP(50);
 //A partir de aqui viene lo relacionado con el quest

 InitChats(7,({"Ailan llora desconsoladamente.\n",
               "Ailan esconde el rostro entre sus brazos y vuelve "
               "a llorar.\n",
               "Ailan mira hacia t� con ojos temerosos.\n",
               "Ailan dice: Lo sab�a, jam�s debimos ir a la torre.\n",
               "Ailan dice: Est�n todos muertos... mis pobres compa�eros....\n",
               "Ailan dice: Hemos perdido todas nuestras notas. "
               "�Malditos demonios!\n"}));
 AddQuestion(({"torre","gundistyr","Gundistyr"}),W("Esa maltida torre de Gundistyr, jam�s debimos "
 "ir all�, siempre lo he dicho... Unos demonios nos atacaron por la noche "
 "y mataron a mis compa�eros.\n"));
 AddQuestion(({"demonios","demonio"}),W("Unas extra�as y chillonas criaturas nos atacaron por "
 "noche y mataron a mis compa�eros. �Estoy seguro de que eran demonios!\n"));
 AddQuestion(({"compa�eros","amigos","companyeros"}),W("Dos compa�eros y yo fuimos a investigar las ruinas de "
 "Gundistyr para estudiarlas cuando nos vimos asaltados por esas criaturas... Yo logr� huir, pero "
 "mis compa�eros murieron y perdimos todos nuestros documentos.\n"));
 AddQuestion(({"documento","documentos","notas"}),W("Al huir no pude coger los escritos con nuestras notas. "
 "Me averg�enzo de mi cobardia. Ahora mis amigos est�n muertos. Ojal� pudiera recuperar los documentos "
 "para honrar a mis amigos.\n"));
 AddQuestion(({"amuleto","amuleto de zafiro","amuleto para g�rgolas"}),W("�Oh, s�, tengo un amuleto aqu� "
 "conmigo. Es �l quien nos ha llevado a todos a la desgracia. Aunque tenga mucho valor, se lo dar�a a "
 "cualquiera que me diera los manuscritos perdidos, esos s� tienen much�simo m�s valor para m�. Es "
 "el �ltimo recuerdo de mis compa�eros...\n"));
}