<?php
class DummyProcessor {
    public static function process($data) {
        // Simulate processing user input
        echo "Processing: " . strrev($data) . "<br>";
    }
}

class FileHandler {
    public static function handleUpload() {
        if ($_FILES['uploadedFile']['error'] === UPLOAD_ERR_OK) {
            $filename = $_FILES['uploadedFile']['name'];
            DummyProcessor::process($filename);

            // CWE-434 vulnerability: No file type validation
            $uploadPath = 'uploads/' . basename($filename);
            move_uploaded_file($_FILES['uploadedFile']['tmp_name'], $uploadPath);

            echo "File uploaded successfully.";
        } else {
            echo "File upload error.";
        }
    }
}

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    FileHandler::handleUpload();
}
?>