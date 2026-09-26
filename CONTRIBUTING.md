# 🤝 Contribuindo para o Megusta

Obrigado por considerar contribuir para o Megusta! Este documento fornece diretrizes para contribuições.

## 📋 Índice

- [Código de Conduta](#código-de-conduta)
- [Como Contribuir](#como-contribuir)
- [Processo de Contribuição](#processo-de-contribuição)
- [Padrões de Código](#padrões-de-código)
- [Commit Messages](#commit-messages)
- [Reportando Bugs](#reportando-bugs)
- [Sugerindo Novos Recursos](#sugerindo-novos-recursos)

---

## Código de Conduta

Este projeto adere ao [Código de Conduta](CODE_OF_CONDUCT.md). Ao participar, você deve manter este código.

---

## Como Contribuir

### 🐛 Reportar Bugs

1. Verifique se o bug já foi reportado
2. Crie um issue com o template de bug
3. Inclua:
   - Descrição clara do problema
   - Passos para reproduzir
   - Comportamento esperado vs real
   - Versão da linguagem/ambiente

### 💡 Sugerir Novos Recursos

1. Verifique se o recurso já foi sugerido
2. Crie um issue com o template de feature
3. Explique:
   - O problema que o recurso resolve
   - Como o recurso funcionaria
   - Alternativas consideradas

---

## Processo de Contribuição

### 1️⃣ Fork e Clone

```bash
# Fork o repositório no GitHub
# Depois clone localmente
git clone https://github.com/seu-usuario/Megusta.git
cd megusta
```

### 2️⃣ Crie uma Branch

```bash
# Para correção de bug
git checkout -b fix/descricao-do-bug

# Para novo recurso
git checkout -b feature/nome-do-recurso

# Para documentação
git checkout -b docs/descricao
```

### 3️⃣ Faça as Mudanças

- Siga os padrões de código
- Adicione testes quando possível
- Atualize a documentação

### 4️⃣ Teste

```bash
# Teste Python
python3 xMain.py

# Teste C
gcc xMain.c -o xMain -lm -lcurl && ./xMain

# Teste Java
javac xMain.java && java xMain
```

### 5️⃣ Commit

```bash
git add .
git commit -m "tipo: descrição clara e concisa"
```

### 6️⃣ Push e Pull Request

```bash
git push origin nome-da-branch

# Abra um PR no GitHub
```

---

## Padrões de Código

### Python

```python
# Use 4 espaços (não tabs)
# Line length: 79 caracteres
# Docstrings em todas as classes/métodos

class Megusta:
    """Classe principal Megusta."""
    
    def rPrint(self, message):
        """Imprime mensagem sem quebra de linha."""
        print(message, end="")
```

### JavaScript

```javascript
// Use 4 espaços
// Arrow functions para callbacks
// Const/let em vez de var

class Megusta {
    /**
     * Imprime mensagem sem quebra de linha.
     * @param {string} message - Mensagem a imprimir
     */
    rPrint(message) {
        document.body.innerHTML += message;
    }
}
```

### Java

```java
// Use 4 espaços
// Javadoc em todas as classes/métodos
// Nome de variáveis camelCase

/**
 * Classe principal Megusta.
 */
public class Megusta {
    
    /**
     * Imprime mensagem sem quebra de linha.
     * @param message Mensagem a imprimir
     */
    public void rPrint(Object message) {
        System.out.print(message);
    }
}
```

### PHP

```php
<?php

/**
 * Classe principal Megusta.
 */
class Megusta {
    
    /**
     * Imprime mensagem sem quebra de linha.
     * @param string $message Mensagem a imprimir
     */
    public function rPrint($message) {
        echo $message;
    }
}
```

### C

```c
/**
 * Imprime mensagem sem quebra de linha.
 * @param message Mensagem a imprimir
 */
void rPrint(const char *message) {
    printf("%s", message);
}
```

### Clipper/Harbour

```harbour
/**
 * Imprime mensagem sem quebra de linha.
 * @param cMessage Mensagem a imprimir
*/
METHOD rPrint( cMessage ) CLASS Megusta
   ?? cMessage
RETURN NIL
```

---

## Commit Messages

Siga o formato [Conventional Commits](https://www.conventionalcommits.org/):

```
tipo: descrição clara

tipo: feat | fix | docs | style | refactor | test | chore
```

### Exemplos

```bash
# Correção de bug
fix(Python): corrige mapeamento de dateWeekDay

# Novo recurso
feat(JavaScript): adiciona strSearch com regex

# Documentação
docs: atualiza README com exemplos

# Refatoração
refactor(C): otimiza alocação em rOpenFile
```

---

## Reportando Bugs

Use o template de bug ao criar um issue:

```markdown
**Descrição do Bug**
[Descrição clara]

**Passos para Reproduzir**
1. 
2. 
3. 

**Comportamento Esperado**
[O que deveria acontecer]

**Comportamento Real**
[O que acontece]

**Ambiente**
- Linguagem: Python/JS/Java/PHP/C/Clipper
- Versão: 
- SO:
```

---

## Sugerindo Novos Recursos

Use o template de feature ao criar um issue:

```markdown
**Problema**
[Qual problema este recurso resolve]

**Solução Proposta**
[Como o recurso funcionaria]

**Alternativas Consideradas**
[Outras soluções possíveis]

**Exemplo de Uso**
[código de exemplo]
```

---

## 📚 Recursos Úteis

- [Documentação Python](https://docs.python.org/3/)
- [Documentação JavaScript](https://developer.mozilla.org/en-US/docs/Web/JavaScript)
- [Documentação Java](https://docs.oracle.com/en/java/)
- [Documentação PHP](https://www.php.net/manual/)
- [Documentação C](https://en.cppreference.com/w/c)
- [Documentação Harbour](https://harbour.github.io/doc/)

---

## 📄 Licença

Ao contribuir, você concorda que suas contribuições serão licenciadas sob a licença MIT do projeto.

---

*Obrigado por contribuir com o Megusta!* 🚀
