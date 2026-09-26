use std::io::{self, Write};
use std::fs;
use std::process::Command;
use chrono::{Local, Datelike, Timelike};
use rand::Rng;
use std::f64::consts::{PI, E, LN_2, LN_10, LOG2_E, LOG10_E};
use reqwest::blocking::Client;
use reqwest::header::USER_AGENT;
use std::error::Error;

/*
📁 Megusta/
  ├── Cargo.toml           (configuração do projeto)
  ├── Cargo.lock           (lock file gerado)
  ├── src/
  │   ├── lib.rs           (biblioteca com módulo Megusta)
  │   └── bin/
  │       └── xMain.rs     (binário principal)
  ├── Megusta/
  │   └── Megusta.rs       (implementação da biblioteca)
  └── target/              (diretório de saída compilado)
      ├── debug/
      └── release/
*/


// Cargo.toml
/*
[package]
name = "megusta"
version = "0.1.0"
edition = "2021"

[dependencies]
chrono = "0.4"
rand = "0.8"

*/

pub struct Megusta {
    pub math_pi: f64,
    pub math_e: f64,
    pub math_ln2: f64,
    pub math_ln10: f64,
    pub math_log2e: f64,
    pub math_log10e: f64,
    pub math_sqrt1_2: f64,
    pub math_sqrt2: f64,
}

impl Megusta {

    pub fn new() -> Self {
        Megusta {
            math_pi: PI,
            math_e: E,
            math_ln2: LN_2,
            math_ln10: LN_10,
            math_log2e: LOG2_E,
            math_log10e: LOG10_E,
            math_sqrt1_2: std::f64::consts::FRAC_1_SQRT_2,
            math_sqrt2: std::f64::consts::SQRT_2,
        }
    }

    // Program
    pub fn r_open_file_web(&self, url: &str) -> Result<(), Box<dyn Error>> {
        let client = Client::new();

        let response = client
            .get(url)
            .header(
                USER_AGENT,
                "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36",
            )
            .send()?;

        let status = response.status();
        let body = response.text()?;

        println!("Status: {}", status);
        println!("{}", body);

        Ok(())
    }

    pub fn r_print(&self, message: &str) {
        print!("{}", message);
        io::stdout().flush().unwrap();
    }

    pub fn r_println<T: std::fmt::Display>(&self, message: T) {
        println!("{}", message);
    }

    pub fn r_println_empty(&self) {
        println!();
    }

    pub fn r_input(&self, prompt: &str) -> String {
        print!("{}", prompt);
        io::stdout().flush().unwrap();

        let mut input = String::new();
        io::stdin().read_line(&mut input).unwrap();
        input.trim().to_string()
    }

    pub fn r_save_file(&self, nome_arquivo: &str, conteudo: &str) {
        match fs::write(nome_arquivo, conteudo) {
            Ok(_) => println!("Arquivo {} salvo com sucesso.", nome_arquivo),
            Err(e) => println!("Erro ao salvar arquivo: {}", e),
        }
    }

    pub fn r_open_file(&self, arquivo: &str) -> String {
        match fs::read_to_string(arquivo) {
            Ok(content) => content,
            Err(_) => {
                println!("Erro: O arquivo nao foi encontrado.");
                String::new()
            }
        }
    }

    pub fn r_open_program(&self, nome_programa: &str) {
        let v: Vec<&str> = nome_programa.split(' ').collect();
        Command::new(v[0])
            .args(&v[1..])
            .spawn()
            .expect("Falha ao abrir o programa");
    }

    // String

    pub fn str_replace(&self, original: &str, v1: &str, v2: &str) -> String {
        original.replace(v1, v2)
    }

    pub fn str_length(&self, s: &str) -> i64 {
        s.len() as i64
    }

    pub fn str_substring(&self, s: &str, i: usize, j: usize) -> String {
        s[i..j].to_string()
    }

    pub fn str_char_at(&self, s: &str, i: usize) -> char {
        s.chars().nth(i).unwrap()
    }

    pub fn str_index_of(&self, s: &str, sub: &str) -> i64 {
        match s.find(sub) {
            Some(i) => i as i64,
            None => -1
        }
    }

    pub fn str_last_index_of(&self, s: &str, sub: &str) -> i64 {
        match s.rfind(sub) {
            Some(i) => i as i64,
            None => -1
        }
    }

    pub fn str_to_lower(&self, s: &str) -> String {
        s.to_lowercase()
    }

