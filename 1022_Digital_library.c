#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
 * 注意，输出的id是7位数，所以应该：printf("%07d\n",booklist[j].id);
 */
typedef struct{
    int id;
    char title[90],author[90],keyword[5][20],publisher[90],year[10];
}Book;
Book booklist[10010];
int cmp(const void *a,const void *b){
    return (*((Book*)a)).id - (*((Book*)b)).id;
}
int find(char* query,int type,int j){
    int ret = 0,i;
    switch (type) {
        case 1://title
            if(strcmp(booklist[j].title,query) == 0){
                ret = 1;
            }
            break;
        case 2://author
            if(strcmp(booklist[j].author,query) == 0){
                ret = 1;
            }
            break;
        case 3://keyword
            for(i = 0; i < 5; i++){
                if(strcmp(booklist[j].keyword[i],query) == 0){
                    ret = 1;
                }
            }
            break;
        case 4://publisher
            if(strcmp(booklist[j].publisher,query) == 0){
                ret = 1;
            }
            break;
        case 5://year
            if(strcmp(booklist[j].year,query) == 0){
                ret = 1;
            }
            break;
    }

    return ret;
}
int main() {
    char s[100];
    int i,n;
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        scanf("%d",&(booklist[i].id));
        getchar();
        gets(s);
        strcpy(booklist[i].title,s);
        gets(s);
        strcpy(booklist[i].author,s);
        gets(s);
        int j = 0,k = 0,l = 0;
        while (s[j] !='\0'){
            if(s[j] != ' '){
                booklist[i].keyword[k][l++] = s[j];
            } else if(s[j] == ' ' && s[j+1] != ' '){
                booklist[i].keyword[k][l++] = '\0';
                k++;
                l = 0;
            }
            j++;
        }
        gets(s);
        strcpy(booklist[i].publisher,s);
        gets(s);
        strcpy(booklist[i].year,s);
    }
    qsort(booklist,n, sizeof(Book),cmp);
    int qn,type;
    char query[90];
    scanf("%d",&qn);
    getchar();
    for(i = 0; i < qn; i++){
        scanf("%d: ",&type);
        gets(query);
        printf("%d: %s\n",type,query);
        int flag = 0;
        for(int j = 0; j < n; j++){
            if(find(query,type,j)){
                printf("%07d\n",booklist[j].id);
                flag = 1;
            }
        }
        if(!flag){
            printf("Not Found\n");
        }
    }
    return 0;
}