<script src="https://cdnjs.cloudflare.com/ajax/libs/limonte-sweetalert2/11.4.24/sweetalert2.all.js"></script>

<?php
 
    include 'connectDB.php';
    #var_dump($_POST);
    #echo $_POST['slno'];
    if(isset($_POST['submit'])){
    session_start();
    
    //print_r($_SESSION);
    $SSN = $_SESSION['Session_SSN'] ;
    $Name = $_SESSION['Session_Name']  ;
    $Phone = $_SESSION['Session_Phone'] ;
    $email = $_SESSION['Session_email'] ;
    $s_name = $_SESSION['Session_s_name'];
    $s_no = $_SESSION['Session_s_no'];
    $pin = $_SESSION['Session_pin'];
    
    $select = "SELECT * FROM `musician` WHERE M_email = '$email';";
    $result = mysqli_query($con,$select);
    if(mysqli_num_rows($result) != 0){ 
        echo ".";
        ?>
        <script>
            Swal.fire({
                icon: 'error',
                title: 'Error',
                text: 'Email already Exists! Record not insrted!',
                background: 'ffffff',
                color: 'red'
                });
        </script>
        
    <?php
      }
    else{
        $AlbumId = $_SESSION['Session_AlbumId'];
    $A_Title = $_SESSION['Session_Title'] ;
    $Copyright = $_SESSION['Session_Copyright'] ;
    $Format = $_SESSION['Session_Format'] ;
    $AID = $_SESSION['Session_AID'] ;
    
    $flag1=0;

    $sql="insert into address (Ph_no,Street_name,Street_no,Pin) values('$Phone','$s_name','$s_no','$pin')";
    if ($con->query($sql) === TRUE){
        $sql="insert into musician (SSN,name,Ph_no,M_email) values('$SSN','$Name','$Phone','$email')";
        if ($con->query($sql) === TRUE){
            $sql="insert into album (A_UID,A_Title,Copyright_data,Format,AID,M_SSN ) values('$AlbumId','$A_Title','$Copyright','$Format','$AID','$SSN')";
            if ($con->query($sql) === TRUE){
                
    $Inst1 = $_SESSION['Session_Inst1'];
    $string = $Inst1;
    $str_arr = explode ("_", $string);
     
    $select = "SELECT I_UID FROM `instrument` WHERE Name = '$str_arr[0]' and Musical_key = '$str_arr[1]';";
    $result = mysqli_query($con,$select);
    $row = $result->fetch_assoc();
    $Inst1ID=$row['I_UID'];
    //echo($Inst1ID); 




 $sql="insert into plays (I_UID,M_SSN) values('$Inst1ID','$SSN')";
    if ($con->query($sql) === TRUE){
        if((isset($_SESSION['Session_Inst2'])) ){
            $string = $_SESSION['Session_Inst2'];
            $str_arr = explode ("_", $string);
             
            $select = "SELECT I_UID FROM `instrument` WHERE Name = '$str_arr[0]' and Musical_key = '$str_arr[1]';";
            $result = mysqli_query($con,$select);
            $row = $result->fetch_assoc();
            $Inst2ID=$row['I_UID'];
            
            $select = "SELECT * FROM `plays` WHERE I_UID = '$Inst2ID' and M_SSN = '$SSN';";
            $result = mysqli_query($con,$select);
            if(mysqli_num_rows($result) != 0){ 
                ?>
                <script>
                    Swal.fire({
                        icon: 'error',
                        title: 'Error',
                        text: 'Repeated Instrument Selected',
                        background: 'ffffff',
                        color: 'red'
                        });
                </script>
                
            <?php
              }
        
            $sql="insert into plays (I_UID,M_SSN) values('$Inst2ID','$SSN')";
            if ($con->query($sql) === TRUE){
                if((isset($_SESSION['Session_Inst3'])) ){
                    $string = $_SESSION['Session_Inst3'];
                    $str_arr = explode ("_", $string);
                     
                    $select = "SELECT I_UID FROM `instrument` WHERE Name = '$str_arr[0]' and Musical_key = '$str_arr[1]';";
                    $result = mysqli_query($con,$select);
                    $row = $result->fetch_assoc();
                    $Inst3ID=$row['I_UID'];
                
                    $select = "SELECT * FROM `plays` WHERE I_UID = '$Inst3ID' and M_SSN = '$SSN';";
                    $result = mysqli_query($con,$select);
                    if(mysqli_num_rows($result) != 0){ 
                        ?>
                        <script>
                            Swal.fire({
                                icon: 'error',
                                title: 'Error',
                                text: 'Repeated Instrument Selected',
                                background: 'ffffff',
                                color: 'red'
                                });
                        </script>
                        
                    <?php
                      }
                
                    $sql="insert into plays (I_UID,M_SSN) values('$Inst3ID','$SSN')";
                    if ($con->query($sql) === TRUE){
                       $flag1=1;
                    }
                    else{
                        echo $con->error;
                    }
                    }else{
                        $flag1=1;
                    }
            }
            else{
                echo $con->error;
            }
                
            }
            else{
                $flag1=1;
            }
        
    }
    else{
        echo $con->error;
    }

             }
             else{
                echo $con->error;
             }
         }
         else{
            echo $con->error;
         }     }
     else{
        echo $con->error;
     }

   


     for($i=0;$i<count($_POST['slno']);$i++){
        //echo "<br>slno= ".$_POST['slno'][$i]."<br>";
        $flag2=0;
        $song = $_POST['song_title'][$i];
        $author = $_POST['song_author'][$i];

        if($song!=='' && $author!==''){
            $sql="insert into song (Title,A_UID,Author) values('$song','$AlbumId','$author')";
            if ($con->query($sql) === TRUE){
                $sql="insert into perform (M_SSN,Title,A_UID) values('$SSN','$song','$AlbumId')";
                //echo ($sql);
                if ($con->query($sql) === TRUE){
                $flag2=1;
                }
                else{
                    echo $con->error;
                }
            }
            
        }
    }



    if($flag1 == 1 and $flag2 == 1){
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
    else{?>
        <script>
            Swal.fire({
                icon: 'error',
                title: 'Error',
                text: 'Could not insert Data!',
                background: 'ffffff',
                color: 'red'
                });
        </script>
        
    <?php
        
    }
    session_destroy();


    }// end of else

    
    }


?>
  
  
  