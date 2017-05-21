/**
 * bin/mortal/_llamar
**/

public int main(string str)
{
    object env;
    if (!TP || !(env = environment(TP))) return 0;
    return env->fknock(str);
}
