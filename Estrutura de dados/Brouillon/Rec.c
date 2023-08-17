/*typedef struct 
{
    int a;
    float b;
}num;

num setFloat(int a, float b);






num setFloat(int a, float b){
    num x = {a,b}
    return r;
}
void imprimir(int a, float b){
    printf("%d, %f", a, b);
}
num sum(int a, float b){
    if(b>9){
        a+=1;
    }
    else{
        r=a+b;
        r++;
    }
}
*/
typedef struct {
    int a;
    float b;
} num;

num setFloat(int a, float b) {
    num x = {a, b};
    return x;
}

void imprimir(num x) {
    printf("%d, %f", x.a, x.b);
}

num sum(num x, num y) {
    num r;
    float total = x.b + y.b;
    if (total > 9) {
        r.a = x.a + y.a + 1;
        r.b = total - 10;
    } else {
        r.a = x.a + y.a;
        r.b = total;
    }
    return r;
}
int main() {
    num x = setFloat(10, 6.0);
    num y = setFloat(10, 6.0);
    num z = sum(x, y);
    printf("x = ");
    imprimir(x);
    printf("\n");
    printf("y = ");
    imprimir(y);
    printf("\n");
    printf("z = ");
    imprimir(z);
    printf("\n");
    return 0;
}
