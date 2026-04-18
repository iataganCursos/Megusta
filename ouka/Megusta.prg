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

FUNCTION rPrint( cMessage )
   ?? cMessage
RETURN NIL

FUNCTION rPrintln( cMessage )
   IF cMessage != NIL
      ?? cMessage         // Com quebra de linha
      ? ""
   ELSE 
      ? ""
   ENDIF
RETURN NIL

FUNCTION rInput( cPrompt )
   LOCAL cValue := ""
   ?? cPrompt         // Exibe o prompt sem quebra de linha
   ACCEPT TO cValue   // Lê a entrada do usuário
   ? ""
RETURN cValue

/* =========================
   FILE
   ========================= */

FUNCTION rSaveFile( cArquivo, cConteudo )
   LOCAL nHandle := FCreate( cArquivo )

   IF nHandle < 0
      ? "Erro ao criar arquivo."
      RETURN NIL
   ENDIF

   FWrite( nHandle, cConteudo )
   FClose( nHandle )

   ? "Arquivo", cArquivo, "salvo com sucesso."
RETURN NIL

FUNCTION rOpenFile( cArquivo )
   LOCAL cConteudo := ""
   LOCAL cLinha

   IF ! File( cArquivo )
      ? "Erro: arquivo não encontrado."
      RETURN ""
   ENDIF

   cConteudo := MemoRead( cArquivo )

RETURN cConteudo

FUNCTION rOpenProgram( cPrograma )
   RUN ( cPrograma )
RETURN NIL

FUNCTION rOpenFileWeb( cArquivo )
   SISTEMA_OPERACIONAL = os()
      IF strIndexOf(SISTEMA_OPERACIONAL, "Windows") >= 1
            RUN ('cmd /c powershell -Command "Invoke-WebRequest -Uri ' + cArquivo + ' -OutFile x0001.txt"')
      ELSEIF strIndexOf(SISTEMA_OPERACIONAL, "Linux") >= 1
            RUN ("wget -O x0001.txt " + cArquivo)
      ENDIF
      arquivo := rOpenFile("x0001.txt")
      ERASE "x0001.txt"
RETURN arquivo
/* =========================
   STRING
   ========================= */

FUNCTION strReplace( cOriginal, cVar1, cVar2 )
RETURN StrTran( cOriginal, cVar1, cVar2 )

FUNCTION strLength( cString )
RETURN Len( cString )

FUNCTION strSubstring( cString, nInicio, nFim )
RETURN SubStr( cString, nInicio + 1, nFim - nInicio )

FUNCTION strCharAt( cString, nPos )
RETURN SubStr( cString, nPos + 1, 1 )

FUNCTION strIndexOf(cadeia, subcadeia)
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

FUNCTION strLastIndexOf(cadeia, subcadeia)
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

FUNCTION strToLowerCase( cString )
RETURN Lower( cString )

FUNCTION strToUpperCase( cString )
RETURN Upper( cString )

FUNCTION strEquals( c1, c2 )
RETURN c1 == c2

FUNCTION strEqualsIgnoreCase( c1, c2 )
RETURN Upper(c1) == Upper(c2)

FUNCTION strCompareTo(cadeia1, cadeia2)
IF cadeia1 == cadeia2
RETURN 0 // As cadeias são iguais
ELSE
IF cadeia1 < cadeia2
RETURN -1 // cadeia1 é menor que cadeia2
ELSE
RETURN 1 // cadeia1 é maior que cadeia2
ENDIF
ENDIF

FUNCTION strCompareToIgnoreCase(cadeia1, cadeia2)
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
/* =========================
   DATE / TIME
   ========================= */

FUNCTION dateDay()
RETURN Day( Date() )

FUNCTION dateWeekDay()
RETURN Dow( Date() ) + 1

FUNCTION dateMonth()
RETURN Month( Date() )

FUNCTION dateYear()
RETURN Year( Date() )

FUNCTION dateSetWeekDay( nAno, nMes, nDia )
RETURN Dow( STOD( Str(nAno,4) + StrZero(nMes,2) + StrZero(nDia,2) ) )

