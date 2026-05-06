#include "ouka/Megusta.prg"

PROCEDURE Main()

        rPrint("Esta eh uma mensagem de exemplo.")

        rPrintln("Esta eh uma mensagem de exemplo.")

        rPrintln()

        nome := rInput("Qual eh o seu nome? ")
        rPrintln("Olah, ", nome, "!")

        rPrintln()

        conteudo := "Este eh o conteudo que serah salvo no arquivo."
        nomeArquivo := "meu_arquivo.txt"
        rSaveFile(nomeArquivo, conteudo)

        rPrintln()

        rPrintln(rOpenFile(nomeArquivo))

        rPrintln()
        rOpenProgram("c:/java/jdk-23/bin/java.exe -jar /MeuApp/WindowJAR.jar")

        // rOpenFileWeb salva em x0001.txt via PowerShell; retorna conteúdo diretamente
        rPrintln(rOpenFileWeb("https://www.ouka.com.br/meu_arquivo.txt"))


        // strReplace
        original := "Hoje é um lindo dia!"
        substituida := strReplace(original, "lindo", "maravilhoso")
        rPrintln(substituida) // Saída: "Hoje é um maravilhoso dia!"

        // strLength
        minhaString := "Olá, mundo!"
        tamanho := strLength(minhaString)
        rPrintln("O tamanho da string é: "+ STR(tamanho)) // Saída: "O tamanho da string é: 12"

        // strSubstring
        original2 := "Isso é uma de exemplo."
        sub := strSubstring(original2, 8, 13)
        rPrintln(sub) // Saída esperada: "uma d"

        // strCharAt
        minhaString2 := "Olá, mundo!"
        primeiroCaractere := strCharAt(minhaString2,0) // Obtém o primeiro caractere 'O'
        quartoCaractere := strCharAt(minhaString2, 3) // Obtém o quarto caractere ','

        rPrintln("Primeiro caractere: " + primeiroCaractere)
        rPrintln("Quarto caractere: " + quartoCaractere)

        // strIndexOf
        minhaString3 := "Isso é um exemplo de indexOf em Java."
        indice := strIndexOf(minhaString3, "exemplo")
        rPrintln("A substring 'exemplo' começa no índice: " + STR(indice)) // Saída: "A substring 'exemplo' começa no índice: 13"

        // strLastIndexOf
        minhaString4 := "Isso é um exemplo de lastIndexOf em Java. lastIndexOf é útil para encontrar a última ocorrência de uma substring."
        indice2 := strLastIndexOf(minhaString4,"lastIndexOf")
        rPrintln("A última ocorrência de 'lastIndexOf' começa no índice: " + STR(indice2)) // Saída: "A última ocorrência de 'lastIndexOf' começa no índice: 38"

        // strToLowerCase
        minhaString5 := "Isso É Uma De Exemplo."
        emMinusculas := strToLowerCase(minhaString5)
        rPrintln(emMinusculas) // Saída: "isso é uma de exemplo."

        // strToUpperCase
        minhaString6 := "Isso É Uma De Exemplo."
        emMaiusculas := strToUpperCase(minhaString6)
        rPrintln(emMaiusculas) // Saída: "ISSO É UMA DE EXEMPLO."

        // strCompareTo
        string1 := "abacate"
        string2 := "banana"

        resultado := strCompareTo(string1, string2)

        IF resultado < 0
                rPrintln("string1 é menor que string2")
        ELSEIF resultado == 0
                rPrintln("string1 é igual a string2")
        ELSE
                rPrintln("string1 é maior que string2")
        ENDIF

        // strCompareToIgnoreCase
        string1_1 := "maçã"
        string2_1 := "MaÇÃ"

        resultado2 := strCompareToIgnoreCase(string1_1, string2_1)

        IF resultado2 < 0
                rPrintln("string1 é menor que string2 (ignorando a diferença entre maiúsculas e minúsculas)")
        ELSEIF resultado2 == 0
                rPrintln("string1 é igual a string2 (ignorando a diferença entre maiúsculas e minúsculas)")
        ELSE
                rPrintln("string1 é maior que string2 (ignorando a diferença entre maiúsculas e minúsculas)")
        ENDIF

        // strEquals
        string1_2 := "Olá, mundo!"
        string2_2 := "Olá, mundo!"
        string3_2 := "olá, Mundo!"

        saoIguais1 := strEquals(string1_2, string2_2) // Retorna true
        saoIguais2 := strEquals(string1_2, string3_2) // Retorna false

        rPrintln(saoIguais1)
        rPrintln(saoIguais2)
 
        // strEqualsIgnoreCase
        string1_3 := "Olá, mundo!"
        string2_3 := "olá, Mundo!"

        saoIguais := strEqualsIgnoreCase(string1_3, string2_3) // Retorna true

        rPrintln(saoIguais)


        rPrintln()

        Texto := ""

        Dia_do_mes := dateDay()
        Dia_da_semana := dateWeekDay()
        Mes := dateMonth()
        Ano := dateYear()

        // ---------------------------------------
        Horas := dateHour24()
        Minutos := dateMinute()
        Segundos := dateSecond()
        // ---------------------------------------
        semana := {"", "Domingo", "Segunda", "Terça", "Quarta", "Quinta", "Sexta", "Sabado"}
        Semana_atual := semana[Dia_da_semana]

        Mes2 := {"Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"}
        Mes_atual := Mes2[Mes]

        Texto += Semana_atual + ", " + str(Dia_do_mes) + " de " + Mes_atual + " de " + str(Ano)
        Texto += "\n"
        Texto += "São: " + str(Horas) + " horas, " + str(Minutos) + " minutos e " + str(Segundos) + " segundos."

        rPrintln(Texto)

        Texto := ""

        x_dia := 28
        x_mes := 4
        x_ano := 1997
        
        // ---------------------------------------
        Dia_do_mes := x_dia
        Dia_da_semana := dateSetWeekDay(x_ano, x_mes, x_dia)
        Mes := x_mes
        Ano := x_ano

        semana := {"", "Domingo", "Segunda", "Terça", "Quarta", "Quinta", "Sexta", "Sabado"}
        Semana_atual := semana[Dia_da_semana]

        Mes2 := {"Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"}
        Mes_atual := Mes2[Mes]

        Texto += Semana_atual + ", " + str(Dia_do_mes) + " de " + Mes_atual + " de " + str(Ano)

        rPrintln(Texto)

        rPrintln()

        // Array usando funções Harbour (arrAdd/arrGet/arrSize)

        frutasx := {}
        arrAddAll(frutasx, "Banana", "Melão", "Goiaba", "Morango")

        for i := 1 to arrSize(frutasx)
                rPrintln(arrGet(frutasx, i))
        next

        rPrintln()

        frutas1 := {}
        arrAdd(frutas1, "Banana")
        arrAdd(frutas1, "Melão")
        arrAdd(frutas1, "Goiaba")
        arrAdd(frutas1, "Morango")

        for i := 1 to arrSize(frutas1)
                rPrintln(arrGet(frutas1, i))
        next

        rPrintln()

        frutas2 := {}
        arrAdd(frutas2, "Banana")
        arrAdd(frutas2, "Melão")
        arrAdd(frutas2, "Goiaba")
        arrAdd(frutas2, "Morango")
        arrAddPos(frutas2, 2, "======")

        for i := 1 to arrSize(frutas2)
                rPrintln(arrGet(frutas2, i))
        next

        rPrintln()

        frutas3 := {}
        arrAdd(frutas3, "Banana")
        arrAdd(frutas3, "Melão")
        arrAdd(frutas3, "Goiaba")
        arrAdd(frutas3, "Morango")
        arrSet(frutas3, 2, "======")

        for i := 1 to arrSize(frutas3)
                rPrintln(arrGet(frutas3, i))
        next

        rPrintln()

        frutas4 := {}
        arrAdd(frutas4, "Banana")
        arrAdd(frutas4, "Melão")
        arrAdd(frutas4, "Goiaba")
        arrAdd(frutas4, "Morango")
        arrRemove(frutas4, 2)

        for i := 1 to arrSize(frutas4)
                rPrintln(arrGet(frutas4, i))
        next

        rPrintln()

        frutas5 := {}
        arrAdd(frutas5, "Banana")
        arrAdd(frutas5, "Melão")
        arrAdd(frutas5, "Goiaba")
        arrAdd(frutas5, "Morango")
        arrClear(frutas5)

        for i := 1 to arrSize(frutas5)
                rPrintln(arrGet(frutas5, i))
        next

        rPrintln()

        lista1 := {}
        arrAdd(lista1, "Jose")
        arrAdd(lista1, "Maria")
        rPrintln(arrContains(lista1, "Jose"))

        rPrintln()

        lista2 := {}
        arrAdd(lista2, "Jose")
        arrAdd(lista2, "Maria")
        arrAdd(lista2, "Joao")

        for i := 1 to arrSize(lista2)
                rPrintln(arrGet(lista2, i))
        next

        rPrintln()

        //int indexOf (Object o): retorna a posição de um objeto.

        lista3 := {}
        arrAdd(lista3, "Jose")
        arrAdd(lista3, "Maria")
        arrAdd(lista3, "João")
        rPrintln(arrIndexOf(lista3, "Maria"))

        rPrintln()

        //int lastIndexOf (Object o): retorna o último índice de um objeto.

        lista4 := {}
        arrAdd(lista4, "Jose")
        arrAdd(lista4, "Maria")
        arrAdd(lista4, "João")
        arrAdd(lista4, "Maria")
        rPrintln(arrLastIndexOf(lista4, "Maria"))

        rPrintln()

