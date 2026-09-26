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
        this._lastHttpStatus = null;
    }

    // Program

    rPrint(message) {
        document.body.innerHTML += message;
    }

    rPrintln(message = "") {
        document.body.innerHTML += message + "<br>";
        console.log(message);
    }

    rInput(promptText) {
        return prompt(promptText);
    }

    rOpenFileWeb(var_url) {
        // Retorna o corpo da resposta. Use rOpenFileWebStatus() para o status HTTP.
        this._lastHttpStatus = null;
        // Nota: em JS puro no browser, não temos acesso direto a HTTP sem fetch/XMLHttpRequest
        // Esta implementação usa fetch moderno
        return fetch(var_url, {
            headers: { "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36" }
        })
        .then(response => {
            this._lastHttpStatus = response.status;
            return response.text();
        })
        .catch(error => {
            throw new Error("A URL não Funcionou: " + error.message);
        });
    }

    rOpenFileWebStatus() {
        return this._lastHttpStatus;
    }
    
    // Alias para compatibilidade com código legado (mesmo que rOpenFileWebStatus)
    rOpenFileWebStatusCode() {
        return this._lastHttpStatus;
    }

    // String

    strReplace(original, var1, var2){
        return original.replace(var1, var2);
    }

    strLength(minhaString){
        return minhaString.length;
    }

    strSubstring(original, var1, var2){
        return original.substring(var1, var2);
    }

    strCharAt(minhaString, var1){
        return minhaString.charAt(var1);
    }

    strIndexOf(minhaString, var1){
        return minhaString.indexOf(var1);
    }

    strLastIndexOf(minhaString, var1){
        return minhaString.lastIndexOf(var1);
    }

    strToLowerCase(minhaString){
        return minhaString.toLowerCase();
    }

    strToUpperCase(minhaString){
        return minhaString.toUpperCase();
    }

    strCompareTo(string1, string2){
        return string1.localeCompare(string2);
    }

    strCompareToIgnoreCase(string1, string2){
        return string1.toLowerCase().localeCompare(string2.toLowerCase());
    }

    strEquals(string1, string2){
        return string1 === string2;
    }

    strEqualsIgnoreCase(string1, string2){
        return string1.toLowerCase() === string2.toLowerCase();
    }
// =========================
    strConcat(...strings) {
        return strings.join('');
    }

    strStartsWith(minhaString, var1) {
        return minhaString.startsWith(var1);
    }

    strEndsWith(minhaString, var1) {
        return minhaString.endsWith(var1);
    }

    strIncludes(minhaString, var1) {
        return minhaString.includes(var1);
    }

    strSplit(minhaString, var1) {
        if (var1 === "") {
            throw new Error("Empty string cannot be used as a delimiter");
        }
        return minhaString.split(var1);
    }

    strPadStart(minhaString, var1, var2 = " ") {
        return minhaString.padStart(var1, var2.charAt(0));
    }

    strPadEnd(minhaString, var1, var2 = " ") {
        return minhaString.padEnd(var1, var2.charAt(0));
    }

    strRepeat(minhaString, var1) {
        return minhaString.repeat(var1);
    }

    strSearch(minhaString, regex) {
        // Busca por regex e retorna o índice da primeira ocorrência
        const match = minhaString.match(new RegExp(regex));
        return match ? match.index : -1;
    }

    strTrim(minhaString) {
        return minhaString.trim();
    }

    strTrimStart(minhaString) {
        return minhaString.replace(/^\s+/, '');
    }

    strTrimEnd(minhaString) {
        return minhaString.replace(/\s+$/, '');
    }

    strSlice(minhaString, var1, var2) {
        return minhaString.slice(var1, var2);
    }
