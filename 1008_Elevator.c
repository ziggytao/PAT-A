#include <stdio.h>
/*t costs 6 seconds to move the elevator up one floor,
 * and 4 seconds to move down one floor.
 * The elevator will stay for 5 seconds at each stop.
 * The elevator is on the 0th floor at the beginning
 */
int move(int current,int destination);
int main() {
    int n;
    scanf("%d",&n);
    int request[n];
    int i;
    int sum = 0,current = 0,destination;
    for (i = 0; i < n; ++i) {
        scanf("%d",request+i);
        destination = request[i];
        sum += move(current,destination);
        current = destination;
    }
    printf("%d\n",sum);
    return 0;
}
int move(int current,int destination){
    int time = 0;
    if(current > destination){
        time += (current - destination) * 4 + 5;
    } else{
        time += (destination - current) * 6 + 5;
    }
    return time;
}
