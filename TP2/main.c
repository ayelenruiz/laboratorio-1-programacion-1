#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <conio.h>
#define A 20


typedef struct
{
    char nombre[A][50];
    int edad[A];
    int dni[A];

}ePersona;

int obtenerEspacioLibre(ePersona lista[]);
int buscarPorDni(ePersona lista[], int dni);

int main()
{
    int opcion;
    int i;
    char seguir='s';
    int j;
    int auxDni;
     char respuesta='s';
    int flagEncontro;

    ePersona persona[A], auxChar;


    do
    {
      printf("1. Agregar persona\n");
      printf("2. Borrar una persona\n");
      printf("3. Imprimir lista ordanada por nombre\n");
      printf("4. imprimir grafico ordenado por nombre\n");
      printf("5. Salir\n");
      printf("Ingrese una opcion: ");
      scanf("%d", &opcion);


        switch(opcion)
        {
           case 1:
           for(i=0; i<A; i++)
           {

             printf("Ingrese un nombre: ");
             fflush(stdin);
             gets(persona[i].nombre[i]);
             printf("Ingese edad: ");
             scanf("%d", & persona[i].edad[i]);
             printf("Ingrese DNI: ");
             scanf("%d", & persona[i].dni[i]);

           }
           break;

           case 2:

    flagEncontro=0;

            printf("Ingrese DNI a buscar");
            scanf("%d", & auxDni);

            for(i=0; i<A; i++)
            {
                if(auxDni==persona[i].dni[i])
                {
                  printf("%s\t %d\t %d\t", persona[i].nombre[i], persona[i].edad[i], persona[i].dni[i] );
                  printf("Esta seguro de eliminar esta persona?: ");
                  respuesta = getche();

                  if(respuesta=='s')
                    {
                        persona[i].dni[i]=-1;
                    }
                    else
                    {
                        printf("Accion cancelada por el usuario!!!");
                    }
                    flagEncontro = 1;
                    break;
                }
                if(flagEncontro==0)
                {

                   printf("Dni inexistente");

                }

            }

           break;

           case 3:

            for(i=0; i<A-1; i++)
            {
               for(j=i+1; j<A; j++)
               {
                 if(persona[i].dni[i] > persona[j].dni[j])
                 {
                   auxChar = persona[i];
                   persona[i] = persona[j];
                   persona[j] = auxChar;

                 }

               }

            }
            for(i=0; i<A; i++)
            {
                printf("%s\t %d\t %d\t", persona[i].nombre[i], persona[i].edad[i], persona[i].dni[i]);
                fflush(stdin);
            }
              fflush(stdin);

           break;


           case 5:
           seguir='n';
           break;
        }
        system("pause");
        system("cls");

    }while(seguir=='s');




    return 0;
}
/*int obtenerEspacioLibre(int estado[] , int tam)
{

 */

 /*  int encontro=-1;

    for(i=0; i<tam; i++)
    {
        if(estado[i]==0)
        {
            encontro=i;
            break;
        }
    }

    return encontro;
}*/
/*int buscarPorDni(ePersona[], int dni)
{


}*/




