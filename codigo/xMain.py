import sys
sys.path.append('ouka')
import ouka.Megusta as mg
r = mg.Megusta()
r.rPrint("Esta é uma mensagem de exemplo.")

r.rPrintln("Esta é uma mensagem de exemplo.")

r.rPrintln()

nome = r.rInput("Qual é o seu nome? ")
r.rPrintln("Olá, " + nome + "!")

r.rPrintln()

conteudo = "Este é o conteúdo que será salvo no arquivo."
nomeArquivo = "meu_arquivo.txt"
r.rSaveFile(nomeArquivo, conteudo)

r.rPrintln()

r.rPrintln(r.rOpenFile(nomeArquivo))

r.rPrintln()
r.rOpenProgram("c:/java/jdk-23/bin/java.exe -jar /MeuApp/WindowJAR.jar")
r.rPrintln()

r.rPrintln(r.rOpenFileWeb("https://www.ouka.com.br/meu_arquivo.txt"))
r.rPrintln()

# strReplace
original = "Hoje é um lindo dia!"
substituida = r.strReplace(original, "lindo", "maravilhoso")
r.rPrintln(substituida) # Saída: "Hoje é um maravilhoso dia!"

# strLength
minhaString= "Olá, mundo!"
tamanho = r.strLength(minhaString)
r.rPrintln("O tamanho da string é: " + str(tamanho)) # Saída: "O tamanho da string é: 12"
 
# strSubstring
original2 = "Isso é uma de exemplo."
sub = r.strSubstring(original2, 8, 13)
r.rPrintln(sub) # Saída: "uma d"

# strCharAt
minhaString2 = "Olá, mundo!"
primeiroCaractere = r.strCharAt(minhaString2,0) # Obtém o primeiro caractere 'O'
quartoCaractere = r.strCharAt(minhaString2, 3) # Obtém o quarto caractere ','

r.rPrintln("Primeiro caractere: " + primeiroCaractere)
r.rPrintln("Quarto caractere: " + quartoCaractere)

# strIndexOf
minhaString3 = "Isso é um exemplo de indexOf em Java."
indice = r.strIndexOf(minhaString3, "exemplo")
r.rPrintln("A substring 'exemplo' começa no índice: " + str(indice)) # Saída: "A substring 'exemplo' começa no índice: 13"

# strLastIndexOf
minhaString4 = "Isso é um exemplo de lastIndexOf em Java. lastIndexOf é útil para encontrar a última ocorrência de uma substring."
indice2 = r.strLastIndexOf(minhaString4,"lastIndexOf")
r.rPrintln("A última ocorrência de 'lastIndexOf' começa no índice: " + str(indice2)) # Saída: "A última ocorrência de 'lastIndexOf' começa no índice: 38"
 
# strToLowerCase
minhaString5 = "Isso É Uma De Exemplo."
emMinusculas = r.strToLowerCase(minhaString5)
r.rPrintln(emMinusculas) # Saída: "isso é uma de exemplo."

# strToUpperCase
minhaString6 = "Isso É Uma De Exemplo."
emMaiusculas = r.strToUpperCase(minhaString6)
r.rPrintln(emMaiusculas) # Saída: "ISSO É UMA DE EXEMPLO."
 
# strCompareTo
string1 = "abacate"
string2 = "banana"

resultado = r.strCompareTo(string1, string2)

if resultado < 0:
        r.rPrintln("string1 é menor que string2")
elif resultado == 0:
        r.rPrintln("string1 é igual a string2")
else :
        r.rPrintln("string1 é maior que string2")


# strCompareToIgnoreCase
string1_1 = "maçã"
string2_1 = "MaÇÃ"

resultado2 = r.strCompareToIgnoreCase(string1_1, string2_1)

if resultado2 < 0:
        r.rPrintln("string1 é menor que string2 (ignorando a diferença entre maiúsculas e minúsculas)")
