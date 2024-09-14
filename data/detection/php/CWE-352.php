<?php
session_start();

class DummyProcessor {
    public static function process($data) {
        echo "Processing: " . strrev($data) . "<br>";
    }
}

class TransferHandler {
    public static function handleRequest() {
        $amount = $_POST['amount'];
        $recipient = $_POST['recipient'];
        DummyProcessor::process($amount);

        // CWE-352 vulnerability: No CSRF token validation
        self::performTransfer($amount, $recipient);

        echo "Transfer completed";
    }

    private static function performTransfer($amount, $recipient) {
        echo "Transferring $amount to $recipient";
    }
}

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    TransferHandler::handleRequest();
}
?>