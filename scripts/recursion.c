#include <stdio.h>

#define FACTORIAL 1
#define PALINDROME 2
#define PEAKS_COUNT 3
#define EXIT 0
#define CHAR_IN_STRING 4
#define MINIMUM 5

#define FALSE 0
#define TRUE 1

void menu();
int calculate_factorial(int,int);
int check_palindrome(char*,int, int);
int peaks_count(int*,int,int,int);
int char_is_present(char*,int,char);
int minimum(int,int);
int find_minimum(int*,int,int);

int main() {

    int choice;
    int n, result, j;
    char word[15];
    int array[20];
    char char_;

    do{
        printf("********** Questo software contiene alcuni esercizi di ricorsione di base **********\n");
        menu();
        printf("**************************************************************************************\n");
        printf("Scelta: ");
        scanf("%d", &choice);

        switch (choice){
            case FACTORIAL:
                printf("Dammi un numero: ");
                scanf("%d", &n);

                if(n == 0){
                    printf("Risultato = 0\n");
                } else {
                    printf("Il fattoriale di %d è %d\n", n, calculate_factorial(1, n));
                }
                break;

            case PALINDROME:
                j = 0;

                printf("Da quante lettere è comaposta la tua parola?");
                scanf("%d", &n);

                printf("Dimmi la parola: ");
                scanf("%s", word);

                result = check_palindrome(word,n - 1,j);

                if(result){
                    printf("La parola è palindroma!\n");
                } else {
                    printf("La parola non è palindroma\n");
                }
                break;

            case PEAKS_COUNT:
                printf("Dimensione array: ");
                scanf("%d",&n);

                for(int i = 0; i < n; i++){
                    printf("Num.%d:",i);
                    scanf("%d", &array[i]);
                }

                printf("Ci sono %d vette!\n", peaks_count(array,n - 1,0,0));
                break;

            case CHAR_IN_STRING:
                printf("Lunghezza stringa: ");
                scanf("%d", &n);

                printf("Dimmi la parola:");
                scanf("%s", word);

                printf("Dimmi il carattere:");
                scanf("\n%c", &char_);

                if(char_is_present(word,n-1,char_)){
                    printf("Il carattere è presente!\n");
                } else {
                    printf("Il carattere non è presente!\n");

                }
                break;

            case MINIMUM:
                printf("Lunghezza array: ");
                scanf("%d", &n);

                for(int i = 0; i < n; i++){
                    printf("Valore %d: ", i+1);
                    scanf("%d", &array[i]);
                }

                printf("Array ->\t");
                for(int i = 0; i < n; i++){
                    printf("%d  ", array[i]);
                }

                printf("Il minimo dell'array è: %d\n", find_minimum(array,0,n-1));
                break;

            case EXIT:
                printf("CIAO!");
                break;
            default: printf("Scelta non valida!\n");

        }
    } while (choice != 0);
    return 0;
}

void menu(void){
    printf("1.Fattoriale\n");
    printf("2.Palindroma\n");
    printf("3.Conta le vette\n");
    printf("4.Cerca il carattere nella stringa\n");
    printf("5.Trova il minimo in un array\n");
    printf("0.Exit");
}

int calculate_factorial(int result, int n){
    if(n == 1)
        return result;
    result = result * n;
    return calculate_factorial(result, n - 1);

}

int check_palindrome(char *_word, int n,int j){
    if(j >= n)
        return TRUE;
    return ((_word[j] == _word[n]) && check_palindrome(_word,n-1,j+1));
}

int peaks_count(int a[], int index, int max, int peaks) {

    if (index == -1) {
        return peaks;
    }
    if(max < a[index]){
        peaks++;
        max = a[index];
        return peaks_count(a,index-1,max,peaks);
    } else {
        return peaks_count(a,index-1,max,peaks);
    }
}

int char_is_present(char a[], int index, char c){
    if(index == -1) {
        return FALSE;
    }
    if(a[index] == c){
        return TRUE;
    } else {
        return char_is_present(a,index - 1, c);
    }
}

int find_minimum(int a[], int p, int u){
    int q;

    if(p >= u){
        return a[p];
    } else {
        q = (u + p) / 2;

        return minimum(find_minimum(a, p, q), find_minimum(a, q + 1, u));
    }
}

int minimum(int a , int b){
    if (a >= b)
        return b;
    return a;
}