FUNCTION dateHour24()
RETURN Val( SubStr( Time(),1,2 ) )

FUNCTION dateMinute()
RETURN Val( SubStr( Time(),4,2 ) )

FUNCTION dateSecond()
RETURN Val( SubStr( Time(),7,2 ) )

/* =========================
   ARRAY
   ========================= */

FUNCTION xArrLength( aLista )
RETURN Len( aLista )

FUNCTION arrAddAll( aLista, ... )
   FOR i := 1 TO PCount()
      AAdd( aLista, PValue( i ) )
   ENDFOR
RETURN NIL

FUNCTION arrAdd( aLista, xValor )
   AAdd( aLista, xValor )
RETURN NIL

FUNCTION arrAddPos( aLista, nPos, xValor )
   AIns( aLista, nPos )
   aLista[nPos] := xValor
RETURN NIL

FUNCTION arrSet( aLista, nPos, xValor )
   aLista[nPos] := xValor
RETURN NIL

FUNCTION arrGet( aLista, nPos )
RETURN aLista[nPos]

FUNCTION arrSize( aLista )
RETURN Len( aLista )

FUNCTION arrRemove( aLista, nPos )
   ADel( aLista, nPos )
   ASize( aLista, Len(aLista)-1 )
RETURN NIL

FUNCTION arrClear( aLista )
   ASize( aLista,0 )
RETURN NIL

FUNCTION arrContains( aLista, xValor )
RETURN ASCan( aLista, xValor ) > 0

FUNCTION arrIndexOf( aLista, xValor )
RETURN ASCan( aLista, xValor )

FUNCTION arrLastIndexOf( aLista, xValor )
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

FUNCTION mathInt( cNumero )
RETURN Val( cNumero )

FUNCTION mathNum( cNumero )
RETURN Val( cNumero )

FUNCTION mathBool( cValor )
RETURN Upper(cValor) == "TRUE"

FUNCTION mathFloor( n )
RETURN Int( n )

FUNCTION mathCeil( n )
RETURN Int(n) + IIF( n > Int(n), 1, 0 )

FUNCTION mathRound( n )
RETURN Round( n, 0 )

FUNCTION mathDecimalFormat( nNumero, cMascara )
   LOCAL nDec := 0

   IF At(".", cMascara) > 0
      nDec := Len(cMascara) - At(".", cMascara)
   ENDIF

   RETURN Str( nNumero, 0, nDec )

FUNCTION mathNumberFormat( nNumero, cLocale, cCountry )
   LOCAL cForm := Str( nNumero, 15, 2 )
   cForm := Trim(cForm)
   cForm := StrTran(cForm, ".", ",")
   RETURN cForm

FUNCTION mathRandom()
RETURN HB_Random()

FUNCTION mathAbs( n )
RETURN Abs( n )

FUNCTION mathMax( n1, n2 )
RETURN Max( n1, n2 )

FUNCTION mathMin( n1, n2 )
RETURN Min( n1, n2 )

FUNCTION mathPow( base, expo )
RETURN base ^ expo

FUNCTION mathSqrt( n )
RETURN Sqrt( n )

FUNCTION mathCbrt( n )
RETURN n ^ (1/3)

FUNCTION mathSignum( n )
   IF n > 0
      RETURN 1
   ELSEIF n < 0
      RETURN -1
   ENDIF
RETURN 0

/* CONSTANTES */

FUNCTION mathPI()
RETURN 3.141592653589793

/* TRIGONOMETRIA */

FUNCTION mathConvertToRadians( graus )
RETURN graus * ( mathPI() / 180 )

// =========================
//   TRIGONOMETRIA
//   =========================
// Quero implementar manualmente o sin, cos, tan (Série de Taylor) 
// sem precisar de biblioteca externa. Preciso "ensinar" ao CLIPPER 
// o sin, o cos e tan usando aproximações matemáticas.
// Implementações usando séries de Taylor para precisão razoável

#define PI 3.14159265358979323846
#define TWO_PI (2 * PI)

