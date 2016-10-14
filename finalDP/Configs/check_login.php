<!-- check if there is a session with a user that already logeed in
	if so it will display the name and logout button or 
	it will show link for singin or Registration -->
	
<div id="top_right_section"  class="pull-right">
    <div id="head_icon">
        <ul class="top">
           <?php if(!isset($_SESSION['login_user'])) { ?>
            <li class="hover"><a href="signin.php" onClick="revealModal('modalPage')"  class="btn-small btn-primary">Login</a>
            </li>
            <li><a href="signup.php" class="btn-small btn-primary">Registration</a>
            </li>
             <?php } else {?>
				<div id="profile">
				<b id="welcome">Welcome : <i style="color: red"><?php echo $_SESSION['login_user'] ?></i></b>
				<b id="logout">&nbsp;&nbsp;&nbsp;<a  href="../Configs/logout.php"  class="btn-small btn-warning">Log Out</a></b>
				</div>
             <?php } ?>
        </ul>
    </div>
</div>