//Funções Matemáticas

//Convertendo para Numérica
//Números Inteiros
//mathint

        // Exemplo simples
        numeroString := "123456"
        numeroLong := mathInt(numeroString)
        rPrintln("Número convertido: " + str(numeroLong))

        // Tratamento de entrada inválida
        entradaInvalida := "abc"
        resultadoL := mathInt(entradaInvalida)
        IF resultadoL == 0 .AND. entradaInvalida != "0"
            rPrintln("Erro: A não é um número válido.")
        ELSE
            rPrintln("Número convertido: " + str(resultadoL))
        ENDIF

//Números Reais
//mathnum

        // Exemplo simples
        numeroString := "123.456"
        numeroDoubleD := mathNum(numeroString)
        rPrintln("Número convertido: " + str(numeroDoubleD))

        // Tratamento de entrada inválida
        entradaInvalida := "abc"
        resultadoD := mathNum(entradaInvalida)
        IF resultadoD == 0 .AND. entradaInvalida != "0"
            rPrintln("Erro: A não é um número válido.")
        ELSE
            rPrintln("Número convertido: " + str(resultadoD))
        ENDIF

//Boleanos
//mathbool

        // Exemplos simples
        trueString := "true"
        booleanTrue := mathBool(trueString)
        rPrint("Valor booleano: ")
        rPrintln((booleanTrue))

        falseString := "false"
        booleanFalse := mathBool(falseString)
        rPrint("Valor booleano: ")
        rPrintln((booleanFalse))

        // Tratamento de entrada inválida
        entradaInvalida := "abc"
        resultadoB := mathBool(entradaInvalida)
        rPrint("Valor booleano: ")
        rPrintln((resultadoB))
        // Como "abc" não é "true", o resultado será false


