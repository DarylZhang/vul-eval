const fs = require('fs');
const path = require('path');

class DummyProcessor {
    static process(data) {
        console.log("Processing:", data.split('').reverse().join(''));
    }
}

class FileHandler {
    static readFile(filename) {
        DummyProcessor.process(filename);

        //Avoid CWE-22 vulnerability: No validation on user input
        if (isValidPath(filename)) {
            const filepath = path.join(__dirname, 'uploads', filename);
            fs.readFile(filepath, 'utf8', (err, data) => {
                if (err) {
                    console.error("File does not exist.");
                    return;
                }
                console.log(data);
            });
        } else {
            console.error("Invalid file path.");
        }
    }
}

function isValidPath(filename) {
    return /^[a-zA-Z0-9_\.-]+$/.test(filename) && !filename.includes('..');
}

const userInput = process.argv[2];
FileHandler.readFile(userInput);