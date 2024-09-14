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

        // CWE-22 vulnerability: No validation on user input
        const filepath = path.join(__dirname, 'uploads', filename);
        fs.readFile(filepath, 'utf8', (err, data) => {
            if (err) {
                console.error("File does not exist.");
                return;
            }
            console.log(data);
        });
    }
}

const userInput = process.argv[2];
FileHandler.readFile(userInput);