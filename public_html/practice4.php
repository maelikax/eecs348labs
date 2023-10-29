<!DOCTYPE html>
<html>
<head>  
</head>
<body>
	<table border="1">
    	<tr>
        	<th>X</th>
            <?php
            for ($h = 1; $h <= $_POST["size"]; $h++) {
            	echo '<th>'.$h.'</th>';
            }
            ?>
        </tr>
        <?php
        for ($i = 1; $i <= $_POST["size"]; $i++) {
        	echo '<tr>
            	<th>'.$i.'</th>';
            for ($j = 1; $j <= $_POST["size"]; $j++) {
            	$product = $i *$j;
                echo "<td>".$product."</td>";
            }
        }
        ?>
    </table>
</body>
</html>
