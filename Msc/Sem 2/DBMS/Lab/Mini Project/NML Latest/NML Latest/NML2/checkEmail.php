
<script src="https://cdnjs.cloudflare.com/ajax/libs/limonte-sweetalert2/11.4.24/sweetalert2.all.js"></script>

<?php
 
     include 'connectDB.php';

    if(!isset($_POST['submit']))
    {
    
    $email = $_POST['email'];
   
    $select = "SELECT SSN FROM `musician` WHERE M_email = '$email';";
    $result = mysqli_query($con,$select);
    $row = $result->fetch_assoc();
    $SSN=$row['SSN'];

    if(mysqli_num_rows($result) > 0){ 
        ?>
        <script>
            Swal.fire({
            icon: 'error',
            title: 'Error',
            text: 'Musician does not exists!',
            background: 'ffffff',
            color: 'red',
            });
        </script>
    <?php
        }
    else{

        echo "<script>window.location.href='addAlbumForm.php?ssn=$SSN';</script>";
    }
   
    
   

    }
    
   
    ?>
  
  




