#include "hbclass.ch"

CLASS Megusta
   METHOD New() CONSTRUCTOR

   METHOD rPrint( cMessage )
   METHOD rPrintln( cMessage )
   METHOD rInput( cPrompt )
   METHOD rSaveFile( cArquivo, cConteudo )
   METHOD rOpenFile( cArquivo )
   METHOD rOpenProgram( cPrograma )
   METHOD rOpenFileWeb( cArquivo )
   METHOD strReplace( cOriginal, cVar1, cVar2 )
   METHOD strLength( cString )
   METHOD strSubstring( cString, nInicio, nFim )
   METHOD strCharAt( cString, nPos )
   METHOD strIndexOf(cadeia, subcadeia)
   METHOD strLastIndexOf(cadeia, subcadeia)
   METHOD strToLowerCase( cString )
   METHOD strToUpperCase( cString )
   METHOD strEquals( c1, c2 )
   METHOD strEqualsIgnoreCase( c1, c2 )
   METHOD strCompareTo(cadeia1, cadeia2)
   METHOD strCompareToIgnoreCase(cadeia1, cadeia2)
   METHOD strConcat( ... )
   METHOD strStartsWith( cString, cPrefix )
   METHOD strEndsWith( cString, cSuffix )
   METHOD strIncludes( cString, cSub )
   METHOD strSplit( cString, cDelimiter )
   METHOD strPadStart( cString, nLen, cPad )
   METHOD strPadEnd( cString, nLen, cPad )
   METHOD strRepeat( cString, nTimes )
   METHOD strSearch( cString, cSub )
   METHOD strTrim( cString )
   METHOD strTrimStart( cString )
   METHOD strTrimEnd( cString )
   METHOD strSlice( cString, nStart, nEnd )
   METHOD dateDay()
   METHOD dateWeekDay()
   METHOD dateMonth()
   METHOD dateYear()
   METHOD dateSetWeekDay( nAno, nMes, nDia )
   METHOD dateHour24()
   METHOD dateMinute()
   METHOD dateSecond()
   METHOD xArrLength( aLista )
   METHOD arrAddAll( aLista, ... )
   METHOD arrAdd( aLista, xValor )
   METHOD arrAddPos( aLista, nPos, xValor )
   METHOD arrSet( aLista, nPos, xValor )
   METHOD arrGet( aLista, nPos )
   METHOD arrSize( aLista )
   METHOD arrRemove( aLista, nPos )
   METHOD arrClear( aLista )
   METHOD arrContains( aLista, xValor )
   METHOD arrIndexOf( aLista, xValor )
   METHOD arrLastIndexOf( aLista, xValor )
   METHOD mathInt( cNumero )
   METHOD mathNum( cNumero )
   METHOD mathBool( cValor )
   METHOD mathFloor( n )
   METHOD mathCeil( n )
   METHOD mathRound( n )
   METHOD mathDecimalFormat( nNumero, cMascara )
   METHOD mathNumberFormat( nNumero, cLocale, cCountry )
   METHOD mathRandom()
   METHOD mathAbs( n )
   METHOD mathMax( n1, n2 )
   METHOD mathMin( n1, n2 )
   METHOD mathPow( base, expo )
   METHOD mathSqrt( n )
   METHOD mathCbrt( n )
   METHOD mathSignum( n )
   METHOD mathPI()
   METHOD mathConvertToRadians( graus )
   METHOD normalizeAngle(x)
   METHOD mathSin(x)
   METHOD mathCos(x)
   METHOD mathTan(x)
   METHOD mathAsin(x)
   METHOD mathAcos(x)
   METHOD mathAtan(x)
   METHOD mathSinh(x)
   METHOD mathCosh(x)
   METHOD mathTanh(x)
   METHOD mathAsinh(x)
   METHOD mathAcosh(x)
   METHOD mathAtanh(x)
   METHOD mathLog( nNumero )
   METHOD mathLog10( nNumero )
   METHOD mathLog2( nNumero )
   METHOD mathExp( nExpoente )
   METHOD mathLog1p( n )
   METHOD mathE()
   METHOD mathLN2()
   METHOD mathLOG2E()
   METHOD mathLN10()
   METHOD mathLOG10E()
   METHOD mathSQRT1_2()
   METHOD mathSQRT2()
   METHOD mathMaxArr( ... )
   METHOD mathMinArr( ... )
