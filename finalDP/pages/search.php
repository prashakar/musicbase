<?php include('../Configs/find.php'); // Includes Search Script ?>

<form action="" method="post">
Search For:
	<input name="searchquery" placeholder="Ex. Song" type="text" size="20" maxlength="30">
Within:
<select name="filter1" title="Select an option" id="filter1">
<option value="QUERY1">Artist</option>
<option value="QUERY2">Album Release Year</option>
<option value="QUERY3">User Comments</option>
<option value="QUERY4">Song Release Year</option>
<option value="QUERY5">Song Comments</option>
<option value="QUERY6">Album Songs</option>
<option value="QUERY7">Song By Rating</option>
<option value="QUERY8">Song By Genre</option>
<option value="QUERY9">TOP Songs By Genre</option>
<option value="QUERY10">Song Links</option>
</select>	
<!-- Keep values of the selected option -->
<script type="text/javascript">
  document.getElementById('filter1').value = "<?php echo $_POST['filter1'];?>";
</script>
	<br/>
	<input name="submit" type="submit" value="Submit Query" class="btn-danger btn-large">	<br/><br/>
	<?php echo $error; ?>
</form>
		
<?php echo $search_output ?>		

<?php echo $search_output2 ?>