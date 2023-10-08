/**
 *  @file matrix.h
 */
/** @struct DATO
*   @brief  Esta estructura contiene los campos correspondientes a la informacion almacenada en la matriz.
*   @var DATO::char array
*   @var DATO::int index
*/
typedef struct{
    char array;
    int index;
}DATO;
/** @struct NODO
*   @brief  Esta estructura contiene los campos correspondientes para definir cada nodo.
*   @var NODO::int i
*   @var NODO::int j
*   @var NODO::DATO dato
*   @var NODO::struct node *sig
*   @var NODO::struct node *ant
*/
typedef struct node{
    int i;
    int j;
    DATO dato;
    struct node *sig;
    struct node *ant;
}NODO;
/** @struct LISTA
*   @brief  Esta estructura contiene los campos correspondientes para definir los renglones de la matriz.
*   @var LISTA::NODO *cabeza
*   @var LISTA::NODO *cola
*   @var LISTA::struct list *sigRenglon
*   @var LISTA::int dim
*/
typedef struct list{
    NODO *cabeza;
    NODO *cola;
    struct list *sigRenglon;
    int dim;
}LISTA;
/** @struct MATRIZ
*   @brief  Esta estructura contiene los campos correspondientes para definir una matriz.
*   @var MATRIZ::LISTA *principio
*   @var MATRIZ::LISTA *final
*   @var MATRIZ::int x
*   @var MATRIZ::int y
*/
typedef struct{
    LISTA *principio;
    LISTA *final;
    int x;
    int y;
}MATRIZ;
/** @fn void nuevaMatriz(MATRIZ *matriz)
 *  @brief Inicializa la matriz.
 *  @param *matriz Recibe la matriz actual.
 */
void nuevaMatriz(MATRIZ *matriz);
/** @fn void nuevaLista(LISTA *lista)
 *  @brief Inicializa la lista que corresponde a los renglones de la matriz.
 *  @param *lista Recibe la lista actual.
 */
void nuevaLista(LISTA *lista);
/** @fn void nuevoNodo(NODO *nodo)
 *  @brief Inicializa los nodos de la matriz.
 *  @param *nodo Recibe el nodo actual a introducir.
 */
void nuevoNodo(NODO *nodo);
/** @fn void MatrizIn(MATRIZ *matriz, LISTA *lista)
 *  @brief Introduce los renglones de la matriz actual.
 *  @param *matriz Recibe la matriz actual.
 *  @param *lista Recibe la lista para anadir un renglon a la matriz.
 */
void MatrizIn(MATRIZ *matriz, LISTA *lista);
/** @fn void anadir(LISTA *lista, char cadena, int indice, int i0, int j0)
 *  @brief Introduce los nodos de la matriz actual.
 *  @param *lista Recibe la lista para anadir un renglon a la matriz.
 *  @param cadena Caracter a introducir dentro de la matriz.
 *  @param indice Entero a introducir dentro de la matriz.
 *  @param i0 Indice que identifica el renglon en el que se encuentra el elemento.
 *  @param j0 Indice que identifica la columna en la que se encuentra el elemento.
 */
void anadir(LISTA *lista, char cadena, int indice, int i0, int j0);
/** @fn void imprimirMatriz(MATRIZ matriz)
 *  @brief Se imprime la matriz actual.
 *  @param matriz Recibe la matriz actual.
 */
void imprimirMatriz(MATRIZ matriz);
/** @fn void imprimirLista(LISTA *lista)
 *  @brief Se imprime la lista actual.
 *  @param *lista Recibe la lista actual.
 */
void imprimirLista(LISTA *lista);
/** @fn void remover(LISTA *lista, int indice)
 *  @brief Se suprime un elemento de la lista.
 *  @param *lista Recibe la lista actual.
 *  @param indice Recibe el elemento a eliminar de la lista.
 */
void remover(LISTA *lista, int indice);
/** @fn void removerColaLista(LISTA *lista)
 *  @brief Se suprime el utlimo elemento de la lista.
 *  @param *lista Recibe la lista actual.
 */
void removerColaLista(LISTA *lista);
/** @fn void buscar(LISTA *lista, int indice)
 *  @brief Busqueda de un elemento de la lista.
 *  @param *lista Recibe la lista actual.
 *  @param indice Recibe el elemento a buscar en la lista.
 */
void buscar(LISTA *lista, int indice);
/** @fn void definirMatriz(MATRIZ *M)
 *  @brief Define las dimensiones y los elementos de la matriz.
 *  @param *M Recibe la matriz actual.
 */
void definirMatriz(MATRIZ *M);
/** @fn void productoMatricial(MATRIZ *A, MATRIZ *B, MATRIZ *AxB)
 *  @brief Realiza el producto matricial.
 *  @param *A Recibe la matriz A.
 *  @param *B Recibe la matriz B.
 *  @param *AxB Recibe la matriz en donde se guardara el resultado de realizar el producto de A con B.
 */
void productoMatricial(MATRIZ *A, MATRIZ *B, MATRIZ *AxB);
/** @fn void sumaDiagonales(MATRIZ *A, LISTA *listaAux)
 *  @brief Realiza la suma de las diagonales de la matriz recorriendo desde la esquina superior derecha hasta la esquina inferior izquierda e inserta los resultados en una lista.
 *  @param *A Recibe la matriz A.
 *  @param *listaAux Recibe la lista que almacenara la suma de las diagonales.
 */