//Arredondando valores
//Math.floor
        numeroOriginal := 0.0
        numeroArredondado := 0.0

        numeroOriginal := 7.8
        numeroArredondado := mathFloor(numeroOriginal)

        rPrintln("Número original: " + str(numeroOriginal))
        rPrintln("Número arredondado para baixo: " + str(numeroArredondado))

//Math.ceil
        numeroOriginal := 7.2
        numeroArredondado := mathCeil(numeroOriginal)

        rPrintln("Número original: " + str(numeroOriginal))
        rPrintln("Número arredondado para cima: " + str(numeroArredondado))
//Math.round
        numeroOriginal := 7.5
        numeroArredondado := mathRound(numeroOriginal)

        rPrintln("Número original: " + str(numeroOriginal))
        rPrintln("Número arredondado: " + str(numeroArredondado))

//Digite um número com 3 casas decimais
//mathDecimalFormat
        numero := 0.0
        numero := 123.456789

        numeroFormatado := mathDecimalFormat(numero, "#.###")

        rPrintln(numeroFormatado)

//Formatar moeda
//mathNumberFormat
        numero := 1234567.89

        // Formatar o número de acordo com a localidade do Brasil
        numeroFormatadoBrasil := mathNumberFormat(numero, "pt","BR")
       
        rPrint("Brasil: ")
        rPrintln(numeroFormatadoBrasil)

