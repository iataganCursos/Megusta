import math
import random
import datetime
import locale
import subprocess

"""
import sys
sys.path.append('ouka')
import ouka.Megusta as mg
r = mg.Megusta()   # supondo que sua classe esteja em megusta.py

r.rPrint("Esta eh uma mensagem de exemplo.")
r.rPrintln("Esta eh uma mensagem de exemplo.")
r.rPrintln()

nome = r.rInput("Qual eh o seu nome? ")
r.rPrintln("Olah, " + nome + "!")
print()
"""
class Megusta:

    # -------------------------
    # Program
    # -------------------------

    def rPrint(self, message):
        print(message, end="")

    def rPrintln(self, message=""):
        print(message)

    def rInput(self, prompt):
        return input(prompt)

    def rSaveFile(self, nomeArquivo, conteudo):
        try:
            with open(nomeArquivo, "w", encoding="utf-8") as f:
                f.write(conteudo)
            print(f"Arquivo {nomeArquivo} salvo com sucesso.")
        except Exception as e:
            print("Erro ao salvar o arquivo:", e)

    def rOpenFile(self, arquivo):
        try:
            with open(arquivo, "r", encoding="utf-8") as f:
                return f.read()
        except FileNotFoundError:
            print("Erro: O arquivo nao foi encontrado.")
            return ""

    def rOpenProgram(self, comando):
        try:
            subprocess.Popen(comando, shell=True)
        except Exception as e:
            print("Erro ao tentar abrir o Programa:", e)

    # -------------------------
    # String
    # -------------------------

    def strReplace(self, original, var1, var2):
        return original.replace(var1, var2)

    def strLength(self, s):
        return len(s)

    def strSubstring(self, original, v1, v2):
        return original[v1:v2]

    def strCharAt(self, s, i):
        return s[i]

    def strIndexOf(self, s, v):
        return s.find(v)

    def strLastIndexOf(self, s, v):
        return s.rfind(v)

    def strToLowerCase(self, s):
        return s.lower()

    def strToUpperCase(self, s):
        return s.upper()

    def strCompareTo(self, s1, s2):
        return (s1 > s2) - (s1 < s2)

    def strCompareToIgnoreCase(self, s1, s2):
        return (s1.lower() > s2.lower()) - (s1.lower() < s2.lower())

    def strEquals(self, s1, s2):
        return s1 == s2

    def strEqualsIgnoreCase(self, s1, s2):
        return s1.lower() == s2.lower()

    # -------------------------
    # Date
    # -------------------------

    def dateNow(self):
        return datetime.datetime.now()

    def dateDay(self):
        return self.dateNow().day

    def dateWeekDay(self):
        return self.dateNow().weekday() + 1

    def dateMonth(self):
        return self.dateNow().month

    def dateYear(self):
        return self.dateNow().year

    def dateSetWeekDay(self, ano, mes, dia):
        return datetime.date(ano, mes, dia).weekday() + 1

    def dateHour24(self):
        return self.dateNow().hour

    def dateMinute(self):
        return self.dateNow().minute

    def dateSecond(self):
        return self.dateNow().second

    # -------------------------
    # Array (List)
    # -------------------------

    def arrAddAll(self, lista, *valores):
        lista.extend(valores)

    def arrAdd(self, lista, valor, index=None):
        if index is None:
            lista.append(valor)
        else:
            lista.insert(index, valor)

    def arrSet(self, lista, i, valor):
        lista[i] = valor

    def arrGet(self, lista, i):
        return lista[i]

    def arrSize(self, lista):
        return len(lista)

    def arrRemove(self, lista, i):
        lista.pop(i)

    def arrClear(self, lista):
        lista.clear()

    def arrContains(self, lista, o):
        return o in lista

    def arrToArray(self, lista):
        return list(lista)

    def arrIndexOf(self, lista, o):
        return lista.index(o)

    def arrLastIndexOf(self, lista, o):
        return len(lista) - 1 - lista[::-1].index(o)

    # -------------------------
    # Math
    # -------------------------

    def mathInt(self, s):
        return int(s)

    def mathNum(self, s):
        return float(s)

    def mathBool(self, s):
        return s.lower() == "true"

    def mathFloor(self, n):
        return math.floor(n)

    def mathCeil(self, n):
        return math.ceil(n)

    def mathRound(self, n):
        return round(n)

    def mathDecimalFormat(self, numero, pattern):
        casas = pattern.count("0") + pattern.count("#") - 1
        return f"{numero:.{casas}f}"

    def mathNumberFormat(self, numero, language, country):
        locale.setlocale(locale.LC_ALL, f"{language}_{country}.UTF-8")
        return locale.format_string("%f", numero, grouping=True)

    def mathRandom(self):
        return random.random()

    def mathAbs(self, n):
        return abs(n)

    def mathMax(self, a, b):
        return max(a, b)

    def mathMin(self, a, b):
        return min(a, b)

    def mathMaxArr(self, *values):
        return max(values)

    def mathMinArr(self, *values):
        return min(values)

    def mathPow(self, base, exp):
        return math.pow(base, exp)

    def mathSqrt(self, n):
        return math.sqrt(n)

    mathSQRT1_2 = math.sqrt(0.5)
    mathSQRT2 = math.sqrt(2)

    def mathCbrt(self, n):
        return n ** (1/3)

    def mathSignum(self, n):
        return (n > 0) - (n < 0)

    mathPI = math.pi

    def mathConvertToRadians(self, graus):
        return math.radians(graus)

    def mathSin(self, a):
        return math.sin(a)

    def mathCos(self, a):
        return math.cos(a)

    def mathTan(self, a):
        return math.tan(a)

    def mathAsin(self, v):
        return math.asin(v)

    def mathAcos(self, v):
        return math.acos(v)

    def mathAtan(self, v):
        return math.atan(v)

    def mathSinh(self, v):
        return math.sinh(v)

    def mathCosh(self, v):
        return math.cosh(v)

    def mathTanh(self, v):
        return math.tanh(v)

    def mathAsinh(self, x):
        return math.log(x + math.sqrt(x*x + 1))

    def mathAcosh(self, x):
        return math.log(x + math.sqrt(x*x - 1))

    def mathAtanh(self, x):
        return 0.5 * math.log((1 + x) / (1 - x))

    def mathLog(self, n):
        return math.log(n)

    def mathLog10(self, n):
        return math.log10(n)

    mathE = math.e
    mathLN2 = math.log(2)
    mathLOG2E = math.log2(math.e)
    mathLN10 = math.log(10)
    mathLOG10E = math.log10(math.e)

    def mathExp(self, exp):
        return math.exp(exp)

    def mathLog2(self, n):
        return math.log2(n)

    def mathLog1p(self, v):
        return math.log1p(v)
