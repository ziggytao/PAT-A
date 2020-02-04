/*
This time, you are supposed to find A+B where A and B are two polynomials.

Input Specification:
Each input file contains one test case. Each case occupies 2 lines, and each line contains the information of a polynomial:



Output Specification:
For each test case you should output the sum of A and B in one line, with the same format as the input. Notice that there must be NO extra space at the end of each line. Please be accurate to 1 decimal place.

Sample Input:
2 1 2.4 0 3.2
2 2 1.5 1 0.5

      
    
Sample Output:
3 2 1.5 1 2.9 0 3.2

*/

#include <stdio.h>
int main() {
    double poly[1020] = {0};
    int k,exp;
    double coef;
    scanf("%d",&k);
    int i;
    int cnt = 0;
    for(i = 0; i < k; i++){
        scanf("%d",&exp);
        scanf("%lf",&(poly[exp]));
        cnt++;
    }
    scanf("%d",&k);
    for(i = 0; i < k; i++){
        scanf("%d",&exp);
        scanf("%lf",&coef);
        if(poly[exp] != 0){
            poly[exp] += coef;
            if(poly[exp] == 0){
                cnt--;
            }
        } else{
            poly[exp] = coef;
            cnt++;
        }
    }
    printf("%d",cnt);
    for(i = 1019; i >= 0; i--){
        if(poly[i] != 0){
            printf(" %d %.1f",i,poly[i]);
        }
    }
    printf("\n");
    return 0;
}
