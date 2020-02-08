#include <stdio.h>
/*
 * 算法：
 * max,front,rear分别代表最大子列和、子列的首、尾下标
 * tmp、tmp_front分别代表临时的子列和，临时子列首位元素的下标
 * 从第一个非负数开始计算，第一次时令tmp_front = front = rear = i，max=tmp=i
 * 之后每次让tmp+l[i]，如果tmp大于max，则max = tmp，front = tmp_front，rear = i；如果tmp小于max但不小于0，则继续
 * 如果tmp小于0，那么重新初始化，tmp_front = -1，tmp = 0，当找到下一个非负数l[i]时，就令tmp_front= i，tmp += l[i]
 * 最后输出max,l[front],l[rear]
 */
int main() {
    //最大子列和
    int n;
    int max = 0,tmp = 0;
    int front = -1,rear = -1,tmp_front = -1;
    scanf("%d",&n);
    int l[n];
    int i;
    for(i = 0; i < n; i++){
        scanf("%d",l+i);
        if(front < 0){
            if(l[i] >= 0){
                tmp += l[i];
                max = tmp;
                tmp_front = front = rear = i;
            }
        } else if(tmp_front >= 0){
            tmp += l[i];
            if(max < tmp){
                rear = i;
                max = tmp;
                front = tmp_front;
            }
            if(tmp < 0){
                tmp = 0;
                tmp_front = -1;
            }
        } else{
            if(l[i] >= 0){
                tmp_front = i;
                tmp += l[i];
                if(max < tmp){
                    rear = i;
                    max = tmp;
                    front = tmp_front;
                }
            }
        }
    }
    if(front >= 0 ){
        printf("%d %d %d\n",max,l[front],l[rear]);
    }
    else{
        printf("%d %d %d\n",max,l[0],l[n-1]);
    }
    return 0;
}
