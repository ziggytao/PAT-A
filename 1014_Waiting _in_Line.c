#include <stdio.h>
typedef struct {
    int time[10],customer_num,max_line_num;
}Window;

void format(int time){
    int hour = time / 60 + 8;
    int minute = time % 60;

    printf("%02d:%02d\n",hour,minute);
}
int main() {
    int windownum,linenum,customer,query;
    scanf("%d %d %d %d",&windownum,&linenum,&customer,&query);
    Window windows[windownum];
    int i,j = 0;
    int time;
    int q[customer+1];
    int sorry[customer+1];
    int nexttime  = 9999,nextwindow = -1;
    for (i = 0; i < windownum; ++i) {
        windows[i].max_line_num = linenum;
        windows[i].customer_num = 0;

    }
    for(i = 1; i <= customer; i++ ){
        scanf("%d",&time);
        if(linenum > 0 && windownum > 0){
            if(windows[j].customer_num == 0){
                windows[j].customer_num++;
                windows[j].time[0] = time;
                q[i] = time;
                sorry[i] = 0;
                j = (j + 1) % windownum;//下一个窗口
            }else if(windows[j].customer_num < windows[j].max_line_num){
                windows[j].time[windows[j].customer_num] = time + windows[j].time[windows[j].customer_num-1];
                q[i] = windows[j].time[windows[j].customer_num];
                if(windows[j].time[windows[j].customer_num-1] >= 540){
                    sorry[i] = 1;
                } else{
                    sorry[i] = 0;
                }
                windows[j].customer_num++;
                j = (j + 1) % windownum;
            } else{
                nexttime = 9999;
                for(j = 0; j < windownum; j++){
                    if(nexttime > windows[j].time[0]){
                        nexttime = windows[j].time[0];
                        nextwindow = j;
                    }
                }
                j = nextwindow;
                for (int k = 0; k < windows[j].customer_num-1; ++k) {
                    windows[j].time[k] = windows[j].time[k+1];
                }
                if(windows[j].time[windows[j].customer_num-1] >= 540){
                    sorry[i] = 1;
                } else{
                    sorry[i] = 0;
                }
                windows[j].time[linenum-1] += time;
//                if(linenum > 1){
//                    windows[j].time[windows[j].customer_num-1] = time + windows[j].time[windows[j].customer_num-2];
//                } else{
//                    windows[j].time[0] += time;
//                }
                q[i] = windows[j].time[windows[j].customer_num-1];

            }
        } else{
            sorry[i] = 1;
        }


    }

    for(i = 0; i < query; i++){
        scanf("%d",&j);
        if(sorry[j]){
//            printf("%d\n",q[j]);
            printf("Sorry\n");
        } else{
//            printf("%d\n",q[j]);
            format(q[j]);
        }
    }

    return 0;
}