elif resultado2 == 0:
        r.rPrintln("string1 é igual a string2 (ignorando a diferença entre maiúsculas e minúsculas)")
else :
        r.rPrintln("string1 é maior que string2 (ignorando a diferença entre maiúsculas e minúsculas)")

# strEquals
string1_2 = "Olá, mundo!"
string2_2 = "Olá, mundo!"
string3_2 = "olá, Mundo!"

saoIguais1 = r.strEquals(string1_2, string2_2) # Retorna true
saoIguais2 = r.strEquals(string1_2, string3_2) # Retorna false

r.rPrintln(saoIguais1)
r.rPrintln(saoIguais2)
 
# strEqualsIgnoreCase
string1_3 = "Olá, mundo!"
string2_3 = "olá, Mundo!"

saoIguais = r.strEqualsIgnoreCase(string1_3, string2_3) # Retorna true

r.rPrintln(saoIguais)


r.rPrintln()

Texto = ""

Dia_do_mes = r.dateDay()
Dia_da_semana = r.dateWeekDay()
Mes = r.dateMonth()
Ano = r.dateYear()

# ---------------------------------------
Horas = r.dateHour24()
Minutos = r.dateMinute()
Segundos = r.dateSecond()
# ---------------------------------------

semana = ["", "", "", "", "", "", "", ""]
semana[0] = ""
semana[1] = "Domingo"
semana[2] = "Segunda"
semana[3] = "Terça"
semana[4] = "Quarta"
semana[5] = "Quinta"
semana[6] = "Sexta"
semana[7] = "Sábado"
Semana_atual = semana[Dia_da_semana]
#-------------------------
Mes2 = ["", "", "", "", "", "", "", "", "", "", "", "", ""]
Mes2[1] = "Janeiro"
Mes2[2] = "Fevereiro"
Mes2[3] = "Março"
Mes2[4] = "Abril"
Mes2[5] = "Maio"
Mes2[6] = "Junho"
Mes2[7] = "Julho"
Mes2[8] = "Agosto"
Mes2[9] = "Setembro"
Mes2[10] = "Outubro"
Mes2[11] = "Novembro"
Mes2[12] = "Dezembro"
Mes_atual = Mes2[Mes]
Texto += Semana_atual + ", " + str(Dia_do_mes) + " de " + Mes_atual + " de " + str(Ano)
Texto += "\n"
Texto += "São: " + str(Horas) + " horas, " + str(Minutos) + " minutos e " + str(Segundos) + " segundos."

r.rPrintln(Texto)

Texto = ""

x_dia = 28
x_mes = 4
x_ano = 1997

# ---------------------------------------
Dia_do_mes = x_dia
Dia_da_semana = r.dateSetWeekDay(x_ano, x_mes, x_dia)
Mes = x_mes
Ano = x_ano
semana = ["", "", "", "", "", "", "", ""]
semana[0] = ""
semana[1] = "Domingo"
semana[2] = "Segunda"
semana[3] = "Terça"
semana[4] = "Quarta"
semana[5] = "Quinta"
semana[6] = "Sexta"
semana[7] = "Sábado"
Semana_atual = semana[Dia_da_semana]
#-------------------------
Mes2 = ["", "", "", "", "", "", "", "", "", "", "", "", ""]
Mes2[1] = "Janeiro"
Mes2[2] = "Fevereiro"
Mes2[3] = "Março"
Mes2[4] = "Abril"
Mes2[5] = "Maio"
Mes2[6] = "Junho"
Mes2[7] = "Julho"
Mes2[8] = "Agosto"
Mes2[9] = "Setembro"
Mes2[10] = "Outubro"
Mes2[11] = "Novembro"
Mes2[12] = "Dezembro"
Mes_atual = Mes2[Mes]
Texto += Semana_atual + ", " + str(Dia_do_mes) + " de " + Mes_atual + " de " + str(Ano)

r.rPrintln(Texto)

