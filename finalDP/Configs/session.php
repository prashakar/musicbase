<?php
include('login.php');
/*
$user_timeStart= time(); // Storing Session start time
$user_timeExpire=$_SESSION['Created'] + (1 * 10); // expire session after one minute
*/
if(!isset($_SESSION['login_user'])){
// mysqli_close($db); // Closing Connection
session_destroy();
session_unset(); 
//header('Location: ../Pages/index.php'); // Redirecting To Home Page
}
/*
else if ($user_timeStart > $user_timeExpire){
session_unset();
session_destroy();
//header('Location: ../index.php'); // Redirecting To Home Page
}*/

?>