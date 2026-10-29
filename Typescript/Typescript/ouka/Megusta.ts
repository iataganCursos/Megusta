/*
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Megusta JS</title>
</head>

<body>

<script src="ouka/megusta.js"></script>

<script>

let r = new Megusta();

r.rPrintln("Olá Mundo!");

let nome = r.rInput("Qual é o seu nome?");
r.rPrintln("Olá " + nome);

let soma = r.mathPow(2,3);
r.rPrintln("2^3 = " + soma);

</script>

</body>
</html>
*/
class Megusta {

    constructor() {
    }
    // Program
    rPrint(message: unknown = "") {
        if (typeof document !== "undefined" && document.body) {
            document.body.innerHTML += String(message);
        }
        console.log(message);
    }
    rPrintln(message: unknown = "") {
        if (typeof document !== "undefined" && document.body) {
            document.body.innerHTML += String(message) + "<br>";
        }
        console.log(message);
    }
    rInput(promptText:string = "") {
        return typeof window !== "undefined" && typeof window.prompt === "function"
            ? window.prompt(promptText)
            : "";
    }
    // String
    strReplace(original: string, search: string, replacement: string) {
        return original.replace(search, replacement);
    }
    strLength(minhaString:string) {
        return minhaString.length;
    }
    strSubstring(original:string, var1:number, var2:number) {
        return original.substring(var1, var2);
    }
    strCharAt(minhaString:string, var1:number) {
        return minhaString.charAt(var1);
    }
    strIndexOf(minhaString: string, search: string) {
        return minhaString.indexOf(search);
    }
    strLastIndexOf(minhaString: string, search: string) {
        return minhaString.lastIndexOf(search);
    }
    strToLowerCase(minhaString:string) {
        return minhaString.toLowerCase();
    }
    strToUpperCase(minhaString:string) {
        return minhaString.toUpperCase();
    }
    strCompareTo(string1:string, string2:string) {
        return string1.localeCompare(string2);
    }
    strCompareToIgnoreCase(string1:string, string2:string) {
        return string1.toLowerCase().localeCompare(string2.toLowerCase());
    }
    strEquals(string1:string, string2:string) {
        return string1 === string2;
    }
    strEqualsIgnoreCase(string1:string, string2:string) {
        return string1.toLowerCase() === string2.toLowerCase();
    }
    // =========================
    strConcat(...strings: string[]) {
        return strings.join('');
    }
    strStartsWith(minhaString: string, search: string) {
        return minhaString.startsWith(search);
    }
    strEndsWith(minhaString: string, search: string) {
        return minhaString.endsWith(search);
    }
    strIncludes(minhaString: string, search: string) {
        return minhaString.includes(search);
    }
    strSplit(minhaString:string, var1:string) {
        if (var1 === "") {
            throw new Error("Empty string cannot be used as a delimiter");
        }
        return minhaString.split(var1);
    }
    strPadStart(minhaString: string, targetLength: number, padString: string = " ") {
        return minhaString.padStart(targetLength, padString);
    }
    strPadEnd(minhaString: string, targetLength: number, padString: string = " ") {
        return minhaString.padEnd(targetLength, padString);
    }
    strRepeat(minhaString:string, var1:number) {
        return minhaString.repeat(var1);
    }
    strSearch(minhaString:string, regex:string) {
        // Busca por regex e retorna o índice da primeira ocorrência
        const match = minhaString.match(new RegExp(regex));
        return match?.index ?? -1;
    }
    strTrim(minhaString:string) {
        return minhaString.trim();
    }
    strTrimStart(minhaString:string) {
        return minhaString.replace(/^\s+/, '');
    }
    strTrimEnd(minhaString:string) {
        return minhaString.replace(/\s+$/, '');
    }
    strSlice(minhaString:string, var1:number, var2:number) {
        return minhaString.slice(var1, var2);
    }
    // =========================
    // Date
    dateDay() {
        return new Date().getDate();
    }
    dateWeekDay() {
        // getDay() retorna 0=Domingo..6=Sábado
        // Queremos: 1=Domingo..7=Sábado
        return new Date().getDay() + 1;
    }
    // dateMonth() é o método oficial (1-based: 1=Janeiro..12=Dezembro)
    // getMonth() retorna 0=Janeiro..11=Dezembro, queremos 1=Janeiro..12=Dezembro
    dateMonth() {
        return new Date().getMonth() + 1;
    }
    // Alias para compatibilidade com código legado (mesmo que dateMonth)
    dateMouth() {
        return this.dateMonth();
    }
    dateYear() {
        return new Date().getFullYear();
    }
    dateSetWeekDay(x_ano:number, x_mes:number, x_dia:number) {
        let d = new Date(x_ano, x_mes - 1, x_dia); // getMonth é 0-based
        return d.getDay() + 1;
    }
    dateHour24() {
        return new Date().getHours();
    }
    dateMinute() {
        return new Date().getMinutes();
    }
    dateSecond() {
        return new Date().getSeconds();
    }
    // Array
    xArrLength<T>(lista: T[]) {
        return lista.length;
    }
    arrAddAll<T>(lista: T[], ...valor: T[]) {
        lista.push(...valor);
    }
    arrAdd<T>(lista: T[], ...values: [value: T] | [index: number, value: T]) {
        if (values.length === 2) {
            lista.splice(values[0], 0, values[1]);
            return;
        }
        lista.push(values[0]);
    }
    arrAddAt<T>(lista: T[], i: number, valor: T) {
        lista.splice(i, 0, valor);
    }
    arrSet<T>(lista: T[], i: number, valor: T) {
        lista[i] = valor;
    }
    arrGet<T>(lista: T[], i: number) {
        return lista[i];
    }
    arrSize<T>(lista: T[]) {
        return lista.length;
    }
    arrRemove<T>(lista: T[], i: number) {
        lista.splice(i, 1);
    }
    arrClear<T>(lista: T[]) {
        lista.length = 0;
    }
    arrContains<T>(lista: T[], o: T) {
        return lista.includes(o);
    }
    arrToArray<T>(lista: T[]) {
        return [...lista];
    }
    arrIndexOf<T>(lista: T[], o: T) {
        return lista.indexOf(o);
    }
    arrLastIndexOf<T>(lista: T[], o: T) {
        return lista.lastIndexOf(o);
    }
    // Math
    mathInt(numeroString:string) {
        const value = Number.parseInt(numeroString, 10);
        if (Number.isNaN(value)) {
            throw new Error("A string não contém um número inteiro válido.");
        }
        return value;
    }
    mathNum(numeroString:string) {
        const value = Number.parseFloat(numeroString);
        if (Number.isNaN(value)) {
            throw new Error("A string não contém um número válido.");
        }
        return value;
    }
    mathBool(booleanString:string) {
        return booleanString.toLowerCase() === "true";
    }
    mathFloor(numero:number) {
        return Math.floor(numero);
    }
    mathCeil(numero:number) {
        return Math.ceil(numero);
    }
    mathRound(numero:number) {
        return Math.round(numero);
    }
    mathDecimalFormat(numero:number, pattern:string) {
        let decimals = (pattern.split(".")[1] || "").length;
        return numero.toFixed(decimals);
    }
    mathNumberFormat(numero:number, language:string, country:string) {
        return new Intl.NumberFormat(`${language}-${country}`).format(numero);
    }
    mathRandom() {
        return Math.random();
    }
    mathAbs(numero:number) {
        return Math.abs(numero);
    }
    mathMax(a:number, b:number) {
        return Math.max(a, b);
    }
    mathMin(a:number, b:number) {
        return Math.min(a, b);
    }
    mathMaxArr(...values: number[]) {
        if (values.length === 0) {
            throw new Error("mathMaxArr requires at least one argument");
        }
        return Math.max(...values);
    }
    mathMinArr(...values: number[]) {
        if (values.length === 0) {
            throw new Error("mathMinArr requires at least one argument");
        }
        return Math.min(...values);
    }
    mathPow(base:number, expoente:number) {
        return Math.pow(base, expoente);
    }
    mathSqrt(numero:number) {
        return Math.sqrt(numero);
    }
    mathSQRT1_2:number = Math.SQRT1_2;
    mathSQRT2:number = Math.SQRT2;
    mathCbrt(numero:number) {
        return Math.cbrt(numero);
    }
    mathSignum(numero:number) {
        return Math.sign(numero);
    }
    mathPI:number = Math.PI;
    mathConvertToRadians(graus:number) {
        return graus * (Math.PI / 180);
    }
    mathSin(x:number) { return Math.sin(x); }
    mathCos(x:number) { return Math.cos(x); }
    mathTan(x:number) { return Math.tan(x); }
    mathAsin(x:number) { return Math.asin(x); }
    mathAcos(x:number) { return Math.acos(x); }
    mathAtan(x:number) { return Math.atan(x); }
    mathSinh(x:number) { return Math.sinh(x); }
    mathCosh(x:number) { return Math.cosh(x); }
    mathTanh(x:number) { return Math.tanh(x); }
    mathAsinh(x:number) {
        return Math.asinh(x);
    }
    mathAcosh(x:number) {
        return Math.acosh(x);
    }
    mathAtanh(x:number) {
        return Math.atanh(x);
    }
    mathLog(x:number) {
        return Math.log(x);
    }
    mathLog10(x:number) {
        return Math.log10(x);
    }
    mathE:number = Math.E;
    mathLN2:number = Math.LN2;
    mathLOG2E:number = Math.LOG2E;
    mathLN10:number = Math.LN10;
    mathLOG10E:number = Math.LOG10E;
    mathExp(x:number) {
        return Math.exp(x);
    }
    mathLog2(x:number) {
        return Math.log2(x);
    }
    mathLog1p(x:number) {
        return Math.log1p(x);
    }
}
interface Window {
    Megusta: typeof Megusta;
}

if (typeof module !== "undefined" && module.exports) {
    module.exports = { Megusta };
} else if (typeof window !== "undefined") {
    window.Megusta = Megusta;
}