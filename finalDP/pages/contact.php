<?php include('../Configs/session.php'); // Starting Session ?>
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="utf-8">
    <title>Contact &middot; Music Database</title>

	<?php include('../Configs/links.php') ?>
  </head>

  <body>

    <div class="container">
	<?php include '../Configs/check_login.php';?>
      <div class="masthead">
        <h3 class="muted">Data Management project </h3>
        <div class="navbar">
          <div class="navbar-inner">
            <div class="container">
              <ul class="nav">
                <li><a href="index.php">Home</a></li>
                <li><a href="news.php">News</a></li>
                <li><a href="about.php">About</a></li>
                <li class="active"><a href="contact.php">Contact us</a></li>
              </ul>
            </div>
          </div>
        </div><!-- /.navbar -->
      </div>

<form action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>" method="post" class="form-signin">
	        <h2 class="form-signin-heading">Contact Us</h2>
    <div>
        <label for="name">Name:</label>
        <input type="text" class="input-block-level" placeholder="my name" />
    </div>
    
        <label for="mail">E-mail:</label>
        <input type="email" class="input-block-level" placeholder="myemail@gmail.com" />
    
    <div>
        <label for="msg">Message:</label>
        <textarea  type="email" class="input-block-level" placeholder="msg.." ></textarea>
    </div>
    
    <div class="button">
        <button class="btn btn-large btn-primary" type="submit">Send</button>
    </div>
</form>
	  
	  
<!-- footer of the page -->
<?php include('footer.php') ?>