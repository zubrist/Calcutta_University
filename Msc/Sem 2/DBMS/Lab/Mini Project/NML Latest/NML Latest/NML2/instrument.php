<?php include 'connectDB.php' ?>
<?php
    $sql="select I_UID from instrument ORDER BY I_UID DESC LIMIT 1 ";  
    $result = $con->query($sql);
    if($result->num_rows > 0){

        $row = $result->fetch_assoc();
        
        $int_var = (int)filter_var($row["I_UID"], FILTER_SANITIZE_NUMBER_INT);
        $int_var = $int_var+1;
        $uid = "Inst@".$int_var;
    }
    else{
        $uid = "Inst@"."1";
    }
?>

<!DOCTYPE html>
<html>

<head>
<meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Form 2</title>
    <link rel="stylesheet" href="style2.css">
    <link rel="stylesheet" href="homepageStyle.css">
    <link rel="preconnect" href="https://fonts.googleapis.com">
    <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
    <link href="https://fonts.googleapis.com/css2?family=Satisfy&display=swap" rel="stylesheet">
</head>

<nav>
        <ul>
            <li><a href="homepage.html">Home</a></li>
            
        </ul>
</nav>


<body style="background: url('instrument.jpg'); background-size: 100%;">
<div class='heading'>
    <h1>Add Instruments Details</h1>
    <hr>
</div>

    <div class="container-form2">
            <form action="instrument.php" method="post">
                <div class="form-row">
                    <div class="col" >
                        <div class="form-group">
                            <label for="I_UID" >Instrument Unique ID <span style="color:red">* ::  </span></label>
                            <input class="form-control item" type="text" value="<?php echo $uid?>" id="I_UID" name="I_UID" required>
                        </div>
                    </div>
                    
                    <div class="col">
                        <div class="form-group">
                            <label for="Mkey" >Musical key<span style="color:red">* ::&nbsp;</span></label>
                            <input class="form-control item" type="text" placeholder="Enter the musical-key" id="Mkey" name="Mkey" required>
                        </div>
                    </div>
                </div>
                <div class="form-row">
                    <div class="col">
                        <div class="form-group"><label for="Name" > Name <span style="color:red">* ::&nbsp;</span></label><input class="form-control item" type="text" placeholder="Enter the Name" id="Name" name="Name" required></div>
                    </div>
                    <div class="col" >
                        <center><div><input class="submit" type="submit" value="Add Instrument" style="background-color: rgb(59,153,224);" name="Add"></div></center>
                        
                    </div>
                </div> 
            </form>
        <?php
            if(isset($_POST['Add'])){
                include "instrument_script.php";
            }
        ?>
   </div>
</body>

</html>