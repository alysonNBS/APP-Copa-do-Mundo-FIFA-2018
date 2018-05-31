int string_comp(char *s1, char *s2)
{
    if(s1 == NULL || s2 == NULL)
        return 100;
    return strcmp(s1, s2);
}