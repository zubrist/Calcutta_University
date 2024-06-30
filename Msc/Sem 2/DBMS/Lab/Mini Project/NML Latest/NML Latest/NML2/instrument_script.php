
<script src="https://cdnjs.cloudflare.com/ajax/libs/limonte-sweetalert2/11.4.24/sweetalert2.all.js"></script>

<?php
 
    include 'connectDB.php';
    $Name = $_POST['Name'];
    $Mkey = $_POST['Mkey'];
    $IUID = $_POST['I_UID'];

    $select = "SELECT * FROM `instrument` WHERE Name = '$Name' and Musical_key = '$Mkey';";
    $result = mysqli_query($con,$select);
    if(mysqli_num_rows($result) != 0){ 
        ?>
        <script>
            Swal.fire({
                icon: 'error',
                title: 'Error',
                text: 'Instrument already Exists! Record not insrted!',
                background: 'ffffff',
                color: 'red'
                });
        </script>
        
<?php
      }

else{
 $sql = "INSERT INTO instrument (I_UID, Name, Musical_key ) VALUES ( '$IUID', '$Name', '$Mkey')";
 if($con->query($sql) === TRUE){?>
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
}
?>




