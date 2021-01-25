int gcd(int a,int b)
{
     while(1)
     {   
           if(a<b)  {int t=a;a=b;b=t;}
           if(b==0)  return a;
           int x=a%b;a=b;b=x;
     }
 }
 
 int lcm(int a,int b)
 {
     return a/gcd(a,b)*b;
 }
 //¿ìËÙLCM=a/gcd(a,b)*b
