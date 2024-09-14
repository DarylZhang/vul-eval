<?php
// PHP 中的反射型 XSS 漏洞示例
if (isset($_GET['name'])) {
    $name = $_GET['name'];
    echo "<h1>Hello $name</h1>";
}
?>