r.rPrintln()

#ArrayList
#arrAllAdd(Object o): adiciona à coleção o objeto passado como argumento.

frutasx = []

# adiciona itens na lista
r.arrAddAll(frutasx, "Banana", "Melão", "Goiaba", "Morango")

# exibe os valores da lista
for i in range(r.arrSize(frutasx)):
    r.rPrintln(r.arrGet(frutasx, i))

r.rPrintln()

#add(Object o): adiciona à coleção o objeto passado como argumento.
#size(): retorna o tamanho da coleção
#get(index): retorna um objeto dada uma posição.

frutas1 = []

# adiciona itens na lista
r.arrAdd(frutas1, "Banana")
r.arrAdd(frutas1, "Melão")
r.arrAdd(frutas1, "Goiaba")
r.arrAdd(frutas1, "Morango")

# exibe os valores da lista
for i in range(r.arrSize(frutas1)):
    r.rPrintln(r.arrGet(frutas1, i))

r.rPrintln()

#add(index, Object element): adiciona um objeto dada uma posição.

frutas2 = []

# adiciona itens na lista
r.arrAdd(frutas2, "Banana")
r.arrAdd(frutas2, "Melão")
r.arrAdd(frutas2, "Goiaba")
r.arrAdd(frutas2, "Morango")

r.arrAdd(frutas2, "======", 1)

# exibe os valores da lista
for i in range(r.arrSize(frutas2)):
    r.rPrintln(r.arrGet(frutas2, i))

r.rPrintln()

#set(index, Object element): edita um objeto dada uma posição.

frutas3 = []

# adiciona itens na lista
r.arrAdd(frutas3, "Banana")
r.arrAdd(frutas3, "Melão")
r.arrAdd(frutas3, "Goiaba")
r.arrAdd(frutas3, "Morango")

r.arrSet(frutas3, 1, "======")

# exibe os valores da lista
for i in range(r.arrSize(frutas3)):
    r.rPrintln(r.arrGet(frutas3, i))

r.rPrintln()

#remove(index): remove um objeto dada sua posição.

frutas4 = []

# adiciona itens na lista
r.arrAdd(frutas4, "Banana")
r.arrAdd(frutas4, "Melão")
r.arrAdd(frutas4, "Goiaba")
r.arrAdd(frutas4, "Morango")

r.arrRemove(frutas4, 1)

# exibe os valores da lista
for i in range(r.arrSize(frutas4)):
    r.rPrintln(r.arrGet(frutas4, i))

r.rPrintln()

#clear(): apaga todo o conteúdo da coleção.

frutas5 = []

# adiciona itens na lista
r.arrAdd(frutas5, "Banana")
r.arrAdd(frutas5, "Melão")
r.arrAdd(frutas5, "Goiaba")
r.arrAdd(frutas5, "Morango")

r.arrClear(frutas5)

# exibe os valores da lista
for i in range(r.arrSize(frutas5)):
    r.rPrintln(r.arrGet(frutas5, i))

r.rPrintln()

#contains(Object o): verifica se o objeto passado como argumento existe na coleção.

lista1 = []
r.arrAdd(lista1, "Jose")
r.arrAdd(lista1, "Maria")
r.rPrintln(r.arrContains(lista1, "Jose")) # True

r.rPrintln()

#Object[ ] toArray(): converte os elementos da coleção em um array (rápidos acesso aos elementos).

lista2 = []
r.arrAdd(lista2, "Jose")
r.arrAdd(lista2, "Maria")
r.arrAdd(lista2, "Joao")
elementos2 = r.arrToArray(lista2)
r.rPrintln(elementos2)

r.rPrintln()

#indexOf (Object o): retorna a posição de um objeto.

lista3 = []
r.arrAdd(lista3, "Jose")
r.arrAdd(lista3, "Maria")
r.arrAdd(lista3, "João")
r.rPrintln(r.arrIndexOf(lista3, "Maria")) #1