FUNCTION normalizeAngle(x)
   // reduz para [-PI, PI]
   x := x % TWO_PI

   IF x > PI
      x := x - TWO_PI
   ELSEIF x < -PI
      x := x + TWO_PI
   ENDIF

RETURN x

FUNCTION mathSin(x)
   LOCAL term, sum, n

   x := normalizeAngle(x)

   term := x
   sum  := x

   FOR n := 1 TO 10
      term := -term * x * x / ((2*n) * (2*n+1))
      sum  += term
   NEXT

RETURN sum

FUNCTION mathCos(x)
   LOCAL term, sum, n

   x := normalizeAngle(x)

   term := 1
   sum  := 1

   FOR n := 1 TO 10
      term := -term * x * x / ((2*n-1) * (2*n))
      sum  += term
   NEXT

RETURN sum

FUNCTION mathTan(x)
   LOCAL s, c

   // normaliza para [-PI, PI]
   x := normalizeAngle(x)

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

   c := mathCos(x)
   s := mathSin(x)

RETURN s / c

FUNCTION mathAsin(x)
   LOCAL n, term, sum

   sum  := x
   term := x

   FOR n := 1 TO 20
      term := term * ( (2*n - 1)*(2*n - 1) * x * x ) / ( (2*n)*(2*n + 1) )
      sum  += term
   NEXT

RETURN sum

FUNCTION mathAcos(x)
   LOCAL pi
   pi := 3.141592653589793

RETURN pi/2 - mathAsin(x)

FUNCTION mathAtan(x)
   LOCAL n, term, sum, xx, sign, pi

   pi := 3.141592653589793

   // Redução de domínio
   IF ABS(x) > 1
      IF x > 0
         RETURN pi/2 - mathAtan(1/x)
      ELSE
         RETURN -pi/2 - mathAtan(1/x)
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

FUNCTION mathSinh(x)
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

FUNCTION mathCosh(x)
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

FUNCTION mathTanh(x)
   LOCAL s := mathSinh(x)
   LOCAL c := mathCosh(x)

   IF c == 0
      RETURN 0
   ENDIF

RETURN s / c

FUNCTION mathAsinh(x)
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
   RETURN mathLog(x + mathSqrt(x*x + 1))

FUNCTION mathAcosh(x)
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

      RETURN mathSqrt(2*t) * sum
   ENDIF

   // Fórmula geral
   RETURN mathLog(x + mathSqrt(x*x - 1))

FUNCTION mathAtanh(x)
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
   RETURN 0.5 * mathLog((1+x)/(1-x))

/* =========================
   EXPONENCIAL
   ========================= */

FUNCTION mathLog( nNumero )
RETURN Log( nNumero )

FUNCTION mathLog10( nNumero )
RETURN Log( nNumero ) / Log( 10 )

FUNCTION mathLog2( nNumero )
RETURN Log( nNumero ) / Log( 2 )

FUNCTION mathExp( nExpoente )
RETURN Exp( nExpoente )

FUNCTION mathLog1p( n )
RETURN Log( 1 + n )

FUNCTION mathE()
RETURN exp(1)

FUNCTION mathLN2()
RETURN log(2)

FUNCTION mathLOG2E()
RETURN log(2) / log(exp(1))

FUNCTION mathLN10()
RETURN log(10)

FUNCTION mathLOG10E()
RETURN 1 / log(10);

FUNCTION mathSQRT1_2()
RETURN Sqrt( 0.5 )

FUNCTION mathSQRT2()
RETURN Sqrt( 2 )

FUNCTION mathMaxArr( ... )
   LOCAL nMax := -999999999
   LOCAL i
   FOR i := 1 TO PCount()
      IF PValue(i) > nMax
         nMax := PValue(i)
      ENDIF
   NEXT
RETURN nMax

FUNCTION mathMinArr( ... )
   LOCAL nMin := 999999999
   LOCAL i
   FOR i := 1 TO PCount()
      IF PValue(i) < nMin
         nMin := PValue(i)
      ENDIF
   NEXT
RETURN nMin
