#include <iostream>
#include <stdlib.h>

using namespace std;

int firstPartition (int, int, int*);
bool nextPartition (int, int*);

//Programa Principal
int main(){

  int num; //Numero deseado
  int lenght; //Tamanio de las particiones
  bool stop = false;

  //Se piden los datos
  while(true){
  	cout << "Ingrese numero para particionar:" << endl;
  	cin >> num;
  	cout << "Ingrese la longitud de las particiones:" << endl;
  	cin >> lenght;
  	if(num >= lenght){
  	  break;
  	}else{
  	  cout << "Error, la longitud de las particiones debe ser menor o igual al numero!\n" << endl;
  	}
  }

  cout << endl << "Particiones:" << endl;

  int partitions[lenght]; //Arreglo para gurdar los valores de las particiones
  int *d_partitions = &partitions[0]; //Puntero hacia el primer valor de la particion

  //Se calcula la primera particion
  firstPartition(num, lenght, d_partitions);

  while (!stop) {

  	//Se imprimen los valores de la ultima particion
    for (int i = 0; i < lenght; i++) {
      if(i==0){
      	cout << partitions[i];
      }else{
      	cout << "+" << partitions[i];
      }
    }

    cout << endl;

    //Se calcula la siguiente particion
    stop = nextPartition(lenght, d_partitions);

  }

  return 0;
}

//Funcion que calcula la primera particion
int firstPartition (int n, int k, int *d_partition) {

  //El primer valor de la primera particion siempres se define como
  //el numero deseado menos el largo de la particion mas uno.
  *d_partition = n-k+1;

  //La primera particion se define en todos los otros espacios
  //que no sean el primero como 1.
  for (int i = 1; i < k; i++){

    *(d_partition + i) = 1;

  }

  return 0;

}

//Funcion que calcula el resto de particiones que no sean la primera
bool nextPartition (int k, int *d_partition) {

  //Se recorren todos los espacios del arreglo, empezando por el ultimo hasta llegar al segundo
  for (int i = (k - 1); i >0; i--) {

  	//Si el valor anterior al actual en el ciclo menos el valor actual es mayor o igual a 2
  	//se le resta uno al valor anterior y se le suma uno al actual y se sale de la funcion
  	//devolviendo un false a la bandera para parar.
    if ((*(d_partition + i - 1) - *(d_partition + i)) >= 2) {

      //cout << (*(d_partition + i - 1) - *(d_partition + i))  << endl;

      *(d_partition + i - 1) -= 1;
      *(d_partition + i) += 1;

      return false;

    }

  }

  //Se recorre por ultima vez (en la llamada de la funcion) el arreglo (si es necesario)
  //para revisar que el primer valor no siga siendo mayor a los demas valores en el arreglo
  //en una magnitud de 2. Si lo es se le resta 1 y se suma 1 en el primer valor que el ciclo
  //encuentre de una magnitud de 2 menor.
  for (int i = 2; i < k; i++) {

    if (*d_partition - *(d_partition + i) == 2) {

      *d_partition -= 1;
      *(d_partition + i) += 1;

      return false;

    }

  }

  //Se asegura que el primer numero sea el mas grande. Esto por dos razones: la primera es
  //unicamente por estedica, y la segunda es que esto permite que el for de arriba se vuelva
  //a revisar permitiendo que se calculen todas las particiones.
  for (int i = 1; i < k; i++) {

    if (*d_partition > *(d_partition + i)) {

      //Almacena el valor de la primera casilla temporalmente.
      int valorTempCasilla1 = *d_partition;

      //Cambio de valores entre casillas;
      *d_partition = *(d_partition + 1);
      *(d_partition + 1) = valorTempCasilla1;

      return false;

    }

  }

  //Si se pasan los dos ciclos anteriores se termina el programa
  return true;

}
