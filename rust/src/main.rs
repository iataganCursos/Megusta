// mod ouka;

use megusta::Megusta;

fn main() {
        let r = Megusta::new();
        r.r_print("Esta eh uma mensagem de exemplo.");

        r.r_println(&format!("Esta eh uma mensagem de exemplo."));

        r.r_println_empty();

        let nome = r.r_input("Qual eh o seu nome? ");
        r.r_println(&format!("Olah, {}!", nome));

        r.r_println_empty();

        let conteudo = "Este eh o conteudo que serah salvo no arquivo.";
        let nome_arquivo = "meu_arquivo.txt";
        r.r_save_file(nome_arquivo, conteudo);

        r.r_println_empty();

        r.r_println(&format!("{}", r.r_open_file(nome_arquivo)));

        r.r_println_empty();
        r.r_open_program("c:/java/jdk-23/bin/java.exe -jar /MeuApp/WindowJAR.jar");

        r.r_println_empty();

        match Megusta::r_open_file_web("https://www.ouka.com.br/meu_arquivo.txt") {
                Ok(_) => {}
                Err(e) => {
                println!("A URL não Funcionou");
                println!("{}", e);
                }
        }

        r.r_println_empty();

        // strReplace
        let original = "Hoje é um lindo dia!";
        let substituida = r.str_replace(original, "lindo", "maravilhoso");
        r.r_println(&format!("{}", substituida)); // Saída: "Hoje é um maravilhoso dia!"

        // strLength
        let minha_string = "Olá, mundo!";
        let tamanho: i64 = r.str_length(minha_string);
        r.r_println(&format!("O tamanho da string é: {}", tamanho)); // Saída: "O tamanho da string é: 12"
 
        // strSubstring
        let original2 = "Isso é uma String de exemplo.";
        let sub = r.str_substring(original2, 8, 13);
        r.r_println(&format!("{}", sub)); // Saída: "uma S"

        // strCharAt
        let minha_string2 = "Olá, mundo!";
        let primeiro_caractere: char = r.str_char_at(minha_string2,0); // Obtém o primeiro caractere 'O'
        let quarto_caractere: char = r.str_char_at(minha_string2, 3); // Obtém o quarto caractere ',', que é uma vírgula

        r.r_println(&format!("Primeiro caractere: {}", primeiro_caractere));
        r.r_println(&format!("Quarto caractere: {}", quarto_caractere));

        // strIndexOf
        let minha_string3 = "Isso é um exemplo de indexOf em Java.";
        let indice: i64 = r.str_index_of(minha_string3, "exemplo");
        r.r_println(&format!("A substring 'exemplo' começa no índice: {}", indice)); // Saída: "A substring 'exemplo' começa no índice: 13"

        // strLastIndexOf
        let minha_string4 = "Isso é um exemplo de lastIndexOf em Java. lastIndexOf é útil para encontrar a última ocorrência de uma substring.";
        let indice2: i64 = r.str_last_index_of(minha_string4,"lastIndexOf");
        r.r_println(&format!("A última ocorrência de 'lastIndexOf' começa no índice: {}", indice2)); // Saída: "A última ocorrência de 'lastIndexOf' começa no índice: 38"
 
        // strToLowerCase
        let minha_string5 = "Isso É Uma String De Exemplo.";
        let em_minusculas = r.str_to_lower(minha_string5);
        r.r_println(&format!("{}", em_minusculas)); // Saída: "isso é uma string de exemplo."

        // strToUpperCase
        let minha_string6 = "Isso É Uma String De Exemplo.";
        let em_maiusculas = r.str_to_upper(minha_string6);
        r.r_println(&format!("{}", em_maiusculas)); // Saída: "ISSO É UMA STRING DE EXEMPLO."
 
        // strCompareTo
        let string1 = "abacate";
        let string2 = "banana";

        let resultado: i64 = r.str_compare_to(string1, string2);

        if resultado < 0 {
                r.r_println(&format!("string1 é menor que string2"));
        } else if resultado == 0 {
                r.r_println(&format!("string1 é igual a string2"));
        } else {
                r.r_println(&format!("string1 é maior que string2"));
        }

        // strCompareToIgnoreCase
        let string1_1 = "maçã";
        let string2_1 = "MaÇÃ";

        let resultado2: i64 = r.str_compare_to_ignore_case(string1_1, string2_1);

        if resultado2 < 0 {
                r.r_println(&format!("string1 é menor que string2 (ignorando a diferença entre maiúsculas e minúsculas)"));
        } else if resultado2 == 0 {
                r.r_println(&format!("string1 é igual a string2 (ignorando a diferença entre maiúsculas e minúsculas)"));
        } else {
                r.r_println(&format!("string1 é maior que string2 (ignorando a diferença entre maiúsculas e minúsculas)"));
        }

        // strEquals
        let string1_2 = "Olá, mundo!";
        let string2_2 = "Olá, mundo!";
        let string3_2 = "olá, Mundo!";

        let sao_iguais1: bool = r.str_equals(string1_2, string2_2); // Retorna true
        let sao_iguais2: bool = r.str_equals(string1_2, string3_2); // Retorna false

        r.r_println(&format!("{}", sao_iguais1));
        r.r_println(&format!("{}", sao_iguais2));
 
        // strEqualsIgnoreCase
        let string1_3 = "Olá, mundo!";
        let string2_3 = "olá, Mundo!";

        let sao_iguais: bool = r.str_equals_ignore_case(string1_3, string2_3); // Retorna true

        r.r_println(&format!("{}", sao_iguais));


        r.r_println_empty();

        let mut texto = String::new();

        let dia_do_mes: i64 = r.date_day();
        let dia_da_semana: i64 = r.date_week_day();
        let mes: i64 = r.date_mouth();
        let ano: i64 = r.date_year();

        // ---------------------------------------
        let horas: i64 = r.date_hour24();
        let minutos: i64 = r.date_minute();
        let segundos: i64 = r.date_second();
        // ---------------------------------------
        let mut semana: Vec<&str> = vec![""];
        semana.push("Domingo");
        semana.push("Segunda");
        semana.push("Terça");
        semana.push("Quarta");
        semana.push("Quinta");
        semana.push("Sexta");
        semana.push("Sabado");
        let semena_atual = semana[dia_da_semana as usize];
        //-------------------------
        let mes2: Vec<&str> = vec![
            "Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho",
            "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Desembro"
        ];
        let mes_atual = mes2.get((mes - 1) as usize).unwrap_or(&"");
        texto.push_str(&format!("{}, {} de {} de {}\n", semena_atual, dia_do_mes, mes_atual, ano));
        texto.push_str(&format!("São: {} horas, {} minutos e {} segundos.", horas, minutos, segundos));

        r.r_println(&texto);

        texto.clear();

        let x_dia: i64 = 28;
        let x_mes: i64 = 4;
        let x_ano: i64 = 1997;
        
        // ---------------------------------------
        let dia_do_mes = x_dia;
        let dia_da_semana = r.date_set_week_day(x_ano as i32, x_mes as i32, x_dia as i32);
        let mes = x_mes;
        let ano = x_ano;

        semana[0] = "";
        semana[1] = "Domingo";
        semana[2] = "Segunda";
        semana[3] = "Terça";
        semana[4] = "Quarta";
        semana[5] = "Quinta";
        semana[6] = "Sexta";
        semana[7] = "Sabado";
        let semena_atual = semana[dia_da_semana as usize];
        //-------------------------

        let mes_atual = mes2.get((mes - 1) as usize).unwrap_or(&"");
        r.r_println(format!("{}, {} de {} de {}", semena_atual, dia_do_mes, mes_atual, ano));

        r.r_println_empty();

        //ArrayList
        //arrAllAdd(Object o): adiciona à coleção o objeto passado como argumento.

        let mut frutasx: Vec<String> = vec![];

        // adiciona itens na lista
        r.arr_add_all(&mut frutasx, &["Banana", "Melão", "Goiaba", "Morango"]);

        // exibe os valores da lista
        for i in 0..(r.arr_size(&frutasx) as usize) {
                r.r_println(r.arr_get(&frutasx, i));
        }

        r.r_println_empty();

        //add(Object o): adiciona à coleção o objeto passado como argumento.
        //size(): retorna o tamanho da coleção
        //get(int index): retorna um objeto dada uma posição.

        let mut frutas1: Vec<String> = vec![];

        // adiciona itens na lista
        r.arr_add(&mut frutas1, "Banana");
        r.arr_add(&mut frutas1, "Melão");
        r.arr_add(&mut frutas1, "Goiaba");
        r.arr_add(&mut frutas1, "Morango");

        // exibe os valores da lista
        for i in 0..r.arr_size(&frutas1) {
                r.r_println(r.arr_get(&frutas1, i as usize));
        }

        r.r_println_empty();

        //add(int index, Object element): adiciona um objeto dada uma posição.

        let mut frutas2: Vec<String> = vec![];

        // adiciona itens na lista
        r.arr_add(&mut frutas2, "Banana");
        r.arr_add(&mut frutas2, "Melão");
        r.arr_add(&mut frutas2, "Goiaba");
        r.arr_add(&mut frutas2, "Morango");

        r.arr_add_index(&mut frutas2, 1, "======");

        // exibe os valores da lista
        for i in 0..r.arr_size(&frutas2) {
                r.r_println(r.arr_get(&frutas2, i as usize));
        }

        r.r_println_empty();

        //set(int index, Object element): edita um objeto dada uma posição.

        let mut frutas3: Vec<String> = vec![];

        // adiciona itens na lista
        r.arr_add(&mut frutas3, "Banana");
        r.arr_add(&mut frutas3, "Melão");
        r.arr_add(&mut frutas3, "Goiaba");
        r.arr_add(&mut frutas3, "Morango");

        r.arr_set(&mut frutas3, 1, "======");

        // exibe os valores da lista
        for i in 0..r.arr_size(&frutas3) {
                r.r_println(r.arr_get(&frutas3, i as usize));
        }

        r.r_println_empty();

        //remove(int index): remove um objeto dada sua posição.

        let mut frutas4: Vec<String> = vec![];

        // adiciona itens na lista
        r.arr_add(&mut frutas4, "Banana");
        r.arr_add(&mut frutas4, "Melão");
        r.arr_add(&mut frutas4, "Goiaba");
        r.arr_add(&mut frutas4, "Morango");

        r.arr_remove(&mut frutas4, 1);

        // exibe os valores da lista
        for i in 0..r.arr_size(&frutas4) {
                r.r_println(r.arr_get(&frutas4, i as usize));
        }

        r.r_println_empty();

        //clear(): apaga todo o conteúdo da coleção.

        let mut frutas5: Vec<String> = vec![];

        // adiciona itens na lista
        r.arr_add(&mut frutas5, "Banana");
        r.arr_add(&mut frutas5, "Melão");
        r.arr_add(&mut frutas5, "Goiaba");
        r.arr_add(&mut frutas5, "Morango");

        r.arr_clear(&mut frutas5);

        // exibe os valores da lista
        for i in 0..r.arr_size(&frutas5) {
                r.r_println(r.arr_get(&frutas5, i as usize));
        }

        r.r_println_empty();

        //boolean contains(Object o): verifica se o objeto passado como argumento existe na coleção.

        let mut lista1: Vec<String> = vec![];
        r.arr_add(&mut lista1, "Jose");
        r.arr_add(&mut lista1, "Maria");
        r.r_println(r.arr_contains(&lista1, "Jose"));

        r.r_println_empty();

        //Object[ ] toArray(): converte os elementos da coleção em um array (rápidos acesso aos elementos).

        let mut lista2: Vec<String> = vec![];
        r.arr_add(&mut lista2, "Jose");
        r.arr_add(&mut lista2, "Maria");
        r.arr_add(&mut lista2, "Joao");
        let elementos2 = r.arr_to_array(&lista2);
        for i in 0..r.x_arr_length(&elementos2) {
                r.r_println(elementos2[i as usize].clone());
        }

        r.r_println_empty();

        //int indexOf (Object o): retorna a posição de um objeto.

        let mut lista3: Vec<String> = vec![];
        r.arr_add(&mut lista3, "Jose");
        r.arr_add(&mut lista3, "Maria");
        r.arr_add(&mut lista3, "João");
        r.r_println(r.arr_index_of(&lista3, "Maria"));

        r.r_println_empty();

        //int lastIndexOf (Object o): retorna o último índice de um objeto.

        let mut lista4: Vec<String> = vec![];
        r.arr_add(&mut lista4, "Jose");
        r.arr_add(&mut lista4, "Maria");
        r.arr_add(&mut lista4, "João");
        r.arr_add(&mut lista4, "Maria");
        r.r_println(r.arr_last_index_of(&lista4, "Maria"));

        r.r_println_empty();

//Funções Matemáticas

//Convertendo String para Numérica
//Números Inteiros
//mathint
        // Exemplo simples
        let numero_string = "123456".to_string();
        let numero_long = r.math_int(&numero_string).unwrap();
        r.r_println(&format!("Número convertido: {}", numero_long));

        // Tratamento de exceção para entrada inválida
        let entrada_invalida = "abc";
        // Nota: Em Rust, use Result e match em vez de try-catch
        match r.math_int(entrada_invalida) {
            Ok(resultado_l) => r.r_println(&format!("Número convertido: {}", resultado_l)),
            Err(_) => r.r_println(&format!("Erro: A string não é um número válido."))
        }

//Números Reais
//mathnum
        // Exemplo simples
        let numero_string = "123.456".to_string();
        let numero_double_d: f64 = r.math_num(&numero_string).unwrap_or(0.0);
        r.r_println(&format!("Número convertido: {}", numero_double_d));

        // Tratamento de exceção para entrada inválida
        let entrada_invalida = "abc";
        // Nota: Em Rust, use Result e match em vez de try-catch
        match r.math_num(entrada_invalida) {
            Ok(resultado_d) => r.r_println(&format!("Número convertido: {}", resultado_d)),
            Err(_) => r.r_println(&format!("Erro: A string não é um número válido."))
        }

//Boleanos
//mathbool
        // Exemplos simples
        let true_string = "true";
        let boolean_true: bool = r.math_bool(true_string);
        r.r_println(&format!("Valor booleano: {}", boolean_true));

        let false_string = "false";
        let boolean_false: bool = r.math_bool(false_string);
        r.r_println(&format!("Valor booleano: {}", boolean_false));

        // Tratamento de entrada inválida
        let entrada_invalida = "abc";
        let resultado_b: bool = r.math_bool(entrada_invalida);
        r.r_println(&format!("Valor booleano: {}", resultado_b));
        // Como "abc" não é "true", o resultado será false
//Arredondando valores
//Math.floor
        let mut numero_original: f64;
        let mut numero_arredondado: f64;

        numero_original = 7.8;
        numero_arredondado = r.math_floor(numero_original);

        r.r_println(&format!("Número original: {}", numero_original));
        r.r_println(&format!("Número arredondado para baixo: {}", numero_arredondado));
//Math.ceil
        numero_original = 7.2;
        numero_arredondado = r.math_ceil(numero_original);

        r.r_println(&format!("Número original: {}", numero_original));
        r.r_println(&format!("Número arredondado para cima: {}", numero_arredondado));
//Math.round
        numero_original = 7.5;
        numero_arredondado = r.math_round(numero_original);

        r.r_println(&format!("Número original: {}", numero_original));
        r.r_println(&format!("Número arredondado: {}", numero_arredondado));

//Digite um número com 3 casas decimais
//mathDecimalFormat
        let mut numero: f64 = 123.456789;

        let numero_formatado = r.math_decimal_format(numero, "#.###");

        r.r_println(&format!("Número formatado: {}", numero_formatado));

//Formatar moeda
//mathNumberFormat
        numero = 1234567.89;

        // Formatar o número de acordo com a localidade do Brasil
        let numero_formatado_brasil = r.math_number_format(numero, "pt","BR");
       
        r.r_println(&format!("Brasil: {}", numero_formatado_brasil));

//Funções matemáticas comuns
//Math.random

        // Gerar um número aleatório no intervalo [0.0, 1.0)
        let numero_aleatorio: f64 = r.math_random();

        r.r_println(&format!("Número aleatório: {}", numero_aleatorio));

        //double numeroAleatorioNoIntervalo = Math.random() * (max - min) + min;
        //double numeroAleatorioIntervalo = Math.random() * (10.0 - 5.0) + 5.0;
        //r.r_println(&format!("Número aleatório no intervalo: " + numeroAleatorioIntervalo);
//Math.abs

        let numero_inteiro: i64 = -5;
        let numero_longo: i64 = -123456789;
        let numero_float: f64 = -3.14;
        let numero_double: f64 = -2.71828;

        // Calcular o valor absoluto para diferentes tipos de números
        let abs_int: i64 = r.math_abs(numero_inteiro as f64) as i64;
        let abs_long: i64 = r.math_abs(numero_longo as f64) as i64;
        let abs_float: f64 = r.math_abs(numero_float);
        let abs_double: f64 = r.math_abs(numero_double);

        r.r_println(&format!("Valor absoluto de {} = {}", numero_inteiro, abs_int));
        r.r_println(&format!("Valor absoluto de {} = {}", numero_longo, abs_long));
        r.r_println(&format!("Valor absoluto de {} = {}", numero_float, abs_float));
        r.r_println(&format!("Valor absoluto de {} = {}", numero_double, abs_double));

//Math.max

        let mut numero3: f64 = 15.5;
        let mut numero4: f64 = 12.3;

        // Encontrar o máximo entre dois números de ponto flutuante
        let maximo_double: f64 = r.math_max(numero3, numero4);
        r.r_println(&format!("Máximo entre {} e {} = {}", numero3, numero4, maximo_double));

        // int maximoEntreTres = Math.max(Math.max(numero1, numero2), numero3);
//Math.min

        numero3 = 15.5;
        numero4 = 12.3;

        // Encontrar o mínimo entre dois números de ponto flutuante
        let minimo_double: f64 = r.math_min(numero3, numero4);
        r.r_println(&format!("Mínimo entre {} e {} = {}", numero3, numero4, minimo_double));

       //int minimoEntreTres = Math.min(Math.min(numero1, numero2), numero3);

//Math.max

        // Encontrar o máximo entre dois números de ponto flutuante
        let maximo_double: f64 = r.math_max_arr(&[15.5, 12.3, 10.8, 14.6]);
        r.r_println(&format!("Máximo entre 15.5, 12.3, 10.8, 14.6 = {}", maximo_double));

//Math.min

        // Encontrar o mínimo entre dois números de ponto flutuante
        let minimo_double: f64 = r.math_min_arr(&[15.5, 12.3, 10.8, 14.6]);
        r.r_println(&format!("Mínimo entre 15.5, 12.3, 10.8, 14.6 = {}", minimo_double));

//Math.pow
        let base: f64 = 2.0;
        let expoente: f64 = 3.0;

        // Calcular 2^3
        let resultado: f64 = r.math_pow(base, expoente);
        r.r_println(&format!("Resultado: {}", resultado));

//Math.sqrt
        let numerox3: f64 = 25.0;

        // Calcular a raiz quadrada de 25
        let raiz_quadrada: f64 = r.math_sqrt(numerox3);

        r.r_println(&format!("Raiz quadrada de {} = {}", numerox3, raiz_quadrada));

//Math.SQRT1_2
        // Utilizando a constante Math.SQRT1_2

        //double mathSQRT1_2 = 0.7071067811865476;
        
        let raiz_quadrada_de_um_meio: f64 = r.math_sqrt1_2();

        r.r_println(&format!("Raiz quadrada de 1/2: {}", raiz_quadrada_de_um_meio));

//Math.SQRT2
        // Utilizando a constante Math.SQRT2

        //double mathSQRT2 = 1.4142135623730951;
        
        let raiz_quadrada_de_dois: f64 = r.math_sqrt2();

        r.r_println(&format!("Raiz quadrada de 2: {}", raiz_quadrada_de_dois));

 
//Math.cbrt
        numero = 27.0;

        // Calcular a raiz cúbica de 27
        let raiz_cubica: f64 = r.math_cbrt(numero);

        r.r_println(&format!("Raiz cúbica de {} = {}", numero, raiz_cubica));

//Math.sign
        let numerox1: f64 = -5.5;

        // Obtendo o sinal do número
        let sinal: i64 = r.math_signum(numerox1);

        r.r_println(&format!("Sinal de {} = {}", numerox1, sinal));

        r.r_println_empty();

//Funções trigonométricas
//Math.PI
        // Acesso à constante Math.PI
        let pi: f64 = r.math_pi();

        // Exibindo o valor de pi
        r.r_println(&format!("O valor de pi é: {}", pi));

        // Exemplo de cálculo usando pi
        let raio: f64 = 5.0;
        let area: f64 = pi * raio * raio;
        r.r_println(&format!("A área de um círculo com raio {} é: {}", raio, area));
/*
function radianos(){
return Math.PI/180
}
*/

        let graus: f64 = 45.0;
        let radianos: f64 = r.math_convert_to_radians(graus);

        r.r_println(&format!("{} graus é equivalente a {} radianos.", graus, radianos));
 
//Math.sin
        // Ângulo em radianos
        let mut angulo_em_radianos: f64 = std::f64::consts::PI / 4.0;

        // Calculando o seno do ângulo
        let seno_do_angulo: f64 = r.math_sin(angulo_em_radianos);

        // Exibindo o resultado
        r.r_println(&format!("O seno de {} radianos é: {}", angulo_em_radianos, seno_do_angulo));

//Math.cos
        // Ângulo em radianos
        angulo_em_radianos = std::f64::consts::PI / 3.0;

        // Calculando o cosseno do ângulo
        let cosseno_do_angulo: f64 = r.math_cos(angulo_em_radianos);

        // Exibindo o resultado
        r.r_println(&format!("O cosseno de {} radianos é: {}", angulo_em_radianos, cosseno_do_angulo));

//Math.tan
        // Ângulo em radianos
        angulo_em_radianos = std::f64::consts::PI / 6.0;

        // Calculando a tangente do ângulo
        let tangente_do_angulo: f64 = r.math_tan(angulo_em_radianos);

        // Exibindo o resultado
        r.r_println(&format!("A tangente de {} radianos é: {}", angulo_em_radianos, tangente_do_angulo));
 
//Math.asin
        // Valor para o qual queremos calcular o arco seno
        let mut valor: f64 = 0.5;

        // Calculando o arco seno do valor
        let arco_seno: f64 = r.math_asin(valor);

        // Exibindo o resultado em radianos
        r.r_println(&format!("O arco seno de {} é: {} radianos.", valor, arco_seno));

//Math.acos
        // Valor para o qual queremos calcular o arco cosseno
        valor = 0.5;

        // Calculando o arco cosseno do valor
        let arco_cosseno: f64 = r.math_acos(valor);

        // Exibindo o resultado em radianos
        r.r_println(&format!("O arco cosseno de {} é: {} radianos.", valor, arco_cosseno));

//Math.atan
        // Valor para o qual queremos calcular o arco tangente
        valor = 0.5;

        // Calculando o arco tangente do valor
        let arco_tangente: f64 = r.math_atan(valor);

        // Exibindo o resultado em radianos
        r.r_println(&format!("O arco tangente de {} é: {} radianos.", valor, arco_tangente));
 
//Math.sinh
        // Valor para o qual queremos calcular o seno hiperbólico
        valor = 2.0;

        // Calculando o seno hiperbólico do valor
        let seno_hiperbolico: f64 = r.math_sinh(valor);

        // Exibindo o resultado
        r.r_println(&format!("O seno hiperbólico de {} é: {}", valor, seno_hiperbolico));

//Math.cosh
        // Valor para o qual queremos calcular o cosseno hiperbólico
        valor = 2.0;

        // Calculando o cosseno hiperbólico do valor
        let cosseno_hiperbolico: f64 = r.math_cosh(valor);

        // Exibindo o resultado
        r.r_println(&format!("O cosseno hiperbólico de {} é: {}", valor, cosseno_hiperbolico));

//Math.tanh
        // Valor para o qual queremos calcular a tangente hiperbólica
        valor = 2.0;

        // Calculando a tangente hiperbólica do valor
        let tangente_hiperbolica: f64 = r.math_tanh(valor);

        // Exibindo o resultado
        r.r_println(&format!("A tangente hiperbólica de {} é: {}", valor, tangente_hiperbolica));
 
//Math.asinh
        // Valor para o qual queremos calcular o arco seno hiperbólico
        valor = 2.0;

        // Calculando o arco seno hiperbólico do valor
        let arco_seno_hiperbolico: f64 = r.math_asinh(valor);
        // Exibindo o resultado
        r.r_println(&format!("O arco seno hiperbólico de {} é: {}", valor, arco_seno_hiperbolico));

        //asinh(x) = ln(x + sqrt(x^2 + 1))
//Math.acosh
        // Valor para o qual queremos calcular o arco cosseno hiperbólico
        valor = 2.0;

        // Calculando o arco cosseno hiperbólico do valor
        let arco_cosseno_hiperbolico: f64 = r.math_acosh(valor);

        // Exibindo o resultado
        r.r_println(&format!("O arco cosseno hiperbólico de {} é: {}", valor, arco_cosseno_hiperbolico));

        //acosh(x) = ln(x + sqrt(x^2 - 1))
//Math.atanh
        // Valor para o qual queremos calcular o arco tangente hiperbólico
        valor = 0.5;

        // Calculando o arco tangente hiperbólico do valor
        let arco_tangente_hiperbolico: f64 = r.math_atanh(valor);

        // Exibindo o resultado
        r.r_println(&format!("O arco tangente hiperbólico de {} é: {}", valor, arco_tangente_hiperbolico));

        //atanh(x) = 0.5 * ln((1 + x) / (1 - x))

        r.r_println_empty();

//Logarítmos

//Math.log
        // Número para o qual queremos calcular o logaritmo natural
        let numeroxx2: f64 = 10.0;

        // Calculando o logaritmo natural do número
        let logaritmo_natural: f64 = r.math_log(numeroxx2);

        // Exibindo o resultado
        r.r_println(&format!("O logaritmo natural de {} é: {}", numeroxx2, logaritmo_natural));

//Math.log10
        // Número para o qual queremos calcular o logaritmo na base 10
        let numeroxx: f64 = 1000.0;

        // Calculando o logaritmo na base 10 do número
        let logaritmo_base10: f64 = r.math_log10(numeroxx);

        // Exibindo o resultado
        r.r_println(&format!("O logaritmo na base 10 de {} é: {}", numeroxx, logaritmo_base10));
 
//Math.E
        // Acesso à constante Math.E
        let constante_e: f64 = r.math_e();

        // Exibindo o valor da constante E
        r.r_println(&format!("O valor da constante E é: {}", constante_e));
//Math.LN2
        // Acesso à constante Math.LN2
        let ln2: f64 = r.math_ln2();

        // Exibindo o valor do logaritmo natural de 2
        r.r_println(&format!("O valor do logaritmo natural de 2 é: {}", ln2));

//Math.LOG2E
        // Acesso à constante Math.LOG2E
        let log2e: f64 = r.math_log2e();

        // Exibindo o valor do logaritmo natural de base 2 de e
        r.r_println(&format!("O valor do logaritmo natural de base 2 de e é: {}", log2e ));

//Math.LN10
        // Acesso à constante Math.LN10
        let ln10: f64 = r.math_ln10();

        // Exibindo o valor do logaritmo natural de 10
        r.r_println(&format!("O valor do logaritmo natural de 10 é: {}", ln10));

//Math.LOG10E
        // Acesso à constante Math.LOG10E
        let log10e: f64 = r.math_log10e();

        // Exibindo o valor do logaritmo natural de base 10 de e
        r.r_println(&format!("O valor do logaritmo natural de base 10 de e é: {}", log10e));
 
//Math.exp
        // Expoente para o qual queremos calcular a exponenciação
        let expoente: f64 = 2.0;

        // Calculando a exponenciação de e elevado ao expoente
        let resultado3: f64 = r.math_exp(expoente);

        // Exibindo o resultado
        r.r_println(&format!("O resultado de e elevado a {} é: {}", expoente, resultado3));

//Math.log2
        // Número para o qual queremos calcular o logaritmo de base 2
        let numero2: f64 = 8.0;

        // Calculando o logaritmo de base 2 do número
        let log2: f64 = r.math_log2(numero2);

        // Exibindo o resultado
        r.r_println(&format!("O logaritmo de base 2 de {} é: {}", numero2, log2));

        //log2(x) = ln(x) / ln(2)

//Math.log1p
        // Valor para o qual queremos calcular o logaritmo natural de 1 mais um
        let valor: f64 = 0.5;

        // Calculando o logaritmo natural de 1 mais um
        let resultado4: f64 = r.math_log1p(valor);

        // Exibindo o resultado
        r.r_println(&format!("O logaritmo natural de 1 mais {} é: {}", valor, resultado4));

}