    pub fn str_to_upper(&self, s: &str) -> String {
        s.to_uppercase()
    }

    pub fn str_equals(&self, a: &str, b: &str) -> bool {
        a == b
    }

    pub fn str_equals_ignore_case(&self, a: &str, b: &str) -> bool {
        a.to_lowercase() == b.to_lowercase()
    }

    pub fn str_compare_to(&self, a: &str, b: &str) -> i64 {
        match a.cmp(b) {
            std::cmp::Ordering::Less => -1i64,
            std::cmp::Ordering::Equal => 0i64,
            std::cmp::Ordering::Greater => 1i64,
        }
    }

    pub fn str_compare_to_ignore_case(&self, a: &str, b: &str) -> i64 {
        self.str_compare_to(&a.to_lowercase(), &b.to_lowercase())
    }

    pub fn str_to_lower_case(&self, s: &str) -> String {
        s.to_lowercase()
    }

    pub fn str_to_upper_case(&self, s: &str) -> String {
        s.to_uppercase()
    }
// ===========================
    pub fn str_concat(&self, strings: &[&str]) -> String {
        strings.concat()
    }

    pub fn str_starts_with(&self, minha_string: &str, var1: &str) -> bool {
        minha_string.starts_with(var1)
    }

    pub fn str_ends_with(&self, minha_string: &str, var1: &str) -> bool {
        minha_string.ends_with(var1)
    }

    pub fn str_includes(&self, minha_string: &str, var1: &str) -> bool {
        minha_string.contains(var1)
    }

    pub fn str_split(&self, minha_string: &str, var1: &str) -> Vec<String> {
        minha_string.split(var1).map(|s| s.to_string()).collect()
    }

    pub fn str_pad_start(&self, minha_string: &str, tamanho: usize, pad: &str) -> String {
        let pad_char = pad.chars().next().unwrap_or(' ');
        if minha_string.len() >= tamanho {
            return minha_string.to_string();
        }
        let padding = tamanho - minha_string.len();
        std::iter::repeat(pad_char).take(padding).collect::<String>() + minha_string
    }

    pub fn str_pad_end(&self, minha_string: &str, tamanho: usize, pad: &str) -> String {
        let pad_char = pad.chars().next().unwrap_or(' ');
        if minha_string.len() >= tamanho {
            return minha_string.to_string();
        }
        let padding = tamanho - minha_string.len();
        let mut result = minha_string.to_string();
        result.push_str(&std::iter::repeat(pad_char).take(padding).collect::<String>());
        result
    }

    pub fn str_repeat(&self, minha_string: &str, vezes: usize) -> String {
        minha_string.repeat(vezes)
    }

    pub fn str_search(&self, minha_string: &str, termo: &str) -> isize {
        match minha_string.find(termo) {
            Some(pos) => pos as isize,
            None => -1
        }
    }

    pub fn str_trim(&self, minha_string: &str) -> String {
        minha_string.trim().to_string()
    }

    pub fn str_trim_start(&self, minha_string: &str) -> String {
        minha_string.trim_start().to_string()
    }

    pub fn str_trim_end(&self, minha_string: &str) -> String {
        minha_string.trim_end().to_string()
    }

    // Atenção: slicing seguro com UTF-8
    pub fn str_slice(&self, minha_string: &str, inicio: usize, fim: usize) -> String {
        minha_string
            .chars()
            .skip(inicio)
            .take(fim - inicio)
            .collect()
    }
// ===========================
    // Date

    pub fn date_day(&self) -> i64 {
        Local::now().day() as i64
    }

    pub fn date_week_day(&self) -> i64 {
        Local::now().weekday().number_from_sunday() as i64
    }

    pub fn date_month(&self) -> i64 {
        Local::now().month() as i64
    }

    pub fn date_mouth(&self) -> i64 {
        self.date_month()
    }

    pub fn date_year(&self) -> i64 {
        Local::now().year() as i64
    }

    pub fn date_hour24(&self) -> i64 {
        Local::now().hour() as i64
    }

    pub fn date_minute(&self) -> i64 {
        Local::now().minute() as i64
    }

    pub fn date_second(&self) -> i64 {
        Local::now().second() as i64
    }

