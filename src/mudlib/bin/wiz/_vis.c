// Comando vis

#include <messages.h>
#include <attributes.h>
#include <properties.h>

public int main(string arg) {
    mixed mmsgin;

    if (arg) return notify_fail("Uso: "+query_verb()+".\n");

    if (!TP->Query(P_INVIS) && !TP->Query(P_INWIZ)) {
        return notify_fail("No te encuentras en forma incorpórea.\n");
    }

    TP->Set(P_INVIS, 0);
    TP->Set(P_INWIZ, 0);
    write("Adoptas de nuevo un cuerpo físico.\n");

    mmsgin = TP->QueryAttr(A_MMSGIN);
    if (!pointerp(mmsgin)) mmsgin = ({ mmsgin});
    tell_room(environment(TP), ({ MSG_SEE, TP->QueryName()+" "+mmsgin[0]+"\n" }), ({ TP }));

    return 1;
}