//Funções matemáticas comuns
//Math.random

        // Gerar um número aleatório no intervalo [0.0, 1.0)
        numeroAleatorio := mathRandom()

        rPrintln("Número aleatório: " + str(numeroAleatorio))

        //double numeroAleatorioNoIntervalo := Math.random() * (max - min), min;
        //double numeroAleatorioIntervalo := Math.random() * (10.0 - 5.0), 5.0;
        //rPrintln("Número aleatório no intervalo: ", numeroAleatorioIntervalo)
//Math.abs

        numeroInteiro := -5
        numeroLongo := -123456789
        numeroFloat := -3.14
        numeroDouble := -2.71828

        // Calcular o valor absoluto para diferentes tipos de números
        absInt :=  mathAbs(numeroInteiro)
        absLong :=  mathAbs(numeroLongo)
        absFloat :=  mathAbs(numeroFloat)
        absDouble := mathAbs(numeroDouble)

        rPrintln("Valor absoluto de " + str(numeroInteiro) + " := " + str(absInt))
        rPrintln("Valor absoluto de " + str(numeroLongo) + " := " + str(absLong))
        rPrintln("Valor absoluto de " + str(numeroFloat) + " := " + str(absFloat))
        rPrintln("Valor absoluto de " + str(numeroDouble) + " := " + str(absDouble))

//Math.max

        numero3 := 15.5
        numero4 := 12.3

        // Encontrar o máximo entre dois números de ponto flutuante
        maximoDouble := mathMax(numero3, numero4)
        rPrintln("Máximo entre " + str(numero3) + " e " + str(numero4) + " := " + str(maximoDouble))

        // maximoEntreTres := Math.max(Math.max(numero1, numero2), numero3)
//Math.min

        numero3 := 15.5
        numero4 := 12.3

        // Encontrar o mínimo entre dois números de ponto flutuante
        minimoDouble := mathMin(numero3, numero4)
        rPrintln("Mínimo entre " + str(numero3) + " e " + str(numero4) + " := " + str(minimoDouble))

       //int minimoEntreTres := Math.min(Math.min(numero1, numero2), numero3)

//Math.max



        // Encontrar o máximo entre dois números de ponto flutuante
        maximoDouble := mathMaxArr(15.5, 12.3, 10.8, 14.6)
        rPrintln("Máximo entre 15.5, 12.3, 10.8, 14.6 := " + str(maximoDouble))

//Math.min

        // Encontrar o mínimo entre dois números de ponto flutuante
        minimoDouble := mathMinArr(15.5, 12.3, 10.8, 14.6)
        rPrintln("Mínimo entre 15.5, 12.3, 10.8, 14.6 := " + str(minimoDouble))

//Math.pow
        base := 2.0
        expoente := 3.0

        // Calcular 2^3
        resultado :=  mathPow(base, expoente)
        rPrintln("Resultado: " + str(resultado))

//Math.sqrt
        numero := 25.0

        // Calcular a raiz quadrada de 25
        raizQuadrada := mathSqrt(numero)

        rPrintln("Raiz quadrada de " + str(numero) + " := " + str(raizQuadrada))

//Math.SQRT1_2
        // Utilizando a constante Math.SQRT1_2

        //double mathSQRT1_2 := 0.7071067811865476;

        raizQuadradaDeUmMeio := mathSQRT1_2()

        rPrintln("Raiz quadrada de 1/2: " + str(raizQuadradaDeUmMeio))

//Math.SQRT2
        // Utilizando a constante Math.SQRT2

        //double mathSQRT2 := 1.4142135623730951;

        raizQuadradaDeDois := mathSQRT2()

        rPrintln("Raiz quadrada de 2: " + str(raizQuadradaDeDois))


//Math.cbrt
        numero := 27.0

        // Calcular a raiz cúbica de 27
        raizCubica := mathCbrt(numero)

        rPrintln("Raiz cúbica de " + str(numero) + " := " + str(raizCubica))

