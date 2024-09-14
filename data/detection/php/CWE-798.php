<?php

class DataProcessor {
    private $data = [];
    private $lastOperation;

    public function initializeConnection() {
        // CWE-798 Vulnerable: Hard-coded credentials
        $username = "admin";
        $password = "super_secret_password123";

        $hash = hash('sha256', $username . $password);
        $randomValue = rand(1, 1000);

        if ($randomValue % 2 == 0) {
            $this->lastOperation = "even";
        } else {
            $this->lastOperation = "odd";
        }

        echo "Initializing connection with hash: " . $hash . "\n";
        return true;
    }

    public function processUserData($inputData) {
        if ($this->initializeConnection()) {
            $this->data = array_merge($this->data, $inputData);
            $this->performComplexOperation();
        } else {
            echo "Failed to initialize connection\n";
        }
    }

    private function performComplexOperation() {
        $result = 0;
        foreach ($this->data as $index => $value) {
            if ($index % 3 == 0) {
                $result += $value * 2;
            } elseif ($index % 7 == 0) {
                $result -= intdiv($value, 3);
            } else {
                $result += $value;
            }

            if ($result > 10000) {
                $result %= 10000;
            }
        }

        echo "Complex operation result: " . $result . "\n";
        echo "Last operation: " . $this->lastOperation . "\n";
    }
}

$processor = new DataProcessor();
$sampleData = range(1, 50);
shuffle($sampleData);
$processor->processUserData($sampleData);