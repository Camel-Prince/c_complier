int fun1(int a)
{
     //数组和指针测试
     int *a=&b;
     b=*a;
     int a[3]={0};
     int a[]={1,2,3};
     b=a[2];
    return b;
}
int main()
{
    //变量
    int a,b=2,c=d,e=1*(23+4);
    a=1+r;a=1-r;a=a*a;a=a/a;a=a%a;a=a^a;
    a=a&&c;a=a||b;a=!a;a==a;a!=a;
    a=func(a);
    //if else
    if (a>5) b=3;
    else if(a<4) b=6;
    else b=7;
    //while
    while(a<=0)
    {
        a=func(a);
    }
    //for
    for(;a<=10;a=a+1)
    {
        scanf(b);
        printf(a);
        printf("eds");
    }
    for(int m=0; m<10; m=m+3)
    {
        if(m>=5) break;
    }
    return 1;

}