//Math.sign
        numero := -5.5

        // Obtendo o sinal do número
        sinal :=  mathSignum(numero)

        rPrintln("Sinal de " + str(numero) + " := " + str(sinal))

        rPrintln()


//Funções trigonométricas
//Math.PI
        // Acesso à constante Math.PI
        pi := mathPI()

        // Exibindo o valor de pi
        rPrintln("O valor de pi é: ", pi)

        // Exemplo de cálculo usando pi
        raio := 5.0
        area := pi * raio * raio
        rPrintln("A área de um círculo com raio " + str(raio) + " é: " + str(area))
/*
function radianos(){
return Math.PI/180
}
*/

        graus := 45.0
        radianos := mathConvertToRadians(graus)

        rPrintln(str(graus) + " graus é equivalente a " + str(radianos) + " radianos")
 
        // Ângulo em radianos
        anguloEmRadianos := mathPI() / 4.0

        // Calculando o seno do ângulo
        senoDoAngulo := mathSin(anguloEmRadianos)

        // Exibindo o resultado
        rPrintln("O seno de " + str(anguloEmRadianos) + " radianos é: " + str(senoDoAngulo))

//Math.cos
        // Ângulo em radianos
        anguloEmRadianos := mathPI() / 3.0

        // Calculando o cosseno do ângulo
        cossenoDoAngulo := mathCos(anguloEmRadianos)

        // Exibindo o resultado
        rPrintln("O cosseno de " + str(anguloEmRadianos) + " radianos é: " + str(cossenoDoAngulo))

//Math.tan
        // Ângulo em radianos
        anguloEmRadianos := mathPI() / 6.0

        // Calculando a tangente do ângulo
        tangenteDoAngulo := mathTan(anguloEmRadianos)

        // Exibindo o resultado
        rPrintln("A tangente de " + str(anguloEmRadianos) + " radianos é: " + str(tangenteDoAngulo))

//Math.asin
        // Valor para o qual queremos calcular o arco seno
        valor := 0.5

        // Calculando o arco seno do valor
        arcoSeno := mathAsin(valor)

        // Exibindo o resultado em radianos
        rPrintln("O arco seno de " + str(valor) + " é: " + str(arcoSeno) + " radianos.")

//Math.acos
        // Valor para o qual queremos calcular o arco cosseno
        valor := 0.5

        // Calculando o arco cosseno do valor
        arcoCosseno := mathAcos(valor)

        // Exibindo o resultado em radianos
        rPrintln("O arco cosseno de " + str(valor) + " é: " + str(arcoCosseno) + " radianos.")

//Math.atan
        // Valor para o qual queremos calcular o arco tangente
        valor := 0.5

        // Calculando o arco tangente do valor
        arcoTangente := mathAtan(valor)

        // Exibindo o resultado em radianos
        rPrintln("O arco tangente de " + str(valor) + " é: " + str(arcoTangente) + " radianos.")
 
//Math.sinh
        // Valor para o qual queremos calcular o seno hiperbólico
        valor := 2.0

        // Calculando o seno hiperbólico do valor
        senoHiperbolico := mathSinh(valor)

        // Exibindo o resultado
        rPrintln("O seno hiperbólico de " + str(valor) + " é: " + str(senoHiperbolico))

//Math.cosh
        // Valor para o qual queremos calcular o cosseno hiperbólico
        valor := 2.0

        // Calculando o cosseno hiperbólico do valor
        cossenoHiperbolico := mathCosh(valor)

        // Exibindo o resultado
        rPrintln("O cosseno hiperbólico de " + str(valor) + " é: " + str(cossenoHiperbolico))

//Math.tanh
        // Valor para o qual queremos calcular a tangente hiperbólica
        valor := 2.0

        // Calculando a tangente hiperbólica do valor
        tangenteHiperbolica := mathTanh(valor)

        // Exibindo o resultado
        rPrintln("A tangente hiperbólica de " + str(valor) + " é: " + str(tangenteHiperbolica))
 
