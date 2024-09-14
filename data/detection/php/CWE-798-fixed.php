<?php

class SecureDataProcessor {
    private $data = [];
    private $lastOperation;
    private $credentialManager;

    public function __construct() {
        $this->credentialManager = new CredentialManager();
    }

    public function initializeConnection() {
        // Avoid CWE-798 Vulnerable: Hard-coded credentials
        list($username, $password) = $this->credentialManager->getCredentials();

        // Dummy logic to increase complexity
        $hash = hash('sha256', $username . $password);
        $randomValue = rand(1, 1000);

        if ($randomValue % 2 == 0) {
            $this->lastOperation = "even";
        } else {
            $this->lastOperation = "odd";
        }

        echo "Initializing connection with hash: " . $hash . "\n";
        return $this->credentialManager->validateCredentials($username, $password);
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

class CredentialManager {
    private $config;

    public function __construct() {
        $this->config = parse_ini_file('config.ini', true);
    }

    public function getCredentials() {
        return [
            $this->config['database']['username'],
            $this->config['database']['password']
        ];
    }

    public function validateCredentials($username, $password) {
        // In a real-world scenario, this would involve checking against a secure database or service
        return $username === $this->config['database']['username'] &&
               $password === $this->config['database']['password'];
    }
}

// Usage
$processor = new SecureDataProcessor();
$sampleData = range(1, 50);
shuffle($sampleData);
$processor->processUserData($sampleData);