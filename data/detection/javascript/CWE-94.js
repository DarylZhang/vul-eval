class DataProcessor {
    constructor() {
        this.data = {
            apple: 5,
            banana: 3,
            orange: 4
        };
    }

    processUserInput(input) {
        // CWE-94 Vulnerability: Uncontrolled code execution
        return eval(input);
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

const processor = new DataProcessor();
const userInput = "2 + 2"; // Harmless input
console.log("Result:", processor.processUserInput(userInput));

processor.displayInfo();
console.log("Complex calculation result:", processor.complexCalculation(10));