r.rPrintln()

#lastIndexOf (Object o): retorna o último índice de um objeto.

lista4 = []
r.arrAdd(lista4, "Jose")
r.arrAdd(lista4, "Maria")
r.arrAdd(lista4, "João")
r.arrAdd(lista4, "Maria")
r.rPrintln(r.arrLastIndexOf(lista4, "Maria")) #3

r.rPrintln()
#Funções Matemáticas

#Convertendo para Numérica
#Números Inteiros
#mathint
# Exemplo simples
numeroString= "123456"
numeroLong= r.mathInt(numeroString)
r.rPrintln("Número convertido: " + str(numeroLong))

# Tratamento de exceção para entrada inválida
entradaInvalida = "abc"
try:
    resultadoL = r.mathInt(entradaInvalida)
    r.rPrintln("Número convertido: " + str(resultadoL))
except:
    r.rPrintln("Erro: A não é um número válido.")

#Números Reais
#mathnum
# Exemplo simples
numero= "123.456"
numeroDoubleD = r.mathNum(numeroString)
r.rPrintln("Número convertido: " + str(numeroDoubleD))

# Tratamento de exceção para entrada inválida
entradaInvalida = "abc"
try:
    resultadoD = r.mathNum(entradaInvalida)
    r.rPrintln("Número convertido: " + str(resultadoD))
except:
    r.rPrintln("Erro: A não é um número válido.")


#Boleanos
#mathbool
# Exemplos simples
trueString= "true"
booleanTrue = r.mathBool(trueString)
r.rPrintln("Valor booleano: " + str(booleanTrue))

falseString= "false"
booleanFalse = r.mathBool(falseString)
r.rPrintln("Valor booleano: " + str(booleanFalse))

# Tratamento de entrada inválida
entradaInvalida = "abc"
resultadoB = r.mathBool(entradaInvalida)
r.rPrintln("Valor booleano: " + str(resultadoB))
# Como "abc" não é "true", o resultado será false
#Arredondando valores
#Math.floor
numeroOriginal = 0.0
numeroArredondado = 0.0

numeroOriginal = 7.8
numeroArredondado = r.mathFloor(numeroOriginal)

r.rPrintln("Número original: " + str(numeroOriginal))
r.rPrintln("Número arredondado para baixo: " + str(numeroArredondado))
#Math.ceil
numeroOriginal = 7.2
numeroArredondado = r.mathCeil(numeroOriginal)

r.rPrintln("Número original: " + str(numeroOriginal))
r.rPrintln("Número arredondado para cima: " + str(numeroArredondado))
#Math.round
numeroOriginal = 7.5
numeroArredondado = r.mathRound(numeroOriginal)

r.rPrintln("Número original: " + str(numeroOriginal))
r.rPrintln("Número arredondado: " + str(numeroArredondado))

#Digite um número com 3 casas decimais
#mathDecimalFormat
numero = 0.0
numero = 123.456789

numeroFormatado = r.mathDecimalFormat(numero, "#.###")

r.rPrintln(numeroFormatado)

#Formatar moeda
#mathNumberFormat
numero = 1234567.89

# Formatar o número de acordo com a localidade do Brasil
numeroFormatadoBrasil = r.mathNumberFormat(numero, "pt","BR")
       
r.rPrintln("Brasil: " + numeroFormatadoBrasil)

#Funções matemáticas comuns
#Math.random

# Gerar um número aleatório no intervalo [0.0, 1.0)
numeroAleatorio = r.mathRandom()

r.rPrintln("Número aleatório: " + str(numeroAleatorio))

#numeroAleatorioNoIntervalo = Math.random() * (max - min) + min
#numeroAleatorioIntervalo = Math.random() * (10.0 - 5.0) + 5.0
#r.rPrintln("Número aleatório no intervalo: " + numeroAleatorioIntervalo)
#Math.abs

