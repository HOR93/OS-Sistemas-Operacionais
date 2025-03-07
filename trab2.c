#include <stdio.h>
#include <time.h>
#include <pthread.h>


typedef struct args{
  int lA;
  int CA;
  int LB;
  int CB;
  int MA[100][100];
  int MB[100][100];
  int Rst[100][100];

} args;


void* f_thread(void *v) {

  args *dados = (args*) v;

  for (int i =0; i< dados->lA; ++i){
    for (int m=0; m< dados->CB; ++m){
      dados->Rst[i][m] = 0;
      for (int n=0; n< dados->CA; ++n){
      dados->Rst[i][m] += dados->MA[i][n] * dados->MB[n][m];
      }
    }
  }

  //printf("retorno da função, deu certo");
  return NULL;
}


  int main() {

  pthread_t thr1, thr2;
  args args_mult;
  int aleatorio;
  clock_t t,f;


  srand(time(NULL));

  aleatorio = rand() % 15;


  scanf("%d %d", &args_mult.lA, &args_mult.CA);
  scanf("%d %d", &args_mult.LB, &args_mult.CB);


  for (int i = 0; i < args_mult.lA; i++) {
    for (int j = 0; j <args_mult.CA; j++) {
        args_mult.MA[i][j] = aleatorio++;
    }
  }

  for (int m = 0; m < args_mult.LB; m++) {
    for (int n = 0; n < args_mult.CB; n++) {
         args_mult.MB[m][n] = aleatorio++;
      }
  }

  printf("matriz A\n");
  for (int i = 0; i < args_mult.lA; i++) {
      for (int j = 0; j < args_mult.CA; j++) {
          printf("%2d ", args_mult.MA[i][j]);
       }
          printf("\n");
  }

  printf("matriz B\n");
  for (int m = 0; m < args_mult.LB; m++) {
        for (int n = 0; n < args_mult.CB; n++) {
            printf("%2d ", args_mult.MB[m][n]);
        }
            printf("\n");
  }


  pthread_create(&thr1, NULL, f_thread, (void*) &args_mult);
  pthread_create(&thr2, NULL, f_thread, (void*) &args_mult);
  t=clock();
  pthread_join(thr1, NULL);
  t=clock()-t;
  double time = ((double)t)/CLOCKS_PER_SEC;

  f=clock();
  pthread_join(thr2, NULL);
  f=clock()-f;
  double time2 = ((double)f)/CLOCKS_PER_SEC;


  printf("Multiplicacao Resultado C = A * B\n");
  for(int i=0; i< args_mult.lA; ++i){
       for (int j = 0; j <args_mult. CB; ++j){
            printf("%2d", args_mult.Rst[i][j]);
       }
      printf("\n");
  }

  printf("thr1 demorou: %f segundos\n", time);
  printf("thr2 demorou: %f segundos", time2);


   return 0;
}
