/* Megusta.prg */

#include "hbclass.ch"

/* =========================
   PRINT / INPUT
   ========================= */

FUNCTION rPrint( cMessage )
   ?? cMessage
RETURN NIL

FUNCTION rPrintln( cMessage )
   ? cMessage
RETURN NIL

FUNCTION rPrintln2()
   ?
RETURN NIL

FUNCTION rInput( cPrompt )
   LOCAL cValue := ""
   ?? cPrompt
   INPUT cValue
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

FUNCTION strIndexOf( cString, cBusca )
RETURN At( cBusca, cString ) - 1

FUNCTION strLastIndexOf( cString, cBusca )
RETURN RAt( cBusca, cString ) - 1

FUNCTION strToLowerCase( cString )
RETURN Lower( cString )

FUNCTION strToUpperCase( cString )
RETURN Upper( cString )

FUNCTION strEquals( c1, c2 )
RETURN c1 == c2

FUNCTION strEqualsIgnoreCase( c1, c2 )
RETURN Upper(c1) == Upper(c2)


/* =========================
   DATE / TIME
   ========================= */

FUNCTION dateDay()
RETURN Day( Date() )

FUNCTION dateWeekDay()
RETURN Dow( Date() )

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

FUNCTION mathE()
RETURN 2.718281828459045


/* TRIGONOMETRIA */

FUNCTION mathConvertToRadians( graus )
RETURN graus * ( mathPI() / 180 )

/* =========================
   TRIGONOMETRIA
   ========================= */

FUNCTION mathSin( nAngulo )
RETURN Sin( nAngulo )

FUNCTION mathCos( nAngulo )
RETURN Cos( nAngulo )

FUNCTION mathTan( nAngulo )
RETURN Tan( nAngulo )

FUNCTION mathAsin( nValor )
RETURN ASin( nValor )

FUNCTION mathAcos( nValor )
RETURN ACos( nValor )

FUNCTION mathAtan( nValor )
RETURN ATan( nValor )

FUNCTION mathSinh( nValor )
RETURN Sinh( nValor )

FUNCTION mathCosh( nValor )
RETURN Cosh( nValor )

FUNCTION mathTanh( nValor )
RETURN Tanh( nValor )


/* =========================
   HIPERBÓLICAS INVERSAS
   ========================= */

FUNCTION mathAsinh( x )
RETURN Log( x + Sqrt( x*x + 1 ) )

FUNCTION mathAcosh( x )
RETURN Log( x + Sqrt( x*x - 1 ) )

FUNCTION mathAtanh( x )
RETURN 0.5 * Log( (1 + x) / (1 - x) )


/* =========================
   LOGARITMOS
   ========================= */

FUNCTION mathLog( nNumero )
RETURN Log( nNumero )

FUNCTION mathLog10( nNumero )
RETURN Log10( nNumero )

FUNCTION mathLog2( nNumero )
RETURN Log( nNumero ) / Log( 2 )


FUNCTION mathLog1p( nValor )
RETURN Log( 1 + nValor )


/* =========================
   EXPONENCIAL
   ========================= */

FUNCTION mathExp( nExpoente )
RETURN Exp( nExpoente )


/* =========================
   CONSTANTES
   ========================= */

FUNCTION mathE()
RETURN 2.718281828459045

FUNCTION mathLN2()
RETURN Log(2.0)

FUNCTION mathLOG2E()
RETURN Log(2.0) / Log( Exp(1.0) )

FUNCTION mathLN10()
RETURN Log(10.0)

FUNCTION mathLOG10E()
RETURN 1.0 / Log(10.0)