ENDCLASS


METHOD New() CLASS Megusta
return Self
/*
PROCEDURE Main

LOCAL x := 1.2

? "sin:", mathSin(x)
? "cos:", mathCos(x)
? "tan:", mathTan(x)

? "log:", mathLog(10)
? "log2:", mathLog2(8)

? "exp:", mathExp(2)

RETURN
*/
/* Megusta.prg */


/* =========================
   PRINT / INPUT
   ========================= */

METHOD rPrint( cMessage ) CLASS Megusta
   ?? cMessage
RETURN NIL

METHOD rPrintln( cMessage ) CLASS Megusta
   IF cMessage != NIL
      ?? cMessage         // Com quebra de linha
      ? ""
   ELSE 
      ? ""
   ENDIF
RETURN NIL

METHOD rInput( cPrompt ) CLASS Megusta
   LOCAL cValue := ""
   ?? cPrompt         // Exibe o prompt sem quebra de linha
   ACCEPT TO cValue   // Lê a entrada do usuário
   ? ""
RETURN cValue

/* =========================
   FILE
   ========================= */

METHOD rSaveFile( cArquivo, cConteudo ) CLASS Megusta
   LOCAL nHandle := FCreate( cArquivo )

   IF nHandle < 0
      ? "Erro ao criar arquivo."
      RETURN NIL
   ENDIF

   FWrite( nHandle, cConteudo )
   FClose( nHandle )

   ? "Arquivo", cArquivo, "salvo com sucesso."
RETURN NIL

METHOD rOpenFile( cArquivo ) CLASS Megusta
   LOCAL cConteudo := ""
   LOCAL cLinha

   IF ! File( cArquivo )
      ? "Erro: arquivo não encontrado."
      RETURN ""
   ENDIF

   cConteudo := MemoRead( cArquivo )

RETURN cConteudo

METHOD rOpenProgram( cPrograma ) CLASS Megusta
   RUN ( cPrograma )
RETURN NIL

METHOD rOpenFileWeb( cArquivo ) CLASS Megusta
   SISTEMA_OPERACIONAL = lower(os())
      IF ::strIndexOf(SISTEMA_OPERACIONAL, "windows") >= 1
            RUN ('cmd /c powershell -Command "Invoke-WebRequest -Uri ' + cArquivo + ' -OutFile x0001.txt"')
      ELSEIF ::strIndexOf(SISTEMA_OPERACIONAL, "linux") >= 1
            RUN ("wget -O x0001.txt " + cArquivo)
      ENDIF
      arquivo := ::rOpenFile("x0001.txt")
      ERASE "x0001.txt"
RETURN arquivo
/* =========================
   STRING
   ========================= */

METHOD strReplace( cOriginal, cVar1, cVar2 ) CLASS Megusta
RETURN StrTran( cOriginal, cVar1, cVar2 )

METHOD strLength( cString ) CLASS Megusta
RETURN Len( cString )

METHOD strSubstring( cString, nInicio, nFim ) CLASS Megusta
RETURN SubStr( cString, nInicio + 1, nFim - nInicio )

METHOD strCharAt( cString, nPos ) CLASS Megusta
RETURN SubStr( cString, nPos + 1, 1 )

METHOD strIndexOf(cadeia, subcadeia) CLASS Megusta
LOCAL pos
LOCAL len_cadeia, len_subcadeia

len_cadeia = LEN(cadeia)
len_subcadeia = LEN(subcadeia)

FOR pos = 1 TO len_cadeia - len_subcadeia + 1
IF SUBSTR(cadeia, pos, len_subcadeia) == subcadeia
RETURN pos
ENDIF
NEXT

RETURN 0 // Retorna 0 se a subcadeia não for encontrada

METHOD strLastIndexOf(cadeia, subcadeia) CLASS Megusta
LOCAL pos
LOCAL len_cadeia, len_subcadeia

len_cadeia = LEN(cadeia)
len_subcadeia = LEN(subcadeia)

FOR pos = len_cadeia TO 1 STEP -1
IF SUBSTR(cadeia, pos, len_subcadeia) == subcadeia
RETURN pos
ENDIF
NEXT