    pub fn date_set_week_day(&self, mut ano: i32, mut mes: i32, dia: i32) -> i64 {
        // Ajuste de meses: janeiro e fevereiro viram 13 e 14 do ano anterior
        if mes < 3 {
            mes += 12;
            ano -= 1;
        }

        let k = ano % 100;
        let j = ano / 100;

        // Fórmula de Zeller
        let h = (dia + (13 * (mes + 1)) / 5 + k + k / 4 + j / 4 + 5 * j) % 7;

        // Conversão:
        // Zeller: 0=Sábado, 1=Domingo, 2=Segunda, ..., 6=Sexta
        // Queremos: 1=Domingo ... 7=Sábado
        match h {
            0 => 7i64, // Sábado
            1 => 1i64, // Domingo
            2 => 2i64, // Segunda
            3 => 3i64, // Terça
            4 => 4i64, // Quarta
            5 => 5i64, // Quinta
            6 => 6i64, // Sexta
            _ => 0i64,
        }
    }

    // Array (Vec)

    pub fn arr_add_all(&self, lista: &mut Vec<String>, valores: &[&str]) {
        for &v in valores {
            lista.push(v.to_string());
        }
    }
    pub fn arr_add(&self, lista: &mut Vec<String>, valor: &str) {
        lista.push(valor.to_string());
    }

    pub fn arr_add_index(&self, lista: &mut Vec<String>, i: usize, valor: &str) {
        lista.insert(i, valor.to_string());
    }

    pub fn arr_set(&self, lista: &mut Vec<String>, i: usize, valor: &str) {
        lista[i] = valor.to_string();
    }

    pub fn arr_get(&self, lista: &Vec<String>, i: usize) -> String {
        lista[i].clone()
    }

    pub fn arr_size(&self, lista: &Vec<String>) -> i64 {
        lista.len() as i64
    }

    pub fn arr_remove(&self, lista: &mut Vec<String>, i: usize) {
        lista.remove(i);
    }

    pub fn arr_clear(&self, lista: &mut Vec<String>) {
        lista.clear();
    }

    pub fn arr_contains(&self, lista: &Vec<String>, v: &str) -> bool {
        lista.contains(&v.to_string())
    }

    pub fn arr_index_of(&self, lista: &Vec<String>, v: &str) -> i64 {
        match lista.iter().position(|x| x == v) {
            Some(i) => i as i64,
            None => -1
        }
    }
    pub fn arr_last_index_of(&self, lista: &Vec<String>, alvo: &str) -> i64 {
        for (i, item) in lista.iter().enumerate().rev() {
            if item == alvo {
                return i as i64;
            }
        }
        -1
    }

    pub fn arr_to_array(&self, lista: &Vec<String>) -> Vec<String> {
        lista.clone()
    }

    pub fn x_arr_length(&self, arr: &Vec<String>) -> i64 {
        arr.len() as i64
    }

    // Math

    pub fn math_decimal_format(&self, numero: f64, pattern: &str) -> String {
        // Suporte básico para padrões como "#.###"
        if let Some(pos) = pattern.find('.') {
            let decimal_places = pattern.len() - pos - 1;
            format!("{:.*}", decimal_places, numero)
        } else {
            format!("{}", numero.trunc())
        }
    }

    pub fn math_number_format(&self, numero: f64, language: &str, country: &str) -> String {
        // Implementação simples para separador de milhar e decimal
        // Exemplo: pt-BR → 1.234.567,89

        let is_brazil = language == "pt" && country == "BR";

        let inteiro = numero.trunc() as i64;
        let decimal = ((numero.fract() * 100.0).round()) as i64;

        let mut inteiro_str = inteiro.abs().to_string();
        let mut resultado = String::new();

        // Inserir separadores de milhar
        while inteiro_str.len() > 3 {
            let parte = inteiro_str.split_off(inteiro_str.len() - 3);
            if is_brazil {
                resultado = format!(".{}{}", parte, resultado);
            } else {
                resultado = format!(",{}{}", parte, resultado);
            }
        }
        resultado = format!("{}{}", inteiro_str, resultado);

        // Adicionar sinal negativo se necessário
        if inteiro < 0 {
            resultado = format!("-{}", resultado);
        }

        // Separador decimal
        if is_brazil {
            format!("{},{}", resultado, format!("{:02}", decimal))
        } else {
            format!("{}.{}", resultado, format!("{:02}", decimal))
        }
    }

    pub fn math_int(&self, s: &str) -> Result<i64, std::num::ParseIntError> {
        s.parse::<i64>()
    }

