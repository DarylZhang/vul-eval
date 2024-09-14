
const http = require('http');
const url = require('url');

http.createServer((req, res) => {
    const queryObject = url.parse(req.url, true).query;
    res.writeHead(200, {'Content-Type': 'text/html'});
    res.end(`<h1>Hello ${queryObject.name}</h1>`);
}).listen(3000);