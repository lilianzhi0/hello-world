#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <bitset>
typedef long long LL;
const int inf=0x3f3f3f3f;
const double pi= acos(-1.0);
const double esp=1e-6;
using namespace std;

const int Maxn=110;
const int maxn=20;
char str[maxn][Maxn];//�����ķ�
char st[maxn];//���봮
char stac[maxn];//ģ��ջ������
char nstr[maxn][maxn];//����ת���ķ�
char mstr[maxn][maxn];
char fin[maxn];//�洢�ս��
char firstvt[maxn][maxn],lastvt[maxn][maxn];
char cmp[maxn][maxn];//�洢���еıȽϷ�
int firstflag[maxn],lastflag[maxn];//���ս����firstvt,lastvt�Ƿ����
int fcnt[maxn],lcnt[maxn];//���ս��firsvt��lastvt�ĸ���
int is_fin(char c) { //�ж��ս��
    for(int i=0; fin[i]!='\0'; i++) {
        if(fin[i]==c)
            return 1;
    }
    return 0;
}
int site(char c) { //���ڱ��е��±�
    for(int i=0; fin[i]!='\0'; i++) {
        if(fin[i]==c)
            return i;
    }
}
void get_firstvt(char s,int t) { //��s���ս����firstvtֵ
    int i,j,ii,jj,tt;
    for(i=0; i<t; i++) {
        if(str[i][0]==s)
            break;
    }
    if(!firstflag[i]) {
        int k=fcnt[i];
        for(j=0; str[i][j]!='\0'; j++) {
            if(j==2||str[i][j]=='|') {
                if(is_fin(str[i][j+1])) {
                    firstvt[i][k++]=str[i][j+1];
                } else {
                    if(is_fin(str[i][j+2])) {
                        firstvt[i][k++]=str[i][j+2];
                    }
                    if(str[i][j+1]!=s) {
                        get_firstvt(str[i][j+1],t);
                        for(ii=0; ii<t; ii++) {
                            if(str[ii][0]==str[i][j+1])
                                break;
                        }
                        for(jj=0; jj<fcnt[ii]; jj++) {
                            for(tt=0; tt<k; tt++) {
                                if(firstvt[i][tt]==firstvt[ii][jj])
                                    break;
                            }
                            if(tt==k) {
                                firstvt[i][k++]=firstvt[ii][jj];
                            }
                        }
                    }
                }
            }
        }
        firstvt[i][k]='\0';
        fcnt[i]=k;
        firstflag[i]=1;
    }
}

void output_firstvt(int T) { //���firstvt��
    for(int i=0; i<T; i++) {
        get_firstvt(str[i][0],T);
    }
    for(int i=0; i<T; i++) {
        printf("Firstvt[%c]:",str[i][0]);
        for(int j=0; j<fcnt[i]; j++) {
            printf("%c ",firstvt[i][j]);
        }
        puts("");
    }
}

void get_lastvt(char s,int t) { //��s���ս����lastvtֵ
    int i,j,ii,jj,tt;
    for(i=0; i<t; i++) {
        if(str[i][0]==s)
            break;
    }
    if(!lastflag[i]) {
        int k=lcnt[i];
        for(j=0; str[i][j]!='\0'; j++) {
            if(str[i][j+1]=='|'||str[i][j+1]=='\0') {
                if(is_fin(str[i][j])) {
                    lastvt[i][k++]=str[i][j];
                } else {
                    if(is_fin(str[i][j-1])) {
                        lastvt[i][k++]=str[i][j-1];
                    }
                    if(str[i][j]!=s) {
                        get_lastvt(str[i][j],t);
                        for(ii=0; ii<t; ii++) {
                            if(str[ii][0]==str[i][j])
                                break;
                        }
                        for(jj=0; jj<lcnt[ii]; jj++) {
                            for(tt=0; tt<k; tt++) {
                                if(lastvt[i][tt]==lastvt[ii][jj])
                                    break;
                            }
                            if(tt==k) {
                                lastvt[i][k++]=lastvt[ii][jj];
                            }
                        }
                    }
                }
            }
        }
        lastvt[i][k]='\0';
        lcnt[i]=k;
        lastflag[i]=1;
    }
}

void output_lastvt(int T) { //���lastvt��
    for(int i=0; i<T; i++) {
        get_lastvt(str[i][0],T);
    }
    for(int i=0; i<T; i++) {
        printf("Lastvt[%c]:",str[i][0]);
        for(int j=0; j<lcnt[i]; j++) {
            printf("%c ",lastvt[i][j]);
        }
        puts("");
    }
}
void output(int i,int j,char *str) {
    printf("\t");
    for(int ii=i; ii<=j; ii++)
        printf("%c",str[ii]);
}
int main() {
    int T;
    while(scanf("%d",&T)!=EOF)
    {
    int cnt=0;//�ս���ĸ���
    memset(firstflag,0,sizeof(firstflag));
    memset(lastflag,0,sizeof(lastflag));
    memset(cmp,0,sizeof(cmp));

    for(int i=0; i<T; i++) {
        scanf("%s",str[i]);
        fcnt[i]=lcnt[i]=0;
    }
    for(int i=0; i<T; i++) {
        for(int j=0; str[i][j]!='\0'; j++) {
            if((str[i][j]<'A'||str[i][j]>'Z')&&(str[i][j]!='-'&&str[i][j]!='>')&&str[i][j]!='|')
                fin[cnt++]=str[i][j];
        }
    }
    fin[cnt++]='#';
    fin[cnt]='\0';
    output_firstvt(T);
    output_lastvt(T);
    }
    return 0;
}