    pub fn math_num(&self, s: &str) -> Result<f64, std::num::ParseFloatError> {
        s.parse::<f64>()
    }

    pub fn math_bool(&self, s: &str) -> bool {
        s.parse::<bool>().unwrap_or(false)
    }

    pub fn math_floor(&self, n: f64) -> f64 {
        n.floor()
    }

    pub fn math_ceil(&self, n: f64) -> f64 {
        n.ceil()
    }

    pub fn math_round(&self, n: f64) -> f64 {
        n.round()
    }

    pub fn math_random(&self) -> f64 {
        rand::thread_rng().gen()
    }

    pub fn math_abs(&self, n: f64) -> f64 {
        n.abs()
    }

    pub fn math_max(&self, a: f64, b: f64) -> f64 {
        a.max(b)
    }

    pub fn math_min(&self, a: f64, b: f64) -> f64 {
        a.min(b)
    }

    pub fn math_max_arr(&self, values: &[f64]) -> f64 {
        let mut max = values[0];
        for &val in &values[1..] {
            if val > max {
                max = val;
            }
        }
        max
    }

    pub fn math_min_arr(&self, values: &[f64]) -> f64 {
        let mut min = values[0];
        for &val in &values[1..] {
            if val < min {
                min = val;
            }
        }
        min
    }

    pub fn math_pow(&self, base: f64, exp: f64) -> f64 {
        base.powf(exp)
    }

    pub fn math_log(&self, n: f64) -> f64 {
        n.ln()
    }

    pub fn math_cbrt(&self, n: f64) -> f64 {
        n.cbrt()
    }

    pub fn math_sqrt(&self, n: f64) -> f64 {
        n.sqrt()
    }

    pub fn math_signum(&self, n: f64) -> i64 {
        n.signum() as i64
    }

    pub fn math_pi(&self) -> f64 {
        self.math_pi
    }
    // Função para converter graus para radianos
    pub fn math_convert_to_radians(&self, graus: f64) -> f64 {
        graus * (std::f64::consts::PI / 180.0)
    }

    pub fn math_sin(&self, angulo: f64) -> f64 {
        angulo.sin()
    }

    pub fn math_cos(&self, angulo: f64) -> f64 {
        angulo.cos()
    }

    pub fn math_tan(&self, angulo: f64) -> f64 {
        angulo.tan()
    }

    pub fn math_asin(&self, valor: f64) -> f64 {
        valor.asin()
    }

    pub fn math_acos(&self, valor: f64) -> f64 {
        valor.acos()
    }

    pub fn math_atan(&self, valor: f64) -> f64 {
        valor.atan()
    }

    pub fn math_sinh(&self, valor: f64) -> f64 {
        valor.sinh()
    }

    pub fn math_cosh(&self, valor: f64) -> f64 {
        valor.cosh()
    }

    pub fn math_tanh(&self, valor: f64) -> f64 {
        valor.tanh()
    }

    // Função para calcular o arco seno hiperbólico
    pub fn math_asinh(&self, x: f64) -> f64 {
        (x + (x * x + 1.0).sqrt()).ln()
    }

    // Função para calcular o arco cosseno hiperbólico
    pub fn math_acosh(&self, x: f64) -> f64 {
        (x + (x * x - 1.0).sqrt()).ln()
    }

    // Função para calcular o arco tangente hiperbólico
    pub fn math_atanh(&self, x: f64) -> f64 {
        0.5 * ((1.0 + x) / (1.0 - x)).ln()
    }
    pub fn math_log10(&self, numero: f64) -> f64 {
        numero.log10()
    }

    pub fn math_exp(&self, expoente: f64) -> f64 {
        expoente.exp()
    }

    pub fn math_log2(&self, numero: f64) -> f64 {
        numero.log2()
    }

    pub fn math_log1p(&self, valor: f64) -> f64 {
        valor.ln_1p()
    }

    pub fn math_sqrt1_2(&self) -> f64 {
        self.math_sqrt1_2
    }

    pub fn math_sqrt2(&self) -> f64 {
        self.math_sqrt2
    }

    pub fn math_e(&self) -> f64 {
        self.math_e
    }

    pub fn math_ln2(&self) -> f64 {
        self.math_ln2
    }

    pub fn math_ln10(&self) -> f64 {
        self.math_ln10
    }

    pub fn math_log2e(&self) -> f64 {
        self.math_log2e
    }

    pub fn math_log10e(&self) -> f64 {
        self.math_log10e
    }
}