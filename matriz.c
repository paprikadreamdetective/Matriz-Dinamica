#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"matrix.h"

void nuevaMatriz(MATRIZ *matriz)
{
    matriz->principio = NULL;
    matriz->final = NULL;
    matriz->x = 0;
    matriz->y = 0;
}

void nuevaLista(LISTA *lista)
{
    lista->cabeza = NULL;
    lista->cola = NULL;
    lista->sigRenglon = NULL;
    lista->dim = 0;
}

void nuevoNodo(NODO *nodo)
{
    nodo->sig = NULL;
    nodo->ant = NULL;
    nodo->i = 0;
    nodo->j = 0;
}

int IsEmptyList(LISTA lista)
{
    if(lista.cabeza == NULL)
        return(1);
    else
        return(0);
}

int IsEmptyMatrix(MATRIZ matriz)
{
    if(matriz.principio == NULL)
        return(1);
    else
        return(0);
}

void MatrizIn(MATRIZ *matriz, LISTA *lista)
{
    if(IsEmptyMatrix(*matriz) == 1)
    {
        matriz->principio = lista;
        matriz->final = lista;
    }
    else
    {
        matriz->final->sigRenglon = lista;
        matriz->final = lista;
    }
}

void ImprimirLista(LISTA *lista)
{
    NODO *aux = lista->cabeza;
    DATO dat;

    if(IsEmptyList(*lista) == 1)
        printf(">> Lista vacia. \n");
    else
    {
        //printf(">> Lista: \n\n");
        while(aux != NULL)
        {
            // dat = aux->dato;
            printf(">> ai(%d)j(%d)\t",aux->i, aux->j);
            printf(">> %d   %c\t",aux->dato.index, aux->dato.array);
            aux = aux->sig;
        }
    }
}


void anadir(LISTA *lista, char cadena, int indice, int i0, int j0)
{
    NODO *head, *actual, *anterior, *aux, *tail;
    head = lista->cabeza;
    actual = head;
    anterior = head;
    //tail = lista->cola;

    if(IsEmptyList(*lista) == 1) /*Si esta vacia,crear un elemento*/
    {
        head = (NODO*)malloc(sizeof(NODO));
        nuevoNodo(head);
        head->dato.array = cadena;
        head->dato.index = indice;
        head->i = i0;
        head->j = j0;
        lista->cabeza = head;
        //lista->cola = head;
        lista->dim++;
        return;
    }
        /*Encontrar el punto de inserccion*/
    // while(actual != NULL && indice > actual->dato.index)
    while(actual != NULL)
    {
        anterior = actual;
        actual = actual->sig;
    }

    aux = (NODO*)malloc(sizeof(NODO));
    nuevoNodo(aux); /*Se genera un nuevo nodo*/

    if(anterior == actual) /*Insertar al inicio*/
    {
        aux->dato.array = cadena;
        aux->dato.index = indice;
        aux->i = i0;
        aux->j = j0;
        //aux = head->ant;
        aux->sig = head;
        head = aux;
        lista->dim++;
    }
    else /*Insertar despues de anterior*/
    {
        aux->dato.array = cadena;
        aux->dato.index = indice;
        aux->i = i0;
        aux->j = j0;
        aux->sig = actual;
        //actual->ant = aux;
        anterior->sig = aux;
        //aux->ant = anterior;
        lista->dim++;
    }
    lista->cabeza = head;
}



void remover(LISTA *lista, int indice)
{
    NODO *head = lista->cabeza;
    NODO *actual = head;
    NODO *anterior = head;

    if(IsEmptyList(*lista) == 1)
    {
        printf(">> Lista vacia. \n");
        return;
    }
    /*Entrar en la lista y encontrar el elemento a borrar*/
    while(actual != NULL && indice != actual->dato.index)
    {
        anterior = actual;
        actual = actual->sig;
    }
    /*Si el dato no se encuentra: */
    if(actual == NULL)
    {
        printf("\n");
        printf(">> Elemento no encontrado. \n");
        return;
    }
    /*Si el dato se encuentra: */
    if(anterior == actual)
    {
        head = head->sig;/*Borrar un elemento de la cabeza*/
        printf("\n");
        printf(">> Elemento eliminado. \n");
    }
    else
    {
        anterior->sig = actual->sig; /*Borrar elemento que no sea la cabeza*/
        printf("\n");
        printf(">> Elemento eliminado. \n");
    }
    free(actual);
    lista->cabeza = head;
    lista->dim--;
}

