<?php  include('../Configs/signup_new.php');  // Includes signup_new Script ?>
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="utf-8">
    <title>Sign Up &middot; Music Database</title>

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
                <li><a href="contact.php">Contact us</a></li>
              </ul>
            </div>
          </div>
        </div><!-- /.navbar -->
      </div>

	      <div class="container">

      <form class="form-signin" method="post">
        <h2 class="form-signin-heading">Sign Up</h2>
        <input name="username" type="text" class="input-block-level" placeholder="Username" maxlength="10" required>
		<input name="loginname" type="text" class="input-block-level" placeholder="Login Name" maxlength="10" required>
		<input name="password" type="password" class="input-block-level" placeholder="Password" maxlength="20" required>
        <input name="address" type="text" class="input-block-level" placeholder="Addresse" maxlength="50">
        <input name="usergenre" type="text" class="input-block-level" placeholder="Genre (Ex.Rock)" maxlength="20">
        <button name="submit" class="btn btn-large btn-primary" type="submit">Submit</button>
		<span><?php echo $error; ?></span>
      </form>

    </div> <!-- /container -->
	

<!-- footer of the page -->
<?php include('footer.php') ?>
