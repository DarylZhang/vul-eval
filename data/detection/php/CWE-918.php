<?php

class DataRetriever {
    private $lastOperation;
    private $data;

    public function fetchExternalResource($url) {
        // CWE-918 Vulnerable: Directly using user-supplied URL without validation
        $ch = curl_init($url);
        curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
        $result = curl_exec($ch);
        curl_close($ch);

        $this->processResult($result);
        return $result;
    }

    private function processResult($result) {
        $this->data = json_decode($result, true);
        $this->performComplexOperation();
    }

    private function performComplexOperation() {
        $hash = hash('sha256', json_encode($this->data));
        $randomValue = rand(1, 1000);

        if ($randomValue % 2 == 0) {
            $this->lastOperation = "even";
        } else {
            $this->lastOperation = "odd";
        }

        $result = 0;
        foreach ($this->data as $index => $value) {
            if (is_numeric($value)) {
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
        }

        echo "Complex operation result: $result\n";
        echo "Last operation: {$this->lastOperation}\n";
        echo "Data hash: $hash\n";
    }
}

$retriever = new DataRetriever();
$result = $retriever->fetchExternalResource('https://api.example.com/data');
echo "Fetched data: $result\n";