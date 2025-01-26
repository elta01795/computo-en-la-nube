/* Directivas para incluir las librerías */
#include <iostream>
#include <omp.h>

/* Declaración de variables */
#define N 1000
#define chunk 100
#define mostrar 10

/* Se invoca función imprimeArreglo, se creara en lineas posteriores*/
void imprimeArreglo(float *d);

int main() {
    std::cout << "Sumando Arreglos en Paralelo!\n";
    /* Se crean tres arreglos: a, b y c del tamaño N (1000)*/
    float a[N], b[N], c[N];
    /* se crea variable i de tipo int que servirá para iterar N* en el bucle for*/
	int i;

    /*Se crea loop for, se hace uso de la variable i para iniciar la iteración con valor 0 hasta 999 y se va incrementando en 1*/
	for(i = 0; i < N; i++)
	{
		/*Se accede a la posición i en el arreglo a y se asigna el valor de 1*10*/
        a[i] = i * 10;
        /*Se accede a la posición i en el arreglo b y se asigna el valor de (i + 3) * 3.7*/
		b[i] = (i + 3) * 3.7;

	}
    /*se igual declara la variable pedazos y se asigna el valor de chunk, en esta caso 100*/
    /*pedazos= 100*/
	int pedazos = chunk;

    /*Se hace uso de las directivas de omp para indicar que el siguiente bloque de código*/
    /*ejecutarán varios subprocesos en paralelo.*/
    #pragma omp parallel for shared(a, b, c, pedazos) private(i) schedule(static, pedazos)
    
    for(i = 0; i < N; i++)
        c[i] = a [i] + b[i];

    /*Se imprime en pantalla los valores que contienen los arreglos a,b y c*/
    /*hasta la posición 10 que es el valor de la variable mostrar*/
	std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo a: " << std::endl; imprimeArreglo(a);
	std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo b: "<< std::endl; imprimeArreglo(b);
	std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo c: "<< std::endl; imprimeArreglo(c);	
}

/*Se declara y crea la función imprimeArreglo*/
void imprimeArreglo(float *d)
{
    /*se itera el arreglo d de 0 a 9 y se presenta su valor en pantalla */
    for(int x = 0; x < mostrar; x++)
    std::cout << d[x] << " - ";
    std::cout << std::endl;
}