//Math.asinh
        // Valor para o qual queremos calcular o arco seno hiperbólico
        valor := 2.0

        // Calculando o arco seno hiperbólico do valor
        arcoSenoHiperbolico := mathAsinh(valor)

        // Exibindo o resultado
        rPrintln("O arco seno hiperbólico de " + str(valor) + " é: " + str(arcoSenoHiperbolico))

        //asinh(x) := ln(x, sqrt(x^2, 1))
//Math.acosh
        // Valor para o qual queremos calcular o arco cosseno hiperbólico
        valor := 2.0

        // Calculando o arco cosseno hiperbólico do valor
        arcoCossenoHiperbolico := mathAcosh(valor)

        // Exibindo o resultado
        rPrintln("O arco cosseno hiperbólico de " + str(valor) + " é: " + str(arcoCossenoHiperbolico))

        //acosh(x) := ln(x, sqrt(x^2 - 1))
//Math.atanh
        // Valor para o qual queremos calcular o arco tangente hiperbólico
        valor := 0.5

        // Calculando o arco tangente hiperbólico do valor
        arcoTangenteHiperbolico := mathAtanh(valor)

        // Exibindo o resultado
        rPrintln("O arco tangente hiperbólico de " + str(valor) + " é: " + str(arcoTangenteHiperbolico))

        //atanh(x) := 0.5 * ln((1, x) / (1 - x))

        rPrintln()

//Logarítmos

//Math.log
        // Número para o qual queremos calcular o logaritmo natural
        numero := 10.0

        // Calculando o logaritmo natural do número
        logaritmoNatural := mathLog(numero)

        // Exibindo o resultado
        rPrintln("O logaritmo natural de " + str(numero) + " é: " + str(logaritmoNatural))

//Math.log10
        // Número para o qual queremos calcular o logaritmo na base 10
        numero := 1000.0

        // Calculando o logaritmo na base 10 do número
        logaritmoBase10 := mathLog10(numero)

        // Exibindo o resultado
        rPrintln("O logaritmo na base 10 de " + str(numero) + " é: " + str(logaritmoBase10))
 
//Math.E
        // Acesso à constante Math.E
        constanteE := mathE()

        // Exibindo o valor da constante E
        rPrintln("O valor da constante E é: " + str(constanteE))
//Math.LN2
        // Acesso à constante Math.LN2
        LN2 := mathLN2()

        // Exibindo o valor do logaritmo natural de 2
        rPrintln("O valor do logaritmo natural de 2 é: " + str(LN2))

//Math.LOG2E
        // Acesso à constante Math.LOG2E
        LOG2E := mathLOG2E()

        // Exibindo o valor do logaritmo natural de base 2 de e
        rPrintln("O valor do logaritmo natural de base 2 de e é: " + str(LOG2E))

//Math.LN10
        // Acesso à constante Math.LN10
        LN10 := mathLN10()

        // Exibindo o valor do logaritmo natural de 10
        rPrintln("O valor do logaritmo natural de 10 é: " + str(LN10))

//Math.LOG10E
        // Acesso à constante Math.LOG10E
        LOG10E := mathLOG10E()

        // Exibindo o valor do logaritmo natural de base 10 de e
        rPrintln("O valor do logaritmo natural de base 10 de e é: " + str(LOG10E))
 
//Math.exp
        // Expoente para o qual queremos calcular a exponenciação
        expoente := 2.0

        // Calculando a exponenciação de e elevado ao expoente
        resultado3 := mathExp(expoente)

        // Exibindo o resultado
        rPrintln("O resultado de e elevado a " + str(expoente) + " é: " + str(resultado3))

//Math.log2
        // Número para o qual queremos calcular o logaritmo de base 2
        numero2 := 8.0

        // Calculando o logaritmo de base 2 do número
        LOG2 := mathLog2(numero2)

        // Exibindo o resultado
        rPrintln("O logaritmo de base 2 de " + str(numero2) + " é: " + str(LOG2))

        //log2(x) := ln(x) / ln(2)

//Math.log1p
        // Valor para o qual queremos calcular o logaritmo natural de 1 mais um
        valor := 0.5

        // Calculando o logaritmo natural de 1 mais um
        resultado4 := mathLog1p(valor)

        // Exibindo o resultado
        rPrintln("O logaritmo natural de 1 mais " + str(valor) + " é: " + str(resultado4))

RETURN NIL