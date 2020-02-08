#include <stdlib.h>
#include <stdio.h>
typedef struct {
    int ID;
    int grades[4],rank[4];
}student;
int tag = -1;
int cmp(const void*a,const void*b){
    return (*(student*)b).grades[tag]-(*(student*)a).grades[tag];
    //b - a是从大到小排序
}
/*
 * qsort的使用方法：
 * 原型：
 * void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*))
 * base：第一个元素的指针
 * nitems：要排序元素的个数
 * size：每个元素的大小
 * compar：用于比较的函数，返回值为int
 * 比较函数的原型：
 * int cmp(const void*a,const void*b){
    return (*(student*)b).grades[tag]-(*(student*)a).grades[tag];
 * }
 * 形参必须是const void* ，return时要把参数强制转换成需要的类型。
 */
int main(){
    student stu[2200];
    int n,k;
    int i = 0;
    int id;
    scanf("%d %d",&n,&k);
    for(i = 0; i < n; i++){
        scanf("%d %d %d %d",&(stu[i].ID),&(stu[i].grades[1]),&(stu[i].grades[2]),&(stu[i].grades[3]));
        stu[i].grades[0] = (stu[i].grades[1]+stu[i].grades[2]+stu[i].grades[3]) / 3.0 + 0.5 ;
    }
    for(tag = 0; tag < 4; tag++){
        qsort(stu,n, sizeof(student),cmp);
        for(i = 0; i < n; i++){
            stu[i].rank[tag] = i+1;
            if(i > 0 && (stu[i].grades[tag] == stu[i-1].grades[tag])){
                stu[i].rank[tag] = stu[i-1].rank[tag];
            }
        }
//        for(i = 0; i < n; i++){
//            printf("%d %d %d\n",stu[i].ID,stu[i].grades[tag],stu[i].rank[tag]);
//        }
//        printf("............\n");
    }

    char s[] = "ACME";
    for(i = 0; i < k; i++){
        scanf("%d",&id);
        int best = 99999,besti = -1;
        for(int j = 0; j < n; j++){
            if(stu[j].ID == id){
                for (int l = 0; l < 4; ++l) {
                    if(stu[j].rank[l] < best){
                        best = stu[j].rank[l];
                        besti = l;
                    }
                }
                printf("%d %c\n",best,s[besti]);
            }
        }
        if(besti == -1){
            printf("N/A\n");
        }
    }

    return 0;
}
