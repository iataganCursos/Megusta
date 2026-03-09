package Megusta;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Calendar;
import java.util.Scanner;
import java.text.DecimalFormat;
import java.text.NumberFormat;
import java.util.Locale;
import java.util.List;
import java.util.Collections;

public class Megusta {
    public Megusta(){
    }

    // Program

    public void rPrint(Object message) {
        System.out.print(message);
    }
    public void rPrintln(Object message) {
        System.out.println(message);
    }
    public void rPrintln() {
        System.out.println("");
    }
    public String rInput(String prompt) {
        System.out.print(prompt);
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        return scanner.nextLine();
    }

    public void rSaveFile(String nomeArquivo, String conteudo){
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(nomeArquivo))) {
            writer.write(conteudo);
            System.out.println("Arquivo " + nomeArquivo + " salvo com sucesso.");
        } catch (IOException e) {
            System.err.println("Erro ao salvar o arquivo: " + e.getMessage());
        }
    }

    public String rOpenFile(String Arquivo){
        String linha = "";
        String linhaX = "";
        Scanner leitor = null;
        try {
            File arquivo = new File(Arquivo);
            leitor = new Scanner(arquivo);

            while (leitor.hasNextLine()){
                linha = leitor.nextLine();
                linhaX = linhaX + linha + "\n";
            }
        } catch (FileNotFoundException e) {
            System.err.println("Erro: O arquivo nao foi encontrado.");
            e.printStackTrace();
        } finally {
            if (leitor != null) {
                leitor.close();
            }
        }
        return linhaX;
    }

    public void rOpenProgram(String nomePrograma) {
        try {
            Process processo = Runtime.getRuntime().exec(nomePrograma);
        } catch (IOException e) {
            System.out.println("Erro ao tentar abrir o Programa: " + e.getMessage());
        }
    }

    // String

    public String strReplace(String original, String var1, String var2){
        return original.replace(var1, var2);
    }
    public int strLength(String minhaString){
        return minhaString.length();
    }
    public String strSubstring(String original, int var1, int var2){
        return original.substring(var1, var2);
    }
    public char strCharAt(String minhaString, int var1){
        return minhaString.charAt(var1);
    }
    public int strIndexOf(String minhaString, String var1){
        return minhaString.indexOf(var1);
    }
    public int strLastIndexOf(String minhaString, String var1){
        return minhaString.lastIndexOf(var1);
    }
    public String strToLowerCase(String minhaString){
        return minhaString.toLowerCase();
    }
    public String strToUpperCase(String minhaString){
        return minhaString.toUpperCase();
    }
    public int strCompareTo(String string1, String string2){
        return string1.compareTo(string2);
    }
    public int strCompareToIgnoreCase(String string1, String string2){
        return string1.compareToIgnoreCase(string2);
    }
    public boolean strEquals(String string1, String string2){
        return string1.equals(string2);
    }
    public boolean strEqualsIgnoreCase(String string1, String string2){
        return string1.equalsIgnoreCase(string2);
    }

    // Date

    public int dateDay(){
        Calendar DataToda = Calendar.getInstance();
        return DataToda.get(Calendar.DATE);
    }
    public int dateWeekDay(){
        Calendar DataToda = Calendar.getInstance();
        return DataToda.get(Calendar.DAY_OF_WEEK);
    }
    public int dateMouth(){
        Calendar DataToda = Calendar.getInstance();
        return DataToda.get(Calendar.MONTH);
    }
    public int dateYear(){
        Calendar DataToda = Calendar.getInstance();
        return  DataToda.get(Calendar.YEAR);
    }
    public int dateSetWeekDay(int x_ano, int x_mes, int x_dia){
        Calendar DataToda = Calendar.getInstance();
        DataToda.set(x_ano, x_mes, x_dia);
        return DataToda.get(Calendar.DAY_OF_WEEK);
    }
    public int dateHour24(){
        Calendar DataToda = Calendar.getInstance();
        return DataToda.get(Calendar.HOUR_OF_DAY);
    }
    public int dateMinute(){
        Calendar DataToda = Calendar.getInstance();
        return DataToda.get(Calendar.MINUTE);
    }
    public int dateSecond(){
        Calendar DataToda = Calendar.getInstance();
        return DataToda.get(Calendar.SECOND);
    }

    // Array

    public int xArrLength(Object[] lista){
        return lista.length;
    }
    public void arrAddAll(List<String> lista, String ... valor) {
        Collections.addAll(lista, valor);
    }
    public void arrAdd(List<String> lista, String valor) {
        lista.add(valor);
    }
    public void arrAdd(List<String> lista, int i, String valor) {
        lista.add(i, valor);
    }
    public void arrSet(List<String> lista, int i, String valor) {
        lista.set(i, valor);
    }
    public String arrGet(List<String> lista, int i) {
        return lista.get(i);
    }
    public int arrSize(List<String> lista){
        return lista.size();
    }
    public void arrRemove(List<String> lista, int i){
        lista.remove(i);
    }
    public void arrClear(List<String> lista){
        lista.clear();
    }
    public boolean arrContains(List<String> lista, String o){
        return lista.contains(o);
    }
    public Object[] arrToArray(List<String> lista){
        return lista.toArray();
    }
    public int arrIndexOf(List<String> lista, String o){
        return lista.indexOf(o);
    }
    public int arrLastIndexOf(List<String> lista, String o){
        return lista.lastIndexOf(o);
    }

    // Math

    public long mathInt(String numeroString){
        return Long.parseLong(numeroString);
    }
    public double mathNum(String numeroString){
        return Double.parseDouble(numeroString);
    }
    public boolean mathBool(String booleanString){
        return Boolean.parseBoolean(booleanString);
    }
    public double mathFloor(double numeroOriginal){
        return Math.floor(numeroOriginal);
    }
    public double mathCeil(double numeroOriginal){
        return Math.ceil(numeroOriginal);
    }
    public double mathRound(double numeroOriginal){
        return Math.round(numeroOriginal);
    }
    public String mathDecimalFormat(double numero, String pattern){
        // Criar um objeto DecimalFormat
        DecimalFormat formato = new DecimalFormat(pattern);

        // Formatar o número com 3 casas decimais
        String numeroFormatado = formato.format(numero);
        return numeroFormatado;
    }
    public String mathNumberFormat(double numero,  String language, String country){
        // Formatar o número de acordo com a localidade do Brasil
        Locale locale = new Locale(language, country);
        NumberFormat formato = NumberFormat.getInstance(locale);
        String numeroFormatado = formato.format(numero);
        return numeroFormatado;
    }
    public double mathRandom(){
        return Math.random();
    }
    public double mathAbs(double numero){
        return Math.abs(numero);
    }
    public double mathMax(double numero1, double numero2){
        return Math.max(numero1, numero2);
    }
    public double mathMin(double numero1, double numero2){
        return Math.min(numero1, numero2);
    }
    public double mathMaxArr(double ... values) {
        double max = values[0];
        for (int i = 1; i < values.length; i++) {
            if (values[i] > max) {
                max = values[i];
            }
        }
        return max;
    }
    public double mathMinArr(double ... values) {
        double min = values[0];
        for (int i = 1; i < values.length; i++) {
            if (values[i] < min) {
                min = values[i];
            }
        }
        return min;
    }
    public double mathPow(double base, double expoente){
        return Math.pow(base, expoente);
    }
    public double mathSqrt(double numero){
        return Math.sqrt(numero);
    }
    public double mathSQRT1_2 = 0.7071067811865476;
    public double mathSQRT2 = 1.4142135623730951;
    public double mathCbrt(double numero){
        return Math.cbrt(numero);
    }
    public double mathSignum(double numero){
        return Math.signum(numero);
    }
    public double mathPI = Math.PI;
    // Função para converter graus para radianos
    public double mathConvertToRadians(double graus) {
        return graus * (Math.PI / 180.0);
    }
    public double mathSin(double angulo){
        return Math.sin(angulo);
    }
    public double mathCos(double angulo){
        return Math.cos(angulo);
    }
    public double mathTan(double angulo){
        return Math.tan(angulo);
    }
    public double mathAsin(double valor){
        return Math.asin(valor);
    }
    public double mathAcos(double valor){
        return Math.acos(valor);
    }
    public double mathAtan(double valor){
        return Math.atan(valor);
    }
    public double mathSinh(double valor){
        return Math.sinh(valor);
    }
    public double mathCosh(double valor){
        return Math.cosh(valor);
    }
    public double mathTanh(double valor){
        return Math.tanh(valor);
    }
    // Função para calcular o arco seno hiperbólico
    public double mathAsinh(double x) {
        return Math.log(x + Math.sqrt(x*x + 1));
    }
    // Função para calcular o arco cosseno hiperbólico
    public double mathAcosh(double x) {
        return Math.log(x + Math.sqrt(x*x - 1));
    }
    // Função para calcular o arco tangente hiperbólico
    public double mathAtanh(double x) {
        return 0.5 * Math.log((1 + x) / (1 - x));
    }
    public double mathLog(double numero){
        return Math.log(numero);
    }
    public double mathLog10(double numero){
        return Math.log10(numero);
    }
    public double mathE = Math.E;
    public double mathLN2 = Math.log(2.0);
    public double mathLOG2E = Math.log(2.0) / Math.log(Math.exp(1.0));
    public double mathLN10 = Math.log(10.0);
    public double mathLOG10E = 1.0 / Math.log(10.0);
    public double mathExp(double expoente){
        return Math.exp(expoente);
    }
    public double mathLog2(double numero){
        return Math.log(numero) / Math.log(2);
    }
    public double mathLog1p(double valor){
        return Math.log1p(valor);
    }
}
