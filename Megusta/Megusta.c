#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <ctype.h>

#define MAX_INPUT 1024

/* =========================
   PROGRAM
========================= */
/*
Para compilar:

gcc megusta.c -o megusta -lm

-lm é necessário para usar math.h.

*/
/*
#include "megusta.h"

int main(){
    rPrintln("Hello World");
}
*/
void rPrint(const char *message){
    printf("%s", message);
}

void rPrintln(const char *message){
    printf("%s\n", message);
}

void rPrintlnEmpty(){
    printf("\n");
}

char *rInput(const char *prompt){
    static char buffer[MAX_INPUT];
    printf("%s", prompt);
    fgets(buffer, MAX_INPUT, stdin);
    buffer[strcspn(buffer,"\n")] = 0;
    return buffer;
}

/* =========================
   FILE
========================= */

void rSaveFile(const char *nomeArquivo, const char *conteudo){
    FILE *f = fopen(nomeArquivo,"w");

    if(!f){
        printf("Erro ao salvar o arquivo.\n");
        return;
    }

    fprintf(f,"%s",conteudo);
    fclose(f);

    printf("Arquivo %s salvo com sucesso.\n", nomeArquivo);
}

char *rOpenFile(const char *arquivo){
    FILE *f = fopen(arquivo,"r");

    if(!f){
        printf("Erro: arquivo nao encontrado.\n");
        return NULL;
    }

    char *buffer = malloc(100000);
    buffer[0] = '\0';

    char linha[1024];

    while(fgets(linha,sizeof(linha),f)){
        strcat(buffer,linha);
    }

    fclose(f);

    return buffer;
}

void rOpenProgram(const char *programa){
    system(programa);
}

/* =========================
   STRING
========================= */

int strLength(const char *s){
    return strlen(s);
}

char *strSubstring(const char *s,int inicio,int fim){
    int len = fim - inicio;
    char *sub = malloc(len+1);
    strncpy(sub,s+inicio,len);
    sub[len] = '\0';
    return sub;
}

char strCharAt(const char *s,int pos){
    return s[pos];
}

int strIndexOf(const char *s,const char *find){
    char *p = strstr(s,find);
    if(!p) return -1;
    return p - s;
}

int strLastIndexOf(const char *s,const char *find){
    char *result=NULL;
    char *p=(char*)s;

    while((p=strstr(p,find))){
        result=p;
        p++;
    }

    if(!result) return -1;
    return result-s;
}

int strEquals(const char *a,const char *b){
    return strcmp(a,b)==0;
}

int strCompareTo(const char *a,const char *b){
    return strcmp(a,b);
}

char *strToUpperCase(char *s){
    for(int i=0;s[i];i++)
        s[i]=toupper(s[i]);
    return s;
}

char *strToLowerCase(char *s){
    for(int i=0;s[i];i++)
        s[i]=tolower(s[i]);
    return s;
}

/* =========================
   DATE
========================= */

int dateDay(){
    time_t t=time(NULL);
    struct tm *tm=localtime(&t);
    return tm->tm_mday;
}

int dateWeekDay(){
    time_t t=time(NULL);
    struct tm *tm=localtime(&t);
    return tm->tm_wday+1;
}

int dateMonth(){
    time_t t=time(NULL);
    struct tm *tm=localtime(&t);
    return tm->tm_mon+1;
}

int dateYear(){
    time_t t=time(NULL);
    struct tm *tm=localtime(&t);
    return tm->tm_year+1900;
}

int dateHour24(){
    time_t t=time(NULL);
    struct tm *tm=localtime(&t);
    return tm->tm_hour;
}

int dateMinute(){
    time_t t=time(NULL);
    struct tm *tm=localtime(&t);
    return tm->tm_min;
}

int dateSecond(){
    time_t t=time(NULL);
    struct tm *tm=localtime(&t);
    return tm->tm_sec;
}

/* =========================
   ARRAY (Lista dinâmica)
========================= */

typedef struct{
    char **data;
    int size;
    int capacity;
} StringList;

void arrInit(StringList *list){
    list->size=0;
    list->capacity=10;
    list->data=malloc(sizeof(char*)*list->capacity);
}

void arrAdd(StringList *list,const char *valor){

    if(list->size>=list->capacity){
        list->capacity*=2;
        list->data=realloc(list->data,sizeof(char*)*list->capacity);
    }

    list->data[list->size]=strdup(valor);
    list->size++;
}

char *arrGet(StringList *list,int i){
    return list->data[i];
}

void arrSet(StringList *list,int i,const char *valor){
    free(list->data[i]);
    list->data[i]=strdup(valor);
}

int arrSize(StringList *list){
    return list->size;
}

void arrRemove(StringList *list,int i){
    free(list->data[i]);

    for(int j=i;j<list->size-1;j++)
        list->data[j]=list->data[j+1];

    list->size--;
}

void arrClear(StringList *list){
    for(int i=0;i<list->size;i++)
        free(list->data[i]);

    list->size=0;
}

/* =========================
   MATH
========================= */

long mathInt(const char *s){
    return atol(s);
}

double mathNum(const char *s){
    return atof(s);
}

double mathFloor(double x){
    return floor(x);
}

double mathCeil(double x){
    return ceil(x);
}

double mathRound(double x){
    return round(x);
}

double mathRandom(){
    return (double)rand()/RAND_MAX;
}

double mathAbs(double x){
    return fabs(x);
}

double mathMax(double a,double b){
    return fmax(a,b);
}

double mathMin(double a,double b){
    return fmin(a,b);
}

double mathPow(double b,double e){
    return pow(b,e);
}

double mathSqrt(double n){
    return sqrt(n);
}

double mathCbrt(double n){
    return cbrt(n);
}

double mathSignum(double x){
    if(x>0) return 1;
    if(x<0) return -1;
    return 0;
}

double mathConvertToRadians(double graus){
    return graus*(M_PI/180.0);
}

double mathSin(double a){ return sin(a); }
double mathCos(double a){ return cos(a); }
double mathTan(double a){ return tan(a); }

double mathAsin(double x){ return asin(x); }
double mathAcos(double x){ return acos(x); }
double mathAtan(double x){ return atan(x); }

double mathSinh(double x){ return sinh(x); }
double mathCosh(double x){ return cosh(x); }
double mathTanh(double x){ return tanh(x); }

double mathAsinh(double x){
    return log(x + sqrt(x*x+1));
}

double mathAcosh(double x){
    return log(x + sqrt(x*x-1));
}

double mathAtanh(double x){
    return 0.5*log((1+x)/(1-x));
}

double mathLog(double x){
    return log(x);
}

double mathLog10(double x){
    return log10(x);
}

double mathExp(double x){
    return exp(x);
}

double mathLog2(double x){
    return log(x)/log(2);
}

double mathLog1p(double x){
    return log1p(x);
}

/* Constantes */

double mathPI = 3.141592653589793;
double mathE = 2.718281828459045;
double mathSQRT1_2 = 0.7071067811865476;
double mathSQRT2 = 1.4142135623730951;
double mathLN2 = 0.6931471805599453;
double mathLN10 = 2.302585092994046;