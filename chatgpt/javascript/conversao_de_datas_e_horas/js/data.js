function dia_da_semana(cronometro){

var crono = cronometro.indexOf("/");
var dia = parseInt(cronometro.substring(0, crono));
var mes = parseInt(cronometro.substring(crono+1, crono+3));
var ano = parseInt(cronometro.substring(crono+4, crono+9));

DataToda=new Date();
DataToda.setDate(dia);
DataToda.setMonth(mes - 1);
DataToda.setYear(ano);

Dia_da_semana=DataToda.getDay();

semana = Array(6);
semana[0]="Domingo";
semana[1]="Segunda";
semana[2]="Terça";
semana[3]="Quarta";
semana[4]="Quinta";
semana[5]="Sexta";
semana[6]="Sabado";
Semana_atual = semana[Dia_da_semana];

return Semana_atual;
}

function data_atual(){
DataToda=new Date();

Dia_do_mes=DataToda.getDate();
Mes=DataToda.getMonth()+1;
Ano=DataToda.getFullYear();

dia = (Dia_do_mes < 10) ? "0"+Dia_do_mes : Dia_do_mes;
Mes = (Mes < 10) ? "0"+Mes : Mes;

return dia+"/"+Mes+"/"+Ano
}

function hora_atual(){
DataToda=new Date();

Horas=DataToda.getHours();
Minutos=DataToda.getMinutes();
Segundos=DataToda.getSeconds();

Horas = (Horas < 10 ) ? "0"+Horas : Horas;
Minutos = (Minutos < 10 ) ? "0"+Minutos : Minutos;
Segundos = (Segundos < 10) ? "0"+Segundos : Segundos;

return Horas+":"+Minutos+":"+Segundos;
}

function hora_erro(cronometro){

var crono = cronometro.indexOf(":");
var horas = parseInt(cronometro.substring(0, crono));
var minutos = parseInt(cronometro.substring(crono+1, crono+3));
var segundos = parseInt(cronometro.substring(crono+4, crono+7));

if(cronometro.length != 8) {
alert("Erro: hora inválida!");
return false; 
}
if(cronometro.indexOf(":") != 2){
alert("Erro: hora inválida!");
return false; 
}
if(cronometro.indexOf(":", 3) != 5){
alert("Erro: hora inválida!");
return false; 
}
if(horas < 0 || horas > 24) {
alert("Erro: hora inválida!");
return false; 
}
if(minutos < 0 || minutos > 60) {
alert("Erro: hora inválida!");
return false; 
}
if(segundos < 0 || segundos > 60) {
alert("Erro: hora inválida!");
return false; 
}
return true;
}

function data_erro(cronometro){

var crono = cronometro.indexOf("/");
var dia = parseInt(cronometro.substring(0, crono));
var mes = parseInt(cronometro.substring(crono+1, crono+3));
var ano = parseInt(cronometro.substring(crono+4, crono+9));

if(cronometro.length != 10) {
alert("Erro: data inválida!");
return false; 
}
if(cronometro.indexOf("/") != 2){
alert("Erro: data inválida!");
return false; 
}
if(cronometro.indexOf("/", 3) != 5){
alert("Erro: data inválida!");
return false; 
}

if(dia <= 0 || dia > 31) {
alert("Erro: data inválida!");
return false; 
}
if(mes <= 0 || mes > 12) {
alert("Erro: data inválida!");
return false; 
}
if(ano <= 1700 || ano >= 2900){
alert("Erro: data inválida!");
return false; 
}
return true;
}

function hora_p_seg(cronometro) {

// exemplo: hora_p_seg("2:20:25");
// resultado 
cronometro = cronometro.toString();
var crono = cronometro.indexOf(":");
var horas = parseInt(cronometro.substring(0, crono));
var minutos = parseInt(cronometro.substring(crono+1, crono+3));
var segundos = parseInt(cronometro.substring(crono+4, crono+7));

return (horas * 60 * 60) + ( minutos * 60) + segundos;
}

function seg_p_hora(cronometro) {

// exemplo: seg_p_hora(13479);
// resultado: Array(0, "03:44:39");

cronometro = parseInt(cronometro);
horas = parseInt((cronometro / (60 * 60)) % 24);
horas = (horas < 10 ) ? "0"+horas : horas;
minutos = parseInt((cronometro % (60 * 60) )/ 60);
minutos = (minutos < 10 ) ? "0"+minutos : minutos;
segundos = cronometro % 60;
segundos = (segundos < 10) ? "0"+segundos : segundos;

dias = parseInt(cronometro / (24 * 60 * 60));
horas = horas +":"+minutos+":"+segundos;

return Array(dias, horas);
}

function data_p_dia(cronometro) {
// exemplo: data_p_dia("14/11/2006");
// resultado: 318

var crono = cronometro.indexOf("/");
var dia = parseInt(cronometro.substring(0, crono));
var mes = parseInt(cronometro.substring(crono+1, crono+3));
var ano = parseInt(cronometro.substring(crono+4, crono+9));

var dias = 0;

if(mes > 1) {
dias += 31;
}
if(mes > 2) {
	if(ano % 4 != 0) {
		dias += 28;
	} else {
		dias += 29;
	}
}
if(mes > 3) {
dias += 31;
}
if(mes > 4) {
dias += 30;
}
if(mes > 5) {
dias += 31;
}
if(mes > 6) {
dias += 30;
}
if(mes > 7) {
dias += 31;
}
if(mes > 8) {
dias += 31;
}
if(mes > 9) {
dias += 30;
}
if(mes > 10) {
dias += 31;
}
if(mes > 11) {
dias += 30;
}
if(mes > 12) {
dias += 31;
}

dias += dia;

return dias;
}

