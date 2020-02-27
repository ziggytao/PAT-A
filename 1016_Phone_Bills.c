#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct{
    int mo,d,h,mi,on;
}Record;
typedef struct {
    char id[30];
    Record records[1000];
    int num;
}Customer;
Customer customers[1000];
int cnt = 0;
int rate[25];
int exist(char s[]){
    int ret = -1;
    int i;
    for(i = 0; i < cnt; i++){
        if(strcmp(customers[i].id,s) == 0){
            ret = i;
            break;
        }
    }
    return ret;
}
int cmp(const void* a,const void* b){
    if((*(Record*)a).d == (*(Record*)b).d){
        if((*(Record*)a).h == (*(Record*)b).h){
            return (*(Record*)a).mi - (*(Record*)b).mi;
        } else{
            return (*(Record*)a).h - (*(Record*)b).h;
        }
    } else{
        return (*(Record*)a).d - (*(Record*)b).d;
    }
}
int cmp1(const void* a,const void* b) {
    return strcmp((*(Customer*)a).id,(*(Customer*)b).id);
}
int calculate(Record a,Record b){
    int pay = 0,cnt = 0;
    Record tmp = a;
    while ((a.d != b.d) || (a.h != b.h) || (a.mi != b.mi)){
        a.mi++;
        cnt++;
        pay += rate[a.h];
        if(a.mi == 60){
            a.h++;
            a.mi = 0;
        }
        if(a.h == 24){
            a.d++;
            a.h = 0;
        }
    }
    printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n",tmp.d,tmp.h,tmp.mi,b.d,b.h,b.mi,cnt,(pay * 0.01));
    return pay;
}
int main() {
    int i,n,j;
    int month,day,hour,minute,online;
    char name[30],time[100],s[20];
    for(i = 0; i < 24; i++){
        scanf("%d",&(rate[i]));
    }
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        scanf("%s %s %s",name,time,s);
        month = time[1] - '0' + (time[0] - '0') * 10;
        day = time[4] - '0' + (time[3] - '0') * 10;
        hour = time[7] - '0' + (time[6] - '0') * 10;
        minute = time[10] - '0' + (time[9] - '0') * 10;
        if(s[1] == 'n'){
            online = 1;
        } else{
            online = 0;
        }
        j = exist(name);
//        printf("%s %d %d %d %d %d\n",name,month,day,hour,minute,online);
//        printf("%d\n",j);
        if(j != -1){
            customers[j].records[customers[j].num].mo = month;
            customers[j].records[customers[j].num].d = day;
            customers[j].records[customers[j].num].h = hour;
            customers[j].records[customers[j].num].mi = minute;
            customers[j].records[customers[j].num].on = online;
            customers[j].num++;
        } else{
            customers[cnt].num = 1;
            strcpy(customers[cnt].id,name);
            customers[cnt].records[0].mo = month;
            customers[cnt].records[0].d = day;
            customers[cnt].records[0].h = hour;
            customers[cnt].records[0].mi = minute;
            customers[cnt].records[0].on = online;
            cnt++;
        }
    }
    qsort(customers,cnt, sizeof(Customer),cmp1);
    for(i = 0; i < cnt; i++){
        int amount = 0,pay;
        int flag = 1;
        qsort(customers[i].records,customers[i].num, sizeof(Record),cmp);
        for(j = 0; j < customers[i].num-1;){
            if((customers[i].records[j].on == 1) && (customers[i].records[j+1].on == 0)){
                if(flag){
                    printf("%s %02d\n",customers[i].id,customers[i].records[0].mo);
                    flag = 0;
                }
                pay= calculate(customers[i].records[j],customers[i].records[j+1]);
                amount += pay;
                j += 2;
            } else{
                j++;
            }
        }
        if(flag == 0){
            printf("Total amount: $%.2f\n",amount*0.01);
            //没有消费的用户不输出任何信息
        }
    }
//    printf("%d\n",cmp((const void*)(&(customers[0].records[0])),(const void*)(&(customers[0].records[1]))));
//    printf("%s %d \n",customers[0].id,customers[0].num);
//    printf("%d\n",cnt);
//    printf("%d %s %s\n",strcmp(customers[0].id,customers[1].id),customers[0].id,customers[1].id);
    return 0;

}