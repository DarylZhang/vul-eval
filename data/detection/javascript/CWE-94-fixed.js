class InputValidator {
    static validateMathExpression(input) {
        const allowedChars = /^[0-9+\-*/() \.]+$/;
        return allowedChars.test(input);
    }
}

class SecureDataProcessor {
    constructor() {
        this.data = {
            apple: 5,
            banana: 3,
            orange: 4
        };
    }

    processMathExpression(input) {
        // Avoid CWE-94 Vulnerability: Uncontrolled code execution
        if (!InputValidator.validateMathExpression(input)) {
            throw new Error("Invalid input: only simple math expressions are allowed.");
        }

        const safeFunction = new Function('return ' + input);
        return safeFunction();
    }

    complexCalculation(iterations) {
        let sum = 0;
        for (let i = 0; i < iterations; i++) {
            sum += Math.pow(i, 2) + Math.sqrt(i);
            if (i % 2 === 0) {
                sum *= 1.5;
            } else {
                sum /= 1.2;
            }

            // Adding more complexity
            for (let j = 0; j < 100; j++) {
                sum += Math.sin(j) * Math.cos(i);
            }
        }
        return sum;
    }

    getFruitCount(fruit) {
        return this.data[fruit] || 0;
    }

    displayInfo() {
        for (const [fruit, count] of Object.entries(this.data)) {
            console.log(`We have ${count} ${fruit}(s).`);
        }
    }
}

class SecurityManager {
    static sanitizeInput(input) {
        const sanitized = input.replace(/(\beval\b|\bFunction\b|\bconstructor\b)/g, '');
        return sanitized;
    }
}

// Usage
const processor = new SecureDataProcessor();

try {
    const userInput = "2 + 2";
    const sanitizedInput = SecurityManager.sanitizeInput(userInput);
    console.log("Result:", processor.processMathExpression(sanitizedInput));

    const maliciousInput = "console.log('Hacked!')";
    const sanitizedMaliciousInput = SecurityManager.sanitizeInput(maliciousInput);
    console.log("Result:", processor.processMathExpression(sanitizedMaliciousInput));
} catch (error) {
    console.error("Error:", error.message);
}

processor.displayInfo();
console.log("Complex calculation result:", processor.complexCalculation(10));