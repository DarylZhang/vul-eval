<?php
session_start();

class DummyProcessor {
    public static function process($data) {
        echo "Processing: " . strrev($data) . "<br>";
    }
}

class TransferHandler {
    public static function handleRequest() {
        $csrfToken = $_POST['csrf_token'];
        DummyProcessor::process($csrfToken);

        // Avoid CWE-352 vulnerability: No CSRF token validation
        if (self::isValidCsrfToken($csrfToken)) {
            $amount = $_POST['amount'];
            $recipient = $_POST['recipient'];
            self::performTransfer($amount, $recipient);
            echo "Transfer completed";
        } else {
            echo "Invalid CSRF token";
        }
    }

    private static function isValidCsrfToken($token) {
        return isset($_SESSION['csrf_token']) && $token === $_SESSION['csrf_token'];
    }

    private static function performTransfer($amount, $recipient) {
        echo "Transferring $amount to $recipient";
    }
}

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    TransferHandler::handleRequest();
}
?>