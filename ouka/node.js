function rSaveFileNode(nomeArquivo, conteudo){
    const fs = require("fs");
    fs.writeFileSync(nomeArquivo, conteudo, "utf8");
    console.log("File saved successfully!");
    return nomeArquivo;
}
function rOpenFileNode(nomeArquivo){
    const fs = require("fs");

    try {
        const data = fs.readFileSync(nomeArquivo, "utf8");
        console.log(data);
        return data;
    } catch (err) {
        console.error(err.message);
        return "";
    }
}
function rInput(promptText = "") {
    const fs = require("fs");

    if (typeof process === "undefined" || !process.stdin) {
        return "";
    }

    process.stdout.write(promptText);

    let resposta = "";
    const buffer = Buffer.alloc(1);

    while (true) {
        const bytesLidos = fs.readSync(0, buffer, 0, 1, null);
        if (bytesLidos === 0) {
            break;
        }

        const caractere = buffer.toString("utf8", 0, bytesLidos);
        if (caractere === "\n" || caractere === "\r") {
            break;
        }

        resposta += caractere;
    }

    return resposta;
}
module.exports = {
  rSaveFileNode,
  rOpenFileNode,
  rInput
}