numeroInteiro = -5
numeroLongo = -123456789
numeroFloat= -3.14
numeroDouble= -2.71828

# Calcular o valor absoluto para diferentes tipos de números
absInt = r.mathAbs(numeroInteiro)
absLong= r.mathAbs(numeroLongo)
absFloat= r.mathAbs(numeroFloat)
absDouble= r.mathAbs(numeroDouble)

r.rPrintln("Valor absoluto de " + str(numeroInteiro) + " = " + str(absInt))
r.rPrintln("Valor absoluto de " + str(numeroLongo) + " = " + str(absLong))
r.rPrintln("Valor absoluto de " + str(numeroFloat) + " = " + str(absFloat))
r.rPrintln("Valor absoluto de " + str(numeroDouble) + " = " + str(absDouble))

#Math.max

numero3 = 15.5
numero4 = 12.3

# Encontrar o máximo entre dois números de ponto flutuante
maximoDouble= r.mathMax(numero3, numero4)
r.rPrintln("Máximo entre " + str(numero3) + " e " + str(numero4) + " = " + str(maximoDouble))

# maximoEntreTres = Math.max(Math.max(numero1, numero2), numero3)
#Math.min

numero3 = 15.5
numero4 = 12.3

# Encontrar o mínimo entre dois números de ponto flutuante
minimoDouble= r.mathMin(numero3, numero4)
r.rPrintln("Mínimo entre " + str(numero3) + " e " + str(numero4) + " = " + str(minimoDouble))

       #minimoEntreTres = Math.min(Math.min(numero1, numero2), numero3)

#Math.max

# Encontrar o máximo entre dois números de ponto flutuante
maximoDouble= r.mathMaxArr(15.5, 12.3, 10.8, 14.6)
r.rPrintln("Máximo entre 15.5, 12.3, 10.8, 14.6 = " + str(maximoDouble))

#Math.min

# Encontrar o mínimo entre dois números de ponto flutuante
minimoDouble= r.mathMinArr(15.5, 12.3, 10.8, 14.6)
r.rPrintln("Mínimo entre 15.5, 12.3, 10.8, 14.6 = " + str(minimoDouble))

#Math.pow
base = 2.0
expoente = 3.0

# Calcular 2^3
resultado = r.mathPow(base, expoente)
r.rPrintln("Resultado: " + str(resultado))

#Math.sqrt
numero = 25.0

# Calcular a raiz quadrada de 25
raizQuadrada = r.mathSqrt(numero)

r.rPrintln("Raiz quadrada de " + str(numero) + " = " + str(raizQuadrada))

#Math.SQRT1_2
# Utilizando a constante Math.SQRT1_2

#mathSQRT1_2 = 0.7071067811865476

raizQuadradaDeUmMeio = r.mathSQRT1_2

r.rPrintln("Raiz quadrada de 1/2: " + str(raizQuadradaDeUmMeio))

#Math.SQRT2
# Utilizando a constante Math.SQRT2

#mathSQRT2 = 1.4142135623730951

raizQuadradaDeDois = r.mathSQRT2

r.rPrintln("Raiz quadrada de 2: " + str(raizQuadradaDeDois))

 
#Math.cbrt
numero = 27.0

# Calcular a raiz cúbica de 27
raizCubica = r.mathCbrt(numero)

r.rPrintln("Raiz cúbica de " + str(numero) + " = " + str(raizCubica))

#Math.sign
numero = -5.5

# Obtendo o sinal do número
sinal = r.mathSignum(numero)

r.rPrintln("Sinal de " + str(numero) + " = " + str(sinal))

r.rPrintln()

#Funções trigonométricas
#Math.PI
# Acesso à constante Math.PI
pi = r.mathPI

# Exibindo o valor de pi
r.rPrintln("O valor de pi é: " + str(pi))

