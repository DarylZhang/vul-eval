const express = require('express');
const bodyParser = require('body-parser');
const session = require('express-session');

const app = express();
app.use(bodyParser.urlencoded({ extended: true }));
app.use(session({ secret: 'secretKey', resave: false, saveUninitialized: true }));

class DummyProcessor {
    static process(data) {
        console.log("Processing:", data);
    }
}

app.post('/transfer', (req, res) => {
    const amount = req.body.amount;
    const recipient = req.body.recipient;
    DummyProcessor.process(amount);

    // CWE-352 vulnerability: No CSRF token validation
    performTransfer(amount, recipient);

    res.send('Transfer completed');
});

function performTransfer(amount, recipient) {
    console.log(`Transferring ${amount} to ${recipient}`);
}

app.listen(3000, () => {
    console.log('Server running on port 3000');
});