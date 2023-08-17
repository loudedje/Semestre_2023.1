#include <stdio.h>
#include<stdlib.h>

void copia(int *A, int *v, int size);
void bubbleSort(int *A, int size);
void selectionSort(int *A, int size);
void insertionSort(int *A, int size);
void mergeSort(int *A, int size);
void quickSort(int *A, int size);
void heapSort(int *A, int size);
void countingSort(int *A, int size);
void radixSort(int *A, int size);


int main(){
    int i;
    int vetor[] = {1, 22, -10, 38, 5, 7};
    int tamanhoVetor = (int)sizeof(vetor)/sizeof(int);
    printf("\nVetor original: ");
    for (i = 0 ; i < tamanhoVetor ; i++)
    printf("%d ", vetor[i]);
    printf("\nVetor tamanho = %d\n", tamanhoVetor);

    // bubble sort
    int bubbleVec[tamanhoVetor];
    copia(vetor, bubbleVec, tamanhoVetor);
    bubbleSort(bubbleVec, tamanhoVetor);
    printf("\nBubble sort: ");
    for (i = 0 ; i < tamanhoVetor ; i++)
        printf("%d ",bubbleVec[i]);
    printf("\n");
    
    //selection Sort
    int selecVec[tamanhoVetor];
    copia(vetor, selecVec, tamanhoVetor);
    selectionSort(selecVec, tamanhoVetor);
    printf("\nselection Sort: ");
    for (i = 0 ; i < tamanhoVetor ; i++)
    printf("%d ",selecVec[i]);
    printf("\n");

     //insertion sort
    int InserVec[tamanhoVetor];
    copia(vetor, selecVec, tamanhoVetor);
    insertionSort(selecVec, tamanhoVetor);
    printf("\nInsertion Sort: ");
    for (i = 0 ; i < tamanhoVetor ; i++)
    printf("%d ",selecVec[i]);
    printf("\n");

    // merge sort
    int mergec[tamanhoVetor];
    copia(vetor, mergec, tamanhoVetor);
    mergeSort(mergec, tamanhoVetor);
    printf("\nMerge Sort: ");
    for (i = 0; i < tamanhoVetor; i++) {
    printf("%d ", mergec[i]);
    }
    printf("\n");
    
    //quick sort
       int quickVec[tamanhoVetor];
        copia(vetor, quickVec, tamanhoVetor);
        quickSort(quickVec, tamanhoVetor);
        printf("\nQuick Sort: ");
    for (i = 0; i < tamanhoVetor; i++) {
        printf("%d ", quickVec[i]);
    }
    printf("\n");


    // heap sort
    int heapVec[tamanhoVetor];
            copia(vetor, heapVec, tamanhoVetor);
            heapSort(heapVec, tamanhoVetor);
            printf("\nHeap Sort: ");
        for (i = 0; i < tamanhoVetor; i++) {
            printf("%d ", heapVec[i]);
        }
        printf("\n");


    // counting sort
        int counVec[tamanhoVetor];
            copia(vetor, counVec, tamanhoVetor);
            countingSort(counVec, tamanhoVetor);
            printf("\nCounting Sort: ");
        for (i = 0; i < tamanhoVetor; i++) {
            printf("%d ", counVec[i]);
        }
        printf("\n");


    // radix sort
    int radixVec[tamanhoVetor];
            copia(vetor, radixVec, tamanhoVetor);
            radixSort(radixVec, tamanhoVetor);
            printf("\nRadix Sort: ");
        for (i = 0; i < tamanhoVetor; i++) {
            printf("%d ", radixVec[i]);
        }
        printf("\n");


    return 0;
}

void copia(int *A, int *V, int size){
    int i;
    for (i = 0 ; i < size ; i++)
        V[i] = A[i];
}
    
void bubbleSort(int *A, int size){
    int i,j,aux;
    for(i= size-1; i>=1; i--){
        int flag =0;
        for(j=0; j<i; j++){
            if (A[j]>A[j+1]){
                aux = A[j];
                A[j] = A[j+1];
                A[j+1] = aux;
                flag=1;
            }
        }
        if (flag==0){
            break;
        }
    }
}

void selectionSort(int *A, int size){
    for(int i=0; i<size-1; i++){
    int menor =i;
    for(int j=i+1; j<size; j++){
        if(A[menor]>A[j]){
            menor=j;
        }
    }
        int  aux = A[i];
        A[i]=A[menor];
        A[menor]=aux;
    }
}

void insertionSort(int *A, int size){
    int i,j,position;
   for(i=1; i<=size-1;i++)
   {
    position=A[i];
    for(j=i; j>=1 && position< A[j-1]; j--){
        A[j]= A[j-1];
    }
    A[j]=position;

   } 
}

