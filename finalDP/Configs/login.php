<?php
include_once ('Config.php');// Establishing Connection with Server by passing server_name, user_id and password  and database as a parameter
$year = time() + 31536000;
session_start(); // Starting Session
$_SESSION['Created']= time();
$error=''; // Variable To Store Error Message
if (isset($_POST['submit'])) {
if (empty($_POST['username']) || empty($_POST['password'])) {
$error = "Username or Password is empty";
}
else
{
// Define $username and $password
$username=$_POST['username'];
$password=$_POST['password'];

// Setcookie To save username and rememberme click for later time
setcookie('remember_me', $_POST['username'], $year);

// To protect MySQL injection for Security purpose
$username = stripslashes($username);
$password = stripslashes($password);
$username = mysqli_real_escape_string($db, $username);
$password = mysqli_real_escape_string($db, $password);


// SQL query to fetch information of registerd users and finds user match.
$query = mysqli_query($db, "select * from user_login where password='$password' AND username='$username'");
$rows = mysqli_num_rows($query);
if ($rows == 1) {
$fetch = mysqli_fetch_array($query);
$login_name=$fetch["LoginName"];
$_SESSION['login_user']=$login_name; // Initializing Session
header("location: ../pages/index.php"); // Redirecting To Other Page
} else {
$error = "Username or Password is invalid";
}
mysqli_close($db); // Closing Connection
}
}
?>