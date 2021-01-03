int main(){
    int a = 0;
    int result = 1;
    while(a < 10){
        a = a+1;
        result = result*(a+1);
        if(result > 20){
            print_int(result);
        }
    }
    
    //24 
    //120
    //720
    //5040
    //40320
    //362880
    //3628800
    
}