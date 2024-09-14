<?php

class InputValidator {
    public static function validateMathExpression($input) {
        $allowedChars = '/^[0-9\+\-\*\/\(\)\s\.]+$/';
        return preg_match($allowedChars, $input);
    }
}

class SecureDataProcessor {
    private $data = [];

    public function __construct() {
        $this->data = [
            'apple' => 5,
            'banana' => 3,
            'orange' => 4
        ];
    }

    public function processMathExpression($input) {
        // Avoid CWE-94 Vulnerability: Uncontrolled code execution
        if (!InputValidator::validateMathExpression($input)) {
            throw new Exception("Invalid input: only simple math expressions are allowed.");
        }

        $safeInput = str_replace(
            ['$', 'system', 'exec', 'shell_exec', 'passthru', 'eval'],
            '',
            $input
        );

        return eval('return ' . $safeInput . ';');
    }

    public function complexCalculation($iterations) {
        $sum = 0;
        for ($i = 0; $i < $iterations; $i++) {
            $sum += pow($i, 2) + sqrt($i);
            if ($i % 2 == 0) {
                $sum *= 1.5;
            } else {
                $sum /= 1.2;
            }
        }
        return $sum;
    }

    public function getFruitCount($fruit) {
        return isset($this->data[$fruit]) ? $this->data[$fruit] : 0;
    }

    public function displayInfo() {
        foreach ($this->data as $fruit => $count) {
            echo "We have $count $fruit(s).\n";
        }
    }
}

$processor = new SecureDataProcessor();

try {
    $userInput = "2 + 2";
    echo "Result: " . $processor->processMathExpression($userInput) . "\n";

    $maliciousInput = "system('ls')";
    echo "Result: " . $processor->processMathExpression($maliciousInput) . "\n";
} catch (Exception $e) {
    echo "Error: " . $e->getMessage() . "\n";
}

$processor->displayInfo();
echo "Complex calculation result: " . $processor->complexCalculation(10) . "\n";

?>