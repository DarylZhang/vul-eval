<?php
class DummyProcessor {
    public static function process($data) {
        echo "Processing: " . strrev($data) . "<br>";
    }
}

class FileHandler {
    public static function readFile($filename) {
        DummyProcessor::process($filename);

        // CWE-22 vulnerability: No validation on user input
        $filepath = "uploads/" . $filename;
        if (file_exists($filepath)) {
            $content = file_get_contents($filepath);
            echo nl2br($content);
        } else {
            echo "File does not exist.";
        }
    }
}

if (isset($_GET['file'])) {
    $filename = $_GET['file'];
    FileHandler::readFile($filename);
}
?>