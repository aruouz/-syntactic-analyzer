//
//  main.c
//  grammer_Annalyse
//
//  Created by aruouz on 2017/11/30.
//  Copyright © 2017年 aruouz. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#define MAX 100
int gra_Num;
char gra[MAX][MAX];
int count[MAX];
char fst[MAX][MAX];
char fol[MAX][MAX];

//void first_frige();
struct grammer{
    int left;
    int right;
    int length;
    int status;
};

struct grammer list[MAX];
//typedef struct node{
//    char data[MAX];
//    struct node *next;
//}LNode,*LinkList;

void get_grammer(){
    FILE *fp;

    if((fp=fopen("/Users/aruouz/Documents/workspace/test/grammer_Annalyse/grammer_Annalyse/TestGra", "r"))==NULL) {
        printf("file cannot be opened/n");
        exit(1);
    }
    
    printf("请输入文法个数:");

//    while((gra_Num=fgetc(fp))!='\n')
//        fputc(gra_Num,stdout);
//        printf("%d",gra_Num);
//    for(int i=0;i<1;i++){
//        printf("%c",getc(fp));
//    }
    printf("\n");
//    LinkList H=(LinkList)malloc(sizeof(LNode));
//    H->next=NULL;
//    LNode *s;
    
//    for(int i=0;i<gra_Num;i++){
    
//        int j=0;
//        while((gra[i][j]=fgetc(fp))!='\n'&&(gra[i][j]=fgetc(fp))!=EOF){
//            j++;
//            fputc(gra[i][j],stdout);
//        }
        int i=0;
        while(!feof(fp)&&i<5)
        {
            printf("请输入第%d个文法：",i+1);
            memset(gra[i], 1, sizeof(gra[i]));
            fgets(gra[i], sizeof(gra[i]), fp); // 包含了\n
            printf("%s\n", gra[i]);
            for(int j=0;j<100;j++){
                if(gra[i][j]=='\n'){
//                    printf("--%c-",gra[i][j]);
                    gra[i][j]=0;
                }
            }
            i++;

        }
        gra_Num=i;
//        scanf("%s",gra[i]);

//        s->next=H->next;
//        H->next=s;
//        }
//     return H;
}

int separator(int i){
        int j=0;
        while(gra[i][j]){
            if(gra[i][j]=='|'){
                count[j]=1;
            }
            j++;
        }
    return 0;
}

void direct_left(){
    for(int i=0;i<gra_Num;i++){
        if(gra[i][1]!='~'){
        if(gra[i][4]!='~')
        if(gra[i][0]==gra[i][3]){
        //第一个式子
            gra[i][3]=gra[i][2];
            gra[i][2]=gra[i][1];
            gra[i][1]='~';
            int counter=0;
            while(gra[i][counter]){
                counter++;
            }
            gra[i][counter]=gra[i][0];
            gra[i][++counter]='~';
            
        //第二个式子
            int al=gra_Num;
            int ct=gra_Num;

            for(int p=0;p<al;p++){
                if(gra[p][0]==gra[i][0])
                        ct=p;
            }
            
            for(int j=0;j<4;j++){
                gra[ct][j]=gra[i][j];
            }
            gra[ct][4]='$';
            if(ct==gra_Num)
                gra_Num++;

            gra[gra_Num][0]=gra[i][0];
            for(int j=2;j<counter+1;j++){
                gra[gra_Num][j-1]=gra[i][j];
            }
            gra_Num++;
            }

        }
        int ct=0;
        while(gra[i][ct]){
            ct++;
        }
        gra[i][ct]='#';
    }
     printf("---------------------------------------------------\n");
    printf("输入的文法为:\n");
    for(int i=0;i<gra_Num;i++)
        printf("%s\n",gra[i]);
    printf("---------------------------------------------------\n");
}

int  is_lDigital(char ch){
    if((ch>='a'&&ch<='z')||ch=='+'||ch=='-'||ch=='*'||ch=='$'){
        return 1;
    }
    else
        return 0;
}

int is_bDigital(char ch){
    if(ch>='A'&&ch<='Z'){
        return 1;
    }
    else
        return 0;
}