void removerColaLista(LISTA *lista)
{
    NODO *cola;
    NODO *anterior;
    if(IsEmptyList(*lista) == 1)
        printf(">> Lista vacia. \n");
    else
    {
        if(lista->cabeza->sig == NULL)
            lista->cabeza = NULL;
        else
        {
            cola=lista->cabeza;
            while(cola->sig != NULL)
            {
                anterior = cola;
                cola = cola->sig;
            }
            anterior->sig = NULL;
            cola=NULL;
            free(cola);
        }
    }
}

void buscar(LISTA *lista, int indice)
{
    NODO *actual = lista->cabeza;

    while(actual != NULL && indice != actual->dato.index)
    {
        actual = actual->sig;
    }

    if(actual)
    {
        printf("\n");
        printf(">> %d      %c\n", actual->dato.index, actual->dato.array);
    }
    else
    {
        printf("\n");
        printf(">> Elemento no encontrado. \n");
    }
}

int size(LISTA *lista)
{
    return(lista->dim);
}

void imprimirMatriz(MATRIZ matriz)
{
    int cnt;
    if(IsEmptyMatrix(matriz) == 1)
    {
        printf("\t >> La matriz esta vacia. \n");
        return;
    }
    else
    {
        cnt = 1;
        printf("\t Matriz: \n");
        while(matriz.principio != NULL)
        {
            printf("Renglon %d\t", cnt);
            ImprimirLista(matriz.principio);
            printf("\n\n");
            matriz.principio = matriz.principio->sigRenglon;
            cnt++;
        }
    }
    printf("----------------------------------------\n");
}

void definirMatriz(MATRIZ *M)
{
    LISTA *lista;
    int number;
    int cnt1, cnt2;
    char a = '\0';
    int n;
    int m;
    printf("\t ----------------------------------------\n");
    printf("\t Ingrese la dimension de la matriz mxn \n");
    printf("\t Numero de renglones:");
    scanf("%d", &n);
    printf("\n");
    printf("\t Numero de columnas: ");
    scanf("%d", &m);
    M->x = n;
    M->y = m;
    cnt1 = 1;
    while(cnt1 <= M->x)
    {
        cnt2 = 1;
        lista = (LISTA*)malloc(sizeof(LISTA));
        nuevaLista(lista);
        while(cnt2 <= M->y)
        {
            printf("Ingrese un elemento a la lista  \n");
            printf("Numero de Elemento i(%d) j(%d)]  \n", cnt1, cnt2);
            scanf("%d", &number);
            anadir(lista, a, number, cnt1, cnt2);
            cnt2++;
        }
        MatrizIn(M, lista);
        cnt1++;
    }
    printf("----------------------------------------\n");
}

int obtenerElementoMatriz(MATRIZ *A, int renglon, int columna)
{
    LISTA *lista = A->principio;
    if(IsEmptyMatrix(*A) == 1)
        return(0);
    else
    {
        while(lista != NULL) /*Recorre los renglones de la matriz*/
        {
            NODO *aux = lista->cabeza;
            while(aux != NULL) /*Recorre las columnas de la matriz*/
            {
                DATO elemento = aux->dato;
                if(aux->i == renglon && aux->j == columna)
                    return(elemento.index);
                aux = aux->sig;
            }
            lista = lista->sigRenglon;
        }
    }
}

void productoMatricial(MATRIZ *A, MATRIZ *B, MATRIZ *AxB)
{
    int i, j, k;
    int suma;
    int a;
    int b;
    if(A->y != B->x)
    {
        printf("\t Las dimensiones de las matrices son incompatibles: A(%d x %d) B(%d x %d)\n", A->x, A->y, B->x, B->y);
        return;
    }
    else
    {
        i=1;
        while(i <= A->x)
        {
            j=1;
            LISTA *listaAux;
            listaAux = (LISTA*)malloc(sizeof(LISTA));
            nuevaLista(listaAux);
            while(j <= B->y)
            {
                k=1;
                suma = 0;
                while(k <= A->y)
                {
                    a = obtenerElementoMatriz(A, i, k);
                    b = obtenerElementoMatriz(B, k, j);
                    suma = suma + a * b;
                    k++;
                }
                anadir(listaAux, '\0', suma, i, j);
                j++;
            }
            MatrizIn(AxB, listaAux);
            i++;
        }
    }
}

