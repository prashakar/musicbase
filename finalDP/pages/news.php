<?php include('../Configs/session.php'); // Starting Session ?>
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="utf-8">
    <title>News &middot; Music Database</title>

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
                <li class="active"><a href="news.php">News</a></li>
                <li><a href="about.php">About</a></li>
                <li><a href="contact.php">Contact us</a></li>
              </ul>
            </div>
          </div>
        </div><!-- /.navbar -->
      </div>

<div class="mid">
            <a class="twitter-timeline"  href="https://twitter.com/TwitterMusic" data-widget-id="538153159626350593">Tweets by @TwitterMusic</a>
            <script>!function(d,s,id){var js,fjs=d.getElementsByTagName(s)[0],p=/^http:/.test(d.location)?'http':'https';if(!d.getElementById(id)){js=d.createElement(s);js.id=id;js.src=p+"://platform.twitter.com/widgets.js";fjs.parentNode.insertBefore(js,fjs);}}(document,"script","twitter-wjs");</script>         
</div>
<!-- footer of the page -->
<?php include('footer.php') ?>