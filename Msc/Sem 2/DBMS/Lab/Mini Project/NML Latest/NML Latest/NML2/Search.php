
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

</head>
<style>
    body{
        background-color: #444;
    }
    .col{
        display: inline-block;
    }
    .btn{
        
    }
</style>

<body style="background-image: url(&quot;../assets/img/y.jpg&quot;); background-size: cover;background-repeat: no-repeat;">
<nav>
        <ul>
            <li><a class="active" href="homepage.html">Home</a></li>
         <!-- <li><a  id="collection" class="shake" href="ourCollection.html">Our Collection</a></li>  -->
        </ul>
    </nav>
    <section class="clean-block clean-form dark" style="padding-top: 10px;background-color:rgb(68 68 68);">
        <h2 class="text-info" style='text-align: center;'  ><strong>Search Album</strong></h2>
        <div class="container" style="padding:5% 27% 0%" >
            <form  method="post" action="Search.php" style="width: 800px;"  >
            <div class="form-row">
            <div class="col">
            <input class="form-control" type="text" style="width: 500px;" name="search" placeholder="Enter the employee name:-">            </div>
            <div class="col">
            <button class="btn btn-primary " type="submit">Search</button>
            </div>
            </div>
            </form>
        </div>
    </section>
<?php
    include 'connectDB.php' ;
    if (isset($_POST["search"])) {
    $search = $_POST["search"];
    $sql = "SELECT * FROM `album` WHERE `A_Title` LIKE '%$search%' OR `A_UID` LIKE '%$search%'";
    $result = mysqli_query($con, $sql);
    if (mysqli_num_rows($result) > 0) {
		echo "<section class='clean-block clean-info dark' style='background-color: rgb(68 68 68);border-radius:0;padding-bottom: 0px;'>";
        echo "<div class='container'>";
            echo "<div class='block-heading' style='padding-top: 25px;'>";
                echo "<h2 style='color: #0dcaf0;'><strong>Here are your search results:-</strong></h2>";
            echo "</div>";
        echo "</div>";
        echo "<div class='container'>";
            echo "<div class='row'>";
                echo "<div class='col' style='background-color: #ffffff;'>";
                    echo "<div class='table-responsive'>";
		echo "<table class='table'>";
            echo "<thead>";                
                echo "<tr>";
                    echo "<th>Album ID</th>";
                    echo "<th>Album Name</th>";
                    echo"<th>CopyRight Data</th>";
                    echo"<th>Format</th>";
                    echo"<th>Musician</th>";
                    echo "</tr>";
                    echo "</thead>";
        while ($row = mysqli_fetch_assoc($result)) {
            $AUID= $row['A_UID'];
            echo "<tbody>";
            echo "<tr>";
            echo "<td>" . $row["A_UID"] ."</td>";
            echo "<td>" . $row["A_Title"] . "</td>";
            echo "<td>" . $row["Copyright_data"] . "</td>";
            echo "<td>" . $row["Format"] . "</td>";
            echo "<td>" . $row["M_SSN"] . "</td>";
            echo "<td> <a href='Viewsongs.php?auid=$AUID' <button type='button' class='btn btn-info'> View </button> </td>";
            //echo "<td> <a href='#?'> <button type='button' class='btn btn-warning'> Edit </button></a> </td>";
            echo "<td> <a href='deleteAlbum.php?auid=$AUID' <button type='button' class='btn btn-danger' onclick='return checkdel()' > Delete </button> </td>";
            echo "</tr>";
            echo "</tbody>";
        }
        echo "</table>";
    } else {
        //echo "<h3 class='text-danger text-center'>No results found</h3>";
    }
}
?>
    <script>
        function checkdel()
        {
            return confirm("Are you sure you want to delete the record?");
        }
    </script>
<section class="clean-block clean-info dark" style="background-color: rgba(246,246,246,0);opacity: 1;padding-top: 130px;">
        <div class="container">
            <div class="block-heading">
                <h2 class="text" style="color: #0dcaf0;"><strong>Our Albums</strong></h2>
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
                                    <th class='text-danger'>Copyright Data</th>
                                    <th>Format</th>
                                    <th>Musician</th>
                                </tr>
                            </thead>
                            <tbody>
                            <?php
                                $sql = "SELECT * FROM `album`";
                                
                                $result = mysqli_query($con, $sql);
                                if(mysqli_fetch_array($result)!=NULL){
                                    $sql = "SELECT * from `album`";
                                    $result = mysqli_query($con, $sql);
                                    while ($row=mysqli_fetch_assoc($result)) {
                                        $SSN= $row['M_SSN'];
                                        $sql1 = "SELECT * FROM `musician` where SSN = '$SSN'";
                                        $result1 = mysqli_query($con, $sql1);
                                        $row2=mysqli_fetch_assoc($result1);
                                        $AUID = $row['A_UID'];
                                        echo "<tr>";
                                        echo "<td>" . $row['A_UID'] . "</td>";
                                        echo "<td>" . $row['A_Title'] . "</td>";
                                        echo "<td>" . $row['Copyright_data'] . "</td>";
                                        echo "<td>" . $row['Format'] . "</td>";
                                        echo "<td>" . $row2['name'] . "</td>";
                                        echo "<td> <a href='Viewsongs.php?auid=$AUID' <button type='button' class='btn btn-info'> View </button> </td>";
                                        echo "<td> <a href='#?'> <button type='button' class='btn btn-warning'> Edit </button></a> </td>";
                                        echo "<td> <a href='deleteAlbum.php?auid=$AUID' <button type='button' class='btn btn-danger' onclick='return checkdel()' > Delete </button> </td>";
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