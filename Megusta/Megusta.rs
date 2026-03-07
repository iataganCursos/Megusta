// Cargo.toml
/*
[dependencies]
chrono = "0.4"
rand = "0.8"
*/

use std::io::{self, Write};
use std::fs;
use std::process::Command;
use chrono::{Local, Datelike, Timelike};
use rand::Rng;
use std::f64::consts::{PI, E, LN_2, LN_10, LOG2_E, LOG10_E};

pub struct Megusta;

impl Megusta {

    pub fn new() -> Self {
        Megusta
    }

    // Program

    pub fn r_print(&self, message: &str) {
        print!("{}", message);
        io::stdout().flush().unwrap();
    }

    pub fn r_println(&self, message: &str) {
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
        let _ = Command::new(nome_programa).spawn();
    }

    // String

    pub fn str_replace(&self, original: &str, v1: &str, v2: &str) -> String {
        original.replace(v1, v2)
    }

    pub fn str_length(&self, s: &str) -> usize {
        s.len()
    }

    pub fn str_substring(&self, s: &str, i: usize, j: usize) -> String {
        s[i..j].to_string()
    }

    pub fn str_char_at(&self, s: &str, i: usize) -> char {
        s.chars().nth(i).unwrap()
    }

    pub fn str_index_of(&self, s: &str, sub: &str) -> isize {
        match s.find(sub) {
            Some(i) => i as isize,
            None => -1
        }
    }

    pub fn str_last_index_of(&self, s: &str, sub: &str) -> isize {
        match s.rfind(sub) {
            Some(i) => i as isize,
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

    // Date

    pub fn date_day(&self) -> u32 {
        Local::now().day()
    }

    pub fn date_week_day(&self) -> u32 {
        Local::now().weekday().number_from_sunday()
    }

    pub fn date_month(&self) -> u32 {
        Local::now().month()
    }

    pub fn date_year(&self) -> i32 {
        Local::now().year()
    }

    pub fn date_hour24(&self) -> u32 {
        Local::now().hour()
    }

    pub fn date_minute(&self) -> u32 {
        Local::now().minute()
    }

    pub fn date_second(&self) -> u32 {
        Local::now().second()
    }

    // Array (Vec)

    pub fn arr_add(lista: &mut Vec<String>, valor: String) {
        lista.push(valor);
    }

    pub fn arr_add_index(lista: &mut Vec<String>, i: usize, valor: String) {
        lista.insert(i, valor);
    }

    pub fn arr_set(lista: &mut Vec<String>, i: usize, valor: String) {
        lista[i] = valor;
    }

    pub fn arr_get(lista: &Vec<String>, i: usize) -> String {
        lista[i].clone()
    }

    pub fn arr_size(lista: &Vec<String>) -> usize {
        lista.len()
    }

    pub fn arr_remove(lista: &mut Vec<String>, i: usize) {
        lista.remove(i);
    }

    pub fn arr_clear(lista: &mut Vec<String>) {
        lista.clear();
    }

    pub fn arr_contains(lista: &Vec<String>, v: &str) -> bool {
        lista.contains(&v.to_string())
    }

    pub fn arr_index_of(lista: &Vec<String>, v: &str) -> isize {
        match lista.iter().position(|x| x == v) {
            Some(i) => i as isize,
            None => -1
        }
    }

    // Math

    pub fn math_int(&self, s: &str) -> i64 {
        s.parse::<i64>().unwrap()
    }

    pub fn math_num(&self, s: &str) -> f64 {
        s.parse::<f64>().unwrap()
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

    pub fn math_pow(&self, base: f64, exp: f64) -> f64 {
        base.powf(exp)
    }

    pub fn math_sqrt(&self, n: f64) -> f64 {
        n.sqrt()
    }

    pub fn math_cbrt(&self, n: f64) -> f64 {
        n.cbrt()
    }

    pub const MATH_PI: f64 = PI;
    pub const MATH_E: f64 = E;
    pub const MATH_LN2: f64 = LN_2;
    pub const MATH_LN10: f64 = LN_10;
    pub const MATH_LOG2E: f64 = LOG2_E;
    pub const MATH_LOG10E: f64 = LOG10_E;

    // Converter graus para radianos
    pub fn math_convert_to_radians(graus: f64) -> f64 {
        graus * (PI / 180.0)
    }

    pub fn math_sin(angulo: f64) -> f64 {
        angulo.sin()
    }

    pub fn math_cos(angulo: f64) -> f64 {
        angulo.cos()
    }

    pub fn math_tan(angulo: f64) -> f64 {
        angulo.tan()
    }

    pub fn math_asin(valor: f64) -> f64 {
        valor.asin()
    }

    pub fn math_acos(valor: f64) -> f64 {
        valor.acos()
    }

    pub fn math_atan(valor: f64) -> f64 {
        valor.atan()
    }

    pub fn math_sinh(valor: f64) -> f64 {
        valor.sinh()
    }

    pub fn math_cosh(valor: f64) -> f64 {
        valor.cosh()
    }

    pub fn math_tanh(valor: f64) -> f64 {
        valor.tanh()
    }

    // arco seno hiperbólico
    pub fn math_asinh(x: f64) -> f64 {
        (x + (x * x + 1.0).sqrt()).ln()
    }

    // arco cosseno hiperbólico
    pub fn math_acosh(x: f64) -> f64 {
        (x + (x * x - 1.0).sqrt()).ln()
    }

    // arco tangente hiperbólico
    pub fn math_atanh(x: f64) -> f64 {
        0.5 * ((1.0 + x) / (1.0 - x)).ln()
    }

    pub fn math_log(numero: f64) -> f64 {
        numero.ln()
    }

    pub fn math_log10(numero: f64) -> f64 {
        numero.log10()
    }

    pub fn math_exp(expoente: f64) -> f64 {
        expoente.exp()
    }

    pub fn math_log2(numero: f64) -> f64 {
        numero.log2()
    }

    pub fn math_log1p(valor: f64) -> f64 {
        valor.ln_1p()
    }
}