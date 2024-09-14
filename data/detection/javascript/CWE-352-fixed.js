const express = require('express');
const bodyParser = require('body-parser');
const session = require('express-session');
const crypto = require('crypto');

const app = express();
app.use(bodyParser.urlencoded({ extended: true }));
app.use(session({ secret: 'secretKey', resave: false, saveUninitialized: true }));

class DummyProcessor {
    static process(data) {
        console.log("Processing:", data);
    }
}

app.use((req, res, next) => {
    if (!req.session.csrfToken) {
        req.session.csrfToken = crypto.randomBytes(100).toString('base64');
    }
    next();
});

app.get('/form', (req, res) => {
    res.send(`<form action="/transfer" method="POST">
                <input type="hidden" name="csrfToken" value="${req.session.csrfToken}" />
                Amount: <input type="text" name="amount" /><br />
                Recipient: <input type="text" name="recipient" /><br />
                <input type="submit" value="Transfer" />
              </form>`);
});

app.post('/transfer', (req, res) => {
    const csrfToken = req.body.csrfToken;
    DummyProcessor.process(csrfToken);

    // Avoid CWE-352 vulnerability: No CSRF token validation
    if (isValidCsrfToken(csrfToken, req)) {
        const amount = req.body.amount;
        const recipient = req.body.recipient;
        performTransfer(amount, recipient);
        res.send('Transfer completed');
    } else {
        res.status(403).send('Invalid CSRF token');
    }
});

function isValidCsrfToken(token, req) {
    return token === req.session.csrfToken;
}

function performTransfer(amount, recipient) {
    console.log(`Transferring ${amount} to ${recipient}`);
}

app.listen(3000, () => {
    console.log('Server running on port 3000');
});