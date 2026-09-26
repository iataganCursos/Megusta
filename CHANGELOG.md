# 📝 Changelog

Todos as mudanças notáveis neste projeto serão documentadas neste arquivo.

O formato é baseado em [Keep a Changelog](https://keepachangelog.com/pt-BR/1.0.0/),
e este projeto adere ao [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

---

## [Unreleased]

### Adicionado
- `rOpenFileWebStatus()` em todas as linguagens
- `dateMouth()` como alias para `dateMonth()` em JS/Java

### Corrigido
- Mapeamento de `dateWeekDay()` em todas as linguagens (1=Domingo, 7=Sábado)
- `mathDecimalFormat()` conta apenas casas após o ponto decimal
- `strIndexOf()` retorna -1 quando não encontrado
- `strLastIndexOf()` retorna -1 quando não encontrado
- `strSplit("")` lança exceção consistente
- `strPadStart/End()` com default de espaço
- `mathMaxArr/MinArr()` validação de args vazios
- `rOpenFile()` alocação dinâmica em C
- `rInput()` implementação real em PHP
- `rOpenFileWeb()` não imprime status

### Melhorado
- README.md completo com documentação
- Adicionado CONTRIBUTING.md
- Adicionado CHANGELOG.md

---

## [1.0.0] - 2025-09-26

### Adicionado
- Implementação Python completa (ouka/Megusta.py)
- Implementação JavaScript completa (ouka/Megusta.js)
- Implementação Java completa (ouka/Megusta.java)
- Implementação PHP completa (ouka/Megusta.php)
- Implementação C completa (ouka/Megusta.c)
- Implementação Clipper/Harbour completa (ouka/Megusta.prg)
- Suporte Rust (rust/)
- Documentação por linguagem (chatgpt/)
- Exemplos em todas as linguagens (xMain.*)
- Tutorial completo (tutorial-megusta/)

### Funcionalidades
- **Programação**: rPrint, rPrintln, rInput, rSaveFile, rOpenFile, rOpenFileWeb, rOpenProgram
- **String**: strReplace, strLength, strSubstring, strCharAt, strIndexOf, strLastIndexOf, strToLowerCase, strToUpperCase, strEquals, strCompareTo, strConcat, strStartsWith, strEndsWith, strIncludes, strSplit, strPadStart, strPadEnd, strRepeat, strSearch, strTrim, strSlice
- **Data/Hora**: dateDay, dateWeekDay, dateMonth, dateYear, dateHour24, dateMinute, dateSecond, dateSetWeekDay
- **Array**: arrAdd, arrAddAll, arrSet, arrGet, arrSize, arrRemove, arrClear, arrContains, arrIndexOf, arrLastIndexOf, arrToArray, xArrLength
- **Matemática**: mathInt, mathNum, mathBool, mathFloor, mathCeil, mathRound, mathDecimalFormat, mathNumberFormat, mathRandom, mathAbs, mathMax, mathMin, mathMaxArr, mathMinArr, mathPow, mathSqrt, mathCbrt, mathSignum, mathPI, mathConvertToRadians, mathSin, mathCos, mathTan, mathAsin, mathAcos, mathAtan, mathSinh, mathCosh, mathTanh, mathAsinh, mathAcosh, mathAtanh, mathLog, mathLog10, mathExp, mathLog2, mathLog1p, mathE, mathLN2, mathLOG2E, mathLN10, mathLOG10E, mathSQRT1_2, mathSQRT2

---

## Histórico de Versões

### Versão 1.0.0 (Atual)
- Primeira versão estável
- 6 linguagens suportadas
- 100+ métodos implementados
- Documentação completa

---

## Notas de Versão

### v1.0.0
- Lançamento inicial do projeto
- Foco em consistência de API entre linguagens
- Correção de bugs críticos de data/hora
- Implementação de métodos string/array/math

---

*Este changelog foi atualizado pela última vez em 26 de setembro de 2025.*