//int first(int i){
//        if(is_lDigital(gra[i][3])&&gra[i][1]!='~'){
//            int ct=0;
//            while(fst[i][ct]&&fst[i][ct]!=gra[i][3]){
//                ct++;
//            }
//            fst[i][ct]=gra[i][3];
//        }
//    //else 中
//        else if(is_lDigital(gra[i][4])){
//            if(gra[i][1]=='~'){
//                int ct=0;
//                while(fst[i][ct]){
//                    ct++;
//                }
//                fst[i][ct]=gra[i][4];
////                printf("%c",fst[i][ct]);
//            }
//        }
////asdasd
//        else{
//            for(int r=0;r<gra_Num;r++){
//                if(i!=r){
//                    if(gra[i][3]==gra[r][0]&&gra[r][1]!='~'){
//
//
//                        if(first(r)){
//                            int p=0;
//                            int flag=0;
//                            char ch=gra[r][0];
//                            while(fst[r][p]){
//                                if(fst[r][p]=='$'){
//                                    int ctt=0;
//                                    while(gra[i][ctt]){
//                                        if(gra[i][ctt]==){
//                                            ctt++;
//                                            break;
//                                        }
//                                        ctt++;
//                                    }
//                                    while(gra[i][ctt]){
//                                    for(int g=0;g<gra_Num;g++){
//                                        if(is_bDigital(gra[i][ctt])){
//                                            if(gra[i][ctt]==gra[g][0]){
//                                                first(g);
//                                                int counter=0;
//                                                while(fst[i][counter]){
//                                                    counter++;
//                                                }
//                                                int ct=0;
//                                                while(fst[g][ct]){
//                                                    ct++;
//                                                }
//                                                int conter=0;
//                                                for(int k=0;k<ct;k++){
//                                                if(fst[r][k]=='$'){
//                                                        continue;
//                                                }
//                                                else{
//                                                    fst[i][counter+conter]=fst[r][k];
//                                                    printf("%c",fst[i][counter+conter]);
//                                                    conter++;
//                                                }
//                                            }
//
////                                            for(int k=0;k<ct;k++){
////                                                fst[i][counter+k]=fst[g][k];
////                                                flag=1;
////                                        }
//
//
//                                    }
//                                    }
//                                        if(is_lDigital(gra[i][ctt])){
//                                            int counter=0;
//                                            while(fst[i][counter]){
//                                                counter++;
//                                            }
//                                                fst[i][counter]=gra[i][ctt];
//                                            flag=2;
//                                            break;
//
//                                        }
//                                        ctt++;
//
//                                    }
//                                        if(flag==2) break;
//                                    }
//
//                                }
//                                     p++;
//                            }
//                            if(flag==0){
//                                int counter=0;
//                                while(fst[i][counter]){
//                                        counter++;
//                                }
//                                int ct=0;
//                                while(fst[r][ct]){
//
//                                    ct++;
//                                }
//                                int conter=0;
//                                for(int k=0;k<ct;k++){
//                                    if(gra[r][k]=='$'){
//                                        continue;
//                                    }
//                                    else{
//                                        fst[i][counter+conter]=fst[r][k];
//                                        conter++;
//                                    }
//                                }
//                            }
//                        }
//                    }
//
//                    if(gra[i][4]==gra[r][0]&&gra[i][1]=='~'){
//                        if(first(r)){
//                            int counter=0;
//                            for(int k=0;k<100;k++){
//                                if(fst[i][k]){
//                                    counter++;
//                                }
//                            }
//                            int ct=0;
//                            while(fst[r][ct]){
//                                    ct++;
//                            }
//                            for(int k=0;k<ct;k++){
//                                fst[i][counter+k]=fst[r][k];
//                            }
//                        }
//                    }
//                }
//            }
//        }
//    //sad
//    return 1;
//
//}
void initlist(){
//    printf("%d",gra_Num);
    for(int i=0;i<gra_Num;i++){
        list[i].left=0;
        list[i].right=0;
        list[i].length=0;
        list[i].status=1;
//        printf("%d,%d",i,list[i].status);
        while(gra[i][list[i].right]){
            if(gra[i][list[i].right]=='>'){
                list[i].right++;
                break;
            }
            else
                list[i].right++;
        }
        while(gra[i][list[i].left]){
            if(gra[i][list[i].left]=='-')
                break;
            else
                list[i].left++;
        }
    }
}
void first_move(){
    
}

