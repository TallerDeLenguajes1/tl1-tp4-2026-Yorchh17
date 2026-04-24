#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

//CONSTANTES
#define MAX 50

//ESTRUCTURAS
typedef struct Tarea{
    int TareaID; //Numérico autoincremental comenzando en 1000
    char *Descripcion; //
    int Duracion; // entre 10 – 100
} Tarea;

typedef struct Nodo {
    Tarea T;
    struct Nodo *Siguiente;
} Nodo;

//FUNCIONES
Nodo *CrearListaVacia();
Nodo *CargarTareas(int ID);
void MostrarLista(Nodo *lista);

int main(){
    srand(time(NULL));
    int bandera=1;
    int ID=1000;
    Nodo *listaPendientes = CrearListaVacia();
    Nodo *listaRealizadas = CrearListaVacia();

    printf("\nDesea cargar una tarea?(1_SI/0_NO) ");
    scanf("%d",&bandera);

    while(bandera==1){
        Nodo *nuevo = CargarTareas(ID);
        nuevo->Siguiente = listaPendientes;
        listaPendientes=nuevo;
        ID++;
        printf("Desea continuar con la carga?(1_SI/0_NO) ");
        scanf("%d",&bandera);
    }

    printf("\n\nLISTADO DE TAREAS PENDIENTES:");
    MostrarLista(listaPendientes);

    return 0;
}

Nodo *CrearListaVacia(){
    return NULL;
}

Nodo *CargarTareas(int ID){
    char buffer[MAX];
    printf("\n=== Nueva Tarea (ID: %d) ===", ID);
    
    Nodo *nuevoNodo = (Nodo *)malloc(sizeof(Nodo));
    nuevoNodo->T.TareaID = ID;
    
    printf("\nIngrese la descripcion: ");
    fflush(stdin);
    fgets(buffer, MAX, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    
    nuevoNodo->T.Descripcion = (char *)malloc((strlen(buffer) + 1) * sizeof(char));
    strcpy(nuevoNodo->T.Descripcion, buffer);
    
    nuevoNodo->T.Duracion = 10 + rand() % 91;
    nuevoNodo->Siguiente = NULL;
    
    return nuevoNodo;
}

void MostrarLista(Nodo *lista){
    Nodo *aux = lista;
    int i = 1;
    while (aux != NULL) { 
        printf("\n--- Tarea  %d ---", i);
        printf("\nID de tarea: %d", aux->T.TareaID); 
        printf("\nDescripcion: %s", aux->T.Descripcion); 
        printf("\nDuracion: %d", aux->T.Duracion); 
        
        aux = aux->Siguiente; 
        i++;
    }
}