<?php include('../Configs/session.php'); // Starting Session ?>
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="utf-8">
    <title>About &middot; Music Database</title>
    
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
                <li class="active"><a href="about.php">About</a></li>
                <li><a href="contact.php">Contact us</a></li>
              </ul>
            </div>
          </div>
        </div><!-- /.navbar -->
      </div>

  
	  <div id="section">
		<h1>About Page</h1> 
		<hr/>
		<p>
			Music is an essential art and as time passes, new songs are released. At this time, 
		music creation is in a great state and websites like “YouTube” and “Vevo” facilitate
		music playback after you sign a contract with a publisher to create the song. Content creation 
		is very important but at the same time, content discovery is vital to finding the newly and previously released songs. 
		The lack of options when it comes to content discovery is what we are hoping to solve with our MusicBase project.
		</p>
		</div>


<!-- footer of the page -->
<?php include('footer.php') ?>