void sumaDiagonales(MATRIZ *A, LISTA *listaAux);
/** @fn void busquedaMatriz(MATRIZ *matriz, int value)
 *  @brief Define las dimensiones y los elementos de la matriz.
 *  @param *matriz Recibe la matriz actual.
 *  @param value Recibe el valor a buscar en la matriz actual.
 */
void busquedaMatriz(MATRIZ *matriz, int value);
/** @fn void MaxAndMin(MATRIZ *matriz);
 *  @brief Muestra el valor maximo y minimo que se encuentran en la matriz.
 *  @param *matriz Recibe la matriz actual.
 */
void MaxAndMin(MATRIZ *matriz);
/** @fn void quicksort(NODO *first, NODO *last)
 *  @brief Implementacion del algortimo quicksort para ordenar los elementos de la matriz.
 *  @param *first Recibe el inicio de la lista a ordenar.
 *  @param *last Recibe el final de la lista a ordenar.
 */
void quicksort(NODO *first, NODO *last);
/** @fn void ordenarMatriz(MATRIZ *matriz)
 *  @brief Se ordenan los renglones de la matriz en orden ascendente.
 *  @param *matriz Recibe la matriz a ordenar.
 */
void ordenarMatriz(MATRIZ *matriz);
/** @fn void limpiarMatriz(MATRIZ *matriz)
 *  @brief Se inicializa la matriz de tal forma que puede recibir nuevos elementos.
 *  @param *matriz Recibe la matriz a vaciar.
 */
void limpiarMatriz(MATRIZ *matriz);
/** @fn void menu()
 *  @brief Menu para manipular la matriz.
 */
void menu();
void limpiarLista(LISTA *lista);
/** @fn int IsEmptyList(LISTA lista)
 *  @brief Verifica si la lista esta vacia o no.
 *  @param lista Recibe la lista actual.
 *  @return 1 si la lista contiene elementos, 0 si la lista no contiene elementos.
 */
int IsEmptyList(LISTA lista);
/** @fn int IsEmptyMatrix(MATRIZ matriz)
 *  @brief Verifica si la matriz esta vacia o no.
 *  @param matriz Recibe la matriz actual.
 *  @return 1 si la matriz contiene elementos, 0 si la lista no contiene elementos.
 */
int IsEmptyMatrix(MATRIZ matriz);
/** @fn int size(LISTA *lista)
 *  @brief Devuelve la dimension la lista.
 *  @param *lista Recibe la lista actual.
 *  @return Retorna la longitud de la lista como un valor de tipo entero.
 */
int size(LISTA *lista);
/** @fn int max2number(int num1, int num2)
 *  @brief Compara el valor de dos numeros y devuelve el mayor de ellos.
 *  @param num1 Recibe un numero entero a comparar.
 *  @param num2 Recibe un numero entero a comparar.
 *  @return Retorna el numero mas grande despues de hacer la comparacion.
 */
int max2number(int num1, int num2);
/** @fn int min2number(int num1, int num2)
 *  @brief Compara el valor de dos numeros y devuelve el menor de ellos.
 *  @param num1 Recibe un numero entero a comparar.
 *  @param num2 Recibe un numero entero a comparar.
 *  @return Retorna el numero mas pequeño despues de hacer la comparacion.
 */
int min2number(int num1, int num2);
/** @fn int obtenerElementoMatriz(MATRIZ *A, int renglon, int columna)
 *  @brief Se obtiene cualquier elemento de la matriz a traves de sus indices.
 *  @param *A Recibe la matriz actual en donde se requiere buscar el elemento.
 *  @param i Recibe el numero de renglon.
 *  @param j Recibe el numero de columna.
 *  @return Retorna el elemento que se requiere.
 */
int obtenerElementoMatriz(MATRIZ *A, int renglon, int columna);
/** @fn NODO *obtenerColaLista(LISTA *lista)
 *  @brief Obtiene la cola de la lista (ultimo elemento de la lista).
 *  @param *lista Recibe la lista actual.
 *  @return Retorna el ultimo nodo de la lista actual.
 */
NODO *obtenerColaLista(LISTA *lista);
/** @fn NODO *particion(NODO *first, NODO *last)
 *  @brief Intercambia los valores de dos nodos y retorna el nodo que se encuentra en medio de las dos partes de la lista.
 *  @param *first Recibe el inicio de la lista.
 *  @param *last Recibe el final de la lista.
 *  @return Retorna el nodo que se encuentra en medio de la lista actual.
 */
NODO *particion(NODO *first, NODO *last);
/** @fn NODO *centro(NODO *primero, NODO *ultimo)
 *  @brief Encuentra el elemento central de la lista
 *  @param *primero Recibe el inicio de la lista.
 *  @param *ultimo Recibe el final de la lista.
 *  @return Retorna el nodo que se encuentra en medio de la lista actual.
 */
NODO *centro(NODO *primero, NODO *ultimo);
/** @fn NODO *busqueda_binaria(LISTA *lista, int value)
 *  @brief Implementacion del algortimo de la busqueda binaria iterativa para una lista.
 *  @param *lista Recibe la lista actual.
 *  @param value Recibe el valor a buscar en la lista.
 *  @return Si se encuentra, retorna el nodo con el valor requerido, si no, retorna un valor NULL.
 */
NODO *busqueda_binaria(LISTA *lista, int value);
