
#include "./path.h"
inherit NPC;
#include <properties.h>
create ()
{
    ::create();
    SetStandard("Marla","humano",13,GENERO_FEMENINO);
    SetShort("una sacerdotisa");
    SetLong(
    "Es Marla, la sacerdotisa de la diosa Valevissa, una mujer alta, y fuerte "
    "est� apenada porque alguien le ha roto el c�liz sagrado con el que realizaba "
    "las ofrendas a la diosa para que favoreciera la pesca.\n");
    AddId(({"mujer", "humana","Sacerdotisa","Marla", "marla"}));
    SetCitizenship("gorat");
    InitChats(3,({
          "La sacerdotisa dice: �qui�n podr�a ayudarme?\n",
        "La sacerdotisa exclama:\n �Me han roto el c�liz, que voy a hacer ahora!\n"}));

    AddQuestion(({"c�liz", "caliz"}),
    "Marla dice: es el c�liz para la ceremonia de la pesca, si pudieras conseguirme otro "
    "te estar�a eternamente agradecida, el C�liz debe estar forjado en vidrio "
    "proveniente de las playas del islote donde se apareci� la diosa por primera "
    "vez, y debe tener una s�lida base de oro tallada a mano.\n"), 1;
    AddQuestion("islote",
    "Marla dice: Seg�n cuenta la leyenda, la diosa se le apareci� a unos pescadores que se "
    "perdieron en el mar durante una tormenta, les gui� a un peque�o islote "
    "que se encuentra en las cercan�as de gorat, donde se le levant� una estatua, "
    "all� es donde tienes que conseguir la arena para poder hacer el c�liz.\n", 1);
    AddQuestion("talla",
    "Marla dice: El caliz sagrado tiene que estar tallado con unas runas que ense�� la diosa "
    "al grupo de pescadores, sin las cuales el caliz no tiene validez.\n", 1);
}

public varargs int DoDamage (int damage, int type, int gentle, mixed xtras) {

    if(QueryHP()==QueryMaxHP())
        write("La sacerdotisa grita: �Valevissa, prot�geme!\n");

    return ::DoDamage(damage, type, gentle, &xtras);
}
