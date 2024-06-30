<?php include 'connectDB.php' ;
  session_start();
    
    $sql="select SSN from musician ORDER BY SSN DESC LIMIT 1 ";  
    $result = $con->query($sql);
    if($result->num_rows > 0){
        $row = $result->fetch_assoc();
        $int_var = (int)filter_var($row["SSN"], FILTER_SANITIZE_NUMBER_INT);
        $int_var = $int_var+1;
        $S = "Musc@".$int_var;
    }
    else{
        $S = "Musc@"."1";
    }
    
?>

<!DOCTYPE html>
<html>
<head>
  <title>Musician Registration</title>
  <style>
    body {
      background-color: #222;
      color: #fff;
      font-family: Arial, sans-serif;
      padding: 20px;
    }

    h1 {
      text-align: center;
      margin-bottom: 20px;
      font-size: 32px;
    }

    .container {
      max-width: 600px;
      margin: 0 auto;
      background-color: #333;
      padding: 30px;
      border-radius: 5px;
      box-shadow: 0 4px 8px rgba(0, 0, 0, 0.5);
    }

    form {
      animation: slideIn 0.8s ease-in-out;
    }

    @keyframes slideIn {
      from {
        transform: translateY(100px);
        opacity: 0;
      }
      to {
        transform: translateY(0);
        opacity: 1;
      }
    }

    label {
      display: block;
      margin-bottom: 10px;
    }

    input[type="text"],input[type="int"],
    input[type="email"],input[type="tel"] {
      width: 100%;
      padding: 10px;
      border: none;
      border-radius: 4px;
      margin-bottom: 20px;
      background-color: #444;
      color: #fff;
    }

    select {
      width: 100%;
      padding: 10px;
      border: none;
      border-radius: 4px;
      margin-bottom: 20px;
      background-color: #444;
      color: #fff;
    }

    input[type="submit"] {
      background-color: #00ffcc;
      color: #222;
      border: none;
      border-radius: 4px;
      padding: 10px 20px;
      cursor: pointer;
      font-size: 16px;
      transition: background-color 0.3s ease-in-out;
    }

    input[type="submit"]:hover {
      background-color: #00cc99;
    }
  </style>

</head>
<body>

  <div class="container">
    <h1>Musician Registration</h1>
    <form  action="musicianForm_script.php"  method="post"  >
      <label for="ssn">SSN:</label>
      <input type="text" id="ssn" name="ssn" value="<?php echo $S?>">

      <label for="name">Name:</label>
      <input type="text" id="name" name="name">

      <label for="phone">Phone No:</label>
      <input type="tel" id="phone" name="phone">

      <label for="email">E-Mail Id:</label>
      <input type="email" id="email" name="email">

      <label for="street_name">Street Name:</label>
      <input type="text" id="street_name" name="street_name">

      <label for="street_no">Street No:</label>
      <input type="text" id="street_no" name="street_no">

      <label for="pin">PIN:</label>
      <input type="int" id="pin" name="pin">

      <label for="instrument1">Instrument 1:</label>

      <select id="instrument1" name="instrument1" required>
        <option value=""> -- Choose an instrument -- </option>
        <?php
            $sql1 = "select * from instrument";
            $result1 = $con->query($sql1);
            if($result1->num_rows > 0){
                while($row1=$result1->fetch_assoc()){
                    echo "<option>".$row1['Name']."_".$row1['Musical_key']."</option>";
                }
            }
        ?>
      </select>

      <label for="instrument2">Instrument 2:</label>
      <select id="instrument2" name="instrument2" >
        <option value=""> -- Choose an instrument -- </option>
        <?php
            $sql1 = "select * from instrument";
            $result1 = $con->query($sql1);
            if($result1->num_rows > 0){
                while($row1=$result1->fetch_assoc()){
                    echo "<option>".$row1['Name']."_".$row1['Musical_key']."</option>";
                }
            }
        ?>
      </select>

      <label for="instrument3">Instrument 3:</label>
      <select id="instrument3" name="instrument3">
        <option value=""> -- Choose an instrument -- </option>
        <?php
            $sql1 = "select * from instrument";
            $result1 = $con->query($sql1);
            if($result1->num_rows > 0){
                while($row1=$result1->fetch_assoc()){
                    echo "<option>".$row1['Name']."_".$row1['Musical_key']."</option>";
                }
            }
        ?>
      </select>

      <input type="submit" name="Add" value="Add Album">
    </form>
  
  </div>

  
</body>

</html>
