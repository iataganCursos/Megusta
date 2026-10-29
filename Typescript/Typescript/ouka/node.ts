function rSaveFileNode(nomeArquivo:string, conteudo:string){
    const fs = require("fs");
    fs.writeFileSync(nomeArquivo, conteudo, "utf8");
    console.log("File saved successfully!");
    return nomeArquivo;
}
function rOpenFileNode(nomeArquivo:string){
    const fs = require("fs");

    try {
        const data = fs.readFileSync(nomeArquivo, "utf8");
        console.log(data);
        return data;
    } catch (err: unknown) {
        console.error(err instanceof Error ? err.message : err);
        return "";
    }
}
let pendingInput = Buffer.alloc(0);

function rInput(promptText:string = "") {
    const fs = require("fs");

    if (typeof process === "undefined" || !process.stdin) {
        return "";
    }

    process.stdout.write(promptText);

    while (true) {
        const newlineIndex = pendingInput.indexOf(10);
        if (newlineIndex !== -1) {
            let line = pendingInput.subarray(0, newlineIndex);
            pendingInput = pendingInput.subarray(newlineIndex + 1);
            if (line[line.length - 1] === 13) {
                line = line.subarray(0, -1);
            }
            return line.toString("utf8");
        }

        const buffer = Buffer.alloc(1024);
        const bytesLidos = fs.readSync(0, buffer, 0, buffer.length, null);
        if (bytesLidos === 0) {
            const resposta = pendingInput.toString("utf8");
            pendingInput = Buffer.alloc(0);
            return resposta;
        }

        pendingInput = Buffer.concat([pendingInput, buffer.subarray(0, bytesLidos)]);
    }
}
module.exports = {
  rSaveFileNode,
  rOpenFileNode,
  rInput
}