int max(int num1, int num2)
{
    int result;
    if(num1 > num2)
        result = num1;
    else
        result = num2;
    return result;
}

int min(int num1, int num2)
{
    int result;
    if(num1 < num2)
        result = num1;
    else
        result = num2;
    return result;
}

void sumaDiagonales(MATRIZ *A, LISTA *listaAux)
{
    int a;
    int numRows = A->x;
    int numCols = A->y;
    if(IsEmptyMatrix(*A) == 1)
    {
        printf("\t >> La matriz esta vacia. \n");
        return;
    }
    else
    {
        LISTA *renglon = A->principio;
        for(int diagonal = 1 - (numCols + 1); diagonal < numRows; diagonal++)
        {
            int suma = 0;
            for(int vertical = max(1, diagonal), horizontal = -min(1, diagonal); vertical <= numRows && horizontal <= numCols; vertical++, horizontal++)
            {
                if(vertical >= 1 && horizontal >= 1)
                {
                    a = obtenerElementoMatriz(A, vertical, horizontal);
                    suma = suma + a;
                }
            }
            anadir(listaAux, '\0', suma, 0, 0);
        }
        removerColaLista(listaAux);
    }
}

NODO *obtenerColaLista(LISTA *lista)
{
    NODO *head = lista->cabeza;
    NODO *temp = head;
    while(temp != NULL && temp->sig != NULL)
        temp = temp->sig;
    return(temp);
}

NODO *particion(NODO *first, NODO *last)
{
    NODO *pivot = first;
    NODO *front = first;
    int number;
    while(front != NULL && front != last)
    {
        if(front->dato.index < last->dato.index)
        {
            pivot = first;
            number = first->dato.index;
            first->dato.index = front->dato.index;
            front->dato.index = number;
            first = pivot->sig;
        }
        front = front->sig;
    }
    number = first->dato.index;
    first->dato.index = last->dato.index;
    last->dato.index = number;
    return(pivot);
}

void quicksort(NODO *first, NODO *last)
{
    if(first == last)
        return;
    NODO *pivot = particion(first, last);
    if(pivot != NULL && pivot->sig != NULL)
        quicksort(pivot->sig, last);
    if(pivot != NULL && first != pivot)
        quicksort(first, pivot);
}

void ordenarMatriz(MATRIZ *matriz)
{
    if(IsEmptyMatrix(*matriz) == 1)
    {
        printf("\t >> La matriz esta vacia. \n");
        return;
    }
    else
    {
        LISTA *renglon = matriz->principio;
        while(renglon != NULL)
        {
            quicksort(renglon->cabeza, obtenerColaLista(renglon));
            renglon = renglon->sigRenglon;
        }
    }
}

NODO *centro(NODO* start, NODO* last)
{
    if(start == NULL)
        return NULL;
    NODO* slow = start;
    NODO* fast = start->sig;
    while(fast != last)
    {
        fast = fast->sig;
        if (fast != last)
        {
            slow = slow->sig;
            fast = fast->sig;
        }
    }
    return(slow);
}

NODO* busqueda_binaria(LISTA *lista, int value)
{
    NODO* start = lista->cabeza;
    NODO* last = NULL;

    do
    {
        NODO* mid = centro(start, last);
        if (mid == NULL)
            return NULL;
        if (mid->dato.index == value)
            return mid;
        else if (mid->dato.index < value)
            start = mid->sig;
        else
            last = mid;
    }while(last == NULL || last != start);
    return(NULL);
}

void busquedaMatriz(MATRIZ *matriz, int value)
{
    if(IsEmptyMatrix(*matriz) == 1)
    {
        printf("\t >> La matriz esta vacia. \n");
        return;
    }
    else
    {
        int cnt = 1;
        LISTA *renglon = matriz->principio;
        while(renglon != NULL)
        {
            if(busqueda_binaria(renglon, value))
                printf("\t >> El valor %d se encuentra en el renglon %d. \n", value, cnt);
            else
                printf("\t >> El valor %d no se encuentra en el renglon %d. \n", value, cnt);
            renglon = renglon->sigRenglon;
            cnt++;
        }
    }
}

