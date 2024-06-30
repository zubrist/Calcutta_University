<?php include 'connectDB.php';
    $AUID=$_GET['auid'];
      
?>



<!DOCTYPE html>
<html>

<head>

<meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Search Employee</title>
    <link rel="stylesheet" href="homepageStyle.css">
    <link rel="preconnect" href="https://fonts.googleapis.com">
    <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
    <link href="https://fonts.googleapis.com/css2?family=Satisfy&display=swap" rel="stylesheet">
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.2.3/dist/css/bootstrap.min.css" rel="stylesheet">

<style>
    body{
        background-color: #444;
    }
</style>
</head>

<body style="background-image: url(&quot;../assets/img/y.jpg&quot;); background-size: cover;background-repeat: no-repeat;">
<nav>
        <ul>
            <li><a class="active" href="homepage.html">Home</a></li>

            <!-- <li><a  id="collection" class="shake" href="ourCollection.html">Our Collection</a></li>  -->
        </ul>
    </nav>


<section class="clean-block clean-info dark" style="background-color: rgba(246,246,246,0);opacity: 1;padding-top: 29px; border">
        <div class="container">
            <div class="block-heading">
                <h2 class="text-light"><strong>Album Songs</strong></h2>
            </div>
        </div>
        <div class="container">
            <div class="row">
                <div class="col" style="background-color: #ffffff;">
                    <div class="table-responsive">
                        <table class="table">
                            <thead>
                                <tr>
                                    <th>Album UID</th>
                                    <th>Album Title</th>
                                    <th class='text-danger'>Song Title</th>
                                    <th>Author</th>
                                    <th>Producing Musician</th>
                                </tr>
                            </thead>
                            <tbody>
                            <?php
                                $sql = "SELECT * FROM `song` where A_UID = '$AUID'";
                                
                                $result = mysqli_query($con, $sql);
                                if(mysqli_fetch_array($result)!=NULL){
                                    $sql = "SELECT * FROM `song` where A_UID = '$AUID'";
                                    $result = mysqli_query($con, $sql);
                                    while ($row=mysqli_fetch_assoc($result)) {
                                        
                                        $sql1 = "SELECT * FROM `album` where A_UID = '$AUID'";
                                        $result1 = mysqli_query($con, $sql1);
                                        $row2=mysqli_fetch_assoc($result1);
                                        $SSN= $row2['M_SSN'];

                                        $sql3 = "SELECT * FROM `musician` where SSN = '$SSN'";
                                        $result1 = mysqli_query($con, $sql3);
                                        $row3=mysqli_fetch_assoc($result1);

                                        echo "<tr>";
                                        echo "<td>" . $row2['A_UID'] . "</td>";
                                        echo "<td>" . $row2['A_Title'] . "</td>";
                                        echo "<td>" . $row['Title'] . "</td>";
                                        echo "<td>" . $row['Author'] . "</td>";
                                        echo "<td>" . $row3['name'] . "</td>";
                                        
                                        echo "<td> <a href='deleteSongs.php?auid=$AUID' <button type='button' class='btn btn-danger' onclick='return checkdel()' > Delete </button> </td>";
                                        echo "</td>";
                                        echo "</tr>";
                                    }
                                   
                                }
                                else{
                                    echo "<tr>";
                                    echo "<td>" . "-" . "</td>";
                                    echo "<td>" . "-" . "</td>";
                                    echo "<td>" . "-" . "</td>";
                                    echo "<td>" . "-" . "</td>";
                                    echo "<td>" . "-" . "</td>";
                                    echo "<tr>";

                                }
                                ?>
                            </tbody>
                        </table>
                    </div>
                </div>
            </div>
        </div>
    </section>


<script src="https://cdnjs.cloudflare.com/ajax/libs/bootstrap/5.3.0/js/bootstrap.min.js"></script>   

                        </table>
                    </div>
                </div>
            </div>
        </div>
    </section>


</body>

</html>