# Exemplo de cálculo usando pi
raio = 5.0
area = pi * raio * raio
r.rPrintln("A área de um círculo com raio " + str(raio) + " é: " + str(area))
'''
function radianos():
return Math.PI/180
}
'''

graus = 45.0
radianos = r.mathConvertToRadians(graus)

r.rPrintln(str(graus) + " graus é equivalente a " + str(radianos) + " radianos.")
 
#Math.sin
# Ângulo em radianos
anguloEmRadianos = r.mathPI / 4.0

# Calculando o seno do ângulo
senoDoAngulo = r.mathSin(anguloEmRadianos)

# Exibindo o resultado
r.rPrintln("O seno de " + str(anguloEmRadianos) + " radianos é: " + str(senoDoAngulo))

#Math.cos
# Ângulo em radianos
anguloEmRadianos = r.mathPI / 3.0

# Calculando o cosseno do ângulo
cossenoDoAngulo = r.mathCos(anguloEmRadianos)

# Exibindo o resultado
r.rPrintln("O cosseno de " + str(anguloEmRadianos) + " radianos é: " + str(cossenoDoAngulo))

#Math.tan
# Ângulo em radianos
anguloEmRadianos = r.mathPI / 6.0

# Calculando a tangente do ângulo
tangenteDoAngulo = r.mathTan(anguloEmRadianos)

# Exibindo o resultado
r.rPrintln("A tangente de " + str(anguloEmRadianos) + " radianos é: " + str(tangenteDoAngulo))
 
#Math.asin
# Valor para o qual queremos calcular o arco seno
valor = 0.5

# Calculando o arco seno do valor
arcoSeno = r.mathAsin(valor)

# Exibindo o resultado em radianos
r.rPrintln("O arco seno de " + str(valor) + " é: " + str(arcoSeno) + " radianos.")

#Math.acos
# Valor para o qual queremos calcular o arco cosseno
valor = 0.5

# Calculando o arco cosseno do valor
arcoCosseno = r.mathAcos(valor)

# Exibindo o resultado em radianos
r.rPrintln("O arco cosseno de " + str(valor) + " é: " + str(arcoCosseno) + " radianos.")

#Math.atan
# Valor para o qual queremos calcular o arco tangente
valor = 0.5

# Calculando o arco tangente do valor
arcoTangente = r.mathAtan(valor)

# Exibindo o resultado em radianos
r.rPrintln("O arco tangente de " + str(valor) + " é: " + str(arcoTangente) + " radianos.")
 
#Math.sinh
# Valor para o qual queremos calcular o seno hiperbólico
valor = 2.0

# Calculando o seno hiperbólico do valor
senoHiperbolico = r.mathSinh(valor)

# Exibindo o resultado
r.rPrintln("O seno hiperbólico de " + str(valor) + " é: " + str(senoHiperbolico))

#Math.cosh
# Valor para o qual queremos calcular o cosseno hiperbólico
valor = 2.0

# Calculando o cosseno hiperbólico do valor
cossenoHiperbolico = r.mathCosh(valor)

# Exibindo o resultado
r.rPrintln("O cosseno hiperbólico de " + str(valor) + " é: " + str(cossenoHiperbolico))

#Math.tanh
# Valor para o qual queremos calcular a tangente hiperbólica
valor = 2.0

# Calculando a tangente hiperbólica do valor
tangenteHiperbolica = r.mathTanh(valor)

# Exibindo o resultado
r.rPrintln("A tangente hiperbólica de " + str(valor) + " é: " + str(tangenteHiperbolica))
 
#Math.asinh
# Valor para o qual queremos calcular o arco seno hiperbólico
valor = 2.0

# Calculando o arco seno hiperbólico do valor
arcoSenoHiperbolico = r.mathAsinh(valor)

# Exibindo o resultado
r.rPrintln("O arco seno hiperbólico de " + str(valor) + " é: " + str(arcoSenoHiperbolico))

