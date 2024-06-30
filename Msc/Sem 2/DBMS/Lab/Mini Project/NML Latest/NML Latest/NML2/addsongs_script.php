
<script src="https://cdnjs.cloudflare.com/ajax/libs/limonte-sweetalert2/11.4.24/sweetalert2.all.js"></script>

<?php
 
    include 'connectDB.php';
    #var_dump($_POST);
    //echo $_POST['slno'];
    if(isset($_POST['submit'])){
    session_start();
    
    //print_r($_SESSION);
    $SSN = $_SESSION['Session_SSN'] ;
   
    $AlbumId = $_SESSION['Session_AlbumId'];
    $A_Title = $_SESSION['Session_Title'] ;
    $Copyright = $_SESSION['Session_Copyright'] ;
    $Format = $_SESSION['Session_Format'] ;
    $AID = $_SESSION['Session_AID'] ;
    

    $sql="insert into album (A_UID,A_Title,Copyright_data,Format,AID,M_SSN ) values('$AlbumId','$A_Title','$Copyright','$Format','$AID','$SSN')";
    if ($con->query($sql) === TRUE){
        for($i=0;$i<count($_POST['slno']);$i++){
            //echo "<br>slno= ".$_POST['slno'][$i]."<br>";
            $song = $_POST['song_title'][$i];
            $author = $_POST['song_author'][$i];
            $flag=0;
            if($song!=='' && $author!==''){
                $sql="insert into song (Title,A_UID,Author) values('$song','$AlbumId','$author')";
                if ($con->query($sql) === TRUE){
                    $sql="insert into perform (M_SSN,Title,A_UID) values('$SSN','$song','$AlbumId')";
                    //echo ($sql);
                    if ($con->query($sql) === TRUE){
                    $flag=1;
                    //echo'<div class="alert alert-danger" role="alert"> submitting perform</div>';
                    }
                    else{
                        echo $con->error;
                    }
                }
                
            }
        }
     }
     else{
        echo $con->error;
     }


     if($flag){
        echo".";
        ?>
        <script>
            Swal.fire({
                icon: 'success',
                title: 'Success',
                text: 'Record Inserted Successfully',
                background: '#ffffff',
                color: '#00b41e',
                });
        </script>
        <?php 

     }
     
     session_destroy();

    }
?>
  
  
  <!-- <script>window.location.href='albumFrom.php?ssn=$SSN';</script> -->