RETURN 0 // Retorna 0 se a subcadeia não for encontrada

METHOD strToLowerCase( cString ) CLASS Megusta
RETURN Lower( cString )

METHOD strToUpperCase( cString )
RETURN Upper( cString )

METHOD strEquals( c1, c2 ) CLASS Megusta
RETURN c1 == c2

METHOD strEqualsIgnoreCase( c1, c2 ) CLASS Megusta
RETURN Upper(c1) == Upper(c2)

METHOD strCompareTo(cadeia1, cadeia2) CLASS Megusta
IF cadeia1 == cadeia2
RETURN 0 // As cadeias são iguais
ELSE
IF cadeia1 < cadeia2
RETURN -1 // cadeia1 é menor que cadeia2
ELSE
RETURN 1 // cadeia1 é maior que cadeia2
ENDIF
ENDIF

METHOD strCompareToIgnoreCase(cadeia1, cadeia2) CLASS Megusta
LOCAL lowerCadeia1, lowerCadeia2
lowerCadeia1 = LOWER(cadeia1)
lowerCadeia2 = LOWER(cadeia2)

IF lowerCadeia1 == lowerCadeia2
RETURN 0 // As cadeias são iguais sem distinção entre maiúsculas e minúsculas
ELSE
IF lowerCadeia1 < lowerCadeia2
RETURN -1 // cadeia1 é menor que cadeia2 sem distinção entre maiúsculas e minúsculas
ELSE
RETURN 1 // cadeia1 é maior que cadeia2 sem distinção entre maiúsculas e minúsculas
ENDIF
ENDIF

// =========================
// Concatenação de strings (array de strings)
METHOD strConcat( ... ) CLASS Megusta
   LOCAL cResultado := ""
   LOCAL i
   LOCAL nParams := PCount()

   FOR i := 1 TO nParams
      cResultado += HB_PValue(i)
   NEXT

   RETURN cResultado


// StartsWith
METHOD strStartsWith( cString, cPrefix ) CLASS Megusta
   RETURN Left( cString, Len( cPrefix ) ) == cPrefix


// EndsWith
METHOD strEndsWith( cString, cSuffix ) CLASS Megusta
   RETURN Right( cString, Len( cSuffix ) ) == cSuffix


// Includes (contains)
METHOD strIncludes( cString, cSub ) CLASS Megusta
   RETURN At( cSub, cString ) > 0


// Split (retorna array)
METHOD strSplit( cString, cDelimiter ) CLASS Megusta
   LOCAL aResult := {}
   LOCAL nPos
   LOCAL i

   // Se delimitador é vazio, divide em caracteres individuais
   IF Empty( cDelimiter )
      FOR i := 1 TO Len( cString )
         AAdd( aResult, SubStr( cString, i, 1 ) )
      NEXT
      RETURN aResult
   ENDIF

   DO WHILE .T.
      nPos := At( cDelimiter, cString )
      IF nPos == 0
         AAdd( aResult, cString )
         EXIT
      ENDIF

      AAdd( aResult, Left( cString, nPos - 1 ) )
      cString := SubStr( cString, nPos + Len( cDelimiter ) )
   ENDDO

   RETURN aResult


// PadStart
METHOD strPadStart( cString, nLen, cPad ) CLASS Megusta
   LOCAL cFill := Replicate( cPad, nLen )

   RETURN Right( cFill + cString, nLen )


// PadEnd
METHOD strPadEnd( cString, nLen, cPad ) CLASS Megusta
   LOCAL cFill := Replicate( cPad, nLen )

   RETURN Left( cString + cFill, nLen )


// Repeat
METHOD strRepeat( cString, nTimes ) CLASS Megusta
   RETURN Replicate( cString, nTimes )


// Search (indexOf)
METHOD strSearch( cString, cSub ) CLASS Megusta
   LOCAL nPos := At( cSub, cString )
   RETURN iif( nPos > 0, nPos - 1, -1 )  // Java é 0-based


// Trim (ambos lados)
METHOD strTrim( cString ) CLASS Megusta
   RETURN AllTrim( cString )


// TrimStart (LTrim)
METHOD strTrimStart( cString ) CLASS Megusta
   RETURN LTrim( cString )


