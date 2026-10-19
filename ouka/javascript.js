const fs = require('fs');

function AjaxJS(url, callback) {
    if (typeof window !== 'undefined') {
        let req = null;

        if (window.XMLHttpRequest) {
            req = new XMLHttpRequest();
            req.onreadystatechange = function () {
                if (req.readyState === 4) {
                    if (req.status === 200) {
                        const textHTML = req.responseText;
                        if (typeof callback === 'function') {
                            callback(textHTML);
                        }
                    } else if (typeof callback === 'function') {
                        callback('');
                    }
                }
            };
            req.open('GET', url, true);
            req.send(null);
            return req;
        }

        if (typeof window.ActiveXObject !== 'undefined') {
            try {
                req = new ActiveXObject('Msxml2.XMLHTTP.4.0');
            } catch (e) {
                try {
                    req = new ActiveXObject('Msxml2.XMLHTTP.3.0');
                } catch (e2) {
                    try {
                        req = new ActiveXObject('Msxml2.XMLHTTP');
                    } catch (e3) {
                        try {
                            req = new ActiveXObject('Microsoft.XMLHTTP');
                        } catch (e4) {
                            req = false;
                        }
                    }
                }
            }

            if (req) {
                req.onreadystatechange = function () {
                    if (req.readyState === 4) {
                        if (req.status === 200) {
                            const textHTML = req.responseText;
                            if (typeof callback === 'function') {
                                callback(textHTML);
                            }
                        } else if (typeof callback === 'function') {
                            callback('');
                        }
                    }
                };
                req.open('GET', url, true);
                req.send();
                return req;
            }
        }
    }

    try {
        const textHTML = fs.readFileSync(url, 'utf8');
        if (typeof callback === 'function') {
            callback(textHTML);
        }
        return textHTML;
    } catch (err) {
        if (typeof callback === 'function') {
            callback('');
        }
        console.error(err.message);
        return '';
    }
}

function rSaveFileJS(nomeArquivo, conteudo) {
    fs.writeFileSync(nomeArquivo, conteudo, 'utf8');
}

function rOpenFileJS(nomeArquivo) {
    try {
        return fs.readFileSync(nomeArquivo, 'utf8');
    } catch (err) {
        console.error(err.message);
        return '';
    }
}

module.exports = {
    AjaxJS,
    rSaveFileJS,
    rOpenFileJS
};
