# 🚀 Megusta — Transpilador Multi-Linguagem

> **União das linguagens de programação:** Java, JavaScript, TypeScript, Node.js, PHP, Python, Clipper, Rust, C/C++, Assembly e WebAssembly.

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Python](https://img.shields.io/badge/Python-3776AB?style=for-the-badge&logo=python&logoColor=white)](https://www.python.org/)
[![JavaScript](https://img.shields.io/badge/JavaScript-F7DF1E?style=for-the-badge&logo=javascript&logoColor=black)](https://developer.mozilla.org/en-US/docs/Web/JavaScript)
[![Java](https://img.shields.io/badge/Java-007396?style=for-the-badge&logo=java&logoColor=white)](https://www.java.com/)
[![PHP](https://img.shields.io/badge/PHP-777BB4?style=for-the-badge&logo=php&logoColor=white)](https://www.php.net/)
[![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)](https://en.cppreference.com/w/c)
[![Clipper](https://img.shields.io/badge/Clipper-Harbour-blue?style=for-the-badge)](https://harbour.github.io/)
[![Rust](https://img.shields.io/badge/Rust-000000?style=for-the-badge&logo=rust&logoColor=white)](https://www.rust-lang.org/)

---

## 📖 Sobre o Projeto

**Megusta** é uma linguagem de programação e transpilador que permite escrever código em uma sintaxe única e depois "transpilar" para diversas linguagens de destino, sem precisar reescrever a lógica de negócio.

### 💡 Ideia Principal

Ao trocar de linguagem de programação, **algumas partes do código não mudam**. De Java para Python, algumas partes do código não mudam, assim como de PHP para Rust.

### 🎯 Benefícios

- ✅ **Escrita única, execução múltipla** — Escreva uma vez, compile para várias linguagens
- ✅ **Consistência** — Mesma API em todas as linguagens
- ✅ **Produtividade** — Reduza o tempo de desenvolvimento
- ✅ **Aprendizado** — Aprenda conceitos de programação sem se preocupar com a sintaxe específica

---

## 🚀 Começando

### Instalação

```bash
# Clone o repositório
git clone https://github.com/iataganCursos/Megusta.git
cd megusta
```

### Uso Rápido

#### Python
```python
import sys
sys.path.append('ouka')
import ouka.Megusta as mg

r = mg.Megusta()
r.rPrintln("Olá, Mundo!")
```

#### JavaScript
```javascript
<script src="ouka/Megusta.js"></script>
<script>
let r = new Megusta();
r.rPrintln("Olá, Mundo!");
</script>
```

#### Java
```java
import ouka.Megusta;

public class Main {
    public static void main(String[] args) {
        Megusta r = new Megusta();
        r.rPrintln("Olá, Mundo!");
    }
}
```

---

## 📚 Documentação

| Linguagem | Documentação | Exemplos |
|---|---|---|
| Python | [Python Docs](chatgpt/python/) | [xMain.py](xMain.py) |
| JavaScript | [JS Docs](chatgpt/javascript/) | [xMain.html](xMain.html) |
| Java | [Java Docs](chatgpt/java/) | [xMain.java](xMain.java) |
| PHP | [PHP Docs](chatgpt/php/) | [xMain.php](xMain.php) |
| C | [C Docs](chatgpt/c/) | [xMain.c](xMain.c) |
| Clipper/Harbour | [Clipper Docs](chatgpt/clipper/) | [xMain.prg](xMain.prg) |
| Rust | [Rust Docs](chatgpt/rust/) | [rust/](rust/) |

### Tutorial Completo
📖 [Tutorial Megusta](https://iatagancursos.github.io/Megusta/tutorial-megusta/tutorial_megusta.html)

---

## 🛠️ API Reference

### Programação
| Método | Descrição |
|---|---|
| `rPrint(message)` | Imprime sem quebra de linha |
| `rPrintln(message)` | Imprime com quebra de linha |
| `rInput(prompt)` | Lê entrada do usuário |
| `rSaveFile(nome, conteudo)` | Salva arquivo |
| `rOpenFile(nome)` | Lê arquivo |
| `rOpenFileWeb(url)` | Busca URL (retorna body) |
| `rOpenFileWebStatus()` | Retorna código HTTP da última requisição |
| `rOpenProgram(comando)` | Executa programa do sistema |

### String
| Método | Descrição |
|---|---|
| `strReplace(original, var1, var2)` | Substitui substring |
| `strLength(s)` | Tamanho da string |
| `strSubstring(s, inicio, fim)` | Extrai substring |
| `strCharAt(s, pos)` | Caractere na posição |
| `strIndexOf(s, sub)` | Índice da substring (-1 se não encontrado) |
| `strLastIndexOf(s, sub)` | Último índice da substring |
| `strToLowerCase(s)` | Converte para minúsculas |
| `strToUpperCase(s)` | Converte para maiúsculas |
| `strEquals(s1, s2)` | Compara strings |
| `strSplit(s, delimiter)` | Divide string em array |
| `strPadStart(s, len, pad)` | Preenche início |
| `strPadEnd(s, len, pad)` | Preenche final |
| `strSearch(s, regex)` | Busca regex (retorna índice) |

### Data/Hora
| Método | Descrição |
|---|---|
| `dateDay()` | Dia do mês (1-31) |
| `dateWeekDay()` | Dia da semana (1=Domingo, 7=Sábado) |
| `dateMonth()` | Mês (1-12) |
| `dateYear()` | Ano |
| `dateHour24()` | Hora (0-23) |
| `dateMinute()` | Minuto (0-59) |
| `dateSecond()` | Segundo (0-59) |

### Array
| Método | Descrição |
|---|---|
| `arrAdd(lista, valor)` | Adiciona elemento |
| `arrAddAll(lista, ...valores)` | Adiciona vários elementos |
| `arrSet(lista, pos, valor)` | Define elemento na posição |
| `arrGet(lista, pos)` | Obtém elemento na posição |
| `arrSize(lista)` | Tamanho do array |
| `arrRemove(lista, pos)` | Remove elemento |
| `arrClear(lista)` | Limpa array |
| `arrContains(lista, valor)` | Verifica se contém |
| `arrIndexOf(lista, valor)` | Índice do elemento |
| `arrLastIndexOf(lista, valor)` | Último índice do elemento |

### Matemática
| Método | Descrição |
|---|---|
| `mathInt(s)` | Converte string para int |
| `mathNum(s)` | Converte string para float |
| `mathFloor(n)` | Arredonda para baixo |
| `mathCeil(n)` | Arredonda para cima |
| `mathRound(n)` | Arredonda |
| `mathAbs(n)` | Valor absoluto |
| `mathMax(a, b)` | Máximo |
| `mathMin(a, b)` | Mínimo |
| `mathPow(base, exp)` | Potência |
| `mathSqrt(n)` | Raiz quadrada |
| `mathRandom()` | Número aleatório [0, 1) |
| `mathPI` | Constante π |
| `mathSin(x)` | Seno |
| `mathCos(x)` | Cosseno |
| `mathTan(x)` | Tangente |

---

## 📝 Exemplos

### Exemplo Básico
```python
import sys
sys.path.append('ouka')
import ouka.Megusta as mg

r = mg.Megusta()

# Strings
r.rPrintln("Olá, " + r.rInput("Digite seu nome: ") + "!")

# Data
dia = r.dateDay()
mes = r.dateMonth()
ano = r.dateYear()
r.rPrintln(f"Hoje é {dia}/{mes}/{ano}")

# Matemática
r.rPrintln(f"2^10 = {r.mathPow(2, 10)}")
r.rPrintln(f"√144 = {r.mathSqrt(144)}")
```

### Exemplo com Arrays
```python
frutas = []
r.arrAdd(frutas, "Banana")
r.arrAdd(frutas, "Maçã")
r.arrAdd(frutas, "Uva")

for i in range(r.arrSize(frutas)):
    r.rPrintln(r.arrGet(frutas, i))
```

---

## 🔧 Contribuindo

1. Fork o repositório
2. Crie uma branch (`git checkout -b feature/AmazingFeature`)
3. Commit suas mudanças (`git commit -m 'Add some AmazingFeature'`)
4. Push para a branch (`git push origin feature/AmazingFeature`)
5. Abra um Pull Request

### Padrões de Código
- Siga o estilo existente de cada linguagem
- Adicione testes quando possível
- Atualize a documentação
- Mantenha a consistência da API

---

## 📄 Licença

Este projeto está sob a licença MIT. Veja o arquivo [LICENSE](LICENSE) para mais detalhes.

---

## 🙏 Agradecimentos

- **IATAGA Cursos** — Pelo projeto e manutenção
- **Comunidade Open Source** — Pelas bibliotecas e ferramentas utilizadas
- **Contribuidores** — Todos que ajudam a melhorar o Megusta

---

## 🔗 Links

- 📖 [Tutorial Completo](https://iatagancursos.github.io/Megusta/tutorial-megusta/tutorial_megusta.html)
- 🌐 [Página Principal](https://iatagancursos.github.io/Megusta/pagina-principal.html)
- 📦 [Download](https://github.com/iataganCursos/Megusta/releases)
- 💬 [Grupo Megusta](https://t.me/megusta)

---

*Correções feitas pela SNN Asael e fera do apocalipse* 🚀
