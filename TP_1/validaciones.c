int validacionFactorial (float numero)
{
    if(numero<0)
    {
        return 0;
    }
    else
    {
        int ent=(int)numero;
        if(numero-ent ==0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}
