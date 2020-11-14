#include<bits/stdc++.h>
using namespace std;
struct node
{
    int fyr,tyr;
    char th[1000];
}a[10000];
char n[1001];
int fyr,tyr,ys1,BD1,ys2,BD2;//fyr开始年份，tyr结束年份，ys世纪1还是年份2，BD公元前1or公元后2
char th[1000],len;
int back_year(int tm,int ys,int BD,int ft)
{
    if(ys==1)
        if(BD==1)
            if(ft==1)
                return (0-tm*100+1);
            else
                return (0-(tm-1)*100);
        else
            if(ft==1)
                return (0+(tm-1)*100+1);
            else
                return (0+tm*100);
    else
        if(BD==1)
            return (0-tm);
        else
            return (0+tm);
}
bool cmp(node &x,node &y)
{
    if(x.fyr!=y.fyr)return (x.fyr<y.fyr);
    else return (x.tyr<y.tyr);
}
int main()
{
    // int ans=1;
    // while(ans<=10000000)
    // {
    //     ans*=2;
    //     printf("%d,",ans);
    // }
    while(gets(n),strcmp(n,"END")!=0)
    {
        if(!strcmp(n,"BACK")){len--;continue;}
        else if(!strcmp(n,"HELP")){printf("开始时间，年份2还是世纪1，公元前1后2，结束时间，年份2还是世纪1，公元前1后2，事件\n");}
        sscanf(n,"%d %d %d %d %d %d:%s",&fyr,&ys1,&BD1,&tyr,&ys2,&BD2,th);
        len++;
        a[len].fyr=back_year(fyr,ys1,BD1,1);
        a[len].tyr=back_year(tyr,ys2,BD2,2);
        printf("%d %d %s\n",a[len].fyr,a[len].tyr,th);
        strcpy(a[len].th,th);
    }
    sort(a+1,a+len+1,cmp);
    for(int i=1;i<=len;i++)
        if(a[i].fyr==a[i].tyr)
            printf("%d\t:%s\n",a[i].fyr,a[i].th);
        else
            printf("%d~%d:%s\n",a[i].fyr,a[i].tyr,a[i].th);
    return 0;
}