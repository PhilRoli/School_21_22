<h1>Formularseite</h1>

<table>

    <?php
    // echo "<p>***" . $_POST['server'] . "***</p>";

    // echo "Hallo Welt";

    $conn = new PDO("mysql:host=localhost;mydb", $_POST['user'], $_POST['pw']);
    $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    $conn->setAttribute(PDO::ATTR_CASE, PDO::CASE_UPPER);
    $conn->beginTransaction();  // bis commit

    $sql = "SELECT * FROM my_shop.artikel";
    $stmt = $conn->query($sql);
    $row = $stmt->fetch();
    // echo $row['ARTIKEL'];

    while ($row = $stmt->fetch()) {
        echo "<tr><td>"  . $row['ARTNR'] . "</td><td>" . $row['ARTIKEL'] . "</td><td>" . $row['PREIS'] . "</td></tr>";
    }

    $conn = null;
    ?>

</table>

<form action="formulare.php" method="post">
    ArtNr: <input type="text" size="20" name="ArtNr">
    <input type="hidden" size="20" name="user" value="<?php echo $_POST['user']; ?>">
    <input type="hidden" size="20" name="pw" value="<?php echo $_POST['pw']; ?>">
    <input type="submit" value="KAUFEN">
</form>

<?php
$conn = new PDO("mysql:host=localhost;mydb", $_POST['user'], $_POST['pw']);
$conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
$conn->setAttribute(PDO::ATTR_CASE, PDO::CASE_UPPER);
$conn->beginTransaction();

$sql = "SELECT * FROM my_shop.artikel WHERE ARTNR=" . $_POST['ArtNr'];
$stmt = $conn->query($sql);
$row = $stmt->fetch();

echo "Artikel " . $row['ARTNR'] . " '" . $row['ARTIKEL'] . "' um günstige " . $row['PREIS'] . " " . $row['WAEHRG'] . " gekauft!";

$conn = null;
?>