void MaxAndMin(MATRIZ *matriz)
{
    int menor = obtenerElementoMatriz(matriz, 1, 1);
    int mayor = obtenerElementoMatriz(matriz, 1, 1);
    if(IsEmptyMatrix(*matriz) == 1)
    {
        printf("\t >> La matriz esta vacia. \n");
        return;
    }
    else
    {
        for(int i = 1; i <= matriz->x; i++)
        {
            for(int j = 1; j <= matriz->y; j++)
            {
                int elementoActual = obtenerElementoMatriz(matriz, i, j);
                if(elementoActual > mayor)
                    mayor = obtenerElementoMatriz(matriz, i, j);
                if(elementoActual < menor)
                    menor = obtenerElementoMatriz(matriz, i, j);
            }
        }
        printf("\t Mayor: %d\n", mayor);
        printf("\t Menor: %d\n", menor);
    }
}

void limpiarMatriz(MATRIZ* matriz)
{
    if(IsEmptyMatrix(*matriz) == 1)
    {
        printf("\t >> La matriz esta vacia. \n");
        return;
    }
    else
    {
        LISTA *renglon = matriz->principio;
        while(renglon != NULL)
        {
            free(renglon);
            renglon = renglon->sigRenglon;
        }
        nuevaMatriz(matriz);
    }
}

void limpiarLista(LISTA* lista)
{
    if(IsEmptyList(*lista) == 1)
    {
        printf("\t >> La lista esta vacia. \n");
        return;
    }
    else
    {
        NODO *aux = lista->cabeza;
        while(aux != NULL)
        {
            free(aux);
            aux = aux->sig;
        }
        nuevaLista(lista);
    }
}


