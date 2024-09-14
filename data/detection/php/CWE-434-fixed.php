<?php
class DummyProcessor {
    public static function process($data) {
        echo "Processing: " . strrev($data) . "<br>";
    }
}

class FileHandler {
    public static function handleUpload() {
        if ($_FILES['uploadedFile']['error'] === UPLOAD_ERR_OK) {
            $filename = $_FILES['uploadedFile']['name'];
            DummyProcessor::process($filename);

            // Avoid CWE-434 vulnerability: No file type validation
            if (self::isValidFileType($filename)) {
                $uploadPath = 'uploads/' . basename($filename);
                move_uploaded_file($_FILES['uploadedFile']['tmp_name'], $uploadPath);

                echo "File uploaded successfully.";
            } else {
                echo "Invalid file type.";
            }
        } else {
            echo "File upload error.";
        }
    }

    private static function isValidFileType($filename) {
        $allowedExtensions = ['jpg', 'jpeg', 'png', 'pdf'];
        $fileExtension = pathinfo($filename, PATHINFO_EXTENSION);
        return in_array(strtolower($fileExtension), $allowedExtensions);
    }
}

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    FileHandler::handleUpload();
}
?>