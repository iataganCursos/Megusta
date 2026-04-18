#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdarg.h>

//typedef enum {false=0, true=1} boolean;

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
void rPrint(const char *message, ...){
  if(message == NULL) {
    printf("\n");
  }
  else {
    va_list args;
    va_start(args, message);
    vprintf(message, args);
    va_end(args);
  }
}

void rPrintln(const char *message, ...){
  if(message == NULL) {
    printf("\n");
  }
  else {
    va_list args;
    va_start(args, message);
    vprintf(message, args);
    va_end(args);
    printf("\n");
  }
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

char *strReplace(const char *original, const char *old, const char *new_str){
    char *result;
    int i, cnt = 0;
    int new_len = strlen(new_str);
    int old_len = strlen(old);

    for (i = 0; original[i] != '\0'; i++) {
        if (strstr(&original[i], old) == &original[i]) {
            cnt++;
            i += old_len - 1;
        }
    }

    result = (char *)malloc(i + cnt * (new_len - old_len) + 1);
    i = 0;
    const char *orig = original;
    while (*orig) {
        if (strstr(orig, old) == orig) {
            strcpy(&result[i], new_str);
            i += new_len;
            orig += old_len;
        } else {
            result[i++] = *orig++;
        }
    }
    result[i] = '\0';
    return result;
}

int strCompareToIgnoreCase(const char *a, const char *b){
    const char *p1 = a;
    const char *p2 = b;
    while (*p1 && *p2) {
        char c1 = tolower(*p1);
        char c2 = tolower(*p2);
        if (c1 != c2) return c1 - c2;
        p1++;
        p2++;
    }
    return tolower(*p1) - tolower(*p2);
}

int strEqualsIgnoreCase(const char *a, const char *b){
    return strCompareToIgnoreCase(a, b) == 0;
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

int dateSetWeekDay(int year, int month, int day){
    if (month < 3) {
        month += 12;
        year -= 1;
    }
    int k = year % 100;
    int j = year / 100;
    int h = (day + (13 * (month + 1)) / 5 + k + k / 4 + j / 4 + 5 * j) % 7;
    return ((h + 6) % 7) + 1; // 1=Sunday, 7=Saturday
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
void arrAddAll(StringList *list,...){
    va_list args;
    va_start(args, list);
    while(1){
        char *valor = va_arg(args, char*);
        if(valor == NULL) break;
        if(list->size >= list->capacity){
            list->capacity *= 2;
            list->data = realloc(list->data, sizeof(char*) * list->capacity);
        }
        list->data[list->size] = strdup(valor);
        list->size++;
    }
    va_end(args);
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

int arrContains(StringList *list, const char *valor){
    for(int i = 0; i < list->size; i++){
        if(strcmp(list->data[i], valor) == 0) return 1;
    }
    return 0;
}

char **arrToArray(StringList *list){
    return list->data;
}

int arrIndexOf(StringList *list, const char *valor){
    for(int i = 0; i < list->size; i++){
        if(strcmp(list->data[i], valor) == 0) return i;
    }
    return -1;
}

int arrLastIndexOf(StringList *list, const char *valor){
    for(int i = list->size - 1; i >= 0; i--){
        if(strcmp(list->data[i], valor) == 0) return i;
    }
    return -1;
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

int mathBool(const char *s){
    return strcmp(s, "true") == 0 || strcmp(s, "1") == 0;
}

char *mathDecimalFormat(double num, const char *pattern){
    static char buf[256];
    if(strcmp(pattern, "#.###") == 0){
        sprintf(buf, "%.3f", num);
        return buf;
    }
    sprintf(buf, "%f", num);
    return buf;
}

char *mathNumberFormat(double num, const char *locale, const char *country){
    static char buf[256];
    sprintf(buf, "%.2f", num);
    return buf;
}

double mathMaxArr(double a, double b, double c, double d){
    return fmax(fmax(a, b), fmax(c, d));
}

double mathMinArr(double a, double b, double c, double d){
    return fmin(fmin(a, b), fmin(c, d));
}

#define mathSQRT1_2 0.7071067811865476
#define mathSQRT2 1.4142135623730951

double mathCbrt(double x){
    return cbrt(x);
}

double mathSignum(double x){
    if (x > 0) return 1.0;
    if (x < 0) return -1.0;
    return 0.0;
}

#define mathPI 3.141592653589793

double mathConvertToRadians(double degrees){
    return degrees * mathPI / 180.0;
}

double mathSin(double x){
    return sin(x);
}

double mathCos(double x){
    return cos(x);
}

double mathTan(double x){
    return tan(x);
}

double mathAsin(double x){
    return asin(x);
}

double mathAcos(double x){
    return acos(x);
}

double mathAtan(double x){
    return atan(x);
}

double mathSinh(double x){
    return sinh(x);
}

double mathCosh(double x){
    return cosh(x);
}

double mathTanh(double x){
    return tanh(x);
}

double mathAsinh(double x){
    return asinh(x);
}

double mathAcosh(double x){
    return acosh(x);
}

double mathAtanh(double x){
    return atanh(x);
}

double mathLog(double x){
    return log(x);
}

double mathLog10(double x){
    return log10(x);
}

#define mathE 2.718281828459045
#define mathLN2 0.6931471805599453
#define mathLOG2E 1.4426950408889634
#define mathLN10 2.302585092994046
#define mathLOG10E 0.4342944819032518

double mathExp(double x){
    return exp(x);
}

double mathLog2(double x){
    return log2(x);
}

double mathLog1p(double x){
    return log1p(x);
}

void arrInsert(StringList *list, int index, const char *valor){
    if(index < 0) index = 0;
    if(index > list->size) index = list->size;
    if(list->size >= list->capacity){
        list->capacity *= 2;
        list->data = realloc(list->data, sizeof(char*) * list->capacity);
    }
    for(int j = list->size; j > index; j--){
        list->data[j] = list->data[j - 1];
    }
    list->data[index] = strdup(valor);
    list->size++;
}