void menu()
{
    MATRIZ *A, *B, *AxB;
    A = (MATRIZ*)malloc(sizeof(MATRIZ));
    B = (MATRIZ*)malloc(sizeof(MATRIZ));
    AxB = (MATRIZ*)malloc(sizeof(MATRIZ));
    nuevaMatriz(A);
    nuevaMatriz(B);
    nuevaMatriz(AxB);
    LISTA *lista = (LISTA*)malloc(sizeof(LISTA));
    nuevaLista(lista);
    int opcion, value, n;
    do
    {
        system("cls");
        printf("\t << Matriz dinamica >>\n");
        printf("\t 1. Definir los valores de las matrices A y B.\n");
        printf("\t 2. Producto de las matricial (AxB).\n");
        printf("\t 3. Suma de diagonales de la matriz A.\n");
        printf("\t 4. Visualizar las matrices A y B.\n");
        printf("\t 5. Ordenar la matriz B.\n");
        printf("\t 6. Buscar un elemento en la matriz B.\n");
        printf("\t 7. Elementos de mayor y menor valor de las matrices A y B.\n");
        printf("\t 8. Vaciar matrices.\n");
        printf("\t 9. Salir.\n");
        printf("\n");
        printf("\t Digite una opcion: ");
        scanf("%d", &opcion);
        switch(opcion)
        {
            case(1):
                do{
                    system("cls");
                    printf("\t 1. Definir los valores de las matrices A y B.\n");
                    printf("\t ---------------------------------------------\n");
                    if(IsEmptyMatrix(*A) == 1 && IsEmptyMatrix(*B) == 1)
                    {
                        printf("\t >> Defina los valores de las matriz A: \n");
                        definirMatriz(A);
                        imprimirMatriz(*A);
                        printf("\t >> Defina los valores de las matriz B: \n");
                        definirMatriz(B);
                        imprimirMatriz(*B);
                    }
                    else
                    {
                        imprimirMatriz(*A);
                        printf("\n");
                        imprimirMatriz(*B);
                        printf("\t >> Las matrices ya han sido definidas. \n");
                    }
                    printf("\n");
                    printf("\t >> Digite 1 para volver al menu: ");
                    scanf("%d", &n);
                }while(n != 1);
                break;
            case(2):
                do{
                    system("cls");
                    printf("\t 2. Producto de las matricial (AxB).\n");
                    printf("\t -----------------------------------\n");
                    if(IsEmptyMatrix(*AxB) == 1)
                    {
                        productoMatricial(A, B, AxB);
                        printf("\t >> El producto de AxB se define como: \n");
                        imprimirMatriz(*AxB);
                    }
                    else
                    {
                        printf("\t >> El producto matricial ya ha sido definido. \n");
                        imprimirMatriz(*AxB);
                    }
                    printf("\n");
                    printf("\t >> Digite 1 para volver al menu: ");
                    scanf("%d", &n);
                }while(n != 1);
                break;
            case(3):
                do{
                    system("cls");
                    printf("\t 3. Suma de diagonales de la matriz A.\n");
                    printf("\t -------------------------------------\n");
                    if(IsEmptyList(*lista) == 1)
                    {
                        printf("\t >> Matriz A: \n");
                        imprimirMatriz(*A);
                        sumaDiagonales(A, lista);
                        printf("\n\n");
                        ImprimirLista(lista);
                    }
                    else
                    {
                        imprimirMatriz(*A);
                        printf("\n\n");
                        ImprimirLista(lista);
                    }
                    printf("\n");
                    printf("\t >> Digite 1 para volver al menu: ");
                    scanf("%d", &n);
                }while(n != 1);
                break;
            case(4):
                do{
                    system("cls");
                    printf("\t 4. Visualizar las matrices A y B.\n");
                    printf("\t ---------------------------------\n");
                    printf("\t >> Matriz A");
                    imprimirMatriz(*A);
                    printf("\n\n");
                    printf("\t >> Matriz B");
                    imprimirMatriz(*B);
                    printf("\n");
                    printf("\t >> Digite 1 para volver al menu: ");
                    scanf("%d", &n);
                }while(n != 1);
                break;
            case(5):
                do{
                    system("cls");
                    printf("\t 5. Ordenar la matriz B.\n");
                    printf("\t -----------------------\n");
                    printf("\t >> Matriz original: \n");
                    imprimirMatriz(*B);
                    ordenarMatriz(B);
                    printf("\t >> La matriz ha sido ordenada: \n");
                    imprimirMatriz(*B);
                    printf("\n");
                    printf("\t >> Digite 1 para volver al menu: ");
                    scanf("%d", &n);
                }while(n != 1);
                break;
            case(6):
                do{
                    system("cls");
                    printf("\t 6. Buscar un elemento en la matriz B.\n");
                    printf("\t -------------------------------------\n");
                    printf("\n\n");
                    printf("\t >> Introduzca el valor a buscar en la matriz B: ");
                    scanf("%d", &value);
                    busquedaMatriz(B, value);
                    printf("\n");
                    printf("\t >> Digite 1 para volver al menu: ");
                    scanf("%d", &n);
                }while(n != 1);
                break;
            case(7):
                do{
                    system("cls");
                    printf("\t 7. Elementos de mayor y menor valor de las matrices A y B.\n");
                    printf("\t ----------------------------------------------------------\n");
                    printf("\t >> Matriz A: \n");
                    MaxAndMin(A);
                    printf("\t >> Matriz B: \n");
                    MaxAndMin(B);
                    printf("\n");
                    printf("\t >> Digite 1 para volver al menu: ");
                    scanf("%d", &n);
                }while(n != 1);
                break;
            case(8):
                do{
                    system("cls");
                    printf("\t 8. Vaciar matrices.\n");
                    printf("\t -------------------\n");
                    if(IsEmptyMatrix(*A) == 1 && IsEmptyMatrix(*B) == 1)
                        printf("\t >> Las matrices estan vacias \n");
                    else
                    {
                        limpiarMatriz(A);
                        limpiarMatriz(B);
                        limpiarMatriz(AxB);
                        limpiarLista(lista);
                        printf("\t >> Se han liberado correctamente las matrices. \n");
                    }
                    printf("\n");
                    printf("\t >> Digite 1 para volver al menu: ");
                    scanf("%d", &n);
                }while(n != 1);
                break;
            default:
                break;
        }
    }while(opcion < 9);
    free(A);
    free(B);
    free(AxB);
    free(lista);
}
