#include <iostream>
using namespace std;
void getNext(int* next, string& p)
{
    next[0] = -1;
    int j = 0, k = -1;
    while (j < p.length())
    {
        if (p[j] == p[k] || k == -1)
        {
            j++; k++;
            if (p[j] != p[k])
                next[j] = k;
            else
            {
                next[j] = next[k];
            }
        }
        else
        {
            k = next[k];
        }
    }
    return;
}
int kmp_find(string &str,string &subs,int *next)
{

    //next[j]-把前面字符的后缀移动变成前缀
    int l = str.length(),r=subs.length();
    int i=0, j=0;
    while(i<l&&j<r)
    {
        if(str[i]==subs[j]||j==-1)
        {
            i++; j++;
        }
        else
        {
            j = next[j];
        }
    }
    if (j == r)return i-j;
    return -1;
}
string replace_all(string str,string substring,string newsubstring)
{
    int * next = new int[substring.length()];

    cout<<endl;

    getNext(next, substring);

    int p=0;
    while(p!=-1)
    {
       p=kmp_find(str,substring,next);
       if(p!=-1)
       {
           str.insert(p,newsubstring);
           str.erase(p+newsubstring.length(),substring.length());
       }
    }
    return str;
}
int main()
{


    cout << replace_all("ccaaabb", "ab", "fuck")<< endl;

}
//ml
//2