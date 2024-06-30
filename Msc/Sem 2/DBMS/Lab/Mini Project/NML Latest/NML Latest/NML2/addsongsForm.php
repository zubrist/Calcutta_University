<?php 
    include 'connectDB.php';
    $AlbumId=$_GET['albumId']; 
?>

<!DOCTYPE html>
<html>
<head>
  <title>Songs Form</title>
  <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css">
    <link rel="stylesheet" type="text/css" href=songsForm_css.css>

</head>
<body >
  <div class="container">
    <div class="form-container">
      <h2>Songs Details</h2>
      <form action="addsongs_script.php" method="post">
          <!-- <div class="form-group">
          <label for="Age">Sl No:</label>
          <input type="text" class="form-control sl" name="slno[]" id="slno" value="1" readonly="">
          </div> -->
        <div id="song-fields" row>
            <div class="form-group col-lg-12">
                <label for="albumId">Album ID</label>
                <input type="text" class="form-control albumId" id="albumId" name="albumId" placeholder="Album ID" value="<?php echo $AlbumId ;?>" disabled required>
            </div>
            
            <div class="row">
                <div class="form-group col-lg-2">
                    <label for="serial_no">Serial</label>
                    <input type="text" class="form-control slno" id="slno" name="slno[]"  value="1" required readonly>
                </div>
                
                  <div class="form-group col-lg-4" >
                    <label for="song-title">Song Title</label>
                    <input type="text" class="form-control" id="song-title" name="song_title[]" placeholder="Enter Song Title" required>
                  </div>
                
                  <div class="form-group col-lg-4">
                    <label for="author">Author</label>
                    <input type="text" class="form-control" id="author" name="song_author[]" placeholder="Enter Author" required>
                  </div>
                <div id="next"></div>
            </div>
            
            <button type="button" name="addrow" id="addrow" class="btn btn-success pull-right">Add New Row</button>
            <br/><br/>
            <button type="submit" name="submit" class="btn btn-info pull-left">Submit</button>
        </div>
      </form>
        
    </div>
  </div>
<script src="https://code.jquery.com/jquery-3.2.1.js" integrity="sha256-DZAnKJ/6XZ9si04Hgrsxu/8s717jcIzLy3oi35EouyE=" crossorigin="anonymous"></script>
<script src="https://cdnjs.cloudflare.com/ajax/libs/bootstrap/5.3.0/js/bootstrap.min.js"></script>   
<script>
    $('#addrow').click(function(){
        var length=$('.slno').length;
        var i=parseInt(length)+parseInt(1);
        var newrow=$('#next').append('<div class="row"><div class="form-group col-lg-2"><label for="serial_no">Serial</label><input type="text" class="form-control slno" name="slno[]" value="'+i+'" readonly=""></div><div class="form-group col-lg-4" ><label for="song-title">Song Title</label><input type="text" class="form-control" id="song-title'+i+'" name="song_title[]" placeholder="Enter Song Title" required></div><div class="form-group col-lg-4"><label for="author">Author</label> <input type="text" class="form-control" id="author'+i+'" name="song_author[]" placeholder="Enter Author" required></div><input type="button" class="btn btn-success btnRemove" value="Remove" style="height:40px; margin-top:35px;"/></div></div><br>');
    });
    $('body').on('click','.btnRemove',function(){
        $(this).closest('div').remove()
        var i=parseInt(length)-parseInt(1);
    });
</script>
</body>
</html>































