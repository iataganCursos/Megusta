class Megusta {

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

    // Date

    dateDay(){
        return new Date().getDate();
    }

    dateWeekDay(){
        return new Date().getDay();
    }

    dateMouth(){
        return new Date().getMonth();
    }

    dateYear(){
        return new Date().getFullYear();
    }

    dateSetWeekDay(x_ano, x_mes, x_dia){
        let d = new Date(x_ano, x_mes, x_dia);
        return d.getDay();
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
        return Math.max(...values);
    }

    mathMinArr(...values){
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