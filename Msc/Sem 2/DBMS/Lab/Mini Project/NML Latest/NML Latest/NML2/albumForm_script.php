
<script src="https://cdnjs.cloudflare.com/ajax/libs/limonte-sweetalert2/11.4.24/sweetalert2.all.js"></script>

<?php
 
    include 'connectDB.php';
    if(!isset($_POST['submit']))
    {
    session_start();
    $AlbumId = $_POST['albumId'];
    $Title = $_POST['title'];
        
    $Copyright = $_POST['copyright'];
    $Format = $_POST['format'];
        
    $AID = $_POST['aid'];
    
    $select = "SELECT * FROM `album` WHERE A_UID = '$AlbumId';";
    $result = mysqli_query($con,$select);

    if(mysqli_num_rows($result) > 0){ 
        ?>
        <script>
            Swal.fire({
            icon: 'error',
            title: 'Error',
            text: 'Album with the same Album UniqueID exists!',
            background: 'ffffff',
            color: 'red',
            });
        </script>
    <?php
        }
        
    $_SESSION['Session_AlbumId'] = $AlbumId;
    $_SESSION['Session_Title'] = $Title;
    $_SESSION['Session_Copyright'] = $Copyright;
    $_SESSION['Session_Format'] = $Format;
    $_SESSION['Session_AID'] = $AID;


    echo "<script>window.location.href='songsForm.php?albumId=$AlbumId';</script>";
    }
    

    ?>
  
  
  <!-- <script>window.location.href='albumForm.php?ssn=$SSN';</script> -->