#asinh(x) = ln(x + sqrt(x^2 + 1))
#Math.acosh
# Valor para o qual queremos calcular o arco cosseno hiperbólico
valor = 2.0

# Calculando o arco cosseno hiperbólico do valor
arcoCossenoHiperbolico = r.mathAcosh(valor)

# Exibindo o resultado
r.rPrintln("O arco cosseno hiperbólico de " + str(valor) + " é: " + str(arcoCossenoHiperbolico))

#acosh(x) = ln(x + sqrt(x^2 - 1))
#Math.atanh
# Valor para o qual queremos calcular o arco tangente hiperbólico
valor = 0.5

# Calculando o arco tangente hiperbólico do valor
arcoTangenteHiperbolico = r.mathAtanh(valor)

# Exibindo o resultado
r.rPrintln("O arco tangente hiperbólico de " + str(valor) + " é: " + str(arcoTangenteHiperbolico))

#atanh(x) = 0.5 * ln((1 + x) / (1 - x))

r.rPrintln()

#Logarítmos

#Math.log
# Número para o qual queremos calcular o logaritmo natural
numero = 10.0

# Calculando o logaritmo natural do número
logaritmoNatural = r.mathLog(numero)

# Exibindo o resultado
r.rPrintln("O logaritmo natural de " + str(numero) + " é: " + str(logaritmoNatural))

#Math.log10
# Número para o qual queremos calcular o logaritmo na base 10
numero = 1000.0

# Calculando o logaritmo na base 10 do número
logaritmoBase10 = r.mathLog10(numero)

# Exibindo o resultado
r.rPrintln("O logaritmo na base 10 de " + str(numero) + " é: " + str(logaritmoBase10))
 
#Math.E
# Acesso à constante Math.E
constanteE = r.mathE

# Exibindo o valor da constante E
r.rPrintln("O valor da constante E é: " + str(constanteE))
#Math.LN2
# Acesso à constante Math.LN2
LN2 = r.mathLN2

# Exibindo o valor do logaritmo natural de 2
r.rPrintln("O valor do logaritmo natural de 2 é: " + str(LN2))

#Math.LOG2E
# Acesso à constante Math.LOG2E
LOG2E = r.mathLOG2E

# Exibindo o valor do logaritmo natural de base 2 de e
r.rPrintln("O valor do logaritmo natural de base 2 de e é: " + str(LOG2E))

#Math.LN10
# Acesso à constante Math.LN10
LN10 = r.mathLN10

# Exibindo o valor do logaritmo natural de 10
r.rPrintln("O valor do logaritmo natural de 10 é: " + str(LN10))

#Math.LOG10E
# Acesso à constante Math.LOG10E
LOG10E = r.mathLOG10E

# Exibindo o valor do logaritmo natural de base 10 de e
r.rPrintln("O valor do logaritmo natural de base 10 de e é: " + str(LOG10E))
 
#Math.exp
# Expoente para o qual queremos calcular a exponenciação
expoente = 2.0

# Calculando a exponenciação de e elevado ao expoente
resultado3 = r.mathExp(expoente)

# Exibindo o resultado
r.rPrintln("O resultado de e elevado a " + str(expoente) + " é: " + str(resultado3))

#Math.log2
# Número para o qual queremos calcular o logaritmo de base 2
numero2 = 8.0

# Calculando o logaritmo de base 2 do número
LOG2 = r.mathLog2(numero2)

# Exibindo o resultado
r.rPrintln("O logaritmo de base 2 de " + str(numero2) + " é: " + str(LOG2))

#log2(x) = ln(x) / ln(2)

#Math.log1p
# Valor para o qual queremos calcular o logaritmo natural de 1 mais um
valor = 0.5

# Calculando o logaritmo natural de 1 mais um
resultado4 = r.mathLog1p(valor)

# Exibindo o resultado
r.rPrintln("O logaritmo natural de 1 mais " + str(valor) + " é: " + str(resultado4))
