#include <stdio.h>
#include <math.h>
#include<stdlib.h> 

void setup() 
{
  Serial.begin(9600);
}

void loop()
{   int* ca_final = (int *) malloc(sizeof(int));

    int array[8][3]={{0, 0, 0},
       {0, 0, 1},
       {0, 1, 0},
       {0, 1, 1},
       {1, 0, 0},
       {1, 0, 1},
       {1, 1, 0},
       {1, 1, 1}};
    int m=0;
    if (m==0){
      ca_final[0]=1;
      ca_final[3]=1;
      ca_final[5]=1;
    }


      delay(3000);
    m=m+1;
    int k=0;
    int n = 5;
    int split_array[6][3]; 
    ///={{1,1,0},{1,0,0},{0,0,1},{0,1,0},{1,0,1},{0,1,1}};
    /// comparar split_array com array e retornar o indice do resultado e busca no resultado
    /// size dividido por 4 bytes
    split_array[0][0]=ca_final[n];
    split_array[0][1]=ca_final[0];
    split_array[0][2]=ca_final[1];
    split_array[n][0]=ca_final[(int)(n-1)];
    split_array[n][1]=ca_final[n];
    split_array[n][2]=ca_final[0];
    for (k=1;k<n;k++){
        split_array[k][0]=ca_final[(int)(k-1)];
        split_array[k][1]=ca_final[k];
        split_array[k][2]=ca_final[(int)(k+1)];
    }
    int i=0;
    int ii=0;
    int posicao[8];
    int states=2;
    int multi[8];
    int regra=30;
    
    int outputs[8];
    int saida[8];

    
    int iter=0;
    int iter2=0;

    ///printf("Which CA rule ?");
    ///scanf("%d",&regra);
    for (i = 0; i <8; i++){
        posicao[i] = i;
        multi[i] = pow(states,i);
        outputs[i]=regra/multi[i];
        saida[i]=outputs[i]%2;
        ///printf("\n%d\n",saida[i]);
    for (ii = 0; ii <6; ii++){
        for (iter2=0;iter2<6;++iter2){
            if (split_array[ii][0]==array[iter2][0] && split_array[ii][1]==array[iter2][1] && split_array[ii][2]==array[iter2][2]){
                ca_final[ii]=saida[iter2];
    
    }
    }
    ///printf("\n%d%d%d%d%d%d%d%d\n",saida[0],saida[1],saida[2],saida[3],saida[4],saida[5],saida[6],saida[7]);
    }
    }
    ///printf("\n%d%d%d%d%d%d\n", ca_final[0], ca_final[1], ca_final[2], ca_final[3], ca_final[4], ca_final[5]);
    for (int p=0;p<6;p++) {
      Serial.print(ca_final[p],DEC);
      }
    Serial.println();


    ///return 0;
    
}
