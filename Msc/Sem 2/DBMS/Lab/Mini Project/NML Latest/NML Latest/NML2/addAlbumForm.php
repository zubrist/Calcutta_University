<?php include 'connectDB.php';
    $SSN=$_GET['ssn'];
      
    session_start();
 
    $sql="select A_UID from album ORDER BY A_UID DESC LIMIT 1 ";  
    $result = $con->query($sql);
    if($result->num_rows > 0){
        $row = $result->fetch_assoc();
        $int_var = (int)filter_var($row["A_UID"], FILTER_SANITIZE_NUMBER_INT);
        $int_var = $int_var+1;
        $auid = "Album@".$int_var;
        $aid = $int_var;
    }
    else{
        $auid = "Album@"."1";
        $aid = "1";
    }
?>


<!DOCTYPE html>
<html>
<head>
  <title>Album Form</title>
  <style>
    body {
      font-family: Arial, sans-serif;
      background-color: #222;
      margin: 0;
      padding: 20px;
    }
  
    .container {
      max-width: 500px;
      margin: 0 auto;
      background-color: #333;
      padding: 20px;
      border-radius: 5px;
      box-shadow: 0 4px 8px rgba(0, 0, 0, 0.5);
    }
  
    h1 {
      text-align: center;
      color: #fff;
      margin-bottom: 20px;
    }
  
    .form-group {
      margin-bottom: 20px;
    }
  
    label {
      display: block;
      font-weight: bold;
      margin-bottom: 5px;
      color: #fff;
    }
  
    input[type="text"],
    select {
      width: 100%;
      padding: 10px;
      border: 1px solid #af9b9b;
      border-radius: 4px;
      box-sizing: border-box;
      color: #4caf50;
     
    background-color: #444;
    }
  
    input[type="submit"] {
      background-color: #4caf50;
      color: #fff;
      padding: 10px 20px;
      border: none;
      border-radius: 4px;
      cursor: pointer;
      font-size: 16px;
    }
  
    input[type="submit"]:hover {
      background-color: #45a049;
    }

  </style>


</head>
<body  >
  <div class="container">
    <h1>Album Details </h1>


    <form  action="addAlbumForm_script.php" method="post" >
      <div class="form-group">
        <label for="albumId">Album ID:</label>
        <input type="text" id="albumId" name="albumId" value="<?php echo $auid?>">
      </div>
      <div class="form-group">
        <label for="title">Title:</label>
        <input type="text" id="title" name="title">
      </div>
      <div class="form-group">
        <label for="copyright">Copyright Date:</label>
        <input type="text" id="copyright" name="copyright">
      </div>
      <div class="form-group">
        <label for="format">Format:</label>
        <select id="format" name="format">
          <option value="CD">CD</option>
          <option value="Vinyl">Vinyl</option>
          <option value="Digital">Digital</option>
        </select>
      </div>
      <div class="form-group">
        <label for="aid">AID:</label>
        <input type="text" id="aid" name="aid" value="<?php echo $aid?>">
      </div>
      <div class="form-group">
        <label for="ssn">SSN:</label>
        <input type="text" id="ssn" name="ssn" value="<?php echo $SSN ;?>">
      </div>
      <div class="form-group">
        <input type="submit" value="Add Songs">
      </div>
    </form>
  </div>
</body>
</html>