// TrimEnd (RTrim)
METHOD strTrimEnd( cString ) CLASS Megusta
   RETURN RTrim( cString )


// Slice (substring)
METHOD strSlice( cString, nStart, nEnd ) CLASS Megusta
   // Java é 0-based; Harbour é 1-based
   RETURN SubStr( cString, nStart + 1, nEnd - nStart )
// =========================
/* =========================
   DATE / TIME
   ========================= */

METHOD dateDay() CLASS Megusta
RETURN Day( Date() )

METHOD dateWeekDay() CLASS Megusta
RETURN Dow( Date() ) + 1

METHOD dateMonth() CLASS Megusta
RETURN Month( Date() )

METHOD dateYear() CLASS Megusta
RETURN Year( Date() )

METHOD dateSetWeekDay( nAno, nMes, nDia ) CLASS Megusta
RETURN Dow( STOD( Str(nAno,4) + StrZero(nMes,2) + StrZero(nDia,2) ) )

METHOD dateHour24() CLASS Megusta
RETURN Val( SubStr( Time(),1,2 ) )

METHOD dateMinute() CLASS Megusta
RETURN Val( SubStr( Time(),4,2 ) )

METHOD dateSecond() CLASS Megusta
RETURN Val( SubStr( Time(),7,2 ) )

/* =========================
   ARRAY
   ========================= */

METHOD xArrLength( aLista ) CLASS Megusta
RETURN Len( aLista )

METHOD arrAddAll( aLista, ... ) CLASS Megusta
   FOR i := 1 TO PCount()
      AAdd( aLista, PValue( i ) )
   ENDFOR
RETURN NIL

METHOD arrAdd( aLista, xValor ) CLASS Megusta
   AAdd( aLista, xValor )
RETURN NIL

METHOD arrAddPos( aLista, nPos, xValor ) CLASS Megusta
   AIns( aLista, nPos )
   aLista[nPos] := xValor
RETURN NIL

METHOD arrSet( aLista, nPos, xValor ) CLASS Megusta
   aLista[nPos] := xValor
RETURN NIL

METHOD arrGet( aLista, nPos ) CLASS Megusta
RETURN aLista[nPos]

METHOD arrSize( aLista ) CLASS Megusta
RETURN Len( aLista )

METHOD arrRemove( aLista, nPos ) CLASS Megusta
   ADel( aLista, nPos )
   ASize( aLista, Len(aLista)-1 )
RETURN NIL

METHOD arrClear( aLista ) CLASS Megusta
   ASize( aLista,0 )
RETURN NIL

METHOD arrContains( aLista, xValor ) CLASS Megusta
RETURN ASCan( aLista, xValor ) > 0

METHOD arrIndexOf( aLista, xValor ) CLASS Megusta
RETURN ASCan( aLista, xValor )

METHOD arrLastIndexOf( aLista, xValor ) CLASS Megusta
   LOCAL i
   FOR i := Len(aLista) TO 1 STEP -1
      IF aLista[i] == xValor
         RETURN i
      ENDIF
   NEXT
RETURN 0

/* =========================
   MATH
   ========================= */

METHOD mathInt( cNumero ) CLASS Megusta
RETURN Val( cNumero )

METHOD mathNum( cNumero ) CLASS Megusta
RETURN Val( cNumero )

METHOD mathBool( cValor ) CLASS Megusta
RETURN Upper(cValor) == "TRUE"

METHOD mathFloor( n ) CLASS Megusta
RETURN Int( n )

METHOD mathCeil( n ) CLASS Megusta
RETURN Int(n) + IIF( n > Int(n), 1, 0 )

METHOD mathRound( n ) CLASS Megusta
RETURN Round( n, 0 )

METHOD mathDecimalFormat( nNumero, cMascara ) CLASS Megusta
   LOCAL nDec := 0

   IF At(".", cMascara) > 0
      nDec := Len(cMascara) - At(".", cMascara)
   ENDIF

   RETURN Str( nNumero, 0, nDec )

METHOD mathNumberFormat( nNumero, cLocale, cCountry ) CLASS Megusta
   LOCAL cForm := Str( nNumero, 15, 2 )
   cForm := Trim(cForm)
   cForm := StrTran(cForm, ".", ",")
   RETURN cForm

METHOD mathRandom() CLASS Megusta
RETURN HB_Random()