int right(int i){
    int rightc=list[i].right;
    if(is_lDigital(gra[i][rightc])){
        if(list[i].length==0){
            fst[i][list[i].length]=gra[i][rightc];
            list[i].length++;
        }
        for(int t=0;t<list[i].length;t++){
            if(fst[i][t]==gra[i][rightc]){
                printf("%d",rightc);
                continue;
                }
            else{
            fst[i][list[i].length]=gra[i][rightc];
            list[i].length++;
            }
        }
    }
    else if(is_bDigital(gra[i][rightc])){
        if(list[i].left==1){
        for(int next=0;next<gra_Num;next++){
            if(i!=next){
//                int flag=0;
            if(gra[next][list[next].left-1]==gra[i][rightc]){
                right(next);
                if(fst[next][list[next].length-1]=='$'){
                    list[i].right++;
                    right(i);
                }
               else{
                    for(int ct=0;ct<list[next].length;ct++){
                        int flag=0;
                        for(int p=0;p<list[i].length;p++){
                            if(fst[next][ct]==fst[i][p]){
                                flag=1;
//                                continue;
                            }
                        }
                        if(flag==0){
                            fst[i][list[i].length]=fst[next][ct];
                            list[i].length++;
                        }
                        }

                }
            }
        }
        }
    }
//        else if(list[i].left==2){
//
//        }
    }
    return 1;
}


void first_frige(){
    int flag=0;
    
    for(int i=0;i<gra_Num;i++){
        for(int j=0;j<gra_Num;j++){
            if(i!=j){
            if(gra[i][list[i].left-1]==gra[j][list[j].left-1]&&gra[i][1]!='~'&&gra[j][1]!='~'){
                if(fst[i][list[i].left-1]==0){
                    continue;
                }
                int ct1=0;
                int ct2=0;
                while(fst[i][ct1]){
                    ct1++;
                }
                while(fst[j][ct2]){
                    ct2++;
                }
                for(int k=0;k<ct1;k++){
                    for(int x=0;x<ct2;k++){
                        if(fst[i][k]==0){
                            flag=1;
                            break;
                        }
                        if(fst[j][x]==0){
                            flag=2;
                            break;
                        }
                        if(fst[i][k]==fst[j][x]){
                            continue;
                        }
                        else{
                            fst[i][ct1+x]=fst[j][x];
                            fst[j][x]=0;
                        }
                    }
                }

            }
            else if(gra[i][0]==gra[j][0]&&gra[i][1]=='~'&&gra[j][1]=='~'){
                if(fst[i][0]==0){
                     flag=1;
                     continue;
                }
                int ct1=0;
                int ct2=0;
                while(fst[i][ct1]){
                    ct1++;
                }
                while(fst[j][ct2]){
                    ct2++;
                }
                for(int k=0;k<ct1;k++){
                    for(int x=0;x<ct2;k++){
                        if(fst[i][k]==0)
                            break;
                        if(fst[j][x]==0)
                            break;

                        if(fst[i][k]==fst[j][x]){
                            continue;
                        }
                        else{
                            fst[i][ct1+x]=fst[j][x];
                             fst[j][x]=0;
                        }
                }
                
            }
        }
                
    }
    }
}
}
void first_out(){
    first_frige();
    for(int i=0;i<gra_Num;i++){
        if(fst[i][0]==0)
            continue;
        
        if(gra[i][1]=='~')
            printf("%c%c的FIRST集为:",gra[i][0],gra[i][1]);
        else
            printf("%c的FIRST集为:",gra[i][0]);
        
        int ct=0;
        while(fst[i][ct]){
            ct++;
        }
        if(ct!=1){
        int j=0;
        for(;j<ct-1;j++)
            printf("%c,",fst[i][j]);
        printf("%c\n",fst[i][ct-1]);
        }
        else{
            printf("%c\n",fst[i][ct-1]);
        }
    }
}


void follow(){
}

int main(int argc, const char * argv[]) {
    get_grammer();
    direct_left();
    initlist();
    for(int i=0;i<gra_Num;i++){
            right(i);
            printf("%s,%d\n",fst[i],i);
    }
    first_out();
    printf("\nHello, World!\n");
    return 0;
}
