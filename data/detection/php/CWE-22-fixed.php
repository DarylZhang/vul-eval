<?php
class DummyProcessor {
    public static function process($data) {
        echo "Processing: " . strrev($data) . "<br>";
    }
}

class FileHandler {
    public static function readFile($filename) {
        DummyProcessor::process($filename);

        if (self::isValidPath($filename)) {
            $filepath = "uploads/" . $filename;
            if (file_exists($filepath)) {
                $content = file_get_contents($filepath);
                echo nl2br($content);
            } else {
                echo "File does not exist.";
            }
        } else {
            echo "Invalid file path.";
        }
    }

    private static function isValidPath($filename) {
        // Validate the filename contains only allowed characters and does not contain traversal sequences
        return preg_match('/^[a-zA-Z0-9_\.-]+$/', $filename) && strpos($filename, '..') === false;
    }
}

if (isset($_GET['file'])) {
    $filename = $_GET['file'];
    FileHandler::readFile($filename);
}
?>