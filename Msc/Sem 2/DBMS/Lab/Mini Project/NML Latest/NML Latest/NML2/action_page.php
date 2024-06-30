<script src="https://cdnjs.cloudflare.com/ajax/libs/limonte-sweetalert2/11.4.24/sweetalert2.all.js"></script>


<?php include 'connectDB.php';
    $email = $_POST['email'];
    $sql = "SELECT * FROM `musician` WHERE  M_email = '$email'";

    $result = mysqli_query($con, $sql);
    if (mysqli_num_rows($result) > 0){
        $row=mysqli_fetch_assoc($result);
        $SSN=$row['SSN'];
        echo "<script>window.location.href='addAlbumForm.php?ssn=$SSN';</script>";
    }
    else{
        echo".";
        ?>
        <script>
            Swal.fire({
                icon: 'error',
                title: 'Error',
                text: 'Musician Not Registered, Please Register Musician!',
                background: 'ffffff',
                color: 'red'
                });
        </script>
        
    <?php
    
    }

?>
