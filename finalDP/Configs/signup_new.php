<?php
include_once ('Config.php');
$error=''; // Variable To Store Error Message
if (isset($_POST['submit'])) {
if (empty($_POST['username']) || empty($_POST['loginname']) || empty($_POST['password'])) {
$error = "You forgot something!";
}
else
{
// Define $username and $password
$username=$_POST['username'];
$password=$_POST['password'];
$loginName=$_POST['loginname'];
$password=$_POST['password'];
$userType='User';
$address=$_POST['address'];
$user_genre=$_POST['usergenre'];

// To protect MySQL injection for Security purpose
$username = stripslashes($username);
$password = stripslashes($password);
$username = mysqli_real_escape_string($db, $username);
$password = mysqli_real_escape_string($db, $password);

// SQL query to insert new  registerd users
$query=mysqli_query($db, "INSERT INTO user_login (UserName,LoginName,Password,UserType,Address,UserGenre) values ('$username','$loginName','$password','$userType','$address','$user_genre')");

if($query){
	$error= "Success";
	include('login.php');
}
else
	{
	$error = "Error:" + die (mysqli_error($db));
	}

mysqli_close($db); // Closing Connection
}
}
?>