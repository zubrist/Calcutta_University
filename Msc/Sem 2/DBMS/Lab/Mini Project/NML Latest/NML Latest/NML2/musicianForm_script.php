
<script src="https://cdnjs.cloudflare.com/ajax/libs/limonte-sweetalert2/11.4.24/sweetalert2.all.js"></script>

<?php
 
     include 'connectDB.php';

    if(!isset($_POST['submit']))
    {
     #print_r ($_POST);
        session_start();
    $SSN = $_POST['ssn'];
    
    $Name = $_POST['name'];
        
    $Phone = $_POST['phone'];
    $email = $_POST['email'];
    $s_name = $_POST['street_name'];
    $s_no = $_POST['street_no'];
    $pin = $_POST['pin'];
        
    $Inst1 = $_POST['instrument1'];
    
    $select = "SELECT * FROM `musician` WHERE SSN = '$SSN';";
    $result = mysqli_query($con,$select);

    if(mysqli_num_rows($result) > 0){ 
        ?>
        <script>
            Swal.fire({
            icon: 'error',
            title: 'Error',
            text: 'Musician with the same SSN exists!',
            background: 'ffffff',
            color: 'red',
            });
        </script>
    <?php
        }
        
    $_SESSION['Session_SSN'] = $SSN;
    $_SESSION['Session_Name'] = $Name;
    $_SESSION['Session_Phone'] = $Phone;
    $_SESSION['Session_email'] = $email;
    $_SESSION['Session_s_name'] = $s_name;
    $_SESSION['Session_s_no'] = $s_no;
    $_SESSION['Session_pin'] = $pin;
    $_SESSION['Session_Inst1'] = $Inst1;
        
    if($_POST['instrument2']!="" ){
        $_SESSION['Session_Inst2'] = $_POST['instrument2'];
    }
    if($_POST['instrument3']!="" ){
        $_SESSION['Session_Inst3'] = $_POST['instrument3'];

    }
    echo "<script>window.location.href='albumForm.php?ssn=$SSN';</script>";
   

    }
    
   
    ?>
  
  




