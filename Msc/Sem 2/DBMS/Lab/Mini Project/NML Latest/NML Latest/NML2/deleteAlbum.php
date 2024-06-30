<script src="https://cdnjs.cloudflare.com/ajax/libs/limonte-sweetalert2/11.4.24/sweetalert2.all.js"></script>


<?php 
    include 'connectDB.php';
    $AlbumId=$_GET['auid']; 
    $sql = "SELECT * FROM `album` WHERE A_UID = '$AlbumId'";
    $result = mysqli_query($con, $sql);
    $row=mysqli_fetch_assoc($result);
    $SSN=$row['M_SSN'];

    
    $sql2 = "DELETE FROM `perform` WHERE A_UID='$AlbumId'";
 
    $sql3 = "DELETE FROM `song` WHERE A_UID='$AlbumId'";
    $sql4 = "DELETE FROM `album` WHERE A_UID='$AlbumId'";

        $result = mysqli_query($con,$sql2);
        if($result){
            $result = mysqli_query($con,$sql3);
            if($result){
                $result = mysqli_query($con,$sql4);
                if($result){
                    $sql5 = "SELECT * FROM `album` WHERE M_SSN = '$SSN' ;";
                    $result = mysqli_query($con, $sql5);
                    if($result->num_rows == 0){

                        $sql = "SELECT * FROM `musician` WHERE SSN = '$SSN'";
                        $result = mysqli_query($con, $sql);
                        $row=mysqli_fetch_assoc($result);
                        $ph_no=$row['Ph_no'];

                        $sql1 = "DELETE FROM `plays` WHERE M_SSN='$SSN'";
                        $sql2 = "DELETE FROM `musician` WHERE SSN='$SSN'";
                        
                        $result1 = mysqli_query($con,$sql1);
                        $result2 = mysqli_query($con,$sql2);

                        if($result1 and $result2){
                            $sql5 = "SELECT * FROM `musician` WHERE Ph_no = '$ph_no' ;";
                            $result = mysqli_query($con, $sql5);
                            if($result->num_rows == 0){
                                $sql = "DELETE FROM `address` WHERE Ph_no='$ph_no'";
                                $result = mysqli_query($con,$sql); 
                                if($result){
                                
                                echo".";
                                ?>
                                <script>
                                Swal.fire({
                                icon: 'success',
                                title: 'Success',
                                text: 'Record Deleted Successfully',
                                background: '#ffffff',
                                color: '#dc3545',
                                });
                                </script>
                                <?php 

                                } 
                            }
                            else{
                                echo".";
                                ?>
                                <script>
                                Swal.fire({
                                icon: 'success',
                                title: 'Success',
                                text: 'Record Deleted Successfully',
                                background: '#ffffff',
                                color: '#dc3545',
                                });
                                </script>
                                <?php 
                            }

                        }
                    }

                    else{
                        echo".";
                        ?>
                        <script>
                        Swal.fire({
                        icon: 'success',
                        title: 'Success',
                        text: 'Record Deleted Successfully',
                        background: '#ffffff',
                        color: '#dc3545',
                        });
                        </script>
                        <?php

                    }
                }
                
                
            }
        }
    
          
?>





