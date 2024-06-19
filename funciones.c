#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <string.h>

void buscarPorTamano(int *numHabitacion,char habitaciones[][3][40],double precios[]){
    char tipo[40];
    int comp=0,x[3],j=0;
    printf("Ingrese el tamaño de habitacion que desea buscar: ");
    scanf("%s",tipo);
    for (int i = 0; i < 9; i++)
    {
        if (strcmp(habitaciones[i][1],tipo)==0)
        {
            printf("#\t\tTamaño\t\tHotel\t\tPrecio\n");
            comp=1;
            break;
        }
    }
    for (int i = 0; i < 9; i++)
    {
        if (strcmp(habitaciones[i][1],tipo)==0)
        {
            printf("%s\t\t%s\t\t%s\t\t%lf\n",habitaciones[i][0],habitaciones[i][1],habitaciones[i][2],precios[i]);
            x[j]=i+1;
            j++;
        }
    }
    if (comp==1) {
        printf("Elija la habitacion que desea reservar: ");
        scanf("%d",numHabitacion);        
        while (*numHabitacion!=x[0] && *numHabitacion!=x[1] && *numHabitacion!=x[2]){
            printf("Ingrese una habitacion valida\n");
            scanf("%d",numHabitacion);
        }
        
    } else {
        printf("No se ha encontrado ninguna habitacion de tipo %s\n",tipo);
    }
}

void buscarHotel(int *numHabitacion,char habitaciones[][3][40],double precios[]){
    char hotel[40];
    int j=0,x[3],comp=0;
    printf("Ingrese el hotel que desea buscar : ");
    scanf("%s",hotel);
    for (int i = 0; i < 9; i++)
    {
        if (strcmp(habitaciones[i][2],hotel)==0)
        {
            printf("#\t\tTamaño\t\tHotel\t\tPrecio\n");
            comp=1;
            break;
        }
    }
    for (int i = 0; i < 9; i++)
    {
        if (strcmp(habitaciones[i][1],hotel)==0)
        {
            printf("%s\t\t%s\t\t%s\t\t%lf\n",habitaciones[i][0],habitaciones[i][1],habitaciones[i][2],precios[i]);
            x[j]=i;
            j++;
        }
    }
    if (comp==1){
        printf("Elija la habitacion que desea reservar: ");
        scanf("%d",numHabitacion);
        while (*numHabitacion!=x[0] && *numHabitacion!=x[1] && *numHabitacion!=x[2]){
            printf("Ingrese una habitacion valida\n");
            scanf("%d",numHabitacion);
        }
    } else {
        printf("No se ha encontrado el hotel %s\n",hotel);
    }
}

void realizarReserva(int numHabitacion,char habitaciones[][3][40],char clientes[][2][40],int reservas[][4],int *numClientes){
    if (numHabitacion==-1){
        printf("Busque primero una habitacion, ingrese 1 en el menu principal\n");
    } else {
        char c[40];
        printf("\nIngrese el numero de cedula del cliente que realiza la reserva : ");
        scanf("%s",c);
        for (int i = 0; i < 5; i++)
        {
            if (atoi(c)==reservas[i][0]){
                printf("Ya hay una reserva con ese numero de cedula\n");
                goto end;
            }
        }
        strcpy(clientes[*numClientes][1],c);
        printf("Ingrese el nombre del cliente que realiza la reserva : ");
        scanf("%s",&clientes[*numClientes][0]);
        printf("\nDe cuantos dias va a ser a estadia en el hotel : ");
        scanf("%d",&reservas[*numClientes][2]);
        reservas[*numClientes][0]=atoi(clientes[*numClientes][1]);
        reservas[*numClientes][1]=numHabitacion;
        *numClientes+=1;
        end:
    }
}

void buscarReservaPorCedula(int *numReserva,int reservas[][4]){
    int cedula;
    printf("Ingrese el numero de cedula de la reserva : ");
    scanf("%d",&cedula);
    for (int i = 0; i < 5; i++)
    {
        if (cedula==reservas[i][0]){
            *numReserva=i;
            break;
        }
    }
}