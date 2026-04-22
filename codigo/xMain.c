#include "ouka/Megusta.c"

int main(){
        rPrint("Esta eh uma mensagem de exemplo.");

        rPrintln("Esta eh uma mensagem de exemplo.");

        rPrintlnEmpty();

        char *nome = rInput("Qual eh o seu nome? ");
        rPrint("Olah, ");
        rPrint(nome);
        rPrintln("!");

        rPrintlnEmpty();

        char *conteudo = "Este eh o conteudo que serah salvo no arquivo.";
        char *nomeArquivo = "meu_arquivo.txt";
        rSaveFile(nomeArquivo, conteudo);

        rPrintlnEmpty();

        char *conteudoArquivo = rOpenFile(nomeArquivo);
        if (conteudoArquivo) {
            rPrintln(conteudoArquivo);
            free(conteudoArquivo);
        }

        rPrintlnEmpty();
        rOpenProgram("c:/java/jdk-23/bin/java.exe -jar /MeuApp/WindowJAR.jar");

        rPrintlnEmpty();
        rPrintln(rOpenFileWeb("https://www.ouka.com.br/meu_arquivo.txt"));

        rPrintlnEmpty();
        // strReplace
        char *original = "Hoje é um lindo dia!";
        char *substituida = strReplace(original, "lindo", "maravilhoso");
        rPrintln(substituida);
        free(substituida); // Saída: "Hoje é um maravilhoso dia!"

        // strLength
        char minhaString[] = "Olá, mundo!";
        int tamanho = strLength(minhaString);
        printf("O tamanho da string é: %d\n", tamanho); // Saída: "O tamanho da string é: 12"
 
        // strSubstring
        char *original2 = "Isso é uma char *de exemplo.";
        char *sub = strSubstring(original2, 8, 13);
        rPrintln(sub);
        free(sub); // Saída: "uma c"

        // strCharAt
        char *minhaString2 = "Olá, mundo!";
        char primeiroCaractere = strCharAt(minhaString2,0); // Obtém o primeiro caractere 'O'
        printf("Primeiro caractere: %c\n", primeiroCaractere);

        char quartoCaractere = strCharAt(minhaString2, 3); // Obtém o quarto caractere ','

        printf("Primeiro caractere: %c\n", primeiroCaractere);
        printf("Quarto caractere: %c\n", quartoCaractere);

        // strIndexOf
        char *minhaString3 = "Isso é um exemplo de indexOf em Java.";
        int indice = strIndexOf(minhaString3, "exemplo");
        printf("A substring 'exemplo' começa no índice: %d\n", indice); // Saída: "A substring 'exemplo' começa no índice: 13"

        // strLastIndexOf
        char *minhaString4 = "Isso é um exemplo de lastIndexOf em Java. lastIndexOf é útil para encontrar a última ocorrência de uma substring.";
        int indice2 = strLastIndexOf(minhaString4,"lastIndexOf");
        printf("A última ocorrência de 'lastIndexOf' começa no índice: %d\n", indice2); // Saída: "A última ocorrência de 'lastIndexOf' começa no índice: 38"
 
        // strToLowerCase
        char minhaString5[] = "Isso É Uma char *De Exemplo.";
        char *emMinusculas = strToLowerCase(minhaString5);
        rPrintln(emMinusculas); // Saída: "isso é uma char *de exemplo."

        // strToUpperCase
        char minhaString6[] = "Isso É Uma char *De Exemplo.";
        char *emMaiusculas = strToUpperCase(minhaString6);
        rPrintln(emMaiusculas); // Saída: "ISSO É UMA char *DE EXEMPLO."
 
        // strCompareTo
        char *string1 = "abacate";
        char *string2 = "banana";

        int resultado = strCompareTo(string1, string2);

        if (resultado < 0) {
                rPrintln("string1 é menor que string2");
        } else if (resultado == 0) {
                rPrintln("string1 é igual a string2");
        } else {
                rPrintln("string1 é maior que string2");
        }

        // strCompareToIgnoreCase
        char *string1_1 = "maçã";
        char *string2_1 = "MaÇÃ";

        int resultado2 = strCompareToIgnoreCase(string1_1, string2_1);

        if (resultado2 < 0) {
                rPrintln("string1 é menor que string2 (ignorando a diferença entre maiúsculas e minúsculas)");
        } else if (resultado2 == 0) {
                rPrintln("string1 é igual a string2 (ignorando a diferença entre maiúsculas e minúsculas)");
        } else {
                rPrintln("string1 é maior que string2 (ignorando a diferença entre maiúsculas e minúsculas)");
        }

        // strEquals
        char *string1_2 = "Olá, mundo!";
        char *string2_2 = "Olá, mundo!";
        char *string3_2 = "olá, Mundo!";

        bool saoIguais1 = strEquals(string1_2, string2_2); // Retorna true
        bool saoIguais2 = strEquals(string1_2, string3_2); // Retorna false

        rPrintln(saoIguais1 ? "true" : "false");
        rPrintln(saoIguais2 ? "true" : "false");
 
        // strEqualsIgnoreCase
        char *string1_3 = "Olá, mundo!";
        char *string2_3 = "olá, Mundo!";

        bool saoIguais = strEqualsIgnoreCase(string1_3, string2_3); // Retorna true

        rPrintln(saoIguais ? "true" : "false");


        rPrintlnEmpty();

        char Texto[500] = "";


        int Dia_do_mes = dateDay();
        int Dia_da_semana = dateWeekDay();
        int Mes = dateMonth();
        int Ano = dateYear();

        // ---------------------------------------
        int Horas = dateHour24();
        int Minutos = dateMinute();
        int Segundos = dateSecond();
        // ---------------------------------------
        char *semana[8] = {
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
        char *Mes2[12] = {
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

        rPrintln(Texto);

        Texto[0] = '\0';

        int x_dia = 28;
        int x_mes = 4;
        int x_ano = 1997;
        
        // ---------------------------------------
        Dia_do_mes = x_dia;
        Dia_da_semana = dateSetWeekDay(x_ano, x_mes, x_dia);
        Mes = x_mes;
        Ano = x_ano;

        semana[0] = "";
        semana[1] = "Domingo";
        semana[2] = "Segunda";
        semana[3] = "Terça";
        semana[4] = "Quarta";
        semana[5] = "Quinta";
        semana[6] = "Sexta";
        semana[7] = "Sabado";
        Semana_atual = semana[Dia_da_semana];
        //-------------------------
        Mes2[0] = "Janeiro";
        Mes2[1] = "Fevereiro";
        Mes2[2] = "Março";
        Mes2[3] = "Abril";
        Mes2[4] = "Maio";
        Mes2[5] = "Junho";
        Mes2[6] = "Julho";
        Mes2[7] = "Agosto";
        Mes2[8] = "Setembro";
        Mes2[9] = "Outubro";
        Mes2[10] = "Novembro";
        Mes2[11] = "Desembro";
        Mes_atual = Mes2[Mes - 1];

        snprintf(Texto, sizeof(Texto), "%s, %d de %s de %d",
                 Semana_atual, Dia_do_mes, Mes_atual, Ano);
        rPrintln(Texto);

        rPrintlnEmpty();

        // ArrayList equivalente em C usando StringList
        StringList frutasx;
        arrInit(&frutasx);
        arrAddAll(&frutasx, "Banana", "Melão", "Goiaba", "Morango", NULL);
        for(int i = 0; i < arrSize(&frutasx); i++){
                rPrintln(arrGet(&frutasx, i));
        }

        rPrintlnEmpty();

        StringList frutas1;
        arrInit(&frutas1);
        arrAdd(&frutas1, "Banana");
        arrAdd(&frutas1, "Melão");
        arrAdd(&frutas1, "Goiaba");
        arrAdd(&frutas1, "Morango");
        for(int i = 0; i < arrSize(&frutas1); i++){
                rPrintln(arrGet(&frutas1, i));
        }

        rPrintlnEmpty();

        StringList frutas2;
        arrInit(&frutas2);
        arrAdd(&frutas2, "Banana");
        arrAdd(&frutas2, "Melão");
        arrAdd(&frutas2, "Goiaba");
        arrAdd(&frutas2, "Morango");
        arrInsert(&frutas2, 1, "======");
        for(int i = 0; i < arrSize(&frutas2); i++){
                rPrintln(arrGet(&frutas2, i));
        }

        rPrintlnEmpty();

        StringList frutas3;
        arrInit(&frutas3);
        arrAdd(&frutas3, "Banana");
        arrAdd(&frutas3, "Melão");
        arrAdd(&frutas3, "Goiaba");
        arrAdd(&frutas3, "Morango");
        arrSet(&frutas3, 1, "======");
        for(int i = 0; i < arrSize(&frutas3); i++){
                rPrintln(arrGet(&frutas3, i));
        }

        rPrintlnEmpty();

        StringList frutas4;
        arrInit(&frutas4);
        arrAdd(&frutas4, "Banana");
        arrAdd(&frutas4, "Melão");
        arrAdd(&frutas4, "Goiaba");
        arrAdd(&frutas4, "Morango");
        arrRemove(&frutas4, 1);
        for(int i = 0; i < arrSize(&frutas4); i++){
                rPrintln(arrGet(&frutas4, i));
        }

        rPrintlnEmpty();

        StringList frutas5;
        arrInit(&frutas5);
        arrAdd(&frutas5, "Banana");
        arrAdd(&frutas5, "Melão");
        arrAdd(&frutas5, "Goiaba");
        arrAdd(&frutas5, "Morango");
        arrClear(&frutas5);
        for(int i = 0; i < arrSize(&frutas5); i++){
                rPrintln(arrGet(&frutas5, i));
        }

        rPrintlnEmpty();

        StringList lista1;
        arrInit(&lista1);
        arrAdd(&lista1, "Jose");
        arrAdd(&lista1, "Maria");
        rPrintln(arrContains(&lista1, "Jose") ? "true" : "false");

        rPrintlnEmpty();

        StringList lista2;
        arrInit(&lista2);
        arrAdd(&lista2, "Jose");
        arrAdd(&lista2, "Maria");
        arrAdd(&lista2, "Joao");
        char **elementos2 = arrToArray(&lista2);
        for(int i=0; i < arrSize(&lista2); i++){
                rPrintln(elementos2[i]);
        }

        rPrintlnEmpty();

        StringList lista3;
        arrInit(&lista3);
        arrAdd(&lista3, "Jose");
        arrAdd(&lista3, "Maria");
        arrAdd(&lista3, "João");
        printf("%d\n", arrIndexOf(&lista3, "Maria"));

        rPrintlnEmpty();

        StringList lista4;
        arrInit(&lista4);
        arrAdd(&lista4, "Jose");
        arrAdd(&lista4, "Maria");
        arrAdd(&lista4, "João");
        arrAdd(&lista4, "Maria");
        printf("%d\n", arrLastIndexOf(&lista4, "Maria"));

        rPrintlnEmpty();

//Funções Matemáticas

//Convertendo char *para Numérica
//Números Inteiros
//mathint
        // Exemplo simples
        char *numeroString = "123456";
        long numeroLong = mathInt(numeroString);
        rPrintln("Número convertido: %ld", numeroLong);

        // Tratamento de entrada inválida para inteiro
        char *entradaInvalida = "abc";
        {
            char *endptr = NULL;
            long resultadoL = strtol(entradaInvalida, &endptr, 10);
            if (*entradaInvalida == '\0' || *endptr != '\0') {
                rPrintln("Erro: A char *não é um número válido.");
            } else {
                rPrintln("Número convertido: %ld", resultadoL);
            }
        }

//Números Reais
//mathnum
        // Exemplo simples
        numeroString = "123.456";
        double numeroDoubleD = mathNum(numeroString);
        rPrintln("Número convertido: %f", numeroDoubleD);

        // Tratamento de entrada inválida para real
        entradaInvalida = "abc";
        {
            char *endptr = NULL;
            double resultadoD = strtod(entradaInvalida, &endptr);
            if (*entradaInvalida == '\0' || *endptr != '\0') {
                rPrintln("Erro: A char *não é um número válido.");
            } else {
                rPrintln("Número convertido: %f", resultadoD);
            }
        }

//Boleanos
//mathbool
        // Exemplos simples
        char *trueString = "true";
        bool booleanTrue = mathBool(trueString);
        rPrintln("Valor booleano: %s", booleanTrue ? "true" : "false");

        char *falseString = "false";
        bool booleanFalse = mathBool(falseString);
        rPrintln("Valor booleano: %s", booleanFalse ? "true" : "false");

        // Tratamento de entrada inválida
        entradaInvalida = "abc";
        bool resultadoB = mathBool(entradaInvalida);
        rPrintln("Valor booleano: %s", resultadoB ? "true" : "false");
        // Como "abc" não é "true", o resultado será false
//Arredondando valores
//Math.floor
        double numeroOriginal = 0.0;
        double numeroArredondado = 0.0;

        numeroOriginal = 7.8;
        numeroArredondado = mathFloor(numeroOriginal);

        rPrintln("Número original: %f", numeroOriginal);
        rPrintln("Número arredondado para baixo: %f", numeroArredondado);
//Math.ceil
        numeroOriginal = 7.2;
        numeroArredondado = mathCeil(numeroOriginal);

        rPrintln("Número original: %f", numeroOriginal);
        rPrintln("Número arredondado para cima: %f", numeroArredondado);
//Math.round
        numeroOriginal = 7.5;
        numeroArredondado = mathRound(numeroOriginal);

        rPrintln("Número original: %f", numeroOriginal);
        rPrintln("Número arredondado: %f", numeroArredondado);

//Digite um número com 3 casas decimais
//mathDecimalFormat
        double numero = 0.0;
        numero = 123.456789;

        char *numeroFormatado = mathDecimalFormat(numero, "#.###");

        rPrintln("Número formatado: %s", numeroFormatado);

//Formatar moeda
//mathNumberFormat
        numero = 1234567.89;

        // Formatar o número de acordo com a localidade do Brasil
        char *numeroFormatadoBrasil = mathNumberFormat(numero, "pt","BR");
       
        rPrintln("Brasil: %s", numeroFormatadoBrasil);

//Funções matemáticas comuns
//Math.random

        // Gerar um número aleatório no intervalo [0.0, 1.0)
        double numeroAleatorio = mathRandom();

        rPrintln("Número aleatório: %f", numeroAleatorio);

        //double numeroAleatorioNoIntervalo = Math.random() * (max - min) + min;
        //double numeroAleatorioIntervalo = Math.random() * (10.0 - 5.0) + 5.0;
        //rPrintln("Número aleatório no intervalo: " + numeroAleatorioIntervalo);
//Math.abs

        int numeroInteiro = -5;
        long numeroLongo = -123456789L;
        float numeroFloat = -3.14f;
        double numeroDouble = -2.71828;

        // Calcular o valor absoluto para diferentes tipos de números
        int absInt = (int) mathAbs(numeroInteiro);
        long absLong = (long) mathAbs(numeroLongo);
        float absFloat = (float) mathAbs(numeroFloat);
        double absDouble = mathAbs(numeroDouble);

        rPrintln("Valor absoluto de %d = %d", numeroInteiro, absInt);
        rPrintln("Valor absoluto de %ld = %ld", numeroLongo, absLong);
        rPrintln("Valor absoluto de %f = %f", numeroFloat, absFloat);
        rPrintln("Valor absoluto de %f = %f", numeroDouble, absDouble);

//Math.max

        double numero3 = 15.5;
        double numero4 = 12.3;

        // Encontrar o máximo entre dois números de ponto flutuante
        double maximoDouble = mathMax(numero3, numero4);
        rPrintln("Máximo entre %f e %f = %f", numero3, numero4, maximoDouble);

        // int maximoEntreTres = Math.max(Math.max(numero1, numero2), numero3);
//Math.min

        numero3 = 15.5;
        numero4 = 12.3;

        // Encontrar o mínimo entre dois números de ponto flutuante
        double minimoDouble = mathMin(numero3, numero4);
        rPrintln("Mínimo entre %f e %f = %f", numero3, numero4, minimoDouble);

       //int minimoEntreTres = Math.min(Math.min(numero1, numero2), numero3);

//Math.max

        // Encontrar o máximo entre dois números de ponto flutuante
        maximoDouble = mathMaxArr(15.5, 12.3, 10.8, 14.6);
        rPrintln("Máximo entre 15.5, 12.3, 10.8, 14.6 = %f", maximoDouble);

//Math.min

        // Encontrar o mínimo entre dois números de ponto flutuante
        minimoDouble = mathMinArr(15.5, 12.3, 10.8, 14.6);
        rPrintln("Mínimo entre 15.5, 12.3, 10.8, 14.6 = %f", minimoDouble);

//Math.pow
        double base = 2.0;
        double expoente = 3.0;

        // Calcular 2^3
        resultado = (int) mathPow(base, expoente);
        rPrintln("Resultado: %d", resultado);

//Math.sqrt
        numero = 25.0;

        // Calcular a raiz quadrada de 25
        double raizQuadrada = mathSqrt(numero);

        rPrintln("Raiz quadrada de %f = %f", numero, raizQuadrada);

//Math.SQRT1_2
        // Utilizando a constante Math.SQRT1_2

        //double mathSQRT1_2 = 0.7071067811865476;
        
        double raizQuadradaDeUmMeio = mathSQRT1_2;

        rPrintln("Raiz quadrada de 1/2: %f", raizQuadradaDeUmMeio);

//Math.SQRT2
        // Utilizando a constante Math.SQRT2

        //double mathSQRT2 = 1.4142135623730951;

        double raizQuadradaDeDois = mathSQRT2;

        rPrintln("Raiz quadrada de 2: %f", raizQuadradaDeDois);

 
//Math.cbrt
        numero = 27.0;

        // Calcular a raiz cúbica de 27
        double raizCubica = mathCbrt(numero);

        rPrintln("Raiz cúbica de %f = %f", numero, raizCubica);

//Math.sign
        numero = -5.5;

        // Obtendo o sinal do número
        int sinal = (int) mathSignum(numero);

        rPrintln("Sinal de %f = %d", numero, sinal);

        rPrintlnEmpty();

//Funções trigonométricas
//Math.PI
        // Acesso à constante Math.PI
        double pi = mathPI;

        // Exibindo o valor de pi
        rPrintln("O valor de pi é: %f", pi);

        // Exemplo de cálculo usando pi
        double raio = 5.0;
        double area = pi * raio * raio;
        rPrintln("A área de um círculo com raio %f é: %f", raio, area);
/*
function radianos(){
return Math.PI/180
}
*/

        double graus = 45.0;
        double radianos = mathConvertToRadians(graus);

        rPrintln("%f graus é equivalente a %f radianos.", graus, radianos);
 
//Math.sin
        // Ângulo em radianos
        double anguloEmRadianos = mathPI / 4.0;

        // Calculando o seno do ângulo
        double senoDoAngulo = mathSin(anguloEmRadianos);

        // Exibindo o resultado
        rPrintln("O seno de %f radianos é: %f", anguloEmRadianos, senoDoAngulo);

//Math.cos
        // Ângulo em radianos
        anguloEmRadianos = mathPI / 3.0;

        // Calculando o cosseno do ângulo
        double cossenoDoAngulo = mathCos(anguloEmRadianos);

        // Exibindo o resultado
        rPrintln("O cosseno de %f radianos é: %f", anguloEmRadianos, cossenoDoAngulo);

//Math.tan
        // Ângulo em radianos
        anguloEmRadianos = mathPI / 6.0;

        // Calculando a tangente do ângulo
        double tangenteDoAngulo = mathTan(anguloEmRadianos);

        // Exibindo o resultado
        rPrintln("A tangente de %f radianos é: %f", anguloEmRadianos, tangenteDoAngulo);
 
//Math.asin
        // Valor para o qual queremos calcular o arco seno
        double valor = 0.5;

        // Calculando o arco seno do valor
        double arcoSeno = mathAsin(valor);

        // Exibindo o resultado em radianos
        rPrintln("O arco seno de %f é: %f radianos.", valor, arcoSeno);

//Math.acos
        // Valor para o qual queremos calcular o arco cosseno
        valor = 0.5;

        // Calculando o arco cosseno do valor
        double arcoCosseno = mathAcos(valor);

        // Exibindo o resultado em radianos
        rPrintln("O arco cosseno de %f é: %f radianos.", valor, arcoCosseno);

//Math.atan
        // Valor para o qual queremos calcular o arco tangente
        valor = 0.5;

        // Calculando o arco tangente do valor
        double arcoTangente = mathAtan(valor);

        // Exibindo o resultado em radianos
        rPrintln("O arco tangente de %f é: %f radianos.", valor, arcoTangente);
 
//Math.sinh
        // Valor para o qual queremos calcular o seno hiperbólico
        valor = 2.0;

        // Calculando o seno hiperbólico do valor
        double senoHiperbolico = mathSinh(valor);

        // Exibindo o resultado
        rPrintln("O seno hiperbólico de %f é: %f", valor, senoHiperbolico);

//Math.cosh
        // Valor para o qual queremos calcular o cosseno hiperbólico
        valor = 2.0;

        // Calculando o cosseno hiperbólico do valor
        double cossenoHiperbolico = mathCosh(valor);

        // Exibindo o resultado
        rPrintln("O cosseno hiperbólico de %f é: %f", valor, cossenoHiperbolico);

//Math.tanh
        // Valor para o qual queremos calcular a tangente hiperbólica
        valor = 2.0;

        // Calculando a tangente hiperbólica do valor
        double tangenteHiperbolica = mathTanh(valor);

        // Exibindo o resultado
        rPrintln("A tangente hiperbólica de %f é: %f", valor, tangenteHiperbolica);
 
//Math.asinh
        // Valor para o qual queremos calcular o arco seno hiperbólico
        valor = 2.0;

        // Calculando o arco seno hiperbólico do valor
        double arcoSenoHiperbolico = mathAsinh(valor);

        // Exibindo o resultado
        rPrintln("O arco seno hiperbólico de %f é: %f", valor, arcoSenoHiperbolico);

        //asinh(x) = ln(x + sqrt(x^2 + 1))
//Math.acosh
        // Valor para o qual queremos calcular o arco cosseno hiperbólico
        valor = 2.0;

        // Calculando o arco cosseno hiperbólico do valor
        double arcoCossenoHiperbolico = mathAcosh(valor);

        // Exibindo o resultado
        rPrintln("O arco cosseno hiperbólico de %f é: %f", valor, arcoCossenoHiperbolico);

        //acosh(x) = ln(x + sqrt(x^2 - 1))
//Math.atanh
        // Valor para o qual queremos calcular o arco tangente hiperbólico
        valor = 0.5;

        // Calculando o arco tangente hiperbólico do valor
        double arcoTangenteHiperbolico = mathAtanh(valor);

        // Exibindo o resultado
        rPrintln("O arco tangente hiperbólico de %f é: %f", valor, arcoTangenteHiperbolico);

        //atanh(x) = 0.5 * ln((1 + x) / (1 - x))

        rPrintlnEmpty();

//Logarítmos

//Math.log
        // Número para o qual queremos calcular o logaritmo natural
        numero = 10.0;

        // Calculando o logaritmo natural do número
        double logaritmoNatural = mathLog(numero);

        // Exibindo o resultado
        rPrintln("O logaritmo natural de %f é: %f", numero, logaritmoNatural);

//Math.log10
        // Número para o qual queremos calcular o logaritmo na base 10
        numero = 1000.0;

        // Calculando o logaritmo na base 10 do número
        double logaritmoBase10 = mathLog10(numero);

        // Exibindo o resultado
        rPrintln("O logaritmo na base 10 de %f é: %f", numero, logaritmoBase10);
 
//Math.E
        // Acesso à constante Math.E
        double constanteE = mathE;

        // Exibindo o valor da constante E
        rPrintln("O valor da constante E é: %f", constanteE);
//Math.LN2
        // Acesso à constante Math.LN2
        double LN2 = mathLN2;

        // Exibindo o valor do logaritmo natural de 2
        rPrintln("O valor do logaritmo natural de 2 é: %f", LN2);

//Math.LOG2E
        // Acesso à constante Math.LOG2E
        double LOG2E = mathLOG2E;

        // Exibindo o valor do logaritmo natural de base 2 de e
        rPrintln("O valor do logaritmo natural de base 2 de e é: %f", LOG2E);

//Math.LN10
        // Acesso à constante Math.LN10
        double LN10 = mathLN10;

        // Exibindo o valor do logaritmo natural de 10
        rPrintln("O valor do logaritmo natural de 10 é: %f", LN10);

//Math.LOG10E
        // Acesso à constante Math.LOG10E
        double LOG10E = mathLOG10E;

        // Exibindo o valor do logaritmo natural de base 10 de e
        rPrintln("O valor do logaritmo natural de base 10 de e é: %f", LOG10E);

//Math.exp
        // Expoente para o qual queremos calcular a exponenciação
        expoente = 2.0;

        // Calculando a exponenciação de e elevado ao expoente
        double resultado3 = mathExp(expoente);

        // Exibindo o resultado
        rPrintln("O resultado de e elevado a %f é: %f", expoente, resultado3);

//Math.log2
        // Número para o qual queremos calcular o logaritmo de base 2
        double numero2 = 8.0;

        // Calculando o logaritmo de base 2 do número
        double LOG2 = mathLog2(numero2);

        // Exibindo o resultado
        rPrintln("O logaritmo de base 2 de %f é: %f", numero2, LOG2);

        //log2(x) = ln(x) / ln(2)

//Math.log1p
        // Valor para o qual queremos calcular o logaritmo natural de 1 mais um
        valor = 0.5;

        // Calculando o logaritmo natural de 1 mais um
        double resultado4 = mathLog1p(valor);

        // Exibindo o resultado
        rPrintln("O logaritmo natural de 1 mais %f é: %f", valor, resultado4);

    return 0;
}
