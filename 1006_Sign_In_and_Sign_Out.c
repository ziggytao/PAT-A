#include <stdio.h>
#include <string.h>
typedef struct log{
    char ID_number[20],Sign_in_time[20],Sign_out_time[20];
}Log;
int main() {
    int n;
    scanf("%d",&n);
    char in[20] = "23:59:59",out[20] = "00:00:00";
    Log sign_in,sign_out;
    Log list[n];
    for (int i = 0; i < n; ++i) {
        scanf("%s %s %s",list[i].ID_number,list[i].Sign_in_time,list[i].Sign_out_time);
        if(strcmp(in,list[i].Sign_in_time) >= 0){
            strcpy(in,list[i].Sign_in_time);
            sign_in = list[i];
        }
        if(strcmp(out,list[i].Sign_out_time) <= 0){
            strcpy(out,list[i].Sign_out_time);
            sign_out = list[i];
        }
    }
    printf("%s %s\n",sign_in.ID_number,sign_out.ID_number);
    return 0;
}
