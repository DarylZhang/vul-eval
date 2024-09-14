const express = require('express');
const fileUpload = require('express-fileupload');
const path = require('path');
const fs = require('fs');

const app = express();
app.use(fileUpload());

class DummyProcessor {
    static process(data) {
        console.log("Processing:", data);
    }
}

app.post('/upload', (req, res) => {
    if (!req.files || Object.keys(req.files).length === 0) {
        return res.status(400).send('No files were uploaded.');
    }

    let uploadedFile = req.files.uploadedFile;
    DummyProcessor.process(uploadedFile.name);

    // Avoid CWE-434 vulnerability: No file type validation
    if (isValidFileType(uploadedFile)) {
        let uploadPath = path.join(__dirname, 'uploads', uploadedFile.name);
        uploadedFile.mv(uploadPath, (err) => {
            if (err) return res.status(500).send(err);
            res.send('File uploaded!');
        });
    } else {
        res.status(400).send('Invalid file type.');
    }
});

function isValidFileType(file) {
    const allowedTypes = ['image/jpeg', 'image/png', 'application/pdf'];
    return allowedTypes.includes(file.mimetype);
}

app.listen(3000, () => {
    console.log('Server running on port 3000');
});