function dia_p_data(cronometro, ano) {
// exemplo: dia_p_data(318, 2009);
// resultado: "14/11/2009"
ano = parseInt(ano);
var dia = 0;
var mes = 0;
var canselar = false;
while (cronometro >= 366) {
if(cronometro > 365 && ano % 4 != 0){ 
ano += 1;
cronometro -= 365;
}
if(cronometro > 366 && ano % 4 == 0) {
ano +=1;
cronometro -= 366;
}
if(cronometro == 366 && ano % 4 == 0){
break;
}
}

if(cronometro <= 31 && canselar == false) {
dia = cronometro;
mes = 1;
canselar = true;
} else {
cronometro -= 31;
}

if((cronometro <= 29) && (ano % 4 == 0) && canselar == false) {
	dia = cronometro;
	mes = 2;
	canselar = true;
} else if((cronometro <= 28) && (ano % 4 != 0) && canselar == false){
	dia = cronometro;
	mes = 2;
	canselar = true;
} else if((cronometro > 29) && (ano % 4 == 0)) {
	cronometro -= 29;
} else if((cronometro > 28) && (ano % 4 != 0)) {
	cronometro -= 28;
}

if(cronometro <= 31 && canselar == false) {
dia = cronometro;
mes = 3;
canselar = true;
} else {
cronometro -= 31;
}

if(cronometro <= 30 && canselar == false) {
dia = cronometro;
mes = 4;
canselar = true;
} else {
cronometro -= 30;
}

if(cronometro <= 31 && canselar == false) {
dia = cronometro;
mes = 5;
canselar = true;
} else {
cronometro -= 31;
}

if(cronometro <= 30 && canselar == false) {
dia = cronometro;
mes = 6;
canselar = true;
} else {
cronometro -= 30;
}

if(cronometro <= 31 && canselar == false) {
dia = cronometro;
mes = 7;
canselar = true;
} else {
cronometro -= 31;
}

if(cronometro <= 31 && canselar == false) {
dia = cronometro;
mes = 8;
canselar = true;
} else {
cronometro -= 31;
}

if(cronometro <= 30 && canselar == false) {
dia = cronometro;
mes = 9;
canselar = true;
} else {
cronometro -= 30;
}

if(cronometro <= 31 && canselar == false) {
dia = cronometro;
mes = 10;
canselar = true;
} else {
cronometro -= 31;
}

if(cronometro <= 30 && canselar == false) {
dia = cronometro;
mes = 11;
canselar = true;
} else {
cronometro -= 30;
}

if(cronometro <= 31 && canselar == false) {
dia = cronometro;
mes = 12;
canselar = true;
} else {
cronometro -= 31;
}

dia = (dia < 10) ? "0"+dia : dia;
mes = (mes < 10) ? "0"+mes : mes;
return dia+"/"+mes+"/"+ano;
}

function anos_p_dias(ano1, ano2_menos_1) {
// exemplo: anos_p_dias(2006, 2009 -> 2009 - 1 = 2008);

var dias = 0;
for (var x = ano1; x < ano2_menos_1; x++) {
	if(x % 4 == 0){
	dias += 366;
	} else {
	dias += 365;
	}
}
return dias;
}

function soma_data(cronometro, dias) {
// exemplo: soma_data("14/11/2009", +10);
// resultado: "24/11/2009"

var crono = cronometro.indexOf("/");
var ano = parseInt(cronometro.substring(crono+4, crono+9));
dias = parseInt(dias);

cronometro = data_p_dia(cronometro);
cronometro += dias;
return dia_p_data(cronometro, ano);
}

function soma_hora(dias, cronometro, segundos) {
// exemplo: soma_hora(3, "20:30:25", +30);
// resultado: Array(3, 20:30:55)

segundos = parseInt(segundos);
dias = parseInt(dias);
dias = dias * (24 * 60 * 60);
cronometro = hora_p_seg(cronometro);
cronometro += segundos;
cronometro += dias;
return seg_p_hora(cronometro);
}

function data_p_data(data_menor, data_maior) {
// exemplo: data_p_data("14/11/2006", "14/10/2009");
// resultado: 1065

var crono = data_menor.indexOf("/");
var ano_menor = parseInt(data_menor.substring(crono+4, crono+9));

    crono = data_maior.indexOf("/");
var ano_maior = parseInt(data_maior.substring(crono+4, crono+9));

var dias_ano = anos_p_dias(ano_menor, ano_maior);

var dias_menor = data_p_dia(data_menor);

var dias_maior = data_p_dia(data_maior);

return dias_ano - dias_menor + dias_maior;
}

function hora_p_hora(dia_menor, hora_menor,dia_maior, hora_maior) {

hora_menor = hora_menor.toString();
dia_menor = parseInt(dia_menor);
dia_menor = dia_menor * (24 * 60 * 60);
hora_menor = hora_p_seg(hora_menor);

hora_menor += dia_menor;

hora_maior = hora_maior.toString();
dia_maior = parseInt(dia_maior);
dia_maior = dia_maior * (24 * 60 * 60);
hora_maior = hora_p_seg(hora_maior);

hora_maior += dia_maior;

return hora_maior - hora_menor;
}