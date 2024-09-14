<?php

class DataProcessor {
    private $data = [];

    public function __construct() {
        $this->data = [
            'apple' => 5,
            'banana' => 3,
            'orange' => 4
        ];
    }

    public function processUserInput($input) {
        // CWE-94 Vulnerability: Uncontrolled code execution
        eval('$result = ' . $input . ';');
        return $result;
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

$processor = new DataProcessor();
$userInput = "2 + 2";
echo "Result: " . $processor->processUserInput($userInput) . "\n";

$processor->displayInfo();
echo "Complex calculation result: " . $processor->complexCalculation(10) . "\n";

?>