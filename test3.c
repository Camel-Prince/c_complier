int main(){
    int a = 0;
    int result = 1;
    int b = 0;
    while(a < 10){
        a = a+1;
        result = result*(a+1);
        if(result > 20){
            b= b+1;
        }
    }
    print_int(result); //3628800
    print_int(b); //7

    //24 
    //120
    //720
    //5040
    //40320
    //362880
    //3628800
    
}