METHOD mathAbs( n ) CLASS Megusta
RETURN Abs( n )

METHOD mathMax( n1, n2 ) CLASS Megusta
RETURN Max( n1, n2 )

METHOD mathMin( n1, n2 ) CLASS Megusta
RETURN Min( n1, n2 )

METHOD mathPow( base, expo ) CLASS Megusta
RETURN base ^ expo

METHOD mathSqrt( n ) CLASS Megusta
RETURN Sqrt( n )

METHOD mathCbrt( n ) CLASS Megusta
RETURN n ^ (1/3)

METHOD mathSignum( n ) CLASS Megusta
   IF n > 0
      RETURN 1
   ELSEIF n < 0
      RETURN -1
   ENDIF
RETURN 0

/* CONSTANTES */

METHOD mathPI() CLASS Megusta
RETURN 3.141592653589793

/* TRIGONOMETRIA */

METHOD mathConvertToRadians( graus ) CLASS Megusta
RETURN graus * ( ::mathPI() / 180 )

// =========================
//   TRIGONOMETRIA
//   =========================
// Quero implementar manualmente o sin, cos, tan (Série de Taylor) 
// sem precisar de biblioteca externa. Preciso "ensinar" ao CLIPPER 
// o sin, o cos e tan usando aproximações matemáticas.
// Implementações usando séries de Taylor para precisão razoável

#define PI 3.14159265358979323846
#define TWO_PI (2 * PI)

METHOD normalizeAngle(x) CLASS Megusta
   // reduz para [-PI, PI]
   x := x % TWO_PI

   IF x > PI
      x := x - TWO_PI
   ELSEIF x < -PI
      x := x + TWO_PI
   ENDIF

RETURN x

METHOD mathSin(x) CLASS Megusta
   LOCAL term, sum, n

   x := ::normalizeAngle(x)

   term := x
   sum  := x

   FOR n := 1 TO 10
      term := -term * x * x / ((2*n) * (2*n+1))
      sum  += term
   NEXT

RETURN sum

METHOD mathCos(x) CLASS Megusta
   LOCAL term, sum, n

   x := ::normalizeAngle(x)

   term := 1
   sum  := 1

   FOR n := 1 TO 10
      term := -term * x * x / ((2*n-1) * (2*n))
      sum  += term
   NEXT

RETURN sum

METHOD mathTan(x) CLASS Megusta
   LOCAL s, c

   // normaliza para [-PI, PI]
   x := ::normalizeAngle(x)

   // redução para [-PI/2, PI/2]
   IF x > PI/2
      x := x - PI
   ELSEIF x < -PI/2
      x := x + PI
   ENDIF

   // tratamento exato da singularidade
   IF x == PI/2 .OR. x == -PI/2
      RETURN NIL
   ENDIF

   c := ::mathCos(x)
   s := ::mathSin(x)

RETURN s / c

METHOD mathAsin(x) CLASS Megusta
   LOCAL n, term, sum

   sum  := x
   term := x

   FOR n := 1 TO 20
      term := term * ( (2*n - 1)*(2*n - 1) * x * x ) / ( (2*n)*(2*n + 1) )
      sum  += term
   NEXT

RETURN sum

METHOD mathAcos(x) CLASS Megusta
   LOCAL pi
   pi := 3.141592653589793

RETURN pi/2 - ::mathAsin(x)

METHOD mathAtan(x) CLASS Megusta
   LOCAL n, term, sum, xx, sign, pi

   pi := 3.141592653589793

   // Redução de domínio
   IF ABS(x) > 1
      IF x > 0
         RETURN pi/2 - ::mathAtan(1/x)
      ELSE
         RETURN -pi/2 - ::mathAtan(1/x)
      ENDIF
   ENDIF

   sum  := 0
   term := x
   xx   := x * x
   sign := 1

   FOR n := 1 TO 25 STEP 1
      sum  += sign * term / (2*n - 1)
      term *= xx
      sign := -sign
   NEXT

RETURN sum

METHOD mathSinh(x) CLASS Megusta
   LOCAL term := x
   LOCAL sum  := x
   LOCAL n    := 1
   LOCAL maxIter := 20  // ajuste conforme precisão desejada

   DO WHILE n <= maxIter
      term := term * (x * x) / ((2*n) * (2*n + 1))
      sum  := sum + term
      n++
   ENDDO

