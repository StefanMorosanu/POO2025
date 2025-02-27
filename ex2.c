#include <stdio.h>    
#include <string.h>
int main(){
FILE *file = fopen("pr.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
   
    char sir[100],*cuv;
    char vec[100][100];
    fgets(sir, sizeof(sir), file);
    cuv= strtok(sir, " ");
    int size=0;
    while (cuv != NULL){
        strcpy (vec[size], cuv);
        size++;
        cuv = strtok(NULL, " ");
    }
    for (int poz1=0;poz1<size; poz1++){
        for(int poz2=poz1+1;poz2<=size;poz2++){
            if (strlen(vec[poz1])<strlen(vec[poz2])){
                char aux[100];
                strcpy(aux, vec[poz1]);
                strcpy(vec[poz1], vec[poz2]);
                strcpy(vec[poz2], aux);
            }
        }
    }
    for (int i=0;i<size;i++){
        printf("%s\n", vec[i]);
    }
}