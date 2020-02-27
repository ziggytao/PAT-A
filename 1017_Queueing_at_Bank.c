#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    int time;
    int processing_time;
}Customer;
int cmp(const void* a,const void* b){
    return (*(Customer*)a).time-(*(Customer*)b).time;
}
int main() {
    int n,windownum,window[100],i,w = 0;
    for(i = 0; i < 100; i++){
        window[i] = 8 * 3600;
    }
    char time[20];
    int ptime;
    int cnt = 0,wait_time = 0;
    scanf("%d %d",&n,&windownum);
    if(n > 0){
        Customer customer[10000];
        for(i = 0; i < 10000; i++){
            customer[i].time = 99999;
        }
        for(i = 0; i < n; i++){
            scanf("%s %d",time,&ptime);
            if(strcmp(time,"17:00:00") <= 0){
                customer[cnt].time = (time[0]-'0') * 36000 + (time[1]-'0') * 3600 + (time[3]-'0') * 600 + (time[4]-'0') * 60 + (time[6]-'0') * 10 + (time[7]-'0');
                customer[cnt].processing_time = ptime * 60;
                cnt++;
            }

        }
        qsort(customer,cnt, sizeof(Customer),cmp);
        for(i = 0; i < cnt; i++){
            if(customer[i].time >= window[w]){
                //顾客到来时window是空闲的，不需要等待
                //注意此时不能直接加processing_time
                window[w] = customer[i].time + customer[i].processing_time;
            } else{
                wait_time += (window[w] - customer[i].time);
                window[w] += customer[i].processing_time;
            }

            //从所有window中找出最快的一个
            int next = 99999,j;
            for(j = 0; j < windownum; j++){
                if(next > window[j]){
                    next = window[j];
                    w = j;
                }
            }
        }
        printf("%.1f\n",wait_time * 1.0 / cnt / 60 );
    } else if(n == 0){
        printf("0.0\n");
    }

    return 0;

}