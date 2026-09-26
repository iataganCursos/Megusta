#include "ouka/Megusta.cpp"

int main(){
        Megusta r;
        r.rPrint("Esta eh uma mensagem de exemplo.");
        r.rPrintln("Esta eh uma mensagem de exemplo.");

        r.rPrintlnEmpty();

        char *nome = r.rInput("Qual eh o seu nome? ");
        r.rPrint("Olah, ");
        r.rPrint(nome);
        r.rPrintln("!");

        r.rPrintlnEmpty();

        char conteudo[] = "Este eh o conteudo que serah salvo no arquivo.";
        char nomeArquivo[] = "meu_arquivo.txt";
        r.rSaveFile(nomeArquivo, conteudo);

        r.rPrintlnEmpty();

        char *conteudoArquivo = r.rOpenFile(nomeArquivo);
        if (conteudoArquivo) {
            r.rPrintln(conteudoArquivo);
            free(conteudoArquivo);
        }

        r.rPrintlnEmpty();
        r.rOpenProgram("c:/java/jdk-23/bin/java.exe -jar /MeuApp/WindowJAR.jar");

        r.rPrintlnEmpty();
        r.rPrintln(r.rOpenFileWeb("https://www.ouka.com.br/meu_arquivo.txt"));

        r.rPrintlnEmpty();
        // strReplace
        char original[] = "Hoje é um lindo dia!";
        char *substituida = r.strReplace(original, "lindo", "maravilhoso");
        r.rPrintln(substituida);
        free(substituida); // Saída: "Hoje é um maravilhoso dia!"

        // strLength
        char minhaString[] = "Olá, mundo!";
        int tamanho = r.strLength(minhaString);
        r.rPrint("O tamanho da string é: %d\n", tamanho); // Saída: "O tamanho da string é: 12"

        // strSubstring
        char original2[] = "Isso é uma char * de exemplo.";
        char *sub = r.strSubstring(original2, 8, 13);
        r.rPrintln(sub); // Saída: "uma c"

        // strCharAt
        char minhaString2[] = "Olá, mundo!";

        char primeiroCaractere = r.strCharAt(minhaString2,0); // Obtém o primeiro caractere 'O'
        char quartoCaractere = r.strCharAt(minhaString2, 3); // Obtém o quarto caractere ','

        r.rPrint("Primeiro caractere: %c\n", primeiroCaractere);
        r.rPrint("Quarto caractere: %c\n", quartoCaractere);

        // strIndexOf
        char minhaString3[] = "Isso é um exemplo de indexOf em Java.";
        int indice = r.strIndexOf(minhaString3, "exemplo");
        r.rPrint("A substring 'exemplo' começa no índice: %d\n", indice); // Saída: "A substring 'exemplo' começa no índice: 13"

        // strLastIndexOf
        char minhaString4[] = "Isso é um exemplo de lastIndexOf em Java. lastIndexOf é útil para encontrar a última ocorrência de uma substring.";
        int indice2 = r.strLastIndexOf(minhaString4,"lastIndexOf");
        r.rPrint("A última ocorrência de 'lastIndexOf' começa no índice: %d\n", indice2); // Saída: "A última ocorrência de 'lastIndexOf' começa no índice: 38"
 
        // strToLowerCase
        char minhaString5[] = "Isso É Uma char *De Exemplo.";
        char *emMinusculas = r.strToLowerCase(minhaString5);
        r.rPrintln(emMinusculas); // Saída: "isso é uma char *de exemplo."

        // strToUpperCase
        char minhaString6[] = "Isso É Uma char *De Exemplo.";
        char *emMaiusculas = r.strToUpperCase(minhaString6);
        r.rPrintln(emMaiusculas); // Saída: "ISSO É UMA char *DE EXEMPLO."
 
        // strCompareTo
        char string1[] = "abacate";
        char string2[] = "banana";

        int resultado = r.strCompareTo(string1, string2);

        if (resultado < 0) {
                r.rPrintln("string1 é menor que string2");
        } else if (resultado == 0) {
                r.rPrintln("string1 é igual a string2");
        } else {
                r.rPrintln("string1 é maior que string2");
        }

        // strCompareToIgnoreCase
        char string1_1[] = "maçã";
        char string2_1[] = "MaÇÃ";

        int resultado2 = r.strCompareToIgnoreCase(string1_1, string2_1);

        if (resultado2 < 0) {
                r.rPrintln("string1 é menor que string2 (ignorando a diferença entre maiúsculas e minúsculas)");
        } else if (resultado2 == 0) {
                r.rPrintln("string1 é igual a string2 (ignorando a diferença entre maiúsculas e minúsculas)");
        } else {
                r.rPrintln("string1 é maior que string2 (ignorando a diferença entre maiúsculas e minúsculas)");
        }

        // strEquals
        char string1_2[] = "Olá, mundo!";
        char string2_2[] = "Olá, mundo!";
        char string3_2[] = "olá, Mundo!";

        bool saoIguais1 = r.strEquals(string1_2, string2_2); // Retorna true
        bool saoIguais2 = r.strEquals(string1_2, string3_2); // Retorna false

        r.rPrintln(saoIguais1 ? "true" : "false");
        r.rPrintln(saoIguais2 ? "true" : "false");
 
        // strEqualsIgnoreCase
        char string1_3[] = "Olá, mundo!";
        char string2_3[] = "olá, Mundo!";

        bool saoIguais = r.strEqualsIgnoreCase(string1_3, string2_3); // Retorna true

        r.rPrintln(saoIguais ? "true" : "false");


        r.rPrintlnEmpty();

r.rPrintln("%c", r.strCharAt("Hello", 4));           // o
r.rPrintln("%s", r.strConcat(3, "Hello", " ", "world")); // Hello world
r.rPrintln("%s", r.strStartsWith("Hello", "H") ? "true" : "false");     // true
r.rPrintln("%s", r.strEndsWith("Hello", "o") ? "true" : "false");       // true
r.rPrintln("%s", r.strIncludes("Hello", "x") ? "true" : "false");       // false
r.rPrintln("%d", r.strIndexOf("Hello", "l"));        // 2
r.rPrintln("%d", r.strLastIndexOf("Hello", "l"));    // 3
r.rPrintln("%s", r.strPadStart("Hello", 6, "?"));    // ?Hello
r.rPrintln("%s", r.strPadEnd("Hello", 6, "?"));      // Hello?
r.rPrintln("%s", r.strRepeat("Hello", 3));           // HelloHelloHello
r.rPrintln("%s", r.strReplace("Hello", "llo", "y")); // Hey
r.rPrintln("%d", r.strSearch("Hello", "e"));         // 1
r.rPrintln("%s", r.strSlice("Hello", 1, 3));         // el
int totalPartes;
char **v = r.strSplit("Hello", "", &totalPartes);  // ['H','e','l','l','o']
for(int i=0; i<totalPartes; i++) {
        r.rPrintln("%s", v[i]);
}
r.rPrintln("%s", r.strSubstring("Hello", 2, 4));     // ll
r.rPrintln("%s", r.strToLowerCase("Hello"));       // hello
r.rPrintln("%s", r.strToUpperCase("Hello"));       // HELLO
r.rPrintln("%s", r.strTrim(" Hello "));            // Hello
r.rPrintln("%s", r.strTrimStart(" Hello "));       // "Hello "
r.rPrintln("%s", r.strTrimEnd(" Hello "));         // " Hello"

        r.rPrintlnEmpty();

        char Texto[500] = "";


        int Dia_do_mes = r.dateDay();
        int Dia_da_semana = r.dateWeekDay();
        int Mes = r.dateMonth();
        int Ano = r.dateYear();

        // ---------------------------------------
        int Horas = r.dateHour24();
        int Minutos = r.dateMinute();
        int Segundos = r.dateSecond();
        // ---------------------------------------
        char semana[8][20] = {
            "",
            "Domingo",
            "Segunda",
            "Terça",
            "Quarta",
            "Quinta",
            "Sexta",
            "Sabado"
        };
        char *Semana_atual = semana[Dia_da_semana];
        //-------------------------
        char Mes2[12][20] = {
            "Janeiro",
            "Fevereiro",
            "Março",
            "Abril",
            "Maio",
            "Junho",
            "Julho",
            "Agosto",
            "Setembro",
            "Outubro",
            "Novembro",
            "Desembro"
        };
        char *Mes_atual = Mes2[Mes - 1];

        snprintf(Texto, sizeof(Texto), "%s, %d de %s de %d\nSão: %d horas, %d minutos e %d segundos.",
                 Semana_atual, Dia_do_mes, Mes_atual, Ano, Horas, Minutos, Segundos);

        r.rPrintln(Texto);

        Texto[0] = '\0';

        int x_dia = 28;
        int x_mes = 4;
        int x_ano = 1997;
        
        // ---------------------------------------
        Dia_do_mes = x_dia;
        Dia_da_semana = r.dateSetWeekDay(x_ano, x_mes, x_dia);
        Mes = x_mes;
        Ano = x_ano;

        Semana_atual = semana[Dia_da_semana];
        //-------------------------

        Mes_atual = Mes2[Mes - 1];

        snprintf(Texto, sizeof(Texto), "%s, %d de %s de %d",
                 Semana_atual, Dia_do_mes, Mes_atual, Ano);
        r.rPrintln(Texto);

        r.rPrintlnEmpty();

        // ArrayList equivalente em C usando StringList
        StringList frutasx;
        r.arrInit(&frutasx);
        r.arrAddAll(&frutasx, "Banana", "Melão", "Goiaba", "Morango", NULL);
        for(int i = 0; i < r.arrSize(&frutasx); i++){
                r.rPrintln(r.arrGet(&frutasx, i));
        }

        r.rPrintlnEmpty();

        StringList frutas1;
        r.arrInit(&frutas1);
        r.arrAdd(&frutas1, "Banana");
        r.arrAdd(&frutas1, "Melão");
        r.arrAdd(&frutas1, "Goiaba");
        r.arrAdd(&frutas1, "Morango");
        for(int i = 0; i < r.arrSize(&frutas1); i++){
                r.rPrintln(r.arrGet(&frutas1, i));
        }

        r.rPrintlnEmpty();

        StringList frutas2;
        r.arrInit(&frutas2);
        r.arrAdd(&frutas2, "Banana");
        r.arrAdd(&frutas2, "Melão");
        r.arrAdd(&frutas2, "Goiaba");
        r.arrAdd(&frutas2, "Morango");
        r.arrInsert(&frutas2, 1, "======");
        for(int i = 0; i < r.arrSize(&frutas2); i++){
                r.rPrintln(r.arrGet(&frutas2, i));
        }

        r.rPrintlnEmpty();

        StringList frutas3;
        r.arrInit(&frutas3);
        r.arrAdd(&frutas3, "Banana");
        r.arrAdd(&frutas3, "Melão");
        r.arrAdd(&frutas3, "Goiaba");
        r.arrAdd(&frutas3, "Morango");
        r.arrSet(&frutas3, 1, "======");
        for(int i = 0; i < r.arrSize(&frutas3); i++){
                r.rPrintln(r.arrGet(&frutas3, i));
        }

        r.rPrintlnEmpty();

        StringList frutas4;
        r.arrInit(&frutas4);
        r.arrAdd(&frutas4, "Banana");
        r.arrAdd(&frutas4, "Melão");
        r.arrAdd(&frutas4, "Goiaba");
        r.arrAdd(&frutas4, "Morango");
        r.arrRemove(&frutas4, 1);
        for(int i = 0; i < r.arrSize(&frutas4); i++){
                r.rPrintln(r.arrGet(&frutas4, i));
        }

        r.rPrintlnEmpty();

        StringList frutas5;
        r.arrInit(&frutas5);
        r.arrAdd(&frutas5, "Banana");
        r.arrAdd(&frutas5, "Melão");
        r.arrAdd(&frutas5, "Goiaba");
        r.arrAdd(&frutas5, "Morango");
        r.arrClear(&frutas5);
        for(int i = 0; i < r.arrSize(&frutas5); i++){
                r.rPrintln(r.arrGet(&frutas5, i));
        }

        r.rPrintlnEmpty();

        StringList lista1;
        r.arrInit(&lista1);
        r.arrAdd(&lista1, "Jose");
        r.arrAdd(&lista1, "Maria");
        r.rPrintln(r.arrContains(&lista1, "Jose") ? "true" : "false");

        r.rPrintlnEmpty();

        StringList lista2;
        r.arrInit(&lista2);
        r.arrAdd(&lista2, "Jose");
        r.arrAdd(&lista2, "Maria");
        r.arrAdd(&lista2, "Joao");
        char **elementos2 = r.arrToArray(&lista2);
        for(int i=0; i < r.arrSize(&lista2); i++){
                r.rPrintln(elementos2[i]);
        }

        r.rPrintlnEmpty();

        StringList lista3;
        r.arrInit(&lista3);
        r.arrAdd(&lista3, "Jose");
        r.arrAdd(&lista3, "Maria");
        r.arrAdd(&lista3, "João");
        printf("%d\n", r.arrIndexOf(&lista3, "Maria"));

        r.rPrintlnEmpty();

        StringList lista4;
        r.arrInit(&lista4);
        r.arrAdd(&lista4, "Jose");
        r.arrAdd(&lista4, "Maria");
        r.arrAdd(&lista4, "João");
        r.arrAdd(&lista4, "Maria");
        printf("%d\n", r.arrLastIndexOf(&lista4, "Maria"));

        r.rPrintlnEmpty();

//Funções Matemáticas

//Convertendo char *para Numérica
//Números Inteiros
//mathint
        // Exemplo simples
        char numeroString[] = "123456";
        long numeroLong = r.mathInt(numeroString);
        r.rPrintln("Número convertido: %ld", numeroLong);

        // Tratamento de entrada inválida para inteiro
        char entradaInvalida[] = "abc";
        {
            char *endptr = NULL;
            long resultadoL = strtol(entradaInvalida, &endptr, 10);
            if (*entradaInvalida == '\0' || *endptr != '\0') {
                r.rPrintln("Erro: A char *não é um número válido.");
            } else {
                r.rPrintln("Número convertido: %ld", resultadoL);
            }
        }

//Números Reais
//mathnum
        // Exemplo simples
        char numeroString1[] = "123.456";
        double numeroDoubleD = r.mathNum(numeroString1);
        r.rPrintln("Número convertido: %f", numeroDoubleD);

        // Tratamento de entrada inválida para real
        char entradaInvalida1[] = "abc";
        {
            char *endptr = NULL;
            double resultadoD = strtod(entradaInvalida1, &endptr);
            if (*entradaInvalida1 == '\0' || *endptr != '\0') {
                r.rPrintln("Erro: A char *não é um número válido.");
            } else {
                r.rPrintln("Número convertido: %f", resultadoD);
            }
        }

//Boleanos
//mathbool
        // Exemplos simples
        char trueString2[] = "true";
        bool booleanTrue = r.mathBool(trueString2);
        r.rPrintln("Valor booleano: %s", booleanTrue ? "true" : "false");

        char falseString3[] = "false";
        bool booleanFalse = r.mathBool(falseString3);
        r.rPrintln("Valor booleano: %s", booleanFalse ? "true" : "false");

        // Tratamento de entrada inválida
        char entradaInvalida3[] = "abc";
        bool resultadoB = r.mathBool(entradaInvalida3);
        r.rPrintln("Valor booleano: %s", resultadoB ? "true" : "false");
        // Como "abc" não é "true", o resultado será false
//Arredondando valores
//Math.floor
        double numeroOriginal = 0.0;
        double numeroArredondado = 0.0;

        numeroOriginal = 7.8;
        numeroArredondado = r.mathFloor(numeroOriginal);

        r.rPrintln("Número original: %f", numeroOriginal);
        r.rPrintln("Número arredondado para baixo: %f", numeroArredondado);
//Math.ceil
        numeroOriginal = 7.2;
        numeroArredondado = r.mathCeil(numeroOriginal);

        r.rPrintln("Número original: %f", numeroOriginal);
        r.rPrintln("Número arredondado para cima: %f", numeroArredondado);
//Math.round
        numeroOriginal = 7.5;
        numeroArredondado = r.mathRound(numeroOriginal);

        r.rPrintln("Número original: %f", numeroOriginal);
        r.rPrintln("Número arredondado: %f", numeroArredondado);

//Digite um número com 3 casas decimais
//mathDecimalFormat
        double numero = 0.0;
        numero = 123.456789;

        char *numeroFormatado = r.mathDecimalFormat(numero, "#.###");

        r.rPrintln("Número formatado: %s", numeroFormatado);

//Formatar moeda
//mathNumberFormat
        numero = 1234567.89;

        // Formatar o número de acordo com a localidade do Brasil
        char *numeroFormatadoBrasil = r.mathNumberFormat(numero, "pt","BR");
       
        r.rPrintln("Brasil: %s", numeroFormatadoBrasil);

//Funções matemáticas comuns
//Math.random

        // Gerar um número aleatório no intervalo [0.0, 1.0)
        double numeroAleatorio = r.mathRandom();

        r.rPrintln("Número aleatório: %f", numeroAleatorio);

        //double numeroAleatorioNoIntervalo = Math.random() * (max - min) + min;
        //double numeroAleatorioIntervalo = Math.random() * (10.0 - 5.0) + 5.0;
        //r.rPrintln("Número aleatório no intervalo: " + numeroAleatorioIntervalo);
//Math.abs

        int numeroInteiro = -5;
        long numeroLongo = -123456789L;
        float numeroFloat = -3.14f;
        double numeroDouble = -2.71828;

        // Calcular o valor absoluto para diferentes tipos de números
        int absInt = (int) r.mathAbs(numeroInteiro);
        long absLong = (long) r.mathAbs(numeroLongo);
        float absFloat = (float) r.mathAbs(numeroFloat);
        double absDouble = r.mathAbs(numeroDouble);

        r.rPrintln("Valor absoluto de %d = %d", numeroInteiro, absInt);
        r.rPrintln("Valor absoluto de %ld = %ld", numeroLongo, absLong);
        r.rPrintln("Valor absoluto de %f = %f", numeroFloat, absFloat);
        r.rPrintln("Valor absoluto de %f = %f", numeroDouble, absDouble);

//Math.max

        double numero3 = 15.5;
        double numero4 = 12.3;

        // Encontrar o máximo entre dois números de ponto flutuante
        double maximoDouble = r.mathMax(numero3, numero4);
        r.rPrintln("Máximo entre %f e %f = %f", numero3, numero4, maximoDouble);

        // int maximoEntreTres = Math.max(Math.max(numero1, numero2), numero3);
//Math.min

        numero3 = 15.5;
        numero4 = 12.3;

        // Encontrar o mínimo entre dois números de ponto flutuante
        double minimoDouble = r.mathMin(numero3, numero4);
        r.rPrintln("Mínimo entre %f e %f = %f", numero3, numero4, minimoDouble);

       //int minimoEntreTres = Math.min(Math.min(numero1, numero2), numero3);

//Math.max

        // Encontrar o máximo entre dois números de ponto flutuante
        maximoDouble = r.mathMaxArr(15.5, 12.3, 10.8, 14.6);
        r.rPrintln("Máximo entre 15.5, 12.3, 10.8, 14.6 = %f", maximoDouble);

//Math.min

        // Encontrar o mínimo entre dois números de ponto flutuante
        minimoDouble = r.mathMinArr(15.5, 12.3, 10.8, 14.6);
        r.rPrintln("Mínimo entre 15.5, 12.3, 10.8, 14.6 = %f", minimoDouble);

//Math.pow
        double base = 2.0;
        double expoente = 3.0;

        // Calcular 2^3
        resultado = (int) r.mathPow(base, expoente);
        r.rPrintln("Resultado: %d", resultado);

//Math.sqrt
        numero = 25.0;

        // Calcular a raiz quadrada de 25
        double raizQuadrada = r.mathSqrt(numero);

        r.rPrintln("Raiz quadrada de %f = %f", numero, raizQuadrada);

//Math.SQRT1_2
        // Utilizando a constante Math.SQRT1_2

        //double mathSQRT1_2 = 0.7071067811865476;
        
        double raizQuadradaDeUmMeio = r.mathSQRT1_2;

        r.rPrintln("Raiz quadrada de 1/2: %f", raizQuadradaDeUmMeio);

//Math.SQRT2
        // Utilizando a constante Math.SQRT2

        //double mathSQRT2 = 1.4142135623730951;

        double raizQuadradaDeDois = r.mathSQRT2;

        r.rPrintln("Raiz quadrada de 2: %f", raizQuadradaDeDois);

 
//Math.cbrt
        numero = 27.0;

        // Calcular a raiz cúbica de 27
        double raizCubica = r.mathCbrt(numero);

        r.rPrintln("Raiz cúbica de %f = %f", numero, raizCubica);

//Math.sign
        numero = -5.5;

        // Obtendo o sinal do número
        int sinal = (int) r.mathSignum(numero);

        r.rPrintln("Sinal de %f = %d", numero, sinal);

        r.rPrintlnEmpty();

//Funções trigonométricas
//Math.PI
        // Acesso à constante Math.PI
        double pi = r.mathPI;

        // Exibindo o valor de pi
        r.rPrintln("O valor de pi é: %f", pi);

        // Exemplo de cálculo usando pi
        double raio = 5.0;
        double area = pi * raio * raio;
        r.rPrintln("A área de um círculo com raio %f é: %f", raio, area);
/*
function radianos(){
return Math.PI/180
}
*/

        double graus = 45.0;
        double radianos = r.mathConvertToRadians(graus);

        r.rPrintln("%f graus é equivalente a %f radianos.", graus, radianos);
 
//Math.sin
        // Ângulo em radianos
        double anguloEmRadianos = r.mathPI / 4.0;

        // Calculando o seno do ângulo
        double senoDoAngulo = r.mathSin(anguloEmRadianos);

        // Exibindo o resultado
        r.rPrintln("O seno de %f radianos é: %f", anguloEmRadianos, senoDoAngulo);

//Math.cos
        // Ângulo em radianos
        anguloEmRadianos = r.mathPI / 3.0;

        // Calculando o cosseno do ângulo
        double cossenoDoAngulo = r.mathCos(anguloEmRadianos);

        // Exibindo o resultado
        r.rPrintln("O cosseno de %f radianos é: %f", anguloEmRadianos, cossenoDoAngulo);

//Math.tan
        // Ângulo em radianos
        anguloEmRadianos = r.mathPI / 6.0;

        // Calculando a tangente do ângulo
        double tangenteDoAngulo = r.mathTan(anguloEmRadianos);

        // Exibindo o resultado
        r.rPrintln("A tangente de %f radianos é: %f", anguloEmRadianos, tangenteDoAngulo);
 
//Math.asin
        // Valor para o qual queremos calcular o arco seno
        double valor = 0.5;

        // Calculando o arco seno do valor
        double arcoSeno = r.mathAsin(valor);

        // Exibindo o resultado em radianos
        r.rPrintln("O arco seno de %f é: %f radianos.", valor, arcoSeno);

//Math.acos
        // Valor para o qual queremos calcular o arco cosseno
        valor = 0.5;

        // Calculando o arco cosseno do valor
        double arcoCosseno = r.mathAcos(valor);

        // Exibindo o resultado em radianos
        r.rPrintln("O arco cosseno de %f é: %f radianos.", valor, arcoCosseno);

//Math.atan
        // Valor para o qual queremos calcular o arco tangente
        valor = 0.5;

        // Calculando o arco tangente do valor
        double arcoTangente = r.mathAtan(valor);

        // Exibindo o resultado em radianos
        r.rPrintln("O arco tangente de %f é: %f radianos.", valor, arcoTangente);
 
//Math.sinh
        // Valor para o qual queremos calcular o seno hiperbólico
        valor = 2.0;

        // Calculando o seno hiperbólico do valor
        double senoHiperbolico = r.mathSinh(valor);

        // Exibindo o resultado
        r.rPrintln("O seno hiperbólico de %f é: %f", valor, senoHiperbolico);

//Math.cosh
        // Valor para o qual queremos calcular o cosseno hiperbólico
        valor = 2.0;

        // Calculando o cosseno hiperbólico do valor
        double cossenoHiperbolico = r.mathCosh(valor);

        // Exibindo o resultado
        r.rPrintln("O cosseno hiperbólico de %f é: %f", valor, cossenoHiperbolico);

//Math.tanh
        // Valor para o qual queremos calcular a tangente hiperbólica
        valor = 2.0;

        // Calculando a tangente hiperbólica do valor
        double tangenteHiperbolica = r.mathTanh(valor);

        // Exibindo o resultado
        r.rPrintln("A tangente hiperbólica de %f é: %f", valor, tangenteHiperbolica);
 
//Math.asinh
        // Valor para o qual queremos calcular o arco seno hiperbólico
        valor = 2.0;

        // Calculando o arco seno hiperbólico do valor
        double arcoSenoHiperbolico = r.mathAsinh(valor);

        // Exibindo o resultado
        r.rPrintln("O arco seno hiperbólico de %f é: %f", valor, arcoSenoHiperbolico);

        //asinh(x) = ln(x + sqrt(x^2 + 1))
//Math.acosh
        // Valor para o qual queremos calcular o arco cosseno hiperbólico
        valor = 2.0;

        // Calculando o arco cosseno hiperbólico do valor
        double arcoCossenoHiperbolico = r.mathAcosh(valor);

        // Exibindo o resultado
        r.rPrintln("O arco cosseno hiperbólico de %f é: %f", valor, arcoCossenoHiperbolico);

        //acosh(x) = ln(x + sqrt(x^2 - 1))
//Math.atanh
        // Valor para o qual queremos calcular o arco tangente hiperbólico
        valor = 0.5;

        // Calculando o arco tangente hiperbólico do valor
        double arcoTangenteHiperbolico = r.mathAtanh(valor);

        // Exibindo o resultado
        r.rPrintln("O arco tangente hiperbólico de %f é: %f", valor, arcoTangenteHiperbolico);

        //atanh(x) = 0.5 * ln((1 + x) / (1 - x))

        r.rPrintlnEmpty();

//Logarítmos

//Math.log
        // Número para o qual queremos calcular o logaritmo natural
        numero = 10.0;

        // Calculando o logaritmo natural do número
        double logaritmoNatural = r.mathLog(numero);

        // Exibindo o resultado
        r.rPrintln("O logaritmo natural de %f é: %f", numero, logaritmoNatural);

//Math.log10
        // Número para o qual queremos calcular o logaritmo na base 10
        numero = 1000.0;

        // Calculando o logaritmo na base 10 do número
        double logaritmoBase10 = r.mathLog10(numero);

        // Exibindo o resultado
        r.rPrintln("O logaritmo na base 10 de %f é: %f", numero, logaritmoBase10);
 
//Math.E
        // Acesso à constante Math.E
        double constanteE = r.mathE;

        // Exibindo o valor da constante E
        r.rPrintln("O valor da constante E é: %f", constanteE);
//Math.LN2
        // Acesso à constante Math.LN2
        double LN2 = r.mathLN2;

        // Exibindo o valor do logaritmo natural de 2
        r.rPrintln("O valor do logaritmo natural de 2 é: %f", LN2);

//Math.LOG2E
        // Acesso à constante Math.LOG2E
        double LOG2E = r.mathLOG2E;

        // Exibindo o valor do logaritmo natural de base 2 de e
        r.rPrintln("O valor do logaritmo natural de base 2 de e é: %f", LOG2E);

//Math.LN10
        // Acesso à constante Math.LN10
        double LN10 = r.mathLN10;

        // Exibindo o valor do logaritmo natural de 10
        r.rPrintln("O valor do logaritmo natural de 10 é: %f", LN10);

//Math.LOG10E
        // Acesso à constante Math.LOG10E
        double LOG10E = r.mathLOG10E;

        // Exibindo o valor do logaritmo natural de base 10 de e
        r.rPrintln("O valor do logaritmo natural de base 10 de e é: %f", LOG10E);

//Math.exp
        // Expoente para o qual queremos calcular a exponenciação
        expoente = 2.0;

        // Calculando a exponenciação de e elevado ao expoente
        double resultado3 = r.mathExp(expoente);

        // Exibindo o resultado
        r.rPrintln("O resultado de e elevado a %f é: %f", expoente, resultado3);

//Math.log2
        // Número para o qual queremos calcular o logaritmo de base 2
        double numero2 = 8.0;

        // Calculando o logaritmo de base 2 do número
        double LOG2 = r.mathLog2(numero2);

        // Exibindo o resultado
        r.rPrintln("O logaritmo de base 2 de %f é: %f", numero2, LOG2);

        //log2(x) = ln(x) / ln(2)

//Math.log1p
        // Valor para o qual queremos calcular o logaritmo natural de 1 mais um
        valor = 0.5;

        // Calculando o logaritmo natural de 1 mais um
        double resultado4 = r.mathLog1p(valor);

        // Exibindo o resultado
        r.rPrintln("O logaritmo natural de 1 mais %f é: %f", valor, resultado4);

        return 0;
}
