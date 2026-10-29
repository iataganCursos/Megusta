const fs = typeof require === "function" ? require("fs") : null;

type TextCallback = (textHTML: string) => void;

interface Window {
    AjaxJS: typeof AjaxJS;
    rSaveFileJS: typeof rSaveFileJS;
    rOpenFileJS: typeof rOpenFileJS;
}

function openResponse(textHTML: string, callback?: TextCallback) {
    const fallbackHandler = (globalThis as typeof globalThis & {
        rOpenFileWebJS?: TextCallback;
    }).rOpenFileWebJS;
    const handler = callback
        ?? fallbackHandler;
    handler?.(textHTML);
}

function AjaxJS(url: string, callback?: TextCallback): XMLHttpRequest | string {
    if (typeof window !== "undefined") {
        const isAbsoluteUrl = /^[a-z][a-z\d+.-]*:/i.test(url);
        if (window.location.protocol === "file:" && !isAbsoluteUrl) {
            const savedContent = window.localStorage.getItem(url);
            if (savedContent !== null) {
                openResponse(savedContent, callback);
                return savedContent;
            }
        }

        const request = new XMLHttpRequest();
        request.onreadystatechange = function () {
            if (request.readyState === XMLHttpRequest.DONE) {
                openResponse(request.status === 200 ? request.responseText : "", callback);
            }
        };
        request.open("GET", url, true);
        request.send();
        return request;
    }

    if (!fs) {
        throw new Error("File access is unavailable in this environment.");
    }

    try {
        const textHTML = fs.readFileSync(url, "utf8");
        callback?.(textHTML);
        return textHTML;
    } catch (error: unknown) {
        callback?.("");
        console.error(error instanceof Error ? error.message : error);
        return "";
    }
}

function rSaveFileJS(nomeArquivo: string, conteudo: string): void {
    if (typeof window !== "undefined") {
        window.localStorage.setItem(nomeArquivo, conteudo);
        return;
    }
    if (!fs) {
        throw new Error("File access is unavailable in this environment.");
    }
    fs.writeFileSync(nomeArquivo, conteudo, "utf8");
}

function rOpenFileJS(nomeArquivo: string): string | null {
    if (typeof window !== "undefined") {
        return window.localStorage.getItem(nomeArquivo);
    }
    if (!fs) {
        throw new Error("File access is unavailable in this environment.");
    }
    try {
        return fs.readFileSync(nomeArquivo, "utf8");
    } catch (error: unknown) {
        console.error(error instanceof Error ? error.message : error);
        return "";
    }
}

if (typeof module !== "undefined" && module.exports) {
    module.exports = {
        AjaxJS,
        rSaveFileJS,
        rOpenFileJS
    };
} else if (typeof window !== "undefined") {
    window.AjaxJS = AjaxJS;
    window.rSaveFileJS = rSaveFileJS;
    window.rOpenFileJS = rOpenFileJS;
}
