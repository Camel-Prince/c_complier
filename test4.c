int main(){
    int b = 9;
    int* a;
    a = &b;
    *a = 100;
    print_int(b);

}