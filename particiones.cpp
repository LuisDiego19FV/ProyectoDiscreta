#include <opencv2/core/core.hpp>
#include <iostream>
#include <stdlib.h>

using namespace cv;
using namespace std;

int firstPartition (int, int, int*);
bool nextPartition (int, int*);

int main(){

  int num;
	int lenght;
  bool stop = false;

  cout << "Ingrese numero para particionar" << endl;
  cin >> num;
  cout << "Ingrese la longitud de las particiones" << endl;
  cin >> lenght;

  cout << endl << "Particiones" << endl;

  int partitions[lenght];
  int *d_partitions = &partitions[0];

  firstPartition(num, lenght, d_partitions);

  while (!stop) {

    for (int i = 0; i < lenght; i++) {
      cout << partitions[i] << " ";
    }

    cout << endl;

    stop = nextPartition(lenght, d_partitions);

  }

  return 0;
}

int firstPartition (int n, int k, int *d_partition) {

  *d_partition = n-k+1;

  for (int i = 1; i < k; i++){

    *(d_partition + i) = 1;

  }

  return 0;

}

bool nextPartition (int k, int *d_partition) {

  for (int i = (k - 1); i >0; i--) {

    if ((*(d_partition + i - 1) - *(d_partition + i)) >= 2) {

      //cout << (*(d_partition + i - 1) - *(d_partition + i))  << endl;

      *(d_partition + i - 1) -= 1;
      *(d_partition + i) += 1;

      return false;

    }

  }

  for (int i = 2; i < k; i++) {

    if (*d_partition - *(d_partition + i) == 2) {

      *d_partition -= 1;
      *(d_partition + i) += 1;

      return false;

    }

  }

  return true;

}
