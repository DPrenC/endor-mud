#include <moving.h>

public int main(string args)
{
    string salida, extra;
    object env;
    int i;

    if (!args)
    {
        return notify_fail("�Ir d�nde?\n", NOTIFY_NOT_VALID);
    }
    if (!(env = environment(TP))) return notify_fail("�No est�s en ning�n sitio!\n");
    
    if ((i = strstr(args, " ")) > -1)
    {
        salida = args[..i - 1];
        extra = args[i + 1..];
    }
    else salida = args;
    return env->UseExit(salida, extra, M_GO);
}