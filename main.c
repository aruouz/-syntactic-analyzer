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
char grac[MAX][MAX];
//typedef struct node{
//    char data[MAX];
//    struct node *next;
//}LNode,*LinkList;

void get_grammer(){
    printf("请输入文法个数:");
    scanf("%d",&gra_Num);
    printf("\n");
//    LinkList H=(LinkList)malloc(sizeof(LNode));
//    H->next=NULL;
//    LNode *s;
    
    for(int i=0;i<gra_Num;i++){
//        s=(LinkList)malloc(sizeof(LNode));
        printf("请输入第%d个文法：",i+1);
        scanf("%s",gra[i]);
        printf("\n");
//        s->next=H->next;
//        H->next=s;
        }
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

int first(int i){
        if(is_lDigital(gra[i][3])&&gra[i][1]!='~'){
            int ct=0;
            while(fst[i][ct]&&fst[i][ct]!=gra[i][3]){
                ct++;
            }
            fst[i][ct]=gra[i][3];
        }
    //else 中
        else if(is_lDigital(gra[i][4])){
            if(gra[i][1]=='~'){
                int ct=0;
                while(fst[i][ct]){
                    ct++;
                }
                fst[i][ct]=gra[i][4];
//                printf("%c",fst[i][ct]);
            }
        }
//asdasd
        else{
            for(int r=0;r<gra_Num;r++){
                if(i!=r){
                    if(gra[i][3]==gra[r][0]&&gra[r][1]!='~'){
                            if(first(r)){
                                int counter=0;
                                while(fst[i][counter]){
                                        counter++;
                                }
                                int ct=0;
                                while(fst[r][ct]){
                                    ct++;
                                }
                                for(int k=0;k<ct;k++){
                                    fst[i][counter+k]=fst[r][k];
                                }
                            }
                    }
                    
                    if(gra[i][4]==gra[r][0]&&gra[i][1]=='~'){
                        if(first(r)){
                            int counter=0;
                            for(int k=0;k<100;k++){
                                if(fst[i][k]){
                                    counter++;
                                }
                            }
                            int ct=0;
                            while(fst[r][ct]){
                                    ct++;
                            }
                            for(int k=0;k<ct;k++){
                                fst[i][counter+k]=fst[r][k];
                            }
                        }
                    }
                }
            }
        }
    //sad
    return 1;

}


void first_frige(){
    int flag=0;
    
    for(int i=0;i<gra_Num;i++){
        for(int j=0;j<gra_Num;j++){
            if(i!=j){
            if(gra[i][0]==gra[j][0]&&gra[i][1]!='~'&&gra[j][1]!='~'){
                if(fst[i][0]==0){
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
    for(int i=0;i<gra_Num;i++){
        if(fst[i][0]) continue;
            first(i);
    }

    first_out();
    printf("\nHello, World!\n");
    return 0;
}
