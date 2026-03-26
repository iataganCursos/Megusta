<?php header('Content-Type: text/html; charset=utf-8'); ?>
<?php
/*
<?php

require "Megusta.php";

$r = new Megusta();

$r->rPrintln("Teste da biblioteca");

$nome = $r->rInput("Digite seu nome: ");
$r->rPrintln("Olá ".$nome);

echo $r->mathPow(2,8);
*/
?>
<?php

class Megusta {

    public $mathSQRT1_2 = 0.7071067811865476;
    public $mathSQRT2 = 1.4142135623730951;
    public $mathPI;
    public $mathE;
    public $mathLN2;
    public $mathLOG2E;
    public $mathLN10;
    public $mathLOG10E;

    public function __construct(){
        $this->mathPI = pi();
        $this->mathE = exp(1);
        $this->mathLN2 = log(2);
        $this->mathLOG2E = log(2) / log(exp(1));
        $this->mathLN10 = log(10);
        $this->mathLOG10E = 1 / log(10);
    }

    // Program

    public function rPrint($message){
        echo $message;
    }

    public function rPrintln($message=""){
        echo $message . "<br />" . PHP_EOL;
    }

    public function rInput($promptText){
        echo '<p>'.$promptText;
        echo " It doesn't exist.</p>";
        return "It doesn't exist.";
    }

    public function rSaveFile($nomeArquivo, $conteudo){
        if(file_put_contents($nomeArquivo,$conteudo)!==false){
            echo "Arquivo $nomeArquivo salvo com sucesso.\n";
        }else{
            echo "Erro ao salvar o arquivo.\n";
        }
    }

    public function rOpenFile($arquivo){
        if(!file_exists($arquivo)){
            echo "Erro: O arquivo nao foi encontrado.\n";
            return "";
        }
        return file_get_contents($arquivo);
    }

    public function rOpenProgram($nomePrograma){
		try {
			shell_exec($nomePrograma);
		} catch (Exception $e) {
			echo '';
		}
    }

    // String

    public function strReplace($original,$var1,$var2){
        return str_replace($var1,$var2,$original);
    }

    public function strLength($minhaString){
        return strlen($minhaString);
    }

    public function strSubstring($original,$var1,$var2){
        return substr($original,$var1,$var2-$var1);
    }

    public function strCharAt($minhaString,$var1){
        return $minhaString[$var1];
    }

    public function strIndexOf($minhaString,$var1){
        return strpos($minhaString,$var1);
    }

    public function strLastIndexOf($minhaString,$var1){
        return strrpos($minhaString,$var1);
    }

    public function strToLowerCase($minhaString){
        return strtolower($minhaString);
    }

    public function strToUpperCase($minhaString){
        return strtoupper($minhaString);
    }

    public function strCompareTo($string1,$string2){
        return strcmp($string1,$string2);
    }

    public function strCompareToIgnoreCase($string1,$string2){
        return strcasecmp($string1,$string2);
    }

    public function strEquals($string1,$string2){
        return $string1 === $string2;
    }

    public function strEqualsIgnoreCase($string1,$string2){
        return strtolower($string1) === strtolower($string2);
    }

    // Date

    public function dateDay(){
        return intval(date("d"));
    }

    public function dateWeekDay(){
        return intval(date("w"));
    }

    public function dateMouth(){
        return intval(date("m"));
    }

    public function dateYear(){
        return intval(date("Y"));
    }

    public function dateSetWeekDay($ano,$mes,$dia){
        return date("w", strtotime("$ano-$mes-$dia"));
    }

    public function dateHour24(){
        return intval(date("H"));
    }

    public function dateMinute(){
        return intval(date("i"));
    }

    public function dateSecond(){
        return intval(date("s"));
    }

    // Array

    public function xArrLength($lista){
        return count($lista);
    }

    public function arrAddAll(&$lista,...$valor){
        foreach($valor as $v){
            $lista[]=$v;
        }
    }

    public function arrAdd(&$lista,$valor){
        $lista[]=$valor;
    }

    public function arrAddIndex(&$lista,$i,$valor){
        array_splice($lista,$i,0,$valor);
    }

    public function arrSet(&$lista,$i,$valor){
        $lista[$i]=$valor;
    }

    public function arrGet($lista,$i){
        return $lista[$i];
    }

    public function arrSize($lista){
        return count($lista);
    }

    public function arrRemove(&$lista,$i){
        array_splice($lista,$i,1);
    }

    public function arrClear(&$lista){
        $lista=[];
    }

    public function arrContains($lista,$o){
        return in_array($o,$lista);
    }

    public function arrToArray($lista){
        return $lista;
    }

    public function arrIndexOf($lista,$o){
        return array_search($o,$lista);
    }

    public function arrLastIndexOf($lista,$o){
        return array_search($o,array_reverse($lista,true));
    }

    // Math

    public function mathInt($numeroString){
        return intval($numeroString);
    }

    public function mathNum($numeroString){
        return floatval($numeroString);
    }

    public function mathBool($booleanString){
        return filter_var($booleanString,FILTER_VALIDATE_BOOLEAN);
    }

    public function mathFloor($numero){
        return floor($numero);
    }

    public function mathCeil($numero){
        return ceil($numero);
    }

    public function mathRound($numero){
        return round($numero);
    }

    public function mathDecimalFormat($numero,$pattern){
        $casas = strlen(substr(strrchr($pattern,"."),1));
        return number_format($numero,$casas,'.','');
    }

    public function mathNumberFormat($numero,$language,$country){
        return number_format($numero,2,",",".");
    }

    public function mathRandom(){
        return mt_rand()/mt_getrandmax();
    }

    public function mathAbs($numero){
        return abs($numero);
    }

    public function mathMax($a,$b){
        return max($a,$b);
    }

    public function mathMin($a,$b){
        return min($a,$b);
    }

    public function mathMaxArr(...$values){
        return max($values);
    }

    public function mathMinArr(...$values){
        return min($values);
    }

    public function mathPow($base,$expoente){
        return pow($base,$expoente);
    }

    public function mathSqrt($numero){
        return sqrt($numero);
    }

    public function mathCbrt($numero){
        return pow($numero,1/3);
    }

    public function mathSignum($numero){
        return $numero <=> 0;
    }

    public function mathConvertToRadians($graus){
        return $graus * ($this->mathPI / 180.0);
    }

    public function mathSin($angulo){
        return sin($angulo);
    }

    public function mathCos($angulo){
        return cos($angulo);
    }

    public function mathTan($angulo){
        return tan($angulo);
    }

    public function mathAsin($valor){
        return asin($valor);
    }

    public function mathAcos($valor){
        return acos($valor);
    }

    public function mathAtan($valor){
        return atan($valor);
    }

    public function mathSinh($valor){
        return sinh($valor);
    }

    public function mathCosh($valor){
        return cosh($valor);
    }

    public function mathTanh($valor){
        return tanh($valor);
    }

    public function mathAsinh($x){
        return log($x + sqrt($x*$x + 1));
    }

    public function mathAcosh($x){
        return log($x + sqrt($x*$x - 1));
    }

    public function mathAtanh($x){
        return 0.5 * log((1+$x)/(1-$x));
    }

    public function mathLog($numero){
        return log($numero);
    }

    public function mathLog10($numero){
        return log10($numero);
    }

    public function mathExp($expoente){
        return exp($expoente);
    }

    public function mathLog2($numero){
        return log($numero,2);
    }

    public function mathLog1p($valor){
        return log(1+$valor);
    }

}
?>