<?php header('Content-Type: text/html; charset=utf-8'); ?>
<?php
/*
<?php

require "ouka/oMegusta.php";

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
    private $lastHttpStatus = null;

    // -------------------------
    // Program
    // -------------------------

    public function rOpenFileWeb($var_url) {
        $this->lastHttpStatus = null;
        try {
            // Criar contexto com header
            $options = [
                "http" => [
                    "header" => "User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36\r\n"
                ]
            ];

            $context = stream_context_create($options);

            // Enviar requisição
            $response = @file_get_contents($var_url, false, $context);

            if ($response === false) {
                throw new Exception("Falha na requisição");
            }

            // Capturar status HTTP
            $status = null;
            if (isset($http_response_header)) {
                preg_match('{HTTP\/\S*\s(\d{3})}', $http_response_header[0], $match);
                $status = (int)($match[1] ?? null);
            }

            $this->lastHttpStatus = $status;
            return $response . PHP_EOL;

        } catch (Exception $error) {
            throw new RuntimeException("A URL não Funcionou: " . $error->getMessage());
        }
    }

    public function rOpenFileWebStatus() {
        return $this->lastHttpStatus;
    }

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
        echo $promptText;
        // Lê a entrada do usuário (CLI) ou formulário (web)
        if (php_sapi_name() === 'cli') {
            $input = trim(fgets(STDIN));
        } else {
            // Modo web: tenta obter do POST/GET
            $input = trim($_POST['megusta_input'] ?? $_GET['megusta_input'] ?? '');
        }
        return $input;
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
        // shell_exec não lança exceptions, try/catch é inútil
        // Executa o comando (bloqueante)
        shell_exec($nomePrograma);
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
        $result = strpos($minhaString,$var1);
        // strpos retorna false quando não encontrado, converter para -1
        return $result === false ? -1 : $result;
    }

    public function strLastIndexOf($minhaString,$var1){
        $result = strrpos($minhaString,$var1);
        return $result === false ? -1 : $result;
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
// =========================

    function strConcat(...$strings) {
        $resultado = "";
        foreach ($strings as $str) {
            $resultado .= $str;
        }
        return $resultado;
    }

    function strStartsWith($minhaString, $var1) {
        return str_starts_with($minhaString, $var1);
    }

    function strEndsWith($minhaString, $var1) {
        return str_ends_with($minhaString, $var1);
    }

    function strIncludes($minhaString, $var1) {
        return str_contains($minhaString, $var1);
    }

    function strSplit($minhaString, $var1) {
        if ($var1 === "") {
            throw new InvalidArgumentException("Empty string cannot be used as a delimiter");
        } else {
            return explode($var1, $minhaString);
        }
    }

    function strPadStart($minhaString, $var1, $var2 = " ") {
        return str_pad($minhaString, $var1, $var2[0], STR_PAD_LEFT);
    }

    function strPadEnd($minhaString, $var1, $var2 = " ") {
        return str_pad($minhaString, $var1, $var2[0], STR_PAD_RIGHT);
    }

    function strRepeat($minhaString, $var1) {
        return str_repeat($minhaString, $var1);
    }

    function strSearch($minhaString, $regex) {
        // Busca por regex
        $result = preg_match('/' . $regex . '/', $minhaString, $matches, PREG_OFFSET_CAPTURE);
        return $result ? $matches[0][1] : -1;
    }

    function strTrim($minhaString) {
        return trim($minhaString);
    }

    function strTrimStart($minhaString) {
        return ltrim($minhaString);
    }

    function strTrimEnd($minhaString) {
        return rtrim($minhaString);
    }

    function strSlice($minhaString, $var1, $var2) {
        return substr($minhaString, $var1, $var2 - $var1);
    }

// =========================
    // Date

    public function dateDay(){
        return intval(date("d"));
    }

    public function dateWeekDay(){
        // date("w") retorna 0=Domingo..6=Sábado
        // Queremos: 1=Domingo..7=Sábado
        $wd = intval(date("w"));
        return $wd + 1;
    }

    public function dateMonth(){
        // date("m") retorna 01=Janeiro..12=Dezembro (1-based) - correto!
        return intval(date("m"));
    }

    // Alias para compatibilidade (mantém dateMouth funcionando)
    public function dateMouth(){
        return $this->dateMonth();
    }

    public function dateYear(){
        return intval(date("Y"));
    }

    public function dateSetWeekDay($ano,$mes,$dia){
        // date("w") retorna 0=Domingo..6=Sábado
        // Queremos: 1=Domingo..7=Sábado
        $wd = intval(date("w", strtotime("$ano-$mes-$dia")));
        return $wd + 1;
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
        $result = array_search($o,$lista);
        return $result === false ? -1 : $result;
    }

    public function arrLastIndexOf($lista,$o){
        $reversed = array_reverse($lista, true);
        $result = array_search($o, $reversed);
        return $result === false ? -1 : $result;
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
        // Tenta usar a locale especificada
        $localeMap = [
            'pt_BR' => 'pt_BR.UTF-8',
            'en_US' => 'en_US.UTF-8',
            'en_GB' => 'en_GB.UTF-8',
            'de_DE' => 'de_DE.UTF-8',
            'fr_FR' => 'fr_FR.UTF-8',
        ];
        $localeKey = $language . '_' . $country;
        $locale = $localeMap[$localeKey] ?? setlocale(LC_NUMERIC, 0);
        
        try {
            setlocale(LC_NUMERIC, $locale);
        } catch (\Exception $e) {
            // Fallback para formato padrão
        }
        
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
        if (empty($values)) {
            throw new InvalidArgumentException("mathMaxArr requires at least one argument");
        }
        return max($values);
    }

    public function mathMinArr(...$values){
        if (empty($values)) {
            throw new InvalidArgumentException("mathMinArr requires at least one argument");
        }
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
