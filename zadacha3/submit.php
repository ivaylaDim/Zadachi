<?php

$name = $_POST["name"];
$surname = $_POST["surname"];
$egn = $_POST["egn"];
$email = $_POST["email"];
$phone = $_POST["phone"];
$course = $_POST["course"];
$major = $_POST["major"];


$host = "localhost";
$dbname = "form";
$username = "root";
$password = "";

$conn = mysqli_connect($host, $username, $password, $dbname);

if (mysqli_connect_errno()) {
    die("Connection failed: " . mysqli_connect_error());
}

$sql = "INSERT INTO students (name, surname, egn, email, phone, course, major) VALUES (?, ?, ?, ?, ?, ?, ?)";
$stmt = mysqli_stmt_init($conn);
if (!mysqli_stmt_prepare($stmt, $sql)) {
    die(mysqli_error($conn));
}
mysqli_stmt_bind_param($stmt, "sssssss", $name, $surname, $egn, $email, $phone, $course, $major);
mysqli_stmt_execute($stmt);