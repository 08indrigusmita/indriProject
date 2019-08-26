<?php
include('../config/db.php');
// 'idDevice':idDevice,'namaDevice':namaDevice,'deksripsi':deksripsi
$idDevice = $_POST['idDevice'];
$namaDevice = $_POST['namaDevice'];
$deksripsi = $_POST['deksripsi'];

$link -> query("INSERT INTO tbl_device VALUES('','$idDevice','$namaDevice','$deksripsi','','y');");
?>
