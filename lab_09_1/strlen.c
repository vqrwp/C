/*
Находит длину строки

@param string [in] - строка
@param i [out] - длина строки

@return возвращает длину строки
*/
unsigned int my_strlen(const char *string)
{
    unsigned int i = 0;
    for (i = 0; string[i]; i++);
    return i;
}