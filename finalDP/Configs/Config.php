<?php
define('DB_SERVER', 'localhost');
define('DB_USERNAME', 'aboody');
define('DB_PASSWORD', '123');
define('DB_DATABASE', 'musicbase');
$db = mysqli_connect(DB_SERVER,DB_USERNAME,DB_PASSWORD,DB_DATABASE);
// Check connection
if (mysqli_connect_errno())
  {
  echo "Failed to connect to MySQL: " . mysqli_connect_error();
  }
?>