// =========================
    // Date

    dateDay(){
        return new Date().getDate();
    }

    dateWeekDay(){
        // getDay() retorna 0=Domingo..6=Sábado
        // Queremos: 1=Domingo..7=Sábado
        return new Date().getDay() + 1;
    }

    // dateMonth() é o método oficial (1-based: 1=Janeiro..12=Dezembro)
    // getMonth() retorna 0=Janeiro..11=Dezembro, queremos 1=Janeiro..12=Dezembro
    dateMonth(){
        return new Date().getMonth() + 1;
    }
    
    // Alias para compatibilidade com código legado (mesmo que dateMonth)
    dateMouth(){
        return this.dateMonth();
    }

    dateYear(){
        return new Date().getFullYear();
    }

    dateSetWeekDay(x_ano, x_mes, x_dia){
        let d = new Date(x_ano, x_mes - 1, x_dia); // getMonth é 0-based
        return d.getDay() + 1;
    }

    dateHour24(){
        return new Date().getHours();
    }

    dateMinute(){
        return new Date().getMinutes();
    }

    dateSecond(){
        return new Date().getSeconds();
    }

    // Array

    xArrLength(lista){
        return lista.length;
    }

    arrAddAll(lista, ...valor){
        lista.push(...valor);
    }

    arrAdd(lista, valor){
        lista.push(valor);
    }

    arrAddAt(lista, i, valor){
        lista.splice(i, 0, valor);
    }

    arrSet(lista, i, valor){
        lista[i] = valor;
    }

    arrGet(lista, i){
        return lista[i];
    }

    arrSize(lista){
        return lista.length;
    }

    arrRemove(lista, i){
        lista.splice(i, 1);
    }

    arrClear(lista){
        lista.length = 0;
    }

    arrContains(lista, o){
        return lista.includes(o);
    }

    arrToArray(lista){
        return [...lista];
    }

    arrIndexOf(lista, o){
        return lista.indexOf(o);
    }

    arrLastIndexOf(lista, o){
        return lista.lastIndexOf(o);
    }

    // Math

    mathInt(numeroString){
        return parseInt(numeroString);
    }

    mathNum(numeroString){
        return parseFloat(numeroString);
    }

    mathBool(booleanString){
        return booleanString.toLowerCase() === "true";
    }

    mathFloor(numero){
        return Math.floor(numero);
    }

    mathCeil(numero){
        return Math.ceil(numero);
    }

    mathRound(numero){
        return Math.round(numero);
    }

    mathDecimalFormat(numero, pattern){
        let decimals = (pattern.split(".")[1] || "").length;
        return numero.toFixed(decimals);
    }

    mathNumberFormat(numero, language, country){
        return new Intl.NumberFormat(`${language}-${country}`).format(numero);
    }

    mathRandom(){
        return Math.random();
    }

    mathAbs(numero){
        return Math.abs(numero);
    }

    mathMax(a, b){
        return Math.max(a, b);
    }

    mathMin(a, b){
        return Math.min(a, b);
    }

    mathMaxArr(...values){
        if (values.length === 0) {
            throw new Error("mathMaxArr requires at least one argument");
        }
        return Math.max(...values);
    }

    mathMinArr(...values){
        if (values.length === 0) {
            throw new Error("mathMinArr requires at least one argument");
        }
        return Math.min(...values);
    }

    mathPow(base, expoente){
        return Math.pow(base, expoente);
    }

    mathSqrt(numero){
        return Math.sqrt(numero);
    }

    mathSQRT1_2 = Math.SQRT1_2;
    mathSQRT2 = Math.SQRT2;

    mathCbrt(numero){
        return Math.cbrt(numero);
    }

    mathSignum(numero){
        return Math.sign(numero);
    }

    mathPI = Math.PI;

    mathConvertToRadians(graus){
        return graus * (Math.PI / 180);
    }

    mathSin(x){ return Math.sin(x); }
    mathCos(x){ return Math.cos(x); }
    mathTan(x){ return Math.tan(x); }

    mathAsin(x){ return Math.asin(x); }
    mathAcos(x){ return Math.acos(x); }
    mathAtan(x){ return Math.atan(x); }

    mathSinh(x){ return Math.sinh(x); }
    mathCosh(x){ return Math.cosh(x); }
    mathTanh(x){ return Math.tanh(x); }

    mathAsinh(x){
        return Math.log(x + Math.sqrt(x*x + 1));
    }

    mathAcosh(x){
        return Math.log(x + Math.sqrt(x*x - 1));
    }

    mathAtanh(x){
        return 0.5 * Math.log((1 + x) / (1 - x));
    }

    mathLog(x){
        return Math.log(x);
    }

    mathLog10(x){
        return Math.log10(x);
    }

    mathE = Math.E;
    mathLN2 = Math.LN2;
    mathLOG2E = Math.LOG2E;
    mathLN10 = Math.LN10;
    mathLOG10E = Math.LOG10E;

    mathExp(x){
        return Math.exp(x);
    }

    mathLog2(x){
        return Math.log2(x);
    }

    mathLog1p(x){
        return Math.log1p(x);
    }
}
