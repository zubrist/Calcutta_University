
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
    $SSN = $_POST['ssn'];
        
    $_SESSION['Session_AlbumId'] = $AlbumId;
    $_SESSION['Session_Title'] = $Title;
    $_SESSION['Session_Copyright'] = $Copyright;
    $_SESSION['Session_Format'] = $Format;
    $_SESSION['Session_AID'] = $AID;
    $_SESSION['Session_SSN'] = $SSN;

    echo "<script>window.location.href='addsongsForm.php?albumId=$AlbumId';</script>";
    }
    

    ?>
  
  
  <!-- <script>window.location.href='albumForm.php?ssn=$SSN';</script> -->