RETURN sum

METHOD mathCosh(x) CLASS Megusta
   LOCAL term := 1
   LOCAL sum  := 1
   LOCAL n    := 1
   LOCAL maxIter := 20

   DO WHILE n <= maxIter
      term := term * (x * x) / ((2*n - 1) * (2*n))
      sum  := sum + term
      n++
   ENDDO

RETURN sum

METHOD mathTanh(x) CLASS Megusta
   LOCAL s := ::mathSinh(x)
   LOCAL c := ::mathCosh(x)

   IF c == 0
      RETURN 0
   ENDIF

RETURN s / c

METHOD mathAsinh(x) CLASS Megusta
   LOCAL ax, x2, term, sum, n

   ax := ABS(x)

   // Usa Taylor para |x| pequeno
   IF ax < 0.5
      term := x
      sum  := x
      x2   := x * x

      FOR n := 1 TO 10
         term := -term * x2 * (2*n-1) / (2*n*(2*n+1))
         sum  += term
      NEXT

      RETURN sum
   ENDIF

   // Fórmula geral
   RETURN ::mathLog(x + ::mathSqrt(x*x + 1))

METHOD mathAcosh(x) CLASS Megusta
   LOCAL t, term, sum, n

   IF x < 1
      RETURN NIL
   ENDIF

   t := x - 1

   // Série perto de 1
   IF t < 0.5
      term := 1
      sum  := 1

      FOR n := 1 TO 10
         term := term * t
         sum  += term * ( (n=1)/12 - (n=2)*3/160 ) // simplificado
      NEXT

      RETURN ::mathSqrt(2*t) * sum
   ENDIF

   // Fórmula geral
   RETURN ::mathLog(x + ::mathSqrt(x*x - 1))

METHOD mathAtanh(x) CLASS Megusta
   LOCAL term, sum, x2, n

   IF ABS(x) >= 1
      RETURN NIL // fora do domínio
   ENDIF

   // Taylor
   IF ABS(x) < 0.5
      term := x
      sum  := x
      x2   := x * x

      FOR n := 1 TO 20
         term := term * x2
         sum  += term / (2*n + 1)
      NEXT

      RETURN sum
   ENDIF

   // Fórmula log
   RETURN 0.5 * ::mathLog((1+x)/(1-x))

/* =========================
   EXPONENCIAL
   ========================= */

METHOD mathLog( nNumero ) CLASS Megusta
RETURN log( nNumero )

METHOD mathLog10( nNumero ) CLASS Megusta
RETURN ::mathLog( nNumero ) / ::mathLog( 10 )

METHOD mathLog2( nNumero ) CLASS Megusta
RETURN ::mathLog( nNumero ) / ::mathLog( 2 )

METHOD mathExp( nExpoente ) CLASS Megusta
RETURN exp( nExpoente )

METHOD mathLog1p( n ) CLASS Megusta
RETURN ::mathLog( 1 + n )

METHOD mathE() CLASS Megusta
RETURN ::mathExp(1)

METHOD mathLN2() CLASS Megusta
RETURN ::mathLog(2)

METHOD mathLOG2E() CLASS Megusta
RETURN ::mathLog(2) / ::mathLog(::mathExp(1))

METHOD mathLN10() CLASS Megusta
RETURN ::mathLog(10)

METHOD mathLOG10E() CLASS Megusta
RETURN 1 / ::mathLog(10);

METHOD mathSQRT1_2() CLASS Megusta
RETURN ::mathSqrt( 0.5 )

METHOD mathSQRT2() CLASS Megusta
RETURN ::mathSqrt( 2 )

METHOD mathMaxArr( ... ) CLASS Megusta
   LOCAL nMax := -999999999
   LOCAL i
   FOR i := 1 TO PCount()
      IF PValue(i) > nMax
         nMax := PValue(i)
      ENDIF
   NEXT
RETURN nMax

METHOD mathMinArr( ... ) CLASS Megusta
   LOCAL nMin := 999999999
   LOCAL i
   FOR i := 1 TO PCount()
      IF PValue(i) < nMin
         nMin := PValue(i)
      ENDIF
   NEXT
RETURN nMin
