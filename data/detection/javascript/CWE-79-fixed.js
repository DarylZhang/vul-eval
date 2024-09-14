const http = require('http');
const url = require('url');

http.createServer((req, res) => {
    const queryObject = url.parse(req.url, true).query;
    const safeName = escapeHtml(queryObject.name);
    res.writeHead(200, {'Content-Type': 'text/html'});
    res.end(`<h1>Hello ${safeName}</h1>`);
}).listen(3000);

function escapeHtml(unsafe) {
    return unsafe
        .replace(/&/g, "&amp;")
        .replace(/</g, "&lt;")
        .replace(/>/g, "&gt;")
        .replace(/"/g, "&quot;")
        .replace(/'/g, "&#039;");
}