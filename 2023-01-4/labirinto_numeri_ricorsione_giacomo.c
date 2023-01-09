
#include <stdio.h>
#include <stdlib.h>
#define N 4


int percorso (int matrice[][N], int n, int m){


  //se siamo arrivati all'ultimo elemento
  if (n == N - 1 && m == N - 1)
    {
      return 1;
    }
  else
    {
      if (m + 1 < N
	  && (matrice[n][m] == matrice[n][m + 1] + 1
	      || matrice[n][m] == matrice[n][m + 1] - 1))
	{
	  printf ("Destra\n");
	  return percorso (matrice, n, m + 1);

	}
      else if (n + 1 < N
	       && (matrice[n][m] == matrice[n + 1][m] + 1
		   || matrice[n][m] == matrice[n + 1][m] - 1))
	{
	  printf ("Basso\n");
	  return percorso (matrice, n + 1, m);
	}
      else if (m - 1 > 0
	       && (matrice[n][m] == matrice[n][m - 1] + 1
		   || matrice[n][m] == matrice[n][m - 1] - 1))
	{
	  printf ("Sinistra\n");
	  return percorso (matrice, n, m - 1);
	}
      if (n - 1 > 0
	  && (matrice[n][m] == matrice[n - 1][m] + 1
	      || matrice[n][m] == matrice[n - 1][m] - 1))
	{
	  printf ("Alto\n");
	  return percorso (matrice, n - 1, m);
	}
    }

  return -1;
}


int vicolo (int matrice[][N], int n, int m, int **buffer){
    if (n == N - 1 && m == N - 1){
      printf("FINE\n");
      return 1;
    }
    
    
  if (*(*(buffer + n) + m) == 1){
      printf ("Sei già  stato su questa casella\n");
      *(*(buffer + n) + m) = 0;
      return -1;
    }
  else{
      *(*(buffer + n) + m) = 1;
}



  
      if (m + 1 < N && (matrice[n][m] == matrice[n][m + 1] + 1 || matrice[n][m] == matrice[n][m + 1] - 1)){
	  printf ("Destra\n");
	  if (vicolo (matrice, n, m + 1, buffer) == -1){
	      printf("Torno indietro\n");
	      return vicolo (matrice, n, m, buffer);
	      
	    }
	  else{
	      return vicolo (matrice, n, m + 1, buffer);
	    }

	}
      else if (n + 1 < N && (matrice[n][m] == matrice[n + 1][m] + 1 || matrice[n][m] == matrice[n + 1][m] - 1)){
	  printf ("Basso\n");
	  if (vicolo (matrice, n+1, m, buffer) == -1){
	      printf("Torno indietro\n");
	      return vicolo (matrice, n, m, buffer);
	    }
	  else{
	      return vicolo(matrice, n + 1, m, buffer);
	    }
	}
      else if (m - 1 > 0 && (matrice[n][m] == matrice[n][m - 1] + 1 || matrice[n][m] == matrice[n][m - 1] - 1)){
	  printf ("Sinistra\n");
	  if (vicolo (matrice, n, m-1, buffer) == -1){
	      printf("Torno indietro\n");
	      return vicolo (matrice, n, m, buffer);
	    }
	  else{
	      return vicolo (matrice, n, m - 1, buffer);
	    }
	}
      if (n - 1 > 0 && (matrice[n][m] == matrice[n - 1][m] + 1 || matrice[n][m] == matrice[n - 1][m] - 1)){
	  printf ("Alto\n");
	  if (vicolo (matrice, n-1, m, buffer) == -1){
	      printf("Torno indietro\n");
	      return vicolo (matrice, n, m, buffer);
	    }
	  else{
	      return vicolo (matrice, n - 1, m, buffer);
	    }
	}
    

  return -1;
}

int main (){
  int mat[N][N];
  int v_mat[N][N];
  int i;
  int j;
  int **buffer;

  buffer = malloc (sizeof (int *) * N);
  for (i = 0; i < N; i++){
      *(buffer + i) = malloc (sizeof (int) * N);
    }
  for (i = 0; i < N; i++){
      for (j = 0; j < N; j++){
	  *(*(buffer + i) + j) = 0;
	}
    }


  mat[0][0] = 0;
  mat[0][1] = 1;
  mat[0][2] = 2;
  mat[0][3] = 5;
  mat[1][0] = 3;
  mat[1][1] = 5;
  mat[1][2] = 3;
  mat[1][3] = 5;
  mat[2][0] = 5;
  mat[2][1] = 5;
  mat[2][2] = 2;
  mat[2][3] = 1;
  mat[3][0] = 5;
  mat[3][1] = 5;
  mat[3][2] = 5;
  mat[3][3] = 0;

  v_mat[0][0] = 0;
  v_mat[0][1] = 1;
  v_mat[0][2] = 2;
  v_mat[0][3] = 5;
  v_mat[1][0] = 1;
  v_mat[1][1] = 5;
  v_mat[1][2] = 3;
  v_mat[1][3] = 5;
  v_mat[2][0] = 2;
  v_mat[2][1] = 5;
  v_mat[2][2] = 2;
  v_mat[2][3] = 1;
  v_mat[3][0] = 5;
  v_mat[3][1] = 5;
  v_mat[3][2] = 5;
  v_mat[3][3] = 0;

  printf ("%d", vicolo(v_mat, 0, 0, buffer));


}
