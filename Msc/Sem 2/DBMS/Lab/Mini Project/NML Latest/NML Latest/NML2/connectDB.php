<?php
$hostname = "localhost";
$username = "root";
$password = "";
$db = "nml";
$con = mysqli_connect($hostname, $username, $password,$db);
if (!$con) {
    die('Could not connect');
}

?>