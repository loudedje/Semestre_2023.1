int Celcius(int a){
    return 5.(a-32)/9;
}
int farenheit(int b){
    return (9.b/5) + 32;
}

int main(){
    char b;
    int g;
    printf("Entrar a temperatura deseja: ");
    scanf("%c", &b);

    if(b == "F"){
    printf("Entrar o grau: ");
    scanf("%d", &g);
    int resultado = farenheit(g);
    }
    else if(b == "C" ){
        printf("Entrar o grau: ");
        scanf("%d", &g);
        int resultado = Celcius(g);
         
    }
    else{
        printf("Entrar uma temperatura Valida");
    }
}