//mergeSort
int intercala(int *A, int inicio, int meio, int fim) {
    int *aux;
    int i, j, k;
    aux = malloc((fim - inicio + 1) * sizeof(int));
    i = inicio;
    j = meio + 1;
    k = 0;
    while (i <= meio && j <= fim) {
        if (A[i] <= A[j]) {
            aux[k] = A[i];
            i++;
        } else {
            aux[k] = A[j];
            j++;
        }
        k++;
    }
    while (i <= meio) {
        aux[k] = A[i];
        k++;
        i++;
    }
    while (j <= fim) {
        aux[k] = A[j];
        k++;
        j++;
    }
    for (k = inicio; k <= fim; k++) {
        A[k] = aux[k - inicio];
    }
    free(aux);
    return 0;
}

void mergerS(int *A, int inicio, int fim) {
    int meio;
    if (inicio >= fim) {
        return;
    }
    meio = (inicio + fim) / 2;
    mergerS(A, inicio, meio);
    mergerS(A, meio + 1, fim);
    intercala(A, inicio, meio, fim);
}

void mergeSort(int *A, int size) {
    mergerS(A, 0, size - 1);
}

//quickSort
int particiona(int *A, int inicio, int fim);//Assinatura da Função particiona do mergeSort

void quickS(int *A, int inicio, int fim){
    if (inicio < fim){
        int pivo = particiona(A, inicio, fim);
        quickS(A, inicio, pivo - 1);
        quickS(A, pivo + 1, fim);
        
    }
}

void quickSort(int *A, int size){
    quickS(A, 0, size-1);
}
int particiona(int *A, int inicio, int fim){
    int posPivo = fim;
    int k = inicio, troque;
    for (int i = inicio; i < fim; i++){
        if (A[i] < A[posPivo]){
            troque = A[i];
            A[i] = A[k];
            A[k] = troque;
            k++;
        }
    }
    troque = A[posPivo];
    A[posPivo] = A[k];
    A[k] = troque;
    return k;
}


//heap sort
void criarHeap(int *A, int i, int n);

void heapSort(int *A, int size){
    int k, aux;
    for(k = size / 2 - 1; k >= 0; k--){
        criarHeap(A, k, size);
    }
    for(k = size - 1; k > 0; k--){
        aux = A[0];
        A[0] = A[k];
        A[k] = aux;
        criarHeap(A, 0, k);
    }
}

void criarHeap(int *A, int i, int n){
    int maior, troque, left, right;
    maior = i;
    left = 2 * i + 1;
    right = 2 * i + 2;
    if(left < n && A[left] > A[i]){
        maior = left;
    }
    if(right < n && A[right] > A[maior]){
        maior = right;
    }
    if(maior != i){
        troque = A[i];
        A[i] = A[maior];
        A[maior] = troque;
        criarHeap(A, maior, n);
    }
}
// countingSort
void countingSort(int *A, int size){
    int k = A[0], i, j, n = size;
    int count[k+1], aux[n];
    for(i = 1; i < size; i++){
        if(A[i] > k){
            k = A[i];
        }
        if(A[i] < 0){
            printf("\nErro: countingSort não funciona com números negativos.\n");
            return;
        }
    }
    for(i = 0; i <= k; i++){
        count[i] = 0;
    }
    for(i = 0; i < size; i++){
        count[A[i]]++;
    }
    for(i = 1; i <= k; i++){
        count[i] += count[i-1];
    }
    for(i = n-1; i >= 0; i--){
        count[A[i]]--;
        aux[count[A[i]]] = A[i];
    }
    for(i = 0; i < size; i++){
        A[i] = aux[i];
    }
    
}
//radixSort
void countingSortPos(int *A, int n, int pos);

int buscaMax(int *A, int size){
    int max = A[0];
    for(int i = 1; i < size; i++){
        if(A[i] > max){
            max = A[i];
        }
    }
    return max;
}

void radixSort(int *A, int size){
    int n = size;
    int max = buscaMax(A, n);

    // Verifica se há números negativos
    for(int i = 0; i < n; i++) {
        if(A[i] < 0) {
            printf("Erro: o Radix Sort não pode receber numeros negativos.\n");
            return;
        }
    }
//se não estiver vai percorrer certinho
    for(int pos = 1; max / pos > 0; pos *= 10){
        countingSortPos(A, n, pos);
    }
}

//Função countingSortPos do Radix 
void countingSortPos(int *A, int n, int pos){
    int aux[n];
    int count[10] = {0};
    for(int i = 0; i < n; i++){
        int digito = (A[i] / pos) % 10;
        count[digito]++;
        
    }
    for(int i = 1; i < 10; i++){
        count[i] += count[i-1];
    }
    for(int i = n-1; i >= 0; i--){
        int digito = (A[i] / pos) % 10;
        count[digito]--;
        aux[count[digito]] = A[i];
    }
    for(int i = 0; i < n; i++){
        A[i] = aux[i];
    }
}

